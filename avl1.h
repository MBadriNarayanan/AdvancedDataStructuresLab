#include"avl.h"

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
AVL<T> :: AVL()
{
    root = NULL;
}


template<class T>
void AVL<T> :: inorder(Node<T>* r)
{
    if (r==NULL)return;
    inorder(r->left);
    cout<<" "<<r->data<<" ";
    inorder(r->right);
}


template<class T>
void AVL<T> :: preorder(Node<T>* r)
{
        if (r==NULL)return;
        cout<<" "<<r->data<<"  ";
        preorder(r->left);
        preorder(r->right);
}


template<class T>
void AVL<T> :: postorder(Node<T> *r)
{
	if(r == NULL)return;
	postorder(r->left);
	postorder(r->right);
	cout<<" "<<r->data<<"  ";
}


template<class T>
Node<T>* AVL<T> :: minimum(Node<T>* r)
{
        Node<T>* temp = r;
        while (temp->left!=NULL)
            temp = temp->left;
        return temp;
}


template<class T>
Node<T>* AVL<T> :: maximum(Node<T>* r)
{
        Node<T>* temp = r;
        while (temp->right!=NULL)
            temp = temp->right;
        return temp;
}

template<class T>
int AVL<T> :: height(Node<T>* p)
{
    int hl, hr;
    hl = (p && p->left) ? (p->left)->height : 0;
    hr = (p && p->right) ? (p->right)->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}


template<class T>
int AVL<T> :: balanceFactor(Node<T>* r)
{
    return height(r->left)-height(r->right);
}


template<class T>
Node<T>* AVL<T> :: LRotation(Node<T>* r)
{
    Node<T>* rc = r->right;
    r->right = rc->left;
    rc->left = r;
    r->height = height(r);
    rc->height = height(rc);
    return rc;
}


template<class T>
Node<T>* AVL<T> :: RRotation(Node<T>* r)
{
    Node<T>* lc = r->left;
   	r->left = lc->right;
    lc->right = r;
    r->height = height(r);
    lc->height = height(lc);
    return lc;
}



template<class T>
Node<T>* AVL<T> :: LRRotation(Node<T>* r)
{
    r->left = LRotation(r->left);
    r = RRotation(r);
    return r;
}


template<class T>
Node<T>* AVL<T> :: RLRotation(Node<T>* r)
{
    r->right = RRotation(r->right);
    r = LRotation(r);
    return r;
}



template<class T>
Node<T>* AVL<T> :: insert(Node<T>* r, T x)
{
    if (r==NULL)r = new Node<T>(x);
    else
    {
        if (x>r->data)r->right = insert(r->right, x);
        else if (x<r->data)r->left = insert(r->left, x);
    }
    r->height = height(r);
    if (balanceFactor(r)==2 && balanceFactor(r->left)==1)r = RRotation(r);
    if (balanceFactor(r)==2 && balanceFactor(r->left)==-1)r = LRRotation(r);
    if (balanceFactor(r)==-2 && balanceFactor(r->right)==1)r = RLRotation(r);
    if (balanceFactor(r)==-2 && balanceFactor(r->right)==-1)r = LRotation(r);
    return r;
}



template<class T>
Node<T>* AVL<T> :: deleteNode(Node<T>* r, T data) 
{ 
    if (r == NULL) return r; 
    if (data < r->data)r->left = deleteNode(r->left, data); 
    else if (data > r->data) r->right = deleteNode(r->right, data); 
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
    r->height = height(r); 
    if (balanceFactor(r)==2 && ((balanceFactor(r->left)==1) || (balanceFactor(r->left)==0)))r = RRotation(r);                
   	if (balanceFactor(r)==2 && balanceFactor(r->left)==-1)r = LRRotation(r);
   	if (balanceFactor(r)==-2 && ((balanceFactor(r->right)==1) || (balanceFactor(r->right)==0)))r = RLRotation(r);
    if (balanceFactor(r)==-2 && balanceFactor(r->right)==-1)r = LRotation(r);
    return r; 
} 



template<class T>
Node<T>* AVL<T> :: insert(T x)
{
    root = insert(root, x);
    return root;
}


template<class T>   
Node<T>* AVL<T> :: deleteNode(T x)
{
    root = deleteNode(root, x);
    return root;
}


template<class T>    
void AVL<T> :: display()
{
    cout<<"\n\n InOrderDisplay \n\n";
    inorder(root);
}


template<class T>
Node<T>* AVL<T> :: getRoot()
{
    return root;
}