/* Author: Akshat Agarwal */

#include <iostream>
#include<cstdlib>
#include<iomanip>
#include<windows.h>
using namespace std;


class basec
{
    protected: char square[10];

    public : virtual int checkwin()
             {
                 cout<<"";
             }
             virtual void board()
             {
                 cout<<"";
             }
};

class tic_tac:public basec
{
    public: tic_tac()
             {
                 square[0]='o';
                 square[1]='1';
                 square[2]='2';
                 square[3]='3';
                 square[4]='4';
                 square[5]='5';
                 square[6]='6';
                 square[7]='7';
                 square[8]='8';
                 square[9]='9';
             }

            int checkwin();
            void board();
            friend void game(tic_tac t);
            friend ostream & operator<<(ostream & output,tic_tac &);

};

void game(tic_tac t)
{

	int player = 1,i,choice,z=0;

	char mark;
	do
	{
		t.board();
		if((z%2)==0)
        {
            system("color f1");
            z++;
        }
        else
        {
            system("color f4");
            z++;
        }
		player=(player%2)?1:2;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;
		if(cin.fail())
        {
            cin.clear();
            cin.ignore(100,'\n');
            choice=29;
        }

		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && t.square[1] == '1')

			t.square[1] = mark;
		else if (choice == 2 && t.square[2] == '2')

			t.square[2] = mark;
		else if (choice == 3 && t.square[3] == '3')

			t.square[3] = mark;
		else if (choice == 4 && t.square[4] == '4')

			t.square[4] = mark;
		else if (choice == 5 && t.square[5] == '5')

			t.square[5] = mark;
		else if (choice == 6 && t.square[6] == '6')

			t.square[6] = mark;
		else if (choice == 7 && t.square[7] == '7')

			t.square[7] = mark;
		else if (choice == 8 && t.square[8] == '8')

			t.square[8] = mark;
		else if (choice == 9 && t.square[9] == '9')

			t.square[9] = mark;
		else
		{
			cout<<"Invalid move ";
            z--;
			player--;
			Sleep(200);
		}
		i=t.checkwin();

		player++;
	}while(i==-1);
	t.board();
	if(i==1)

		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
}

ostream & operator<<(ostream & output,tic_tac &intro)
{
    output<<"Topic        :  TIC TAC TOE Game\n";
    output<<"Made by      :  \n";
    output<<"\nconcepts used:  1.Class\n\t\t2.Inheritance\n\t\t3.Operator Overloading\n\t\t4.Friend Function";
    output<<"\n\t\t5.Abstract Class\n\t\t6.Virtual Function\n\t\t7.Polymorphism\n\t\t8.Constructor\n";
    output<<"\npress enter to continue";
    return output;

}

int tic_tac::checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}

void tic_tac::board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}

int main(void)
{
    char s[60];
    int size=50;
    tic_tac t;
    tic_tac intro;
    system("color 3f");
    cout<<intro;
    cin.getline(s,size);
    system("cls");
    cout<<"\t\t\tRULES\n";
    cout<<"\t\t\t-----\n\n";
    cout<<"1. The game is played on a grid that's 3 squares by 3 squares.\n";
    cout<<"\n2. one player is X, other player is O. Players take turns putting their marks in respective numbered squares.\n";
    cout<<"\n3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n";
    cout<<"\n4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n";
    cout<<"\n\n\t Press enter to start the game";
    cin.getline(s,size);
    {
        cout<<"\n\n\n\t\t\t\t\tPlease wait while loading\n\n";
        char a=177, b=219;
        cout<<"\t\t\t\t\t";
        for (int i=0;i<=15;i++)
        cout<<a;
        cout<<"\r";
        cout<<"\t\t\t\t\t";
        for (int i=0;i<=15;i++)
        {
            cout<<b;
            Sleep(70);
        }
    }
    game(t);
    return 0;

}
