//Vadim Biryukov || Final Project Programming 2|| Tic Tac Toe

#include <conio.h> // for real time input
#include <iostream>

using namespace std;

class Game {
    
    private: 
        char boardArr[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};    
        int player=1;
        int turn =2;
        bool win=0; 
        
        int i=0;
        
        void resetter(){// in case if after the game user wants to play again, this resets values 
            player=1;
            turn =2;
            win=0;
            i=0;
            for (int i = 0; i <10; i++)
            {
                boardArr[i]=' ';
            }
        } 
              
    public:  
        void setResetter(){
            resetter();
        }
        void setWin (int x ){
             win=x ;
        };
        bool getWin (){
            return win;
        };
        
        void setBoardArr (int x){ // sets 'X' or 'O' in to an array that represents a board
                char input = getch();
            if (x==1){
                    if ( input=='1' && boardArr[0]==' '){
                        boardArr[0]='O';  
                    }
                    else if ( input=='2' && boardArr[1]==' '){
                        boardArr[1]='O';
                    }
                    else if ( input=='3' && boardArr[2]==' '){
                        boardArr[2]='O';
                    }
                    else if ( input=='4' && boardArr[3]==' '){
                        boardArr[3]='O';
                    }
                    else if ( input=='5' && boardArr[4]==' '){
                        boardArr[4]='O';
                    }
                    else if ( input=='6' && boardArr[5]==' '){
                        boardArr[5]='O';
                    }
                    else if ( input=='7' && boardArr[6]==' '){
                        boardArr[6]='O';
                    }
                    else if ( input=='8' && boardArr[7]==' '){
                        boardArr[7]='O';
                    }
                    else if ( input=='9' && boardArr[8]==' '){
                        boardArr[8]='O';
                    }
                    else {
                        setBoardArr(x);
                    }
                }
                else {
                            if ( input=='1' && boardArr[0]==' '){
                                boardArr[0]='X';
                            }
                            else if ( input=='2' && boardArr[1]==' '){
                                boardArr[1]='X';
                            }
                            else if ( input=='3' && boardArr[2]==' '){
                                boardArr[2]='X';
                            }
                            else if ( input=='4' && boardArr[3]==' '){
                                boardArr[3]='X';
                            }
                            else if ( input=='5' && boardArr[4]==' '){
                                boardArr[4]='X';
                            }
                            else if ( input=='6' && boardArr[5]==' '){
                                boardArr[5]='X';
                            }
                            else if ( input=='7' && boardArr[6]==' '){
                                boardArr[6]='X';
                            }
                            else if ( input=='8' && boardArr[7]==' '){
                                boardArr[7]='X';
                            }
                            else if ( input=='9' && boardArr[8]==' '){
                                boardArr[8]='X';
                            }
                            else {
                                setBoardArr(x);
                            }
                }
        };

        char getBoardArr (int x){
            return boardArr[x];
        };
        void setPlayer ( ){ // it is a number of a turn that determines a player
            
            for ( turn = 1; turn <10; turn++){
                if(win!=1){
                    if (turn%2){
                        player=1; 
                        cout << "currently its a turn of a player "<<getPlayer()<< endl;
                        setBoardArr(1);
                    }
                    else {
                        player=2;
                        cout << "currently its a turn of a player "<<getPlayer()<< endl;
                        setBoardArr(2);
                    }
                boardDraw();
                wincheck();
                }
            }
        };

        int getPlayer (){
            return player;
        }; 

        int boardDraw(){ 
            system ("CLS");
            cout << endl<< endl;
            cout <<"\t"<< " "<<getBoardArr(0)<<" "<<"|"<< " "<<getBoardArr(1)<<" "<<"|"<< " "<<getBoardArr(2)<<" "<<endl;
            cout <<"\t"<< "____________"<<endl<<endl;
            cout <<"\t"<< " "<<getBoardArr(3)<<" "<<"|"<< " "<<getBoardArr(4)<<" "<<"|"<< " "<<getBoardArr(5)<<" "<<endl;
            cout <<"\t"<< "____________"<<endl<<endl;
            cout <<"\t"<< " "<<getBoardArr(6)<<" "<<"|"<< " "<<getBoardArr(7)<<" "<<"|"<< " "<<getBoardArr(8)<<" "<<endl;   
            
        }

        int wincheck(){ 
            // 0,1,2    3,4,5   6,7,8
            if (getBoardArr(0)==getBoardArr(1) && getBoardArr(1)==getBoardArr(2)&&(getBoardArr(0)=='O'||getBoardArr(0)=='X')){
                conclusion();
            }
            if (getBoardArr(3)==getBoardArr(4) && getBoardArr(4)==getBoardArr(5)&&(getBoardArr(3)=='O'||getBoardArr(3)=='X')){
                conclusion();
            }
            if (getBoardArr(6)==getBoardArr(7) && getBoardArr(7)==getBoardArr(8)&&(getBoardArr(6)=='O'||getBoardArr(6)=='X')){
                conclusion();
            }
            // 0,3,6    1,4,7   2,5,8
            if (getBoardArr(0)==getBoardArr(3) && getBoardArr(3)==getBoardArr(6)&&(getBoardArr(0)=='O'||getBoardArr(0)=='X')){
                conclusion();
            }
            if (getBoardArr(1)==getBoardArr(4) && getBoardArr(4)==getBoardArr(7)&&(getBoardArr(1)=='O'||getBoardArr(1)=='X')){
                conclusion();
            }
            if (getBoardArr(2) ==getBoardArr(5)  && getBoardArr(5) ==getBoardArr(8) &&(getBoardArr(2) =='O'||getBoardArr(2) =='X')){
                conclusion();
            }
            //0,4,8     6,4,2
            if (getBoardArr(0) ==getBoardArr(4)  && getBoardArr(4)==getBoardArr(8) &&(getBoardArr(0) =='O'||getBoardArr(0) =='X')){
                conclusion();
            }
            if (getBoardArr(6) ==getBoardArr(4)  && getBoardArr(4) ==getBoardArr(2) &&(getBoardArr(6) =='O'||getBoardArr(6) =='X')){
                conclusion();
            }
            i++;
            if (i>=9 && getWin()!=1){
                draw();
            }
        }
 
        void conclusion(){ // when there is a winner this is where the congratulation message appears
            cout <<endl<<endl<<"\t Congratulations Player "<<getPlayer()<<" WON the game"<<endl<<endl;
            setWin(1);
            }
        void draw(){
            cout << "It was a draw"<<endl;
            setWin(1);
        }
};

class HowTo { 
    private: 
        char input='0';

    public: 
        void setInput (char x){
            input = x;
        };
        char getInput (){
            return input;
        };
        void GameHowTo(){ //explanation of how to play the game
            cout <<endl;
            cout << "\t How To Play:"<<endl<<endl<<endl;
            cout << "The board is divided in to nine squares from 1 to 9";
            cout << endl<< endl;
            cout <<"\t"<< " "<<"1"<<" "<<"|"<< " "<<"2"<<" "<<"|"<< " "<<"3"<<" "<<endl;
            cout <<"\t"<< "____________"<<endl<<endl;
            cout <<"\t"<< " "<<"4"<<" "<<"|"<< " "<<"5"<<" "<<"|"<< " "<<"6"<<" "<<endl;
            cout <<"\t"<< "____________"<<endl<<endl;
            cout <<"\t"<< " "<<"7"<<" "<<"|"<< " "<<"8"<<" "<<"|"<< " "<<"9"<<" "<<endl<<endl;
            
            cout<< "To choose the place where you want to put simply enter the key from 1 to 9, all the inputs are real-time";
            cout << endl<< endl << endl;
            cout <<"q: Go Back";

            if (ToMenuBack()=='q'){
                return;
            }

        }
        char ToMenuBack(){//fixes a blink in a How To Play when user enters invalid character
            
            setInput(getch());
            
            if (getInput()=='q'){
                system ("CLS");
                return 'q';
            }
            else {
                ToMenuBack();
            }
        }
};

char menuBlinkFix(){ //fixes a blink in a menu when user enters invalid character
        char input='0';   
            input=getch();
            
            if (input=='q'){
                system ("CLS");
                return 'q';
            }
            else if (input=='1'){
                system ("CLS");
                return '1';
            }
            else if (input=='2'){
                system ("CLS");
                return '2';
            }
            else {
                menuBlinkFix();
            }
        }

int main() 
{
    char asker='0';
    char input='0';
    HowTo HowGameObj;
    Game gameObj;

    while (input!='q'){
        system ("CLS");
        cout << endl<< "Welcome to Tic Tac Toe game" << endl<< endl;
        cout << "Please select" << endl<< endl;   
        cout << "   1: Two Players" << endl;
        cout << "   2: How To Play" << endl<< endl;
        cout << "   q: Quite" << endl<< endl<< endl<< endl;
        cout << "   Made By: Vadim Biryukov" << endl;
        
        input=menuBlinkFix(); //real time input
        
        switch (input)
        {
        case '1':
            system ("CLS");  
                gameObj.boardDraw(); 
            while(gameObj.getWin()!=1){
                gameObj.setPlayer();
            }
            cout <<"Do you want to go to main menu? (y?)"<<endl;
// if player wants to play again
            asker=getch();
            if (asker=='y'){
                gameObj.setResetter();
            }
            else { 
            cout <<"Thank you for playing"<<endl;
                exit(0);
            }
//------------------------------            
            break;
        case '2':
            system ("CLS");
            HowGameObj.GameHowTo();
            break;
        case 'q':
            system ("CLS");
            cout << "Thank you for playing";  
            exit(0);                        
            break;
        }
    }
return 0;
}
