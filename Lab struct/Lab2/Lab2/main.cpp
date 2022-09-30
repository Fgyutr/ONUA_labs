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
    int count = 0;
    Node *head = NULL, *c, *end = NULL;
    do {
        c = new struct Node;
        c->next = NULL;
        std::cin>>c->data;
        count++;
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
    } while (count<=10);
    c=head;
    double min(c->data);
    while (c!=NULL)
    {
        if(min > c->data)
        {
            min = c->data;
        }
        c=c->next;
    }
    c=head;
    while (c!=NULL)
    {
        if(c->data == 0)
        {
            c->data = min;
        }
        c=c->next;
    }
    c=head;
    while (c!=NULL)
    {
        std::cout<<c->data<<" ";
        c=c->next;
    }
    Free_Memory(head);
    return 0;
}


/*Замінити всі нульові елементи значенням мінімального елемента*/
