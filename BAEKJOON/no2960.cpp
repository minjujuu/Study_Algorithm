#include <iostream>
#include <list>
using namespace std;

int main()
{
    int input_n, input_k;
    list<int> iList;

    // 입력받기
    cin>>input_n>>input_k;

    int size = input_n-1;
    int start_num = 2;
    
    // 값 집어넣기 
    for(int i=0; i<size; i++)
    {
        iList.push_back(start_num++);
    }

    int count = 0;
    int answer = 0;
    int tmp = 0;
    while(iList.size() > 0)
    {
        // 1. 가장 작은 수 찾기
        int min_num = iList.front();
        for (int i = 0; i < size; i++)
        {
            if (min_num > iList.front())
            {
                min_num = iList.front();
            }
        }
        // 2. 가장 작은 수 삭제
        tmp = iList.front();
        iList.pop_front();
        count++;
        if (count == input_k)
        {
            answer = tmp;
        }
        list<int>::iterator it = iList.begin();
        // 3. 가장 작은 수의 배수 삭제
        while (it != iList.end())
        {          
            if (*it % min_num == 0)
            {
                // cout << *it << "delete" << endl;
                tmp = *it;
                iList.erase(it++);
                count++;
                if(count == input_k)
                {
                    answer = tmp;
                }
            }
            else
            {
                // cout << *it << "no delete" << endl;
                it++;
            }
        } 
    }

    cout << answer << endl;

/* 출력 코드 */
//     iList.sort();
//     list<int>::iterator print_iter = iList.begin();
//    // 값이 잘 들어갔는지 출력
//     for(print_iter=iList.begin(); print_iter != iList.end(); print_iter++)
//     {
//         cout<<*print_iter<<" ";
//     }
//     cout<<endl<<"print completed"<<endl;
    
}
