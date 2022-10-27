#pragma GCC optimize ("O2") // "Ofast" for REAL FAST
// #pragma GCC optimization ("unroll-loops")

#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#include <bits/stdc++.h>
#define DEBUG 1

using namespace std;

#define rep(i, a, b) for (i = (a); i < (b); i++)
#define trav(a, x) for (auto & a : x)
#define all(x) (x).begin (), (x).end ()
#define rall(x) (x).rbegin (), (x).rend ()
#define sz(x) (int) (x).size ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;

typedef pair <int, int> pii;
#define f first
#define s second
#define mp(x, y) make_pair (x, y)

typedef vector <int> vi;
#define pb(x) push_back (x)

#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+5+7; // UPDATE

inline void ftg (int & r)
{
    char c;
    c = getchar_unlocked ();
    while (c < '0' || '9' < c)
        c = getchar_unlocked ();
    r = c - '0';
    c = getchar_unlocked ();
    while ('0' <= c && c <= '9')
    {
        r *= 10;
        r += c - '0';
        c = getchar_unlocked ();
    }
}

// int main ()
// {
//     int i, j, k, l, N, M, ub, lb, mb, am;
//     ll sum = 0, cur, x;
//     ftg (N);
//     ftg (M);
//     vi A (N), fq (MAXN + 2);
//     trav (a, A)
//     {
//         ftg (a);
//         fq[a]++;
//     }
//     sort (rall (A));
//     for (i = MAXN; i >= 0; i--)
//         fq[i] += fq[i + 1];
//     for (ub = MAXN, lb = 0; ub - lb > 0;)
//     {
//         mb = (ub + lb)/2; 
        
//         for (am = i = x = 0; A[i] > 0; i++)
//         {
//         }

//         if (am > M)
//             ub = mb;
//         else
//             lb = mb;
//     }
    
//     cout << sum << "\n";

//     return 0;
// }


//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
    
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<ll> pow(n);
    vector<ll> dat(1e5+2);
    FOR(i,0,n){
        cin>>pow[i];
        dat[pow[i]]++;
    }
    sortAlr(pow);
    vector<ll> v(n+1);
    FOR(i,0,n) v[i+1] += v[i] + pow[i];
    FORr(i,1,1e5)dat[i-1] += dat[i];
    
    trav (a, pow)
        ddcout << a << " ";
    ddcout << "\n";
    trav (a, v)
        ddcout << a << " ";
    ddcout << "\n";
    for (int i = 0; i < 40; i++)
        ddcout << dat[i] << " ";
    ddcout << "\n";

    ll lb = 0;
    ll ub = 2e5+2;
    while(ub-lb!=1){
        ll md = (ub+lb)/2;
        ll cnt = 0;
        ddcout << ub << " " << md << " " << lb << "\n";
        FOR(i,0,n){
            ll t = max((ll)0,min(md - pow[i],(ll)1e5+1));
            cnt += dat[t];
            ddcout << "\t" << t << " " << pow[i] << " " << cnt << "\n";
        }
        if(m>cnt) ub = md;
        else lb = md;
    }
    
    ll scr = 0;
    ll sum = 0;
    FOR(i,0,n){
        ll t = max((ll)0,min(ub - pow[i],(ll)1e5+1));
        ll cnt = dat[t];
        sum += cnt;
        scr += v[cnt] + pow[i]*cnt;
        ddcout << t << " " << cnt << " " << sum << " " << scr << " " << v[cnt] << " " << pow[i] << "\n";
    }
    scr += lb*(m-sum);
    cout<<scr<<endl;
}

