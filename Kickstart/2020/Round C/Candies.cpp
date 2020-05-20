// Work Hard,Party Harder- Devang Sharma, MAIT DELHI

#include <bits/stdc++.h>
#define maxn 200003
using namespace std;
typedef long long LL;

int T, n, m;
LL ar[maxn];
LL sum1[maxn];
LL sum2[maxn];
vector<LL> tree1, tree2;

void reset()
{
    tree1.clear();
    tree1.resize(4 * n + 1, 0);
    tree2.clear();
    tree2.resize(4 * n + 1, 0);
}

void update(int cx, int cy, int qx, int qy, int id, LL add, vector<LL> &tree)
{
    if (cy < qx || qy < cx)
        return;
    if (qx <= cx && cy <= qy)
    {
        tree[id] += add;
        return;
    }
    int mid = (cx + cy) >> 1;
    update(cx, mid, qx, qy, id * 2, add, tree);
    update(mid + 1, cy, qx, qy, id * 2 + 1, add, tree);
}

LL query(int cx, int cy, int q, int id, vector<LL> &tree)
{
    if (cy < q || q < cx)
        return 0;
    if (cx == cy)
        return tree[id];
    int mid = (cx + cy) >> 1;
    LL total = tree[id];
    total += query(cx, mid, q, id * 2, tree);
    total += query(mid + 1, cy, q, id * 2 + 1, tree);
    return total;
}

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d%d", &n, &m);
        reset();
        for (int i = 1; i <= n; i++)
            scanf("%lld", &ar[i]);
        for (int i = 1; i <= n; i++)
        {
            sum1[i] = sum1[i - 1];
            sum2[i] = sum2[i - 1];
            if (i % 2)
            {
                sum1[i] += ar[i];
                sum2[i] += i * ar[i];
            }
            else
            {
                sum1[i] -= ar[i];
                sum2[i] -= i * ar[i];
            }
            update(1, n, i, i, 1, sum1[i], tree1);
            update(1, n, i, i, 1, sum2[i], tree2);
        }
        LL ans = 0;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            char s[3];
            scanf("%s%d%d", s, &x, &y);
            if (s[0] == 'U')
            {
                LL diff = y - ar[x], diff1, diff2;
                if (x % 2)
                {
                    diff1 = diff;
                    diff2 = x * diff;
                }
                else
                {
                    diff1 = -diff;
                    diff2 = -x * diff;
                }
                update(1, n, x, n, 1, diff1, tree1);
                update(1, n, x, n, 1, diff2, tree2);
                ar[x] = y;
            }
            else
            {
                LL diff1 = query(1, n, y, 1, tree1) - query(1, n, x - 1, 1, tree1);
                LL diff2 = query(1, n, y, 1, tree2) - query(1, n, x - 1, 1, tree2);
                LL total = diff2 - diff1 * (x - 1);
                if (x % 2 == 0)
                    total = -total;
                ans += total;
            }
        }
        printf("Case #%d: %lld\n", tc, ans);
    }
    return 0;
}