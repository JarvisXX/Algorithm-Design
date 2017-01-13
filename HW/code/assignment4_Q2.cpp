#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = s.length();
        int count[26] = {0};
        int start = 0;
        int max_ = 0;
        int res = 0;
        for (int end = 0; end < l; end++) {
            max_ = max(max_, ++count[s[end] - 'A']);
            while (end - start + 1 - max_ > k) {
                --count[s[start] - 'A'];
                ++start;
            }
            res = max(res, end - start + 1);
        }
        return res;
    }
};

int main(){
    string s;
    int k;
    cin >> s;
    scanf("%d", &k);
    int result = 0;
    Solution sol;

    result = sol.characterReplacement(s, k);
    printf("The length of the longest substring: %d\n", result);
}
