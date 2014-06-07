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

struct UnionOfIntervals {

    int nthElement(const vector<int>& lowerBound, vector<int>& upperBound, int n) {
        long long lo = -2000000000L;
        long long hi =  2000000000L;

        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2L;
            long long count = 0L;
            long long in = 0L;

            for(int i = 0; i < lowerBound.size(); ++i) {
                if(lowerBound[i] <= mid && mid <= upperBound[i]) {
                    count += mid - lowerBound[i]; ++in;
                }
                else if(upperBound[i] < mid) count += upperBound[i] - lowerBound[i] + 1;
            }

            if(count <= n && count + in > n) return mid;
            else if(count == n) {
                int result = 2000000000;
                for(int i = 0; i < upperBound.size(); ++i)
                    result = (lowerBound[i] > mid) ? min(lowerBound[i], result) : result;
                return result;
            }
            else if(count < n) lo = mid + 1;
            else hi = mid - 1;
       }
       return -1;
    }
};


int main(int argc, char *argv[]) {
    int as0[] = {1,5};
    int as1[] = {3,7};
    VI l(as0, as0 + 2);
    VI h(as1, as1 + 2);
    UnionOfIntervals u;
    cout << u.nthElement(l,h,4) << endl;
    return 0;
}
