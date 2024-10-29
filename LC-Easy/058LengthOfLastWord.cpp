/*
58. Length of Last Word - Easy
------------------------------
Given a string s consisting of words and spaces, 
return the length of the last word in the string.

A word is a maximal substring consisting of 
non-space characters only.
*/

#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int count = 0;
    for(int i= s.length()-1; i>=0; i--) {
        if(s[i] == ' ') {
            // check if we have started the count or not
            if(count > 0) break;
        }
        else
            count++;
    }
    return count;
}
