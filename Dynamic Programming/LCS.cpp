// Time Complexity: O(2^(n+m)) Recursive | O(n*m) for remaining
// Memory Complexity: O(n+m) Recursive | O(n*m) Memoization & Tabulation | O(m) Space optimized Tabulation
// Find the longest common subsequence length between two strings

// Recursive
ll lcsRecurse(string &s, string &t, ll sidx, ll tidx)
{
    if (sidx == s.size() || tidx == t.size())
    {
        return 0;
    }

    if (s[sidx] == t[tidx])
    {
        return 1 + lcsRecurse(s, t, sidx + 1, tidx + 1);
    }
    return max(lcsRecurse(s, t, sidx + 1, tidx), lcsRecurse(s, t, sidx, tidx + 1));
}

ll lcs(string s, string t)
{
    return lcsRecurse(s, t, 0, 0);
}

// Memoization (Top-down)
ll lcsMemo(string &s, string &t, vector<vector<ll>> &dp, ll sidx, ll tidx)
{
    if (sidx == s.size() || tidx == t.size())
    {
        return 0;
    }
    if (dp[sidx][tidx] != -1)
    {
        return dp[sidx][tidx];
    }

    if (s[sidx] == t[tidx])
    {
        return dp[sidx][tidx] = 1 + lcsMemo(s, t, dp, sidx + 1, tidx + 1);
    }
    return dp[sidx][tidx] = max(lcsMemo(s, t, dp, sidx + 1, tidx), lcsMemo(s, t, dp, sidx, tidx + 1));
}

ll lcs(string s, string t)
{
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    return lcsMemo(s, t, dp, 0, 0);
}

// Tabulation (Bottom-up)
ll lcs(string s, string t)
{
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

// Space optimized Tabulation (Rolling-array optimization)
ll lcs(string s, string t)
{
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(2, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i % 2][j] = dp[1 - i % 2][j - 1] + 1;
            }
            else
            {
                dp[i % 2][j] = max(dp[1 - i % 2][j], dp[i % 2][j - 1]);
            }
        }
    }

    return dp[n%2][m];
}
