#ifndef splay_h
#define splay_h

#include<iostream>

using namespace std;

template <class T>
class Node
{
    public:

    T data;
    Node<T>*right;
    Node<T>*left;

    Node()
    {
        right = NULL;
        left = NULL;
    }
    Node(T x)
    {
        right = NULL;
        left = NULL;
        data = x;
    }
};

template <class T>
class Splay
{
    Node<T> *root;

    Node<T>* minimum(Node<T>* r)
    {
            Node<T>* temp = r;
            while (temp->left!=NULL)
                temp = temp->left;
            return temp;
    }
    Node<T>* maximum(Node<T>* r)
    {
        Node<T>* temp = r;
        while (temp->right!=NULL)
            temp = temp->right;
        return temp;
    }
    void preorder(Node<T> *t)
    {
        if(t == NULL)return;
        cout<<" "<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
    void inorder(Node<T> *t)
    {
        if(t == NULL)return;
        inorder(t->left);
        cout<<" "<<t->data<<" ";
        inorder(t->right);
    }
    void postorder(Node<T> *t)
    {
        if(t == NULL)return ;
        postorder(t->left);
        postorder(t->right);
        cout<<" "<<t->data<<" ";
    }
    Node<T>* rightRotate(Node<T> *x) 
    { 
        Node<T> *y = x->left; 
        x->left = y->right; 
        y->right = x; 
        return y; 
    }
    Node<T>* leftRotate(Node<T> *x) 
    { 
        Node<T> *y = x->right; 
        x->right = y->left; 
        y->left = x; 
        return y; 
    } 
    Node<T>* splay(Node<T> *r,T key) 
    { 
        if (r == NULL || r->data == key) return r; 
        if (r->data > key) 
        { 
            if (r->left == NULL) return r;  
            if (r->left->data > key) 
            { 
                r->left->left = splay(r->left->left, key); 
                r = rightRotate(r); 
            } 
            else if (r->left->data < key) 
            { 
                r->left->right = splay(r->left->right, key); 
                if (r->left->right != NULL)r->left = leftRotate(r->left); 
            } 
            return (r->left == NULL)? r: rightRotate(r); 
        } 
        else  
        { 
            if (r->right == NULL) return r; 
            if (r->right->data > key) 
            { 
                r->right->left = splay(r->right->left, key); 
                if (r->right->left != NULL)r->right = rightRotate(r->right); 
            } 
            else if (r->right->data < key) 
            {  
                r->right->right = splay(r->right->right, key); 
                r = leftRotate(r); 
            } 
            return (r->right == NULL)? r: leftRotate(r); 
        } 
    } 
    Node<T>* insert(Node<T> *r,T k)
    {   
        if (r == NULL)return new Node<T>(k); 
        r = splay(r, k);    
        if (r->data == k) return r;    
        Node<T> *newnode = new Node<T>(k);  
        if (r->data > k)  
        {  
            newnode->right = r;  
            newnode->left = r->left;  
            r->left = NULL;  
        }  
        else
        {  
            newnode->left = r;  
            newnode->right = r->right;  
            r->right = NULL;  
        }  
        return newnode;  
    }
    Node<T>* search(Node<T>* r,T key)
    {
        return splay(r,key);
    }
    Node<T>* delete_key(Node<T>* r,T key)
    {
        Node<T> *temp; 
        if (!r) return NULL;      
        r = splay(r, key); 
        if (key != r->data) return r;   
        if (!r->left) 
        { 
            temp = r; 
            r = r->right; 
        } 
        else
        { 
            temp = r; 
            r = splay(r->left, key); 
            r->right = temp->right; 
        } 
        delete temp; 
        return r;
    } 

    public:

    Splay()
    {
        root = NULL;
    }
    Node<T>* insert(T x)
    {
        root = insert(root,x);
        return root;
    }
    Node<T>* search(T key)
    {
        root = search(root,key);
        return root;
    }
    Node<T>* delete_key(T key)
    {
        root = delete_key(root,key);
        return root;
    }
    int display()
    {
        cout<<"\n\n InOrder Display \n\n";
        inorder(root);
        cout<<endl;
        return 0;
    }
    Node<T>* getRoot()
    {
        return root;
    }

};

#endif