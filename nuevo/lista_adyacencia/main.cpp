#include <iostream>
#include<list>

using namespace std;

int main()
{
    list<char> ady_list[8];

    ady_list[0].push_back('b');
    ady_list[0].push_back('c');
    ady_list[0].push_back('d');

    //ady_list[].push_back('');

    list<char>::iterator a;
    list<char>::iterator b;
    list<char>::iterator c;
    list<char>::iterator d;
    list<char>::iterator f;
    list<char>::iterator g;

    a=ady_list[0].begin();

    cout<<*a;


    cout << "Hello World!" << endl;
    return 0;
}

