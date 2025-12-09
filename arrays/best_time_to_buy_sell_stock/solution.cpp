#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int x(vector<int> prices)
    {
        int buy, profit;

        for(int i = 0; i < prices.size(); i++)
        {
            if(buy > prices[i]) buy = prices[i];
            if(prices[i] - buy > profit) profit = prices[i] - buy;
        }
        return profit;
    }
};