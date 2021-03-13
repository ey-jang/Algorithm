#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int>q;

    int sum = 0;
    int Truck_Index = 0;

    while (1) {
        answer++;
        if (q.size() == bridge_length)// 트럭이 더 못들어가는 상황
        {
            sum -= q.front();
            q.pop(); 
        }
        if (sum + truck_weights[Truck_Index] <= weight) {//다리에 트럭을 추가로 넣을 수 있을 때
            if (Truck_Index == truck_weights.size() - 1) {
                answer += bridge_length;
                break;
            }
            q.push(truck_weights[Truck_Index]); 
            sum += truck_weights[Truck_Index]; 
            Truck_Index++; 
        }
        else {//다리에 추가로 트럭을 올리지 못할 때
            q.push(0);
        }
    }
    return answer;


}