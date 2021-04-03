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
    vi coins(n);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        sum += coins[i];
    }

    sum = sum / 2.0;
    sort(all(coins));

    double sum2 = 0;
    int count = 0;
    for (int i = coins.size() - 1; i >= 0; i--)
    {
        sum2 += coins[i];
        count++;
        if (sum2 > sum)
        {
            cout << count;
            return;
        }
    }
    cout << count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}