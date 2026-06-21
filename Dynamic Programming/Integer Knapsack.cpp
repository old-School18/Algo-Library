// Time Complexity: O(2^(n+W)) Recursive | O(n*W) for remaining
// Memory Complexity: O(n+W) Recursive | O(n*W) Memoization | O(W) Tabulation
// Fill up a knapsack with given weights such that the sum of values of chosen weights is maximum. Each weight can be added multiple times. The sack can be filled up to W capacity

// Recursive
ll unboundedKnapsackRecurse(vector<ll> &weights, vector<ll> &values, ll W, ll idx)
{
    if (idx == weights.size())
    {
        return 0;
    }

    return max(unboundedKnapsackRecurse(weights, values, W, idx + 1),
               (weights[idx] <= W) ? values[idx] + unboundedKnapsackRecurse(weights, values, W - weights[idx], idx)
                                   : 0ll);
}

ll unboundedKnapsack(vector<ll> &weights, vector<ll> &values, ll W)
{
    return unboundedKnapsackRecurse(weights, values, W, 0);
}

// Memoization (Top-down)
ll unboundedKnapsackMemo(vector<ll> &weights, vector<ll> &values, vector<vector<ll>> &dp, ll W, ll idx)
{
    if (idx == weights.size())
    {
        return 0;
    }
    if (dp[idx][W] != LLONG_MIN)
    {
        return dp[idx][W];
    }

    return dp[idx][W] =
               max(unboundedKnapsackMemo(weights, values, dp, W, idx + 1),
                   (weights[idx] <= W) ? values[idx] + unboundedKnapsackMemo(weights, values, dp, W - weights[idx], idx)
                                       : 0ll);
}

ll unboundedKnapsack(vector<ll> &weights, vector<ll> &values, ll W)
{
    ll n = weights.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, LLONG_MIN));
    return unboundedKnapsackMemo(weights, values, dp, W, 0);
}

// Tabulation (Bottom-up)
ll unboundedKnapsack(vector<ll> &weights, vector<ll> &values, ll W)
{
    ll n = weights.size();
    vector<ll> dp(W + 1, 0);
    for (ll i = 0; i <= W; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i >= weights[j])
            {
                dp[i] = max(dp[i], dp[i - weights[j]] + values[j]);
            }
        }
    }
    return dp[W];
}
