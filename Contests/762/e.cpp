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

    sort(all(a));

    map<int, int> mp;

    for (int i : a)
        mp[i]++;

    int mex = 0;

    for (int i : a)
    {
        if (i == mex)
        {
            mex++;
        }
    }

    vl res(n + 1, 0);

    ll cost = 0;

    set<int> exts;
    map<int, int> exts_cnt;

    for (int i = 0; i <= n; i++)
    {
        if (i < mex)
        {
            ll cnt = mp[i];
            res[i] = mp[i];
            if (cnt > 1)
            {
                exts.insert(i);
                exts_cnt[i] = cnt - 1LL;
            }
        }
        else if (i == mex)
        {
            res[i] = 0;
            if (exts.size() == 0)
            {
                cost = -1;
            }
            else
            {
                ll last = *exts.rbegin();
                ll cnt = exts_cnt[last];

                cost = (mex - last);

                cnt--;
                exts_cnt[last] = cnt;

                if (cnt == 0)
                {
                    exts.erase(--exts.end());
                }
            }
        }
        else
        {
            if (mp[i] == 0)
            {
                // no occurrance
                // debug(cost);
                res[i] = cost;
                if (exts.size() == 0)
                {
                    cost = -1;
                }
                else if (cost != -1)
                {
                    ll last = *exts.rbegin();
                    ll cnt = exts_cnt[last];
                    // cout << endl;
                    // debug(i);
                    // debug(last);
                    // debug(cnt);
                    cost += (i - last);
                    cnt--;
                    exts_cnt[last] = cnt;
                    if (cnt == 0)
                    {
                        exts.erase(--exts.end());
                    }
                }
            }
            else
            {
                // debug(i);
                if (cost == -1)
                {
                    res[i] = cost;
                }
                else
                {
                    ll cnt = mp[i];
                    res[i] = cost + cnt;

                    if (cnt > 1)
                    {
                        exts.insert(i);
                        exts_cnt[i] = cnt - 1;
                    }
                }
                // debug(res[i]);
            }
        }
    }

    for (ll i : res)
        cout << i << " ";
    cout << '\n';
}
/*
    4
    4 0 0 0
    0 1 2 
*/
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