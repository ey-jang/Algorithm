#include <string>
#include <vector>

using namespace std;

int chk[200]; //�湮����


void dfs(int x, int n, vector<vector<int>> computers) {
    chk[x] = 1;
    for (int i = 0; i < n; i++) {
        if (chk[i] == 0 && computers[x][i] == 1) { //�湮�� ���ϰ�, computers[x][i]�� 1�̸�
            dfs(i, n, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {

    int answer = 0;
    for (int i = 0; i < n; i++) {

        if (chk[i] == 0) {
            dfs(i, n, computers);
            answer++;
        }
    }


    return answer;


}