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

	ifstream in ("generators.in");
	streambuf *cinbuf = cin.rdbuf ();
	cin.rdbuf (in.rdbuf ());

	ofstream out ("generators.out");
	streambuf *coutbuf = cout.rdbuf ();
	cout.rdbuf (out.rdbuf ());

	ll i, j, n, k, mxsize = 0;
	cin >> n >> k;
	vector <vector <pair <ll, ll>>> inp (n);
	for (i = 0; i < n; ++i)
	{
		ll x, a, b, c;
		cin >> x >> a >> b >> c;
		set <ll> conj;
		conj.insert (x);
		ll idx = 0;
		inp[i].push_back ({x, idx++});
		while (true)
		{
			ll cur = (x*a + b) % c;
			if (conj.count (cur)) break;
			conj.insert (cur);
			inp[i].push_back ({cur, idx++});
			x = cur;
		}
		sort (inp[i].begin (), inp[i].end ());
		mxsize = max (mxsize, (ll) inp[i].size ());
	}
	ll sum = 0;
	trav (v, inp) sum += v.back ().f;

	vector <vector <pair <ll, ll>>> seq (n);
	for (i = 0; i < n; ++i)
	{
		vector <ll> filt (min (inp[i].back ().f + 1, k), -1);
		for (j = inp[i].size () - 1; j >= 0; --j)
			if (filt[inp[i][j].f%k] < 0)
				filt[inp[i][j].f%k] = j;
		trav (a, filt)
			if (a >= 0)
				seq[i].push_back (inp[i][a]);
		sort (seq[i].begin (), seq[i].end ());
	}

	bool can = false;
	for (i = 0; i < seq.size (); ++i)
		if (seq[i].size () > 1) can = true;
	if (sum%k) can = true;
	if (!can)
	{
		cout << "-1\n";

		cin.rdbuf (cinbuf);
		cout.rdbuf (coutbuf);

		return 0;
	}

	set <pair <ll, vector <ll> *>> djk;
	vector <bool> viz (sum + 1);
	vector <ll> * here = new vector <ll> (n);
	for (i = 0; i < n; ++i)
		(*here)[i] = seq[i].size () - 1;
	viz[sum] = 1;
	djk.insert ({-sum, here});
	while (!djk.empty ())
	{
		ll cur_sum = -(djk.begin ()->f);
		vector <ll> * cur_vec = djk.begin ()->s;
		djk.erase (djk.begin ());
		if (cur_sum%k != 0)
		{
			cout << cur_sum << '\n';
			for (i = 0; i < n; ++i)
				cout << seq[i][(*cur_vec)[i]].s << ' ';
			cout << '\n';
			goto out;
		}
		for (i = 0; i < n; ++i)
		{
			if ((*cur_vec)[i] > 0 && !viz[cur_sum - (seq[i][(*cur_vec)[i]].f - 
					seq[i][(*cur_vec)[i] - 1].f)])
			{
				viz[cur_sum - (seq[i][(*cur_vec)[i]].f - 
						seq[i][(*cur_vec)[i] - 1].f)] = 1;
				vector <ll> * there = new vector <ll> (*cur_vec);
				(*there)[i] = (*cur_vec)[i] - 1;
				djk.insert ({-(cur_sum - (seq[i][(*cur_vec)[i]].f - 
						seq[i][(*cur_vec)[i] - 1].f)), there});
			}
		}
		delete cur_vec;
	}
	cout << "-1\n";
	out:;
	while (!djk.empty ())
	{
		delete djk.begin ()->s;
		djk.erase (djk.begin ());
	}

	cin.rdbuf (cinbuf);
	cout.rdbuf (coutbuf);

	return 0;
}

