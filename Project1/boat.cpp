#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); // 오름차순 배열 

    int head = 0, tail = people.size() - 1; 
    //가장 무게가 적은 사람, 가장 무게가 많이 나가는 사람 비교
    while (head <= tail) {
        if (people[head] + people[tail] < limit) {
            head++;
            tail--;
        }
        else {
            tail--;
        }
        answer++;
    }
   

    
    return answer;
}
