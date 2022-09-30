#include <iostream>
struct Node
{
    double data;
    Node *next;
};

Node* InitList(int x)
{
    Node* c = new Node;
    c->next = c;
    c->data = x;
    return c;
}

void Free_Memory(Node* head, Node* end) {
    if (head == NULL) return;
    Node* c = head;
    end->next = NULL;
    while (c != NULL )
    {
        head = head->next;
        delete c;
        c = head;
    }
}

Node* AddNodeAfter(Node* &ptr, int x)
{
    Node* c = new Node;
    c->next = c;
    c->data = x;
    if (ptr == NULL)
        return NULL;
    else
    {
        c->next = ptr->next;
        ptr->next = c;
        ptr = c;
        return c->next;
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
        if (c == head)
        {
            break;
        }
        
    }
    std::cout << std::endl;
}



Node* DeleteNode(Node* &ptr)
{
    if (ptr == NULL) return NULL;
    Node* prev = ptr->next;
    while (prev && prev->next != ptr)
        prev = prev->next;
    if (prev!=ptr)
     {
           prev->next = ptr->next;
           delete ptr;
           return prev->next;
     }
    else
    {
        delete ptr; ptr = NULL;
        return NULL;
    }
}

int main()
{
    Node* head = NULL, *end = NULL, *c; int x;
    int count(0x0);
    double sum(0x0);
    std::cout << "Input 0xA elements:" << std::endl;
    for (int i = 1; i <= 0xA; i++)
    {
        std::cin >> x;
        sum += x;
        if (i == 0x1)
        {
            head = end = InitList(x);
        }
        else
        {
            AddNodeAfter(end, x);
        }
        count++;
    }
    c = head;
    count = 0;
    do
    {
        if (c->data > sum)
        {
            if (c == head)
            {
                sum -= c->data;
                head = c = DeleteNode(c);

            }
            else if (c == end)
            {
                sum -= c->data;
                end = c = DeleteNode(c);
            }
            else
            {
                sum -= c->data;
                c = DeleteNode(c);
            }
        }
        else
        {
            c = c->next;
        }
    }
    while (c != NULL && (c != head || c != end));
    Print_Right(head);
    Free_Memory(head,end);
    return 0;
}

/*
 Створити циклічний список із чисел. Визначити, чи є в списку дійсних чисел елементи, що перевершують суму всіх елементів списку. Видалити ці елементи
 */


