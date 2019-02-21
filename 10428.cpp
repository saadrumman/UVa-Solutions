#include <bits/stdc++.h>
using namespace std;

const double E = 0.000001;

int N, n, c = 0;
vector<double> a, b, root;
double x, pr;

void process() {
  for(int i = n - 1; i >= 0; --i) {
    b[i] = a[i + 1] * (i + 1);
  }
  return;
}

double com() {
  double prod = 1, sum = a[0];
  for(int i = 1; i <= n; ++i) {
    prod *= x;
    sum += prod * a[i];
  }
  return sum;
}

double dif() {
  double prod = 1, sum = b[0];
  for(int i = 1; i <= n - 1; ++i) {
    prod *= x;
    sum += prod * b[i];
  }
  return sum;
}

void deflate() {
  vector<double> c = a;
  a[n] = 0;
  for(int i = n - 1; i >= 0; --i) {
    a[i] = c[i + 1] + a[i + 1] * x;
  }
  return;
}

int main() {
  while(1) {
    cin >> N;
    if(N == 0) break;
    a.resize(N + 1);
    b.resize(N);
    root.resize(N);
    for(int i = N; i >= 0; --i) {
      cin >> a[i];
    }
    n = N;
    for(int i = 0; i < N; ++i) {
      process();
      if(!i) x = 25;
      else x = root[i - 1];
      do {
        pr = x;
        x = x - com() / dif();
      } while(abs(x - pr) >= E);
      root[i] = x;
      deflate();
      --n;
    }
    sort(root.begin(), root.end());
    cout << fixed << setprecision(4);
    cout << "Equation " << ++c << ':';
    for(double i : root) cout << ' ' << i;
    cout << '\n';
  }
  return 0;
}
