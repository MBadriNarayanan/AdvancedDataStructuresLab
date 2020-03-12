#include"bst.h"

template<class T>
Node<T> :: Node()
{
    right = NULL;
    left = NULL;
    height = 0;
}

template<class T>
Node<T> :: Node(T x)
{
    right = NULL;
    left = NULL;
    data = x;
    height = 0;
}

template<class T>
Node<T>* BST<T> :: insert(Node<T>* r, T x)
{
        if (r==NULL)
            r = new Node<T>(x);
        else
        {
            if (x>r->data)
                r->right = insert(r->right, x);
            else if (x<r->data)
                r->left = insert(r->left, x);
        }
        return r;
}

template<class T>
void BST<T> :: inorder(Node<T>* r)
{
        if (r==NULL)
            return;
        inorder(r->left);
        cout<<" "<<r->data<<"  ";
        inorder(r->right);
}

template<class T>
void BST<T> :: preorder(Node<T>* r)
{
        if (r==NULL)
            return;
        cout<<" "<<r->data<<"  ";
        preorder(r->left);
        preorder(r->right);
}

template<class T>
void BST<T> :: postorder(Node<T> *r)
{
	if(r == NULL)return;
	postorder(r->left);
	postorder(r->right);
	cout<<" "<<r->data<<"  ";
}

template<class T>
Node<T>* BST<T> :: minimum(Node<T>* r)
{
        Node<T>* temp = r;
        while (temp->left!=NULL)
            temp = temp->left;
        return temp;
}

template<class T>
Node<T>* BST<T> :: maximum(Node<T>* r)
{
        Node<T>* temp = r;
        while (temp->right!=NULL)
            temp = temp->right;
        return temp;
}

template<class T>
Node<T>* BST<T> :: deleteNode(Node<T>* r, T data) 
{ 
        if (r == NULL) return r; 
        if (data < r->data) 
            r->left = deleteNode(r->left, data); 
        else if (data > r->data) 
            r->right = deleteNode(r->right, data); 
        else
        { 
            if (r->left == NULL) 
            { 
                Node<T>* temp = r->right; 
                delete r;
                return temp; 
            } 
            else if (r->right == NULL) 
            { 
                Node<T>* temp = r->left; 
                delete r;
                return temp; 
            } 
            Node<T>* temp = minimum(r->right); 
            r->data = temp->data; 
            r->right = deleteNode(r->right, temp->data); 
        } 
        return r; 
} 

template<class T>
BST<T> :: BST()
{
    root = NULL;
}

template<class T>
Node<T>* BST<T> :: insert(T x)
{
   root = insert(root, x);
   return root;
}

template<class T>
void BST<T> :: display()
{
	cout<<"\n\n InOrderDisplay \n\n";
    inorder(root);
}

template<class T>
Node<T>* BST<T> :: deleteNode(T data)
{
    return deleteNode(root, data);
}