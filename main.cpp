#include "b_tree.h"

int main()
{
	b_tree t(2); // A B-Tree with minimum degree 2
	for (const int i : { 12, 10, 12, 15, 5, 6, 7, 10, 10, 12, 15, 100 , -1})
		t.insert(i);
	t.print_level_order();
	return 0;
}
