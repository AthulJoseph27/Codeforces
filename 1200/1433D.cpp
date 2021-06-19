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

    /*
        1 1 1 2

        if all are same , then its not possible
    */

    vector<int> a(n);

    set<int> st;

    for (int &i : a)
    {
        cin >> i;
        st.insert(i);
    }

    if (st.size() == 1)
    {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';

    int index = 0;

    map<int, int> mp;
    vector<bool> b(n, false);

    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[index])
        {
            b[i] = true;
            b[index] = true;
            mp[a[i]] = index;
            mp[a[index]] = i;
            cout << (index + 1) << ' ' << (i + 1) << '\n';
            index = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!b[i])
        {
            assert(mp.find(a[i]) != mp.end());
            cout << (i + 1) << ' ' << (mp[a[i]] + 1) << '\n';
        }
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