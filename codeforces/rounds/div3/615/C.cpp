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
const ll MAXN = 1e+6+1;

// vi sieves_table (MAXN), primes;

// void sieve ()
// {
//     for (int i = 0; i < MAXN; ++i)
//         if (!sieves_table[i])
//         {
//             for (int j = i; j < MAXN; j += i)
//                 sieves_table[j] = i;
//             primes.pb (i);
//         }
// }

int main ()
{
    FASTIO;
    ll i, j, n, T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vll facs;
        for (i = 2; (i-1)*(i-1) < n; ++i)
            if (n%i == 0)
                facs.pb (i);
        vll nums;
        for (i = 0; i < facs.size (); ++i)
        {
            for (j = 0; j < facs.size (); ++j)
            {
                if (facs[i] == facs[j]) continue;
                ll num2 = n/(facs[i]*facs[j]);
                if (num2 > 1 && num2 != facs[i] && num2 != facs[j] &&
                        num2*facs[i]*facs[j] == n)
                {
                    nums = {facs[i], facs[j], num2};
                    i = facs.size ();
                    break;
                }
            }
        }
        if (nums.size ())
        {
            cout << "YES\n";
            trav (a, nums)
                cout << a << ' ';
            cout << "\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}


