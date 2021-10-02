#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{

    int currentMin = INT_MAX;
    int result = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        result = max(result, prices[i] - currentMin);
        currentMin = min(currentMin, prices[i]);
    }

    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> prices;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            prices.push_back(a);
        }
        cout << maxProfit(prices);
    }

    return 0;
}