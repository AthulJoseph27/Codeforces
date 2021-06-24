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

    long long maxPrice = 0;

    vector<pair<long long, long long>> pds(n);
    // vector<pair<long long, long long>> b(n);
    map<long long, vector<long long>> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> pds[i].first >> pds[i].second;
        // b[i].first = pds[i].first;
        // b[i].second = pds[i].second;
        maxPrice += (pds[i].first * 2);
    }

    sort(all(pds), [&](const pair<int, int> aa, const pair<int, int> bb)
         {
             if (aa.second == bb.second)
                 return aa.first > bb.first;
             return aa.second > bb.second;
         });

    // sort(all(b), [&](const pair<int, int> aa, const pair<int, int> bb)
    //      {
    //          if (aa.second == bb.second)
    //              return aa.first > bb.first;
    //          return aa.second < bb.second;
    //      });

    long long cost = 0;
    long long items = 0;

    int l = 0, r = n - 1;

    while (l <= r)
    {
        while (l <= r && pds[l].second <= items)
        {
            cost += pds[l].first;
            items += pds[l].first;
            pds[l].first = 0;
            l++;
        }

        if (l > r)
            break;

        if (pds[r].first + items >= pds[l].second)
        {
            assert((pds[l].second - items) >= 0);
            cost += (2 * (pds[l].second - items));
            pds[r].first -= (pds[l].second - items);
            items = pds[l].second;
        }
        else
        {
            cost += (2 * pds[r].first);
            items += pds[r].second;
            pds[r].first = 0;
            r--;
        }
    }

    cout << cost << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}