#include <iostream>
#include "Board.h"
using namespace std;
void Board::Init()
{
	for (int y = 0; y < 18; ++y)
	{
		for (int x = 0; x < 27; ++x)
		{
			_board[y][x] = new Piece;
			_board[y][x]->SetPos({ x, y });
		}
	}
	for (int y = 0; y < 18; ++y)
	{
		for (int x = 0; x < 27; ++x)
		{
			if (x < 25 && y < 17)
			{
				if (x % 3 == 0)
				{
					if (y % 2 == 0)
						_board[y][x]->SetShape(32);
					else
						_board[y][x]->SetShape(124);
				}
				else if (y % 2 == 0)
				{
					_board[y][x]->SetShape(45);
				}
				else
					_board[y][x]->SetShape(32);
			}
			else
				_board[y][x]->SetShape(32);
		}
	}
	char alphabet = 65;
	for (int i = 1; i < 23; i += 3)
	{
		_board[17][i]->SetShape(alphabet);
		alphabet++;
	}
	int num = 56;
	for (int i = 1; i < 17; i += 2)
	{
		_board[i][26]->SetShape(num);
		num--;
	}

	_board[1][1]->SetShape('B');
	_board[1][2]->SetShape('R');
	_board[1][1]->SetTeam(Team::Black);
	_board[1][1]->SetType(PieceType::Rook);

	_board[1][4]->SetShape('B');
	_board[1][5]->SetShape('N');
	_board[1][4]->SetTeam(Team::Black);
	_board[1][4]->SetType(PieceType::Knight);

	_board[1][7]->SetShape('B');
	_board[1][8]->SetShape('B');
	_board[1][7]->SetTeam(Team::Black);
	_board[1][7]->SetType(PieceType::Bishop);

	_board[1][10]->SetShape('B');
	_board[1][11]->SetShape('K');
	_board[1][10]->SetTeam(Team::Black);
	_board[1][10]->SetType(PieceType::King);

	_board[1][13]->SetShape('B');
	_board[1][14]->SetShape('Q');
	_board[1][13]->SetTeam(Team::Black);
	_board[1][13]->SetType(PieceType::Queen);

	_board[1][16]->SetShape('B');
	_board[1][17]->SetShape('B');
	_board[1][16]->SetTeam(Team::Black);
	_board[1][16]->SetType(PieceType::Bishop);

	_board[1][19]->SetShape('B');
	_board[1][20]->SetShape('N');
	_board[1][19]->SetTeam(Team::Black);
	_board[1][19]->SetType(PieceType::Knight);

	_board[1][22]->SetShape('B');
	_board[1][23]->SetShape('R');
	_board[1][22]->SetTeam(Team::Black);
	_board[1][22]->SetType(PieceType::Rook);

	for (int i = 1; i < 25; i += 3)
	{
		_board[3][i]->SetShape('B');
		_board[3][i+1]->SetShape('P');
		_board[3][i]->SetTeam(Team::Black);
		_board[3][i]->SetType(PieceType::Pawn);
	}

	_board[15][1]->SetShape('W');
	_board[15][2]->SetShape('R');
	_board[15][1]->SetTeam(Team::Black);
	_board[15][1]->SetType(PieceType::Rook);
			
	_board[15][4]->SetShape('W');
	_board[15][5]->SetShape('N');
	_board[15][4]->SetTeam(Team::White);
	_board[15][4]->SetType(PieceType::Knight);
			
	_board[15][7]->SetShape('W');
	_board[15][8]->SetShape('B');
	_board[15][7]->SetTeam(Team::White);
	_board[15][7]->SetType(PieceType::Bishop);
			
	_board[15][10]->SetShape('W');
	_board[15][11]->SetShape('K');
	_board[15][10]->SetTeam(Team::White);
	_board[15][10]->SetType(PieceType::King);
			
	_board[15][13]->SetShape('W');
	_board[15][14]->SetShape('Q');
	_board[15][13]->SetTeam(Team::White);
	_board[15][13]->SetType(PieceType::Queen);

	_board[15][16]->SetShape('W');
	_board[15][17]->SetShape('B');
	_board[15][16]->SetTeam(Team::White);
	_board[15][16]->SetType(PieceType::Bishop);

	_board[15][19]->SetShape('W');
	_board[15][20]->SetShape('N');
	_board[15][19]->SetTeam(Team::White);
	_board[15][19]->SetType(PieceType::Knight);

	_board[15][22]->SetShape('W');
	_board[15][23]->SetShape('R');
	_board[15][22]->SetTeam(Team::White);
	_board[15][22]->SetType(PieceType::Rook);

	for (int i = 1; i < 25; i += 3)
	{
		_board[13][i]->SetShape('W');
		_board[13][i + 1]->SetShape('P');
		_board[13][i]->SetTeam(Team::White);
		_board[13][i]->SetType(PieceType::Pawn);
	}

}

void Board::Render()
{
	for (int y = 0; y < 18; ++y)
	{
		for (int x = 0; x < 27; ++x)
		{
			cout << _board[y][x]->GetShape();
		}
		cout << endl;
	}
}
