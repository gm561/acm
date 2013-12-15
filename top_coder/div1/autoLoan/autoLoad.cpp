#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define VI vector<int>
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second

const double EPS = 10e-13;

struct AutoLoad {

    bool isTooHigh(double ir, double p, double mp, int lt) {
	double balance = p;
	REP(i, lt) balance = balance * (1.0 + ir/12.0) - mp;

	return balance > 0;
    }

    double interestRate(double p, double mp, int lt) {

	double lo = 0.0;
	double hi = 100.0;
	while(hi - lo > EPS) {
	    double mid = lo + (hi - lo) / 2;
	    if(isTooHigh(mid, p, mp, lt)) hi = mid;
	    else lo = mid;
	}

	return lo*100.0;
    }
};

int main() {

    AutoLoad al;
    cout << al.interestRate(6800, 680, 10) << endl;
    cout << al.interestRate(2000, 510, 4) << endl;
    cout << al.interestRate(15000, 364, 48) << endl;

    return 0;
}
