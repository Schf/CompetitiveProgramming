#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;
typedef pair <int, int> pii;

typedef vector <int> vi;
typedef vector <vi> mi;
typedef vector <ll> vll;
typedef vector <vll> mll;
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 1e+3+7;

int a[MAXN][MAXN];

bool check(int mid, int n, int m){
    
    rep(j, 0, m){
        int cont = 0;
        rep(i, 0, n){
            if (a[i][j] >= mid) cont++;
            else cont = 0;
            if (cont == mid) return true;
        }   
    }
    return false;
}

int main ()
{
    FASTIO;
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) a[i][0] = 1;
    vector<string> s(n);
    rep(i, 0, n){
        cin >> s[i];
        rep(j, 1, m){
            if (s[i][j] == s[i][j-1]) a[i][j] = a[i][j-1]+1;
            else a[i][j] = 1;
        }
    }
    //rep(i, 0, n) {rep(j, 0, m) cout << a[i][j] << ' '; cout << '\n';}
    int ans = 1;
    int l = 1, r = 1e9;
    while(r - l > 1){
        int mid = l + (r-l)/2;
        if (check(mid, n, m)){
            l = mid;
            ans = max(ans, mid);
        }
        else r = mid;
    }
    rep(i, l, r+1) if (check(i, n, m)) ans = max(ans, i);
    cout << ans * ans << '\n';
    return 0;
}


