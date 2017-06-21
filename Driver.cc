/*############################################################################### @Auther: Ethan Patterson
# Professor Joseph Jess
# CS260
#
# Note:
# I had a tone of help working on this one, this is why I chose not to use it
# For the final project, however, I spent a tone of time working on this
# so I chose to through it in.
#
# What it do:
# Bileds a graph and find the shortest dastince to all nodes from a strarting
# node
#
# Example output:
# 0  0
# 1  4
# 2 12
# 3 19
# 4 21
# 5 11
# 6  9
# 7  8
# 8 14
#############################################################################*/
#include"Graph.h"// Contanies graph utility functions

int main(int arg, char** args)
{
	int V = 9;// Number of vertices
	Graph graphConstructor;// Graph constructor
	struct GraphManager* graph = graphConstructor.createGraph(V);// Ceates a new graph manager called graph
	// Addes vertices to graph while connecting them and adding a distance value
	graphConstructor.addEdge(graph, 0, 1, 6);
	graphConstructor.addEdge(graph, 0, 4, 1);
	graphConstructor.addEdge(graph, 1, 2, 5);
	graphConstructor.addEdge(graph, 1, 3, 2);
	graphConstructor.addEdge(graph, 1, 4, 2);
	graphConstructor.addEdge(graph, 2, 3, 5);
	graphConstructor.addEdge(graph, 3, 4, 1);
	// Run dijkstra's algoritham on graph
	graphConstructor.dijkstra(graph, 0);
	return 0;
}
