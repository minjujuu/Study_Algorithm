// 연습문제 > 문자열을 정수로 바꾸기 https://programmers.co.kr/learn/courses/30/lessons/12925

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0; // answer = atoi(s); 만 해도 정답...
    
    bool isNegative = false;
    string tmpStr = s;
    
    if(!isdigit(s[0])) {
        if(s[0] == '-') isNegative = true;    
        tmpStr = s.substr(1); // 1번 인덱스부터 마지막 문자열까지 저장
    }
    answer = stoi(tmpStr);
    
    if(isNegative) answer *= -1;
    return answer;
}
