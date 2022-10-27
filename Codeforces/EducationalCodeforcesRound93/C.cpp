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
	cin >> n;
	while (cin >> n)
	{
		string s;
		cin >> s;
		vector <ll> suf (n + 1);
		for (i = 0; i < n; ++i)
			suf[i] = s[i] - '0';
		for (i = n - 1; i >= 0; --i)
			suf[i] += suf[i + 1];
		vector <ll> sum (n + 1);
		for (i = 0; i < n; ++i)
			sum[0] += (suf[0] - suf[i + 1] == i + 1);
		cout << sum[0] << '\n';
	}

	return 0;
}

