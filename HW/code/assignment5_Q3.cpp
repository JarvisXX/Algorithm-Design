#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp;
        dp.resize(m + 1, vector<int>(n + 1));
        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                dp[i][j] = 0;
            }
        }

        for (int k = 0; k < strs.size(); ++k) {
            int num0 = 0;
            int num1 = 0;
            for (int p = 0; p < strs[k].length(); ++p) {
                switch (strs[k][p]) {
                    case '0':
                        ++num0;
                        break;
                    case '1':
                        ++num1;
                }
            }
            for (int i = m; i >= 0; --i) {
                for (int j = n; j >= 0; --j) {
                    if (i - num0 >= 0 && j - num1 >= 0)
                        dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    int m, n, N;
    scanf("%d %d %d", &m, &n, &N);
    vector<string> strs(N);
    for (int i = 0; i < N; ++i) {
        cin >> strs[i];
    }
    Solution sol;
    int result;

    result = sol.findMaxForm(strs, m, n);
    printf("%d", result);
}
