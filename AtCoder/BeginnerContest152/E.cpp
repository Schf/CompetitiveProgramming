#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#define DEBUG 1
#define dd if (DEBUG)

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define rall(a) (a).rbegin (), (a).rend ()
#define sz(a) (int) (a).size ()
#define szl(a) (int) (a).length ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;
typedef pair <int, int> pii;
#define f first
#define s second
#define mp(a, b) make_pair((a), (b))
typedef vector <int> vi;
typedef vector <vi> mi;
typedef vector <ll> vll;
typedef vector <vll> mll;
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 1e+4+7;


template <typename T>
T extGcd (T a , T b , T& x , T& y ) {
    if ( b == 0 ) {
        x = 1 ; y = 0 ; return a ;
    }
    else {
    T g = extGcd ( b , a % b , y , x ) ;
    y -= a / b * x ; return g ;
    }
}

template <typename T>
T modInv (T a , T m) {
    T x, y;
    extGcd ( a , m, x , y ) ;
    return ( x % m + m) % m;
}

template <typename T>
T modDiv (T a , T b , T m) {
    return ( ( a % m) * modInv ( b , m) ) % m;
}

#define F first 
#define S second 
#define MAX 10000003 
using namespace std; 
  
typedef long long ll; 
const int mod = 1000000007; 
  
int prime[MAX]; 
unordered_map<int, int> max_map; 
  
// Function to return a^n 
int power(int a, int n) 
{ 
    if (n == 0) 
        return 1; 
    int p = power(a, n / 2) % mod; 
    p = (p * p) % mod; 
    if (n & 1) 
        p = (p * a) % mod; 
    return p; 
} 
  
// Function to find the smallest prime factors 
// of numbers upto MAX 
void sieve() 
{ 
    prime[0] = prime[1] = 1; 
    for (int i = 2; i < MAX; i++) { 
        if (prime[i] == 0) { 
            for (int j = i * 2; j < MAX; j += i) { 
                if (prime[j] == 0) { 
                    prime[j] = i; 
                } 
            } 
            prime[i] = i; 
        } 
    } 
} 

ll lcmModuloM(vll & ar, int n) 
{ 
  
    for (int i = 0; i < n; i++) { 
        int num = ar[i]; 
        unordered_map<int, int> temp; 
  
        // Temp stores mapping of prime factor to 
        // its power for the current element 
        while (num > 1) { 
  
            // Factor is the smallest prime factor of num 
            int factor = prime[num]; 
  
            // Increase count of factor in temp 
            temp[factor]++; 
  
            // Reduce num by its prime factor 
            num /= factor; 
        } 
  
        for (auto it : temp) { 
  
            // Store the highest power of every prime 
            // found till now in a new map max_map 
            max_map[it.first] = max(max_map[it.first], it.second); 
        } 
    } 
  
    ll ans = 1; 
  
    for (auto it : max_map) { 
  
        // LCM is product of primes to their highest powers modulo M 
        ans = (ans * power(it.F, it.S)) % mod; 
    } 
  
    return ans; 
} 

int main ()
{
    FASTIO;
    int i, j, n;
    cin >> n;
    vll A (n);
    ll num = 1, sum = 0;
    sieve ();
    trav (a, A)
    {
        cin >> a;
        // num = num * modDiv (a, __gcd (num, a), MOD) % MOD;
    }
    num = lcmModuloM (A, sz (A));
    trav (a, A)
        sum = (sum + modDiv (num,  a, MOD)) % MOD;
    cout << sum << '\n';


    return 0;
}


