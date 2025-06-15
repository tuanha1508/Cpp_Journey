//1432. Max Difference You Can Get From Changing an Integer
/*
    Time Complexity: O(n) 
    Space Complexity: O(n)
    
    Problem Overview: In two operations : 
    - Change one digit of the number to any digit from 0 to 9.
    - Replace all occurrences of a digit with choosen digit.
    - Find the maximum difference between two numbers that can be obtained by performing the above operations.

    Approach: Math, Greedy
    - Convert the number to a string to easily manipulate its digits.
    - For the maximum number, replace the first non-9 digit with 9.
    - For the minimum number, replace the first non-0 digit with 0 (if it's not the first digit) or 1 (if it is the first digit).
    - Calculate the difference between the maximum and minimum numbers obtained.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string mx = "";
        string mn = "";
        char find_max = '#';
        char find_min = '#';

        for(auto i : s) {
            if(i == '9' || i == '1') {
                if(i == '1' && find_max == '#' && i != '9') find_max = i;
                if(i == '9' && find_min == '#' && i != '0') find_min = i;
                continue; 
            } 
            if(find_max == '#' && i != '9') find_max = i;
            if(find_min == '#' && i != '0') find_min = i;
        }   
        if(find_max == '#') mx = s;
        if(find_min == '#') mn = s;
        
        for(int i = 0 ; i < s.size() ; i++) {
            if(mx.size() < s.size()) {
                if(s[i] == find_max) mx += '9';
                else mx += s[i];
            }
            
            if(mn.size() < s.size()) {
                if(s[i] == find_min && s[i] != '0') {
                    if(s[0] != '1') {
                        mn += "1";
                    }
                    else {
                        mn += "0";
                    }
                }
                else mn += s[i];
            }   
        }
        return stoi(mx) - stoi(mn);
    }
};