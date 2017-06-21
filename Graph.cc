#include "Graph.h"
#include "Heap.h"
#include <limits.h>
// Create a new adjacency list node
struct AdjListNode* Graph::newAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode = new AdjListNode;
	newNode -> dest = dest;// Set destination of node
	newNode -> weight = weight;// Set node weight value
	newNode -> next = NULL;// Set node next to NULL
	return newNode;
}
// Creates a graph of with a V number of vertices
struct GraphManager* Graph::createGraph(int V)
{
	// Allocate Memory for a graph pointer
	struct GraphManager* graph = new GraphManager;
	graph -> V = V;// Set graph V equal to passed in v
	
	graph -> list = new AdjList[V];// Dinamicly create an array of Adjacency lists
	
	for (int i = 0; i < V; ++i)
		graph -> list[i].head = NULL;// Set each head to NULL
	
	return graph;
}
// Addes an edge t a vertice
void Graph::addEdge(struct GraphManager* graph, int src, int dest, int weight)
{
	struct AdjListNode* newNode = newAdjListNode(dest, weight);// Creates adjacency node to be a  heads
	newNode -> next = graph -> list[src].head;// Sets newNode's next node to list
	graph -> list[src].head = newNode;

	// Add an edge weight from dest to src 
	newNode = newAdjListNode(src, weight);
	newNode -> next = graph -> list[dest].head;
	graph -> list[dest].head = newNode;
}
// Finds the shortes path to all vertices from a src vertex
void Graph::dijkstra(struct GraphManager* graph, int src)
{
	int V = graph -> V;// Number of vertices in the graph
	int dist[V];// dist values used to pick minimum weight edge in count
	
	Heap HeapConstr;// Heap constructor
	struct MinHeap* minHeap = HeapConstr.createMinHeap(V);
	// Initialize min heap with all vertixes
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap -> list[v] = HeapConstr.newMinHeapNode(v, dist[v]);
		minHeap -> pos[v] = v;
	}

	// Makes dist value of src vertex as 0
	minHeap -> list[src] = HeapConstr.newMinHeapNode(src, dist[src]);
	minHeap -> pos[src] = src;
	dist[src] = 0;
	HeapConstr.decreaseKey(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V
	minHeap -> size = V;
	
	//contains all nodes whose shortest distance is not yet found.
	while (!HeapConstr.isEmpty(minHeap))
	{
		// Get the vertex with minimum ditance value
		struct MinHeapNode* minHeapNode = HeapConstr.extractMin(minHeap);
		int u = minHeapNode->v;

		struct AdjListNode* pCrawl = graph->list[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl -> dest;
			// If Distance has not been checked and if u is less than the previously found distance
			if (HeapConstr.isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl -> weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl -> weight;
				// Updates distance value in min heap
				HeapConstr.decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl -> next;
		}
	}
	HeapConstr.printArr(dist, V);
}
