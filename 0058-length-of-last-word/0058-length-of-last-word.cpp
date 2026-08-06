class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        long iLength = 0;

        while (s[i] == ' ') i--;

        while (i >= 0 && s[i] != ' ') {
            iLength++;
            i--;
        }

        return iLength;
    }
};