// 핸드폰 번호 가리기 https://programmers.co.kr/learn/courses/30/lessons/12948
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    // phone_number의 길이-4 보다 작으면 *로 채움
    for(int i=0; i<phone_number.length()-4; i++) {
        phone_number[i] = '*';
    }
    answer = phone_number;
    return answer;
}