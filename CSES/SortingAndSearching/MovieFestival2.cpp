#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n, k, cur;
		cin >> n >> k;
		vector <pair <ll, ll>> inp (n);
		trav (p, inp) cin >> p.s >> p.f;
		sort (inp.begin (), inp.end ());
		set <pair <ll, ll>> st;
		ll ans = 1;
		st.insert (inp[0]);
		//trav (p, st) cout << p.f << ' ' << p.s << "| ";
		//cout << '\n';
		for (i = 1; i < n; ++i)
		{
			if (inp[i].s < st.begin ()->f && st.size () < k)
				++ans, st.insert (inp[i]);
			else if (inp[i].s >= st.begin ()->f)
			{
				auto itt = st.upper_bound ({inp[i].s, INF});
				--itt;
				st.erase (itt);
				st.insert (inp[i]);
				++ans;
			}
			//trav (p, st) cout << p.f << ' ' << p.s << "| ";
			//cout << '\n';
		}
		
		cout << ans << '\n';
	}

	return 0;
}


