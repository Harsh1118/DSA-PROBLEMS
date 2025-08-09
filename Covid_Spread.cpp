/*
Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a
hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following
meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1],
[i,j+1] (up, down, left and right) in unit time. Help Aterp determine the minimum units of time after which
there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected
after infinite units of time then simply return -1.




Example 1:

Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
Output:
2
Explanation:
Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1},
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st
unit time. And, during 2nd unit time, patient at
{1, 0} will get infected and will infect patient
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.
Example 2:

Input:
3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1
Output:
-1
Explanation:
All patients will not be infected.


Your Task:
You don't need to read input or print anything. Your task is to complete the function helpaterp() which takes a
2-D Matrix hospital as input parameter and returns the minimum units of time in which all patients will be infected
or -1 if it is impossible.


Constraints:
1 ≤ R,C ≤ 1000
0 ≤ mat[i][j] ≤ 2


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int r;
    int c;
    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    int helpaterp(vector<vector<int>> hospital)
    {
        // code here
        r = hospital.size();
        c = hospital[0].size();

        int healthy_patient = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (hospital[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }

                if (hospital[i][j] == 1)
                {
                    healthy_patient++;
                }
            }
        }

        if (!healthy_patient)
        {
            return 0;
        }

        int timer = 0;

        while (!q.empty())
        {
            timer++;
            int curr_patient = q.size();

            while (curr_patient--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    if (valid(i + row[k], j + col[k]) && hospital[i + row[k]][j + col[k]] == 1)
                    {
                        hospital[i + row[k]][j + col[k]] = 2;
                        q.push(make_pair(i + row[k], j + col[k]));
                    }
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (hospital[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return timer - 1;
    }
};