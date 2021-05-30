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

    vector<vector<int>> ans(n);

    map<string, int> mp;

    ans[0].push_back(1);

    cout << "1" << '\n';

    mp["1"]++;

    for (int i = 1; i < n; i++)
    {
        if (a[i] == 1)
        {
            for (int j = 0; j < ans[i - 1].size(); j++)
            {
                ans[i].push_back(ans[i - 1][j]);
            }

            ans[i].push_back(1);
        }
        else
        {
            bool flag = false;

            for (int j = ans[i - 1].size() - 1; j >= 0; j--)
            {
                if (ans[i - 1][j] + 1 == a[i])
                {
                    string stmp = to_string(ans[i - 1][0]);
                    for (int k = 1; k < j; k++)
                    {
                        stmp += ("." + to_string(ans[i - 1][k]));
                    }
                    stmp += ("." + to_string(a[i]));

                    if (mp[stmp] > 0)
                    {
                        continue;
                    }
                    mp[stmp]++;
                    flag = true;
                    for (int k = 0; k < j; k++)
                    {
                        ans[i].push_back(ans[i - 1][k]);
                    }
                    ans[i].push_back(a[i]);
                    // debug(stmp);
                    break;
                }
            }

            if (!flag)
            {
                ans[i].push_back(a[i]);
                mp[to_string(a[i])]++;
            }
        }
        string stmp = to_string(ans[i][0]);
        for (int k = 1; k < ans[i].size(); k++)
        {
            stmp += ("." + to_string(ans[i][k]));
        }
        mp[stmp]++;
        cout << stmp << '\n';
    }

    // debug(mp);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << ans[i][0];
    //     for (int j = 1; j < ans[i].size(); j++)
    //     {
    //         cout << '.' << ans[i][j];
    //     }
    //     cout << '\n';
    // }
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