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
		bool ah = false, bh = false;
		string s;
		cin >> s;
		for (i = 0; i < n; i += 2)
			if ((s[i] - '0')%2) ah = true;
		for (i = 0; i < n; i += 2)
			if ((s[i] - '0')%2 == 0) bh = true;
		if (ah && bh)
			cout << (n%2==1 ? 1 : 2) << '\n';
		else if (ah && !bh) cout << 1 << '\n';
		else if (!ah && bh) cout << 2 << '\n';
		else cout << (n%2==1 ? 2 : 1) << '\n';
	}

	return 0;
}

