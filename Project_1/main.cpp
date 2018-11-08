#include <iostream>
#include <string>
#include <ctime>
#include<stdlib.h>
#include<windows.h>
#include<iomanip>
#include<cmath>

using namespace std;


class game
{
    int tries=7;
    int counter;
    string respnse;
    string shown="";

public:
    void reset();
    void drawing();
    void triesL();
    void store(string hWord);
    void addT();
    void fullMan();
};
void game::triesL()
{
    int loop=1;
    char letter;
    float sCountr=0;

    for(int i=0; i<(int)respnse.length(); i++)
    {
        if(isalnum(respnse[i]))
        {
            shown=shown+"-";
            sCountr++;
        }
        else
        {
            shown=shown+respnse[i];
        }
    }
    cout<<shown<<endl;

    cout<<"What letter do you think is here?"<<endl;
    cin>>letter;

    for(int b=0; b<(int)respnse.size(); b++)
    {
        if(respnse[b]==letter || toupper(letter)==respnse[b])
        {
            shown[b]=letter;
        }

    }

    cout<<shown<<endl;
    cout<<"You have "<<tries<<" tries left."<<endl;
    while(loop)
    {
        int tracker=0;
        int shownT=0;

        cout<<"What letter do you think is here? or enter (?) to leave"<<endl;
        cin>>letter;

        if(letter=='?')
        {
            break;
        }
        for(int b=0; b<(int)respnse.size(); b++)
        {
            if(respnse[b]==letter || toupper(letter)==respnse[b])
            {
                shown[b]=letter;
                tracker=1;
            }
            else if(respnse[b]!=letter || respnse[b]!=toupper(letter))
            {
                tracker=tracker+0;
            }
        }

        for(int d=0; d<sCountr; d++)
        {
            if(shown[d]=='-' || shown[d]==' ')
            {
                shownT=1;
            }
            else if(shown[d]!='-')
            {
                shownT=shownT+0;
            }
        }

        if(tracker==0)
        {
            addT();
        }

        if(shownT==0 || shown==respnse)
        {
            loop=0;
            cout<<"Secret Word: "<<respnse<<endl;
            cout<<"You win."<<endl;
            reset();
        }
        cout<<shown<<endl;

        if(tries>0 && shownT!=0 && shown!=respnse)
        {
            cout<<"You have "<<tries<<" tries left."<<endl;
        }
        if(tries==0)
        {
            loop=0;
            cout<<"You lose."<<endl;
            cout<<"The word was: "<<respnse<<endl;
            cout<<"Try the game again... Thank you"<<endl;
            reset();

            cout<<endl;
            cout<<endl;
        }

    }
}
void game::store(string x)
{
    respnse=x;
}
void game::reset()
{
    respnse="";
    shown="";
    tries=7;
}
void game::addT()
{
    tries--;
}

int main()
{
    game obj;
    int choice;//the bread and butter of the classes letter the user over and over until they get tired
    int loop=1;//used for the while loop below
    char ans='n';//the original condition of the while loop
    string uWord;// the secret word the user enters
    string topic;// the topic for the hangman game

    while(ans=='n' || ans=='N')
    {
        cout<<"Welcome to a game of hangman."<<endl;
        cout<<"Press any key to continue."<<endl;
        cin>>ans;
        system(" ");
    }
    while(loop)
    {
        cout<<"********************"<<endl;
        cout<<"1)Select your word *"<<endl;
        cout<<"2)Play game        * "<<endl;
        cout<<"********************"<<endl;
        cout<<"Your choice here >";
        cin>>choice;
        if(choice==1)
        {
            HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
            DWORD mode = 0;
            GetConsoleMode(hStdin, &mode);
            SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
            cout << "Type out the desired word and press enter." << endl;
            cin.ignore();
            getline(cin,uWord);
            SetConsoleMode(hStdin, mode);
            obj.store(uWord);
            cout<<"Your word has been entered."<<endl;
            cout<<endl;
            cout<<endl;
        }

        else (choice==2);
        {
            obj.triesL();
        }

    }

}