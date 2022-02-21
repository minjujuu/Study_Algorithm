// 폰켓몬 https://programmers.co.kr/learn/courses/30/lessons/1845
#include <vector>
#include <algorithm>
// 로직
// 1. 정렬을 함
// 2. 하나씩 순회하면서 숫자가 달라지면 result +1, 
// - 배열 끝까지 갔는데 종류가 더 이상 없으면 그 result가 끝 
// - result가 n/2가 되면 멈춤 
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    sort(nums.begin(), nums.end());
    
    int prev = 0, limit = nums.size()/2;
    vector<int>::iterator iter;
    for(iter = nums.begin(); iter != nums.end(); iter++) {        
        if(prev != *iter) {
            answer++;
            if(answer == limit)
                break;
        }
        prev = *iter;
    }
    
    return answer;
}