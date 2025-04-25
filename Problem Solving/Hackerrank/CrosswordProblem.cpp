#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> crosswordPuzzle(vector<string> crossword, string words)
{
    // calculate how many positions are empty verticaly and horizontaly
    // allign those positions to there respective letters that can fit that position
    // trial and error with backtracking a solution
    vector<int> colHash(0, 10);
    vector<int> rowHash(0, 10);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (crossword[i][j] == '-')
            {
                colHash[j]++;
                rowHash[i]++;
            }
            continue;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << colHash[i] << "-";
    }
    for (int i = 0; i < 10; i++)
    {
        cout << rowHash[i] << "-";
    }
}

int main()
{
    vector<string> v = {"+-++++++++",
                        "+-++++++++",
                        "+-++++++++",
                        "+-----++++",
                        "+-+++-++++",
                        "+-+++-++++",
                        "+++++-++++",
                        "++------++",
                        "+++++-++++",
                        "+++++-++++"};

    string c = "LONDON;DELHI;ICELAND;ANKARA";

    crosswordPuzzle(v, c);
    return 0;
}