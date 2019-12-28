#pragma once
#include <iostream>

using namespace std;

template<class T>
class Edge;
template<class T>
class Node;

template<class T>
class Graph
{
protected:
	Node<T>* start;
	int numberOfNodes;
public:
	Graph()
	{
		start = NULL;
		numberOfNodes = 0;
	}
	~Graph();
	Node<T>* findNode(T info);
	Edge<T>* findEdge(T a, T b);
	void insertNode(T info);
	void insertEdge(T a, T b);
	void print();

	T maxInDegree();
	bool isStronglyConnected();
	bool findPath(Node<T>* a, Node<T>* b);
	void statusZero();
	bool wordExists(char* wordToFind);
};

template<class T>
Node<T>* Graph<T>::findNode(T info)
{
	Node<T>* ptr = start;
	while (ptr != NULL && ptr->info != info)
		ptr = ptr->next;
	return ptr;
}

template<class T>
Edge<T>* Graph<T>::findEdge(T a, T b)
{
	Node<T>* pa = findNode(a);
	Node<T>* pb = findNode(b);

	if (pa == NULL || pb == NULL)
		return NULL;

	Edge<T>* ptr = pa->adj;
	while (ptr != NULL && ptr->dest != pb)
		ptr = ptr->next;
	return ptr;
}

template<class T>
 void Graph<T>::insertNode(T info)
{
	Node<T>* newNode = new Node<T>(info, start);
	
	start = newNode;
	numberOfNodes++;
}

template<class T>
void Graph<T>::insertEdge(T a, T b)
{
	Node<T>* pa = findNode(a);
	Node<T>* pb = findNode(b);

	if (pa == NULL || pb == NULL) return;

	Edge<T>* ptr = new Edge<T>(pb, pa->adj);
	pa->adj = ptr;
}

template<class T>
inline void Graph<T>::print()
{
	Node<T>* ptr = start;

	while (ptr != NULL)
	{
		cout << ptr->info;
		if (ptr->adj != NULL) cout << " --> ";
		Edge<T>* pa = ptr->adj;
		while (pa != NULL)
		{
			cout << pa->dest->info << " | ";
			pa = pa->next;
		}
		cout << endl;
		ptr = ptr->next;
	}
}

template<class T>
T Graph<T>::maxInDegree()
{
	// this array will keep in degrees of all nodes 
	// degrees[3] is keeping indegree of fourth node
	int* degrees = (int*)calloc(numberOfNodes, sizeof(int)); //all zeros in array with calloc

	Node<T>* ptri = start;
	int i = 0;
	while (ptri != NULL)
	{
		Node<T>* ptrj = start;
		while (ptrj != NULL)
		{
			Edge<T>* pj = ptrj->adj;
			while (pj != NULL)
			{
				if (pj->dest == ptri)
					degrees[i]++;
				pj = pj->next;
			}

			ptrj = ptrj->next;
		}

		ptri = ptri->next;
		i++;
	}

	int max = 0;
	int imax = 0;

	for (i = 0; i < numberOfNodes; i++)
	{
		if (degrees[i] > max)
		{
			max = degrees[i];
			imax = i;
		}
	}

	ptri = start;
	i = 0;
	while (i != imax)
	{
		ptri = ptri->next;
		i++;
	}


	free(degrees);
	return ptri->info;
}

template<class T>
bool Graph<T>::isStronglyConnected()
{
	//if graph is strongly connected, there is a path between each pair of nodes
	bool connected = true;

	Node<T>* ptr = start;
	
	while (ptr->next != NULL && connected)
	{
		Node<T>* ptrN = ptr->next;
		while (ptrN != NULL && connected)
		{
			connected = findPath(ptr, ptrN);
			statusZero(); 
			ptrN = ptrN->next;
		}
		ptr = ptr->next;
	}
	return connected;
}

template<class T>
bool Graph<T>::findPath(Node<T>* a, Node<T>* b)
{
	if (a->status == 1)
		return false;

	a->status = 1;
	//first trying to se if there is direct path
	if (findEdge(a->info, b->info)) return true;
	Edge<T>* ptr = a->adj;
	bool path = false;
	while (ptr != NULL && !path)
	{
		path = findPath(ptr->dest, b);
		ptr = ptr->next;
	}

	return path;
}

template<class T>
void Graph<T>::statusZero()
{
	Node<T>* ptr = start;
	while (ptr != NULL)
	{
		ptr->status = 0;
		ptr = ptr->next;
	}
}

template<class T>
bool Graph<T>::wordExists(char* wordToFind)
{
	bool path = true;
	int i = 0;

	while (wordToFind[i + 1] != '\0' && path)
	{
		if (findEdge(wordToFind[i], wordToFind[i + 1]) == NULL)
			path = false;
		i++;
	}
	return path;
}
