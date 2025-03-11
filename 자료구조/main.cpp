#include "MyList.h"
#include <iostream>

using namespace std;

#include <list>

int main()
{
    MyList nums;
    for (int i = 0; i < 10; i++)
    {
        nums.push_back(i);
    }
    nums.print();
    nums.clear();

    for (int i = 0; i < 10; i++)
    {
        nums.push_front(i * 10);
    }
    nums.print();
    nums.clear();

    for (int i = 0; i < 10; i++)
    {
        nums.push_front(i * 100);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << nums.at(i) << ", ";
    }
    cout << endl;

    nums.insert(5, 2025);
    nums.insert(0, 1234);
    nums.insert(nums.size(), 99999);
    nums.insert(nums.size() - 1, 8888);
    nums.print();

    return 0;
}