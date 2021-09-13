#include <iostream>
using namespace std;

// 교훈: 반례찾기
class Bridge
{
    public:
        int cur_weight;
        int max_weight;
        int length;
        int cur_truckNum;
    public:
        Bridge()
        {
            cur_weight = 0;
            max_weight = 0;
            length = 0;
            cur_truckNum = 0;
        }
};

class Truck
{
    public:
        int weight;
        int move_distance;
        bool isOnBridge;
    public:
        Truck()
        {
            weight = 0;
            move_distance = 0;
            isOnBridge = false;
        }
};

int main(void)
{
    int n = 0, w = 0, L = 0;
    cin>>n>>w>>L;

    Bridge bridge;
    bridge.length = w;
    bridge.max_weight = L;

    Truck trucks[n];

    for(int i=0; i<n; i++)
    {
        cin>>trucks[i].weight;
    }

    int startIdx = 0;
    int time = 0;

    while(trucks[n-1].move_distance <= bridge.length)
    {
        time++;
        for(int i = startIdx; i<n; i++)
        {
            if(!trucks[i].isOnBridge)
            {
                if(trucks[i].weight + bridge.cur_weight <= bridge.max_weight 
                    && bridge.cur_truckNum < bridge.length)
                {
                    trucks[i].isOnBridge = true;
                    trucks[i].move_distance += 1;
                    bridge.cur_weight += trucks[i].weight;
                    bridge.cur_truckNum += 1;
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                trucks[i].move_distance += 1;
                if(trucks[i].move_distance > bridge.length)
                {
                    startIdx++;
                    trucks[i].isOnBridge = false;
                    bridge.cur_weight -= trucks[i].weight;
                    bridge.cur_truckNum -= 1;
                }

            }
        }
    }

    cout<<time<<endl;
    return 0;

}