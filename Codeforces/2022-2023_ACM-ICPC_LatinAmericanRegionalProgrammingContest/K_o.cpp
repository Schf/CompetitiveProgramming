#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto &a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mll;
typedef vector<mll> mmll;

ll MOD = 1e+9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5 + 7;

void printv(vll v, string opt = "")
{
	if ((int)opt.size())
		printf("% 5s : ", opt.c_str());
	trav(e, v)
		printf("% 3d ", e);
}

void printv(vll v, int opt)
{
	printv(v, to_string(opt));
}

void printm(mll m, string opt = "")
{
	trav(v, m)
	{
		printv(v, opt);
		printf("\n");
	}
}

void printm(mll m, int opt)
{
	printm(m, to_string(opt));
}

void printmm(mmll m, string opt = "")
{
	int i = 0;
	trav(sm, m)
	{
		printm(sm, opt + " (" + to_string(i) + ")");
		printf("\n");
		++i;
	}
}
void printmm(mmll m, int opt)
{
	printmm(m, to_string(opt));
}

// modulo of vector's elements
template<typename T>
vector<T> operator%(vector<T> a, ll MODULO)
{
	for (int i = 0; i < a.size(); ++i)
		a[i] = a[i] % MODULO;
	return a;
}

// matrix sum
template<typename T>
vector<vector<T>> operator+(vector<vector<T>> a, vector<vector<T>> b)
{
	vector<vector<T>> r(a.size(), vector<T>(a[0].size(), 0));
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < a[0].size(); ++j)
			r[i][j] = (a[i][j] + b[i][j]) % MOD;
	return r;
}

// matrix multiply
template<typename T>
vector<vector<T>> operator*(vector<vector<T>> a, vector<vector<T>> b)
{
	vector<vector<T>> r(a.size(), vector<T>(b[0].size(), 0));
	for (int i = 0; i < a.size(); ++i)
		for (int k = 0; k < a[0].size(); ++k)
			for (int j = 0; j < b[0].size(); ++j)
				r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % MOD;
	return r;
}

// a(x) * b(x) mod f(x)
template<typename T>
vector<T> mul(const vector<T> &a, const vector<T> &b, const vector<T> &c) {
    int n = (int) c.size();

    vector<T> ret(a.size() + b.size() - 1);
    // ret = a * b
    for (int i=0; i<(int)a.size(); i++)
        for (int j=0; j<(int)b.size(); j++)
            ret[i+j] = ret[i+j] + a[i] * b[j];
    // reducing ret mod f(x)
    for (int i=(int)ret.size()-1; i>=n; i--)
        for (int j=n-1; j>=0; j--)
            ret[i-j-1] = ret[i-j-1] + ret[i] * c[j];
    ret.resize(min((int) ret.size(), n));
    return ret;
}

// Fiduccia's K-th term of linear recurrent sequence
template<typename T>
T solve(const vector<T> &c, const vector<T> &s, long long k) {
    int n = (int) c.size();
    assert(c.size() <= s.size());

    vector<T> a = n == 1 ? vector<T>{c[0]} : vector<T>{0, 1}, x{1};
    for (; k>0; k/=2) {
        if (k % 2)
            x = mul(x, a, c);  // mul(a, b) computes a(x) * b(x) mod f(x)
        a = mul(a, a, c);
    }
    x.resize(n);

    T ret = 0;
    for (int i=0; i<n; i++)
        ret += x[i] * s[i];
    return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i, j, n;

	ll N_CONST, M_CONST, K_CONST, D_CONST = 10;
	cin >> N_CONST >> M_CONST >> K_CONST;
	K_CONST++;

	if (N_CONST == 1)
	{
		cout << "1\n";
		return 0;
	}

	// mll JUMPS(D_CONST, vll(K_CONST + 1));
	mmll M(D_CONST, mll(K_CONST, vll(K_CONST)));
	for (ll M_ITERATOR = 0; M_ITERATOR < M_CONST; ++M_ITERATOR)
	{
		ll d, p;
		cin >> d >> p;
		// JUMPS[d - 1][p]++;
		for (j = 0; j + p < K_CONST; ++j)
			M[d - 1][j][j + p]++;
	}

	mmll W(2 * D_CONST, mll(K_CONST, vll(K_CONST)));
	for (n = 0; n < D_CONST; ++n)
	{
		W[n] = M[n];
		for (i = 0; i < n; ++i)
			W[n] = W[n] + W[n - i - 1] * M[i];
	}
	// for (n = D_CONST; n < W.size(); ++n)
	// 	for (i = 0; i < D_CONST; ++i)
	// 		W[n] = W[n] + W[n - i - 1] * M[i];

	// mll A(D_CONST * K_CONST, vll(D_CONST * K_CONST)), R(A);
	// for (i = 0; i < D_CONST; ++i)
	// {
	// 	for (j = 0; j < K_CONST; ++j)
	// 	{
	// 		if (i)
	// 			A[i * K_CONST + j][(i - 1) * K_CONST + j] = 1;
	// 		for (ll k = 0; k < K_CONST; ++k)
	// 		{
	// 			A[i * K_CONST + j][(D_CONST - 1) * K_CONST + k] =
	// 				M[D_CONST - i - 1][j][k];

	// 			for (ll d = 0; d < D_CONST; ++d)
	// 				R[i * K_CONST + j][d * K_CONST + k] = W[i + d][j][k];
	// 		}
	// 	}
	// }

	// ll N_LOG_ITERATOR = N_CONST - 2;
	// for (; N_LOG_ITERATOR; N_LOG_ITERATOR /= 2)
	// {
	// 	if (N_LOG_ITERATOR % 2)
	// 		R = R * A;
	// 	A = A * A;
	// }

	// ll ans = 0;
	// for (i = 0; i < K_CONST; ++i)
	// 	ans = (ans + R[0][i])%MOD;

	// cout << ans << endl;

	return 0;
}
