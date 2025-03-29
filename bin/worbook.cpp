//#include <iostream>
//#include <map>
//
//using namespace std;
////단어장 규칙
////1.자주 나오는 단어는 앞에 배치 
//bool compare1(int a, int b)
//{
//	return  a > b;
//}
////2.단어의 길이가 길수록 앞에 배치
//bool compare2(string A, string B)
//{
//	bool compare = A.size() > B.size();
//	return compare;
//}
//int main()
//{
//	map<string, int> wordbook;
//	map<string, int>::iterator iter;
//
//	int N, M;
//	cin >> N >> M;
//	//3.알파벳 순서대로 배치
//	for (int i = 0; i < N; i++)
//	{
//		string input;
//		cin >> input;
//
//		int count{ 0 };
//
//		if (!wordbook.empty() && M <= input.size() <= 10)
//		{
//			if (wordbook.find(input) != wordbook.end()) //단어장에 같은 단어가 있으면 
//			{
//				count++;
//				wordbook.insert({ input, count });
//			}
//		}
//	}
//}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second != b.second) // 빈도수를 비교합니다.
		return a.second > b.second;

	if (a.first.length() != b.first.length()) // 단어의 길이를 비교합니다.
		return a.first.length() > b.first.length();

	return a.first < b.first; //사전순으로 앞에 있는 단어인지 확인합니다.
}

int main()
{
	unordered_map<string, int> wordMap;
	vector<pair<string, int>> rst;
	pair<unordered_map<string, int>::iterator, bool> p; // map에 단어를 삽입했을 때 반환값을 확인하기 위한 변수입니다.
	string tmp;                                         // 이미 있는 단어를 삽입했을 때, p.second는 false가 됩니다.
	int len, n;

	cin >> n >> len;
	while (n--)
	{
		cin >> tmp;
		if (tmp.length() >= len) // len 이상의 단어만 map에 삽입합니다.
		{
			p = wordMap.emplace(tmp, 1);
			if (!p.second) // map에 해당 단어가 이미 있을 때
				wordMap[tmp]++;
		}
	}

	copy(wordMap.begin(), wordMap.end(), back_inserter(rst)); // map을 vertor로 옮겨줍니다.
	sort(rst.begin(), rst.end(), comp);

	for (auto& a : rst)
		cout << a.first << "\n";
	return 0;
}