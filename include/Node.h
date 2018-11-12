#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
    public:
        Node();
        Node(int data = 0,Node *left = nullptr,Node *right = nullptr);
        Node(const Node &node);
        ~Node();
        void print(Node *,int);
        int getData() const;
        void setData(int);
        Node *getLeft() const;
        void setLeft(Node *left);
        Node *getRight() const;
        void setRight(Node *right);

    private:
        int data;
        Node *right;
        Node *left;

};

#endif // NODE_H
