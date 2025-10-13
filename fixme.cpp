//
// Created by heinrichsc3989 on 10/13/2025.
//

#include "fixme.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::min

using namespace std;

// The dp vector is now passed by reference using the '&' symbol.
// This means the function modifies the ORIGINAL vector from main(), not a copy.
// It no longer needs to return anything, so the return type is void.
void count_letters(const string& s, vector<vector<int>>& dp, int word_index)
{
    // It's safer to use word_index (0 or 1) instead of a boolean
    for (char current_char : s)
    {
        // We cast the char to unsigned char to avoid potential issues with negative char values
        // when using it as an array index.
        dp[static_cast<unsigned char>(current_char)][word_index]++;
    }
}

// This function is now corrected to calculate the result based on your
// character-counting method.
void calculate_shared_chars(const vector<vector<int>>& dp)
{
    int shared_char_count = 0;

    // Iterate through all possible character values (0-255)
    for (int i = 0; i < 256; ++i)
    {
        // For each character, the number of times it can appear in a common
        // subsequence is the minimum of its counts in both strings.
        // For example, if 'a' appears 3 times in string one and 1 time in string two,
        // they share at least one 'a'.
        shared_char_count += min(dp[i][0], dp[i][1]);
    }

    cout << "Total shared characters (ignoring order): " << shared_char_count << endl;
}

int main()
{
    string eins = "abcde";
    string zwei = "ace";

    // The vector to hold the character counts for both strings.
    // dp_vec[char_code][0] is the count in the first string.
    // dp_vec[char_code][1] is the count in the second string.
    vector<vector<int>> dp_vec(256, vector<int>(2, 0));

    cout << "String 1: " << eins << endl;
    cout << "String 2: " << zwei << endl;
    cout << "------------------------------------" << endl;

    // Now, these function calls will correctly modify dp_vec.
    count_letters(eins, dp_vec, 0); // Use 0 for the first word
    count_letters(zwei, dp_vec, 1); // Use 1 for the second word

    calculate_shared_chars(dp_vec);

    return 0;
}
