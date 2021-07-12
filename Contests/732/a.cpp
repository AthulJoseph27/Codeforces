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
    vector<int> b(n);

    int sm_a = 0, sm_b = 0;

    for (int &i : a)
    {
        cin >> i;
        sm_a += i;
    }

    for (int &i : b)
    {
        cin >> i;
        sm_b += i;
    }

    if (sm_a != sm_b)
    {
        cout << "-1\n";
        return;
    }

    bool allSame = true;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            allSame = false;
            break;
        }
    }

    if (allSame)
    {
        cout << "0\n";
        return;
    }

    int size = 0;

    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            continue;

        if (a[i] > b[i])
        {
            int delta = a[i] - b[i];
            for (int j = i + 1; delta > 0 && j < n; j++)
            {
                if (a[j] < b[j])
                {
                    int dl2 = min(b[j] - a[j], delta);
                    delta -= dl2;
                    a[j] += dl2;
                    size += dl2;
                    res.push_back({i + 1, j + 1, dl2});
                }
            }
            if (delta == 0)
                a[i] = b[i];
            else
            {
                cout << "-1\n";
                return;
            }
        }
        else
        {
            int delta = b[i] - a[i];
            for (int j = i + 1; delta > 0 && j < n; j++)
            {
                if (a[j] > b[j])
                {
                    int dl2 = min(a[j] - b[j], delta);
                    delta -= dl2;
                    a[j] -= dl2;
                    size += dl2;
                    res.push_back({j + 1, i + 1, dl2});
                }
            }
            if (delta == 0)
                a[i] = b[i];
            else
            {
                cout << "-1\n";
                return;
            }
        }
    }

    cout << size << '\n';

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i][2]; j++)
        {
            cout << res[i][0] << " " << res[i][1] << '\n';
        }
    }
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