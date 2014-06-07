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


struct Mortgage {

	int monthlyPayment(int loan, int in, int term) {
		LL lo = 0;
        LL hi = loan;

        while(lo < hi) {
            LL mid = lo + (hi -  lo) / 2L;
            LL toPay = loan;
            for(int i = 0; i < term * 12; ++i) {
                toPay -= mid;
                if(toPay <= 0L || toPay >= loan) break;
                toPay = ceil(((long double)in / 12.0 / 1000.0 + 1) * toPay);
            }

            if(toPay > 0) lo = mid + 1;
            else if(toPay <= 0) hi = mid;
        }

		return hi;
    }
};


int main(int argc, char *argv[])
{
    Mortgage m;
    cout << m.monthlyPayment(1000000, 1000000, 1000) << endl;

    return 0;
}
