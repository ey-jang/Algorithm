#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size(); // answer�� citations ũ�⺸�� Ŭ �� ���� ������
   
    int cnt = 0; //�ο�� �� ��
    while (answer != 0) {
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= answer) cnt++;  

        }
        if (cnt >= answer ) {
            if ((citations.size() - cnt) <= cnt) { // ������ ���� h�� ���� �ο�Ǹ� 
                
                break;
            }
        }
        cnt = 0;
        answer--;
    }
    
    return answer;
}