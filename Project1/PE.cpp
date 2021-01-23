#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i : reserve) student[i] += 1; // ������ ������ +1
    for (int i : lost) student[i] -= 1;//�Ҿ������ -1
    for (int i = 1; i <= n; i++) {
        if (student[i] == -1) {
            if (student[i - 1] == 1) { //�Ҿ���� ��� �չ�ȣ�� ������������
                student[i - 1] = student[i] = 0;

            }
            else if (student[i + 1] == 1) { //�Ҿ���� ��� �޹�ȣ�� ������������
                student[i + 1] = student[i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (student[i] != -1) answer++;
    
    return answer;
}