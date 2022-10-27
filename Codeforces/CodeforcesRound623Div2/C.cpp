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
		int i, j, n;
		cin >> n;
		vector <int> B (n), A (2*n, -1), cnt (2*n, -1);
		for (i = 0; i < B.size (); ++i)
			cin >> B[i], cnt[--B[i]] = 2*i, A[2*i] = B[i];
		for (i = 0; i < A.size (); ++i)
		{
			if (cnt[i] >= 0)
				continue;
			vector <int> cand;
			for (j = 1; j < A.size (); ++j)
				if (A[j] < 0 && A[j - 1] >= 0 && A[j - 1] < i)
					cand.push_back (j);
			//cout << i + 1 << ": ";
			//trav (a, cand) cout << a + 1 << ' ';
			//cout << '\n';
			if (!cand.size ())
				break;
			A[cand[0]] = i;
			cnt[i] = cand[0];
		}
		bool can = true;
		trav (a, A) if (a < 0) can = false;
		if (can) trav (a, A) cout << a + 1 << ' ';
		else cout << -1;
		cout << '\n';
		//trav (a, cnt) cout << a + 1 << ' ';
		//cout << "\n------------------\n";
	}

	return 0;
}


