#include <bits/stdc++.h>
#define rep(i,a, b) for(int i =a; i < (b); ++i)
using namespace std;

int already[3][1003][1003];
double dp[3][1003][1003];

double solve(int p, int w, int b){
    if (w < 0 || b < 0) return 0;
    if (w == 0 and p) return 0;
    if (w ==0 and !p) return 1;
    if (b == 0 and p) return 1;
    if (b == 0) return 0;
    if (already[p][w][b]) return dp[p][w][b];
    if (p){
        dp[p][w][b] = (double)w/(w + b) + (double)b/(b+w)*solve(!p, w, b-1);
        already[p][w][b] = 1;
        return dp[p][w][b];
    }
    dp[p][w][b] = (double)b/(w+b)*((double)(b-1)/(w+b-1)*solve(!p, w, b-2) + (double)(w)/(w+b-1)*solve(!p, w-1, b-1));
    already[p][w][b] = 1;
    return dp[p][w][b];
}

int main(){
    int w, b;
    cin >> w >> b;
    printf("%.9lf\n",solve(1, w, b));// << '\n';
    /*rep(i, 0, 2){
        rep(j, 0, w + 1){
            rep(k, 0, b + 1){
                cout << already[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n' << '\n';
    }*/
    return 0;
}