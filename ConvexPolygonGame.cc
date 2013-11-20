#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <cstring>
#include <complex>
#include <numeric>
#include <functional>
//#define NDEBUG
#include <cassert>
#include <limits>
//INT_MAX INT_MIN
#include <limits.h>
#include <cstdarg>
#include <iterator>
#include <valarray>
using namespace std;
#define debug(x) cerr<<#x<<"=\""<<x<<"\""<<" at line#"<<__LINE__<<endl;
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(typeof(a) i=a;i<(b);++i)
#define SZ(vec) ((int)(vec).size())
#define All(vec) (vec).begin(),(vec).end()
typedef long long int llint;

llint Cross(llint x1, llint y1, llint x2, llint y2) {
  return x1 * y2 - x2 * y1;
}

bool GetInter(llint y, llint x1, llint y1, llint x2, llint y2, double& ix) {
  vector<llint> ret;
  if ((y1 - y) * (y2 - y) > 0) return false;
  ix = 1.0 * (x2 - x1) * ( y - y1) / (y2 - y1) + x1; 
  return true;
}

bool InPolygon(const vector<int>& X, const vector<int>& Y, int x, int y) {
  const int n = SZ(X) - 1;
  Rep(i, n) {
    if (X[i] == x && Y[i] == y) return false;
    if (Cross(X[i+1] - X[i], Y[i+1] - Y[i], x - X[i], y - Y[i])< 0) return false;
  }
  return true;
}

typedef pair<int, int> pii;

class ConvexPolygonGame {
 public:
  string winner(vector <int> X, vector <int> Y) {
    const int Y1 = *min_element(All(Y));
    const int Y2 = *max_element(All(Y));
    const int n = SZ(X);
    X.push_back(X[0]);
    Y.push_back(Y[0]);
    vector<pii> inter;
    for (int y = Y1; y <= Y2; ++y) {
      double dx1 = 1e8, dx2 = -1e8;
      Rep(i, n) {
        double ix;
        if (GetInter(y, X[i], Y[i], X[i+1], Y[i+1], ix)) {
          dx1 = min(ix, dx1);
          dx2 = max(ix, dx2);
        }
      }
      const int E = 20;
      int x1 = dx1 - E;
      while (x1 < dx1 + E && !InPolygon(X, Y, x1, y)) x1++;
      int x2 = dx2 + E;
      while (x2 > dx2 - E && !InPolygon(X, Y, x2, y)) x2--;
      if (InPolygon(X, Y, x1, y)) inter.push_back(pii(x1, y));
      if (x2 != x1 && InPolygon(X, Y, x2, y)) inter.push_back(pii(x2, y));
    }
    if (SZ(inter) < 3) return "Petya";
    sort(All(inter));
    if (inter[0].first == inter.back().first) return "Petya";
    Rep(i, SZ(inter)) swap(inter[i].first, inter[i].second);
    sort(All(inter));
    if (inter[0].first == inter.back().first) return "Petya";
    return "Masha";
  }
};
