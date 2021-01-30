#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int>m;

    //�� ������ ������ 1����
    for (auto i : clothes) {
        m[i[1]] += 1;
    }

   //�� ������ŭ �ݺ��ؼ� (�� ���� +1) ���ϱ�
    for (auto it = m.begin(); it != m.end(); it++) {
        answer *= it->second + 1;
    }
    
    
    return answer-1;
}
int main()
{
    vector<vector<string>> c = { {"yellow_hat", "headgear"},
    {"blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } };

    cout << solution(c) << "\n";
    return 0;
}