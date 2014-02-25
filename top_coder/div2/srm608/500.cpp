#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <complex>
#include <iterator>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>

using namespace std;

#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()

struct MysticAndCandiesEasy {

    int minBoxes(int C, int X, vector<int> high) {
	if(SIZE(high) == 0) return 0;
	sort(high.begin(), high.end());
	int bs = SIZE(high);

	int i = 0;
	while(bs - i > 0 && C >= X) C -= high[i++];

	--i;
	return bs - i;
    }
};


int main(int argc, char *argv[]) {
    MysticAndCandiesEasy m;
    vector<int> h0;
    h0.push_back(20);
    cout << m.minBoxes(10, 10, h0) << endl;

    vector<int> h1;
    h1.push_back(3);
    h1.push_back(3);
    h1.push_back(3);
    h1.push_back(3);
    h1.push_back(3);
    cout << m.minBoxes(10, 7, h1) << endl;


    vector<int> h2;
    h2.push_back(12);
    h2.push_back(34);
    h2.push_back(23);
    h2.push_back(45);
    h2.push_back(34);
    cout << m.minBoxes(100, 63, h2) << endl;



    return 0;
}
