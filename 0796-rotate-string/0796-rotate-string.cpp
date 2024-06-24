class Solution {
public:
    bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
        return false;
    }

    string concat = s + s;

    for (int i = 0; i < s.length(); ++i) {
        int j = 0;
        while (j < goal.length() && concat[i + j] == goal[j]) {
            ++j;
        }
        if (j == goal.length()) {
            return true; // Found the goal as a substring of concat
        }
    }

    return false; // goal is not a substring of concat
}
};