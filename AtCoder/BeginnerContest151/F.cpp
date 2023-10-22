#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#define DEBUG 1
#define dd if (DEBUG)

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define rall(a) (a).rbegin (), (a).rend ()
#define sz(a) (int) (a).size ()
#define szl(a) (int) (a).length ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;
typedef pair <int, int> pii;
#define f first
#define s second
#define mp(a, b) make_pair((a), (b))
typedef vector <int> vi;
typedef vector <vi> mi;
typedef vector <ll> vll;
typedef vector <vll> mll;
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

double dist (double a, double b)
{
    return a*a + b*b;
}

int main ()
{
    FASTIO;
    int i, j, n;
    pair <double, double> m;
    cin >> n;
    vector <pair <double, double> > A (n);
    trav (a, A)
    {
        cin >> a.f >> a.s;
        m.f += a.f;
        m.s += a.s;
    }
    m.f /= n; m.s /= n;
    double P = 0.1, d, e;
	for (int i = 0; i < 30000; i++) {
		int f = 0;
		d = dist(m.f - A[0].f, m.s - A[0].s);
		for (int j = 1; j < n; j++) {
			e = dist(m.f - A[j].f, m.s - A[j].s);
			if (d < e) { d = e; f = j; }
		}
		m.f += (A[f].f - m.f)*P;
		m.s += (A[f].s - m.s)*P;
		P *= 0.999;
	}
    printf ("%.7lf\n", sqrt (d));

    return 0;
}


