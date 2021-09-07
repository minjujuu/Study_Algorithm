#include <iostream>
using namespace std;

int main(void)
{
    int count_people = 0;
    cin>>count_people;

    int *time_withdrawals = new int[count_people];

    for(int i=0; i<count_people;i++)
    {
        cin>>time_withdrawals[i];
    }

    // 합의 최솟값이니까 가장 걸리는 시간이 적은 사람부터 인출하면 됨
    // 삽입정렬
    for(int i=1; i<count_people; i++)
    {
        int tmp = time_withdrawals[i];
        int idx = 0;
        for(int j=i-1; j>=0; j--)
        {
            if(time_withdrawals[j] > tmp)
            {
                time_withdrawals[j+1] = time_withdrawals[j];
                idx=j;
            }
            else
            {
                idx=j+1;
                break;
            }
        }
        time_withdrawals[idx]=tmp;
    }

    int *answer = new int[count_people];
    for(int i=0; i<count_people; i++)
    {
        for(int j=0; j<=i; j++)
        {
            answer[i] += time_withdrawals[j];
        }
    }

    int ans = 0;

    for(int i=0; i<count_people; i++)
    {
        ans += answer[i];
    }

    cout<<ans<<endl;

    delete[] time_withdrawals;
    delete[] answer;
    
    return 0;
}