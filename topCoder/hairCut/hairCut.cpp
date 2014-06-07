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

#define EPS 10e-10
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


struct HairCut {

	double maxCut(vector<string> &enter, string& exit) {
		vector<double> times;
		for(int i = 0; i < enter.size(); ++i) {
			int hour = atoi(enter[i].substr(0, 2).c_str());
			if(hour < 7) hour += 12;
			int time = hour * 60  + atoi(enter[i].substr(3, 2).c_str());
			times.PB(time);
        }
        sort(times.begin(), times.end());

        int h0 = atoi(exit.substr(0,2).c_str());
        if(h0 < 7) h0 += 12;
        int exitTime = h0 * 60 + atoi(exit.substr(3,2).c_str());

        double lo = 0.0;
        double hi = 24.0 * 60.0;
        int t = 100;
        while(t--) {
            double mid = lo + (hi - lo) / 2.0;
            double curTime = times[0] + mid;
            for(int i = 1; i < times.size(); ++i)
                curTime = max(times[i], curTime) + mid;

            if(curTime < exitTime) lo = mid;
            else hi = mid;
        }

        return (hi + EPS < 5) ? -1 : hi;
    }
};


int main(int argc, char *argv[]) {
    string as[] = {"01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00", "01:00"} ;
    vector<string> vs(as, as + sizeof(as) / sizeof(string));
    string exit = "05:10";
    HairCut hc;
    cout << hc.maxCut(vs, exit) << endl;
    return 0;
}
