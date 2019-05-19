#ifndef __BINSTRTREE_H__
#define __BINSTRTREE_H__

#include <iostream>

class TreeNode
{
public:
    TreeNode(): count(0), left(nullptr), right(nullptr) { }
    TreeNode(const std::string &s, int c): value(s), count(c), 
                                      left(nullptr), right(nullptr) { }
    TreeNode(const std::string &s, int c, TreeNode *l, TreeNode *r):
            value(s), count(c), left(l), right(r) { }
    TreeNode(const TreeNode &n) = delete;
    ~TreeNode(); 
    TreeNode& operator=(const TreeNode &n) = delete;

    void print();

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree
{
public:
    BinStrTree(): root(new TreeNode()), use(new int(1)) { }
    BinStrTree(TreeNode *n): root(n), use(new int(1)) { }
    BinStrTree(const BinStrTree &t): root(t.root), use(t.use) { ++*use; }
    ~BinStrTree();
    BinStrTree& operator=(const BinStrTree &rht);
    void print() { root->print(); }
    int get_use() { return *use; }

private:
    TreeNode *root;
    int *use;
};

TreeNode::~TreeNode()
{
    if (left)
    {
        std::cout << "delete left " << left->value << " " << left->count << std::endl;
        delete left;
        left = nullptr;
    }
    if (right)
    {
        std::cout << "delete right " << right->value << " " << right->count << std::endl;
        delete right;
        right = nullptr;
    }
}

void TreeNode::print()
{
    std::cout << value << " " << count << std::endl;
    if (left)
        left->print();
    if (right)
        right->print();
}

BinStrTree::~BinStrTree()
{
    if (--*use == 0)
    {
        if (root)
            delete root;
        delete use;
    }
}

BinStrTree& BinStrTree::operator=(const BinStrTree &rht)
{
    ++*rht.use;

    if (--*use == 0)
    {
        delete root;
        delete use;
    }

    root = rht.root;
    use = rht.use;

    return *this;
}

#endif
