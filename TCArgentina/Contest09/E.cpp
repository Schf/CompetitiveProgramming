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


void LPS (vector <ll> & pat, vector <ll> & lps)
{ 
	int len = 0; 
	lps[0] = 0;

	for (int i = 1; i < pat.size (); )
		if (pat[i] == pat[len])
			++len, lps[i] = len, ++i;
		else
			if (len != 0) len = lps[len - 1];
			else lps[i] = 0, ++i;
} 

ll KMP (vector <ll> & seq, vector <ll> & pat)
{
	ll ans = 0;
	vector <ll> lps (pat.size ());
	LPS (pat, lps);

	for (ll i = 0, j = 0; i < seq.size (); )
	{
		if (pat[j] == seq[i])
			++i, ++j;

		if (j == pat.size ())
			++ans, j = lps[j - 1];

		else if (i < seq.size () && pat[j] != seq[i])
		{
			if (j != 0)
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, k;
	cin >> n >> k;
	if (k == 1)
	{
		cout << n << '\n';
		return 0;
	}
	if (n < k)
	{
		cout << "0\n";
		return 0;
	}
	vector <ll> seq (n), pat (k);
	trav (a, seq) cin >> a;
	trav (a, pat) cin >> a;
	for (i = n - 1; i > 0; --i)
		seq[i] -= seq[i - 1];
	for (i = k - 1; i > 0; --i)
		pat[i] -= pat[i - 1];
	seq.erase (seq.begin ());
	pat.erase (pat.begin ());
	cout << KMP (seq, pat) << '\n';

	return 0;
}
