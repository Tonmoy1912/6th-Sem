#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define endl '\n'

bool check(string &a, string &b, string &c, unordered_map<char, int> &m)
{
    string an, bn, cn;
    for (auto it : a)
    {
        an.push_back(m[it] + '0');
    }
    for (auto it : b)
    {
        bn.push_back(m[it] + '0');
    }
    for (auto it : c)
    {
        cn.push_back(m[it] + '0');
    }
    ll anum, bnum, cnum;
    anum = stoll(an);
    bnum = stoll(bn);
    cnum = stoll(cn);
    ll sum = anum + bnum;
    return sum == cnum;
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    set<char> s;
    for (auto it : a)
    {
        s.insert(it);
    }
    for (auto it : b)
    {
        s.insert(it);
    }
    for (auto it : c)
    {
        s.insert(it);
    }
    if (s.size() > 10)
    {
        cout << "Number of unique character greater than 10" << endl;
        return 0;
    }
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    unordered_map<char, int> m;
    do
    {
        int i = 0;
        for (auto it : s)
        {
            m[it] = arr[i];
            i++;
        }
        bool t = check(a, b, c, m);
        if (t)
        {
            for (auto it : m)
            {
                cout << it.first << " " << it.second << endl;
            }
                return 0;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    cout << "No match" << endl;
    return 0;
}