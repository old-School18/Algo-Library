// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Identify minimum number of rooms required to schedule N meetings

// Sweep line appraoch – Maximum overlapping identification
class Comparator
{
  public:
    bool operator()(const pair<ll, ll> &x, const pair<ll, ll> &y)
    {
		// tie-breaker - if an event cannot start right at the moment another event ends. If problem mentions that this does not count as a conflict, skip this condition
        if (x.first == y.first)
        {
            return x.second > y.second;
        }
        return x.first < y.first;
    }
};

ll sweepLine(vector<ll> &start, vector<ll> &end)
{
    vector<pair<ll, ll>> sweepList;

    for (auto &p : start)
    {
        sweepList.push_back({p, 1});
    }
    for (auto &p : end)
    {
        sweepList.push_back({p, -1});
    }

    sort(sweepList.begin(), sweepList.end(), Comparator());

    ll sweepScore = 0, maxScore = 0;

    for (auto &p : sweepList)
    {
        sweepScore += p.second;
        maxScore = max(maxScore, sweepScore);
    }

    return maxScore;
}

---------------------------
// Minimum Resource Allocation approach - Minimum resources to avoid overlaps identification
vector<ll> minResourcesAllocation(vector<ll> &start, vector<ll> &end)
{
    ll n = start.size();
    vector<pair<pair<ll, ll>, ll>> schedules;
    vector<ll> allocatedResources(n + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll resources = 0;

    for (ll i = 0; i < n; i++)
    {
        schedules.push_back({{start[i], end[i]}, i});
    }
    sort(schedules.begin(), schedules.end());

    for (auto &p : schedules)
    {
		// use <= if a meeting can start right after a meeting ends in a given room
        if (!pq.empty() && pq.top().first < p.first.first)
        {
            allocatedResources[p.second] = pq.top().second;
            pq.pop();
            pq.push({p.first.second, allocatedResources[p.second]});
        }
        else
        {
            pq.push({p.first.second, ++resources});
        }
    }

    return allocatedResources;
}

---------------------------------
Reference:
https://neetcode.io/problems/meeting-schedule-ii/solution
https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/
