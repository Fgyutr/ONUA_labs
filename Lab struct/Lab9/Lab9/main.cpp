
#include <iostream>
#include <cmath>
using namespace std;
struct BinTree
{
    int value;
    BinTree* left;
    BinTree* right;
};

void newBinTree(int val, BinTree** Tree)
{
    if ((*Tree) == NULL)
    {
        (*Tree) = new BinTree;
        (*Tree)->value = val;
        (*Tree)->left = (*Tree)->right = NULL;
        return;
    }
    if (val > (*Tree)->value) newBinTree(val, &(*Tree)->right);
    else newBinTree(val, &(*Tree)->left);
}

void Print(BinTree*Tree, int l)
{
    int i;
 
    if (Tree != NULL)
    {
        Print(((*Tree).right), l + 1);
        for (i = 1; i <= l; i++) cout << "   ";
        cout << (*Tree).value << endl;
        Print(((*Tree).left), l + 1);
    }
}

BinTree* Search(BinTree* Tree, int key) {
    if (Tree == NULL)
        return NULL;
    if  (Tree->value == key)
        return Tree;
    if (key < Tree->value)
        return Search(Tree->left, key);
    else
        return Search(Tree->right, key);
}

int NumberOfNodes(BinTree* Tree)
{
    if (Tree == NULL) return 0;
    return NumberOfNodes(Tree->left) + 1+ NumberOfNodes(Tree->right);
}

int List(BinTree* node)
{
    if (!node)
        return 1;
    if (!node->left && !node->right)
        return node->value;
    return  List(node->left) * List(node->right);
}

BinTree* DestroyBTree(BinTree* Tree)
{
    if (Tree != NULL) {
        DestroyBTree(Tree->left);
        DestroyBTree(Tree->right);
        delete(Tree);
    }
    return NULL;
}

BinTree* DestroyNode(BinTree* TreeRoot, BinTree* TreeNode)
{
    if (TreeRoot != NULL && TreeNode != NULL) {
        if (TreeRoot->value == TreeNode->value) {
            TreeRoot = DestroyBTree(TreeRoot);
        }
        else if (TreeRoot->value < TreeNode->value && TreeRoot->right && TreeRoot->right->value != TreeNode->value)
        {
            DestroyNode(TreeRoot->right, TreeNode);
        }
        else if (TreeRoot->value > TreeNode->value && TreeRoot->left && TreeRoot->left->value != TreeNode->value)
        {
            DestroyNode(TreeRoot->left, TreeNode);
        }
        else if (TreeRoot->value < TreeNode->value && TreeRoot->right->value == TreeNode->value)
        {
            DestroyBTree (TreeNode);
            TreeRoot->right = NULL;
        }
        else if (TreeRoot->value > TreeNode->value && TreeRoot->left->value == TreeNode->value)
        {
            DestroyBTree (TreeNode);
            TreeRoot->left = NULL;
        }
    }
    else
    {
        return NULL;
    }
    return TreeRoot;
}
void MenuProc()
{
    BinTree* Tree = NULL;
    int val;
    cout << "ведите значение: " << endl;
    for (int i(0); i<15; i++) {
        cin >> val;
        newBinTree(val, &Tree);
    }
    Print(Tree, 0);
    cout << "Произведение листьев в дереве-> ";
    long b = List(Tree);
    cout << b<< endl;
    cout << "Поиск элемента" << endl;
    int key;
    cout << "Введите значение элемента для поиска-> ";
    cin >> key;
    BinTree* Tree1 = Search(Tree,key);
    if (Tree1 == NULL)
        cout << "Элемент не найден";
    else
        cout << "Ваш элемент->" << Tree1->value;
    cout << endl;
    Tree = DestroyNode(Tree,Tree1);
    Print(Tree, 0);
    Tree = DestroyBTree(Tree);
    if (Tree) {
        Print(Tree, 0);
    }
    else
        cout << "Empty" << endl;
}
 
int main() {
    MenuProc();
    return 0;
}


// 44 49 65 42 19 91 66 87 57 24 14 6 95 75 99

 schitaem(tree->right, n+1)
schitaem(tree->left, n+1)
if (n == 4 )

