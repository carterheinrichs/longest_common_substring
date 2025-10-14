#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

void count_letters(const string& s, vector<vector<int>>& dp, int wort)
{
    for (char current_char : s)
    {
        dp[static_cast<unsigned char>(current_char)][wort]++;
    }
}

void lc_calc(vector<vector <int>> dp)
{
    int counter = 0;

    for (int i =0 ; i < 256; ++i)
    {
        counter += min(dp[i][0], dp[i][1]);
    }

    cout << "VALUE: " << counter << endl;
    return;
}

int main()
{
    string eins = "abcde";
    string zwei = "ace";

    // 26 letters
    // 2 strings...
    //int dp[256][2];
    //vector<int> dp_vec;
    vector<vector<int>> dp_vec(256, vector<int>(2, 0));


    cout << eins << endl;
    cout << zwei << endl;

    count_letters(eins, dp_vec, 0);
    count_letters(zwei, dp_vec, 1);

    lc_calc(dp_vec);

    return 0;
}