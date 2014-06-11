#include <cassert>
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

struct PackingBallsDiv2 {

    int minPacks(int R, int G, int B) {
	int result = 0;
	while(R > 0 && G > 0 && B > 0) ++result, --R,--B,--G;

	int r3 = R / 3;
	int g3 = G / 3;
	int b3 = B / 3;

	result += r3 + g3 + b3;
	R -= r3 * 3;
	G -= g3 * 3;
	B -= b3 * 3;

	while(R * G > 0 || R * B > 0 || G * B > 0){
	    if(R * G > 0) --R,--G;
	    else if(R * B > 0) --R,--B;
	    else if(G * B > 0) --G,--B;
	    ++result;

	    R = max(R,0);
	    G = max(G,0);
	    B = max(B,0);
	}

	int r2 = R / 2;
	int g2 = G / 2;
	int b2 = B / 2;

	result += r2 + g2 + b2;

	R -= r2 * 2;
	G -= g2 * 2;
	B -= b2 * 2;

	return result + R + G + B;
    }
};


int main() {
    PackingBallsDiv2 pb;


    assert(pb.minPacks(4,2,4) == 4);
    assert(pb.minPacks(1,7,1) == 3);
    assert(pb.minPacks(2,3,5) == 4);
    assert(pb.minPacks(78,53,64) == 66);
    assert(pb.minPacks(100,100,100) == 100);

    return 0;
}
