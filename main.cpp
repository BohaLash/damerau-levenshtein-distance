//  Damerau-Levenshtein

#include <iostream>
#include <damerau-levenshtein.h>

using namespace std;

int main(int argc, const char * argv[]) {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << damerauLevenshteinDistance(s1, s2) << '\n';
    return 0;
}
