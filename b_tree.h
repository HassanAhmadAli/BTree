#pragma once
#include "b_tree_node.h"

class b_tree
{
	b_tree_node* root_;
	int minimum_degree_;
public:
	explicit b_tree(int);
	void traverse();
	b_tree_node* search(int);
	void insert(int);
	void print_level_order();
	~b_tree();
};
