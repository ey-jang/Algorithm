#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = brown + yellow;
    for (int height = 3;; height++) { // ���̴� �ּ� 3�̹Ƿ�
        if (!(sum % height)) { // ��/ ������ �������� 0�� ���
            int weight = sum / height;// ���δ� �� / ����  (����*����)=(�� ī�� ����)
            if ((height - 2) * (weight - 2) == yellow) { // ������� ���� �׵θ� �ȿ� ���Ƿ�
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }

    return answer;
}