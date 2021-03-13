#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int solution(vector<int> priorities, int location) {
	int answer = 0;
	priority_queue<int> pq; //우선순위 큐
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push(make_pair(i, priorities[i]));
	}//우선순위 큐 [2, 1, 3, 2] -> [3, 2, 2, 1] 내림차순 정렬

	while (!q.empty()) {
		int first = q.front().first;
		int second = q.front().second;

		q.pop();
		if (pq.top() == second) { // pq의 top과 priorities의 맨 앞의 값과 같다면
			pq.pop();
			answer++;
			if (location == first) break; // 이때, location과 first가 같다면
		}
		else {
			q.push({ first, second });
		}

	}

	return answer;
}