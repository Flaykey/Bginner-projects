#include<iostream>
#include<string.h>
using std::cout;
using std::cin;

char b1,b2,b3,b4,b5,b6,b7,b8,b9;

int a= 1;
bool turn =true;
bool win = false;
bool p1=false,p2=false;
char valid[9];
int count = 0;

bool validation(char input){
    valid[count] = input;
    int i = 0;
    for(i=0;i<count;i++){
        if(valid[i]==input){
            return false;
            break;
        }
    }
    count++;
    return true;
}

void blockInitialize(){
    b1 = '1';
    b2 = '2';
    b3 = '3';
    b4 = '4'; 
    b5 = '5';  
    b6 = '6';
    b7 = '7';  
    b8 = '8';
    b9 = '9';
}
void board(){
    system("cls");
    cout<<"          TIC TAC TOE         "<<std::endl;
    cout<<std::endl;
    cout<<"       [ "<<b7<<" ]"<<" [ "<<b8<<" ]"<<" [ "<<b9<<" ]"<<std::endl;
    cout<<"       [ "<<b4<<" ]"<<" [ "<<b5<<" ]"<<" [ "<<b6<<" ]"<<std::endl;
    cout<<"       [ "<<b1<<" ]"<<" [ "<<b2<<" ]"<<" [ "<<b3<<" ]"<<std::endl;
    cout<<std::endl;
    cout<<"Player1(X)           Player2(O)"<<std::endl;
}

void game(){
    char play;
    
    
    if(win!=true){
    cout<<"Player"<<a<<" turn, which block:";
    cin>>play;
    }
    while(!validation(play)){
        board();
        cout<<"Player"<<a<<" Please Enter  A valid block: ";
        cin>>play;
    }
    
    if(turn){
        if(play==b1) b1 = 'X';
        if(play==b2) b2 = 'X';
        if(play==b3) b3 = 'X';
        if(play==b4) b4 = 'X';
        if(play==b5) b5 = 'X';
        if(play==b6) b6 = 'X';
        if(play==b7) b7 = 'X';
        if(play==b8) b8 = 'X';
        if(play==b9) b9 = 'X';
        a=2;
    }
    else{
        if(play==b1) b1 = 'O';
        if(play==b2) b2 = 'O';
        if(play==b3) b3 = 'O';
        if(play==b4) b4 = 'O';
        if(play==b5) b5 = 'O';
        if(play==b6) b6 = 'O';
        if(play==b7) b7 = 'O';
        if(play==b8) b8 = 'O';
        if(play==b9) b9 = 'O';
        a=1;
    }
    
    if ((b1 == b2 && b2 == b3 && b3 == 'X') ||  // Updated condition
    (b4 == b5 && b5 == b6 && b6 == 'X') ||
    (b7 == b8 && b8 == b9 && b9 == 'X') ||
    (b1 == b5 && b5 == b9 && b9 == 'X') ||
    (b7 == b5 && b5 == b3 && b3 == 'X') ||
    (b1 == b7 && b7 == b4 && b4 == 'X') ||
    (b2 == b5 && b5 == b8 && b8 == 'X') ||
    (b3 == b6 && b6 == b9 && b9 == 'X')) {
    a=1;
    win = true; 
    turn = NULL;
    cout<<"Player1(X) Won The Game!!"<<std::endl;
    }
    else if ((b1 == b2 && b2 == b3 && b3 == 'O') ||  // Updated condition
    (b4 == b5 && b5 == b6 && b6 == 'O') ||
    (b7 == b8 && b8 == b9 && b9 == 'O') ||
    (b1 == b5 && b5 == b9 && b9 == 'O') ||
    (b7 == b5 && b5 == b3 && b3 == 'O') ||
    (b1 == b7 && b7 == b4 && b4 == 'O') ||
    (b2 == b5 && b5 == b8 && b8 == 'O') ||
    (b3 == b6 && b6 == b9 && b9 == 'O')) {
    a=2;
    win = true; 
    turn = NULL;
    cout<<"Player2(O) Won The Game!!"<<std::endl;
    }

}


int main(){
    bool play = true;
    char willPlay;


    while(play){
        win = false;
        blockInitialize();
        turn = true;
        a=1;

        while(win!=true){

        board();
        game();
        // Switches between players
        if(turn == true){
            turn = false;
        }
        else{
            turn = true;
        }
        // Clear console
        if(win == true){
        board();
        game();
        break;
        }
    }
    cout<<"Would you like to play again y/n:";
    cin>>willPlay;

    if(willPlay=='y'){
        play = true;
    }
    else{
        play = false;
    }
    
    
    }
    return 0;
}