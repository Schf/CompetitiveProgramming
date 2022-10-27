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
	ll i, j, n, m, k;
	cin >> n >> m >> k;
	vector <ll> inp (n), A (n), M (n);
	trav (a, inp) cin >> a;
	ll nm; cin >> nm;
	for (i = 0; i < nm; ++i)
		cin >> j, --j, M[j] = 1;
	ll na; cin >> na;
	for (i = 0; i < na; ++i)
		cin >> j, --j, A[j] = 1;

	ll can_check = 0;
	for (i = 0; i < n; ++i)
		can_check += (A[i] || M[i]);
	if (can_check < m)
	{
		cout << "-1\n";
		return 0;
	}
	if (2*k )

	return 0;
}

