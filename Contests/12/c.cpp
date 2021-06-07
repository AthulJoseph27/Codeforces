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

    string s;
    cin >> s;

    int d = 0;
    int k = 0;

    string tmp = "";

    vector<int> ans(n + 1, 1);

    vector<pair<int, int>> prefs = {{0, 0}};

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'D')
        {
            prefs.emplace_back(prefs.back().first + 1, prefs.back().second);
        }
        else
        {
            prefs.emplace_back(prefs.back().first, prefs.back().second + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'D')
        {
            tmp += 'D';
        }
        else
        {
            tmp += 'K';
        }
        int tmp_size = tmp.size();
        int itr = 2;

        pair<int, int> cur_count = prefs[i + 1];

        int len = cur_count.first + cur_count.second;

        for (int j = i + 1; (j + len) <= n; j += len)
        {
            pair<int, int> itr_count = {prefs[j + len].first - prefs[j].first, prefs[j + len].second - prefs[j].second};

            long long ad = ((long long)itr_count.first) * ((long long)cur_count.second);
            long long bc = ((long long)itr_count.second) * ((long long)cur_count.first);
            if (ad == bc)
            {
                ans[j + len] = max(itr, ans[j + len]);
            }
            else
            {
                bool flag = true;
                for (int ki = len + 1; (j + ki) <= n; ki++)
                {
                    // debug(tmp, s.substr(j, ki));

                    itr_count = {prefs[j + ki].first - prefs[j].first, prefs[j + ki].second - prefs[j].second};
                    ad = ((long long)itr_count.first) * ((long long)cur_count.second);
                    bc = ((long long)itr_count.second) * ((long long)cur_count.first);
                    if (ad == bc)
                    {
                        ans[j + ki] = max(itr, ans[j + ki]);
                        // debug(ans[j + ])
                        // j = j - len + ki;
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            itr++;
        }
    }
    // else
    // {
    //     tmp += 'K';
    //     int tmp_size = tmp.size();
    //     int itr = 2;

    //     // if (ans[i] != 1)
    //     //     continue;
    //     pair<int, int> cur_count = prefs[i + 1];

    //     for (int j = i + 1; (j + tmp_size) <= n; j += tmp_size)
    //     {
    //         pair<int, int> itr_count = {prefs[j + tmp_size].first - prefs[j].first, prefs[j + tmp_size].second - prefs[j].second};
    //         long long ad = ((long long)itr_count.first) * ((long long)cur_count.second);
    //         long long bc = ((long long)itr_count.second) * ((long long)cur_count.first);
    //         if (ad == bc)
    //         {
    //             ans[tmp_size * itr] = max(itr, ans[tmp_size * itr]);
    //         }
    //         else
    //         {
    //             break;
    //         }
    //         itr++;
    //     }
    // }
    // }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
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