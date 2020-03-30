#ifndef avl_h
#define avl_h
#include <iostream>
#include<string>

using namespace std;

template <class T>

class Node
{
    public:
            T data;
            Node<T>* right;
            Node<T>* left;
            int height;
            Node();
            Node(T x);
};

template <class T>

class AVL
{
    protected:
            Node<T>* root;
            void inorder(Node<T>* r);
            void preorder(Node<T>* r);
            void postorder(Node<T>* r);
            Node<T>* minimum(Node<T>* r);
            Node<T>* maximum(Node<T>* r);
            int height(Node<T>* p);
            int balanceFactor(Node<T>* r);
            Node<T>* LRotation(Node<T>* r);
            Node<T>* RRotation(Node<T>* r);
            Node<T>* LRRotation(Node<T>* r);
            Node<T>* RLRotation(Node<T>* r);
            Node<T>* insert(Node<T>* r, T x);
            Node<T>* deleteNode(Node<T>* r, T data);
    public:
            AVL();
            Node<T>* insert(T x);
            Node<T>* deleteNode(T x);
            void display();
            Node<T>* getRoot();

};
#endif