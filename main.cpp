/*
 * LCS calculator
 * 10/15/2025
 *
 * Algorithms class
 */
#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

/**
 * @brief Counts the frequency of each character in a string and stores the results.
 * @param s this is the string to be gone through
 * @param dp this is our vector
 * @param wort this is the flag to choose which order to put this word in
 */
void count_letters(const string& s, vector<vector<int>>& dp, int wort)
{
    for (char current_char : s)
    {
        // map characters in the 0-255 range
        dp[static_cast<unsigned char>(current_char)][wort]++;
    }
}

/**
 * @brief Calculates and prints the lcs.
 * @param dp this is our vector
 */
void lc_calc(vector<vector <int>> dp)
{
    int counter = 0;

    for (int i =0 ; i < 256; ++i)
    {
        // add the count from string 0 and 1
        counter += min(dp[i][0], dp[i][1]);
    }

    cout << "VALUE: " << counter << endl;
    return;
}

int main()
{
    cout << "LONGEST COMMON SUBSTRING" << endl;
    cout << "------------------------" << endl;

    string eins = "abcde";
    string zwei = "ace";

    cout << "BYO STRINGS? (y/n)";
    char choice = 'N';
    cin >> choice;
    cin.ignore();

    if (choice == 'y' || choice == 'Y') {
        cout << "ENTER STRING 1:";
        getline(cin, eins);

        cout << "ENTER STRING 2:";
        getline(cin, zwei);
    }

    // 26 letters
    // 2 strings...
    vector<vector<int>> dp_vec(256, vector<int>(2, 0));

    cout << "STRINGS:" << endl;
    cout << eins << endl;
    cout << zwei << endl;

    // count each function, vector is referenced so no need to return
    count_letters(eins, dp_vec, 0);
    count_letters(zwei, dp_vec, 1);

    // add up the two vectors and print the result
    lc_calc(dp_vec);

    return 0;
}