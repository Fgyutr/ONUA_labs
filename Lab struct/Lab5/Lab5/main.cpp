#include <iostream>


struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node* InitList(int x)
{
    Node* c = new Node;
    c->next = NULL;
    c->prev = NULL;
    c->data = x;
    return c;
}

void Free_Memory(Node* head, Node* end) {
    if (head == NULL) return;
    Node* c = head;
    end->next = NULL;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
}

void AddNodeAfter(Node* &ptr, int x)
{
    if (ptr == NULL){
        return;
    }
    else
    {
        Node* c = new Node;
        c->data = x;
        c->next = ptr->next;
        c->prev = ptr;
        if (ptr->next != NULL)
            ptr->next->prev = c;
        ptr->next = c;
        ptr = c;
    }
}

void Print_Right(Node* head)
{
    std::cout << "The list from head to end:" << std::endl;
    if (head == NULL)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    Node* c = head;
    while (c != NULL)
    {
        std::cout << c->data << " ";
        c = c->next;
        
    }
    std::cout << std::endl;
}

int main()
{
    Node* head = NULL, *end = NULL, *c;
    int x;
    int chislo(0);
    bool temp = false;
    std::cout << "Input 5 elements:" << std::endl;
    for (int i = 1; i <= 5; i++)
    {
        std::cin >> x;
        if (i == 1)
        {
            head = end = InitList(x);
        }
        else
        {
            AddNodeAfter(end, x);
        }
    }
    c = head;
    while (c != NULL)
    {
        if (c->data%2==0 && c->data!=0)
        {
            chislo = c->data;
            temp = true;
            c = c->next;
        }
        else
        {
            c = c->next;
        }
    }
    c = head;
    while (c != NULL)
    {
        if (c->data%2!=0)
        {
            if (!temp) {
                c = c->next;
                continue;
            }
            AddNodeAfter(c, chislo);
            if (c->next == NULL)
            {
                end = c;
            }
        }
        c = c->next;
    }
         Print_Right(head);
    Free_Memory(head,end);
    return 0;
}



/*Створити лінійний двозв'язний список з цілих чисел. Вставити в список останній парний елемент після кожного непарного елемента*/
