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

void color_main_dig(int *count_mainr, int *ir, int n, int *delta_mainr, bool *top_mainr, vector<vector<int>> &a)
{
    int count_main = *count_mainr;
    int i = *ir;
    int delta_main = *delta_mainr;
    bool top_main = *top_mainr;

    count_main--;

    if ((i + delta_main) >= n)
    {
        // debug(count_main, i, delta_main, n);
        i = 0;
        delta_main += 2;
        if (delta_main >= n)
        {
            delta_main = 2;
            top_main = true;
        }
    }

    if (top_main)
    {
        a[i][i + delta_main] = 1;
        cout << 1 << " " << i + 1 << " " << i + delta_main + 1 << endl;
    }
    else
    {
        a[i + delta_main][i] = 1;
        cout << 1 << " " << i + delta_main + 1 << " " << i + 1 << endl;
    }
    i++;

    *count_mainr = count_main;
    *ir = i;
    *delta_mainr = delta_main;
    *top_mainr = top_main;
}

void color_beta(int *count_minr, int *jr, int n, int *deltar, bool *topr, vector<vector<int>> &a)
{
    int count_min = *count_minr;
    int j = *jr;
    int delta = *deltar;
    bool top = *topr;

    count_min--;
    if ((j + delta) >= n)
    {
        j = 0;
        delta += 2;
        if (delta >= n)
        {
            delta = 1;
            top = true;
        }
    }
    if (top)
    {
        a[j][j + delta] = 2;
        cout << 2 << " " << j + 1 << " " << j + delta + 1 << endl;
    }
    else
    {
        a[j + delta][j] = 2;
        cout << 2 << " " << j + delta + 1 << " " << j + 1 << endl;
    }

    j++;

    *count_minr = count_min;
    *jr = j;
    *topr = top;
    *deltar = delta;
}

set<int> get_neighbour_colors(vector<vector<int>> &a, int y, int x)
{

    set<int> colors;

    if ((y - 1) >= 0)
    {
        colors.insert(a[y - 1][x]);
    }

    if ((y + 1) < a.size())
    {
        colors.insert(a[y + 1][x]);
    }

    if ((x - 1) >= 0)
    {
        colors.insert(a[y][x - 1]);
    }

    if ((x + 1) < a.size())
    {
        colors.insert(a[y][x + 1]);
    }

    return colors;
}

void solve(int cc)
{
    int n;
    cin >> n;

    // debug(n);

    vector<vector<int>> a(n, vector<int>(n, 0));

    int count_main = 0, count_min = 0;

    if (n % 2 == 0)
    {
        count_main = n * n / 2;
        count_min = count_main;
    }
    else
    {
        count_main = n * n / 2 + 1;
        count_min = n * n / 2;
    }

    int limit = n * n;

    int i = 0, j = 0, delta = 1, delta_main = 0;

    bool top = false, top_main = false;

    for (int _ = 0; _ < limit; _++)
    {
        int color;
        cin >> color;

        // fill diagonally

        if (color != 1)
        {
            if (count_main > 0)
            {
                // debug(i, n);
                color_main_dig(&count_main, &i, n, &delta_main, &top_main, a);
                // debug(i);
            }
            else
            {
                // color is not 1 and main dig is left
                // check and use color here

                count_min--;
                if ((j + delta) >= n)
                {
                    j = 0;
                    delta += 2;
                    if (delta >= n)
                    {
                        delta = 1;
                        top = true;
                    }
                }

                int x, y;

                if (top)
                {
                    y = j;
                    x = j + delta;
                }
                else
                {
                    y = j + delta;
                    x = j;
                }

                j++;

                set<int> neighbour_colors = get_neighbour_colors(a, y, x);

                set<int> usable = {1, 2, 3};

                usable.erase(color);

                bool filled = false;

                for (auto cl : usable)
                {
                    if (neighbour_colors.find(cl) == neighbour_colors.end())
                    {
                        filled = true;
                        a[y][x] = cl;
                        cout << cl << " " << y + 1 << " " << x + 1 << endl;
                    }
                }

                assert(filled);
            }
        }
        else
        {
            if (count_min > 0)
                color_beta(&count_min, &j, n, &delta, &top, a);
            else
            {
                count_main--;

                // debug(i, delta_main);

                if ((i + delta_main) >= n)
                {
                    i = 0;
                    delta_main += 2;
                    if (delta_main >= n)
                    {
                        delta_main = 2;
                        top_main = true;
                    }
                }

                int x, y;

                // debug(y, x, delta_main);
                // debug(a);

                if (top_main)
                {
                    y = i;
                    x = i + delta_main;
                }
                else
                {
                    y = i + delta_main;
                    x = i;
                }

                i++;

                // color is 1

                set<int> neighbour_colors = get_neighbour_colors(a, y, x);

                set<int> usable = {2, 3};

                bool filled = false;

                for (auto cl : usable)
                {
                    if (neighbour_colors.find(cl) == neighbour_colors.end())
                    {
                        filled = true;
                        a[y][x] = cl;
                        cout << cl << " " << y + 1 << " " << x + 1 << endl;
                    }
                }

                assert(filled);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}