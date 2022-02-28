// 같은 숫자는 싫어 https://programmers.co.kr/learn/courses/30/lessons/12906
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    // 1. 배열을 순회
    // 2. 이전 숫자랑 비교해서 새로운 숫자가 나오면 answer에 넣음
    int prev = -1;
    for(auto it=arr.begin(); it != arr.end(); it++) {
        if(prev != *it) {
            answer.push_back(*it);
        }
        prev = *it;
    }

    return answer;
}
