#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size(); // answer는 citations 크기보다 클 수 없기 때문에
   
    int cnt = 0; //인용된 논문 수
    while (answer != 0) {
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= answer) cnt++;  

        }
        if (cnt >= answer ) {
            if ((citations.size() - cnt) <= cnt) { // 나머지 논문도 h번 이하 인용되면 
                
                break;
            }
        }
        cnt = 0;
        answer--;
    }
    
    return answer;
}