// 완주하지 못한 선수 https://programmers.co.kr/learn/courses/30/lessons/42576
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 1. 정렬해서 비교하기 위해 sort()
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
        
    vector<string>::iterator iter_participant = participant.begin();
    vector<string>::iterator iter_completion = completion.begin();
    
    for(; iter_participant != participant.end(); iter_participant++, iter_completion++) {
        // 2. completion이 end()에 도달하면, participant의 마지막 원소가 완주하지 못한 선수
        // 혹은 sort 상태에서 비교했을 때 두 원소가 다르면 iter_participant가 가리키는 게 완주하지 못한 선수
        if(iter_completion == completion.end() || *iter_participant != *iter_completion) {
            answer = *iter_participant;
            break;
        }
    }

    return answer;
}