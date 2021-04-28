#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> c;
    for (int i = 0; i < commands.size(); i++) {
        
        for (int j = commands[i][0]; j <=commands[i][1]; j++) {
            //commands의 첫번째 배열의 첫번째 요소-1부터 두번째 요소-1까지 돌면서 c 배열에 넣는다.
            c.push_back(array[j - 1]); //array[1]~array[4]

        }
        sort(c.begin(), c.end()); // c배열 정렬
        answer.push_back(c.at(commands[i][2] - 1)); // c 배열 중에 (commands의 첫번째 배열의 세번째 요소-1 )번째 요소를 answer 배열에 넣는다.
        c.clear(); // commands의 다음 배열에 넘어가기 전 clear 해준다.
    }


    return answer;
}