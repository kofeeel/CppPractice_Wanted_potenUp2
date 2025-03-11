#pragma once

class MyNode
{
public:
    MyNode* prev;
    int val;
    MyNode* next;

    MyNode(int val);
    MyNode(MyNode* prev, int val, MyNode* next);
};

/*
    ����� ���� ���Ḯ��Ʈ��. ���� ���� �������� ��� �� ����.

*/
class MyList
{

private:
    MyNode* frontNode; //head
    MyNode* backNode;  //tail
    int count;      //����Ʈ�� ����� ��� ����

    MyNode* atNode(int at);

public:
    MyList();
    ~MyList();

    void push_front(int val);
    void push_back(int val);

    void pop_back();
    void pop_front();

    int& front();    // �� ���� �� ��ȯ.
    int& back();        // �� ���� �� ��ȯ.
    int at(int index);

    void insert(int index, int value);
    void erase(int index, int value);
    void clear();    // ����Ʈ ������ ��� ��� ����

    void print();    // ����Ʈ ������ cout���� ���(������ �Լ�)
    size_t size();    // ����Ʈ�� ����ִ� �������� �� ��ȯ.

};