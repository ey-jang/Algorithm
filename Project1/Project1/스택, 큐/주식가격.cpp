#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


vector<int> solution(vector<int>prices) {
	vector<int>answer;
	int sum = 0;
	for (int i = 0; i < prices.size() - 1; i++) {
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[i] <= prices[j]) {
				sum++;
			}
			else { // prices[i] ���� prices[j] ������ sum++ �� ������
				sum++;
				break; 
			}

		}

		answer.push_back(sum);
		sum = 0;
	}
	answer.push_back(0); // ������ 0 �ֱ�
	return answer;
}