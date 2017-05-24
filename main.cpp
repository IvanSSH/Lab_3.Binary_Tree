#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

struct BinaryTree{
       int Data;
       char Str[32];
       BinaryTree* Left;
       BinaryTree* Right;
};

                                                            //создание бинарного дерева
void Make_Tree(BinaryTree** Node, int n){
  BinaryTree** ptr;
  while (n > 0) {
    ptr = Node;
    while (*ptr != NULL) {
      if ((double) rand()/RAND_MAX < 0.5)                   //Random
        ptr = &((*ptr)->Left);
      else ptr = &((*ptr)->Right);
    }
    (*ptr) = new BinaryTree();
    cout << "Enter the value and string ";
    cin >> (*ptr)->Data;
    cin >> (*ptr)->Str;
    n--;
  }
}

                                                            //печать бинарного дерева
void Print_Tree(BinaryTree* Node, int l){
  int i;
  if (Node != NULL) {
    Print_Tree(Node->Right, l+1);
    for (i=0; i< l; i++) cout << "     ";
    printf ("%d_%s", Node->Data,Node->Str);
    Print_Tree(Node->Left, l+1);
  }
  else cout << endl;
}

                                                            //прямой обход бинарного дерева
void Direct_go(BinaryTree* Node){
  if (Node != NULL) {
    printf ("%5d_%s",Node->Data,Node->Str);
    Direct_go(Node->Left);
    Direct_go(Node->Right);
  }
}

                                                            //обратный обход бинарного дерева
void Back_go(BinaryTree* Node){
  if (Node != NULL) {
    Back_go(Node->Left);
    Back_go(Node->Right);
    printf ("%5d_%s",Node->Data,Node->Str);
  }
}

                                                            //симметричный обход бинарного дерева
void Symmetric_go(BinaryTree* Node){
  if (Node != NULL) {
    Back_go(Node->Left);
    printf ("%5d_%s",Node->Data,Node->Str);
    Back_go(Node->Right);
  }
}

                                                            //отчистка памяти
void Delete_BinaryTree(BinaryTree* Node){
  if (Node != NULL) {
    Delete_BinaryTree(Node->Left);
    Delete_BinaryTree(Node->Right);
    delete(Node);
  }
}

void Find(BinaryTree* Node, int val){
  if (Node != NULL) {
    if (val == Node->Data) printf ("%3d_%s\n",Node->Data,Node->Str);
    Find(Node->Left,val);
    Find(Node->Right,val);
  }
}


int main()
{
    int num;
    BinaryTree* BTree = NULL;
    cout << "The number of elements:  " << endl;
    cin >> num;
    Make_Tree(&BTree,num);
    Print_Tree(BTree,1);

    cout << "The element you want to find:  " << endl;       // ввод числа, по которому будет пои узла
    cin >> num;
    Find(BTree,num);

    cout << "\nDirect_go: " << endl;                         // прямой обх.
    Direct_go(BTree);
    cout << "\nBack_go: " << endl;                           // обратный обх.
    Back_go(BTree);
    cout << "\nSymmetric_go: " << endl;                      // СИмметричный обх.
    Symmetric_go(BTree);

    Delete_BinaryTree(BTree);


    return 0;
}
