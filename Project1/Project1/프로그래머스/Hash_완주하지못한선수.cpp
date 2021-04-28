#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end()); //�������� ����
    sort(completion.begin(), completion.end()); //�������� ����

    for (int i = 0; i < completion.size(); i++) { 
        // ������ ������ ������ ���� �̸��� ���� ������ �����ڼ��� �̸� ��ȯ
        if (completion[i] != participant[i]) return participant[i];
    }
    //if���� �ɸ��� ���� ��� �������� �� ���������� �̸� ��ȯ
    return participant[participant.size() - 1];
}
//answer�� ��Ƽ� answer�� �����ϰ� �Ǹ� ȿ������ ��������..