/*class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> newNums(n);
        for (int i = 0; i < n; i++)
            newNums[i] = {nums[i], i};
        sort(newNums.begin(), newNums.end());

        vector<int> getI(n);
        for (int i = 0; i < n; i++)
            getI[newNums[i].second] = i;

        vector<vector<int>> st(n, vector<int>(18));

        int r = 0;
        for (int i = 0; i < n; i++) {
            if (r < i) r = i;
            while (r + 1 < n &&
                   newNums[r + 1].first - newNums[r].first <= maxDiff )
                r++;
            st[i][0] = r;
        }

        for (int j = 1; j < 18; j++)
            for (int i = 0; i < n; i++)
                st[i][j] = st[st[i][j - 1]][j - 1];

        vector<int> ans(queries.size(), -1);
        for (int i = 0; i < (int)queries.size(); i++) {
            int a = getI[queries[i][0]];
            int b = getI[queries[i][1]];
            if (a > b) swap(a, b);
            if (a == b) { ans[i] = 0; continue; }

            int curr = a, steps = 0;
            for (int j = 17; j >= 0; j--)
                if (st[curr][j] < b) { curr = st[curr][j]; steps += (1 << j); }

            ans[i] = (st[curr][0] >= b) ? steps + 1 : -1;
        }
        return ans;
    }
};*/
/*class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& val, int d, vector<vector<int>>& q) {
        vector<int> reach(n, -1);
        reach[n - 1] = n - 1;
        vector<pair<int, int>> valIdx(n);
        for (int i = 0; i < n; i++) valIdx[i] = { val[i], i };
        sort(valIdx.begin(), valIdx.end());
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[valIdx[i].second] = i;
        for (int i = n - 2; i >= 0; i--) {
            if (valIdx[i + 1].first - valIdx[i].first <= d) reach[i] = reach[i + 1];
            else reach[i] = i;
        }
        int l = 0;
        int jump[100005][18];
        for (int r = 0; r < n; r++) {
            while (valIdx[r].first - valIdx[l].first > d) {
                jump[l][0] = r - 1;
                l++;
            }
        }
        while (l < n) {
            jump[l][0] = n - 1;
            l++;
        }
        for (int j = 1; j < 18; j++) {
            for (int i = 0; i < n; i++) {
                jump[i][j] = jump[jump[i][j - 1]][j - 1];
            }
        }
        vector<int> res(q.size(), -1);
        for (int i = 0; i < q.size(); i++) {
            int a = pos[q[i][0]], b = pos[q[i][1]];
            if (a > b) swap(a, b);
            if (a == b) {
                res[i] = 0;
                continue;
            }
            if (reach[a] < b) {
                res[i] = -1;
                continue;
            }
            int cnt = 0;
            for (int j = 17; j >= 0; j--) {
                if (jump[a][j] < b) {
                    a = jump[a][j];
                    cnt += (1 << j);
                }
            }
            res[i] = cnt + 1;
        }
        return res;
    }
};*/