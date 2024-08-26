
#include <iostream>
#include <map>
#include <vector>


using namespace std;

// N is the size of the 2D matrix   N*N
#define N 9
int n = 3;    // sqrt(N);


void print(char arr[N][N])
{

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;

    }
}
bool isSafe(char grid[N][N], int row, int col, char num);    // we'll use it below

vector<char> allowedValues(char board[N][N],int row,int col)
{
    char allowed[] = "123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<char> numbersList;

    for(int v = 0; v < N; ++v)
    {

        if(isSafe(board, row, col, allowed[v]))
        {
            numbersList.push_back(allowed[v]);
        }
           
    }
    return numbersList;
}

map<tuple<int,int>, vector<char>> cacheValidValues(char board[N][N])
{

    map<tuple<int,int>, vector<char>> cache;
    for(int i=0; i<N; i++)
    {

        for(int j=0; j<N; j++)
        {
            if (board[i][j] == '0')
            {
                tuple<int, int> pos= make_tuple(i,j);
                cache[pos] = allowedValues(board,i,j);
            }
        }
    }
    return cache;
}


// Checks whether it will be legal to assign num to given row, col
bool isSafe(char grid[N][N], int row, int col, char num)
{

    // Check if we find the same num in the similar row, we return false
    for (int x = 0; x < N; x++)
    {
        if (grid[row][x] == num)
        {
            return false;
        }
    }
        
    // Check if we find the same num in the similar column, we return false
    for (int x = 0; x < N; x++)
    {
        if (grid[x][col] == num)
        {
            return false;
        }
    }
        
    // Check if we find the same num in the particular n*n matrix, we return false
    int startRow = row - row % n,
    startCol = col - col % n;

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
            
    }
        
    return true;
}

//Takes a partially filled-in grid and attempts to assign values to all unassigned locations
bool solveSudoku(char grid[N][N], int row, int col, map<tuple<int,int>,vector<char>> &cache)
{

    // Check if we have reached the 15th row and 16th column
    if (row == N - 1 && col == N)
    {
        return true;
    }
        
    // Check if column value  becomes N , we move to next row and column start from 0
    if (col == N)
    {
        row++;
        col = 0;
    }

    // Check if the current position of the grid already contains value >0, we iterate for next column
    if (grid[row][col] != '0')
    {
        return solveSudoku(grid, row, col + 1,cache);
    }

    // vector<char> newallowed;
    // cache[make_tuple(row,col)]=newallowed;


    // for (char n:newallowed){
        for (char n:cache[make_tuple(row,col)])
        {
        // Check if it is safe to place the num (1-9) or A to G  in the given row ,col  ->we move to next column
        if (isSafe(grid, row, col, n))
        {

           /* Assigning the num in the current (row,col) position of the grid and assuming our assigned
              num in the position is correct */
            grid[row][col] = n;

            //  Checking for next possibility with next column
            if (solveSudoku(grid, row, col + 1, cache))
                return true;
        }


        // Removing the assigned num , since our assumption was wrong , and we go for next assumption with diff num value
        grid[row][col] = '0';
        }

    return false;
}

// Driver Code
int main()
{
    // 0 means unassigned cells

    char board[N][N];
    for(int i = 0; i < N; i++)
    {
          for(int j = 0; j < N; j++)
          {
            do
              cin>>board[i][j];
            while(board[i][j] == ' ' || board[i][j] == '\n');
          }
    }

    map<tuple<int,int>, vector<char>> cache= cacheValidValues(board);

    if(solveSudoku(board, 0, 0,cache))
    {
        print(board);
    }
    else
    {
        cout << "No Solution" << endl;
    }

    return 0;

}