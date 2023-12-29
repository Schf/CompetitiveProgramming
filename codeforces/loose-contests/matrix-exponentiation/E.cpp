#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef unsigned int ll;

//ll MOD = 4294967296;
//const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

typedef vector <ll> vll;
typedef vector <vll> mll;

mll graph;

mll operator * (mll & op, mll & mt)
{
	auto aux = op;
	trav (v, aux) v.assign (v.size (), 0);
	for (ll i = 0; i < op.size (); ++i)
		for (ll j = 0; j < mt[0].size (); ++j)
			for (ll k = 0; k < op[0].size (); ++k)
				aux[i][j] += op[i][k] * mt[k][j];
	return aux;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int i, j, n = 8, m = 8, k;
	cin >> k;
	++k;
	graph.resize (n*m);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
		{
			if (i - 2 >= 0 && j - 1 >= 0) graph[i*m+j].push_back ((i-2)*m+j-1);
			if (i - 2 >= 0 && j + 1  < m) graph[i*m+j].push_back ((i-2)*m+j+1);
			if (i - 1 >= 0 && j - 2 >= 0) graph[i*m+j].push_back ((i-1)*m+j-2);
			if (i - 1 >= 0 && j + 2  < m) graph[i*m+j].push_back ((i-1)*m+j+2);
			if (i + 1  < n && j - 2 >= 0) graph[i*m+j].push_back ((i+1)*m+j-2);
			if (i + 1  < n && j + 2  < m) graph[i*m+j].push_back ((i+1)*m+j+2);
			if (i + 2  < n && j - 1 >= 0) graph[i*m+j].push_back ((i+2)*m+j-1);
			if (i + 2  < n && j + 1  < m) graph[i*m+j].push_back ((i+2)*m+j+1);
		}
	mll dp (1, vll (graph.size () + 1, 0)), 
			mult (graph.size () + 1, vll (graph.size () + 1, 0));
	dp[0][0] = 1;
	for (i = 0; i < graph.size (); ++i)
		for (j = 0; j < graph[i].size (); ++j)
			mult[i][graph[i][j]] = 1;
	for (i = 0; i <= graph.size (); ++i)
		mult[i][graph.size ()] = 1;
	while (k)
	{
		if (k & 1) dp = dp * mult;
		mult = mult * mult;
		k >>= 1;
	}
	cout << dp[0][graph.size ()] << '\n';

	return 0;
}

