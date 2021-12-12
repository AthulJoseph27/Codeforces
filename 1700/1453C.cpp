#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pi;

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

int area(pi v1, pi v2, pi v3)
{
    // assumption : v1 and v2 are parallel

    if (v1.first == v2.first)
    {
        // same row
        int b = abs(v1.second - v2.second);
        int h = abs(v1.first - v3.first);
        return b * h;
    }

    int b = abs(v1.first - v2.first);
    int h = abs(v1.second - v3.second);
    return b * h;
}

void solve_case(vvi &a, vi &ans)
{
    int n = a.size();

    vector<pair<int, int>> fi(10, {-1, -1});

    for (int i = 0; i < n; i++)
    {
        vi seen1(10, -1);
        vi seen2(10, -1);

        for (int j = 0; j < n; j++)
        {
            int d = a[i][j];
            if (seen1[d] != -1)
            {
                seen2[d] = j;
                ans[d] = max({
                    ans[d],
                    area({i, seen1[d]}, {i, seen2[d]}, {0, 0}),
                    area({i, seen1[d]}, {i, seen2[d]}, {n - 1, 0}),
                    area({i, seen1[d]}, {i, seen2[d]}, {0, n - 1}),
                    area({i, seen1[d]}, {i, seen2[d]}, {n - 1, n - 1}),
                });
            }
            else
            {
                seen1[d] = j;
            }
            if (fi[d].first == -1)
            {
                fi[d] = {i, j};
                continue;
            }

            if ((fi[d].first == i) || (fi[d].second == j))
            {
                ans[d] = max({
                    ans[d],
                    area(fi[d], {i, j}, {0, 0}),
                    area(fi[d], {i, j}, {n - 1, 0}),
                    area(fi[d], {i, j}, {0, n - 1}),
                    area(fi[d], {i, j}, {n - 1, n - 1}),
                });
            }

            ans[d] = max({ans[d], area(fi[d], {fi[d].first, n - 1}, {i, j}),
                          area(fi[d],
                               {n - 1, fi[d].second}, {i, j}),
                          area(fi[d], {fi[d].first, 0}, {i, j}),
                          area(fi[d], {0, fi[d].second}, {i, j}),
                          area({i, j}, {i, n - 1}, fi[d]),
                          area({i, j}, {i, 0}, fi[d]),
                          area({i, j}, {n - 1, j}, fi[d]),
                          area({i, j}, {0, j}, fi[d])});
        }
    }

    for (int i = 0; i < 10; i++)
    {
        fi[i] = {-1, -1};
    }

    for (int i = n - 1; i >= 0; i--)
    {
        vi seen1(10, -1);
        vi seen2(10, -1);
        for (int j = n - 1; j >= 0; j--)
        {
            int d = a[i][j];

            if (seen1[d] != -1)
            {
                seen2[d] = j;
                ans[d] = max({
                    ans[d],
                    area({i, seen1[d]}, {i, seen2[d]}, {0, 0}),
                    area({i, seen1[d]}, {i, seen2[d]}, {n - 1, 0}),
                    area({i, seen1[d]}, {i, seen2[d]}, {0, n - 1}),
                    area({i, seen1[d]}, {i, seen2[d]}, {n - 1, n - 1}),
                });
            }
            else
            {
                seen1[d] = j;
            }

            if (fi[d].first == -1)
            {
                fi[d] = {i, j};
                continue;
            }

            if ((fi[d].first == i) || (fi[d].second == j))
            {
                ans[d] = max({
                    ans[d],
                    area(fi[d], {i, j}, {0, 0}),
                    area(fi[d], {i, j}, {n - 1, 0}),
                    area(fi[d], {i, j}, {0, n - 1}),
                    area(fi[d], {i, j}, {n - 1, n - 1}),
                });
            }

            ans[d] = max({ans[d], area(fi[d], {fi[d].first, n - 1}, {i, j}),
                          area(fi[d],
                               {n - 1, fi[d].second}, {i, j}),
                          area(fi[d], {fi[d].first, 0}, {i, j}),
                          area(fi[d], {0, fi[d].second}, {i, j}),
                          area({i, j}, {i, n - 1}, fi[d]),
                          area({i, j}, {i, 0}, fi[d]),
                          area({i, j}, {n - 1, j}, fi[d]),
                          area({i, j}, {0, j}, fi[d])});
        }
    }

    for (int i = 0; i < 10; i++)
    {
        fi[i] = {-1, -1};
    }

    for (int i = 0; i < n; i++)
    {
        vi seen1(10, -1);
        vi seen2(10, -1);
        for (int j = n - 1; j >= 0; j--)
        {
            int d = a[i][j];

            if (seen1[d] != -1)
            {
                seen2[d] = j;
                ans[d] = max({
                    ans[d],
                    area({i, seen1[d]}, {i, seen2[d]}, {0, 0}),
                    area({i, seen1[d]}, {i, seen2[d]}, {n - 1, 0}),
                    area({i, seen1[d]}, {i, seen2[d]}, {0, n - 1}),
                    area({i, seen1[d]}, {i, seen2[d]}, {n - 1, n - 1}),
                });
            }
            else
            {
                seen1[d] = j;
            }

            if (fi[d].first == -1)
            {
                fi[d] = {i, j};
                continue;
            }

            if ((fi[d].first == i) || (fi[d].second == j))
            {
                ans[d] = max({
                    ans[d],
                    area(fi[d], {i, j}, {0, 0}),
                    area(fi[d], {i, j}, {n - 1, 0}),
                    area(fi[d], {i, j}, {0, n - 1}),
                    area(fi[d], {i, j}, {n - 1, n - 1}),
                });
            }

            ans[d] = max({ans[d], area(fi[d], {fi[d].first, n - 1}, {i, j}),
                          area(fi[d],
                               {n - 1, fi[d].second}, {i, j}),
                          area(fi[d], {fi[d].first, 0}, {i, j}),
                          area(fi[d], {0, fi[d].second}, {i, j}),
                          area({i, j}, {i, n - 1}, fi[d]),
                          area({i, j}, {i, 0}, fi[d]),
                          area({i, j}, {n - 1, j}, fi[d]),
                          area({i, j}, {0, j}, fi[d])});
        }
    }

    for (int i = 0; i < 10; i++)
    {
        fi[i] = {-1, -1};
    }

    for (int i = n - 1; i >= 0; i--)
    {
        vi seen1(10, -1);
        vi seen2(10, -1);
        for (int j = 0; j < n; j++)
        {
            int d = a[i][j];

            if (seen1[d] != -1)
            {
                seen2[d] = j;
                ans[d] = max({
                    ans[d],
                    area({i, seen1[d]}, {i, seen2[d]}, {0, 0}),
                    area({i, seen1[d]}, {i, seen2[d]}, {n - 1, 0}),
                    area({i, seen1[d]}, {i, seen2[d]}, {0, n - 1}),
                    area({i, seen1[d]}, {i, seen2[d]}, {n - 1, n - 1}),
                });
            }
            else
            {
                seen1[d] = j;
            }

            if (fi[d].first == -1)
            {
                fi[d] = {i, j};
                continue;
            }

            if ((fi[d].first == i) || (fi[d].second == j))
            {
                ans[d] = max({
                    ans[d],
                    area(fi[d], {i, j}, {0, 0}),
                    area(fi[d], {i, j}, {n - 1, 0}),
                    area(fi[d], {i, j}, {0, n - 1}),
                    area(fi[d], {i, j}, {n - 1, n - 1}),
                });
            }

            ans[d] = max({ans[d],
                          area(fi[d], {fi[d].first, n - 1}, {i, j}),
                          area(fi[d], {n - 1, fi[d].second}, {i, j}),
                          area(fi[d], {fi[d].first, 0}, {i, j}),
                          area(fi[d], {0, fi[d].second}, {i, j}),
                          area({i, j}, {i, n - 1}, fi[d]),
                          area({i, j}, {i, 0}, fi[d]),
                          area({i, j}, {n - 1, j}, fi[d]),
                          area({i, j}, {0, j}, fi[d])});
        }
    }
}

void solve(int cc)
{
    int n;
    cin >> n;

    vvi a(n, vi(n));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = (int)(s[j] - '0');
        }
    }

    vi ans(10, 0);
    solve_case(a, ans);

    vvi trans(n, vi(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            trans[i][j] = a[j][i];
        }
    }
    solve_case(trans, ans);

    for (int i : ans)
    {
        cout << i << ' ';
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