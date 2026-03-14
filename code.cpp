#include <iostream>
using namespace std;
int winner(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return 1;
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return 1;
    return 0;
}
int check(char board[3][3], int pos)
{
    if (board[(pos - 1) / 3][(pos - 1) % 3] == pos + '0')
    {

        return 1;
    }
    return 0;
}
void display_on_game(char board[3][3], int x, char z)
{
    board[(x - 1) / 3][(x - 1) % 3] = z;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";
            if (j < 2)
                cout << " | " << " ";
        }
        cout << endl;
        for (int j = 0; j < 3; j++)
        {
            if (i < 2)
                cout << "------";
        }
        cout << endl;
    }
}

void display(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";
            if (j < 2)
                cout << " | " << " ";
        }
        cout << endl;
        for (int j = 0; j < 3; j++)
        {
            if (i < 2)
                cout << "------";
        }
        cout << endl;
    }
}
int main()
{
    int start, ply1 = 0, ply2 = 0;
    cout << "To enter the game press 1 or exit press 0 and show final result" << endl;
    cin >> start;
    if(start==0){
            cout<<"Player first winning score is "<<ply1<<endl;
            cout<<"Player second winning score is "<<ply2<<endl;
        }
    while (start == 1)
    {
        cout << endl;
        cout << "************** Game Start **************" << endl;
       
        char board[3][3], n = '0';
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ++n;
            }
        }
        display(board);
        for (int i = 0; i < 9; i++)
        {
            if (i % 2 == 0)
            {
                int pos;

                cout << "Player 1 --> Enter the number you want to put 'X'" << endl;
                cin >> pos;
                if (pos >= 1 && pos <= 9)
                {
                    if (!check(board, pos))
                    {
                        cout << "The position is already used look carefully toward board" << endl;
                        i--;
                    }
                    else
                        display_on_game(board, pos, 'X');
                }
                else
                {
                    cout << "Enter the valid number " << endl;
                    i--;
                    continue;
                }
                if (winner(board))
                {
                    cout << "Winner is player 1" << endl;
                    ply1++;
                    break;
                }
            }
            else
            {
                int pos;
                cout << "Player 2 --> Enter the number you want to put 'O'" << endl;
                cin >> pos;
                if (pos >= 1 && pos <= 9)
                {
                    if (!check(board, pos))
                    {
                        cout << "The position is already used look carefully toward board" << endl;
                        i--;
                    }
                    else
                        display_on_game(board, pos, 'O');
                }
                else
                {
                    cout << "Enter the valid number " << endl;
                    i--;
                    continue;
                }
                if (winner(board))
                {
                    cout << "Winner is player 2"<<endl;
                    ply2++;
                    break;
                }
            }
            if (i == 8 && !winner(board))
                cout << "Game Draw" << endl;
        }
        cout<<"To play again press 1 or 0 for exits and full result"<<endl;
        cin>>start;
        while(start!=0 &&  start!=1){
            cout<<"Enter the valid number"<<endl;

            cin>>start;
            
        }
        if(start==0){
            cout<<"Player first winning score is "<<ply1<<endl;
            cout<<"Player second winning score is "<<ply2<<endl;
            break;
        }
       
    }
    

    return 0;
}
