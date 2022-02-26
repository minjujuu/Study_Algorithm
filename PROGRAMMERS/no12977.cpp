// 소수 만들기 https://programmers.co.kr/learn/courses/30/lessons/12977
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool IsPrimeNumber(int num) {
    // 소수는 자기 자신과만 나누어지는 수
    // 2부터 num/2까지 해서 나누어지는지 확인
    // 8이면 2,3,4,5,6,7,8 인데 5부터는 나누어질 수가 없음
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

    // 1. 조합을 위한 보조 순열 만들기 
    int numsSize = nums.size();
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
            // elem이 1이면 tmp에 더해보고 소수이면 answer++
            if(subPermutation[i] == 1) {
                sum += nums[i];
            }
        }
        if(IsPrimeNumber(sum)) {
            answer++;
        }
    } while(next_permutation(subPermutation, subPermutation+nums.size()));

    return answer;
}