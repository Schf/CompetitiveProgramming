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

ll pow (ll a, ll x)
{
	ll ans = 1;
	for (ll i = 0; i < x; ++i)
		ans *= a;
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n;
	vector <pair <ll, ll>> inp (n);
	trav (p, inp) cin >> p.f >> p.s;
	string s;
	cin >> m;
	getline (cin, s);
	vector <ll> vals (inp.size ());
	bool neg = false;
	ll mul, exp;
	for (int polc = 0; polc < m; ++polc)
	{
		getline (cin, s);
		for (i = j = 0; i < s.size (); ++i)
			if (s[i] != ' ') s[j++] = s[i];
		s.erase (j, i - j);
		for (i = 0; i < s.size (); ++i)
			if ('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
		//cout << s << '\n';
		trav (a, vals) a = 0;
		for (j = 0; j < s.size ();)
		{
			mul = 1, exp = 0, neg = false;
			if (s[j] == '-') neg = true, ++j;
			if (s[j] == '+') neg = false, ++j;
			if ('0' <= s[j] && s[j] <= '9')
			{
				mul = 0;
				for (; '0' <= s[j] && s[j] <= '9'; ++j)
					mul = mul*10 + s[j] - '0';
			}
			if (s[j] == 'x')
			{
				if (s[++j] == '^')
					for (++j; '0' <= s[j] && s[j] <= '9'; ++j)
						exp = exp*10 + s[j] - '0';
				else exp = 1;
			}
			for (i = 0; i < n; ++i)
				vals[i] += (neg?(-1):1)*mul*pow (inp[i].f, exp);
			//cout << (char)(neg?'-':'+') << mul;
			//if (exp == 1) cout << 'X';
			//if (exp > 1) cout << "X^" << exp;
			if (s[j] == '=') break;
		}
		//cout << '\n';
		vector <ll> ans;
		for (i = 0; i < n; ++i)
			if (inp[i].s == vals[i]) ans.push_back (i);
		for (i = 0; i < ans.size (); ++i)
		{
			cout << ans[i];
			if (i < ans.size () - 1) cout << ',';
		}
		cout << '\n';
	}

	return 0;
}


