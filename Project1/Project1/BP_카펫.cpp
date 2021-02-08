#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = brown + yellow;
    for (int height = 3;; height++) { // 높이는 최소 3이므로
        if (!(sum % height)) { // 합/ 높이의 나머지가 0인 경우
            int weight = sum / height;// 가로는 합 / 높이  (가로*높이)=(총 카펫 개수)
            if ((height - 2) * (weight - 2) == yellow) { // 노란색은 갈색 테두리 안에 들어가므로
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }

    return answer;
}