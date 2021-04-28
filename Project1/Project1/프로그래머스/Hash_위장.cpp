#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int>m;

    //옷 종류가 같으면 1증가
    for (auto i : clothes) {
        m[i[1]] += 1;
    }

   //옷 종류만큼 반복해서 (옷 개수 +1) 곱하기
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