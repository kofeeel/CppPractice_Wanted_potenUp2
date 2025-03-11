#include "Mylist.h"

MyNode::MyNode(int val)  //prev,next�� nullptr�̰� �����͸� �����ϴ� ��� ����
{
	prev = nullptr;
	next = nullptr;
	this->val = val;
}

MyNode::MyNode(MyNode* prev, int val, MyNode* next) //prev,next ,�����͸� �����ϴ� ��� ����
{
	this->prev = prev;
	this->val = val;
	this->next = next;
}

MyNode* MyList::atNode(int at)
{
	if (at < 0 || at >= count)
	{
		return nullptr;
	}

	MyNode* current = frontNode; //�����带 head���� ����

	for (int i = 0; i < at; i++)
	{
		current = current->next;
	}
	return current; 
}

MyList::MyList()
{
	frontNode = nullptr;
	backNode = nullptr;
	count = 0;
}

MyList::~MyList()         
{
	MyNode* current = frontNode;
	while (current)  //�����Ͱ� nullptr�� �ƴϸ�
	{
		MyNode* nextNode = current->next; 
		delete current;
		current = nextNode;
	}
	frontNode = nullptr;
	backNode = nullptr;
	count = 0;
}

void MyList::push_front(int val)
{
	MyNode* newNode = new MyNode(val);
	if (frontNode == nullptr) //��尡 ���������
	{
		frontNode = backNode = newNode;
	}
	else
	{
		frontNode->prev = newNode;
		newNode->next = frontNode;
		frontNode = newNode;
	}
	frontNode->prev = nullptr;
	count++;  //������� ������ 1��ŭ �ø���.
}

void MyList::push_back(int val)
{
	MyNode* newNode = new MyNode(val);
	if (backNode == nullptr) //��尡 ���������
	{
		frontNode = backNode = newNode;
	}
	else
	{
		frontNode->next = newNode;
		newNode->prev = backNode;
		backNode = newNode;
	}
	backNode->next = nullptr;
	count++; 
}

void MyList::pop_back()
{
	if (backNode == nullptr)
	{
		return;
	}
	if (frontNode == backNode) 
	{
		delete backNode;
		frontNode = backNode = nullptr;
	}
	else
	{
		MyNode* temp = backNode; //���� ��������� ����
		backNode = backNode->prev;  //tail��ĭ�ڷ� �̵�	
		backNode->next = nullptr; //tail�� nullptr�� ����Ű����
		delete temp; 
	}
	count--;
}

void MyList::pop_front()
{
	if (frontNode == nullptr)
	{
		return;
	}
	if (frontNode == backNode)
	{
		delete frontNode;
		frontNode = backNode = nullptr;
	}
	else
	{
		MyNode* temp = frontNode; //���� ù��� ����
		frontNode = frontNode->next;  //head��ĭ������ �̵�	
		frontNode->prev = nullptr; //head�� nullptr�� ����Ű����
		delete temp;
	}
	count--;
}

int& MyList::front()// �� ���� �� ��ȯ.
{	// TODO: ���⿡ return ���� �����մϴ�.
	if (frontNode != nullptr)
	{
		return frontNode->val;
	}
}

int& MyList::back()// �� ���� �� ��ȯ.
{
	// TODO: ���⿡ return ���� �����մϴ�.
	if (backNode != nullptr)
	{
		return backNode->val;
	}
}

int MyList::at(int index)
{
	if (index > 0 || index < count) 
	{
		MyNode* current = frontNode;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->val; 
	}
}

void MyList::insert(int index, int value)
{
}

void MyList::erase(int index, int value)
{
}

void MyList::clear() // ����Ʈ ������ ��� ��� ����
{
}

void MyList::print() // ����Ʈ ������ cout���� ���(������ �Լ�)
{
}

size_t MyList::size() // ����Ʈ�� ����ִ� �������� �� ��ȯ.
{
	return size_t();
}
