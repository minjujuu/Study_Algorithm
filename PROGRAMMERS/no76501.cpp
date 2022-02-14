// 음양 더하기: https://programmers.co.kr/learn/courses/30/lessons/76501

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    // absoultes에 있는 값과 signs에 있는 값을 순서대로 조회
    // 만약 signs의 값이 false이면 -1을 곱해서 answer에 더함
    // 만약 signs의 값이 true이면 양수를 answer에 더함
    
    vector<int>::iterator iter_absolutes = absolutes.begin();
    vector<bool>::iterator iter_signs = signs.begin();
    for(; iter_absolutes != absolutes.end(), iter_signs != signs.end(); iter_absolutes++, iter_signs++) {
        if(!*iter_signs) {
            answer += (*iter_absolutes * -1);
        } else {
            answer += *iter_absolutes;
        }
    }
    
    return answer;
}