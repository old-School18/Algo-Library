// Time Complexity: O(2^n) Recursion | O(n) Memoization & Tabulation
// Memory Complexity: O(n)
// Count the number of ways to fill up blocks to build a 2*n tower
// Boundary State DP

// Recursive
ll countTowersRecurse(ll n, ll layer, ll boundaryState)
{
    if (layer > n)
    {
        return 1;
    }

    if (!boundaryState)
    {
        return 4 * countTowersRecurse(n, layer + 1, 0) + countTowersRecurse(n, layer + 1, 1);
    }
    else
    {
        return countTowersRecurse(n, layer + 1, 0) + 2 * countTowersRecurse(n, layer + 1, 1);
    }
}

ll countTowers(ll n)
{
    return countTowersRecurse(n, 2, 0) + countTowersRecurse(n, 2, 1);
}


// Memoization (Top-down)
ll countTowersMemo(vector<vector<ll>> &dp, ll n, ll layer, ll boundaryState)
{
    if (layer > n)
    {
        return 1;
    }

    if (dp[layer][boundaryState])
    {
        return dp[layer][boundaryState];
    }

    if (!boundaryState)
    {
        return dp[layer][boundaryState] =
                   4 * countTowersMemo(dp, n, layer + 1, 0) + countTowersMemo(dp, n, layer + 1, 1);
    }
    else
    {
        return dp[layer][boundaryState] =
                   countTowersMemo(dp, n, layer + 1, 0) + 2 * countTowersMemo(dp, n, layer + 1, 1);
    }
}

ll countTowers(ll n)
{
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    return countTowersMemo(dp, n, 2, 0) + countTowersMemo(dp, n, 2, 1);
}

// Tabulation (Bottom-up)
ll countTowers(ll n)
{
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[1][0] = dp[1][1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        dp[i][0] = 4 * dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1];
    }
    return dp[n][0] + dp[n][1];
}


------------------------------------------------------
Note: BoundaryState = 0 means two separate blocks at the edge. BoundaryState = 1 means single block along the edge.
Problem reference: https://cses.fi/problemset/task/2413
