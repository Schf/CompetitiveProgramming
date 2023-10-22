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
	cout.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n, sum = 0;
		cin >> n;
		vector <ll> inp (n), freq (n + 1, 0);
		trav (a, inp) cin >> a, ++freq[a];
		trav (a, freq) sum += a*(a-1)/2;
		trav (a, inp)
			cout << sum - freq[a]*(freq[a]-1)/2 + (freq[a]-1)*(freq[a]-2)/2 << '\n';
	}

	return 0;
}


