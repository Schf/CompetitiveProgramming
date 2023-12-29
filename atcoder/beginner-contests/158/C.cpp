#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

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
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, n, a, b;
		cin >> a >> b;
		bool ans = false;
		for (i = 0; i < 1e8; ++i)
			if (i*8/100 == a && i*10/100 == b)
			{
				ans = true;
				cout << i << '\n';
				break;
			}
		if (!ans) cout << "-1\n";
		
	}

	return 0;
}


