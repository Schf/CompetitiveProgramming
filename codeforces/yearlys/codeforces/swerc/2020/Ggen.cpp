#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
    vector <ll> fact (10);
    fact[0] = fact[1] = 1;
    for (i = 2; i < 10; ++i)
        fact[i] = i*fact[i - 1];
    for (n = 1; n < 4; ++n)
    {
        vector <pair <ll, ll>> dups;
        for (i = 0; i < n; ++i)
            for (j = i + 1; j < n; ++j)
                dups.push_back ({i, j});
        for (ll bm = 0; bm < (1 << (dups.size ())); ++bm)
        {
            vector <ll> cur_dups;
            for (i = 0; (1<<i) <= (1 << (dups.size ())); ++i)
                if (bm&(1<<i)) cur_dups.push_back (i);
            cout << n << ' ' << cur_dups.size () << ' ' << n*n*2 << '\n';
            for (i = 0; i < n; ++i)
                cout << (char) ('A' + i) << '\n';
            trav (i, cur_dups)
                cout << (char) ('A' + dups[i].f) << ' ' << (char) ('A' + dups[i].s) << '\n';
            for (i = 0; i < n; ++i)
                for (j = 0; j < n; ++j)
                    cout << (char) ('A' + i) << ' ' << (char) ('A' + j) << ' ';
            cout << '\n';
        }
    }

	return 0;
}

