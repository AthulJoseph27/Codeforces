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
        a.first > i.first and a.second > i.first
                    OR
        a.first > i.second and a.second > i.first

        so order within a pair doesnt matter...so sort them

        (a,b) ; a<=b

    */

    map<pair<int, int>, int> mp;

    vector<pair<int, int>> a;

    vector<pair<int, int>> b;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);

        a.emplace_back(x, y);
        b.emplace_back(x, y);
    }

    sort(all(b), [&](const pair<int, int> aa, const pair<int, int> bb)
         {
             if (aa.first == bb.first)
                 return aa.second < bb.second;

             return aa.first < bb.first;
         });

    map<int, int> tmp;

    for (auto p : b)
    {
        if (tmp.find(p.first) != tmp.end())
            tmp[p.first] = min(tmp[p.first], p.second);
        else
            tmp[p.first] = p.second;
    }

    b.assign(all(tmp));

    vector<pair<int, int>> prefs = {{INT_MAX, -1}};

    for (int i = 0; i < b.size(); i++)
    {
        if (b[i].second < prefs.back().first)
            prefs.push_back({b[i].second, i});
        else
            prefs.push_back(prefs.back());
    }

    for (int i = 0; i < n; i++)
    {
        mp[a[i]] = i;
    }

    auto bnS = [&](pair<int, int> &p)
    {
        int l = 0, r = b.size() - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (b[mid].first == p.first)
            {
                return mid;
            }
            if (b[mid].first > p.first)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (b[r].first <= p.first)
            return r;

        return l;
    };

    for (auto p : a)
    {
        int r = bnS(p);
        pair<int, int> sr = prefs[r];

        if (sr.second == -1)
        {
            cout << -1 << ' ';
            continue;
        }

        sr = b[sr.second];

        if (sr.first < p.first && sr.second < p.second)
        {
            cout << (mp[sr] + 1) << ' ';
        }
        else
        {
            cout << "-1 ";
        }
    }

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