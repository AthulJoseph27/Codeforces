#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define push push_back
#define all(v) v.begin(), v.end()

void solve()
{
    int n;

    cin >> n;

    vi a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxSub = -1e9;
    int sub = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            sub++;
        }
        else
        {
            maxSub = max(sub, maxSub);
            sub = 1;
        }
    }
    maxSub = max(sub, maxSub);
    cout << maxSub;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}