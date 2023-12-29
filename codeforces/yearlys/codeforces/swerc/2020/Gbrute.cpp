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
	ll i, j, s, l, n;
    while (cin >> s >> l >> n)
    {
        map <string, ll> stn;
        vector <string> nts (s);
        for (i = 0; i < s; ++i)
        {
            string s;
            cin >> s;
            stn[s] = 1;
        }
        i = 0;
        trav (p, stn)
            p.s = i++,
            nts[p.s] = p.f;
        vector <vector <bool>> nb (s, vector <bool> (s, false));
        for (i = 0; i < l; ++i)
        {
            string s, t;
            cin >> s >> t;
            nb[stn[s]][stn[t]] = true;
            nb[stn[t]][stn[s]] = true;
        }
        vector <ll> order (n);
        trav (a, order)
        {
            string s;
            cin >> s;
            a = stn[s];
        }
        for (i = 0; i < nb.size (); ++i)
            nb[i][i] = true;
        for (ll tt = 0; tt < 2; ++tt)
            for (i = 0; i < n; ++i)
                for (j = 0; j + 1 < n; ++j)
                    if (nb[order[j]][order[j + 1]] && order[j] > order[j + 1])
                        swap (order[j], order[j + 1]);
        trav (a, order) cout << nts[a] << ' ';
        cout << '\n';
    }

	return 0;
}

