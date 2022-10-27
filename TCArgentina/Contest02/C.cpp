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
	ll i, j, n, p;
	cin >> n >> p;
	vector <vector <ll>> alg (p, vector <ll> (2, 0));
	string inp;
	cin >> inp;
	if (p == n)
	{
		trav (c, inp)
			if (c == '.') cout << 1;
			else cout << c;
		cout << '\n';
		return 0;
	}
	for (i = 0; i < n; ++i)
		if (inp[i] == '.')
			if (i + p < n)
				if (inp[i + p] == '0' || inp[i + p] == '.') inp[i] = '1';
				else inp[i] = '0';
			else if (i - p >= 0)
				if (inp[i - p] == '0') inp[i] = '1';
				else inp[i] = '0';
			else inp[i] = '1';
	for (i = 0; i < inp.size (); ++i)
		++alg[i%p][inp[i] - '0'];
	bool can = false;
	trav (v, alg)
		if ((v[0]&&1)+(v[1]&&1) > 1) can = true;
	if (!can && n != p) cout << "No\n";
	else cout << inp << '\n';

	return 0;
}

