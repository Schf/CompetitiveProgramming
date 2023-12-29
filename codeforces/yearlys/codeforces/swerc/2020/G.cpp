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
		for (i = 0; i < nb.size (); ++i)
			nb[i][i] = true;
		list <ll> order;
		for (i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			order.push_back (stn[s]);
		}
		//trav (a, order) cout << nts[a] << ' ';
		//cout << '\n';
		order.reverse ();
		for (i = s - 1; i >= 0; --i)
		{
			ll cnt = 0;
			auto itt = order.begin ();
			for (; itt != order.end (); )
			{
				//for (auto ittt = order.rbegin (); ittt != order.rend (); ++ittt)
				//	cout << nts[*ittt] << ' ';
				//cout << "| " << cnt << ' ' << i << ' ' << *itt << ' ' << (int)nb[i][*itt] << '\n';
				if (*itt == i) ++cnt, itt = order.erase (itt);
				else if (nb[i][*itt]) ++itt;
				else order.insert (itt, cnt, i), cnt = 0, ++itt;
			}
			order.insert (itt, cnt, i);
		}
		order.reverse ();
		for (i = s - 1; i >= 0; --i)
		{
			ll cnt = 0;
			auto itt = order.begin ();
			for (; itt != order.end (); )
			{
				//for (auto ittt = order.rbegin (); ittt != order.rend (); ++ittt)
				//	cout << nts[*ittt] << ' ';
				//cout << "| " << cnt << ' ' << i << ' ' << *itt << ' ' << (int)nb[i][*itt] << '\n';
				if (*itt == i) ++cnt, itt = order.erase (itt);
				else if (nb[i][*itt] && i > *itt) ++itt;
				else order.insert (itt, cnt, i), cnt = 0, ++itt;
			}
			order.insert (itt, cnt, i);
		}
		//cout << "------------------\n";
		trav (a, order) cout << nts[a] << ' ';
		cout << '\n';
	}

	return 0;
}

