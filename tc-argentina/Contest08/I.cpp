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

vector <ll> DP (1 << 20, -1);

void print_game (vector <vector <ll>> & game)
{
	cout << "  " << game[0][0] << ' ' << game[0][1] << ' ' << game[0][2] << '\n';
	cout << ' ' << game[1][0] << ' ' << game[1][1] << ' ' << game[1][2] << ' ' << game[1][3] << '\n';
	cout << game[2][0] << ' ' << game[2][1] << ' ' << game[2][2] << ' ' << game[2][3] << ' ' << game[2][4] << '\n';
	cout << ' ' << game[3][0] << ' ' << game[3][1] << ' ' << game[3][2] << ' ' << game[3][3] << '\n';
	cout << "  " << game[4][0] << ' ' << game[4][1] << ' ' << game[4][2] << '\n';
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;

	vector <vector <ll>> game = {
		{0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0}
	};
	vector <pair <ll, ll>> stg = {
		{0, 0}, {0, 1}, {0, 2},
		{1, 0}, {1, 1}, {1, 2}, {1, 3},
		{2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4},
		{3, 0}, {3, 1}, {3, 2}, {3, 3},
		{4, 0}, {4, 1}, {4, 2},
	};

	DP[0] = 0;
	queue <ll> bfs;
	bfs.push (0);
	while (!bfs.empty ())
	{
		ll state = bfs.front ();
		bfs.pop ();

		// state to game
		for (i = 0; i < 20; ++i)
			game[stg[i].f][stg[i].s] = (state >> i) & 1;

		

		// game to state
		state = 0; trav (v, game) trav (a, v)
			state = ((state << 1) | a);
	}

	char c;
	for (n = 0; cin >> c;)
	{
		if (c == '.')
			n = (n << 1);
		else if (c == 'O')
			n = ((n << 1) | 1);
	}
	cout << (DP[n] ? "Lillebror\n" : "Karlsson\n");
	return 0;
}

