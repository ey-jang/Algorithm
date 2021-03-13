#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    vector<bool>visit(words.size(), false); // words 크기만큼 방문 벡터 만들기
    queue<pair<string, int>> q;
    q.push({ begin, 0 }); // begin, 0 넣기

    while (!q.empty()) {
        string start = q.front().first; 
        int count = q.front().second; 
        q.pop();
        for (int i = 0; i < words.size(); i++) {
            int cnt = 0;
            if (visit[i] == 1) continue;
            for (int j = 0; j < begin.size(); j++) {
                if (start[j] != words[i][j]) cnt++; // start 와 words 배열의 단어 비교, 같지 않은 문자가 있으면 cnt++
            }
            if (cnt == 1) { //같지 않은 문자가 1개인 경우
                if (words[i] == target) {  // 이때 target과 같으면
                    return count + 1; // count 증가 후 반환
                }
                visit[i] = 1;
                q.push({ words[i], count + 1 }); // count 증가 후 push
            }
        }
    }


    return answer;
}