#pragma once

struct tree //tree struct
{
int Value;
tree *left;
tree *right;
tree *parent;
};

tree *node(int Value);

void insert(tree *&tr, int value);  //Insert node with value
void Delete(tree *&tr, tree *node); //Delete Node

tree *find(tree *tr,   int Value);  //Find node by Value
tree *min(tree *tr);                //Find min node
tree *next(tree *tr, int value);    //Find next node



void preorder (tree *tr); //прямой обход
void postorder (tree *tr);//обратный обход
void inorder (tree *tr);  //симетричный обход  
