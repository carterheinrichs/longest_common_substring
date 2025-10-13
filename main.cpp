#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

vector<vector<int>> count_letters(string s, vector<vector<int>> dp, int wort)
{
    for (int i = 0; i < s.length(); ++i)
    {
        char current = s[i];
        dp[current][wort] += 1;
    }
    return dp;
}

void lc_calc(vector<vector <int>> dp)
{
    int counter = 0;

    for (int i =0 ; i < 256; ++i)
    {
       for (int j = 0; j < 2; ++j)
       {
           if (i) {
               counter++;
           }
       }
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

    count_letters(eins, dp_vec, false);
    count_letters(zwei, dp_vec, true);

    lc_calc(dp_vec);

    return 0;
}