#include "TicTacToe.h"


TicTacToe :: TicTacToe(int size) : b(size){ //init line in cpp file
    this->boardSize = size;
    this->setWinner('-');
}


void TicTacToe :: play(Player& xPlayer, Player& oPlayer){
 
    this->setTurn('X');
    this->b = '.';
    xPlayer.myChar = 'X';
    oPlayer.myChar = 'O';
    
    this->xPlayer = &xPlayer;
    this->oPlayer = &oPlayer;
    

    int countX = 0, countO = 0;
    Coordinate coordinate;
    Coordinate c{0,0};
    
    do{
        //X turn
        if(this->getTurn() == 'X'){
            if(typeid(*this->xPlayer) == typeid(ExceptionPlayer)){
                setWinner('O');
                break;
            }
            coordinate = xPlayer.play(this->b);
            
            //illigal player
            if(b[coordinate] != '.'){
                    setWinner('O');
                    break;
            }
            this->b[coordinate] = 'X';
            countX++;
            //check win
            if(countX >= getBoardSize()){
                if (this->checkWin()){
                    setWinner('X');
                    break;
                }
                else if((countX+countO) == (getBoardSize()*getBoardSize())){
                    setWinner('O');
                    break;
                }
               
            }
            
            setTurn('O');
        }
        
        //O turn
        else{
            if(typeid(*this->oPlayer) == typeid(ExceptionPlayer)){
                setWinner('X');
                break;
            }

            coordinate = oPlayer.play(this->b);
            if(b[coordinate] != '.'){
                    setWinner('X');
                    break;
            }
            
            b[coordinate] = 'O';
            countO++;
            
            if(countO >= getBoardSize()){
                if (this->checkWin()){
                    setWinner('O');
                    break;
                }
            }
            setTurn('X');
        }
    }while((countO+countX) != (b.size()*b.size()));
    
    if((countO+countX) == (b.size()*b.size())){
        setWinner('O');
    }
}

bool TicTacToe :: checkWin() const{ 
    if ((this->checkRows()) || (this->checkCols()) || (this->check1Diagonal()) || (this->check2Diagonal())){

        return true;
    }
    return false;
}


Player& TicTacToe :: winner() const{
    if(this->getWinner() == 'X')
        return (*this->xPlayer);
    else
        return (*this->oPlayer);
}

const Board& TicTacToe :: board() const{
    return this->b;
}


//help-functions

bool TicTacToe :: checkRows() const{
    for (int i = 0; i <  this -> b.size() ; i++){
        bool same = true;
        for (int j = 1; j < this -> b.size(); j++){
            if ((this->b[{i,0}] != this->b[{i,j}]) || (b[{i,0}] == '.' )){
                same = false;
                break;
            }
        }
    
    if(same){
        return true;
    }
    }
    return false;
}

bool TicTacToe :: checkCols() const{
    for (int j = 0; j < this->getBoardSize(); j++){
        bool same = true;
        for (int i = 1; i < this -> getBoardSize(); i++){
            if ((b[{0,j}] != b[{i,j}]) || (b[{0,j}] == '.' )){
                same = false;
                break;
            }
        }
      
    if(same){
        return true;
    
    }
    }
    return false;
    
}

bool TicTacToe :: check1Diagonal() const{
    bool same = true;
    for (int i = 1; i < this->getBoardSize(); i++){
        if (b[{0,0}] != b[{i,i}]){
            same = false; 
            break;
        }
    }
    if(same){
        return true;
    }
    return false;
}

bool TicTacToe :: check2Diagonal() const{
    bool same = true;
    for (int i = 1; i < this->getBoardSize(); i++){
        if (b[{0,this->getBoardSize()-1}] != b[{i,this->getBoardSize() - i - 1}]){
            same = false;
            break;
        }
    }
    if(same){
        return true;
    }
    return false;    
}
