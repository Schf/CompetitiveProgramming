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
	ll i, j, n, m;
	cin >> n >> m;
	vector <string> inp (n);
	trav (s, inp) cin >> s;
	//trav (s, inp) cout << s << '\n';
	//cout << "-----------\n";
	while (!is_sorted (inp.begin (), inp.end ()))
	{
		for (j = 0; j < inp[0].size (); ++j)
		{
			string cur;
			for (i = 0; i < n; ++i)
				cur += inp[i][j];
			if (!is_sorted (cur.begin (), cur.end ()))
				break;
		}
		trav (s, inp)
			s.erase (s.begin () + j);
		//trav (s, inp) cout << s << '\n';
		//cout << "-----------\n";
	}

	cout << m - inp[0].size () << '\n';


	return 0;
}

