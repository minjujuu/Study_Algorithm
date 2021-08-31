#include <iostream>
#include <list>
using namespace std;

int main()
{
    int input_n, input_k;
    
    // 입력받기
    cin>>input_n>>input_k;

    int size = input_n-1;

    int * arr = new int[size];
    int start_num = 2;

    // 값 집어넣기 
    for(int i=0; i<size; i++)
    {
        arr[i] = start_num++;
    }

    int delete_count = 0;
    int answer = 0;
    int tmp = 0;
    int delete_Idx = 0;
    int count = size;
    
    int min_num = arr[0];
    int start = 0;
    while(count > 0)
    {
        // 1. 가장 작은 수 찾기
        for (int i = start; i < size; i++)
        {
            if (arr[i] != -1)
            {
                min_num = arr[i];
                delete_Idx = i;
                break;
            }
        }

        // 2. 가장 작은 수 삭제
        tmp = arr[delete_Idx];
        arr[delete_Idx] = -1;
        delete_count++;
        count--;
        if (delete_count == input_k)
        {
            answer = tmp;
            break;
        }
        

        // 3. 가장 작은 수의 배수 삭제
        for (int j = 0; j < size; j++)
        {
            if (arr[j] % min_num == 0)
            {
                if (arr[j] != -1)
                {
                    tmp = arr[j];
                    delete_count++;
                    count--;
                    if (delete_count == input_k)
                    {
                        answer = tmp;
                        break;
                    }
                    arr[j] = -1;
                }
            }
        }

        if (delete_count == input_k)
        {
            break;
        }
        
        start++;
        delete_Idx = start;
    }

    
    cout<<answer<<endl;

    delete [] arr;
    return 0;
    
}