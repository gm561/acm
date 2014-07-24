#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

#define REP(x, n) for(int x = 0; x < (n); ++x)

using namespace std;

void algo(int n) {
    string line;
    while(getline(cin , line), line != "0") {
        vector<int> perm(n, 0);
        stringstream ss(line);
        REP(i, n) ss >> perm[i];

        stack<int> st;
        int j = 1;
        REP(i, n) {
            while(st.empty() || st.top() < perm[i]) st.push(j++);
            if(!st.empty() && st.top() == perm[i]) st.pop();
        }

        cout << ((st.empty()) ? "Yes\n" : "No\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string line;

    while(getline(cin, line), line != "0") {
        stringstream ss(line);
        ss >> n;
        algo(n);
        cout << "\n";
    }
    return 0;
}

