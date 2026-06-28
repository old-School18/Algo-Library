// Time Complexity: O(2^n) Recursion | O(n^3) Memoization & Tabulation
// Memory Complexity: O(n) Recursion | O(n^2) Memoization & Tabulation
// Least number of multiplication operations required to multiply a chain of matrices
// Partition DP strategy

// Recursive
ll mcmRecurse(vector<ll> &matrixDims, ll left, ll right)
{
    if (left == right)
    {
        return 0;
    }
    ll minima = LLONG_MAX;
    for (ll partition = left; partition < right; partition++)
    {
        ll leftMcm = mcmRecurse(matrixDims, left, partition);
        ll rightMcm = mcmRecurse(matrixDims, partition + 1, right);
        ll cost = matrixDims[left - 1] * matrixDims[partition] * matrixDims[right];
        minima = min(minima, leftMcm + cost + rightMcm);
    }
    return minima;
}

ll mcm(vector<ll> &matrixDims)
{
    ll n = matrixDims.size();
    return mcmRecurse(matrixDims, 1, n - 1);
}


// Memoization (Top-down)
ll mcmRecurse(vector<ll> &matrixDims, vector<vector<ll>> &dp, ll left, ll right)
{
    if (left == right)
    {
        return 0;
    }
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }
    ll minima = LLONG_MAX;
    for (ll partition = left; partition < right; partition++)
    {
        ll leftMcm = mcmRecurse(matrixDims, dp, left, partition);
        ll rightMcm = mcmRecurse(matrixDims, dp, partition + 1, right);
        ll cost = matrixDims[left - 1] * matrixDims[partition] * matrixDims[right];
        minima = min(minima, leftMcm + cost + rightMcm);
    }
    return dp[left][right] = minima;
}

ll mcm(vector<ll> &matrixDims)
{
    ll n = matrixDims.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    return mcmRecurse(matrixDims, dp, 1, n - 1);
}

// Tabulation (Bottom-up)
ll mcm(vector<ll> &matrixDims)
{
    ll n = matrixDims.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, LLONG_MAX));
    for (ll length = 1; length < n; length++)
    {
        for (ll left = 1; left <= n - length; left++)
        {
            ll right = left + length - 1;
            if (left == right)
            {
                dp[left][right] = 0;
                continue;
            }
            for (ll partition = left; partition < right; partition++)
            {
                dp[left][right] =
                    min(dp[left][right], dp[left][partition] +
                                             matrixDims[left - 1] * matrixDims[partition] * matrixDims[right] +
                                             dp[partition + 1][right]);
            }
        }
    }
    return dp[1][n - 1];
}
