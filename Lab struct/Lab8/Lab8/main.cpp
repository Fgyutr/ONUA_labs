#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void Free_memory(stack<int> &var, queue<int> &var2)
{
    for( ;var.size()!=0;)
        var.pop();
    for( ;var2.size()!=0;)
        var2.pop();
}
void printStack(stack<int> var)
{
    stack<int> temp = var;
    for( ;temp.size()!=0;)
    {
        cout << temp.top() << " ";
        temp.pop();
    }
}
void printQueue(queue<int> var, int kratn)
{
    queue<int> temp = var;
    for( ;temp.size()!=0;)
    {
        if(temp.front()%kratn==0)
        {
            cout << temp.front() << " ";
        }
        temp.pop();
    }
}
int main(int argc, const char * argv[])
{
    setlocale(LC_ALL, "");
    stack<int> kratnie_three;
    queue<int> kratnie_two;
    int x;
    cout<<"Введите число: ";
    cin >> x;
    for (int i(1); i <= x; i++)
    {
        if (i%2==0)
        {
            kratnie_two.push(i);
        }
        if (i%3==0)
        {
            kratnie_three.push(i);
        }
    }
    cout << endl << "1" << endl;
    printStack(kratnie_three);
    cout << endl << "2" << endl;
    printQueue(kratnie_two,1);
    
    for (; !kratnie_three.empty();) {
        x = kratnie_three.top();
        kratnie_two.push(x);
        kratnie_three.pop();
    }
    cout << endl << "3" << endl;
    printQueue(kratnie_two, 2);
    Free_memory(kratnie_three, kratnie_two);
    return 0;
}

//https://en.cppreference.com/
/*Ввести з клавіатури число X. Додати в стек кратні трьом числа з діапазону від 1 до X, а в чергу – парні з цього діапазону. Всі числа зі стека витягувати по одному і додавати в чергу. Потім числа з черги виймати по одному і парні друкувати*/
