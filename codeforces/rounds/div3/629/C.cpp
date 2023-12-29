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
	int tc;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <ll> X (n), A (n), B (n);
		bool dec = false;
		trav (a, X)
		{
			char c = 0;
			while (c < '0' || '2' < c) cin >> c;
			a = c - '0';
		}
		if (X[0] == 0) A[0] = 2, B[0] = 1, dec = true;
		else if (X[0] == 1) A[0] = B[0] = 2;
		else A[0] = B[0] = 1;
		for (i = 1; i < n; ++i)
		{
			if (X[i] == 0) A[i] = B[i] = 0;
			else if (X[i] == 1)
				if (dec) A[i] = 0, B[i] = 1;
				else A[i] = 1, B[i] = 0, dec = true;
			else
				if (dec) A[i] = 0, B[i] = 2;
				else A[i] = B[i] = 1;
		}
		trav (a, A) cout << a;
		cout << '\n';
		trav (a, B) cout << a;
		cout << '\n';
	}

	return 0;
}


