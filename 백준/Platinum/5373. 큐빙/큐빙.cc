#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

int map_[12][9] =
{
	0,0,0,4,4,4,0,0,0,
	0,0,0,4,4,4,0,0,0,
	0,0,0,4,4,4,0,0,0,
	5,5,5,1,1,1,6,6,6,
	5,5,5,1,1,1,6,6,6,
	5,5,5,1,1,1,6,6,6,
	0,0,0,3,3,3,0,0,0,
	0,0,0,3,3,3,0,0,0,
	0,0,0,3,3,3,0,0,0,
	0,0,0,2,2,2,0,0,0,
	0,0,0,2,2,2,0,0,0,
	0,0,0,2,2,2,0,0,0
};

int ttt[12][9] =
{
	0,0,0,4,4,4,0,0,0,
	0,0,0,4,4,4,0,0,0,
	0,0,0,4,4,4,0,0,0,
	5,5,5,1,1,1,6,6,6,
	5,5,5,1,1,1,6,6,6,
	5,5,5,1,1,1,6,6,6,
	0,0,0,3,3,3,0,0,0,
	0,0,0,3,3,3,0,0,0,
	0,0,0,3,3,3,0,0,0,
	0,0,0,2,2,2,0,0,0,
	0,0,0,2,2,2,0,0,0,
	0,0,0,2,2,2,0,0,0
};




void rotate_plus(int y,int x) //시계
{
	int temp[3][3] = { 0, };
	for (int i = y; i < y+3; i++)
	{
		for (int j = x; j < x+3; j++)
		{
			temp[i - y][j - x] = map_[i][j];
		}
	}

	for (int i = 0; i <3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			map_[i + y][j + x] = temp[2-j][i];
		}
	}

}

void rotate_minus(int y, int x) //반시계
{
	int temp[3][3] = { 0, };
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			temp[i - y][j - x] = map_[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			map_[i + y][j + x] = temp[j][2 - i];
		}
	}

}
//w=1 y=2 r=3 o=4 g=5 b=6 
/*
int map_[12][9] =
{
	0,0,0,4,4,4,0,0,0,
	0,0,0,4,4,4,0,0,0,
	0,0,0,4,4,4,0,0,0,
	5,5,5,1,1,1,6,6,6,
	5,5,5,1,1,1,6,6,6,
	5,5,5,1,1,1,6,6,6,
	0,0,0,3,3,3,0,0,0,
	0,0,0,3,3,3,0,0,0,
	0,0,0,3,3,3,0,0,0,
	0,0,0,2,2,2,0,0,0,
	0,0,0,2,2,2,0,0,0,
	0,0,0,2,2,2,0,0,0
};*/

int main()
{
	int T;
	cin >> T;
	string temp;
	
	for (int t = 0; t < T; t++)
	{
		copy(&ttt[0][0], &ttt[0][0] + 108, &map_[0][0]);

		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> temp;

			if (temp == "U+")
			{
				vector<int> t;
				t.push_back(map_[2][3]);
				t.push_back(map_[2][4]);
				t.push_back(map_[2][5]);

				t.push_back(map_[3][6]);
				t.push_back(map_[4][6]);
				t.push_back(map_[5][6]);

				t.push_back(map_[6][5]);
				t.push_back(map_[6][4]);
				t.push_back(map_[6][3]);

				t.push_back(map_[5][2]);
				t.push_back(map_[4][2]);
				t.push_back(map_[3][2]);

				map_[3][6] = t[0];
				map_[4][6] = t[1];
				map_[5][6] = t[2];

				map_[6][5] = t[3];
				map_[6][4] = t[4];
				map_[6][3] = t[5];

				map_[5][2] = t[6];
				map_[4][2] = t[7];
				map_[3][2] = t[8];

				map_[2][3] = t[9];
				map_[2][4] = t[10];
				map_[2][5] = t[11];



				rotate_plus(3, 3);
			}
			else if (temp == "U-")
			{
				vector<int> t;
				t.push_back(map_[2][3]);
				t.push_back(map_[2][4]);
				t.push_back(map_[2][5]);

				t.push_back(map_[3][6]);
				t.push_back(map_[4][6]);
				t.push_back(map_[5][6]);

				t.push_back(map_[6][5]);
				t.push_back(map_[6][4]);
				t.push_back(map_[6][3]);

				t.push_back(map_[5][2]);
				t.push_back(map_[4][2]);
				t.push_back(map_[3][2]);

				map_[5][2] = t[0];
				map_[4][2] = t[1];
				map_[3][2] = t[2];

				map_[2][3] = t[3];
				map_[2][4] = t[4];
				map_[2][5] = t[5];

				map_[3][6] = t[6];
				map_[4][6] = t[7];
				map_[5][6] = t[8];

				map_[6][5] = t[9];
				map_[6][4] = t[10];
				map_[6][3] = t[11];


				rotate_minus(3, 3);
			}

			else if (temp == "L+")
			{
				vector<int> t;
				t.push_back(map_[0][3]);
				t.push_back(map_[1][3]);
				t.push_back(map_[2][3]);

				t.push_back(map_[3][3]);
				t.push_back(map_[4][3]);
				t.push_back(map_[5][3]);

				t.push_back(map_[6][3]);
				t.push_back(map_[7][3]);
				t.push_back(map_[8][3]);

				t.push_back(map_[9][3]);
				t.push_back(map_[10][3]);
				t.push_back(map_[11][3]);

				map_[3][3] = t[0];
				map_[4][3] = t[1];
				map_[5][3] = t[2];

				map_[6][3] = t[3];
				map_[7][3] = t[4];
				map_[8][3] = t[5];

				map_[9][3] = t[6];
				map_[10][3] = t[7];
				map_[11][3] = t[8];

				map_[0][3] = t[9];
				map_[1][3] = t[10];
				map_[2][3] = t[11];


				rotate_plus(3, 0);
			}

			else if (temp == "L-")
			{
				vector<int> t;
				t.push_back(map_[0][3]);
				t.push_back(map_[1][3]);
				t.push_back(map_[2][3]);

				t.push_back(map_[3][3]);
				t.push_back(map_[4][3]);
				t.push_back(map_[5][3]);

				t.push_back(map_[6][3]);
				t.push_back(map_[7][3]);
				t.push_back(map_[8][3]);

				t.push_back(map_[9][3]);
				t.push_back(map_[10][3]);
				t.push_back(map_[11][3]);

				map_[9][3] = t[0];
				map_[10][3] = t[1];
				map_[11][3] = t[2];

				map_[0][3] = t[3];
				map_[1][3] = t[4];
				map_[2][3] = t[5];

				map_[3][3] = t[6];
				map_[4][3] = t[7];
				map_[5][3] = t[8];

				map_[6][3] = t[9];
				map_[7][3] = t[10];
				map_[8][3] = t[11];


				rotate_minus(3, 0);
			}

			else if (temp == "R+")
			{
				vector<int> t;
				t.push_back(map_[0][5]);
				t.push_back(map_[1][5]);
				t.push_back(map_[2][5]);

				t.push_back(map_[3][5]);
				t.push_back(map_[4][5]);
				t.push_back(map_[5][5]);

				t.push_back(map_[6][5]);
				t.push_back(map_[7][5]);
				t.push_back(map_[8][5]);

				t.push_back(map_[9][5]);
				t.push_back(map_[10][5]);
				t.push_back(map_[11][5]);

				map_[9][5] = t[0];
				map_[10][5] = t[1];
				map_[11][5] = t[2];

				map_[0][5] = t[3];
				map_[1][5] = t[4];
				map_[2][5] = t[5];

				map_[3][5] = t[6];
				map_[4][5] = t[7];
				map_[5][5] = t[8];

				map_[6][5] = t[9];
				map_[7][5] = t[10];
				map_[8][5] = t[11];


				rotate_plus(3, 6);
			}

			else if (temp == "R-")
			{
				vector<int> t;
				t.push_back(map_[0][5]);
				t.push_back(map_[1][5]);
				t.push_back(map_[2][5]);

				t.push_back(map_[3][5]);
				t.push_back(map_[4][5]);
				t.push_back(map_[5][5]);

				t.push_back(map_[6][5]);
				t.push_back(map_[7][5]);
				t.push_back(map_[8][5]);

				t.push_back(map_[9][5]);
				t.push_back(map_[10][5]);
				t.push_back(map_[11][5]);

				map_[3][5] = t[0];
				map_[4][5] = t[1];
				map_[5][5] = t[2];

				map_[6][5] = t[3];
				map_[7][5] = t[4];
				map_[8][5] = t[5];

				map_[9][5] = t[6];
				map_[10][5] = t[7];
				map_[11][5] = t[8];

				map_[0][5] = t[9];
				map_[1][5] = t[10];
				map_[2][5] = t[11];


				rotate_minus(3, 6);
			}

			else if (temp == "F+")
			{
				vector<int> t;
				t.push_back(map_[5][0]);
				t.push_back(map_[5][1]);
				t.push_back(map_[5][2]);

				t.push_back(map_[5][3]);
				t.push_back(map_[5][4]);
				t.push_back(map_[5][5]);

				t.push_back(map_[5][6]);
				t.push_back(map_[5][7]);
				t.push_back(map_[5][8]);

				t.push_back(map_[9][3]);
				t.push_back(map_[9][4]);
				t.push_back(map_[9][5]);

				map_[5][3] = t[0];
				map_[5][4] = t[1];
				map_[5][5] = t[2];

				map_[5][6] = t[3];
				map_[5][7] = t[4];
				map_[5][8] = t[5];

				map_[9][5] = t[6];
				map_[9][4] = t[7];
				map_[9][3] = t[8];

				map_[5][2] = t[9];
				map_[5][1] = t[10];
				map_[5][0] = t[11];


				rotate_plus(6, 3);
			}

			else if (temp == "F-")
			{
				vector<int> t;
				t.push_back(map_[5][0]);
				t.push_back(map_[5][1]);
				t.push_back(map_[5][2]);

				t.push_back(map_[5][3]);
				t.push_back(map_[5][4]);
				t.push_back(map_[5][5]);

				t.push_back(map_[5][6]);
				t.push_back(map_[5][7]);
				t.push_back(map_[5][8]);

				t.push_back(map_[9][3]);
				t.push_back(map_[9][4]);
				t.push_back(map_[9][5]);

				map_[9][5] = t[0];
				map_[9][4] = t[1];
				map_[9][3] = t[2];

				map_[5][0] = t[3];
				map_[5][1] = t[4];
				map_[5][2] = t[5];

				map_[5][3] = t[6];
				map_[5][4] = t[7];
				map_[5][5] = t[8];

				map_[5][8] = t[9];
				map_[5][7] = t[10];
				map_[5][6] = t[11];


				rotate_minus(6, 3);
			}

			else if (temp == "B+")
			{
				vector<int> t;
				t.push_back(map_[3][8]);
				t.push_back(map_[3][7]);
				t.push_back(map_[3][6]);

				t.push_back(map_[3][5]);
				t.push_back(map_[3][4]);
				t.push_back(map_[3][3]);

				t.push_back(map_[3][2]);
				t.push_back(map_[3][1]);
				t.push_back(map_[3][0]);

				t.push_back(map_[11][3]);
				t.push_back(map_[11][4]);
				t.push_back(map_[11][5]);

				map_[3][5] = t[0];
				map_[3][4] = t[1];
				map_[3][3] = t[2];

				map_[3][2] = t[3];
				map_[3][1] = t[4];
				map_[3][0] = t[5];

				map_[11][3] = t[6];
				map_[11][4] = t[7];
				map_[11][5] = t[8];

				map_[3][8] = t[9];
				map_[3][7] = t[10];
				map_[3][6] = t[11];


				rotate_plus(0, 3);
			}

			else if (temp == "B-")
			{
				vector<int> t;
				t.push_back(map_[3][8]);
				t.push_back(map_[3][7]);
				t.push_back(map_[3][6]);

				t.push_back(map_[3][5]);
				t.push_back(map_[3][4]);
				t.push_back(map_[3][3]);

				t.push_back(map_[3][2]);
				t.push_back(map_[3][1]);
				t.push_back(map_[3][0]);

				t.push_back(map_[11][3]);
				t.push_back(map_[11][4]);
				t.push_back(map_[11][5]);

				map_[11][3] = t[0];
				map_[11][4] = t[1];
				map_[11][5] = t[2];

				map_[3][8] = t[3];
				map_[3][7] = t[4];
				map_[3][6] = t[5];

				map_[3][5] = t[6];
				map_[3][4] = t[7];
				map_[3][3] = t[8];

				map_[3][2] = t[9];
				map_[3][1] = t[10];
				map_[3][0] = t[11];


				rotate_minus(0, 3);
			}

			else if (temp == "D+")
			{
				vector<int> t;
				t.push_back(map_[8][3]);
				t.push_back(map_[8][4]);
				t.push_back(map_[8][5]);

				t.push_back(map_[5][8]);
				t.push_back(map_[4][8]);
				t.push_back(map_[3][8]);

				t.push_back(map_[0][5]);
				t.push_back(map_[0][4]);
				t.push_back(map_[0][3]);

				t.push_back(map_[3][0]);
				t.push_back(map_[4][0]);
				t.push_back(map_[5][0]);

				map_[5][8] = t[0];
				map_[4][8] = t[1];
				map_[3][8] = t[2];

				map_[0][5] = t[3];
				map_[0][4] = t[4];
				map_[0][3] = t[5];

				map_[3][0] = t[6];
				map_[4][0] = t[7];
				map_[5][0] = t[8];

				map_[8][3] = t[9];
				map_[8][4] = t[10];
				map_[8][5] = t[11];


				rotate_plus(9, 3);
			}

			else if (temp == "D-")
			{
				vector<int> t;
				t.push_back(map_[8][3]);
				t.push_back(map_[8][4]);
				t.push_back(map_[8][5]);

				t.push_back(map_[5][8]);
				t.push_back(map_[4][8]);
				t.push_back(map_[3][8]);

				t.push_back(map_[0][5]);
				t.push_back(map_[0][4]);
				t.push_back(map_[0][3]);

				t.push_back(map_[3][0]);
				t.push_back(map_[4][0]);
				t.push_back(map_[5][0]);

				map_[3][0] = t[0];
				map_[4][0] = t[1];
				map_[5][0] = t[2];

				map_[8][3] = t[3];
				map_[8][4] = t[4];
				map_[8][5] = t[5];

				map_[5][8] = t[6];
				map_[4][8] = t[7];
				map_[3][8] = t[8];

				map_[0][5] = t[9];
				map_[0][4] = t[10];
				map_[0][3] = t[11];


				rotate_minus(9, 3);
			}




		}
		/*
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d ", map_[i][j]);
			}
			printf("\n");
		}*/


		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{

				if (map_[i][j] == 1)
				{
					printf("w");
				}
				else if (map_[i][j] == 2)
				{
					printf("y");
				}
				else if (map_[i][j] == 3)
				{
					printf("r");
				}
				else if (map_[i][j] == 4)
				{
					printf("o");
				}
				else if (map_[i][j] == 5)
				{
					printf("g");
				}
				else if (map_[i][j] == 6)
				{
					printf("b");
				}


			}
			printf("\n");
		}
	}
}

//w=1 y=2 r=3 o=4 g=5 b=6 