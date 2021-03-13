#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int solution(vector<int> priorities, int location) {
	int answer = 0;
	priority_queue<int> pq; //�켱���� ť
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push(make_pair(i, priorities[i]));
	}//�켱���� ť [2, 1, 3, 2] -> [3, 2, 2, 1] �������� ����

	while (!q.empty()) {
		int first = q.front().first;
		int second = q.front().second;

		q.pop();
		if (pq.top() == second) { // pq�� top�� priorities�� �� ���� ���� ���ٸ�
			pq.pop();
			answer++;
			if (location == first) break; // �̶�, location�� first�� ���ٸ�
		}
		else {
			q.push({ first, second });
		}

	}

	return answer;
}