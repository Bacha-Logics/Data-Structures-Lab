#include<iostream>

using namespace std;

struct node
{
    int info;
    node * right , * left;
};

class AVL
{
    node * root;
public:
    AVL();
    void bst_to_avl(int);   // function converting bst to AVL
    void inserting(int , node *&);                          //I wanted to make Root Private thats why I need two funs for deleting and Inserting
    void in_order_traversal(node * = NULL);
    int BalanceFactor(node * = NULL);   //  balance factor using in AVL
    int Height(node * = NULL);   
    void RotateRight(node *&);
    void RotateLeft(node *&);
    
};


AVL::AVL()
{
    root = NULL;
}


void AVL::bst_to_avl(int key)
{
    inserting(key , root);
}

void AVL::inserting(int key , node *& temp)
{
    if(root == NULL)
    {
        root = new node;
        root->right = root->left = NULL;
        root->info = key;
        return;
    }
    if(temp->info == key)
    {
        cout << "Duplication Not Allowed!" << endl;
        return;
    }
    if(temp->info > key)
    {
        if(temp->left == NULL)
        {
            temp->left = new node;
            temp->left->left = temp->left->right = NULL;
            temp->left->info = key;
            return;
        }
        else
        {    
            inserting(key , temp->left);
        }
    }
    else
    {
        if(temp->right == NULL)
        {
            temp->right = new node;
            temp->right->left = temp->right->right = NULL;
            temp->right->info = key;
            return;
        }
        else
        {
            inserting(key, temp->right);
        }
    }
    int BF = BalanceFactor(temp);
    if(BF == 2)
    {   
        if(key < temp->left->info)
        {
            RotateRight(temp);
        }
        else
        {
            RotateLeft(temp->left);
            RotateRight(temp);
        }
    }
    if(BF == -2)
    {
        if(key > temp->right->info)
        {
            RotateLeft(temp);
        }
        else
        {
            RotateRight(temp->right);
            RotateLeft(temp);
        }
    }
}


int AVL::BalanceFactor(node * temp)
{
    if(temp == NULL)
        return 0;
    int l_subtree =  0;
    int r_subtree = 0;
    if(temp->left != NULL)
    {
        l_subtree++;
        l_subtree +=  Height(temp->left);
    }
    if(temp->right != NULL)
    {
        r_subtree++;
        r_subtree +=  Height(temp->right);
    }

    return l_subtree - r_subtree;
}

int AVL::Height(node * temp)
{
    if(temp == NULL)
        return 0;
    int count_r = 0;
    int count_l = 0;
    if(temp->left != NULL)
    {
        count_l++;
        count_l += Height(temp->left);
    }
    if(temp->right != NULL)
    {
        count_r++;
        count_r += Height(temp->right);
    }
    if(count_r > count_l)
        return count_r;
    else
        return count_l;
}

void AVL::RotateRight(node *& temp)
{
    node * temp2 = temp->left;
    temp->left = temp2->right;
    temp2->right = temp;
    temp = temp2;
}

void AVL::RotateLeft(node *& temp)
{
    node * temp2 = temp->right;
    temp->right = temp2->left;
    temp2->left = temp;
    temp = temp2;
}


void AVL::in_order_traversal(node * temp)
{
    if(root == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    if(temp == NULL)
        temp = root;
    if(temp->left != NULL)
        in_order_traversal(temp->left);
    cout << temp->info << ' ';
    if(temp->right != NULL)
        in_order_traversal(temp->right);
}


int main()
{
    AVL tree1;
    tree1.bst_to_avl(1);
    tree1.bst_to_avl(2);
    tree1.bst_to_avl(3);
    tree1.bst_to_avl(4);
    tree1.bst_to_avl(5);
 
    tree1.in_order_traversal();
    cout << endl;

    return 0;
}
