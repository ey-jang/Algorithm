#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i : reserve) student[i] += 1; // 여분이 있으면 +1
    for (int i : lost) student[i] -= 1;//잃어버리면 -1
    for (int i = 1; i <= n; i++) {
        if (student[i] == -1) {
            if (student[i - 1] == 1) { //잃어버린 사람 앞번호가 여분이있으면
                student[i - 1] = student[i] = 0;

            }
            else if (student[i + 1] == 1) { //잃어버린 사람 뒷번호가 여분이있으면
                student[i + 1] = student[i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (student[i] != -1) answer++;
    
    return answer;
}