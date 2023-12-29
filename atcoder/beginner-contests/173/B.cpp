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
	ll i, j, n, v1 = 0, v2 = 0, v3 = 0, v4 = 0;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		if (s == "AC") ++v1;
		if (s == "WA") ++ v2;
		if (s == "TLE") ++v3;
		if (s == "RE") ++v4;
	}
	cout << "AC x " << v1 << "\nWA x " << v2;
	cout << "\nTLE x " << v3 << "\nRE x " << v4 << '\n';

	return 0;
}

