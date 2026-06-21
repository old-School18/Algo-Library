// Time Complexity: O(2^n) Recursive | O(n*W) for remaining
// Memory Complexity: O(n) Recursive | O(n*W) Memoization & Tabulation | O(W) Space optimized Tabulation
// Fill up a knapsack with given weights such that the sum of values of chosen weights is maximum. Each weight can be added only once. The sack can be filled up to W capacity

// Recursive
ll knapsack01Recurse(vector<ll> &weights, vector<ll> &values, ll W, ll idx)
{

    if (idx == weights.size())
    {
        return 0;
    }

    return max((weights[idx] <= W) ? values[idx] + knapsack01Recurse(weights, values, W - weights[idx], idx + 1) : 0ll,
               knapsack01Recurse(weights, values, W, idx + 1));
}

ll knapsack01(vector<ll> &weights, vector<ll> &values, ll W)
{
    return knapsack01Recurse(weights, values, W, 0);
}

// Memoization (Top-down)
ll knapsack01Memo(vector<ll> &weights, vector<ll> &values, vector<vector<ll>> &dp, ll W, ll idx)
{
    if (idx == weights.size())
    {
        return 0;
    }
    if (dp[idx][W] != LLONG_MIN)
    {
        return dp[idx][W];
    }

    return dp[idx][W] = max(
               (weights[idx] <= W) ? values[idx] + knapsack01Memo(weights, values, dp, W - weights[idx], idx + 1) : 0ll,
               knapsack01Memo(weights, values, dp, W, idx + 1));
}

ll knapsack01(vector<ll> &weights, vector<ll> &values, ll W)
{
    ll n = weights.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, LLONG_MIN));
    return knapsack01Memo(weights, values, dp, W, 0);
}

// Tabulation (Bottom-up)
ll knapsack01(vector<ll> &weights, vector<ll> &values, ll W)
{
    ll n = weights.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= W; j++)
        {
            dp[i][j] = max(dp[i - 1][j], (weights[i - 1] <= j) ? values[i - 1] + dp[i - 1][j - weights[i - 1]] : 0ll);
        }
    }

    return dp[n][W];
}

// Space optimized Tabulation (Rolling-array optimization)
ll knapsack01(vector<ll> &weights, vector<ll> &values, ll W)
{
    ll n = weights.size();
    vector<vector<ll>> dp(2, vector<ll>(W + 1, 0));

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= W; j++)
        {
            dp[i % 2][j] =
                max(dp[1 - i % 2][j], (weights[i - 1] <= j) ? values[i - 1] + dp[1 - i % 2][j - weights[i - 1]] : 0ll);
        }
    }

    return dp[n % 2][W];
}

// Ultra space optimized Tabulation (1D DP)
ll knapsack01(vector<ll> &weights, vector<ll> &values, ll W)
{
    ll n = weights.size();
    vector<ll> dp(W + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = W; j >= 1; j--)
        {
            if (weights[i - 1] <= j)
            {
                dp[j] = max(dp[j], values[i - 1] + dp[j - weights[i - 1]]);
            }
        }
    }

    return dp[W];
}
