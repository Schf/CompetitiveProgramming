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
	ll i, j, n, m;
	string s;
	cin >> s >> n >> m;
	getline (cin, s);
	vector <vector <ll>> form (m, vector <ll> (n, -1));
	for (i = 0; i < m; ++i)
	{
		getline (cin, s);
		stringstream ss; ss << s;
		ll num;
		while (!ss.eof ())
		{
			ss >> s;
			if (stringstream (s) >> num)
				form[i][abs(num) - 1] = (1 + num/abs(num))/2;
		}
	}
	vector <vector <ll>> out;
	for (i = 0; i < (1 << n); ++i)
	{
		bool ok = true;
		for (ll f = 0; f < m; ++f)
		{
			bool curok = false;
			for (j = 0; j < n; ++j)
				if (form[f][j] == ((i>>j)&1))
					curok = true;
			if (!curok) ok = false;
		}
		if (ok)
			for (out.emplace_back (n), j = 0; j < n; ++j)
				out[out.size () - 1][j] = (((i>>j)&1)*2 - 1)*(j + 1);
	}
	sort (out.begin (), out.end ());
	for (i = 0; i < out.size (); ++i)
	{
		cout << out[i][0];
		for (j = 1; j < out[i].size (); ++j)
			cout << ' ' << out[i][j];
		cout << '\n';
	}

	return 0;
}


