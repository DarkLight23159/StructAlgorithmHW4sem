#include"BinarySearchTree.h"
#include<iostream>

tree *node(int value){  //create new node
    tree *n = new tree;
    n->Value=value;
    n->left=nullptr;
    n->right=nullptr;
    n->parent=nullptr;
    return n;
}

void insert(tree *&tr, int value)   
{
    tree *newNode = node(value); // create new node
    if(!tr) tr = newNode;// If tree is empty, nNode is root
    else
    {
        tree *y = tr;
        while(y)
        {
            if (newNode->Value > y->Value)
            {
                if (y->right)
                {
                    y = y->right;
                }
                else
                {
                    newNode->parent = y;
                    y->right=newNode;
                    break;
                }
            }
            else if (newNode->Value < y->Value )
                {
                    if (y->left)   
                    {
                    y=y->left;    
                    }
                    else{
                        newNode->parent = y;
                        y->left=newNode;
                        break;
                    }
                }
                
            }
        }
    }

void Delete(tree*& tr, tree* node){ 
        tree *nodeParent = node->parent;
        if (!nodeParent) tr = nullptr;
        else if (!node->left && !node->right)
        {
            if (nodeParent->left==node)
            {
                nodeParent->left=nullptr;
            }
            if (nodeParent->right==node)
            {
                nodeParent->right=nullptr;
            }
            delete node;
            }
        else if (!node->left||!node->right)
        {
            if (!nodeParent)
            {
                if (!node->left)
                {
                    tr = node->right;
                    node->parent = nullptr;
                }
                else{
                    tr= node->left;
                    node->parent = nullptr;
                }
            }
            else
            {
            if (!node->left) {
                if (nodeParent->left == node) {
                    nodeParent->left = node->right;
                }
                else {
                    nodeParent->right = node->right;
                }
                node->right->parent = nodeParent;
            }
            else {
                if (nodeParent->left == node) {
                    nodeParent->left = node->left;
                }
                else {
                    nodeParent->right = node->left;
                }
                node->left->parent = nodeParent;
            }
            delete node;
        }
    }
    else {
        tree *succ = next(tr, node->Value);
        node->Value = succ->Value;

        if (succ->parent->left == succ) {
            succ->parent->left = succ->right;
            if (succ->right) {
                succ->right->parent = succ->parent;
            }
        }
        else {
            succ->parent->right = succ->right;
            if (succ->right) {
                succ->right->parent = succ->parent;
            }
        }
        delete succ;
    }
}

tree *next(tree *tr, int value) {
    tree *node = find(tr, value);
    if (node->right) {
        return min(node->right);
    }
    tree *nodeParent = node->parent;
    while (nodeParent && node == nodeParent->right) {
        node = nodeParent;
        nodeParent = nodeParent->parent;
    }
    return nodeParent;
}

tree *find(tree *tr, int value) {
    if (tr->Value == value || !tr) {
        return tr;
    }
    if (tr->Value < value) {
        return find(tr->right, value);
    }
    else {
        return find(tr->left, value);
    }
}

tree *min(tree *tr) {
    if (!tr->left) {
        return tr;
    }
    else {
        return min(tr->left);
    }
}
    

void preorder (tree *tr) //прямой обход NLR
{
    if(tr){
        std::cout<<tr->Value<<" ";
        preorder(tr->left);
        preorder(tr->right);
    }
}

void postorder (tree *tr)//обратный обход LRN
{
    if (tr) {
        postorder(tr->left);
        postorder(tr->right);
        std::cout << tr->Value << " ";
    }
}

void inorder (tree *tr) //симетричный обход LNR
{
    if (tr)
    {
        inorder(tr->left);
        std::cout << tr->Value << " ";
        inorder(tr->right);
    }
}   