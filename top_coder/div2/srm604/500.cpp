
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()

typedef long long LL;

struct PowerOfThreeEasy {

    bool pos(LL x, LL y, LL k) {
	if(x < 0 || y < 0) return false;
	if(x == 0 && y == 0) return true;

	bool b0 = pos(x - k, y, k*3);
	bool b1 = pos(x, y - k, k*3);

	return b0 || b1;
    }


    string ableToGet(LL x, LL y) {
	if(pos(x, y, 1)) return "Possible";
	return "Impossible";
    }
};

int main() {
    PowerOfThreeEasy pow;
    cout << pow.ableToGet(1, 3) << endl;
    cout << pow.ableToGet(1, 1) << endl;
    cout << pow.ableToGet(3, 0) << endl;
    cout << pow.ableToGet(1, 9) << endl;
    cout << pow.ableToGet(3, 10) << endl;
    cout << pow.ableToGet(1093, 2187) << endl;
    cout << pow.ableToGet(0, 0) << endl;
    cout << pow.ableToGet(1000000000, 1000000000) << endl;
    return 0;
}
