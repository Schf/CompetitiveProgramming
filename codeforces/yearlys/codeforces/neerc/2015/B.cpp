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

	ifstream in ("i.txt");
	streambuf *cinbuf = cin.rdbuf ();
	cin.rdbuf (in.rdbuf ());

	//ofstream out ("binary.out");
	//streambuf *coutbuf = cout.rdbuf ();
	//cout.rdbuf (out.rdbuf ());

	ll i, j, n, num;
	cin >> n;
	for (i = j = 0; j <= n; ++i)
	{
		num = 0;
		for (ll k = i, cc = 1; k > 0; k >>= 1, cc *= 10)
			num += (k&1)*cc;
		bool ok = true;
		for (ll k = i, kn = num; k > 0 && ok; k >>= 1, kn >>= 1)
			if ((k&1)^(kn&1)) ok = false;
		if (ok) cout << num << '\n';
		j += ok;
	}
	cout << num << '\n';

	cin.rdbuf (cinbuf);
	//cout.rdbuf (coutbuf);
	return 0;
}

