#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j = 0, n;
	cin >> n;
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	vector <bool> is_here (MAXN);
	set <ll> been_here;
	trav (a, inp)
	{
		j += a;
		if (!is_here[abs (a)])
			if (a < 0)
			{
				cout << "-1\n";
				return 0;
			}
			else 
				if (been_here.find (abs (a)) != been_here.end ())
				{
					cout << "-1\n";
					return 0;
				}
				else is_here[abs (a)] = true;
		else
			if (a > 0)
			{
				cout << "-1\n";
				return 0;
			}
			else
				is_here[abs (a)] = false,
				been_here.insert (abs (a));
		if (j == 0) been_here.clear ();
	}
	if (j != 0)
	{
		cout << "-1\n";
		return 0;
	}
	vector <ll> ans;
	for (i = j = 0; i < n; ++i)
	{
		j += inp[i];
		if (j == 0) ans.push_back (i);
	}
	cout << ans.size () << '\n';
	cout << ans[0] + 1 << ' ';
	for (i = 1; i < ans.size (); ++i)
		cout << ans[i] - ans[i - 1] << ' ';
	cout << '\n';

	return 0;
}

