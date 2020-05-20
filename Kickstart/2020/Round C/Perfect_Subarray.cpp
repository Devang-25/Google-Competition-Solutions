// Work Hard,Party Harder- Devang Sharma, MAIT DELHI
// Trying Second Time, Hoping to compete TLE

#include <bits/stdc++.h>
#define fi first
#define se second
#define maxs 20000001
using namespace std;
typedef long long LL;
typedef pair<int, int> pi;

int T, n;
pi cnt[maxs];

void update(int val, int tc)
{
    if (cnt[val].se != tc)
        cnt[val] = pi(1, tc);
    else
        cnt[val].fi++;
}

int query(int val, int tc)
{
    if (cnt[val].se != tc)
        return 0;
    return cnt[val].fi;
}

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d", &n);
        LL ans = 0;
        int sum = maxs / 2;
        int mn = sum;
        update(sum, tc);
        for (int i = 1; i <= n; i++)
        {
            int val;
            scanf("%d", &val);
            sum += val;
            for (int j = 0; sum - j * j >= mn; j++)
                ans += query(sum - j * j, tc);
            update(sum, tc);
            mn = min(mn, sum);
        }
        printf("Case #%d: %lld\n", tc, ans);
    }
    return 0;
}