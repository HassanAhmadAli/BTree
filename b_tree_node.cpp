#include "b_tree_node.h"

b_tree_node::b_tree_node(int _minimum_degree, bool _is_leaf)
	:minimum_degree_(_minimum_degree), is_leaf_(_is_leaf), num_keys_(0)
{
	// Initialized the arrays
	this->keys_ = new int[2 * minimum_degree_ - 1];
	this->ptr_children_ = new b_tree_node * [2 * minimum_degree_];
}

void b_tree_node::insert_non_full(int k)
{

	int i = num_keys_ - 1;
	if (is_leaf_)
	{

		while (i >= 0 && keys_[i] > k)
			keys_[i + 1] = keys_[i], i--;

		keys_[i + 1] = k;
		num_keys_ = num_keys_ + 1;
	}
	else
	{
		while (i >= 0 && keys_[i] > k)
			i--;
		if (ptr_children_[i + 1]->num_keys_ == 2 * minimum_degree_ - 1)
		{
			split_child(i + 1, ptr_children_[i + 1]);
			if (keys_[i + 1] < k)
				i++;
		}
		ptr_children_[i + 1]->insert_non_full(k);
	}
}

void b_tree_node::split_child(int i, b_tree_node* dest)
{
	b_tree_node* newNode = new b_tree_node(dest->minimum_degree_, dest->is_leaf_);
	newNode->num_keys_ = minimum_degree_ - 1;
	for (int j = 0; j < minimum_degree_ - 1; j++)
		newNode->keys_[j] = dest->keys_[j + minimum_degree_];

	if (!dest->is_leaf_)
	{
		for (int j = 0; j < minimum_degree_; j++)
			newNode->ptr_children_[j] = dest->ptr_children_[j + minimum_degree_];
	}
	dest->num_keys_ = minimum_degree_ - 1;
	for (int j = num_keys_; j >= i + 1; j--)
		ptr_children_[j + 1] = ptr_children_[j];
	ptr_children_[i + 1] = newNode;
	for (int j = num_keys_ - 1; j >= i; j--)
		keys_[j + 1] = keys_[j];
	keys_[i] = dest->keys_[minimum_degree_ - 1];
	this->num_keys_ = this->num_keys_ + 1;
}

void b_tree_node::traverse()
{
	int i;
	for (i = 0; i < num_keys_; i++)
	{
		if (is_leaf_ == false)
			ptr_children_[i]->traverse();
		std::cout << " " << keys_[i];
	}

	if (is_leaf_ == false)
		ptr_children_[i]->traverse();
}

b_tree_node* b_tree_node::search(int k)
{
	int i = 0;
	while (i < num_keys_ && k > keys_[i])
		i++;

	if (keys_[i] == k)
		return this;

	if (is_leaf_)
		return nullptr;

	return ptr_children_[i]->search(k);
}

void b_tree_node::print_level_order()
{
	if (this == nullptr)
	{
		return;
	}
	std::queue<b_tree_node*> q;
	q.push(this);

	while (!q.empty())
	{
		int n = q.size();
		for (int i = 0; i < n; i++)
		{
			b_tree_node* temp = q.front();
			q.pop();
			for (int j = 0; j < temp->num_keys_; j++)
			{
				std::cout << temp->keys_[j] << " ";
			}
			if (!temp->is_leaf_)
			{
				for (int j = 0; j < temp->num_keys_ + 1; j++)
				{
					q.push(temp->ptr_children_[j]);
				}
			}
			std::cout << "| ";
		}
		std::cout << std::endl;
	}
}

b_tree_node::~b_tree_node() {
	delete keys_;
	for (int i = 0; i < num_keys_; i++) {
		ptr_children_[i] = nullptr;}
delete ptr_children_;
	
}
