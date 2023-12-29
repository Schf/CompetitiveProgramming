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

	ifstream in ("easy.in");
	streambuf *cinbuf = cin.rdbuf ();
	cin.rdbuf (in.rdbuf ());

	ofstream out ("easy.out");
	streambuf *coutbuf = cout.rdbuf ();
	cout.rdbuf (out.rdbuf ());

	ll i, j, n, k, mp = 0;
	cin >> n >> k;
	vector <vector <ll>> inp (n);
	vector <ll> ord;
	for (i = 0; i < n; ++i)
	{
		ll p;
		cin >> p;
		mp = max (mp, p);
		inp[i].resize (p);
		trav (a, inp[i]) cin >> a;
	}
	ll sum = 0, qnt = 0;
	for (i = 0; i < n*mp && qnt < k; ++i)
		if (inp[i%n].size () > i/n)
		{
			if (inp[i%n][i/n] >= sum)
				sum += inp[i%n][i/n], ++qnt;
		}
		else sum += 50, ++qnt;
	for (; qnt < k; ++qnt) sum += 50;
	cout << sum << '\n';


	cin.rdbuf (cinbuf);
	cout.rdbuf (coutbuf);

	return 0;
}

