#include"Heap.h"
// Creates a new heap node 
struct MinHeapNode* Heap::newMinHeapNode(int v, int dist)
{
	// Get memory for node
	// Than assighnes it values
	struct MinHeapNode* minHeapNode = new MinHeapNode;
	minHeapNode -> v = v;
	minHeapNode -> dist = dist;
	return minHeapNode;
}
// Creates a Min Heap
struct MinHeap* Heap::createMinHeap(int capacity)
{
	struct MinHeap* minHeap = new MinHeap;
	minHeap -> pos = new int[capacity];
	minHeap -> size = 0;
	minHeap-> capacity = capacity;
	minHeap -> list = new MinHeapNode*[capacity];// Get memory for the double pointer 
	for (int i = 0; i < capacity; ++i)
		minHeap -> list[i] = new  MinHeapNode[capacity];

	return minHeap;
}
// Function to swap two nodes of min heap
void Heap::swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;

}
// Heapify at a given index
// Updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void Heap::minHeapify(struct MinHeap* minHeap, int index)
{
	int smallest, left, right;
	smallest = index;
	left = 2 * index + 1;
	right = 2 * index + 2;

	if (left < minHeap -> size && minHeap -> list[left]->dist < minHeap->list[smallest]->dist)
		smallest = left;

	if (right < minHeap -> size && minHeap -> list[right] -> dist < minHeap -> list[smallest]->dist)
		smallest = right;

	if (smallest != index)
	{
		// The nodes to be swapped in the min heap
		MinHeapNode* smallestNode = minHeap -> list[smallest];
		MinHeapNode* indexNode = minHeap -> list[index];
		
		// Swap positions
		minHeap -> pos[smallestNode -> v] = index;
		minHeap -> pos[indexNode -> v] = smallest;
		
		// Swap nodes
		swapMinHeapNode(&minHeap -> list[smallest], &minHeap -> list[index]);
		
		minHeapify(minHeap, smallest);
	}
}
// Check if the given minHeap is empty
int Heap::isEmpty(struct MinHeap* minHeap)
{
	return minHeap -> size == 0;
}
//
struct MinHeapNode* Heap::extractMin(struct MinHeap* minHeap)
{
	if (isEmpty(minHeap))
		return NULL;
	// Store the root/head node
	struct MinHeapNode* root = minHeap -> list[0];
	// Replace root node with last node
	struct MinHeapNode* lastNode = minHeap-> list[minHeap->size - 1];
	minHeap -> list[0] = lastNode;

	// Update position of last node
	minHeap -> pos[root->v] = minHeap -> size - 1;
	minHeap -> pos[lastNode -> v] = 0;
	
	// Reduce heap size and heapify root
	--minHeap -> size;
	minHeapify(minHeap, 0);
	
	return root;
}
// Decrease dist value of a vertex v
void Heap::decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
	// Get the index of v in heap array
	int i = minHeap -> pos[v];
	
	// Get the node and update its dist value
	minHeap ->list[i]->dist = dist;

	// Travel up while the complete tree is not hepified.
	while (i && minHeap -> list[i] -> dist < minHeap->list[(i - 1) / 2] -> dist)
	{
		// Swap this node with its parent
		minHeap -> pos[minHeap -> list[i]-> v] = (i-1)/2;
		minHeap -> pos[minHeap -> list[(i-1)/2]->v] = i;
		swapMinHeapNode(&minHeap -> list[i], &minHeap -> list[(i - 1) /2]);

		// Move to parent index
		i = (i - 1)/2;
	}
}
// Is vertex v in the heap
bool Heap::isInMinHeap(struct MinHeap* minHeap, int v)
{
	if (minHeap -> pos[v] < minHeap -> size)
		return true;
	return false;
}
// Prints distance values
void Heap::printArr(int dist[], int n)
{
	std::cout <<"Vertex Distance from Source" << std::endl;
	for (int i = 0; i < n; ++i)
		std::cout << i <<"\t\t"<< dist[i] << std::endl;
}
