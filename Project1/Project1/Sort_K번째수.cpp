#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> c;
    for (int i = 0; i < commands.size(); i++) {
        
        for (int j = commands[i][0]; j <=commands[i][1]; j++) {
            //commands�� ù��° �迭�� ù��° ���-1���� �ι�° ���-1���� ���鼭 c �迭�� �ִ´�.
            c.push_back(array[j - 1]); //array[1]~array[4]

        }
        sort(c.begin(), c.end()); // c�迭 ����
        answer.push_back(c.at(commands[i][2] - 1)); // c �迭 �߿� (commands�� ù��° �迭�� ����° ���-1 )��° ��Ҹ� answer �迭�� �ִ´�.
        c.clear(); // commands�� ���� �迭�� �Ѿ�� �� clear ���ش�.
    }


    return answer;
}