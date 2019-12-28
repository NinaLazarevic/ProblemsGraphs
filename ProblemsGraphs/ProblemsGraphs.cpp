#pragma once
#include "Graph.h"
#include "Edge.h"
#include "Node.h"

int main()
{
	Graph<int>* graph = new Graph<int>();

	graph->insertNode(7);
	graph->insertNode(6);
	graph->insertNode(5);
	graph->insertNode(4);
	graph->insertNode(3);
	graph->insertNode(2);
	graph->insertNode(1);

	graph->insertEdge(2, 4);
	graph->insertEdge(2, 2);
	graph->insertEdge(3, 2);
	graph->insertEdge(3, 1);
	graph->insertEdge(4, 3);
	graph->insertEdge(4, 2);
	graph->insertEdge(4, 1);
	graph->insertEdge(6, 3);
	graph->insertEdge(6, 7);
	graph->insertEdge(7, 5);
	graph->insertEdge(3, 5);

	//graph->insertEdge(1, 2);
	//graph->insertEdge(1, 4);
	//graph->insertEdge(2, 3);
	//graph->insertEdge(3, 1);
	//graph->insertEdge(4, 2);

	graph->print();

	//problem 1
	int maxD = graph->maxInDegree();
	cout << "Node with highest indegree is " << maxD << endl;

	//problem 2
	//Node<int>* a = graph->findNode(1);
	//Node<int>* b = graph->findNode(3);
	//bool path = graph->findPath(a, b);
	//if (path)
	//	cout << "Path between 1 and 3 exist" << endl;
	//else
	//	cout << "Path between 1 and 3 doesn't exist" << endl;

	bool conn = graph->isStronglyConnected();
	if (conn)
		cout << "\nGraph is strongly connected" << endl;
	else
		cout << "\nGraph isn't strongly connected" << endl;

	Graph<char>* graph2 = new Graph<char>();

	graph2->insertNode('F');
	graph2->insertNode('E');
	graph2->insertNode('D');
	graph2->insertNode('C');
	graph2->insertNode('B');
	graph2->insertNode('A');

	graph2->insertEdge('A', 'B');
	graph2->insertEdge('B', 'A');
	graph2->insertEdge('A', 'D');
	graph2->insertEdge('D', 'A');
	graph2->insertEdge('A', 'C');
	graph2->insertEdge('C', 'A');
	graph2->insertEdge('C', 'B');
	graph2->insertEdge('B', 'C');
	graph2->insertEdge('C', 'D');
	graph2->insertEdge('D', 'C');
	graph2->insertEdge('C', 'E');
	graph2->insertEdge('E', 'C');
	graph2->insertEdge('E', 'F');
	graph2->insertEdge('F', 'E');
	graph2->insertEdge('F', 'F');

	graph2->print();

	//problem 3
	char first[] = "FFEF";
	char second[] = "ABFE";
	bool word1 = graph2->wordExists(first);
	bool word2 = graph2->wordExists(second);

	if (word1)
		cout << "Word " <<first<<" exist" << endl;
	else
		cout << "Word "<<first<<" doesn't exist" << endl;

	if (word2)
		cout << "Word " << second << " exist" << endl;
	else
		cout << "Word " << second << " doesn't exist" << endl;

	
}

