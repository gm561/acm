#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define SZ(x) (int)(x).size()

using namespace std;

typedef vector<int> VI;

void algo(const string& line) {
    stringstream ss(line);
    int n; ss >> n;
    int z; VI ns;
    while(ss >> z) ns.push_back(z);

    VI pres(n-1, 0);
    REP(i, SZ(ns)-1) {
        int x = abs(ns[i+1] - ns[i]) - 1;
        if(x >= 0 && x < SZ(pres)) pres[x] = 1;
    }

    bool is_good = true;
    REP(i, SZ(pres)) if(!pres[i]) is_good = false;

    if(SZ(ns) == 1) is_good = true;
    cout << ((is_good) ? "Jolly\n" : "Not jolly\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    string line;
    while(getline(cin, line)) {
        algo(line);
    }

    return 0;
}
