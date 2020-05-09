#ifndef RBT_H
#define RBT_H

#include<iostream>

using namespace std;

enum Colour {RED, BLACK};

template <class T>
class Node
{
    public:

    T data;
    Node<T>*right;
    Node<T>*left;
    Colour col;
    Node()
    {
        right = NULL;
        left = NULL;
        col = RED;
    }
    
    Node(T x)
    {
        right = NULL;
        left = NULL;
        data = x;
        col = RED;
    }
};

template <class T>
class RBT
{
    Node<T> *root;
    Node<T> *rotateRightChild(Node<T> *t)
    {

        if(t->right)
        {
            Node<T> *u = t->right;
            t->right = u->left;
            u->left = t;
            return u;
        }

        else
            return t;
    }
    Node<T> *rotateLeftChild(Node<T> *t)
    {
        if(t->left)
        {
            Node<T> *u = t->left;
            t->left = u->right;
            u->right = t;
            return u;
        }

        else
            return t;
    }
    Node<T> *doubleRotateLeft(Node<T> *t)
    {
        t->left = rotateRightChild(t->left);
        t = rotateLeftChild(t);
        return t;
    }
    Node<T> *doubleRotateRight(Node<T> *t)
    {
        t->right = rotateLeftChild(t->right);
        t = rotateRightChild(t);
        return t;
    }
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
        cout<<t->data<<"-"<<(t->col ? "BLACK":"RED")<<endl;
        preorder(t->left);
        preorder(t->right);
    }
    void inorder(Node<T> *t)
    {
        if(t == NULL)return;
        inorder(t->left);
        cout<<t->data<<"-"<<(t->col ? "BLACK":"RED")<<endl;
        inorder(t->right);
    }
    void postorder(Node<T> *t)
    {
        if(t == NULL)return ;
        postorder(t->left);
        postorder(t->right);
        cout<<t->data<<"-"<<(t->col ? "BLACK":"RED")<<endl;
    }
    bool isLeaf(Node<T> *t)
    {
        if(t->right == NULL && t->left == NULL)
            return true;
        
        return false;
    }
    bool isChildRed(Node<T> *t)
    {
        if(t->left && t->left->col == RED)
            return true;
        
        if(t->right && t->right->col == RED)
            return true;
        
        return false;
    }
    bool isGrandparent(Node<T> *t)
    {
        if(t->left)
        {
            if(t->left->right || t->left->left)
                return true;
        }

        if(t->right)
        {
            if(t->right->right || t->right->left)
                return true;    
        }

        return false;
    }
    Node<T> *makeEmpty(Node<T> *t)
    {
        if(t == NULL)return NULL;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return NULL;
    }
    Node<T> *resolve(Node<T> *t)
    {        
        if(isGrandparent(t))
        {
            if(t->right && t->left)
            {
                if(t->right->col == RED && t->left->col == RED)
                {
                    if(isChildRed(t->right) || isChildRed(t->left))
                    {
                        t->right->col = t->col;
                        t->left->col = t->col;
                        t->col = RED;
                    }
                }

                else if(t->right->col == RED && t->left->col == BLACK)
                {
                    if(t->right->right && t->right->right->col == RED)
                    {
                        t = rotateRightChild(t);
                        t->col = BLACK;
                        t->left->col = RED;
                    }
                    
                    else if(t->right->left && t->right->left->col == RED)
                    {
                        t = doubleRotateRight(t);
                        t->col = BLACK;
                        t->left->col = RED;
                    }
                        
                }

                else if(t->right->col == BLACK && t->left->col == RED)
                {
                    if(t->left->right && t->left->right->col == RED)
                    {
                        t = doubleRotateLeft(t);
                        t->col = BLACK;
                        t->right->col = RED;
                    }   
                    
                    else if(t->left->left && t->left->left->col == RED)
                    {
                        t = rotateLeftChild(t);
                        t->col = BLACK;
                        t->right->col = RED;  
                    }
                        
                }
            }

            else if(t->right && t->right->col == RED)
            {
                if(t->right->right && t->right->right->col == RED)
                {
                    t = rotateRightChild(t);
                    t->col = BLACK;
                    t->left->col = RED;
                }
                
                else if(t->right->left && t->right->left->col == RED)
                {
                    t = doubleRotateRight(t);
                    t->col = BLACK;
                    t->left->col = RED;
                }
            }

            else if(t->left && t->left->col == RED)
            {
                if(t->left->right && t->left->right->col == RED)
                {
                    t = doubleRotateLeft(t);
                    t->col = BLACK;
                    t->right->col = RED;
                }  
                
                else if(t->left->left && t->left->left->col == RED)
                {
                    t = rotateLeftChild(t);
                    t->col = BLACK;
                    t->right->col = RED;  
                }
            }
        }

        return t;
    }
    Node<T> *insert(Node<T> *t, T x)
    {
        if(t == NULL)t = new Node<T>(x);
        else if(x < t->data) t->left = insert(t->left, x);
        else if(x > t->data)t->right = insert(t->right, x);
        t = resolve(t);
        return t;    
    }
    Node<T> *remove(Node<T> *t, T x)
    {
        Node<T> *temp;

        if(t == NULL)return NULL;
        else if(x > t->data)t->right = remove(t->right, x);
        else if(x < t->data)t->left = remove(t->left, x);
        else if(t->left && t->right)
        {
            temp = maximum(t->left);
            t->data = temp->data;
            t->left = remove(temp, temp->data);
        }
        else
        {
            temp = t;
            if(t->left == NULL)t = t->right;
            else if(t->right == NULL)t = t->left;
            delete temp;     
        }
        t = resolve(t);
        return t;
    }

    public:
    RBT()
    {
        root = NULL;
    }
    ~RBT()
    {
        root = makeEmpty(root);
    }
    Node<T>* insert(T x)
    {
        root = insert(root, x);
        root->col = BLACK;
        return root;
    }
    Node<T>* remove(T x)
    {
        root = remove(root, x);
        root->col = BLACK;
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