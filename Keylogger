#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	list <char> passwords{};
	vector <char> answer{};
	list<char>::iterator it;
	string password;
	//길이가 L인문자열, N번 입력받음
	for (int i = 0; i < N; i++)
	{
		cin >> password;
		for (char c : password) //list{"abcad", "asdsd"...} //문자열 넣어주고
		{
			passwords.push_back(c);
		}
		
		for (int i = 0; i < passwords.size(); i++) //리스트 돌면서 임무수행
		{

			switch (passwords.front())
			{//		<< BP<A >> Cd -     -> BAPC
				//입력 '<' : 커서가 맨앞이 아니면 왼쪽으로 한칸
			case '<':
				passwords.pop_front();
				break;
				//입력 '>' : 커서가 맨뒤가 아니면 오른쪽으로 한칸
			case '>':
				
				break;
				//입력 '-' : 커서의 왼쪽 문자 삭제
			case '-':
				passwords.erase(it);
				break;
			default :
				passwords.push_back(*it);
			}
		}
		
	}
}
