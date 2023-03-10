#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto &a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mll;
typedef vector<mll> mmll;

vll VID, VZR;
// mll ID, ZR;

ll MOD = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5 + 7;

void printv(vll v, string opt = "")
{
	if ((int)opt.size())
		printf("% 5s : ", opt.c_str());
	trav(e, v)
		printf("% 3d ", e);
	printf("\n");
}

void printv(vll v, int opt)
{
	printv(v, to_string(opt));
}

void printm(mll m, string opt = "")
{
	trav(v, m)
		printv(v, opt);
	printf("\n");
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
		++i;
	}
	printf("\n");
}
void printmm(mmll m, int opt)
{
	printmm(m, to_string(opt));
}

// vector sum
vll operator+(vll &A, vll B)
{
	for (int i = 0; i < B.size(); ++i)
		B[i] = ((A[i] + B[i]) % MOD + MOD) % MOD;
	return B;
}

// vector diff
vll operator-(vll &A, vll B)
{
	for (int i = 0; i < B.size(); ++i)
		B[i] = ((A[i] - B[i]) % MOD + MOD) % MOD;
	return B;
}

// scalar vector multiplication
vll operator*(ll a, vll &B)
{
	vll R(B);
	trav(e, R) e = ((a * e) % MOD + MOD) % MOD;
	return R;
}

// vector convolution mod x^(A.size()+1)
vll operator*(vll &A, vll &B)
{
	ll K_CONST = (int)A.size();
	vll R(K_CONST, 0);
	for (ll i = 0; i < (int)A.size(); ++i)
		for (ll j = 0; j < (int)B.size() && i + j < K_CONST; ++j)
			R[i + j] = ((R[i + j] + A[i] * B[j]) % MOD + MOD) % MOD;
	return R;
}

mll operator*(mll &A, mmll &B)
{
	ll D_CONST = (int)A.size(), K_CONST = (int)A[0].size();
	mll R(D_CONST, vll(K_CONST, 0));
	for (ll i = 0; i < D_CONST; ++i)
		for (ll j = 0; j < D_CONST; ++j)
			R[i] = R[i] + A[j] * B[j][i];
	return R;
}

mmll operator*(mmll &A, mmll &B)
{
	ll D_CONST = A.size(), K_CONST = A[0][0].size();
	mmll R(D_CONST, mll(D_CONST, vll(K_CONST, 0)));
	for (ll i = 0; i < D_CONST; ++i)
		for (ll j = 0; j < D_CONST; ++j)
			for (ll k = 0; k < D_CONST; ++k)
				R[i][j] = R[i][j] + A[i][k] * B[k][j];
	return R;
}

// a(x) * b(x) mod f(x)
mll mul(mll &a, mll &b, mll &f)
{
	ll i, j;
	mll ret(a.size() + b.size() - 1, vll(a[0].size(), 0));

	// ret = a * b
	for (i = 0; i < a.size(); ++i)
		for (j = 0; j < b.size(); ++j)
			ret[i + j] = ret[i + j] + a[i] * b[j];

	// reducing ret mod f(x)
	for (i = ret.size() - 1; i >= f.size() - 1; --i)
		for (j = 0; j < f.size(); ++j)
			ret[i + j - f.size() + 1] = ret[i + j - f.size() + 1] - ret[i] * f[j];

	ret.resize(min(ret.size(), f.size() - 1));

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

	VZR.resize(K_CONST, 0);
	VID.resize(K_CONST, 0);

	VID[0] = 1;

	mll JUMPS(D_CONST, vll(K_CONST));
	for (ll M_ITERATOR = 0; M_ITERATOR < M_CONST; ++M_ITERATOR)
	{
		ll d, p;
		cin >> d >> p;
		if (p < K_CONST)
			JUMPS[d - 1][p]++;
	}

	mll WAYS(D_CONST, vll(K_CONST));
	for (n = 0; n < WAYS.size(); ++n)
	{
		WAYS[n] = JUMPS[n];
		for (int d = 1; n - d >= 0; ++d)
			for (i = K_CONST - 1; i >= 0; --i)
				for (j = 0; j <= i; ++j)
					WAYS[n][i] =
						(WAYS[n][i] + WAYS[n - d][j] * JUMPS[d - 1][i - j]) % MOD;
	}

	mll Xn{VZR, VID}, R{VID}, F(JUMPS.size() + 1);
	F[F.size() - 1] = VID;

	for (i = 0; i < JUMPS.size(); ++i)
		F[i] = -1 * JUMPS[JUMPS.size() - i - 1];

	for (ll N_IT = N_CONST - 2; N_IT; N_IT /= 2)
	{
		if (N_IT % 2)
			R = mul(R, Xn, F);
		Xn = mul(Xn, Xn, F);
	}

	vll ret(VZR);
	for (i = 0; i < min((ll)R.size(), D_CONST); ++i)
		ret = ret + WAYS[i] * R[i];

	ll ans = 0;
	for (i = 0; i < K_CONST; ++i)
		ans = ((ans + ret[i]) % MOD + MOD) % MOD;
	cout << ans << endl;

	return 0;
}
