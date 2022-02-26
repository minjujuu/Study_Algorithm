// 소수 만들기 https://programmers.co.kr/learn/courses/30/lessons/12977
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsPrimeNumber(int num) {
    for(int i = 2; i <= num/2; i++) {
        if(num % i == 0) {  
            return false;
        }   
    }
    return true;
}

int solution(vector<int> nums) {
    // 서로 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수
    int answer = 0;
    int numsSize = nums.size();

    // 1. 조합을 위한 보조 순열 만들기  
    int subPermutation[numsSize];
    for(int i=0; i<numsSize-3; i++) {
        subPermutation[i] = 0;
    }
    for(int i=numsSize-3; i<numsSize; i++) {
        subPermutation[i] = 1;
    }
    
    // 2. 소수의 개수 판단
    do {
        int sum = 0;
        for(int i=0; i<numsSize; i++) {
            // elem이 1이면 sum에 더해보고 소수이면 answer++
            if(subPermutation[i] == 1) {
                sum += nums[i];
            }
        }
        if(IsPrimeNumber(sum)) {
            answer++;
        }
    } while(next_permutation(subPermutation, subPermutation + nums.size()));

    return answer;
}