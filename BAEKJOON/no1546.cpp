#include <iostream>
using namespace std;

int main(void)
{
    int subNum = 0;
    cin>>subNum;

    float scoreArr[subNum];
    for(int i=0; i<subNum; i++)
    {
        cin>>scoreArr[i];
    }

    int maxScore = scoreArr[0];
    for(int i=0; i<subNum; i++)
    {
        if(maxScore < scoreArr[i])
        {
            maxScore = scoreArr[i];
        }
    }

    float total = 0;
    for(int i=0; i<subNum; i++)
    {
        scoreArr[i] = scoreArr[i]/maxScore*100;
        total += scoreArr[i];
    }

    cout.precision(10);
    cout<<(float)total/(float)subNum<<endl;
    
    return 0;
}
