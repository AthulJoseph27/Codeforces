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

void solve(int cc)
{
    int n, a, b;
    cin >> n >> a >> b;

    vi c;

    set<int> st;

    for (int i = 1; i <= n; i++)
    {
        if (i == a || i == b)
            continue;
        st.insert(i);
    }

    c.push_back(a);

    for (int i = 1; i < (n / 2); i++)
    {
        c.push_back(*st.rbegin());
        st.erase(--st.end());
    }

    c.push_back(b);
    for (int i = 1; i < (n / 2); i++)
    {
        c.push_back(*st.begin());
        st.erase(st.begin());
    }

    vi tmp = c;

    sort(all(tmp));

    // debug(tmp);

    for (int i = 1; i <= n; i++)
    {
        if (tmp[i - 1] != i)
        {
            cout << "-1\n";
            return;
        }
    }

    if ((*min_element(c.begin(), c.begin() + n / 2) != a) || (*max_element(c.begin() + n / 2, c.end()) != b))
    {
        cout << "-1\n";
        return;
    }

    for (int i : c)
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