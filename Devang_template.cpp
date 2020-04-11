#include<bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;


int taken[100];

bool dfs(vector<int>& v, int szneed, int totleft) {
  if(totleft < szneed - sz(v)) return false;
  if(totleft > (szneed - sz(v)) * szneed) return false;
  if(sz(v) == szneed) {
    for(int a = 1; a <= szneed; a++) if(taken[a] == szneed-1) return false;
    return true;
  }
  for(int i = 1; i <= szneed; i++) {
    taken[i]++;
    v.push_back(i);
    if(dfs(v, szneed, totleft - i)) return true;
    v.pop_back();
    taken[i]--;
  }
  return false;
}

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

int ret[55][55];


void solve() {
  int t;
  cin >> t;
  for(int casenum = 1; casenum <= t; casenum++) {
    cout << "Case #" << casenum << ": ";
    rsolve();
  }
}

int main() {
  solve();
}
