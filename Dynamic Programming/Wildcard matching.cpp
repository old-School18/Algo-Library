// Time Complexity: O(2^(n+m)) Recursive | O(n*m) for remaining
// Memory Complexity: O(n+m) Recursive | O(n*m) Memoization & Tabulation | O(m) Space optimized Tabulation
// Check whether pattern p matches string s by replacing '?' with any single character and '*' with any sequence of characters including empty sequence.

// Recursive
bool wildcardRecurse(string &s, string &p, ll n, ll m, ll idx, ll idy)
{
    if (idx == n && idy == m)
    {
        return true;
    }
    if (idx == n)
    {
        while (idy < m)
        {
            if (p[idy++] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if (idy == m)
    {
        return false;
    }

    if (s[idx] == p[idy] || p[idy] == '?')
    {
        return wildcardRecurse(s, p, n, m, idx + 1, idy + 1);
    }
    if (p[idy] == '*')
    {
        return wildcardRecurse(s, p, n, m, idx + 1, idy) || wildcardRecurse(s, p, n, m, idx, idy + 1);
    }

    return false;
}

bool wildcard(string &s, string &p)
{
    return wildcardRecurse(s, p, s.size(), p.size(), 0, 0);
}

// Memoization (Top-down)
bool wildcardMemo(string &s, string &p, vector<vector<ll>> &dp, ll n, ll m, ll idx, ll idy)
{
    if (idx == n && idy == m)
    {
        return true;
    }
    if (idx == n)
    {
        while (idy < m)
        {
            if (p[idy++] != '*')
            {
                return false;
            }
        }
        return true;
    }
    if (idy == m)
    {
        return false;
    }
    if (dp[idx][idy] != -1)
    {
        return dp[idx][idy];
    }

    if (s[idx] == p[idy] || p[idy] == '?')
    {
        return dp[idx][idy] = wildcardMemo(s, p, dp, n, m, idx + 1, idy + 1);
    }
    if (p[idy] == '*')
    {
        return dp[idx][idy] = wildcardMemo(s, p, dp, n, m, idx + 1, idy) || wildcardMemo(s, p, dp, n, m, idx, idy + 1);
    }

    return dp[idx][idy] = false;
}

bool wildcard(string &s, string &p)
{
    ll n = s.size();
    ll m = p.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    return wildcardMemo(s, p, dp, s.size(), p.size(), 0, 0);
}

// Tabulation (Bottom-up)
bool wildcard(string &s, string &p)
{
    ll n = s.size();
    ll m = p.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = (j == 0) || (dp[i][j - 1] && p[j - 1] == '*');
                continue;
            }
            if (j == 0)
            {
                dp[i][j] = false;
                continue;
            }
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}

// Space optimized Tabulation (Rolling-array optimization)
bool wildcard(string &s, string &p)
{
    ll n = s.size();
    ll m = p.size();
    vector<vector<ll>> dp(2, vector<ll>(m + 1));
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i % 2][j] = (j == 0) || (dp[i % 2][j - 1] && p[j - 1] == '*');
                continue;
            }
            if (j == 0)
            {
                dp[i % 2][j] = false;
                continue;
            }
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i % 2][j] = dp[1 - i % 2][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i % 2][j] = dp[1 - i % 2][j] || dp[i % 2][j - 1];
            }
            else
            {
                dp[i % 2][j] = 0;
            }
        }
    }
    return dp[n % 2][m];
}
