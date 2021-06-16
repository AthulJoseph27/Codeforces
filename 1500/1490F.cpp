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
    map<int, int> mp;

    for (int &i : a)
    {
        cin >> i;
        mp[i]++;
    }

    if (mp[a[0]] == n)
    {
        cout << 0 << '\n';
        return;
    }

    map<int, int> freq_freq;

    int ans = n;

    for (int i : a)
    {
        ans = min(ans, (n - mp[i]));
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
        freq_freq[it->second]++;

    // int prefs = 0;

    vector<pair<int, int>> fv;
    for (auto it = freq_freq.begin(); it != freq_freq.end(); it++)
    {
        fv.emplace_back(it->first, it->second);
    }

    sort(all(fv), [&](const pair<int, int> aa, const pair<int, int> bb)
         { return aa.first < bb.first; });

    int sz = fv.size();

    vector<int> _prefs = {0};

    for (int i = 0; i < sz; i++)
        _prefs.push_back(_prefs.back() + fv[i].second);

    for (int i = 0; i < sz; i++)
    {
        // if we plan to keep the current frequency
        // get rid of all numbers with freq less than this freq

        // if fv[i].first is the choosen frequencey
        // then no of elements in the array will be fv[i].first * (sum of fv[i].first * fv[x].second for x in range i+1 to sz)

        ans = min(ans, n - (fv[i].first * (_prefs[sz] - _prefs[i])));
    }

    cout << ans << '\n';
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