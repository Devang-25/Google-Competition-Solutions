//"Dont Stop When you are Tired, Stop When You are Done "
//Devang Sharma- Droer

#include <bits/stdc++.h>
using namespace std;

int ans_l(const vector<int> &d)
{
    int n = d.size();
    long long l = 0, r = 1000000001;
    long long a = 0;
    int sign = 1;
    for (int i = 0; i < n; ++i)
    {
        if (sign)
        {
            l = max(l, -a);
            r = min(r, d[i] - a);
            a = d[i] - a;
            sign = 0;
        }
        else
        {
            l = max(l, a - d[i]);
            r = min(r, a);
            a = d[i] - a;
            sign = 1;
        }
        if (l >= r)
        {
            vector<int> d2(d.data() + i, d.data() + n);
            int ret = ans_l(d2) + 1;
            return ret;
        }
    }

    return 0;
}

int ans_c(const vector<int> &d)
{
    int n = d.size();
    long long l = 0, r = 1000000001;
    long long a = 0;
    int sign = 1;
    for (int i = 0; i < n; ++i)
    {
        if (sign)
        {
            l = max(l, -a);
            r = min(r, d[i] - a);
            a = d[i] - a;
            sign = 0;
        }
        else
        {
            l = max(l, a - d[i]);
            r = min(r, a);
            a = d[i] - a;
            sign = 1;
        }
    }

    if (sign == 0)
    {
        if (a <= l * 2 || a >= r * 2)
        {
            goto fail;
        }
    }
    else
    {
        if (a != 0)
        {
            goto fail;
        }
    }

    if (l >= r)
    {
        goto fail;
    }

    return n;

fail:
    int ans = n * 2;
    for (int i = 0; i < n; ++i)
    {
        vector<int> d2(n + 1);

        for (int j = 0; j <= n; ++j)
            d2[j] = d[(i + j) % n];
        ans = min(ans, n + 1 + ans_l(d2));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ct;

    cin >> ct;
    for (int t = 0; t < ct; ++t)
    {
        int k, n;
        cin >> k >> n;

        vector<int> x(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> x[i];
        }
        for (int i = 0; i < n; ++i)
        {
            int _;
            cin >> _;
        }

        vector<int> d(n);
        for (int i = 0; i < n; ++i)
        {
            if (i == n - 1)
            {
                d[i] = x[0] - x[i] + k;
            }
            else
            {
                d[i] = x[i + 1] - x[i];
            }
        }

        cout << "Case #" << (t + 1) << ": " << ans_c(d) << endl;
    }

    return 0;
}
