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
typedef pair <int, int> pii;
typedef vector <int> vi;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		int i, j, n;
		cin >> n;
		vector <int> A (n);
		int mxi = 0;
		trav (a, A)
			cin >> a;
		bool can = true;
		if (n == 2 && A[0] == 0 && A[1] == 0)
			can = false;
		for (i = 0; i < A.size () && can; ++i)
			if (A[i] < min (i, (int)A.size () - i - 1))
				can = false;
		if ((!(n&1)) && A[n/2 - 1] <= n/2-1 && A[n/2] <= n/2-1)
			can = false;
		if (can) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}


