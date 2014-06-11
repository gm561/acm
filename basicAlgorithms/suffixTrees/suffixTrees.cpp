#include <stack>
#include <set>
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
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<LL> VL;
typedef vector<vector<LL> > VVL;
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

struct Node {
    map<char, Node> childs;
    char v;
    Node(char v_) : v(v_) { }
};


void naiveSuffixTreeBuild(Node* root, const string& s) {
    int ns = s.length() - 1;
    while(ns >= 0) {
        Node* node = root;
        for(int i = ns; i < s.length(); ++i) {
            map<char,Node>::iterator it = node->childs.find(s[i]);
            if(it == node->childs.end()) {
                it = node->childs.insert(make_pair(s[i], Node(s[i]))).first;
            }
            node = &(it->second);
        }
        ns--;
    }
}

void printTree(Node& node) {
    cout << node.v << endl;
    int sz = node.childs.size();
    if(!sz) cout << "end" << endl;
    for(map<char, Node>::iterator it = node.childs.begin(); it != node.childs.end(); ++it) {
        printTree(it->second);
    }
}

int main() {
    Node root('R');
    naiveSuffixTreeBuild(&root, "aabc");
    printTree(root);
    return 0;
}
