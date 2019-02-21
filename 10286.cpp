#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x;
  string a;
  while(cin >> x) {
    cin.ignore();
    getline(cin, a);
    stringstream ss(a);
    vector<long long> A;
    A.clear();
    long long l, n = -1;
    while(ss >> l) {
	    A.push_back(l);
	    n++;
    }
    if(A.size() == 1) {
	    cout << "0\n";
	    continue;
    }
    vector<long long> p(n + 1);
    p[n] = A[0] * n;
    for(long long i = n - 1; i >= 1; i--) {
      p[i] = p[i + 1] * x + A[n - i] * i;
    }
    cout << p[1] << '\n';
  }
  return 0;
}
