#include <sstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <fstream>
#include <bitset>
#include <numeric>

using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef pair<int, int> pii;

#define EPS 10e-9
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define MP(x,y) make_pair(x,y)
#define ALL(x) (x).begin(), (x).end()
#define FT first
#define ST second
#define FOREACH(i, c) for(typeof((c.begin())) i = (c).begin() ; i != (c).end(); ++i)
#define PB(x) push_back((x))
#define SZ(x) (int)x.size()
#define LN(x) (int)(x).length()
#define INF 1000001

struct PackingShapes {
bool isRec(int w, int h, int rw, int rh) {
	double lo = 0;
	double hi = M_PI / 2;
	if(rw > w && rh > h) return false;
	int t = 100;
	while(t--) {
		double mid = lo + (hi -  lo) / 2;
		int mH = rw * sin(mid) + rh * cos(mid);
		int mW = rw * cos(mid) + rh * sin(mid);
		if(mH - EPS <= h && mW - EPS <= w) return true;
        if(mH >= h) hi = mid;
        else lo = mid;
    }
	return false;
}

bool isCir(int w, int h, int r) {
	return w >= 2*r && h >= 2*r;
}

vector<string> tryToFit(int width, int height, const vector<string>& shapes) {
	vector<string> results;
    REP(i, SZ(shapes)) {
		stringstream ss(shapes[i]);
		vector<string> res;
        string shape; ss >> shape;
        bool pr;
        if(shape == "RECTANGLE") {
            int rw, rh; ss >> rw >> rh;
            pr = isRec(width, height, max(rw,rh), min(rw,rh));
        }
        else {
            int rad; ss >> rad;
            pr = isCir(width, height, rad);
        }

        results.PB((pr) ? "YES" : "NO");
    }
	return results;
}
};

int main() {
    PackingShapes ps;
    string as[] = { "RECTANGLE 1 3"};

    vector<string> vs(as, as + 1);
    vector<string> rs = ps.tryToFit(2, 2, vs);
    REP(i, SZ(rs)) cout << rs[i] << endl;

    return 0;
}
