#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 소수 판별
bool isPrime(int num)
{
    if (num < 2) // 0과 1은 소수에서 제외
        return false;
    for (int i = 2; i <= sqrt(num); i++) // 2부터 주어진 수의 제곱근까지 포함하여 겁사
        if (num % i == 0) // 나누어 떨어지면 소수가 아님
            return false;
    return true;
}

// 숫자가 주어진 문자들로 구성 가능한지 판별
bool isIncluded(int num, string str)
{
    string strNum = to_string(num); // 숫자를 문자열로 변환
    for (int i = 0; i < strNum.size(); i++) {
        int flag = false;
        for (int j = 0; j < str.size(); j++) {
            if (strNum.at(i) == str.at(j)) { // 일치하는 문자가 있다면
                flag = true;
                str.at(j) = ' '; // 해당 문자를 공백으로 대체, 또 사용할 수 없게
                break;
            }
        }
        if (!flag) // 한번이라도 일치하는 문자가 없는 경우 false 리턴
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<int>()); // 문자 큰 순서로 정렬
    int maxNum = stoi(numbers); // 문자열을 숫자로 변환

    for (int i = 0; i <= maxNum; i++) { // 가장 큰수까지의 숫자들을 검사
        if (isPrime(i) && isIncluded(i, numbers)) { // 소수이고, 갖고있는 문자로 구성할 수 있는 수 판별
            answer++;
        }
    }
    return answer;
}