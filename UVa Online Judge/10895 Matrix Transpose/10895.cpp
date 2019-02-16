#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<pair<int, vii>> matrix; // vector<pair<rowIndex, vector<pair<colIndex, value>>>
vector<pair<int, vii>> transpose;
int colToRow[10001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    matrix.reserve(1000);
    transpose.reserve(1000);

    int row, col;
    while (cin >> row >> col, !cin.eof())
    {
        matrix.clear();
        transpose.clear();
        memset(colToRow, -1, sizeof(colToRow));

        ///////////// input
        for (int i = 1; i <= row; ++i) // Matrix subscripts are 1-based
        {
            int numOfNoneZeros;
            cin >> numOfNoneZeros;

            if (numOfNoneZeros == 0)
            {
                continue;
            }
            else
            {
                matrix.push_back(pair<int, vii>(i, vii()));
            }

            int colIndex;
            for (int j = 0; j < numOfNoneZeros; ++j)
            {
                cin >> colIndex;
                matrix.back().second.push_back(ii(colIndex, 0));

                ++colToRow[colIndex];
            }

            int value;
            for (int j = 0; j < numOfNoneZeros; ++j)
            {
                cin >> value;
                matrix.back().second[j].second = value;
            }
        }

        //////////////// transpose
        int count = 0;
        for (int i = 1; i <= col; ++i) // Matrix subscripts are 1-based
        {
            if (colToRow[i] > -1)
            {
                transpose.push_back(pair<int, vii>(i, vii()));
                colToRow[i] = count++;
            }
        }

        for (size_t i = 0; i < matrix.size(); ++i)
        {
            int rowIndex = matrix[i].first;
            vii &rowVector = matrix[i].second;
            for (auto it = rowVector.begin(); it != rowVector.end(); ++it)
            {
                int colIndex = it->first;
                int value = it->second;
                transpose[colToRow[colIndex]].second.push_back(ii(rowIndex, value));
            }
        }

        for (size_t i = 0; i < transpose.size(); ++i)
        {
            sort(transpose[i].second.begin(), transpose[i].second.end());
        }

        /////////////////// output
        cout << col << ' ' << row << '\n';

        for (int i = 1; i <= col; ++i) // Matrix subscripts are 1-based
        {
            if (colToRow[i] < 0)
            {
                cout << 0 << "\n\n";
                continue;
            }

            vii &rowVector = transpose[colToRow[i]].second;
            cout << rowVector.size();
            for (size_t j = 0; j < rowVector.size(); ++j)
            {
                cout << ' ' << rowVector[j].first;
            }
            cout << '\n';

            cout << rowVector[0].second;
            for (size_t j = 1; j < rowVector.size(); ++j)
            {
                cout << ' ' << rowVector[j].second;
            }
            cout << '\n';
        }
    }
}