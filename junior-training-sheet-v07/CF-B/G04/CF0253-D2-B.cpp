#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef int ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	//ios_base::sync_with_stdio (0);
	//cin.tie (0);
	ll i, j, n = 0;
	FILE * in = fopen ("input.txt", "r");
	FILE * out = fopen ("output.txt", "w");
	fscanf (in, "%d", &n);
	vector <ll> inp (n);
	trav (a, inp)
		fscanf (in, "%d", &a);
	sort (inp.begin (), inp.end ());
	ll ans = 0;
	for (i = 0; i < n; ++i)
	{
		ll up = i;
		for (ll stp = n/2; stp > 0; stp /= 2)
			while (up + stp < n && inp[up + stp] <= 2*inp[i]) up += stp;
		ans = max (ans, up - i + 1);
		//for (j = 0; j < i; ++j) cout << "- ";
		//for (; j <= up; ++j) cout << inp[j] << ' ';
		//for (; j < n; ++j) cout << "- ";
		//cout << '\n';
	}
	fprintf (out, "%d\n", n - ans);
	fclose (in);
	fclose (out);

	return 0;
}

