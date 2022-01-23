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
#define rall(v) v.rbegin(), v.rend()

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
    int k;
    cin >> k;

    string s;
    cin >> s;

    // 1,4,6,8,9 -> delete all but these

    // 5,2 -> leave 1 digit behind this and delete rest
    // 27 -> ok leave it as such

    // 3,7
    // 33 or 77

    set<char> st;

    for (char c : s)
        st.insert(c);

    vector<char> t1 = {'1', '4', '6', '8', '9'};

    for (char c : t1)
    {
        if (st.find(c) != st.end())
        {
            cout << 1 << '\n'
                 << c << '\n';
            return;
        }
    }

    int index = 0;
    bool flag = false;

    while (index < k)
    {
        if (index != 0 && (s[index] == '2' || s[index] == '5'))
        {
            flag = true;
            break;
        }
        index++;
    }

    if (flag)
    {
        cout << 2 << '\n'
             << s[index - 1] << s[index] << '\n';
        return;
    }

    index = 0;

    while (index < k)
    {
        if (s[index] == '2')
        {
            break;
        }
        index++;
    }

    if (index != k)
    {
        int tmp = index;
        while (index < k)
        {
            if (s[index] == '7')
            {
                cout << 2 << '\n'
                     << 27 << '\n';
                return;
            }
            index++;
        }
    }

    index = 0;

    while (index < k)
    {
        if (s[index] == '5')
        {
            while (index < k)
            {
                if (s[index] == '7')
                {
                    cout << 2 << '\n'
                         << 57 << '\n';
                    return;
                }
                index++;
            }
            break;
        }
        index++;
    }

    int c3 = 0, c7 = 0;

    for (char c : s)
    {
        if (c == '3')
            c3++;
        else if (c == '7')
            c7++;
    }

    if (c3 > 1)
    {
        cout << 2 << '\n'
             << 33 << '\n';
        return;
    }

    cout << 2 << '\n'
         << 77 << '\n';
    return;
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