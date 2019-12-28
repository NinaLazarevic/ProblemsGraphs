#pragma once
#include <iostream>
using namespace std;

template<class T>
class Edge;

template<class T>
class Node
{
public:
	T info;
	Node<T>* next;
	Edge<T>* adj;
	int status;

	Node()
	{
		status = 0;
		next = NULL;
		adj = NULL;
	}
	Node(T info)
	{
		this->info = info;
		status = 0;
		next = NULL;
		adj = NULL;
	}
	Node(T info, Node<T>* n)
	{
		this->info = info;
		status = 0;
		next = n;
		adj = NULL;
	}
	Node(T info, Node<T>* n, Edge<T>* a)
	{
		this->info = info;
		status = 0;
		next = n;
		adj = a;
	}
	void visit()
	{
		cout << info;
	}
};
