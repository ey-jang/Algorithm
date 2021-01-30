#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int>v1; 
    vector<int>v2; 
    vector<int>v3; 

    v2.push_back(2);

    for (int i = 1; i <= 5; i++) {
        v1.push_back(i);
        if (i == 2)continue;
        else {
            v2.push_back(i);
            v2.push_back(2);
        }

    }
    v3.push_back(3);
    v3.push_back(3);
    for (int i = 1; i <= 5; i++) {

        if (i == 3) continue;
        else {
            v3.push_back(i);
            v3.push_back(i);
        }
    }
    // 여기까지 v1, v2, v3 에 넣기


    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        int i1 = i % 5; // 5개 반복
        int i2 = i % 8; //8개 반복
        int i3 = i % 10; //10개 반복
        if (answers[i] == v1.at(i1)) a1++;
        if (answers[i] == v2.at(i2)) a2++;
        if (answers[i] == v3.at(i3)) a3++;
    }
    
    //큰 순서대로 answer 배열에 넣기
    int max2 = max(a1, max(a2, a3));

    if (a1 == max2)
        answer.push_back(1);
    if (a2 == max2)
        answer.push_back(2);
    if (a3 == max2)
        answer.push_back(3);

    return answer;
    


}