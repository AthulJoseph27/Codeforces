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
    int n, k;
    cin >> n >> k;

    vector<int> pos(k);
    vector<int> temp(k);

    for (int &i : pos)
        cin >> i;

    for (int &i : temp)
        cin >> i;

    map<int, int> mp;
    for (int i = 0; i < k; i++)
        mp[pos[i] - 1] = temp[i];

    int index = 0;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pos[index] = it->first;
        temp[index] = it->second;
        index++;
    }

    vector<int> a(n, INT_MAX);

    for (int i = 0; i < k; i++)
        a[pos[i]] = temp[i];

    // vector<int> left(n, INT_MAX);

    // vector<int> right(n, INT_MAX);

    int min_temp = INT_MAX;

    vector<int> left(n, INT_MAX);
    vector<int> right(n, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        if (min_temp == INT_MAX)
            min_temp = a[i];
        else
            min_temp = min(a[i], min_temp + 1);

        left[i] = min_temp;
    }

    min_temp = min(INT_MAX, a[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (min_temp == INT_MAX)
            min_temp = a[i];
        else
            min_temp = min(a[i], min_temp + 1);
        right[i] = min_temp;
    }

    for (int i = 0; i < n; i++)
        cout << min(left[i], right[i]) << " ";
    cout << '\n';
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