#include <iostream>
#include <cstdio>

using namespace std;

// a에다가 b를 연결하는 거고, w는 weight임
class TRI {
public:
    int a, b, w;
};

// Priority Queue
class PQ {
public:
    int n;
    TRI Arr[1000];
    PQ();
    TRI Delete();
    void Insert(TRI x);
    int isEmpty();
};

PQ::PQ()
{
    n = 0;
}

int PQ::isEmpty()
{
    return n == 0;
}

void PQ::Insert(TRI x)
{
    // n개가 들어있음 (1부터 n까지)
    // 넘치지 않도록 n에다가 넣어야 함
    int i;
    Arr[n + 1] = x; // 1부터이고 0은 안씀
    i = n + 1;
    n = n + 1;
    // w가 Parent보다 작으면 바꿔야 함 
    while(i > 1 && Arr[i].w < Arr[i/2].w) {
        swap(Arr[i], Arr[i/2]);
        i = i/2; // 부모로 간 것 
    }
}

TRI PQ::Delete()
{
    TRI ret = Arr[1]; // save return value 
    int i, j;
    if(n == 1) { n = 0; return ret; } // special case 
    Arr[1] = Arr[n]; // 1부터 n까지 쓰고 있으니까 n번을 1로 보냄

    i = 1; n = n-1;
    while(1) {
        // 왼쪽 child가 n보다 크면 끝난 것
        if (i*2 > n) {
            break;
        }
        else if(i*2+1 > n) { // Left Child Only
            //왼쪽 차일드랑 비교해서 내가 더 크면 바꾸는 것
            if (Arr[i*2].w < Arr[i].w)
            {
                swap(Arr[i*2], Arr[i]);
                i = i*2;
            }
            else {
                break;
            }
        }
        else { // Left and Right Child exists
            // 둘 중 작은 거랑 교환해야 함. 케이스가 많음
            // 내가 둘 다 보다 큰 경우
            if(Arr[i].w > Arr[i*2].w && Arr[i].w > Arr[i*2+1].w) {
                if(Arr[i*2].w < Arr[i*2+1].w) {
                    j = i*2;
                }
                else {
                    j = i*2+1;
                }
                // 둘 중 작은 거랑 바꿈 
                swap(Arr[i], Arr[j]);
                i = j; // 그리고 그 아래쪽을 보러 감
            }
            // 오른쪽 꺼보다는 작거나 같음 
            else if(Arr[i].w > Arr[i*2].w && Arr[i].w <= Arr[i*2+1].w) {
                // 무조건 왼쪽 꺼랑 바꾸어야 함
                j = i *2;
                swap(Arr[i], Arr[j]);
                i = j; // 그리고 그 아래쪽을 보러 감
            }
            // 왼쪽 꺼보다는 작거나 같음 
            else if(Arr[i].w <= Arr[i*2].w && Arr[i].w > Arr[i*2+1].w) {
                j = i *2+1;
                swap(Arr[i], Arr[j]);
                i = j; // 그리고 그 아래쪽을 보러 감
            }
            // 내가 그냥 제일 작은 경우 
            else {
                break; // 할 일 없음 
            }
        }
    }
    return ret;
}

PQ Q;

int main()
{
    TRI s[100] = {
        {1, 2, 3},
        {4, 5, 6},
        {2, 2, 4},
        {4, 2, 1},
        {4, 2, 2},
        {4, 6, 8}
    };

    TRI t;
    Q.Insert(s[0]);
    Q.Insert(s[1]);
    Q.Insert(s[2]);
    Q.Insert(s[3]);
    Q.Insert(s[4]);
    Q.Insert(s[5]);
    t = Q.Delete(); // weight가 가장 작은 (4, 2, 1)이 삭제되어야 함 
    printf("Deleted (%d %d %d)\n", t.a, t.b, t.w);
    return 0;
}