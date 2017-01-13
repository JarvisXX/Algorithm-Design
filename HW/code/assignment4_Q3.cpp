#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i = 3; i < x.size(); ++i){
            if (i >= 3 && x[i-1] <= x[i-3] && x[i] >= x[i-2])
                return true;
            if (i >= 4 && x[i-1]==x[i-3] && x[i] + x[i-4] >= x[i-2])
                return true;
            if (i >= 5 && x[i-2] > x[i-4] && x[i-1] <= x[i-3] && x[i-1] + x[i-5] >= x[i-3] && x[i] + x[i-4] >= x[i-2])
                return true;
        }
        return false;
    }
};

int main(){
    int N;
    scanf("%d", &N);
    vector<int> x(N);
    for (int i = 0; i < N; ++i){
        scanf("%d", &x[i]);
    }
    bool result;
    Solution sol;

    result = sol.isSelfCrossing(x);
    if (result)
        printf("True\n");
    else
        printf("False\n");
}
