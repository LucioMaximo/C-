
#include <iostream>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<strings.h>
#include <Windows.h>
#include <stdlib.h>
#include<time.h>

using namespace std;


char gridcr[10][10],AI_gridcr[10][10],hm_gridcr[10][10];
void indentheight(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\n");
    }
}


void indent(int n)
{
    for(int i=0; i<n; i++)
    {
        printf(" ");
    }
}


void centertext(int n, char* c)
{
    for(int i=0; i<n; i++)
        cout<<" ";
    cout<<c;
}
bool checkhit(int x, int y){

        if (AI_gridcr[y][x] == 'S'){
            return true;
        }
        else{
            return false;
        }

}
bool aiattack(){
         int aix, aiy;
         centertext(10,"INCOMING FIRE, TAKE COVER.");
         Sleep(300),cout<<".",Sleep(300),cout<<".",Sleep(300),cout<<".",Sleep(300),cout<<".",Sleep(300),cout<<".";
         Sleep(300),cout<<".",Sleep(300),cout<<".",Sleep(300),cout<<".",Sleep(300),cout<<".",Sleep(300),cout<<".\n";
         aix = rand()%(10);
         aiy = rand()%(10);
         if (gridcr[aiy][aix]!='.' && gridcr[aiy][aix]!='*'){
         gridcr[aiy][aix]='*';
         centertext(10,"WE'RE HIT!\n");
         return true;
         }
         else{
         centertext(10,"They missed. Phew. \n\n");
         Sleep(2000);
         }

}


bool attack(){

        int xcoord,ycoord, sc=0;

        centertext(10,"Make your attack! Choose co-ordinates to strike. \n");
        centertext(10,"1. Choose the X co-ordinate(across) to attack. \n");
        xcoord = getch();
        xcoord-=48;
        indent(10);
        printf(">> %i \n\n",xcoord);
        centertext(10,"2. Choose the Y co-ordinate(down) to attack. \n");
        ycoord = getch();
        ycoord-=48;
        indent(10);
        printf(">> %i \n\n",ycoord);
        centertext(10,"Roger that commander. Firing a salvo at ");
        cout<<xcoord,cout<<" ",cout<<ycoord,cout<<".";
        Sleep(300),cout<<".",Sleep(300),cout<<".",Sleep(300),cout<<".",Sleep(300),cout<<".",Sleep(300),cout<<".\n";

        if(checkhit(xcoord,ycoord)==true){
           centertext(10,"=================\n");
           centertext(10," _   _ ___ _____\n");
           centertext(10,"| | | (   |_   _)\n");
           centertext(10,"| |_| || |  | | \n" );
           centertext(10,"|  _  || |  | |\n"  );
           centertext(10,"| | | || |  | | \n" );
           centertext(10,"|_| |_(___) |_|  \n");
           centertext(10,"=================\n");

            hm_gridcr[ycoord][xcoord]='H';
            return true;
           }
        else{
            centertext(10,"===========================\n");
            centertext(10," __  __ _____  _____ _____\n");
            centertext(10,"|  \\/  |_   _|/ ____/ ____|\n");
            centertext(10,"| \\  / | | | | (___| (___  \n");
            centertext(10,"| |\\/| | | |  \\___ \\\\___ \\ \n");
            centertext(10,"| |  | |_| |_ ____) |___) |\n");
            centertext(10,"|_|  |_|_____|_____/_____/ \n");
            centertext(10,"===========================\n");
            hm_gridcr[ycoord][xcoord]='M';
            return false;
        }


}

void drawgrid(char c[][10])
{
    indentheight(1);
    indent(10);
    cout<< "  ";
    for(int i=0; i<10; i++)
    {
        cout<<i,cout<<" ";
    }
    cout<<"\n";
    indent(10);
    for (int i=0; i<10; i++)
    {
        cout<<i,cout<<" ";
        for(int x=0; x<10; x++)
        {
            printf("%c ",c[i][x]);
        }
        cout<<"\n";
        indent(10);
    }
}

bool horizontal(string ship)
{
    while(true)
    {
        bool hori;
        char input;
        indent(5);
        cout<<ship, cout<<"\n";
        centertext(5,"1. Place Horizontally or Vertically. (Enter V or H) \n");
        input = getch();

        if (input == 72 || input == 104)
        {
            centertext(5,"Horizontally, Roger that! \n\n");
            hori = true;
            return hori;

        }
        if (input == 86 || input == 118)
        {
            centertext(5,"Vertically, Roger that! \n\n");
            hori = false;
            return hori;
        }
        else
        {
            centertext(5,"You didn't enter V or H \n");
        }

    }


}
int xycoordcheck(string ship,int length,bool h)
{
    while(true)
    {
        int xcoord,ycoord, sc=0;
        indent(5);
        cout<<ship, cout<<"\n";
        centertext(5,"Ships are placed from left to right or top to bottom \n");
        centertext(5,"2. Choose the X co-ordinate(across) to place the ship. \n");
        xcoord = getch();
        xcoord-=48;
        indent(5);
        printf(">> %i \n\n",xcoord);
        centertext(5,"3. Choose the Y co-ordinate(down) to place the ship. \n");
        ycoord = getch();
        ycoord-=48;
        indent(5);
        printf(">> %i \n\n",ycoord);

        drawgrid(gridcr);

        if (h == true)
        {
            if(xcoord+length<=10 && ycoord <=10)
            {
                for(int i=xcoord; i<xcoord+length; i++)
                {

                    if(gridcr[ycoord][i] !='.')
                    {

                        sc+=1;

                    }
                }

                    if (sc>=1)
                    {
                        centertext(5,"There is a ship in the way of that location. \n");
                        Sleep(1000);
                    }

                    else if (sc == 0)
                    {
                    for(int i=xcoord; i<xcoord+length; i++)
                    {
                        gridcr[ycoord][i] = ship[0];

                    }
                    indent(5);
                    cout<<ship, cout<<" placed \n";
                    return 0;
                }

            }
            else
            {
                centertext(5,"Your ship doesn't fit there \n");
            }
        }
        if (h == false)
        {
            if(ycoord+length<=10 && xcoord <=10)
            {
                for(int i=ycoord; i<ycoord+length; i++)
                {

                    if(gridcr[i][xcoord] !='.')
                    {
                        sc+=1;
                    }
                }
                    if (sc>=1)
                    {
                        centertext(5,"There is a ship in the way of that location. \n");
                        Sleep(1000);
                    }

                    else if (sc == 0)
                    {
                    for(int i=ycoord; i<ycoord+length; i++)
                    {
                        gridcr[i][xcoord] = ship[0];
                    }
                    indent(5);
                    cout<<ship, cout<<" placed \n";
                    return 0;
                }

            }
            else
            {
                centertext(5,"Your ship doesn't fit there \n");
            }
        }
    }

}

int aigen(){
    bool three = true;
    int shipcount = 0;
    int r1;
    for(int length=5; length>=2; length--){
        if (length == 2 && three == true ){
            length+=1;
            three = false;
        }
        [&]{
        bool horiz = false;
        int aix, aiy,sc=0;

        aix = rand()%(11-length);
        aiy = rand()%(11-length);
        r1 = rand()%2;
            if (r1 == 1){
                horiz = true;
                for(int i=aix; i<aix+length; i++)
                {
                    if(AI_gridcr[aiy][i] == 'S')
                    {
                        sc+=1;
                    }
                }
                if (sc>=1){
                    length+=1;
                    return;
                }
                else{
                 for(int i=aix; i<aix+length; i++){
                    AI_gridcr[aiy][i] = 'S';
                 }
                }
            }
            else{
                for(int i=aiy; i<aiy+length; i++)
                {
                    if(AI_gridcr[i][aix] == 'S')
                    {

                        sc+=1;
                    }
                }
                if (sc>=1){

                    length+=1;
                    return;
                }
                else{
                 for(int i=aiy; i<aiy+length; i++){
                    AI_gridcr[i][aix] = 'S';
                }
            }
            }

        }();
    }
    return 0;
}





int main()
{
    srand(time(NULL));
    char input,ycoord,xcoord;
    bool hori;
    indentheight(10);
    centertext(30,"Welcome to Battleships \n\n");
    centertext(30,"Don't left click inside the console, if you do, press right click to clear \n\n");
    Sleep(1000);
    while (true)
    {

        centertext(30, "1. Start new game \n");
        centertext(30, "2. Rules \n");
        centertext(30, "3. Quit \n");
        input = getch();

        if (input==49)
        {
            int length = 5, yhits=0, aihits =0;
            string shiptype = "Aircraft Carrier (5x1)";
            system("cls");
            centertext(15, ">>1. Start new game \n\n");
            for(int i=0; i<10; i++)
            {
                for(int x=0; x<10; x++)
                {
                    gridcr[i][x] = 46;
                }
            }
            drawgrid(gridcr);
            hori = horizontal(shiptype);
            xycoordcheck(shiptype,length,hori);
            drawgrid(gridcr);
            shiptype = "Battleship (4x1)",length = 4;
            hori = horizontal(shiptype);
            xycoordcheck(shiptype,length,hori);
            drawgrid(gridcr);
            shiptype = "Cruiser (3x1)",length = 3;
            hori = horizontal(shiptype);
            xycoordcheck(shiptype,length,hori);
            drawgrid(gridcr);
            shiptype = "Submarine (3x1)",length = 3;
            hori = horizontal(shiptype);
            xycoordcheck(shiptype,length,hori);
            drawgrid(gridcr);
            shiptype = "Destroyer (2x1)",length = 2;
            hori = horizontal(shiptype);
            xycoordcheck(shiptype,length,hori);
            drawgrid(gridcr);
            centertext(10, "You've placed all of your ships. Now time to blow them to smithereens!");
            aigen();
            //drawgrid(AI_gridcr);  Cheat mode - show the ai ships

            while (true){
                if (yhits>=17){
                    centertext(25,"\n\n\nTheir ships are all sunk. Congratulations. We've won!\n\n\n");
                    break;
                }
                if (aihits>=17){
                    centertext(25,"\n\n\n Your ships are all sunk. Commiserations. We've lost.\n\n\n");
                    break;
                }
                drawgrid(hm_gridcr);
                 centertext(5, "Target Computer. \n\n");
                if (attack() == true){
                    yhits+=1;
                }
                if(aiattack() == true){
                    aihits+=1;
                };
                drawgrid(gridcr);
                centertext(5,"Our fleet. \n\n");

            }

        }
        if (input==50)
        {
            system("cls");
            centertext(15, ">>2. Rules \n\n");
            centertext(15, "1. There's a 10x10 grid.\n");
            centertext(15, "2. Place your Aircraft Carrier(5x1), Battleship(4x1), Cruiser(3x1), Submarine(3x1) and Destroyer(2x1).\n");
            centertext(15, "3. Choose to place them Vertically or Horizontally. (V/H) \n");
            centertext(15, "4. Choose the starting co-ordinate to place them at. (X Y) \n");
            centertext(15, "5. Once placed, you and the computer take turns to sink each others' ships. \n");
            centertext(15, "6. * denotes a miss, X denotes a hit. \n");
            centertext(15, "7. First person to sink all of the other player's ships wins. \n\n\n\n\n\n");
            Sleep(3000);
        }
        if (input==51)
        {
            centertext(15, ">>3. Quit \n");
            centertext(15, "Thanks for playing \n");
            break;
        }
    }
}
