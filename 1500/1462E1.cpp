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

    for (int &i : a)
        cin >> i;

    sort(all(a));

    long long count = 0;

    map<int, int> mp;
    set<int> st;

    for (int i : a)
    {
        mp[i]++;
        st.insert(i);
    }

    for (int cur : st)
    {
        long long x = mp[cur];
        long long x1 = mp[cur + 1];
        long long x2 = mp[cur + 2];

        count += (x * (x1 * (x1 - 1)) / 2); // x * x1C2
        count += (x * x1 * x2);
        count += (x * (x2 * (x2 - 1)) / 2);           // x * x2C2
        count += (x1 * (x * (x - 1)) / 2);            // x1 * xC2
        count += (x2 * (x * (x - 1)) / 2);            // x2 * xC2
        count += ((x * (x - 1) * (x - 2)) / (2 * 3)); // xC3
    }

    /*
        [x,x+1,x+1]
        [x,x+1,x+2]
        [x,x+2,x+2]
        [x,x,x+1]
        [x,x,x+2]
        [x,x,x]
    */

    cout << count << '\n';
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