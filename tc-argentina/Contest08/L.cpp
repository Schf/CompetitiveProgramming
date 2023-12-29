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
	ll i, j, n;
	cin >> n;
	vector <ll> freq (10, 0);
	for (; n > 0; n /= 10)
		++freq[n%10];
	n = freq[4] + freq[7];
	if (n == 4 || n == 7) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}

