#ifndef Graph_h
#define Graph_h

#include<iostream>
// Defines a Adjacency list node
struct AdjListNode
{
	int dest;// Node value
	int weight;// weight of node
	struct AdjListNode* next;// Points to next node
};
// Defines a list to hold  linked's lists of adjacency nodes
struct AdjList
{
	struct AdjListNode *head;// makes an adjacency list of nodes
};
// Graph is a list that holds lists of linked List adjacency nodes
struct GraphManager
{
	int V;// Number of vertices
	struct AdjList* list;
};
// Class graph holds graph type functions for dijkstra operater and addEdge operater
class Graph
{
	public:
		// Adds an edge to a graph
		void addEdge(struct GraphManager* graph, int src, int dest, int weight);	
		// Use dijkstra's algorithem to find shortest paths from source node
		void dijkstra(struct GraphManager* graph, int src);
	private:
		// Utility functions for addEdge and dijkstra functions
		struct AdjListNode* newAdjListNode(int dest, int weight);
		// Creates a new Graph
		struct GraphManager* createGraph(int V);
		//void printGraph(struct GraphManager* graph);

};
#endif
