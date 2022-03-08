// 가운데 글자 가져오기 https://programmers.co.kr/learn/courses/30/lessons/12903?language=cpp
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = s.length()/2;
    if(s.length() % 2 == 0) {        
        answer.push_back(s[index-1]);
        answer.push_back(s[index]);
    } else {
        answer = s[index];
    }
    return answer;
}
