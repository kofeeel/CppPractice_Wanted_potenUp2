#include <iostream>
#include "Board.h"
Board board;


int main()
{
    
    board.Init();
  
    do
    {
        board.Update();
        board.Render();
    } while (!gameOver);     
}

