#include <iostream>
#include <cmath>
using namespace std;
struct BinTree
{
    int value;
    BinTree* left, *right;
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

void Print(BinTree**Tree, int l)
{
    int i;
    if (*Tree != NULL)
    {
        Print(&((**Tree).right), l + 1);
        for (i = 1; i <= l; i++) cout << "   ";
        cout << (**Tree).value << endl;
        Print(&((**Tree).left), l + 1);
    }
}
 
void TreeTraversalAndPrint(BinTree* Root)
{
    if (Root != NULL)
    {
        cout << Root->value << " ";
        TreeTraversalAndPrint(Root->left);
        TreeTraversalAndPrint(Root->right);
 
    }
    
}
 
void TreeTraversalAndPrint2(BinTree* Root)
{
    if (Root != NULL)
    {
        TreeTraversalAndPrint2(Root->left);
        TreeTraversalAndPrint2(Root->right);
        cout << Root->value << " ";
    }
}

void TreeTraversalAndPrint3(BinTree* Root)
{
    if (Root != NULL)
    {
        TreeTraversalAndPrint2(Root->left);
        cout << Root->value << " ";
        TreeTraversalAndPrint2(Root->right);
    }
}

BinTree* MinValue(BinTree* Tree)
{
    if (Tree->left != NULL)
    {
        return MinValue(Tree->left);
    }
    else
    {
        return Tree;
    }
}
BinTree* MaxValue(BinTree* Tree)
{
    if (Tree->right != NULL)
    {
        return  MaxValue(Tree->right);
    }
    else
    {
        return Tree;
    }
}

int NumberOfNodes(BinTree* Tree)
{
    if (Tree == NULL) return 0;
    return NumberOfNodes(Tree->left) + 1+ NumberOfNodes(Tree->right);
}
 
int ListCount(BinTree* node)
{
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return 1;
    return  ListCount(node->left) + ListCount(node->right);
}

int List(BinTree* node)
{
    if (!node)
        return 1;
    if (!node->left && !node->right)
        return node->value;
    return  ListCount(node->left) * ListCount(node->right);
}

int HeightBTree(BinTree* Tree)
{
    int x = 0, y = 0;
    if (Tree == NULL) return 0;
    if(Tree->left) x = HeightBTree(Tree->left);
    if (Tree->right) y = HeightBTree(Tree->right);
    if (x > y) return x + 1;
    else return y + 1;
}
BinTree* Search(BinTree* Tree, int key)
{
    if (Tree == NULL) return NULL;
    if  (Tree->value == key) return Tree;
    if (key < Tree->value) return Search(Tree->left, key);
    else
        return Search(Tree->right, key);
}
 
BinTree* SearchParrent(BinTree* Tree, BinTree* Son)
{
    if (Son == NULL) {
        return NULL;
    }
    else if (Tree == Son)
    {
        return Son;
    }
    else if (Son->value == Tree->left->value)
    {
        return Tree;
    }
    else if (Son->value == Tree->right->value)
    {
        return Tree;
    }
    else if (Son->value > Tree->value)
    {
        return SearchParrent(Tree->right, Son);
    }
    else if(Son->value > Tree->value)
    {
        return SearchParrent(Tree->left, Son);
    }
    else
        return NULL;
}

BinTree* DestroyBTree(BinTree* Tree) {
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
 
int main() {
    BinTree* Tree = NULL;
    int val;
    int count;
    cout << "Введите кол-во значений: " << endl;
    cin >> count;
    for (int i(0); i<count; i++) {
        cout << "Введите значение: " << endl;
        cin >> val;
        newBinTree(val, &Tree);
    }
    Print(&Tree, 0);
    cout << "Прямой обход дерева" << endl;
    TreeTraversalAndPrint(Tree);
    cout << endl;
    cout << "Обратный обход дерева" << endl;
    TreeTraversalAndPrint2(Tree);
    cout << endl;
    cout << "Cимметричный обход дерева" << endl;
    TreeTraversalAndPrint3(Tree);
    cout << endl;
    cout << "Минимальный элемент дерева-> ";
    BinTree* min = MinValue(Tree);
    cout << min->value;
    cout << endl << "Максимальный элемент дерева-> ";
    BinTree* max = MaxValue(Tree);
    cout << max->value;
    cout << endl;
    cout << "Высота дерева-> ";
    int Heigh = HeightBTree(Tree);
    cout << Heigh;
    cout << endl;
    cout<<"Количество элементов в дереве-> ";
    int a = NumberOfNodes(Tree);
    cout << a << endl;
    cout << "Количество листов в дереве-> ";
    int b = ListCount(Tree);
    cout << b<< endl;
    cout << "Произведение листьев в дереве-> ";
    long bl = List(Tree);
    cout << bl << endl;
    cout << "Поиск элемента" << endl;
    int key;
    cout << "Введите значение элемента для поиска-> ";
    cin >> key;
    BinTree* Tree1 = Search(Tree,key);
    BinTree* Tree2 = SearchParrent(Tree,Tree1);
    if (Tree1 == NULL)
        cout << "Элемент не найден" << endl;
    else
        cout << "Ваш элемент->" << Tree1->value;
    if (Tree2 == Tree1 && Tree2 != NULL)
        cout << "Отца нет. это корень!";
    else if (Tree2 == NULL)
        cout << "Он ушёл за хлебом"<< endl;
    else
        cout << "Отец найден это ->" << Tree2->value;
    cout << endl;
    cout << "Введите значение элемента для поиска и удаления-> ";
    cin >> key;
    Tree1 = Search(Tree,key);
    if (Tree1 == NULL)
        cout << "Элемент не найден";
    else
        cout << "Ваш элемент->" << Tree1->value;
    cout << endl;
    Tree = DestroyNode(Tree,Tree1);
    Print(&Tree, 0);
    Tree = DestroyBTree(Tree);
    if (Tree) {
        Print(&Tree, 0);
    }
    else
        cout << "Empty" << endl;
    DestroyBTree(Tree);
    system("pause");
    return 0;
}
