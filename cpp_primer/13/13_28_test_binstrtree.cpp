#include <iostream>
#include "13_28_BinStrTree.h"

int main()
{
    TreeNode a("a", 1);
    TreeNode c("c", 3);
    TreeNode e("e", 5);
    TreeNode g("g", 7);
    TreeNode b("b", 2, &a, &c);
    TreeNode f("f", 6, &e, &g);
    TreeNode d("d", 4, &b, &f);
    BinStrTree *tr = new BinStrTree(&d);

    tr->print();
    std::cout << "Use: " << tr->get_use() << std::endl;
    delete tr;

    return 0;
}
