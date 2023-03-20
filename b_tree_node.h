#pragma once
#include <iostream>
#include <queue>
using std::cout;
using std::cin;
using std::queue;

class b_tree_node
{
	int* keys_;
	int minimum_degree_;
	b_tree_node** ptr_children_;
	int num_keys_;
	bool is_leaf_;
public:
	b_tree_node(int, bool);
	void insert_non_full(int);
	void split_child(int, b_tree_node*);
	void traverse();
	b_tree_node* search(int);
	void print_level_order();
	~b_tree_node();
	friend class b_tree;
};
