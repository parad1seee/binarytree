#include "binaryTree.h"

binaryTree::binaryTree()
{
    this->setRoot(nullptr);
}

binaryTree::~binaryTree()
{
    this->removeTree(this->getRoot());
}

binaryTree::binaryTree(const binaryTree &tree)
{
    this->setRoot(tree.getRoot());
}

Node * binaryTree::getRoot() const
{
    return root;
}

void binaryTree::setRoot(Node *root)
{
    this->root = root;
}

void binaryTree::add(int data)
{
    Node *node =  new Node(data);
    if(root == nullptr)
    {
        root = node;
        return;
    }

    if(this->findElement(node->getData()) != nullptr)
    {
        return;
    }

    Node *currNode = root;
    Node *prevNode = root;

    while(currNode != nullptr)
    {
        prevNode = currNode;
        if(currNode->getData() > data)
        {
            currNode = currNode->getLeft();
        }
        else
        {
            currNode = currNode->getRight();
        }
    }

    if(prevNode->getData() > node->getData())
    {
        prevNode->setLeft(node);
    }
    else {
        prevNode->setRight(node);
    }

    return;
}

void binaryTree::print()
{
    root->print(root,0);
    return;
}

void binaryTree::removeElement(int data)
{
    if(root == nullptr)
    {
        std::cout << "Tree is empty,nothing to remove" << std::endl;
        return;
    }

    if(this->findElement(data) == nullptr)
    {
        std::cout << "No such element in tree" << std::endl;
        return;
    }

    int tmpData = 0;

    Node *currNode = root;
    Node *prevNode = root;

    while(currNode->getData() != data)
    {
        prevNode = currNode;
        if(currNode->getData() > data)
            currNode = currNode->getLeft();
        else currNode = currNode->getRight();
    }

    if(currNode->getLeft() == nullptr && currNode->getRight() == nullptr)
    {
        if(prevNode->getRight() == currNode)
        {
            delete currNode;
            prevNode->setRight(nullptr);
            return;
        }
        else
        {
            delete currNode;
            prevNode->setLeft(nullptr);
            return;
        }
    }

    if(currNode->getLeft() != nullptr && currNode->getRight() != nullptr)
    {
        Node *localMax = this->getMaxNode(currNode->getLeft());
        tmpData = localMax->getData();
        this->removeElement(localMax->getData());
        currNode->setData(tmpData);
        return;
    }
    else if(currNode->getLeft() != nullptr)
    {
        if(currNode == root)
        {
            this->setRoot(currNode->getLeft());
            return;
        }

        if(prevNode->getLeft() == currNode)
        {
            prevNode->setLeft(currNode->getLeft());
            delete currNode;
            return;
        }
        else
        {
            prevNode->setRight(currNode->getLeft());
            delete currNode;
            return;
        }
    }
    else
    {
        if(currNode == root)
        {
            this->setRoot(currNode->getRight());
            return;
        }

        if(prevNode->getLeft() == currNode)
        {
            prevNode->setLeft(currNode->getRight());
            delete currNode;
            return;
        }
        else
        {
            prevNode->setRight(currNode->getRight());
            delete currNode;
            return;
        }
    }
}

Node * binaryTree::getMinNode(Node *currNode)
{
    while (currNode->getLeft()) {
        return this->getMinNode(currNode->getLeft());
    }
    return currNode;
}

Node * binaryTree::getMaxNode(Node *currNode)
{
    while (currNode->getRight()) {
        return this->getMaxNode(currNode->getRight());
    }
    return currNode;
}

Node * binaryTree::findElement(int data)
{

    Node *currNode = root;

    while(1)
    {
        if(currNode->getData() == data) return currNode;

        if(currNode->getData() > data)
            currNode = currNode->getLeft();
        else currNode = currNode->getRight();

        if(currNode == nullptr) return nullptr;
    }
}

void binaryTree::removeTree(Node *currNode)
{
    if(currNode != nullptr)
    {
        removeTree(currNode->getLeft());
        removeTree(currNode->getRight());
        delete currNode;
    }
    this->setRoot(nullptr);
}
