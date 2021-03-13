#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    vector<bool>visit(words.size(), false); // words ũ�⸸ŭ �湮 ���� �����
    queue<pair<string, int>> q;
    q.push({ begin, 0 }); // begin, 0 �ֱ�

    while (!q.empty()) {
        string start = q.front().first; 
        int count = q.front().second; 
        q.pop();
        for (int i = 0; i < words.size(); i++) {
            int cnt = 0;
            if (visit[i] == 1) continue;
            for (int j = 0; j < begin.size(); j++) {
                if (start[j] != words[i][j]) cnt++; // start �� words �迭�� �ܾ� ��, ���� ���� ���ڰ� ������ cnt++
            }
            if (cnt == 1) { //���� ���� ���ڰ� 1���� ���
                if (words[i] == target) {  // �̶� target�� ������
                    return count + 1; // count ���� �� ��ȯ
                }
                visit[i] = 1;
                q.push({ words[i], count + 1 }); // count ���� �� push
            }
        }
    }


    return answer;
}