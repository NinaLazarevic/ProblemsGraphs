#pragma once

template<class T>
class Node;

template<class T>
class Edge
{
public:
	Node<T>* dest;
	Edge<T>* next;
	int weight;

	Edge()
	{
		dest = NULL;
		next = NULL;
		weight = 0;
	}
	Edge(Node<T>* d)
	{
		dest = d;
		next = NULL;
		weight = 0;
	}
	Edge(Node<T>* d, Edge<T>* n)
	{
		dest = d;
		next = n;
		weight = 0;
	}
	Edge(Node<T>* d, Edge<T>* n, int w)
	{
		dest = d;
		next = n;
		weight = w;
	}

	void changeWeight(int w)
	{
		weight = w;
	}
};