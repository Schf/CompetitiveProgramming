#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define OP(x) (((x) >> (16 * TWICE)) & ((1 << 16) - 1))

int main() {
  ll TC, N, A, B, C, X, Y, V;
  vector<vector<ll>> S(2, vector<ll>(10e6 + 7));
  int bucket[1 << 16];
  cin >> TC;
  while (TC--) {
    cin >> N >> A >> B >> C >> X >> Y;
    S[0][0] = A;
    for (int i = 1; i < N; ++i)
      S[0][i] = (S[0][i - 1] * B + A) % C;

    for (int TWICE = 0; TWICE < 2; ++TWICE) {
      memset(bucket, 0, sizeof(bucket));
      for (int i = 0; i < N; ++i)
        bucket[OP(S[TWICE][i])]++;
      for (int i = 1; i < (1 << 16); ++i)
        bucket[i] += bucket[i - 1];
      for (int i = N - 1; i >= 0; --i)
        S[1 - TWICE][--bucket[OP(S[TWICE][i])]] = S[TWICE][i];
    }

    V = 0;
    for (int i = 0; i < N; ++i)
      V = (V * X + S[0][i]) % Y;
    cout << V << '\n';
  }

  return 0;
}
