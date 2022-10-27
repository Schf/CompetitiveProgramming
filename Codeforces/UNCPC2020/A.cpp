#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;
typedef long double ldd;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

pair <ll, ll> A, B, C, D;

inline ldd dd (pair <ldd, ldd> p1, pair <ldd, ldd> p2)
{
	return hypot (p1.f - p2.f, p1.s - p2.s);
}


inline ldd max (double a, ldd b)
{
	return max ((ldd) a, b);
}

inline ldd min (double a, ldd b)
{
	return min ((ldd) a, b);
}

inline ldd ff (ldd t)
{
	return max (0.0, min (1.0, t));
}

inline ldd f (ldd t)
{
	ldd p = dd (C, D) / dd (A, B);
	return hypot ((A.f*ff (1 - t*p) + B.f*ff (t*p)) - 
					(C.f*ff (1 - t) + D.f*ff (t)),
		(A.s*ff (1 - t*p) + B.s*ff (t*p)) - 
				(C.s*ff (1 - t) + D.s*ff (t)));
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	ldd eps = 1e-9;
	cin >> A.f >> A.s >> B.f >> B.s;
	cin >> C.f >> C.s >> D.f >> D.s;
	if (dd (A, B) < dd (C, D)) swap (A, C), swap (B, D);

	ldd l = -1;
	ldd r = dd (A, B) / dd (C, D) + 1;

	//ldd p = dd (C, D) / dd (A, B);
	//for (double t = l; t <= r; t += 0.05)
	//	cout << t << ' ' << (A.s*max (0.0, 1 - t*p) + B.s*min (1.0, t*p)) << ' '
	//			<< (C.s*max(0.0, 1 - t) + D.s*min(1.0, t)) << '\n';

	vector <ldd> vals (11);
	ldd step = (r - l)/10;
	while (step > eps)
	{
		for (i = 0; i < 11; ++i)
			vals[i] = f (l*(1 - i/10.0) + r*i/10.0);
		j = min_element (vals.begin (), vals.end ()) - vals.begin ();
		ldd pivot = l*(1 - j/10.0) + r*j/10.0;
		step /= 10;
		l = pivot - 5*step;
		r = pivot + 5*step;
	}
	cout << fixed << setprecision (9) << vals[5] << '\n';

	/*
	while (r - l > eps)
	{
		ldd m1 = l + (r - l) / 3;
		ldd m2 = r - (r - l) / 3;
		ldd f1 = f(m1);
		ldd f2 = f(m2);
		if (f1 - f2 > 0)
			l = m1;
		else
			r = m2;
	}
	cout << fixed << setprecision (9) << f (l) << '\n';
	*/

	return 0;
}

