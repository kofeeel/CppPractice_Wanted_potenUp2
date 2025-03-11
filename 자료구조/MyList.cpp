#include "Mylist.h"

MyNode::MyNode(int val)  //prev,next가 nullptr이고 데이터만 포함하는 노드 생성
{
	prev = nullptr;
	next = nullptr;
	this->val = val;
}

MyNode::MyNode(MyNode* prev, int val, MyNode* next) //prev,next ,데이터를 포함하는 노드 생성
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

	MyNode* current = frontNode; //현재노드를 head에서 시작

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
	while (current)  //포인터가 nullptr이 아니면
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
	if (frontNode == nullptr) //노드가 비어있으면
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
	count++;  //노드요소의 개수를 1만큼 늘린다.
}

void MyList::push_back(int val)
{
	MyNode* newNode = new MyNode(val);
	if (backNode == nullptr) //노드가 비어있으면
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
		MyNode* temp = backNode; //현재 마지막노드 저장
		backNode = backNode->prev;  //tail한칸뒤로 이동	
		backNode->next = nullptr; //tail이 nullptr를 가리키게함
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
		MyNode* temp = frontNode; //현재 첫노드 저장
		frontNode = frontNode->next;  //head한칸앞으로 이동	
		frontNode->prev = nullptr; //head가 nullptr를 가리키게함
		delete temp;
	}
	count--;
}

int& MyList::front()// 맨 앞의 값 반환.
{	// TODO: 여기에 return 문을 삽입합니다.
	if (frontNode != nullptr)
	{
		return frontNode->val;
	}
}

int& MyList::back()// 맨 뒤의 값 반환.
{
	// TODO: 여기에 return 문을 삽입합니다.
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

void MyList::clear() // 리스트 내부의 모든 노드 삭제
{
}

void MyList::print() // 리스트 값들을 cout으로 출력(연습용 함수)
{
}

size_t MyList::size() // 리스트에 들어있는 데이터의 수 반환.
{
	return size_t();
}
