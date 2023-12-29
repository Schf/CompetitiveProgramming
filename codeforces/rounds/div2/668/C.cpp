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

inline ll sign (ll num)
{
	return (num > 0) - (num < 0);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, k;
	string s;
	cin >> n;
	while (cin >> n >> k >> s)
	{
		ll sum = 0;
		bool ok = true;
		for (ll cc = 0; cc < 3e2 && ok; ++cc)
		{
			vector <ll> sums (n - k + 1);
			for (i = 0; i < k; ++i)
				if (s[i] == '1') ++sums[0];
				else if (s[i] == '0') --sums[0];
			for (i = 0; i < k; ++i)
				if (sign (sums[0]) && s[i] == '?')
					s[i] = (-sign (sums[0]) + 1)/2 + '0',
					sums[0] -= sign (sums[0]);
			for (i = k; i < n && ok; ++i)
			{
				if (s[i] == '1')
				{
					if (s[i - k] == '1')
						sums[i - k + 1] = sums[i - k];
					else if (s[i - k] == '0')
						ok = false,
						sums[i - k + 1] = sums[i - k] + 1;
					else s[i - k] = '1',
						sums[i - k + 1] = sums[i - k];
				}
				else if (s[i] == '0')
				{
					if (s[i - k] == '0')
						sums[i - k + 1] = sums[i - k];
					else if (s[i - k] == '1')
						ok = false,
						sums[i - k + 1] = sums[i - k] - 1;
					else s[i - k] = '0',
						sums[i - k + 1] = sums[i - k];
				}
				else
				{
					s[i] = s[i - k];
						sums[i - k + 1] = sums[i - k] - sign (sums[i - k]);
				}
			}
			trav (a, sums)
				ok = ok && (a == 0);
		}
		if (ok) cout << "YES";
		else cout << "NO";
		//cout << '\n';
		cout << " | " << s << '\n';
	}

	return 0;
}

