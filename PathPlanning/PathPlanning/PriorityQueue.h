#pragma once
#include <vector>
#include "Node.h"
// A priority queue implementation, min element is alway on top.
// @author: Tianhua Zhao
class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();
	// push a node to priority queue.
	void push(Node*);
	// pop the min node.
	Node* pop();
	// peek the min node.
	Node* top() const;
	// is the priority queue empty?
	bool empty() const;
	// the size of the priority queue
	int size() const;
	// does the priority queue contain the elememt?
	bool contains(Node*) const;
private:
	std::vector<Node*> vec_;
	void perculate_up(int);
	void perculate_down(int);
};