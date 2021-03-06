#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define out(a)                                                                 \
  for (auto i : a)                                                             \
    cout << i << " ";
#define outl(a)                                                                \
  for (auto i : a)                                                             \
    cout << i << endl;

// ll n,m,k;
string str, s1, s2;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  freopen("/Users/shitian/Desktop/gcj/gcj/A-small-attempt0.in", "r", stdin);
  freopen("/Users/shitian/Desktop/gcj/gcj/A-small-attempt0.txt", "w", stdout);
  int tcase;
  cin >> tcase;
  for (int tc = 1; tc <= tcase; tc++) {
    cout << "Case #" << tc << ": ";

    int d, n;
    cin >> d >> n;
    double max_time = 0;
    FOR(i, n) {
      int k, s;
      cin >> s >> k;
      int delta = d - s;
      double time = (double)delta / k;
      max_time = max(max_time, time);
    }
    double speed = (double)d / max_time;
    printf("%.10f\n", speed);
  }

  return 0;
}
