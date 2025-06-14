//2566. Maximum Difference by Remapping a Digit
/*
    Time Complexity: O(1)
    Space Complexity: O(1)
    
    Problem Overview: Change one digit in a number to maximize the difference between the maximum and minimum numbers.

    Approach: Greedy, Math
    - Greedy : maximum number is obtained by changing the first non-9 digit to 9 -> maximun value
    -          minimum number is obtained by changing the first non-minimum digit to 0 -> minimum value
    - Iterate through the digits of the number, find the first digit that is not 9 for maximum.
    - For minimum, find the first digit change.
    - Construct the maximum and minimum numbers by replacing the digits accordingly.
    - Finally, return the difference between the maximum and minimum numbers.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        int find = -1;
        int pos_min = -1;    
        for(int i = 100000000 ; i >= 1 ; i /= 10) {
            if(i > num) continue;
            int curr = num / i;
            curr %= 10;
            if(pos_min == -1) pos_min = curr;
            if(curr == 9) continue;
            else {
                find = curr;
                break;
            }
        }

        int num_build = 0;
        int min_build = 0;
        for(int i = 100000000 ; i >= 1 ; i /= 10) {
            if(i > num) continue;
            int curr = num / i;
            curr %= 10;
            if(curr != find) num_build = num_build * 10 + curr;
            else num_build = num_build * 10 + 9;

            if(curr != pos_min) min_build = min_build * 10 + curr;
            else min_build = min_build * 10 + 0;
        }

        return num_build - min_build;
    }
};