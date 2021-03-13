#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>q;

    for (int i = 0; i < progresses.size(); i++) {
        if (((100 - progresses[i]) % speeds[i]) != 0) {
            q.push((100 - progresses[i]) / speeds[i] + 1);
        }
        else q.push((100 - progresses[i]) / speeds[i]);
    }
    // 7, 3, 9
    //5, 10, 1, 1, 20, 1
    
    while (!q.empty()) {
        int sum = 1;
        int k = q.front();
        q.pop();

        while (k >= q.front() && !q.empty()) {
            q.pop();
            sum++;
        }

        answer.push_back(sum);
    }
    return answer;
}