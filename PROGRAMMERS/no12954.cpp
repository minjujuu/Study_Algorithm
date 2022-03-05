// x만큼 간격이 있는 n개의 숫자 https://programmers.co.kr/learn/courses/30/lessons/12954
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    int addValue = x;
    
    for(int i=0; i<n; i++) {
        answer.push_back(x);
        x+=addValue;
    }
    return answer;
}