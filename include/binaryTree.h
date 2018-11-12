#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

class binaryTree
{
    public:
        binaryTree();
        binaryTree(const binaryTree &tree);
        ~binaryTree();
        void add(int);
        void print();
        void removeElement(int);
        Node *getMinNode(Node *);
        Node *getMaxNode(Node *);
        Node *findElement(int);
        void removeTree(Node *);
        Node *getRoot() const;
        void setRoot(Node *);

    private:
         Node *root;
};

#endif // BINARYTREE_H
