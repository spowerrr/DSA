#include <iostream>
using namespace std;
string commonPrefixUtil(string &p1, string &p2) {
    string result;
    int l1 = p1.length();
    int l2 = p2.length();
    for (int i = 0; i < l1 && i < l2; i++) {
        if (p1[i] != p2[i]) {
            break;
        }
        result.push_back(p1[i]);
    }
    return result;
}
string commonPrefix(vector<string> &arr, int l, int r) {
    if (l == r) {
        return arr[l];
    }
    if (l < r) {
        int mid = (l + r) / 2;
        string p1 = commonPrefix(arr, l, mid);
        string p2 = commonPrefix(arr, mid + 1, r);
        return commonPrefixUtil(p1, p2);
    }
    return "";
}
string longestCommonPrefix(vector<string> &arr) {
    return commonPrefix(arr, 0, arr.size() - 1);
}
int main() {
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    cout << longestCommonPrefix(arr);
    return 0;
}
