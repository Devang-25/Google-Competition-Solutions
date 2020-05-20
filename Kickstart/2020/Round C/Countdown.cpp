// Believe in Yourself, The World Will Bow- Devang Sharma, MAIT DELHI

#include <bits/stdc++.h>

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define big(x) greater<x>()
#define ll long long int
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    fast int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        int n, k;
        cin >> n >> k;
        int arr[n], ans = 0;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == k)
            {
                int j;
                for (j = 1; j < k and (i + j) < n; ++j)
                    if (arr[i + j] != (k - j))
                        break;
                if (j == k)
                    ans++;
                i += j - 1;
            }
        }
        cout << "Case #" << test + 1 << ": " << ans << "\n";
    }
}