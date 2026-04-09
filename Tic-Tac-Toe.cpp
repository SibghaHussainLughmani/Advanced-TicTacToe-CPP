
using namespace std;

int main()
{
    char board[3][3];
    int choice;
    int scoreX = 0, scoreO = 0;

    while (true)
    {
        cout << "\n====== TIC TAC TOE ======\n";
        cout << "1. Start Game\n";
        cout << "2. Instructions\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3)
        {
            cout << "Exiting game...\n";
            break;
        }

        if (choice == 2)
        {
            cout << "\nINSTRUCTIONS:\n";
            cout << "- Players take turns (X and O)\n";
            cout << "- Enter row and column (1-3)\n";
            cout << "- First to align 3 wins\n";
            cout << "- Rows, Columns, Diagonals count\n";
            continue;
        }

        // Initialize board
        char num = '1';
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = num++;
            }
        }

        char player = 'X';
        int moves = 0;
        bool win = false;

        while (!win && moves < 9)
        {
            // Display Scoreboard
            cout << "\nScoreboard:\n";
            cout << "Player X: " << scoreX << "  |  Player O: " << scoreO << endl;

            // Display Board
            cout << "\nCurrent Board:\n";
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << " " << board[i][j];
                    if (j < 2) cout << " |";
                }
                cout << endl;
                if (i < 2) cout << "---|---|---\n";
            }

            cout << "\nGame State: RUNNING\n";
            cout << "Player " << player << " turn\n";

            int row, col;
            cout << "Enter row (1-3) and column (1-3): ";
            cin >> row >> col;

            row--; col--;

            // Validation
            if (row < 0 || row > 2 || col < 0 || col > 2 ||
                board[row][col] == 'X' || board[row][col] == 'O')
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[row][col] = player;
            moves++;

            // Check Win
            for (int i = 0; i < 3; i++)
            {
                if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                    (board[0][i] == player && board[1][i] == player && board[2][i] == player))
                {
                    win = true;
                }
            }

            if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
                (board[0][2] == player && board[1][1] == player && board[2][0] == player))
            {
                win = true;
            }

            if (win)
            {
                cout << "\n?? Player " << player << " WINS!\n";
                cout << "Game State: WIN\n";

                if (player == 'X') scoreX++;
                else scoreO++;
            }
            else if (moves == 9)
            {
                cout << "\nGame is DRAW!\n";
                cout << "Game State: DRAW\n";
            }
            else
            {
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        // Final Board
        cout << "\nFinal Board:\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << " " << board[i][j];
                if (j < 2) cout << " |";
            }
            cout << endl;
            if (i < 2) cout << "---|---|---\n";
        }

        int again;
        cout << "\n1. Play Again\n2. Back to Menu\nEnter choice: ";
        cin >> again;

        if (again == 1)
            continue;
    }

    cout << "\nFinal Scores:\n";
    cout << "Player X: " << scoreX << endl;
    cout << "Player O: " << scoreO << endl;

    cout << "Thanks for playing!\n";
    return 0;
}

