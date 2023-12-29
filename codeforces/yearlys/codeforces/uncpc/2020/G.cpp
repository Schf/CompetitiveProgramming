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
	ll i, j, n, m;
	for (n = 1; n < 11; ++n)
	{
		cout << n << ": ";
		vector <ll> ord (n), resp (n/2 + 1);
		iota (ord.begin (), ord.end (), 0);
		do
		{
			for (m = 0; 2*m <= n; ++m)
			{
				bool ok = true;
				for (i = 0; i/2 < m; i += 2)
					if (find (ord.begin (), ord.end (), i) - ord.begin () > 
							find (ord.begin (), ord.end (), i + 1) - ord.begin ())
						ok = false;
				if (ok) ++resp[m];
			}
		}
		while (next_permutation (ord.begin (), ord.end ()));
		trav (a, resp) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}

