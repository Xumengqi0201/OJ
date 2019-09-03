#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
    用内置的find函数即可
*/

int strStr(string haystack, string needle) {
    size_t found = haystack.find(needle);
    if (found != string :: npos)
        return found;
    else
        return -1;
    
    
    return pos;
}

int main(){
    string haystack = "mississippi", needle = "issip";
    strStr(haystack,needle);

    return 0;
}
