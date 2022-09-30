#include <iostream>
struct Node
{
    char data;
    Node *next;
};


Node* deleteNodePtr(Node* &head, Node* &end, Node* ptr)
{
    if (ptr == NULL)
        return NULL;
    Node* c = head;
    if (ptr == head)
    {
        head = head->next;
        delete c;
        return head;
    }
    c = head;
    while (c->next != ptr && c != NULL)
        c = c->next;
    if (c == NULL)
        return NULL;
    c->next = ptr->next;
    if (ptr == end)
        end = c;
    delete ptr;
    return c->next;
}

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
    Node *head = NULL, *c, *end = NULL;
    do {
        c = new struct Node;
        c->next = NULL;
        std::cin>>c->data;
        if (c->data == 33)
        {
            break;
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
    } while (true);
    c=head;
    while (c!=NULL)
    {
        std::cout<<c->data<<" ";
        c=c->next;
        
    }
    std::cout<<std::endl;
    c=head;
    while (c!=NULL)
    {
        if (c->data < 57 && c->data > 48) {
            c = deleteNodePtr(head, end, c);
        }
        else
        {
            c = c->next;
        }
    }
    c = head;
    if (c == NULL)
    {
        std::cout<<"EMPTY";
    }
    
    while (c!=NULL)
    {
        std::cout<<c->data<<" ";
        c=c->next;
        
    }
    std::cout<<std::endl;
    
    Free_Memory(head);
    return 0;
}

/*Видалити зі списку всі цифри*/
