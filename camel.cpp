
Conversation opened. 2 messages. All messages read.

Skip to content
Using Hartnell College Mail with screen readers
Israel
Click here to enable desktop notifications for Hartnell College Mail.   Learn more  Hide
 
 
More 
1 of 1,759
 
Updated Code
Inbox
	x
Israel Andrade	
	Attachments4:35 PM (21 hours ago)
Giselle Beltran
	
Attachments1:15 PM (36 minutes ago)
		
to me
> On Nov 9, 2015, at 4:35 PM, Israel Andrade <israelandrade18957@student.hartnell.edu> wrote:
>
>
> <camelG.cpp>
Attachments area
Preview attachment Camel.txt
[Text]
	
Click here to Reply or Forward
Using 2.73 GB
Program Policies
Powered by
Google
Last account activity: 0 minutes ago
Open in 1 other location  Details
	
	
	Giselle Beltran
gisellembeltran@student.hartnell.edu
Show details

// Giselle Beltran, Israel Andrade, Carlos Huizar
// 6 November 2016
// Camel Game
#include <iostream>
#include <cstdlib> //rand()
#include <ctime> //srand(time(0))

using namespace std;

void drink(int& tH, int& can);
void moderateSpeed(int& mT, int& tH, int& cT, int& nD, bool& done);
void fullSpeed(int& mT, int& tH, int& cT, int& nD, bool& done);
void stopAndRest(int& cT, int& nD, bool& done);
void statusCheck(int& mT, int& can, int& cT, int& nD, int& tH);
void oasis(int& cT, int& can, int& tH, int chance);


int main()
{
    srand(time(0));
    bool done = false;
    int canteen = 10;
    int milesTraveled = 0, thirst = 0, camelTiredness = 0;
    char user_choice;
    int nativeDistance = -20;
    int chance = (rand() + 1) + 20;
    char playerOption;
    
    
    //Welcome print stuff
   cout << "\nWelcome to Camel!" << endl;
   cout << "\nYou have stolen a camel to make your way across the great Mobi desert." << endl;
   cout << "The natives want their camel back and are chasing you down!" << endl;
   cout << "Survive your desert trek and out run the natives." << endl;
    do
    {
    cout << "\nA. Drink from your canteen." << endl;
    cout << "B. Ahead moderate speed." << endl;
    cout << "C. Ahead full speed." << endl;
    cout << "D. Stop for the night." << endl;
    cout << "E. Status check." << endl;
    cout << "Q. Quit." << endl;
    
    cout << "\nYour decision : ";
    cin >> playerOption;
    cout << " " << endl;
    
    compUI();

   // statusCheck(milesTraveled, canteen, camelTiredness, nativeDistance, thirst);
    
    switch(toupper(playerOption))
    {
        case 'A': drink(thirst,canteen);
        break;
        
        case 'B': oasis(camelTiredness, canteen, thirst, chance);
                  moderateSpeed(milesTraveled, thirst, camelTiredness, nativeDistance, done);
        break;
        
               
        case 'C': oasis(camelTiredness, canteen, thirst, chance);
                  fullSpeed(milesTraveled, thirst, camelTiredness, nativeDistance, done);
        break;
        
        case 'D': oasis(camelTiredness, canteen, thirst, chance);
                  stopAndRest(camelTiredness, nativeDistance, done);
        break; 
              
        case 'E': statusCheck(milesTraveled, canteen, camelTiredness, nativeDistance, thirst);
        break; 
               
        case 'Q':  done = true;
        break;
        
        default:   cout << "Wrong Input" << endl;
        break;
        
    }  
    }
        while(done != true);


    return 0;
}
void statusCheck(int& mT, int& can, int& cT, int& nD, int& tH)
{

    cout << "Miles Traveled: " << mT << endl;
    cout << "Drink in Canteen: " << can << endl;
    cout << "The natives are " << (mT -nD) << " miles behind you." << endl;
    cout << "Your thirst is at: " << tH << endl;
    cout << "Your camel tiredness is: " << cT << endl;
    return;

}
void stopAndRest(int& cT, int& nD, bool& done)
{
    srand(time(0));
    cT = 0;
    nD += (rand() % 7) + 7;  
    cout << "Camel is happy :)" << endl;
    return;   
}
void fullSpeed(int& mT, int& tH, int& cT, int& nD, bool& done)
{
    srand(time(0));
    int distanceTraveled = (rand() % 10) + 11;
    mT += distanceTraveled;
    cout << "You traveled " << distanceTraveled << " miles far" << endl;
    tH += 1;
    cT = (rand() % 1) + 2;
    nD += (rand() % 7) + 7; 
    
    if(tH > 6 && tH < 10)
    {
        cout << "You are getting thirsty" << endl;
    }
    else if(tH == 10)
    {
        cout << "You died of thirst" << endl;
        done = true;
    }
    if((mT - nD) < 50 && mT < nD) 
    {
        cout << "The natives are getting closer to you" << endl;
    }
    else if(mT <= nD)
    {
        cout << "The natives cought up to you" << endl;
        cout << "They took back their camel and now you're dead" << endl;
        done = true;
    }  
    
    return;

}
void moderateSpeed(int& mT, int& tH, int& cT, int& nD, bool& done)
{
    srand(time(0));
    int distanceTraveled = (rand() % 5) + 7;
    mT += distanceTraveled;
    cout << "You traveled " << distanceTraveled << " miles far" << endl;
    tH += 1;
    cT = (rand() % 1);
    nD += (rand() % 7) + 7;  
    
    if(tH > 6 && tH < 10)
    {
        cout << "You are getting thirsty" << endl;
    }
    else if(tH == 10)
    {
        cout << "You died of thirst" << endl;
        done = true;
    }
    if((mT - nD) < 50 && mT < nD) 
    {
        cout << "Eeeek, the natives are getting closer to you!" << endl;
    }
    else if(mT <= nD)
    {
        cout << "The natives cought up to you!" << endl;
        cout << "They took back their camel...and now you're dead. The end." << endl;
        done = true;
    } 
    return;
}
void drink(int& tH, int& can)
{
    if(can > 0) 
    {
        can -= 1;
        tH = 0;
    }
    else
    {
        cout << "You have no more drinks in your canteen." << endl;
    }
    return;
}
void oasis(int& cT, int& can, int& tH, int chance)
{
    int value = (rand() % 1) + 20;   
    if(chance == value)
    {
        cT = 0;
        can = 10;
        tH = 0;
        cout << "You found and oasis!" << endl;
    }
   
    return;
}

Camel.txt
Displaying Camel.txt.
