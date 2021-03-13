#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_cnt = 0;
void dfs(string x, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer, vector<string>& temp, int cnt) {

    temp.push_back(x);

    if (max_cnt < cnt) { // max_cnt �� cnt���� ���� ��� max_cnt �� �ٲ��, answer�� temp ���Ϳ� ���� ���� �ִ´�.
        max_cnt = cnt;
        answer = temp;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (!visit[i] && x == tickets[i][0]) { // �湮���� �ʰ�, x�� tickets�� ���� ��ġ�� ���ٸ� 
            visit[i] = true;
            dfs(tickets[i][1], tickets, visit, answer, temp, cnt + 1); // x�� tickets ������ ��ġ ���� dfs, cnt+1
            visit[i] = false;
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> temp;
    vector<bool>visit(tickets.size(), false); // tickets ũ�⸸ŭ �湮 ���� Ȯ���� ����
    sort(tickets.begin(), tickets.end()); // ������������ ����
    int cnt = 0;
    dfs("ICN", tickets, visit, answer, temp, cnt); // ICN���� �湮 ����
    return answer;
}