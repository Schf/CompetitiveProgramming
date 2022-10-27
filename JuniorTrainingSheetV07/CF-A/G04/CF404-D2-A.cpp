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
	cin >> n;
	vector <string> inp (n);
	trav (s, inp) cin >> s;
	bool is = (inp[0][0] != inp[0][1]);
	for (i = 0; i < n && is; ++i)
		for (j = 0; j < n && is; ++j)
			if (((i == j || i == n - j - 1) && inp[i][j] != inp[0][0]) ||
					((i != j && i != n - j - 1) && inp[i][j] != inp[0][1]))
				is = false;
	if (is) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}

