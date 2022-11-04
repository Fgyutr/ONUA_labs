#include <iostream>
#include <vector>
using namespace std;

void SincAutomat()
{
    string Start, End;
    cout << "Введите строку: \n";
    cin >> Start;
    vector <pair<char,bool>> points;
    points.push_back(pair<char,bool> ('A',true));
    points.push_back(pair<char,bool> ('B',false));
    points.push_back(pair<char,bool> ('C',false));
    for(int i(0); i < Start.size(); i++)
    {
        if (points[0].second)
        {
            if (Start[i] == '0')
            {
                End.push_back('0');
            }
            else if(Start[i] == '1')
            {
                End.push_back('0');
                points[0].second = false;
                points[2].second = true;
            }
        }
        else if(points[1].second)
        {
            if (Start[i] == '0')
            {
                End.push_back('1');
                points[1].second = false;
                points[0].second = true;
            }
            else if(Start[i] == '1')
            {
                End.push_back('0');
            }
        }
        else if (points[2].second)
        {
            if (Start[i] == '0')
            {
                End.push_back('1');
                
            }
            else if(Start[i] == '1')
            {
                End.push_back('1');
                points[2].second = false;
                points[1].second = true;
            }
        }
    }
    cout << End << endl;
}

void AsincAutomat()
{
    string Start, End;
    cout << "Введите строку: \n";
    cin >> Start;
    vector <pair<char,bool>> points;
    points.push_back(pair<char,bool> ('A',true));
    points.push_back(pair<char,bool> ('B',false));
    points.push_back(pair<char,bool> ('C',false));
    for(int i(0); i < Start.size(); i++)
    {
        if (points[0].second)
        {
            if (Start[i] == '1')
            {
                End.push_back('0');
                End.push_back('0');
                End.push_back('0');
                points[0].second = false;
                points[1].second = true;
            }
            else if(Start[i] == '0')
            {
                End.push_back('1');
                End.push_back('1');
                points[0].second = false;
                points[2].second = true;
            }
        }
        else if(points[1].second)
        {
            if (Start[i] == '0')
            {
                End.push_back('1');
                End.push_back('1');
            }
            else if(Start[i] == '1')
            {
                points[1].second = false;
                points[2].second = true;
            }
        }
        else if (points[2].second)
        {
            if (Start[i] == '0')
            {
                points[2].second = false;
                points[1].second = true;
                
            }
            else if(Start[i] == '1')
            {
                End.push_back('1');
                End.push_back('0');
                End.push_back('1');
                points[2].second = false;
                points[0].second = true;
            }
        }
    }
    cout << End << endl;
}


int main()
{
    SincAutomat();
    AsincAutomat();
    return 0;
}
//0111001011000101101
//0010100110100011010

//11011010000011
//01101101111110
//
//11011010000011
//0001011110111111111101
//

