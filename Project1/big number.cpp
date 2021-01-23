#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int numSize = number.size() - k; 
	int start = 0;
	for (int i = 0; i < numSize; i++) {  //몇번 돌건지0,1,2,3
		char max = number[start]; // for루프 돌면서 다음 max 초기화는 최대값을 구한 다음자리
		int t = start;
		for (int j = start; j <= k + i; j++) {//맨 앞자리 비교//0~3
			if (max < number[j]) {
				max = number[j];
				t = j;
			}
		}
		start = t + 1; // 최대값을 구한 다음 자리
		answer += max;
	}
	return answer;
}