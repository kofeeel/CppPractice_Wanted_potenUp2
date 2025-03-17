#pragma once
#include <assert.h>
#include <iostream>
class MyNode
{
public:
    MyNode* prev;
    int val;
    MyNode* next;

    size_t count;
    MyNode(int val);
    MyNode(MyNode* prev, int val, MyNode* next);
};

/*
    만들어 놓은 연결리스트는. 추후 정렬 구현에도 사용 할 예정.

*/
class MyList 
{

private:
    MyNode* frontNode; //head
    MyNode* backNode;  //tail
    int count;      //리스트에 저장된 노드 개수

    MyNode* atNode(int at);

public:
    MyList();
    ~MyList();

    void push_front(int val);
    void push_back(int val);

    void pop_back();
    void pop_front();

    int& front();    // 맨 앞의 값 반환.
    int& back();        // 맨 뒤의 값 반환.
    int at(int index);

    void insert(int index, int value);
    void erase(int index, int value);
    void clear();    // 리스트 내부의 모든 노드 삭제

    void print();    // 리스트 값들을 cout으로 출력(연습용 함수)
    size_t size();    // 리스트에 들어있는 데이터의 수 반환.

    void BubbleSort(); 
    void MergeRight(); //MergeSort() head ~ middle - 1
    void MergeLeft();  //MergeSort() middle  ~ tail 
    void MergeSort();
    void Swap(int& a ,int& b);
    int Max(int x, int y);
};

