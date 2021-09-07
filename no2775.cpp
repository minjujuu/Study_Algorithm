#include <iostream>
using namespace std;

// 부녀회장이 될테야
int main(void)
{
    int testcase = 0;
    cin>>testcase;

    int k_values[testcase];
    int n_values[testcase];
    for (int i = 0; i < testcase; i++)
    {
        cin>>k_values[i]>>n_values[i];
    }

    int sum = 0;
    
    for(int i=0; i<testcase; i++)
    {
        // 아파트에 숫자 채우기
        int apartment[k_values[i]][n_values[i]];
        for(int j=0; j<k_values[i]; j++)
        {
            for(int k=0; k<n_values[i]; k++)
            {
                if(j==0)
                {
                    apartment[j][k] = k+1;
                }
                else
                {
                    if(k==0)
                    {
                        apartment[j][k] = 1;
                    }
                    else
                    {
                        apartment[j][k] = apartment[j-1][k] + apartment[j][k-1];
                    }   
                }
            }
        }

        for(int z=0; z<n_values[i]; z++)
        {
            sum += apartment[k_values[i]-1][z];
        }

        cout<<sum<<endl;
        sum = 0;
    }
    return 0;
}