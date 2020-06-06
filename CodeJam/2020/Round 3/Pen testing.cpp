/*
Done With My Approach, 1 out of 3 TC Passed. Score: 6/32.
--Debugging Korotkevich's Solution.

The Guy is a Genius, Solved This Complex Problem Using Simple C++ STL
-Devang Sharma
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, n, c;
  cin >> t >> n >> c;
  auto Evaluate = [&](const vector<int>& asked, const vector<int>& alive) {
    int bound = 0;
    for (int i = 0; i < n; i++) {
      if (!alive[i]) {
        bound += 1;
      }
    }
    vector<int> dec;
    for (int i = n - 1; i >= 0; i--) {
      if (alive[i]) {
        dec.push_back(asked[i]);
        if (dec.size() == 2) {
          break;
        }
      }
    }
    int good = 0;
    int bad = 0;
    for (int x = bound; x < n; x++) {
      for (int y = x + 1; y < n; y++) {
        if (x + y - dec[0] - dec[1] >= n) {
          good += 1;
        } else {
          bad += 1;
        }
      }
    }
    return 1.0 * good / (good + bad);
  };
  vector<vector<int>> asked(t, vector<int>(n, 0));
  vector<vector<int>> alive(t, vector<int>(n, 1));
  vector<int> searching(t, 0);
  vector<int> think_about_it(t, 1);
  vector<int> dead(t, 0);
  while (true) {
    vector<int> to_ask(t, -1);
    for (int q = 0; q < t; q++) {
      if (dead[q]) {
        continue;
      }
      vector<int> options;
      for (int i = 0; i < n; i++) {
        if (alive[q][i] && asked[q][i] <= searching[q]) {
          options.push_back(i);
        }
      }
      if (think_about_it[q]) {
        if (searching[q] >= 12) {
          dead[q] = 1;
          continue;
        }
        {
          double cur = Evaluate(asked[q], alive[q]);
          double total = 0;
          for (int it = 0; it < (int) options.size(); it++) {
            vector<int> aux_asked = asked[q];
            vector<int> aux_alive = alive[q];
            for (int jt = 0; jt < it; jt++) {
              aux_asked[options[jt]] = searching[q] + 1;
            }
            aux_asked[options[it]] = searching[q];
            aux_alive[options[it]] = 0;
            total += Evaluate(aux_asked, aux_alive);
          }
          total /= (int) options.size();
//          if (q < 1)
//            debug(q, cur, total, searching[q], options);
          if (cur > total) {
            dead[q] = 1;
            continue;
          }
        }
      }
      to_ask[q] = options[0];
    }
    bool any = false;
    for (int i = 0; i < t; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << to_ask[i] + 1;
      if (to_ask[i] != -1) {
        any = true;
      }
    }
    cout << endl;
//    debug(to_ask);
    if (!any) {
      break;
    }
    for (int q = 0; q < t; q++) {
      int foo;
      cin >> foo;
      think_about_it[q] = 0;
      if (to_ask[q] == -1) {
        continue;
      }
      if (foo == 1) {
        asked[q][to_ask[q]] += 1;
      } else {            
        alive[q][to_ask[q]] = 0;
        searching[q] += 1;
        think_about_it[q] = 1;
      }
    }
  }
  for (int i = 0; i < t; i++) {
    if (i > 0) {
      cout << " ";
    }
    vector<int> ret;
    for (int j = n - 1; j >= 0; j--) {
      if (alive[i][j]) {
        ret.push_back(j);
      }
    }
    cout << ret[0] + 1 << " " << ret[1] + 1;
  }
  cout << endl;
  return 0;
}
