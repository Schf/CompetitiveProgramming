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

	ifstream in ("adjustment.in");
	streambuf *cinbuf = cin.rdbuf ();
	cin.rdbuf (in.rdbuf ());

	ofstream out ("adjustment.out");
	streambuf *coutbuf = cout.rdbuf ();
	cout.rdbuf (out.rdbuf ());

	ll i, j, n, q, rs, cs;
	cin >> n >> q;
	rs = cs = ((n+1)*n)/2;
	set <ll> rg, cg;
	while (q--)
	{
		char qc;
		ll pos;
		cin >> qc >> pos;
		if (qc == 'R')
		{
			if (rg.find (pos) != rg.end ())
				cout << "0\n";
			else cout << pos*(n-cg.size ()) + cs << '\n',
				rg.insert (pos), rs -= pos;
		}
		else
		{
			if (cg.find (pos) != cg.end ())
				cout << "0\n";
			else cout << pos*(n-rg.size ()) + rs << '\n',
				cg.insert (pos), cs -= pos;
		}
	}
	

	cin.rdbuf (cinbuf);
	cout.rdbuf (coutbuf);

	return 0;
}

