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
#pragma region 병합정렬
//MyNode* MyList::Split(MyNode* head)
//{
//	if (!frontNode || !frontNode->next) { return nullptr; }
//
//	MyNode* slow = head; //중간지점을 찾는 노드
//	MyNode* fast = head; //맨끝을     찾는 노드
//	//포인터 두개로 리스트 한개를 리스트 두개로 나눈것처럼 조작
//	//노드가 비어있지않거나 맨끝을 가리키지 않으면 반복
//	while (fast->next != nullptr && fast->next->next != nullptr) 
//	{
//		slow = slow->next;       //1칸씩 이동
//		fast = fast->next->next; // 2칸씩 이동
//	}
//
//	if (slow->next == nullptr) {  return nullptr;	} 
//
//	MyNode* secondHead = slow->next; //두번째 리스트의 시작 노드 = 첫번째리스트의 마지막 노드
//	slow->next = nullptr; //첫번째 리스트와 두번째 리스트 연결끊기
//
//	if (secondHead)
//	{
//		secondHead->prev = nullptr; 
//	}
//
//	return secondHead; //두번째 리스트의 시작주소 반환
//}
//
//MyNode* MyList::MergeSort(MyNode* head) 
//{
//	if (head != nullptr || head->next != nullptr)  //리스트가 비어있거나 노드가 하나면 정렬할 필요 없음
//		return head;
//
//	MyNode* secondHead = Split(head);  // 리스트를 반으로 나눔
//
//	head = MergeSort(head);  //첫 번째 반을 재귀적으로 정렬
//	secondHead = MergeSort(secondHead);  //두 번째 반을 재귀적으로 정렬
//
//	return Merge(head, secondHead);  //정렬된 두 개의 리스트 병합
//}
//
//MyNode* MyList::Merge(MyNode* head, MyNode* secondHead)
//{
//	if (!head) return secondHead;
//	if (!secondHead) return head;
//
//	MyNode* mergedHead;
//
//	if (head->val < secondHead->val)
//	{
//		mergedHead = head;
//		head = head->next;
//	}
//	else
//	{
//		mergedHead = secondHead;
//		secondHead = secondHead->next;
//	}
//
//	MyNode* mergedTail = mergedHead; //mergedTail부터 시작해서 두 리스트의 값을 비교하며 병합
//
//	while (head != nullptr && secondHead != nullptr)
//	{
//		if (head->val < secondHead->val)//두번째 값이 더 크면
//		{
//			mergedTail->next = head;
//			head->prev = mergedTail;
//			head = head->next;
//		}
//		else //첫번째 값이 더 크면
//		{
//			mergedTail->next = secondHead;
//			secondHead->prev = mergedTail;
//			secondHead = secondHead->next;
//		}
//
//		mergedTail = mergedTail->next;
//	}
//
//	// 남은 노드 연결
//	if (head != nullptr)
//		mergedTail->next = head;
//	else
//		mergedTail->next = secondHead;
//
//	return mergedHead;
//}
//
//MyNode* MyList::getFrontNode()
//{
//	return frontNode;
//}
#pragma end

void MyList::mergeSort()
{
	if (frontNode == nullptr || frontNode->next == nullptr) {
		return; 
	}

	frontNode = mergeSortRecursive(frontNode);

	MyNode* current = frontNode;
	while (current && current->next) {
		current = current->next;
	}
	backNode = current;
}

MyNode* MyList::mergeSortRecursive(MyNode* head)
{

	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	MyNode* middle = getMiddle(head);
	MyNode* secondHalf = middle->next;

	middle->next = nullptr;
	if (secondHalf) {
		secondHalf->prev = nullptr;
	}

	MyNode* left = mergeSortRecursive(head);
	MyNode* right = mergeSortRecursive(secondHalf);

	return merge(left, right);
}

MyNode* MyList::getMiddle(MyNode* head)
{
	if (head == nullptr) {
		return nullptr;
	}

	MyNode* slow = head;
	MyNode* fast = head->next;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}


MyNode* MyList::merge(MyNode* left, MyNode* right)
{
	
	if (left == nullptr) {
		return right;
	}
	if (right == nullptr) {
		return left;
	}

	MyNode* result = nullptr;

	if (left->val <= right->val) {
		result = left;
		result->next = merge(left->next, right);
		if (result->next) {
			result->next->prev = result;
		}
	}
	else {
		result = right;
		result->next = merge(left, right->next);
		if (result->next) {
			result->next->prev = result;
		}
	}

	return result;
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
