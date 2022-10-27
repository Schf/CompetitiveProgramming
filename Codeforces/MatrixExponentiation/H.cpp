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

typedef vector <ll> vll;
typedef vector <vll> mll;
typedef vector <mll> vmll;

mll operator * (mll & op, mll & mt)
{
	auto aux = op;
	trav (v, aux) v.assign (v.size (), 0);
	for (ll i = 0; i < op.size (); ++i)
		for (ll j = 0; j < mt[0].size (); ++j)
			for (ll k = 0; k < op[0].size (); ++k)
				aux[i][j] += op[i][k] * mt[k][j],
				aux[i][j] %= MOD;
	return aux;
}

mll char2mll (char c)
{
	mll out;
	switch (c)
	{
		case 'S':
		case 'D':
			out = {{0, 1}, {0, 1}};
			break;
		case 'H':
			out = {{1, 0}, {1, 0}};
			break;
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			out = {{0, 1}, {1, 0}};
			break;
		case '?':
			out = {{19, 7}, {6, 20}};
			break;
		default:
			out = {{1, 0}, {0, 1}};
			break;
	}
	return out;
}

void print (vmll & tree)
{
	mll dp = {{1, 0}};
	dp = dp * tree[1];
	cout << dp[0][0] << '\n';
}

void debug (vmll & tree)
{
	for (ll i = 1; i < tree.size (); ++i)
	{
		cout << i << ":\n";
		trav (v, tree[i])
		{
				trav (a, v) cout << a << ' ';
			cout << "\n";
		}
		cout << "--------\n";
	}
	cout << "====================\n";
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	ll pow = 0;
	for (i = n - 1; i > 0; ++pow, i /= 2);
	vmll tree (1<<(pow+1), {{1, 0}, {0, 1}});
	for (i = 0; i < n; ++i)
		tree[i + (1<<pow)] = char2mll (s[i]);
	for (i = (1<<pow)-1; i > 0; --i)
		tree[i] = tree[i<<1] * tree[i<<1|1];
	
	for (i = 0; i < q; ++i)
	{
		ll pos;
		char c;
		cin >> pos >> c;
		print (tree);
		pos = pos - 1 + (1<<pow);
		tree[pos] = char2mll (c);
		for (pos >>= 1; pos > 0; pos >>= 1)
			tree[pos] = tree[pos<<1]*tree[pos<<1|1];
	}
	print (tree);

	return 0;
}

