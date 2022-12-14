// Cut Vertex
// 학번: 201914302
// 이름: 박민주

// 그래프에서 단절점 찾기
// 양방향 그래프 기준

#include <iostream>
#include <vector>
using namespace std;

int n, m, dfn;
// dfn: depth first number
vector<int> Edge[10000];
vector<int> Type[10000]; // 1 parent, 2 child, 3 back/forward
int Dfn[10000];
int L[10000];
int Cut[10000];

// x: dfs 시작점, p: 부모 노드
void dfs(int x, int p) // x 노드에 대해 
{
    int i, s;
    Dfn[x] = ++dfn;
    s = Edge[x].size();
    for(i=0; i<s; i++) {
        // Edge[x][i]가 노드 번호인 게 포인트
        if(Edge[x][i] == p) {
            Type[x][i] = 1;
        }
        else if(Dfn[Edge[x][i]] == 0) {
            Type[x][i] = 2;
            dfs(Edge[x][i], x);            
        }
        else {
            Type[x][i] = 3;
        }
    }
}

int dfs2(int x, int p)
{
    int i, s, rv, cc;
    // cc: child count, rv: return value
    L[x] = Dfn[x];
    s = Edge[x].size();

    // L값 계산
    for(i=0; i<s; i++) {
        if(Type[x][i] == 1) { // parent
            // 할 게 없음
        }
        else if(Type[x][i] == 2) { // child
            // 내려가서 L 계산하고 리턴해라
            rv = dfs2(Edge[x][i], x);
            L[x] = min(L[x], rv);
        }
        else { // back 하면서 내꺼에 반영
            L[x] = min(L[x], Dfn[Edge[x][i]]);
        }
    }
    
    if(p == 0) { // 루트인 경우
        cc = 0;
        for(i=0; i<s; i++) {
            if(Type[x][i] == 2) cc++;
        }
        if(cc>1) Cut[x] = 1;
    }
    else {
        for(i=0; i<s; i++) {
            if(Type[x][i] == 2) {
                // 부모x 없이는 Edge[x][i]인 x의 자식이 선조 L[Edge[x][i]]를 만날 수 없단 의미 
                // child의 L값이 내 dfn값보다 크거나 같으면 내가 단절점
                if(L[Edge[x][i]] >= Dfn[x])
                {
                    Cut[x] = 1;
                }
            }
        }
    }

    return L[x];
}

int main()
{
    int i, x, y;
    scanf("%d %d", &n, &m);
    for (i=0; i<m; i++)
    {
        scanf("%d %d", &x, &y);
        Edge[x].push_back(y);
        Type[x].push_back(0); // 공간을 만들기 위한 dummy 데이터
        Edge[y].push_back(x);
        Type[y].push_back(0); // 공간을 만들기 위한 dummy 데이터
    }

    dfn = 0;
    fprintf(stderr, "First Dfs starts\n");
    dfs(1, 0);
    fprintf(stderr, "First Dfs ends\n");
    
    for(i=1; i<=n; i++)
    {
        if(Dfn[i] == 0) break;
    }
    
    if(i<=n)
    {
        printf("Disconnected Graph!\n");
        exit(1);
    }
    fprintf(stderr, "Look for Cut Vertices\n");

    dfs2(1, 0);
    fprintf(stderr, "Cut Vertices");

    for(i=1; i<=n; i++)
    {
        // printf("i : %d, Cut : %d\n", i, Cut[i]);
        if(Cut[i] == 1)
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;

}


/*
Disconnected Grph
5 3
3 2
2 1
1 4

Connected Graph
5 4
3 2
2 1 
1 4
4 5

Connected Graph
16 20
1 2
1 3
2 4
3 4
4 5
5 6
4 6
5 7
7 8
4 12
12 13
4 11
11 13
11 10
10 9
9 11
13 14
14 15
15 16
14 16

Cut vertice: 4, 5, 7, 11, 13, 14

Alg 12 01 01 (32:21)에 그림 있음
*/