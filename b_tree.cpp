#include "b_tree.h"

b_tree::b_tree(const int minimum_degree)
{
	root_ = nullptr;
	minimum_degree_ = minimum_degree;
}

void b_tree::traverse()
{
	if (root_ != nullptr) root_->traverse();
}

b_tree_node* b_tree::search(int k)
{
	if (root_ == nullptr)
		return  nullptr;
	//else
	return	root_->search(k);
}

void b_tree::insert(int k)
{
	if (root_ == nullptr)
	{
		root_ = new b_tree_node(minimum_degree_, true);
		root_->keys_[0] = k; 			root_->num_keys_ = 1;
	}
	else {
		if (root_->num_keys_ == 2 * minimum_degree_ - 1)
		{
			b_tree_node* s = new b_tree_node(minimum_degree_, false);

			s->ptr_children_[0] = root_;
			s->split_child(0, root_);
			int i = 0;
			if (s->keys_[0] < k)
				i++;
			s->ptr_children_[i]->insert_non_full(k);
			root_ = s;
		}
		else root_->insert_non_full(k);
	}
}

void b_tree::print_level_order() {
	if (root_ != nullptr) root_->print_level_order();
}

b_tree::~b_tree() {
	delete root_;
}
