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
	ll i, j, n, q, ord_read = 0, unread = 0;
	cin >> n >> q;
	vector <pair <ll, vector <ll>>> app (n);
	vector <pair <ll, ll>> ord;
	ll type, x;
	while (cin >> type >> x)
	{
		if (type == 1)
		{
			--x;
			app[x].s.push_back (ord.size ());
			ord.push_back ({x, 0});
			++unread;
		}
		else if (type == 2)
		{
			--x;
			for (; app[x].f < app[x].s.size (); ++app[x].f)
				if (!ord[app[x].s[app[x].f]].s)
					ord[app[x].s[app[x].f]].s = 1,
					--unread;
		}
		else
		{
			for (; ord_read < x; ++ord_read)
				if (!ord[ord_read].s)
					++app[ord[ord_read].f].f,
					ord[ord_read].s = 1,
					--unread;
		}
		/*trav (v, app)
		{
			trav (a, v.s) cout << a << ' ';
			cout << "| " << v.f << '\n';
		}
		cout << "------\n";
		trav (p, ord) cout << p.f << ' ' << p.s << " | ";
		cout << '\n';*/
		cout << unread << '\n';
		//cout << "==========\n";
	}

	return 0;
}

