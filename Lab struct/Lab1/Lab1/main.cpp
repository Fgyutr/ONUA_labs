#include <iostream>
struct Node
{
    double data;
    Node *next;
};

void Free_Memory(Node* head) {
    if (head == NULL) return;
    Node* c = head;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
}

int main()
{
    double sum = 0;
    Node *head = NULL, *c, *end = NULL;
    do {
        c = new struct Node;
        c->next = NULL;
        std::cin>>c->data;
        if (c->data > 9 && c->data < 100)
        {
            sum+=c->data;
        }
        if(head == NULL)
        {
            head = c;
            end = c;
        }
        else
        {
            end->next = c;
            end = c;
        }
    } while (c->data!=999);
    std::cout<<sum<<std::endl;
    Free_Memory(head);
    return 0;
}

/*Обчислити суму тільки двоцифрових елементів*/
