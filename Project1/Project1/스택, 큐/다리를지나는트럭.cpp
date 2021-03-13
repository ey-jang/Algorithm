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
        if (q.size() == bridge_length)// Ʈ���� �� ������ ��Ȳ
        {
            sum -= q.front();
            q.pop(); 
        }
        if (sum + truck_weights[Truck_Index] <= weight) {//�ٸ��� Ʈ���� �߰��� ���� �� ���� ��
            if (Truck_Index == truck_weights.size() - 1) {
                answer += bridge_length;
                break;
            }
            q.push(truck_weights[Truck_Index]); 
            sum += truck_weights[Truck_Index]; 
            Truck_Index++; 
        }
        else {//�ٸ��� �߰��� Ʈ���� �ø��� ���� ��
            q.push(0);
        }
    }
    return answer;


}