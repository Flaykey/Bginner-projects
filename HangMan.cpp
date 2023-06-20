#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
using namespace std;

typedef string str;
str words[] ={
"abruptly",
"absurd",
"abyss",
"affix",
"askew",
"avenue",
"awkward",
"axiom",
"azure",
"bagpipes",
"bandwagon",
"banjo",
"bayou",
"beekeeper",
"bikini",
"blitz",
"blizzard",
"boggle",
"bookworm",
"boxcar",
"boxful",
"buckaroo",
"buffalo",
"buffoon",
"buxom",
"buzzard",
"buzzing",
"buzzwords",
"caliph",
"cobweb",
"cockiness",
"croquet",
"crypt",
"curacao",
"cycle",
"daiquiri",
"dirndl",
"disavow",
"dizzying",
"duplex",
"dwarves",
"embezzle",
"equip",
"espionage",
"euouae",
"exodus",
"faking",
"fishhook",
"fixable",
"fjord",
"flapjack",
"flopping",
"fluffiness",
"flyby"};



int x;
str show,word;
int wlen;
int i, gcount;



void getWord(){
        system("cls");
        gcount = 1;
        x = rand()% 54;
        word = words[x];
        wlen = word.length();
        show = "";
        for(i=0;i < wlen; i++){
        show.append("*");
        }
}


void hangmanPics(int a,str word){
    switch(a)
    {
        case 1:
            cout<<"WORD: "<<word<<endl;
            cout<<"________________"<<endl;
            cout<<"|             |"<<endl;
            cout<<"|              "<<endl;
            cout<<"|              "<<endl;
            cout<<"|              "<<endl;
            cout<<"|              "<<endl;
            cout<<"|              "<<endl;
            cout<<"|              "<<endl;
            cout<<"|              "<<endl;
            cout<<"==============="<<endl;
            break;
        case 2:
            cout<<"WORD: "<<word<<endl;
            cout<<"________________"<<endl;
            cout<<"|             | "<<endl;
            cout<<"|            ( )"<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"================"<<endl;
            break;
        case 3:
            cout<<"WORD: "<<word<<endl;
            cout<<"________________"<<endl;
            cout<<"|             | "<<endl;
            cout<<"|            ( )"<<endl;
            cout<<"|             | "<<endl;
            cout<<"|             | "<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"==============="<<endl;
            break;
        case 4:
            cout<<"WORD: "<<word<<endl;
            cout<<"________________"<<endl;
            cout<<"|             | "<<endl;
            cout<<"|            ( )"<<endl;
            cout<<"|            /|\\"<<endl;
            cout<<"|           / | \\"<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"==============="<<endl;
            break;
        case 5:
            cout<<"WORD: "<<word<<endl;
            cout<<"________________"<<endl;
            cout<<"|             | "<<endl;
            cout<<"|            ( )"<<endl;
            cout<<"|            /|\\"<<endl;
            cout<<"|           / | \\"<<endl;
            cout<<"|            / \\ "<<endl;
            cout<<"|           /   \\"<<endl;
            cout<<"|               "<<endl;
            cout<<"|               "<<endl;
            cout<<"==============="<<endl;
            break;


    }
}

int main(){
    cout<<"***WELCOME TO HANGMAN***"<<endl;

    srand(time(NULL));
    bool play = true;
    char guess ;

    getWord();

    //game play
    while (play)
    {   
        // the game
        while(gcount != 6){
        hangmanPics(gcount,show);
        cout<<endl;
        cout<<"GUESS A LETTER:";
        cin >> guess;
        cout<<endl;
        str temp = show;
        for(i = 0;i<wlen ;i++){
            if(guess == word[i]){
                show[i] = guess;
            }
        }
        if(temp == show){
            gcount = gcount+1;
            }
        if(gcount == 5){
            hangmanPics(gcount,show);
            cout<<"THE WORD WAS ";
            cout<<word<<endl;
            cout<<"***YOU LOST***"<<endl;
            cout<<"***THANKS FOR PLAYING***"<<endl;
            break;

        }
        if(word == show)
        {   cout<<"WORD:"<<word;
            cout<<"***YOU WON***"<<endl;
            cout<<"***THANKS FOR PLAYING***"<<endl;
            break;
        }
        cout<<endl;
    }


    // REPLAY MENU
    cout<<"Would you like to play  again y/n:";
    cin>>guess;
    switch (guess)
    {
    case 'y':
        play = true;
        getWord();
        break;
    case 'n':
        play = false;
        break;
    default:
        cout<<"there is something wrong!!";
        exit(0);
    
    }

    }
    return 0;
}