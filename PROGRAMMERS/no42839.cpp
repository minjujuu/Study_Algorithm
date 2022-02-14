// 소수 찾기 https://programmers.co.kr/learn/courses/30/lessons/42839
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


bool IsPrimeNumber(int num) {
    for(int i = 2; i*i <= num; i++) {        
        if(num % i == 0) {
            return false;
        }            
    }
    return true;
}

// IsNumbersMember()
// 숫자의 모든 자리수를 대상으로 numbers에 있는지 확인
// - 확인된 숫자는 numbers에서 제거 (숫자 카드는 하나만 존재)
bool IsNumbersMember(int num, string numbers) {
    string tempstr = numbers;
    string numstr = to_string(num);

    for(int i=0; i<numstr.length(); i++) {
        if(tempstr.find(numstr[i]) == string::npos) {
            return false;
        }
        else { 
            tempstr.erase(tempstr.find(numstr[i]),1);
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int n = 1;
    n = pow(10, numbers.length());

    for(int i=2; i<n; i++) {
        // 해당 숫자가 numbers에 있는지 확인
        if(IsNumbersMember(i, numbers)) {
            // 있다면 소수인지 확인
            if(IsPrimeNumber(i)) {
                answer++;
            }
        }      
    }

    return answer;
}