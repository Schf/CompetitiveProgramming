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
	ll i, j, n;
	string s, w = "WUB", out;
	cin >> s;
	for (i = 0; i < s.size (); ++i)
	{
		bool is = true;
		for (j = 0; j < w.size () && is; ++j)
			if (s[i + j] != w[j])
				is = false;
		if (is) i += w.size () - 1, out += ' ';
		else out += s[i];
	}
	for (i = 0; i < out.size (); ++i)
		if (out[i] != ' ')
			break;
	for (j = out.size () - 1; j >= 0; --j)
		if (out[j] != ' ')
			break;
	for (; i <= j; ++i)
		cout << out[i];
	cout << '\n';

	return 0;
}

