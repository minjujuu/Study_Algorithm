// https://www.acmicpc.net/problem/14501
/*
7
3 10
5 20
1 10
1 20
2 15
4 40
2 200
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int t[n+1]; // 상담에 걸리는 기간 
    int p[n+1]; // 상담했을 때 받는 돈
    int dp[n+1]; 

    int inputT, inputP;
    for(int i=1; i<=n; i++)
    {
        cin>>inputT>>inputP;
        t[i] = inputT;
        p[i] = inputP;
        dp[i] = 0;
    }

    int prev;
    for(int i=1; i<=n; i++)
    {
        // i에다가 일수를 더한 게 n보다 작아야 일할 수 있음
        if(i + t[i] <= n)
        {
            dp[i] = max(p[i], dp[i]);
            prev = i;
        }
        int j = i + t[i];
        for(int j=1; j<)
        {   
            // 더한 뒤에 일수가 n을 넘지 않아야 일할 수 있음
            if(j <= n)
            {
                dp[j] = max(dp[j], dp[prev] + p[j]);
                printf("[%d] j: %d, dp[j]: %d, prev: %d, dp[prev]: %d, p[j]: %d\n", i, j, dp[j], prev, dp[prev], p[j]);
                prev = j;
                j += t[j];
            }
            else
            {
                printf("-[%d] j: %d, dp[j]: %d, prev: %d, dp[prev]: %d, p[j]: %d\n", i, j, dp[j], prev, dp[prev], p[j]);
                break;
            }
        }
    }


    for(int i=1; i<=n; i++)
    {
        cout<<dp[i]<<endl;
    }
    cout<<*std::max_element(dp+1, dp+n+1)<<endl;;

    return 0;

}