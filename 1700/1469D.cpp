#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define all(v) v.begin(), v.end()

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void solve(int cc)
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    /*
        n-1 ones and 1 two, in no more than n+5 steps
        [1,2,3]
        [1,2,2]
        [1,2,2]

        [1,2,3,4,5]
        [1,2,3,4,3]
        [1,2,3,2,3]
        [1,2,1,2,3]
        [1,2,1,1,3]
        [1,2,1,1,2]
        [1,2,1,1,1]

        [1,2,3,4,5,6,7,8,9,10]
        [1,2,3,1,5,1,1,1,1,10]
        [1,2,3,1,5,1,1,1,1,2]
        [1,2,3,1,5,1,1,1,1,1]
        [1,2,3,1,2,1,1,1,1,1]
        [1,2,2,1,1,1,1,1,1,1]->2
        [1,2,1,1,1,1,1,1,1,1] -> total 11 operations

        using n-4 moves reduce all elements to 1 except 2 and 64

        use 64 to reduce the last element to 1 using 3 moves

        moves left = n+5 - (n-4)- 3 = 6
        using 6 moves reduce 64 to 1

        total moves used = n-4 + 3 + 6 = n+5

    */

    int mid = min(64, a[n / 2]);
    int index = n / 2;
    if (mid == 64)
        index = 63;

    vector<pair<int, int>> ans;

    for (int i = 2; i < (n - 1); i++)
    {
        if (a[i] == mid)
            continue;
        a[i] = ceil((float)a[i] / (float)a[n - 1]);
        ans.emplace_back((i + 1), n);
    }

    while (a[n - 1] > 1)
    {
        a[n - 1] = ceil((float)a[n - 1] / (float)a[index]);
        ans.emplace_back(n, index + 1);
    }

    if (index != 1)
    {
        while (a[index] > 1)
        {
            a[index] = ceil((float)a[index] / 2.0);
            ans.emplace_back(index + 1, 2);
        }
    }

    assert(ans.size() <= (n + 5));

    cout << ans.size() << '\n';

    for (auto p : ans)
    {
        cout << p.first << " " << p.second << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}