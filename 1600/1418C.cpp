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
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n), c(m);

    for (int &i : a)
        cin >> i;

    for (int &i : b)
        cin >> i;

    for (int &i : c)
        cin >> i;

    map<int, int> mp;

    for (int i : b)
        mp[i]--;

    for (int i : a)
        mp[i]++;

    for (int i : c)
        mp[i]++;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second < 0)
        {
            cout << "NO\n";
            return;
        }
    }

    vector<int> ans(m, -1);

    map<int, set<pair<int, int>>> fence; // map<final color,set<{indice,initial color}>>
    map<int, set<int>> colored_fence;    // map<final color, set<{indice}>>;

    for (int i = 0; i < n; i++)
    {
        if (b[i] == a[i])
            colored_fence[b[i]].insert(i);
        else
            fence[b[i]].insert({i, a[i]});
    }

    for (int i = 0; i < m; i++)
    {
        if (fence[c[i]].size() == 0)
        {
            // color is not needed

            if (colored_fence[c[i]].size() > 0)
            {
                // have a fence with the same color, so repaint tht fence
                ans[i] = *colored_fence[c[i]].begin();
            }
            else
            {
                // doest not have any fence of this color
                bool fixed = false;
                int j = i + 1;
                while (j < m)
                {
                    if (fence[c[j]].size() > 0)
                    {
                        auto ptr = fence[c[j]].begin();
                        a[ptr->first] = c[j];
                        colored_fence[c[j]].insert(ptr->first);
                        fixed = true;

                        for (int ii = i; ii <= j; ii++)
                        {
                            ans[ii] = ptr->first;
                        }

                        fence[c[j]].erase(ptr);

                        break;
                    }
                    else
                    {
                        if (colored_fence[c[j]].size() > 0)
                        {
                            for (int ii = i; ii <= j; ii++)
                            {
                                ans[ii] = *colored_fence[c[j]].begin();
                            }

                            fixed = true;
                            break;
                        }
                    }
                    j++;
                }

                i = j;
                if (!fixed)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
        else
        {
            auto ptr = fence[c[i]].begin();
            a[ptr->first] = c[i];
            colored_fence[c[i]].insert(ptr->first);
            ans[i] = ptr->first;
            fence[c[i]].erase(ptr);
        }
    }

    for (int i : ans)
        if (i == -1)
        {
            cout << "NO\n";
            return;
        }

    for (int i = 0; i < m; i++)
    {
        a[ans[i]] = c[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    for (int i : ans)
        cout << (i + 1) << ' ';

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