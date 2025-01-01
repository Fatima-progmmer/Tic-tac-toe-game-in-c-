#include <iostream>
using namespace std;


char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// Function to draw the game board
void drawBoard(char board[3][3]) 
{
	cout << "\n\n\t\t\t";
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++)
	 {
	 	cout << "\t\t\t";
	 	cout << "|";
        for (int j = 0; j < 3; j++)
		 {
		 	
            cout << " " << board[i][j] << " ";
            if(j<2)
            cout << "|";
        }
        
        cout << "|";
        cout << endl;
        
        cout << "\t\t\t";
        if (i < 2) 
		{
            cout << "|-----------|" << endl;
        }
    }
    cout << "-------------" << endl;
}

// Function to check for a win
bool checkWin(char board[3][3], char player)
 {
    // Check rows and columns
    for (int i = 0; i < 3; i++)
	 {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
    
    for (int i = 0; i < 3; i++)
    {
    	if (!(board[i][0] == player && board[i][1] == player && board[i][2] == player)) 
        if (!(board[0][i] == player && board[1][i] == player && board[2][i] == player))
        if (!(board[0][0] == player && board[1][1] == player && board[2][2] == player)) 
    if (!(board[0][2] == player && board[1][1] == player && board[2][0] == player))
    cout << "\n\t\t\t No Player Win !!" << endl;
    
	}
}

bool checkDraw(){
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]!='X' && board[i][j]!='0')
			{
				return false;
			}
		}
	}
	return true;
}

int main() {

    char player = 'X';
    int move;
    
    while (true) 
	{
        system("cls"); // clear the console
        cout << "\t\t\t============="<< endl;
		cout << "\t\t\t Tic Tae Toc" << endl;
		cout << "\t\t\t============="<< endl;
        drawBoard(board);
        cout << "\n\tPlayer " << player << ":!\n\t\t Enter your move (1-9): ";
        cin >> move;

        // Validate move
        if (move < 1 || move > 9) 
		{
            cout << "Invalid move, try again." << endl;
            cin.ignore();
            cin.get();
            continue;
        }

        // Convert move to board coordinates
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Check if space is already occupied
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;

            // Check for win
            if (checkWin(board, player)) 
			{
                system("cls");
				cout << "\t\t\t============="<< endl;
				cout << "\t\t\t Tic Tae Toc" << endl;
				cout << "\t\t\t============="<< endl; // clear the console
                drawBoard(board);
                cout << "\n\n\t\t ! Player " << player << " wins!" << endl;
                break;
            }

            // Switch player
            player = (player == 'X') ? 'O' : 'X';
        }
		 else 
		 {
            cout << "\n\n\t\tSpace already occupied, try again." << endl;
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}