#include <iostream>

using namespace std;

/**
 * Damerau–Levenshtein distance.
 *
 * Calculate Damerau–Levenshtein distance from a to b.
 * Prints steps (optional).
 *
 * Using DP.
 *
 * @param a First string.
 * @param b Second string.
 * @param sound Operations printing.
 * @return Damerau–Levenshtein distance |b - a|.
 */
unsigned long damerauLevenshteinDistance(string& a, string& b, bool sound = true) {
    const unsigned long l1 = a.length(), l2 = b.length();
    unsigned long i, j, d[l1 + 1][l2 + 1];
    for (i = 0; i <= l1; ++i) {
        for (j = 0; j <= l2; ++j) {
            if (i == 0) { d[i][j] = j; continue; }
            if (j == 0) { d[i][j] = i; continue; }
            d[i][j] = min(d[i - 1][j], d[i][j - 1]) + 1; // deletion & insertion
            d[i][j] = min(d[i][j], d[i - 1][j - 1] + (a[i - 1] != b[j - 1])); // match or mismatch
            if (i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1])
                d[i][j] = min(d[i][j], d[i - 2][j - 2] + 1); // transposition
        }
    }
    
    if (!sound) return d[l1][l2];
    
    i = l1; j = l2;
    while (i && j) {
        if (i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1]) {
            if (d[i-2][j-2] < d[i-1][j] && d[i-2][j-2] < d[i][j-1] && d[i-2][j-2] < d[i-1][j-1]) {
                cout << "transposition '" << a[i - 1] << "' <> '" << a[i - 2] << "'\n";
                i -= 2; j -=2; continue;
            }
        }
        
        if (d[i-1][j-1] < d[i-1][j] && d[i-1][j-1] < d[i][j-1]) {
            if (a[i - 1] != b[j - 1]) cout << "substitution '" << a[i - 1] << "' > '" << b[j - 1] << "'\n";
            i -= 1; j -= 1; continue;
        }
        
        if (d[i-1][j] < d[i][j-1]) {
            cout << "deletion '" << a[i - 1] << "'\n";
            i -= 1; continue;
        }
        
        cout << "insertion '" << b[j - 1] << "'\n";
        j -= 1; continue;
    }
    
    return d[l1][l2];
}
