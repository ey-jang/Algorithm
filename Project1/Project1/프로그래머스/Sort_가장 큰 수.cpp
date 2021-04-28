#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v1;


    for (int i = 0; i < numbers.size(); i++) {
        v1.push_back(to_string(numbers[i]));
    }

    sort(v1.begin(), v1.end(), cmp);

    for (int i = 0; i < v1.size(); i++)
        answer += v1[i];

    if (answer[0] == '0')return"0";

    return answer;
}