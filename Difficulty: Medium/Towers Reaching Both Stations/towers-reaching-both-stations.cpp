class Solution {
public:
    int countCoordinates(vector<vector<int>> &mat) {
        int N = mat.size();
        int M = mat[0].size();

        vector<vector<int>> indianOcean(N, vector<int>(M, 0));
        vector<vector<int>> arabianSea(N, vector<int>(M, 0));

        vector<int> dir = {0, -1, 0, 1, 0};
        queue<pair<int, int>> q;
        int ans = 0;

        // Indian Ocean (Top row + Left column)
        for (int i = 0; i < N; i++) {
            indianOcean[i][0] = 1;
            q.push({i, 0});
        }

        for (int j = 1; j < M; j++) {
            indianOcean[0][j] = 1;
            q.push({0, j});
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int x = p.first + dir[k];
                int y = p.second + dir[k + 1];

                if (x < 0 || x >= N || y < 0 || y >= M ||
                    indianOcean[x][y])
                    continue;

                if (mat[x][y] >= mat[p.first][p.second]) {
                    indianOcean[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        // Arabian Sea (Bottom row + Right column)
        for (int i = 0; i < N; i++) {
            arabianSea[i][M - 1] = 1;
            if (indianOcean[i][M - 1])
                ans++;
            q.push({i, M - 1});
        }

        for (int j = 0; j < M - 1; j++) {
            arabianSea[N - 1][j] = 1;
            if (indianOcean[N - 1][j])
                ans++;
            q.push({N - 1, j});
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int x = p.first + dir[k];
                int y = p.second + dir[k + 1];

                if (x < 0 || x >= N || y < 0 || y >= M ||
                    arabianSea[x][y])
                    continue;

                if (mat[x][y] >= mat[p.first][p.second]) {
                    if (indianOcean[x][y])
                        ans++;

                    arabianSea[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        return ans;
    }
};