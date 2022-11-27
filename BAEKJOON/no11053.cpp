// 가장 긴 증가하는 부분 수열 https://www.acmicpc.net/problem/11053
// 먼저 O(n^2)의 Dp로 풀어보자

// 10, 20, 10, 30, 20, 50

// dp 배열을 만든다
// 입력배열을 앞에서부터 순회
// 1. 자기보다 앞 쪽에 자신보다 더 작은 숫자가 있는지 탐색
// 2. 그 작은 숫자 중 가장 큰 값을 찾음
// 3. 그 숫자의 dp에 1을 더해서 자신의 dp 숫자로 만듦

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);

    int n = 0;
    cin>>n;

    int input[n];
    int dp[n];
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }

    for(int i=0; i<n; i++)
    {
        int maxofmin = input[i];
        dp[i] = 1;
        for(int j=i-1; j>=0; j--)
        {
            // printf("j: %d, input[j] = %d, maxofmin = %d\n", j, input[j], maxofmin);
            // 지금 숫자보다 작은지
            if(input[j] < input[i])
            {
                // 초기값인 경우 
                if(maxofmin == input[i])
                {
                    maxofmin = input[j];
                    // 이 반복을 마지막으로 다음 반복이 없을 수도 있음
                    dp[i] = dp[j] + 1;
                }
                else {
                    // 작은 것 중에 가장 큰 것
                    if(input[j] > maxofmin)
                    {
                        maxofmin = input[j];
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        // printf("----\n");
    }

    // for(int i=0; i<n; i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    cout<<*max_element(dp, dp+n)<<endl;
    return 0;
}