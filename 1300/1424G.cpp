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

    map<int, long long> birth_count;
    map<int, long long> death_count;

    for (int i = 0; i < n; i++)
    {
        int b, d;
        cin >> b >> d;
        birth_count[b]++;
        death_count[d]++;
    }

    vector<pair<int, long long>> timeline;

    for (auto it = birth_count.begin(); it != birth_count.end(); it++)
    {
        timeline.emplace_back(it->first, it->second - death_count[it->first]);
        death_count[it->first] = 0;
    }

    for (auto it = death_count.begin(); it != death_count.end(); it++)
    {
        if (it->second == 0)
            continue;
        timeline.emplace_back(it->first, -death_count[it->first]);
    }

    sort(all(timeline), [&](const pair<int, long long> aa, const pair<int, long long> bb)
         { return aa.first < bb.first; });

    int mxyr = timeline[0].first;
    long long mxcnt = timeline[0].second;
    long long cnt = timeline[0].second;

    for (int i = 1; i < timeline.size(); i++)
    {
        cnt += timeline[i].second;
        if (cnt > mxcnt)
        {
            mxcnt = cnt;
            mxyr = timeline[i].first;
        }
    }

    cout << mxyr << " " << mxcnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}