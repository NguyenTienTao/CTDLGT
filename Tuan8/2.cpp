#include <bits/stdc++.h>
using namespace std;

int procedure(int N, int W, double v[], int w[]) {
    double MaxV[N+1][W+1];
    for (int i = 0; i <= N; i++) {
        MaxV[i][0] = 0;
    }
    for (int i = 0; i <= W; i++) {
        MaxV[0][i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if ((j >= w[i]) && (MaxV[i-1][j-w[i]] + v[i] > MaxV[i-1][j]))
                MaxV[i][j] = MaxV[i-1][j-w[i]] + v[i];
            else
               MaxV[i][j] = MaxV[i-1][j];
        }
    }
    return MaxV[N][W];
}

int main()
{
    int N, W;
    cin >> N >> W;
    double v[N+1]; int w[N+1];
    for (int i = 1; i <= N; i++) {
        double value; int weight;
        cin >> value >> weight;
        v[i] = value;
        w[i] = weight;
    }
    cout << procedure(N, W, v, w);


    return 0;
}
