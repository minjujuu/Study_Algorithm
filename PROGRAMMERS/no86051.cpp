// 없는 숫자 더하기 https://programmers.co.kr/learn/courses/30/lessons/86051
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    for(int i=0; i<10; i++) {
        // 만약 numbers에서 찾아서 없으면 answer에 더해줌
        auto it = find(numbers.begin(), numbers.end(), i);
        if (it == numbers.end()) {
            answer += i;
        }
    }
    return answer;
}