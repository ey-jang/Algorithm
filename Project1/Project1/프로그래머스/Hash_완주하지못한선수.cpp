#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end()); //오름차순 정렬
    sort(completion.begin(), completion.end()); //오름차순 정렬

    for (int i = 0; i < completion.size(); i++) { 
        // 완주한 선수와 참가자 선수 이름이 같지 않으면 참가자선수 이름 반환
        if (completion[i] != participant[i]) return participant[i];
    }
    //if문에 걸리지 않은 경우 참가자의 맨 마지막선수 이름 반환
    return participant[participant.size() - 1];
}
//answer에 담아서 answer를 리턴하게 되면 효율성이 떨어진다..