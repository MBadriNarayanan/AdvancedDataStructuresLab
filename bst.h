#ifndef bst_h
#define bst_h
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
class BST
{
    public:
    Node<T>* root;
    Node<T>* insert(Node<T>* r, T x);
    void inorder(Node<T>* r);
    void preorder(Node<T>* r);
    void postorder(Node<T>*r);
    Node<T>* minimum(Node<T>* r);
    Node<T>* maximum(Node<T>* r);
    Node<T>* deleteNode(Node<T>* r, T data);  
    BST();
    Node<T>* insert(T x);
    void display();
    Node<T>* deleteNode(T data);
};
#endif