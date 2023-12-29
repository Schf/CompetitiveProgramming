#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; cin >> tc;
	while (tc--)
	{
		int i, j, n, m;
		cin >> n >> m;
		vector <int> A (n), B, P (n, 0);
		trav (a, A) cin >> a;
		B = A;
		sort (B.begin (), B.end ());
		for (i = 0; i < m; ++i)
		{
			int aux; cin >> aux; --aux;
			P[aux] = 1;
		}
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)
					if (P[k] && A[k] > A[k + 1])
						swap (A[k], A[k + 1]);
		if (A != B) cout << "No\n";
		else cout << "Yes\n";
	}

	return 0;
}


