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

    vector<int> a(k);

    for (int &i : a)
        cin >> i;

    int ans = k;

    // debug(a);

    map<int, int> mp;

    for (int i : a)
    {
        if (i == 0)
        {
            ans--;
            continue;
        }
        mp[i]++;
    }

    // debug(mp);

    set<pair<int, int>> st;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        st.insert({it->first, it->second});
    }

    int ct = 0;
    int saved = 0;

    while (st.size() > 0)
    {
        pair<int, int> lst = *st.rbegin();
        auto ptr = st.end();
        ptr--;
        st.erase(ptr);
        int time = n - lst.first;
        lst.second--;
        saved++;
        ct += time;
        if (lst.second > 0)
        {
            st.insert(lst);
        }

        while (st.size() > 0 && (*st.begin()).first <= ct)
        {
            st.erase(st.begin());
        }
    }

    cout << saved << '\n';
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