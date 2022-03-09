#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    // 10진법을 3진법으로
    // 1. 10진법 수를 몫이 0이 나올 때까지 3으로 나눔
    // 2. 그 사이에 나온 나머지를 벡터에 기록 
    vector<int> ternary;
    while(n > 0) {
        ternary.push_back(n % 3);
        n /= 3;
    }
    
    // 3진법 앞뒤반전
    // - pushback을 통해 넣었기 때문에 자동으로 반전됨

    // 3진법을 10진법으로
    // 1. 맨 마지막 수 부터 1, 3, 3^2, 3^3.. 으로 곱해서 더해줌 
    int index = 0;
    for(vector<int>::reverse_iterator it = ternary.rbegin(); it != ternary.rend(); ++it) {
        answer += (*it * pow(3, index++));
    }
    
    return answer;
}