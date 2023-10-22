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
		ll i, j, n;
		cin >> n;
		if (n == 1) cout << "1\n";
		else if (n <= 3) cout << "NO SOLUTION\n";
		else if (n == 4) cout << "3 1 4 2\n";
		else if (n == 5) cout << "3 1 4 2 5\n";
		else
		{
			vector <ll> A (n);
			for (i = 0; i < n; i += 2)
				A[i] = i/2 + 1, A[i + 1] = i/2 + 1 + (n + 1)/2;
			if (n&1) A[n - 1] = n/2 + 1;
			trav (a, A) cout << a << ' ';
			cout << '\n';
		}
	}

	return 0;
}

