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
    ll n, k;
    cin >> n >> k;

    if (n % 2 != 0)
    {
        if (k <= (n / 2 + 1))
        {
            cout << 1 + (k - 1) * 2 << endl;
        }
        else
        {
            k -= n / 2;
            k--;
            cout << 2 + (k - 1) * 2 << endl;
        }
    }
    else
    {
        if (k <= (n / 2))
        {
            cout << 1 + (k - 1) * 2 << endl;
        }
        else
        {
            k -= n / 2;
            cout << 2 + (k - 1) * 2 << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}