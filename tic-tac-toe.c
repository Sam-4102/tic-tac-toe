
#include<iostream>

using namespace std;
 
     char board [3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
     int row;
     int column;
     char token='x';
     bool tie=false;
     string n1="";
     string n2="";
     
void functionOne(){

   
    
    
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"     |     |     \n";
}

void functionTwo()
{
    
  int digit;
  if(token=='x')
  {
      cout<<n1<<" please enter your move: ";
      cin>>digit;
  }
  
  if(token=='0')
  {
      cout<<n2<<" please enter your move: ";
      cin>>digit;
  }
  
  
  if(digit==1)
  {
      row=0;
      column=0;
  }
   if(digit==2)
  {
      row=0;
      column=1;
  }
   if(digit==3)
  {
      row=0;
      column=2;
  }
   if(digit==4)
  {
      row=1;
      column=0;
  }
   if(digit==5)
  {
      row=1;
      column=1;
  }
   if(digit==6)
  {
      row=1;
      column=2;
  }
   if(digit==7)
  {
      row=2;
      column=0;
  }
   if(digit==8)
  {
      row=2;
      column=1;
  }
   if(digit==9)
  {
      row=2;
      column=2;
  }
  
  else if(digit<1 || digit>9)
  {
      cout<<"Invalid move !!!"<<endl;
  }
  
  if(token=='x' && board[row][column] !='x' && board[row][column] !='0')
  {
  board[row][column]='x';
  token='0';
  }
  
  else if(token=='0' && board[row][column] !='x' && board[row][column] !='0')
  {
  board[row][column]='0';
  token='x';
  }
  
  else{
      cout<<"there is no empty space!"<<endl;
      functionTwo();
      
      }
}
  
  bool functionThree()
  {
      for(int i=0;i<3;i++)
      {
          if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
          return true;
          
      }
      
       if(board[0][0]==board[1][1] && board[1][1]==board[2][2] || board[0][2]==board[1][1] && board[1][1]==board[2][0])
       {
          return true;
       }
       
       for(int i=0;i<3;i++)
       {
              for(int j=0;j<3;j++)
              {
                if(board[i][j] !='x' && board [i][j] !='0')
                {
                    return false;
                }
              }
       }
       tie=true;
       return false;
       
} 

int main()
{
    cout<<"WELCOME TO TIC-TAC-TOE\n";
    cout<<"(NOTE: Enter your move by the digits given on the board) \n\n";
    cout<<"Enter the name of the first player : \n";
    getline(cin,n1);
    cout<<"Enter the name of the second player : \n";
    getline(cin,n2); 
    cout<< n1 << " will play first  \n";  
    cout<< "and " << n2 << " will play the next  \n";


    while(!functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
        
    }
    
    if(token =='0' && tie == false)
    {
        cout<< " CONGRATULATIONS "<<n1<<", YOU ARE THE WINNER!! "<<endl;
    }
     else if(token =='x' && tie == false)
    {
        cout<< " CONGRATULATIONS "<<n2<<", YOU ARE THE WINNER!! "<<endl;
    }
    else
    {
        cout<<"It's a draw"<<endl;
    }
}

