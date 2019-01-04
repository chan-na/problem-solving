#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

typedef struct
{
    int id;
    int solved;
    int penalty;
} contestant;

vector<contestant> contestants;
bool checkParticipation[101];
bool isSolved[101][10];
int tryCount[101][10];

bool contest_cmp(contestant a, contestant b)
{
    if (a.solved != b.solved)
        return a.solved > b.solved;
    else if (a.penalty != b.penalty)
        return a.penalty < b.penalty;
    else
        return a.id < b.id;
}

void addJudge(char judge[])
{
    int id, problem, submission_time;
    char result, *tok;

    tok = strtok(judge, " ");
    id = atoi(tok);

    tok = strtok(NULL, " ");
    problem = atoi(tok);

    tok = strtok(NULL, " ");
    submission_time = atoi(tok);

    tok = strtok(NULL, " ");
    result = tok[0];

    if (checkParticipation[id] == false)
    {
        contestants.push_back({id, 0, 0});
        checkParticipation[id] = true;
    }

    if (!isSolved[id][problem])
    {
        for (auto it = contestants.begin(); it != contestants.end(); it++)
        {
            if ((*it).id == id)
            {
                if (result == 'C')
                {
                    (*it).solved++;
                    isSolved[id][problem] = true;
                    (*it).penalty += submission_time;
                }
                else if (result == 'I')
                {
                    tryCount[id][problem]++;
                }
                return;
            }
        }
    }
}

void calculatePenalty()
{
    for (auto it = contestants.begin(); it != contestants.end(); it++)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (isSolved[(*it).id][i])
                (*it).penalty += 20 * tryCount[(*it).id][i];
        }
    }
}

int main(void)
{
    int tc;
    char buffer[64];

    scanf("%d ", &tc);
    while (tc--)
    {
        contestants.clear();
        memset(checkParticipation, 0, sizeof(checkParticipation));
        memset(isSolved, 0, sizeof(isSolved));
        memset(tryCount, 0, sizeof(tryCount));

        while ((fgets(buffer, 64, stdin) != NULL) && isdigit(buffer[0]))
            addJudge(buffer);
        calculatePenalty();

        sort(contestants.begin(), contestants.end(), contest_cmp);

        for (auto it = contestants.begin(); it != contestants.end(); it++)
            printf("%d %d %d\n", (*it).id, (*it).solved, (*it).penalty);

        if (tc != 0)
            putchar('\n');
    }
}