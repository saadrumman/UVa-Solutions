#include <bits/stdc++.h>
using namespace std;

int k, n, r;
string s;
vector<int> a, b;

int com_r() {
  int sum = a[n], prod = 1;
  for(int i = n - 1; i >= 0; --i) {
    prod *= k;
    sum += prod * a[i];
  }
  return sum;
}

void com_b() {
  b[0] = 0;
  for(int i = 1; i <= n; ++i) {
    b[i] = a[i - 1] + b[i - 1] * k;
  }
  return;
}

int main() {
  while(cin >> k) {
    cin.ignore();
    getline(cin, s);
    stringstream ss(s);
    a.clear();
    n = -1;
    int temp;
    while(ss >> temp) {
      a.push_back(temp);
      ++n;
    }
    b.resize(n + 1);
    r = com_r();
    a[n] -= r;
    com_b();
    cout << "q(x):";
    for(int i = 1; i <= n; ++i) cout << ' ' << b[i];
    cout << '\n';
    cout << "r = " << r << "\n\n";
  }
  return 0;
}
