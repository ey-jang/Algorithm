#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int numSize = number.size() - k; 
	int start = 0;
	for (int i = 0; i < numSize; i++) {  //��� ������0,1,2,3
		char max = number[start]; // for���� ���鼭 ���� max �ʱ�ȭ�� �ִ밪�� ���� �����ڸ�
		int t = start;
		for (int j = start; j <= k + i; j++) {//�� ���ڸ� ��//0~3
			if (max < number[j]) {
				max = number[j];
				t = j;
			}
		}
		start = t + 1; // �ִ밪�� ���� ���� �ڸ�
		answer += max;
	}
	return answer;
}