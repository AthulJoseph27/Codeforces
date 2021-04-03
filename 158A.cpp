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
    int n, k;

    cin >> n >> k;

    vi a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // sort(all(a));

    int q = a[k - 1];

    int cnt = 0;
    for (int i : a)
        if (i >= q && i > 0)
            cnt++;

    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}