#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// �Ҽ� �Ǻ�
bool isPrime(int num)
{
    if (num < 2) // 0�� 1�� �Ҽ����� ����
        return false;
    for (int i = 2; i <= sqrt(num); i++) // 2���� �־��� ���� �����ٱ��� �����Ͽ� �̻�
        if (num % i == 0) // ������ �������� �Ҽ��� �ƴ�
            return false;
    return true;
}

// ���ڰ� �־��� ���ڵ�� ���� �������� �Ǻ�
bool isIncluded(int num, string str)
{
    string strNum = to_string(num); // ���ڸ� ���ڿ��� ��ȯ
    for (int i = 0; i < strNum.size(); i++) {
        int flag = false;
        for (int j = 0; j < str.size(); j++) {
            if (strNum.at(i) == str.at(j)) { // ��ġ�ϴ� ���ڰ� �ִٸ�
                flag = true;
                str.at(j) = ' '; // �ش� ���ڸ� �������� ��ü, �� ����� �� ����
                break;
            }
        }
        if (!flag) // �ѹ��̶� ��ġ�ϴ� ���ڰ� ���� ��� false ����
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<int>()); // ���� ū ������ ����
    int maxNum = stoi(numbers); // ���ڿ��� ���ڷ� ��ȯ

    for (int i = 0; i <= maxNum; i++) { // ���� ū�������� ���ڵ��� �˻�
        if (isPrime(i) && isIncluded(i, numbers)) { // �Ҽ��̰�, �����ִ� ���ڷ� ������ �� �ִ� �� �Ǻ�
            answer++;
        }
    }
    return answer;
}