#include <string>
#include <vector>

using namespace std;

int chk[200]; //방문여부


void dfs(int x, int n, vector<vector<int>> computers) {
    chk[x] = 1;
    for (int i = 0; i < n; i++) {
        if (chk[i] == 0 && computers[x][i] == 1) { //방문을 안하고, computers[x][i]가 1이면
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