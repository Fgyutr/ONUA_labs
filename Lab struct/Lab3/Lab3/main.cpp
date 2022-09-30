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
    int count_pluss(0), count_minus(0);
    Node *head = NULL, *c, *end = NULL;
    do {
        c = new struct Node;
        c->next = NULL;
        std::cin>>c->data;
        if (c->data>0) {
            count_pluss++;
        }
        else if (c->data<0)
        {
            count_minus++;
        }
        if(head == NULL)
        {
            head = c;
            end = c;
            if (c->data>0) {
                Node *d = new struct Node;
                d->data = c->data;
                d->next = NULL;
                end->next=d;
                end = d;
            }
        }
        else
        {
            end->next = c;
            end = c;
        }
    } while (count_pluss>count_minus);
    c=head;
    while (c!=NULL)
    {
        std::cout<<c->data<<" ";
        c=c->next;
    }
    Free_Memory(head);
    return 0;
}

/*Продублювати в списку перший додатний елемент (якщо такого немає, залишити список без зміни)*/
