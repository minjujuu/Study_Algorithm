#include <iostream>
#include <list>

using namespace std;
void PrintListAll(list<int> listt);
void SearchLastTwo(int N, int K);

int main(void)
{
    int testcase = 0;
    cin>>testcase;

    int * input_N = new int[testcase];
    int * input_K = new int[testcase];

    for(int i=0; i<testcase; i++)
    {
        cin>>input_N[i]>>input_K[i];
        
    }
    for(int i=0; i<testcase; i++)
    {
        SearchLastTwo(input_N[i], input_K[i]);
    }

    delete[] input_N;
    delete[] input_K;

    return 0;
}

void SearchLastTwo(int N, int K)
{
    list<int> josephus;
    for(int i=0; i<N; i++)
    {
        josephus.push_back(i+1);
    }

    bool isEnd = false;
    bool isFirst = false;
    list<int>::iterator iter_main = josephus.begin();
    for(iter_main = josephus.begin(); josephus.size() > 2;)
    {
        // 예외 1 : 지우려는 노드가 마지막 노드이면 삭제 후 iter을 end으로 옮겨주어야 함
        if(iter_main == josephus.end())
        {
            isEnd = true;
        }

        // erase는 삭제 성공 시 삭제한 요소의 바로 다음 iterator를 return하기 때문에 그대로 대입
        iter_main = josephus.erase(iter_main); /* 노드 삭제 */
        if(isEnd)
        {
            iter_main = josephus.end();
            isEnd = false;
        }
            
        // 예외 2: 삭제 후 노드가 마지막 노드이면 begin으로 옮겨주어야 함
        if (iter_main == josephus.end())
        {
            iter_main = josephus.begin();
        }

        for(int i=0; i<K-1; i++) /* k-1만큼 이동 */
        {
            iter_main++;
            // 예외 2 : 이동하다가 마지막 노드를 만나면 다시 처음으로 옮겨주어야 함
            if(iter_main == josephus.end())
            {
                iter_main = josephus.begin();
            }
        }
    }

    PrintListAll(josephus);
    josephus.clear();
}

void PrintListAll(list<int> listt)
{
    list<int>::iterator iter;
    for(iter = listt.begin(); iter != listt.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
}
