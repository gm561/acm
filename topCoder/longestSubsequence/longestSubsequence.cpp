#include <cassert>
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
typedef vector<vector<int> > VVI;
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

int longestSubsequence(VI &seq) {
    int n = seq.size();
    VI A(n, 0);
    for(int i = 0; i < n; ++i) {
        A[i] = 1;
        for(int j = 0; j < i; ++j)
            A[i] = (seq[j] < seq[i]) ? max(A[j] + 1, A[i]) : A[i];
    }
    return *max_element(A.begin(), A.end());
}

int main(int argc, char *argv[]) {
    int as[] = {1,2,1,1,3,2,4};
    VI vs(as, as + sizeof(as) / sizeof(int));
    cout << longestSubsequence(vs) << endl;
    return 0;
}
