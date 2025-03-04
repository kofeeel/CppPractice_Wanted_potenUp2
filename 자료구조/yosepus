#include <iostream>
#include <list>

using namespace std;
//요세푸스 순열, K번째 사람 N번 뽑기
//idx 1 2 [3] 4 5 6 7
//	  1 2 idx 4 5 [6] 7
//	  1 [2] 4 5 idx 7
//    1 idx 4 5 [7]
//    1 4 [5] idx
//   [1] 4 idx
//  idx [4]
//연결리스트로 1,2, 3, 4,5,6,7		erase(next(list.begin(), K))    
//			   1,2,idx,4,5,6,7      
//			   1,2,4,5,idx,7
//			   1,idx,4,5,7
//			   1,4,5,idx
//			   1,4,idx
//			   idx,4
//			   idx
// 마지막에 pop_front()
int main()
{
	int N,K;
	list<int> yosepus(N);
	list<int> answer(N);
	cin >> N >> K;

	for (auto i: yosepus)
	{
		yosepus.push_back(i);
		yosepus.push_front(0);
	}
	//리스트가 빌때까지
	while (N--)
	{
		//리스트 K번째 요소를 꺼내와서 answer 리스트에 넣는다
		auto it = yosepus.begin();
		
		if (  == yosepus.end())
		{
			
		}
		else
		{
			advance(it, K);
			answer.push_front(*it);
		}
		
		
		//K번째 요소를 지운다
		yosepus.erase()

	}
}
 
