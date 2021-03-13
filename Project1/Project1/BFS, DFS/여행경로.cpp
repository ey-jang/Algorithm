#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_cnt = 0;
void dfs(string x, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer, vector<string>& temp, int cnt) {

    temp.push_back(x);

    if (max_cnt < cnt) { // max_cnt 가 cnt보다 작을 경우 max_cnt 값 바뀌고, answer에 temp 벡터에 넣은 값을 넣는다.
        max_cnt = cnt;
        answer = temp;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (!visit[i] && x == tickets[i][0]) { // 방문하지 않고, x와 tickets의 시작 위치가 같다면 
            visit[i] = true;
            dfs(tickets[i][1], tickets, visit, answer, temp, cnt + 1); // x의 tickets 마지막 위치 부터 dfs, cnt+1
            visit[i] = false;
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> temp;
    vector<bool>visit(tickets.size(), false); // tickets 크기만큼 방문 여부 확인할 벡터
    sort(tickets.begin(), tickets.end()); // 오름차순으로 정렬
    int cnt = 0;
    dfs("ICN", tickets, visit, answer, temp, cnt); // ICN부터 방문 시작
    return answer;
}