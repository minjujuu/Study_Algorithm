// 데이터 애널리틱스 과제(AHP)를 위한 행렬곱, ramdaMax, CR 계산기
#include <iostream>

using namespace std;

int main()
{
    // 예시 행렬
    // double A[3][3] = {{1.0, 0.5, 3.0},
    //                   {2.0, 1.0, 4.0},
    //                   {0.333, 0.25, 1.0}};
    // double x[3][1] = {{0.32}, {0.56}, {0.12}};
    // double Ax[3][1];

    // A 의견
    // double A[4][4] = {{1.0, 0.2, 9.0, 0.2},
    //                   {5.0, 1.0, 7.0, 3.0},
    //                   {0.111, 0.143, 1.0, 0.111},
    //                   {5.0, 0.333, 9.0, 1.0}};
    // double x[4][1] = {{0.151}, {0.504}, {0.040}, {0.307}};
    // double Ax[4][1];

    // B의견 
    double A[4][4] = {{1.0, 0.111, 0.2, 0.111},
                      {9.0, 1.0, 7.0, 1.0},
                      {5.0, 0.143, 1.0, 0.2},
                      {9.0, 1, 5.0, 1.0}};
    double x[4][1] = {{0.039}, {0.446}, {0.108}, {0.408}};
    double Ax[4][1];
    
    int A_col = sizeof(A[0]) / sizeof(double);
    int A_row = sizeof(A) / sizeof(A[0]);
    int x_col = sizeof(x[0]) / sizeof(double);
    int x_row = sizeof(x) / sizeof(x[0]);

    double sum = 0;
    for (int r = 0; r < A_row; r++)
    {
        for (int c = 0; c < x_col; c++)
        {
            sum = 0;
            for (int k = 0; k < A_col; k++)
            {
                sum += A[r][k] * x[k][c];
            }
            Ax[r][c] = sum;
        }
    }

    for (int r = 0; r < A_row; r++)
    {
        for (int c = 0; c < x_col; c++)
        {
            cout << Ax[r][c] << '\t';
        }
        cout << endl;
    }

    int n = 4; // criteria의 수
    cout<<"- n: "<<n<<endl;

    double ramdaMax = 0;
    for (int i = 0; i < x_row; i++)
    {
        ramdaMax += (Ax[i][0] / x[i][0]);
    }
    ramdaMax = ramdaMax / x_row;
    cout<<"- Ramda Max: "<<ramdaMax<<endl;

    double CI = 0, CR = 0;
    double RI = 0.9; // criteria의 수(4) 의 Random index 
    CI = (ramdaMax-n)/n-1;
    CR = CI/RI;
    cout<<"- Consistency index (CI): "<<CI<<endl;
    cout<<"- Consistency ratio (CR): "<<CR<<endl;
    if(CR < 0.1) {
        cout<<">> The comparison matrix is consistent <<"<<endl;
    } else {
        cout<<">> The comparison matrix is inconsistent <<"<<endl;
    }

}