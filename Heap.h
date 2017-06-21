#ifndef Heap_h
#define Heap_h

#include <iostream>
// Defines a heap node
struct MinHeapNode
{
	int v;
	int dist;
};
// Defines a heap
struct MinHeap
{
	int size; // Number of heap nodes present
	int capacity; // Capacity of heap
	int *pos; // Used in decreaseKey()
	struct MinHeapNode **list;
};

class Heap
{
	public:
		// Creates a new min heap node
		struct MinHeapNode* newMinHeapNode(int v, int dist);
		// Creates a heap
		struct MinHeap* createMinHeap( int capacity);
		// swaps two nodes in the min heap
		void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
		// Heap function
		void minHeapify(struct MinHeap* minHeap, int index);
		// Check if heap is empty
		int isEmpty(struct MinHeap* minHeap);
		// Get the minimum most node from the heap
		struct MinHeapNode* extractMin(struct MinHeap* minHeap);
		// For decreasing dist value at a vertex v
		void decreaseKey(struct MinHeap* minHeap, int v, int dist);
		// Chack vertex v is in heap
		bool isInMinHeap(struct MinHeap *minHeap, int v);
		// Print the distances
		void printArr(int dist[], int n);

};
#endif
