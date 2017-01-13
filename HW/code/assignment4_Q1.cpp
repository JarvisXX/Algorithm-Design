#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int cnt = 0;
        while(i < j) {
            cnt += nums[j--] - nums[i++];
        }
        return cnt;
    }
};

int main(){
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    for (int i = 0; i < N; ++i){
        scanf("%d", &A[i]);
    }
    int minMoves;
    Solution sol;

    minMoves = sol.minMoves(A);
    printf("Minimum moves: %d\n", minMoves);
}
