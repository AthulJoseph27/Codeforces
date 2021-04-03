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
    string s;
    cin >> s;

    int count = 1;
    for (int i = 1; i < s.size(); i++)
    {
        // cout << s[i] << " " << s[i - 1] << " " << count << endl;
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            if (count >= 7)
            {
                cout << "YES" << endl;
                return;
            }
            count = 1;
        }
    }
    // cout << count << endl;
    if (count >= 7)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}