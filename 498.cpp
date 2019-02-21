#include <bits/stdc++.h>
using namespace std;

int main() {
  string c, x;
  while(getline(cin, c)) {
    getline(cin, x);
    vector<long long> C, X;
    C.clear();
    X.clear();
    long long a, n = -1, m = 0;
    stringstream ss;
    ss << c;
    while(ss >> a) {
      C.push_back(a);
      n++;
    }
    ss.clear();
    ss << x;
    while(ss >> a) {
      X.push_back(a);
      m++;
    }
    vector<long long> ans(m);
    for(long long i = 0; i < m; i++) {
      vector<long long> p(n + 1);
      p[n] = C[0];
      for(long long j = n - 1, k = 1; j >= 0; j--, k++) {
        p[j] = p[j + 1] * X[i] + C[k];
      }
    ans[i] = p[0];
    }
    for(long long i = 0; i < m; i++) {
      if(i == m - 1)
      cout << ans[i] << '\n';
      else cout << ans[i] << ' ';
    }
  }
  return 0;
}
