#include <iostream>

using namespace std;


int sudoku_size = 9;
int sudoku[10][10];
bool chk_row[10][10];
bool chk_col[10][10]; 
bool chk_square[10][10]; 


// (x,y)가 몇 번째 정사각형(0~8)에 해당하는지 return.
int square(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}

void print_Sudoku()
{
	for (int i = 0; i < sudoku_size; i++)
	{
		for (int j = 0; j < sudoku_size; j++)
		{
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
}

void make_sudoku(int z)
{
	if (z == 81)
	{
		print_Sudoku();
		exit(0);
	}

	int x = z / sudoku_size, y = z % sudoku_size;

	if (sudoku[x][y] != 0)
	{
		make_sudoku(z + 1);
	}
	// 0이 들어가있는 곳이면
	else
	{
		// 들어갈 숫자 찾기
		for (int i = 1; i <= 9; i++)
		{
			// 해당 열, 행, 정사각형 안에 i가 없으면 i를 사용한다
			if (chk_row[x][i] == 0 && chk_col[y][i] == 0 && chk_square[square(x, y)][i] == 0)
			{
				chk_row[x][i] = chk_col[y][i] = chk_square[square(x, y)][i] = true;
				sudoku[x][y] = i;
				make_sudoku(z + 1);
				// 숫자 i가 아니면 백트래킹
				sudoku[x][y] = 0;
				chk_row[x][i] = chk_col[y][i] = chk_square[square(x, y)][i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < sudoku_size; i++)
	{
		for (int j = 0; j < sudoku_size; j++)
		{
			cin >> sudoku[i][j];
			if (sudoku[i][j] != 0)
			{
				// 각 열, 행, 정사각형에 입력된 숫자가 있다고 저장한다.
				chk_row[i][sudoku[i][j]] = true;
				chk_col[j][sudoku[i][j]] = true;
				chk_square[square(i, j)][sudoku[i][j]] = true;
			}
		}
	}

	make_sudoku(0);

	return 0;
}