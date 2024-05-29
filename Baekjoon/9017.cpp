#include <iostream>

using namespace std;

int numberOfTeamMember[201];
int scoreOfTeams[201];
int scoreOfFifthPlayer[201];


int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	while (T--)
	{
		fill_n(numberOfTeamMember, 201, 0);
		fill_n(scoreOfTeams, 201, 0);
		fill_n(scoreOfFifthPlayer, 201, 0);

		int N, t, result = 0;
		int min = INT32_MAX;

		cin >> N;

		for (int i = 1; i <= N; i++)	// i 는 점수.
		{
			cin >> t;		// 팀 번호 입력.

			numberOfTeamMember[t]++;
			
			if (numberOfTeamMember[t] < 5)		// 4명 까지 점수 합산
			{
				scoreOfTeams[t] += i;
			}

			if (numberOfTeamMember[t] == 5)	// 팀 내 5번째 점수 기록.
			{
				scoreOfFifthPlayer[t] = i;
			}
		}
		
		for (int i = 1; i <= 201; i++)
		{
			if (numberOfTeamMember[i] < 6 || scoreOfTeams[i] == 0) continue;
			
			if (scoreOfTeams[i] < min)
			{
				min = scoreOfTeams[i];
				result = i;
			}
			else if (scoreOfTeams[i] == min)
			{
				if (scoreOfFifthPlayer[result] > scoreOfFifthPlayer[i])
				{
					result = i;
				}
			}
		}

		cout << result << '\n';
	}

	return 0;
}