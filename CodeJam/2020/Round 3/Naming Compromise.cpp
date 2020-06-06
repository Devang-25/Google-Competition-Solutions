//"Dont Stop When you are Tired, Stop When You are Done "
//Devang Sharma- Droer

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ct;
    cin >> ct;
    
    for (int t = 0; t < ct; ++t) 
    {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, MAXN));

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i - 1 >= 0) {
                        dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                    }
                    if (j - 1 >= 0) {
                        dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
                    }
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        dp[i][j] = min(dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]? 0 : 1), dp[i][j]);
                    }
                }
            }

        {
            int target = dp[n][m] / 2;
            std::string s;

            int i = n, j = m;
            while (dp[i][j] > target)
            {
                if (i - 1 >= 0 && dp[i][j] == dp[i - 1][j] + 1)
                {
                    s.push_back(a[i - 1]);
                    --i;
                }
                else if (i - 1 >= 0 && j - 1 >= 0 && dp[i][j] == dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]? 0 : 1))
                {
                    s.push_back(a[i - 1]);
                    --i;
                    --j;
                }
                else
                {
                    --j;
                }
            }
            while (i > 0 || j > 0)
            {
                if (j - 1 >= 0 && dp[i][j] == dp[i][j - 1] + 1)
                {
                    s.push_back(b[j - 1]);
                    --j;
                }
                else if (i - 1 >= 0 && j - 1 >= 0 && dp[i][j] == dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]? 0 : 1))
                {
                    s.push_back(b[j - 1]);
                    --i;
                    --j;
                }
                else
                {
                    --i;
                }
            }

            reverse(s.begin(), s.end());

            cout << "Case #" << (t + 1) << ": " << s << endl;
        }
    }

    return 0;
}
