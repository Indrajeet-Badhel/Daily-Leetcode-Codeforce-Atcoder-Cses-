class Solution {
public:
    const int MOD = 1000000007;

    vector<vector<int>> memopathval;
    vector<vector<int>> memoway;

    vector<int> solve(int row, int col, vector<string>& board) {

        if (row < 0 || col < 0)
            return {-1, 0};

        char ch = board[row][col];

        if (ch == 'X')
            return {-1, 0};

        // Reached E
        if (row == 0 && col == 0)
            return {0, 1};

        // Already computed
        if (memopathval[row][col] != -2)
            return {memopathval[row][col], memoway[row][col]};

        vector<int> up = solve(row - 1, col, board);
        vector<int> left = solve(row, col - 1, board);
        vector<int> diagonal = solve(row - 1, col - 1, board);

        int best = max({up[0], left[0], diagonal[0]});

        if (best == -1) {
            memopathval[row][col] = -1;
            memoway[row][col] = 0;
            return {-1, 0};
        }

        long long ways = 0;

        if (up[0] == best)
            ways = (ways + up[1]) % MOD;

        if (left[0] == best)
            ways = (ways + left[1]) % MOD;

        if (diagonal[0] == best)
            ways = (ways + diagonal[1]) % MOD;

        int value = 0;

        if (ch >= '1' && ch <= '9')
            value = ch - '0';

        memopathval[row][col] = best + value;
        memoway[row][col] = ways;

        return {memopathval[row][col], memoway[row][col]};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        memopathval.assign(n, vector<int>(n, -2));
        memoway.assign(n, vector<int>(n, 0));

        vector<int> ans = solve(n - 1, n - 1, board);

        if (ans[0] == -1)
            return {0, 0};

        return ans;
    }
};