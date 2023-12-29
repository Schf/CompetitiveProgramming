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

bool cmp (string & a, string & b)
{
	if (a.size () == b.size ()) return a < b;
	return a.size () < b.size ();
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc;
	cin >> tc;
	for (ll tcc = 1; tcc <= tc; ++tcc)
	{
		cout << "Case #" << tcc << ": ";
		ll i, j, n;
		cin >> n;
		vector <string> bgn, mid, end;
		for (i = 0; i < n; ++i)
		{
			string s, a, b, c;
			cin >> s;
			for (j = 0; j < s.size () && s[j] != '*'; ++j)
				a += s[j];
			for (j = s.size () - 1; j >= 0 && s[j] != '*'; --j);
			for (++j; j < s.size (); ++j)
				c += s[j];
			if (a.size () + c.size () < s.size () - 1)
				b += s.substr (a.size (), s.size () - a.size () - b.size () - 1);
			for (j = b.size () - 1; j >= 0; --j)
				if (b[j] == '*') b.erase (b.begin () + j);
			if (a.size ()) bgn.push_back (a);
			if (b.size ()) mid.push_back (b);
			if (c.size ()) end.push_back (c);
		}
		sort (bgn.rbegin (), bgn.rend (), cmp);
		sort (mid.rbegin (), mid.rend (), cmp);
		sort (end.rbegin (), end.rend (), cmp);
		
		/*cout << "bgn:\n";
		trav (s, bgn) cout << s << '\n';
		cout << "mid:\n";
		trav (s, mid) cout << s << '\n';
		cout << "end:\n";
		trav (s, end) cout << s << '\n';
		cout << "over." << endl;*/
		bool can = true;
		for (i = 1; i < bgn.size () && can; ++i)
			for (j = 0; j < bgn[i].size () && can; ++j)
				if (bgn[0][j] != bgn[i][j])
					can = false;
		for (i = 1; i < end.size () && can; ++i)
			for (j = 0; j < end[i].size () && can; ++j)
				if (end[0][end[0].size () - j - 1] != end[i][end[i].size () - j - 1])
					can = false;
		string out;
		if (bgn.size ()) out += bgn[0];
		trav (s, mid) out += s;
		if (end.size ()) out += end[0];
		if (can) cout << out;
		else cout << "*";
		cout << '\n';
	}

	return 0;
}

