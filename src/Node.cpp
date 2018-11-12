#include "Node.h"

Node::Node()
{
    this->setData(0);
    this->setLeft(nullptr);
    this->setRight(nullptr);
}

Node::Node(int data, Node *right,Node *left)
{
    this->setData(data);
    this->setLeft(left);
    this->setRight(right);
}

Node::Node(const Node &node)
{
    this->setData(node.getData());
    this->setLeft(node.getLeft());
    this->setRight(node.getRight());
}

Node::~Node()
{
    this->setData(0);
    this->setLeft(nullptr);
    this->setRight(nullptr);
}

void Node::print(Node *node,int spaces)
{
    while(node != 0)
    {
        this->print(node->getRight(),spaces+5);
        for(int i = 1; i < spaces; ++i)
            std::cout << ' ';

        std::cout << node->data << std::endl;

        node = node->left;
        spaces += 5;
    }
}

int Node::getData() const
{
    return data;
}

void Node::setData(int data)
{
    this->data = data;
}

Node * Node::getLeft() const
{
    return left;
}

void Node::setLeft(Node *left)
{
    this->left = left;
}

Node * Node::getRight() const
{
    return right;
}

void Node::setRight(Node *right)
{
    this->right = right;
}

