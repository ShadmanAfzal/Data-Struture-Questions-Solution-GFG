#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    map<int, int> hash;
    vector<vector<int>> sol;
    int n = nums.size();

    for (int i = 0; i < n; i++)
        hash[nums[i]] = i;

    for (int i = 0; i < n; i++)
    {
        set<vector<int>> st;
        for (int j = i + 1; j < n; j++)
        {
            int numk = -1 * (nums[i] + nums[j]);
            if (hash.count(numk) > 0)

                if ((i != j and i != hash[numk] and j != hash[numk]))
                {
                    {
                        vector<int> s(3, 0);
                        s[0] = nums[i];
                        s[1] = nums[j];
                        s[2] = numk;
                        if (st.count(s) > 0)
                            continue;
                        else
                            st.insert(s);
                    }
                }
        }
    }
    return sol;
}

int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> sol = threeSum(nums);
    for (int i = 0; i < sol.size(); i++)
    {
        for (int j : sol[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}