#include <iostream>
#include <vector>

using namespace std;

bool checksudokuO(vector<vector<char>> board, int i, int j, bool* hs)
{
    int x = i;
    int y = j;
        for(int i = x; i< x+3; i++ )
        {
            for(int j = y; j< y +3; j++)
            {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '1';
                if(hs[num]) return false;
                hs[num] = true;
            }
        }
        return true;
}
bool checksudokuHang(vector<vector<char>> board, int i, bool* hs)
{
    for(int j=0; j < 9; j++)
    {
        if(board[i][j] == '.') continue;;
        
        int num = board[i][j] -'1';

        if(hs[num]) return false;
        hs[num] = true;
    }
    return true;
}
bool checksudokuCot(vector<vector<char>>board, int j, bool *hs)
{
    for(int i=0; i < 9; i++)
    {
        if(board[i][j] == '.') continue;;
        
        int num = board[i][j] -'1';

        if(hs[num]) return false;
        hs[num] = true;
    }
    return true;
}
bool isValidSudoku(vector<vector<char>>& board)
{
    bool* hs = new bool[9]{false};
    for(int i = 0 ; i < 7 ; i=i+3)
    {
        fill(hs, hs + 9, false);
        if(!checksudokuO(board, i, 0, hs)) return false;

        fill(hs, hs + 9, false);
        if(!checksudokuO(board, i, 3, hs)) return false;

        fill(hs, hs + 9, false);
        if(!checksudokuO(board, i, 6, hs)) return false;
    }
    for(int i = 0; i< 9; i++)
    {
        fill(hs, hs + 9, false);
        if(!checksudokuHang(board, i, hs)) return false;
    }
    for(int j = 0; j< 9; j++)
    {
        fill(hs, hs + 9, false);
        if(!checksudokuCot(board, j, hs)) return false;
    }
    return true;


}
int main()
{
    vector<vector<char>> board(9, vector<char>(9));
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9 ; j++)
        {
            cin >> board[i][j];
        }

    }
    if(isValidSudoku(board)) cout << "true";
    else cout << "false";

    
}