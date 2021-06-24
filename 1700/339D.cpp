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

class SegTree
{

public:
    int leftmost, rightmost;
    int val;
    int type;
    SegTree *lChild, *rChild;

    SegTree(int leftmost, int rightmost, int type, vector<int> &a)
    {
        this->leftmost = leftmost;
        this->rightmost = rightmost;

        if (leftmost == rightmost)
        {
            val = a[leftmost];
            this->type = type;
            lChild = NULL;
            rChild = NULL;
        }
        else
        {
            int mid = (leftmost + rightmost) / 2;

            lChild = new SegTree(leftmost, mid, type, a);
            rChild = new SegTree(mid + 1, rightmost, type, a);

            if (lChild->type == 0)
                this->type = 1;
            else
                this->type = 0;

            recalc();
        }
    }

    void recalc()
    {
        if (leftmost == rightmost)
            return;
        if (type == 0)
        {
            val = lChild->val ^ rChild->val;
        }
        else
        {
            val = lChild->val | rChild->val;
        }
    }

    void pointUpdate(int index, int newVal)
    {
        if (leftmost == rightmost)
        {
            val = newVal;
            return;
        }

        if (index <= lChild->rightmost)
        {
            lChild->pointUpdate(index, newVal);
        }
        else
        {
            rChild->pointUpdate(index, newVal);
        }

        recalc();
    }

    void deleteChild()
    {
        if (lChild != NULL)
        {
            lChild->deleteChild();
            delete lChild;
        }
        if (rChild != NULL)
        {
            rChild->deleteChild();
            delete rChild;
        }
    }
};

void solve(int cc)
{
    int n, m;
    cin >> n >> m;

    int N = (1 << n);

    vector<int> a(N);

    for (int i = 0; i < N; i++)
        cin >> a[i];

    SegTree *T = new SegTree(0, N - 1, 0, a);

    for (int i = 0; i < m; i++)
    {
        int index, newVal;
        cin >> index >> newVal;

        T->pointUpdate(index - 1, newVal);

        cout << T->val << '\n';
    }

    T->deleteChild();

    delete T;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}