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
    string s;

    cin >> s;

    long long count = s.size();

    int sublen = 1;

    int n = s.size();

    char ch = s[0];

    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            index = i;
        }
        else
        {
            break;
        }
    }

    if ((index + 1) == n)
    {
        count = count + ((long long)n * (long long)(n - 1)) / 2L;
        cout << count << '\n';
        return;
    }

    string str = "";

    if (index == -1)
    {
        str += s[0];
        index = 0;
    }
    else
    {
        for (int i = 0; i <= index; i++)
        {
            str += s[i];
        }
        str += s[index + 1];
        index += 1;
    }

    for (int i = index + 1; i < n; i++)
    {
        if (s[i] == '?')
        {
            if (str.back() == '0')
                str += '1';
            else
                str += '0';
        }
        else if (s[i] == str.back())
        {

            // debug(str);
            count = count + ((long long)str.size() * (long long)(str.size() - 1)) / 2L;

            str = "";
            str += s[i];

            int tc = 0;

            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] == '?')
                {
                    str = '?' + str;
                    tc++;
                }
                else
                {
                    break;
                }
            }

            count = count - ((long long)tc * (long long)(tc - 1)) / 2L;
        }
        else
        {
            str += s[i];
        }
    }

    count = count + ((long long)str.size() * (long long)(str.size() - 1)) / 2L;

    cout << count << '\n';
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