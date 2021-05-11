#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define push push_back
#define ALL(v) v.begin(), v.end()

bool solve(int c)
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) > 1)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    int count = 0;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        if (solve(i + 1))
            count++;
    }

    cout << count << endl;

    return 0;
}