//자릿수 더하기 https://programmers.co.kr/learn/courses/30/lessons/12931
#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    while(n) {
        answer += (n%10);
        n/=10;
    }

    return answer;
}