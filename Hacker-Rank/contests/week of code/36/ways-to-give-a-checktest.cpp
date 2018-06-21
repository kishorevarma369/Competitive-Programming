#include <bits/stdc++.h>

using namespace std;
int cou;

char valueat(vector < vector<char> > &board,int i,int j)
{
  if(i<0||i>7||j<0||j>7) return '#';
  return board[i][j];
}

int night_check(vector < vector<char> > &board,int i,int j,char ch)
{
  int p=0;
  if(valueat(board,i+1,j-2)==ch) p++;
  if(valueat(board,i+1,j+2)==ch) p++;
  if(valueat(board,i+2,j+1)==ch) p++;
  if(valueat(board,i+2,j-1)==ch) p++;
  if(valueat(board,i-1,j-2)==ch) p++;
  if(valueat(board,i-1,j+2)==ch) p++;
  if(valueat(board,i-2,j+1)==ch) p++;
  if(valueat(board,i-2,j-1)==ch) p++;
  return p;
}

int king_check(vector < vector<char> > &board,int i,int j,char ch)
{
  int p=0;
  if(valueat(board,i+1,j)==ch) p++;
  if(valueat(board,i-1,j)==ch) p++;
  if(valueat(board,i+1,j+1)==ch) p++;
  if(valueat(board,i+1,j-1)==ch) p++;
  if(valueat(board,i-1,j+1)==ch) p++;
  if(valueat(board,i-1,j-1)==ch) p++;
  if(valueat(board,i,j+1)==ch) p++;
  if(valueat(board,i,j-1)==ch) p++;
  return p;
}

int rook_check(vector < vector<char> > &board,int i,int j,char ch)
{
  int p=0;
  for(int k=j+1;k<8;k++)
  {
    if(board[i][k]!='#')
    {
      if(board[i][k]==ch) p++;
      break;
    }
  }
  for(int k=j-1;k>=0;k--)
  {
    if(board[i][k]!='#')
    {
      if(board[i][k]==ch) p++;
      break;
    }
  }
  for(int k=i+1;k<8;k++)
  {
    if(board[k][j]!='#')
    {
      if(board[k][j]==ch) p++;
      break;
    }
  }
  for(int k=i-1;k>=0;k--)
  {
    if(board[k][j]!='#')
    {
      if(board[k][j]==ch) p++;
      break;
    }
  }
  return p;
}

int bishop_check(vector < vector<char> > &board,int i,int j,char ch)
{
  int k=i+1,l=j+1,p=0;
  for(;k<8&&l<8;k++,l++)
  {
    if(board[k][l]!='#')
    {
      if(board[k][l]==ch) p++;
      break;
    }
  }
  k=i+1;
  l=j-1;
  for(;k<8&&l>=0;k++,l--)
  {
    if(board[k][l]!='#')
    {
      if(board[k][l]==ch) p++;
      break;
    }
  }
  k=i-1;
  l=j-1;
  for(;k>=0&&l>=0;k--,l--)
  {
    if(board[k][l]!='#')
    {
      if(board[k][l]==ch) p++;
      break;
    }
  }
  k=i-1;
  l=j+1;
  for(;k>=0&&l<8;k--,l++)
  {
    if(board[k][l]!='#')
    {
      if(board[k][l]==ch) p++;
      break;
    }
  }
  return p;
}



int valid_move(vector<vector<char>> &board)
{
  int i,j;
  for(i=0;i<8;i++)
  {
    for(j=0;j<8;j++) if(board[i][j]=='K') goto a;
  }
  a:
  if(night_check(board,i,j,'n')) return 0;
  if(rook_check(board,i,j,'r')) return 0;
  if(bishop_check(board,i,j,'b')) return 0;
  if(rook_check(board,i,j,'q')) return 0;
  if(bishop_check(board,i,j,'q')) return 0;
  return 1;
}

int eval_secret(vector < vector<char> >& board)
{
  int i,j,p=0;
  for(i=0;i<8;i++)
  {
    for(j=0;j<8;j++) if(board[i][j]=='k') goto a;
  }
  a:
  p+=night_check(board,i,j,'N');
  p+=rook_check(board,i,j,'R');
  p+=bishop_check(board,i,j,'B');
  p+=rook_check(board,i,j,'Q');
  p+=bishop_check(board,i,j,'Q');
  return p;
}

int threat(vector < vector<char> >& board,int i,int j)
{
  if(night_check(board,i,j,'n')) return 0;
  if(rook_check(board,i,j,'r')) return 0;
  if(bishop_check(board,i,j,'b')) return 0;
  if(rook_check(board,i,j,'q')) return 0;
  if(bishop_check(board,i,j,'q')) return 0;
  if(king_check(board,i,j,'k')) return 0;
  return 1;
}

int validity_check(vector < vector<char> >& board,int i,int j)
{
  if(board[i][j]!='#') return 0;
  char t1,t2;
  t1=valueat(board,i,j-1);
  t2=valueat(board,i,j+1);
  if(t1!='#')
  {
    if(islower(t1))
    {
      if(t1=='r'||t1=='q') return 0;
    }
  }
  if(t2!='#')
  {
    if(islower(t2))
    {
      if(t2=='r'||t2=='q') return 0;
    }
  }
  return 1;
}

int waysToGiveACheck(vector < vector<char> >& board)
{
  int i=1,j=0,cou,k;
  vector<int> opval,flag;
  for(;j<8;j++)
  {
    if(board[i][j]=='P')
    {
      cou=0;
      board[i][j]='#';
      if(validity_check(board,0,j))
      {
        board[0][j]='P';
        if(valid_move(board))
        {
          cou+=night_check(board,0,j,'k');
          cou+=2*bishop_check(board,0,j,'k');
          cou+=2*rook_check(board,0,j,'k');
          if(cou==0)
          {
              opval.push_back(eval_secret(board));
              flag.push_back(threat(board,0,j));
          }
          opval.push_back(cou);
          flag.push_back(threat(board,0,j));
        }
        board[0][j]='#';
      }
      board[i][j]='P';
    }
  }
  k=0;
  for(i=0;i<opval.size();i++)
  {
    if(flag[i])
    {
      if(k<opval[i]) k=opval[i];
    }
  }
  if(k==0)
  {
    for(i=0;i<opval.size();i++)
    {
      if(k<opval[i]) k=opval[i];
    }
  }
  return k;
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
