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

    vi a(n);

    for (int &i : a)
        cin >> i;

    set<int> st;

    for (int i : a)
    {
        if (i <= n)
            st.insert(i);
    }

    vector<int> b(n + 1, 0);

    vector<int> c;

    map<int, int> mp;

    for (int i : a)
        mp[i]++;

    map<int, int> seen;

    for (int i : a)
    {
        if (i <= n)
        {
            if (seen[i] > 0)
                continue;
            seen[i]++;
            for (int j = 1; j < mp[i]; j++)
                c.push_back(i);
        }
        else
        {
            c.push_back(i);
        }
    }

    for (int i : c)
    {
        if (i == 1)
            continue;
        int max_reminder = i % ((i / 2) + 1);
        max_reminder = min(n, max_reminder);
        b[max_reminder]++;
    }

    for (int i = n - 1; i > 0; i--)
    {
        b[i] += b[i + 1];
    }

    int taken = 0;

    for (int i = n; i >= 1; i--)
    {
        if (st.find(i) == st.end())
        {
            if ((b[i] - taken) <= 0)
            {
                cout << -1 << '\n';
                return;
            }
            else
            {
                taken++;
            }
        }
    }

    cout << n - st.size() << '\n';
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