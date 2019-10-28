#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long int slong;
typedef pair<int, int> pii;
typedef pair<slong, slong> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds;
typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1000000007;
const int MAXN = 50;
const int SQRTN = 550;
const int LOGN = 60;
const int INT_INFINITY = 1001001001;
const int LIMIT = 1e6;

const slong LONG_INFINITY = 1001001001001001001ll;
const slong LONG_LIMIT = 200100100100101ll;

int N, P;
int req[MAXN + 5];
int amount[MAXN + 5][MAXN + 5];

int memo[10][(1 << 10)];

const int TRY = 10000;

int findTwo(int index, int mask) {
  if (index == P) {
    return 0;
  } else {
    if (memo[index][mask] != -1) {
      return memo[index][mask];
    }

    int best = 0;

    // unmatched
    best = max(best, findTwo(index + 1, mask));

    // match this
    int canmake = amount[0][index] / req[0];

    {
      for (int step = 0; step <= TRY && ((canmake - step) >= 1); step++) {
        int nowmake = canmake - step;

        {
          slong reqvolume = 1ll * nowmake * req[0];
          slong currentvolume = amount[0][index];

          if ((10 * currentvolume >= 9 * reqvolume) &&
              (10 * currentvolume <= 11 * reqvolume)) {
            // match with other
            for (int j = 0; j < P; j++) {
              if ((mask & (1 << j)) == 0) {
                slong y = 1ll * nowmake * req[1];
                slong x = amount[1][j];

                if ((10 * x >= 9 * y) && (10 * x <= 11 * y)) {
                  best = max(best, 1 + findTwo(index + 1, mask | (1 << j)));
                }
              }
            }
          }
        }
      }

      for (int step = 0; step <= TRY; step++) {
        int nowmake = canmake + step;

        {
          slong reqvolume = 1ll * nowmake * req[0];
          slong currentvolume = amount[0][index];

          if ((10 * currentvolume >= 9 * reqvolume) &&
              (10 * currentvolume <= 11 * reqvolume)) {
            // match with other
            for (int j = 0; j < P; j++) {
              if ((mask & (1 << j)) == 0) {
                slong y = 1ll * nowmake * req[1];
                slong x = amount[1][j];

                if ((10 * x >= 9 * y) && (10 * x <= 11 * y)) {
                  best = max(best, 1 + findTwo(index + 1, mask | (1 << j)));
                }
              }
            }
          }
        }
      }
    }

    memo[index][mask] = best;

    return best;
  }
}

int ansForOne() {
  int i, j;
  int ans = 0;

  for (j = 0; j < P; j++) {
    int canmake = amount[0][j] / req[0];

    bool possi = false;

    for (int step = 0; step <= TRY && ((canmake - step) >= 1); step++) {
      int nowmake = canmake - step;

      {
        slong reqvolume = 1ll * nowmake * req[0];
        slong currentvolume = amount[0][j];

        if ((10 * currentvolume >= 9 * reqvolume) &&
            (10 * currentvolume <= 11 * reqvolume)) {
          possi = true;
        }
      }
    }

    for (int step = 0; step <= TRY; step++) {
      int nowmake = canmake + step;

      {
        slong reqvolume = 1ll * nowmake * req[0];
        slong currentvolume = amount[0][j];

        if ((10 * currentvolume >= 9 * reqvolume) &&
            (10 * currentvolume <= 11 * reqvolume)) {
          possi = true;
        }
      }
    }

    if (possi) {
      ans++;
    }
  }

  return ans;
}

int main() {

  cout.tie(0);
  cin.tie(0);

  int t, T, i, j;

  cin >> T;

  for (t = 1; t <= T; t++) {
    cin >> N >> P;

    for (i = 0; i < N; i++) {
      cin >> req[i];
    }

    for (i = 0; i < N; i++) {
      for (j = 0; j < P; j++) {
        cin >> amount[i][j];
      }
    }

    memset(memo, -1, sizeof(memo));

    if (N == 1) {
      cout << "Case #" << t << ": " << ansForOne() << endl;
    } else if (N == 2) {
      cout << "Case #" << t << ": " << findTwo(0, 0) << endl;
    } else {
      cout << "Case #" << t << ": " << -1 << endl;
    }
  }

  return 0;
}
