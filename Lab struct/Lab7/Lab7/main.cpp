#include <iostream>

struct NodeOne
{
    double data;
    NodeOne *next;
};
struct NodeTwo
{
    double data;
    NodeTwo *prev;
    NodeTwo *next;
};
NodeOne* InitListOne(double x)
{
    NodeOne* c = new NodeOne;
    c->next = c;
    c->data = x;
    return c;
}
NodeTwo* InitListTwo(double x)
{
    NodeTwo* c = new NodeTwo;
    c->next = NULL;
    c->prev = NULL;
    c->data = x;
    return c;
}
void Free_MemoryOne(NodeOne* head, NodeOne* end) {
    if (head == NULL) return;
    NodeOne* c = head;
    end->next = NULL;
    while (c != NULL )
    {
        head = head->next;
        delete c;
        c = head;
    }
}
void Free_MemoryTwo(NodeTwo* head, NodeTwo* end) {
    if (head == NULL) return;
    NodeTwo* c = head;
    end->next = NULL;
    while (c != NULL)
    {
        head = head->next;
        delete c;
        c = head;
    }
}
NodeOne* AddNodeAfterOne(NodeOne* &ptr, double x)
{
    if (ptr == NULL)
        return NULL;
    else
    {
        NodeOne* c = new NodeOne;
        c->next = c;
        c->data = x;
        c->next = ptr->next;
        ptr->next = c;
        ptr = c;
        return c->next;
    }
}
void AddNodeAfterTwo(NodeTwo* &ptr, double x)
{
    if (ptr == NULL){
        return;
    }
    else
    {
        NodeTwo* c = new NodeTwo;
        c->data = x;
        c->next = ptr->next;
        c->prev = ptr;
        if (ptr->next != NULL)
            ptr->next->prev = c;
        ptr->next = c;
        ptr = c;
    }
}
void Print_RightOne(NodeOne* head)
{
    if (head == NULL)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    NodeOne* c = head;
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

void Print_RightTwo(NodeTwo* head)
{
    if (head == NULL)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    NodeTwo* c = head;
    while (c != NULL)
    {
        std::cout << c->data << " ";
        c = c->next;
    }
    std::cout << std::endl;
}
int main()
{
    setlocale(LC_ALL, "");
    NodeTwo *headTwo = NULL,*c, *endTwo = NULL;
    double sum_mod(0), sum_fifteen(0), x;
    NodeOne *headOne = NULL, *endOne = NULL;
    std::cout << "Введите 10 чисел:" << std::endl;
    for (int i(0); i < 10; i++) {
        std::cin >> x;
        
        if (x < 0)
        {
            sum_mod+=-1*x;
        }
        else
            sum_mod+=x;
        if (x>=15)
            sum_fifteen += x;
        if (i == 0)
        {
            headTwo = endTwo = InitListTwo(x);
        }
        else
        {
            AddNodeAfterTwo(endTwo, x);
        }
    }
    c = headTwo;
    while (c != NULL) {
        if(c->data<0){
            if  ( c->data!= 10.5 && (headOne == NULL ||endOne == NULL)) {
                headOne = endOne = InitListOne(c->data);
                c=c->next;
                continue;
            }
            else
            {
                AddNodeAfterOne(endOne, c->data);
                c=c->next;
                continue;
            }
        }
        c=c->next;
    }
    std::cout << "Сумма чисел больше 15: " << sum_fifteen << std::endl;
    std::cout << "Сумма модулю: " << sum_mod << std::endl;
    std::cout << "Двусвязный список: " << std::endl;
    Print_RightTwo(headTwo);
    std::cout << "Односвязный список: " << std::endl;
    Print_RightOne(headOne);
    Free_MemoryOne(headOne, endOne);
    Free_MemoryTwo(headTwo, endTwo);
    return 0;
}

/*
 Створити циклічний двозв'язний список із дійсних чисел. Визначити суму модулів елементів списку. Визначити суму елементів списку зі значеннями більше або рівними 15. Створити циклічний однозв'язний список із негативних елементів вихідного списку, не рівних 10,5.
 */
