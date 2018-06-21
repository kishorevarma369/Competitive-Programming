#include <bits/stdc++.h>

using namespace std;
int cou;

char valueat(vector < vector<char> > &board,int i,int j)
{
  if(i<0||i>7||j<0||j>7) return '#';
  return board[i][j];
}

void night_check(vector < vector<char> > &board,int i,int j)
{
  if(valueat(board,i+1,j-2)=='k') cou++;
  else if(valueat(board,i+1,j+2)=='k') cou++;
  else if(valueat(board,i+2,j+1)=='k') cou++;
  else if(valueat(board,i+2,j-1)=='k') cou++;
}

void rook_check(vector < vector<char> > &board,int i,int j)
{
  for(int k=j+1;k<8;k++)
  {
    if(board[i][k]!='#')
    {
      if(board[i][k]=='k') cou+=2;
      break;
    }
  }
  for(int k=j-1;k>=0;k--)
  {
    if(board[i][k]!='#')
    {
      if(board[i][k]=='k') cou+=2;
      break;
    }
  }
  for(int k=i+1;k<8;k++)
  {
    if(board[k][j]!='#')
    {
      if(board[i][k]=='k') cou+=2;
      break;
    }
  }
}

void bishop_check(vector < vector<char> > &board,int i,int j)
{
  int k=i+1,l=j+1;
  for(;k<8&&l<8;k++,l++)
  {
    if(board[k][l]!='#')
    {
      if(board[k][l]=='k') cou+=2;
      break;
    }
  }
  k=i+1;
  l=j-1;
  for(;k<8&&l>=0;k++,l--)
  {
    if(board[k][l]!='#')
    {
      if(board[k][l]=='k') cou+=2;
      break;
    }
  }
}

int waysToGiveACheck(vector < vector<char> >& board)
{
  cou=0;
  int i=1,j=0,k;
  for(;j<8;j++)
  {
    if(board[i][j]=='P')
    {
      board[i][j]='#';
      if(board[0][j]=='#')
      {
        night_check(board,0,j);
        bishop_check(board,0,j);
        rook_check(board,0,j);
      }
      board[i][j]='P';
    }
  }
  return cou;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        vector< vector<char> > board(8,vector<char>(8));
        for(int board_i = 0;board_i < 8;board_i++){
           for(int board_j = 0;board_j < 8;board_j++){
              cin >> board[board_i][board_j];
           }
        }
        int result = waysToGiveACheck(board);
        cout << result << endl;
    }
    return 0;
}
