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
	vector <double> fat (15, 1);
	for (i = 2; i < fat.size (); ++i)
		fat[i] = i*fat[i - 1];
	string orig, sent;
	cin >> orig >> sent;
	ll orig_p, orig_m, sent_p, sent_m, sent_i = 0;
	orig_p = orig_m = sent_p = sent_m = 0;
	trav (s, orig)
		if (s == '+') ++orig_p;
		else ++orig_m;
	trav (s, sent)
		if (s == '+') ++sent_p;
		else if (s == '-') ++sent_m;
		else ++sent_i;
	if (orig_p < sent_p || orig_m < sent_m)
	{
		cout << "0.000000000\n";
		return 0;
	}
	printf ("%.12lf\n", (fat[sent_i]/(fat[orig_p - sent_p]*fat[sent_i - orig_p + sent_p]))/pow (2, sent_i));

	return 0;
}

