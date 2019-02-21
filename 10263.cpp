#include <bits/stdc++.h>
using namespace std;

const double E = .0000000001;

double Xm, Ym, ax, ay, bx, by, cx, cy, da, db, dc, rx, ry, mn;
int N;
vector<double> X, Y;

double com(double x, double y) {
  return sqrt((x - Xm) * (x - Xm) + (y - Ym) * (y - Ym));
}

int main() {
  while(cin >> Xm >> Ym >> N) {
    X.resize(N + 1);
    Y.resize(N + 1);
    for(int i = 0; i <= N; ++i) cin >> X[i] >> Y[i];
    mn = DBL_MAX;
    for(int i = 1; i <= N; ++i) {
      ax = X[i - 1];
      ay = Y[i - 1];
      bx = X[i];
      by = Y[i];
      da = com(ax, ay);
      db = com(bx, by);
      while(abs(ax - bx) >= E || abs(ay - by) >= E) {
        cx = (ax + bx) / 2;
        cy = (ay + by) / 2;
        dc = com(cx, cy);
        if(dc <= mn) {
          rx = cx;
          ry = cy;
          mn = dc;
        }
        if(da == db) break;
        else if(da < db) {
          bx = cx;
          by = cy;
          db = dc;
        }
        else {
          ax = cx;
          ay = cy;
          da = dc;
        }
      }
    }
    cout << fixed << setprecision(4);
    cout << rx << '\n' << ry << '\n';
  }
  return 0;
}
