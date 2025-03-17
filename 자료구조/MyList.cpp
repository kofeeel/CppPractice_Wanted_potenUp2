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
	if (at < 0 or at >= count)
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
	clear();
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
	if (backNode == nullptr) //리스트가 비어있으면
	{
		frontNode = backNode = newNode;
	}
	else
	{
		backNode->next = newNode;
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
	MyNode* node = atNode(index);  
	if (node == nullptr)
	{
		return -1; //잘못된 index면 -1 반환
	}
	return node->val; 
}

void MyList::insert(int index, int value)
{
	if (index < 0 || index > count) 
		return;

	if (index == 0) //맨앞
	{
		push_front(value);
		return;
	}

	if (index == count)  //맨뒤
	{
		push_back(value);
		return;
	}

	MyNode* prevNode = atNode(index - 1);  // 삽입위치 찾기
	MyNode* nextNode = prevNode->next;

	MyNode* newNode = new MyNode(prevNode, value, nextNode); 
	prevNode->next = newNode;
	nextNode->prev = newNode;

	count++; 
}

void MyList::erase(int index, int value)
{
	MyNode* deleteNode = atNode(index);  

	if (deleteNode == nullptr)  
		return;

	if (deleteNode == frontNode)  
	{
		pop_front();
		return;
	}

	if (deleteNode == backNode)  //마지막 노드 삭제
	{
		pop_back();
		return;
	}

	deleteNode->prev->next = deleteNode->next;  //이전 노드의 next 수정
	deleteNode->next->prev = deleteNode->prev;  //다음 노드의 prev 수정

	delete deleteNode;  
	count--;  
}

void MyList::clear() // 리스트 내부의 모든 노드 삭제
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

void MyList::print() // 리스트 값들을 cout으로 출력(연습용 함수)
{
	MyNode* current = frontNode;
	while (current != nullptr)  
	{
		std::cout << current->val << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

size_t MyList::size() // 리스트에 들어있는 데이터의 수 반환.
{
	return count;
}

void MyList::BubbleSort()
{
	for (int i = 0; i < size(); i++)            
	{
		for (int j = 0; j < size() - 1 - i; j++)  
		{								
			MyNode* node1 = atNode(j);
			MyNode* node2 = atNode(j + 1);
			if (at(j) > at(j + 1))
			{								  
				Swap(node1->val, node2->val);
			}
		}
	}
}

void MyList::MergeRight()
{
	MyNode* current = frontNode;

	for (int i = 0; i < (size() / 2) - 1; i++)
	{
		BubbleSort();
	}

}

void MyList::MergeLeft()
{
	MyNode* current = atNode(size() / 2);

	for (int i = size() / 2; i < size(); i++)
	{
		BubbleSort();
	}
}

void MyList::MergeSort()
{
	
	//
}

void MyList::Swap(int& a, int& b)
{
	int temp{ 0 };
	temp = a;
	a = b;
	b = temp;
}

int MyList::Max(int x, int y)
{
	int x1{ x }, y1{ y };
	
	if (x1 > y1) { return x1; }
	else { return y1; }
}
