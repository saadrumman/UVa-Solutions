#include <bits/stdc++.h>
using namespace std;

const double PI = 2 * acos(0);
const double E = 0.000001;

int R, t;
double P, area, cur, rope, x, y, l, r;

double com_area() {
  return asin(y / R) * R * R + asin(y / rope) * rope * rope
  - x * y - (R - x) * y;
}

int main() {
  cin >> t;
  while(t--) {
    cin >> R >> P;
    area = P * PI * R * R;
    cur = -1;
    rope = 0;
    l = 2 * R;
    r = 0;
    do {
      if(area < cur) {
        l = rope;
        rope = (l + r) / 2; 
      }
      else {
        r = rope;
        rope = (l + r) / 2;
      }
      x = R - (rope * rope) / (2 * R);
      y = sqrt(R * R - x * x);
      cur = com_area();
    } while(abs(area - cur) >= E);
    cout << fixed << setprecision(2);
    cout << "R = " << R << ", P = " << P 
    << ", Rope = " << rope << "\n\n";
  }
  return 0;
}
