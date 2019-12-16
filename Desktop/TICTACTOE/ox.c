//The file contains the code for TICTACTOE game.
//This file is written in C programming language.
//It follows all the standards mentioned in C99.
//The code is windows specific and it will not run on any other operating system.
/*the game works on 2d character array
*in the character array two users insert their characters either O or X one by one and the winner is decided
*if any of the user manages to have his/her character all the boxes in any of the row/column/diagonal.
*there are total 9 positions i.e 3 rows, 3 columns and 2 diagonals.
*if none of the user manages to insert their characters according to given conditions then the game is tied*/
#include<stdio.h>//this header file is included to execute basic C functions like printf and scanf.//
#include<stdlib.h>//this header file is included to execute functions like exit().
#define _WIN32_WINNT 0x0500
#include<windows.h>
/*windows.h is a windows specific file.
*the file was included to execute the system(char *) function.
*system() function is used to clear the screen by using system("cls").
*system() function is used to change the color of font by using system("color 1"), the numeric value represents the code color.*/
void sample_display();//function to display sample positions.
int win();//function to check the result of match.
void real_time_positions_display();//function to display the in-game positions.
int pos;//integer to store the position during game.
int getpos();//function to accept the position during the game.
int enter_value(int,char);//function accepts position and character and inserts that character on accepted position.
int sample_positions[3][3]={1,2,3,4,5,6,7,8,9};//array to hold sample positions.
char real_time_positions[3][3];//array to hold in-game positions.
char name[2][10];//array to store names of players.

//main function
int main(void)
{
    system("TITLE TICTACTOE");//change the title of cmd.exe
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);
    int chance=0,res=0,i=0,j=0;
    //integer chance is used to ask the user his choice of starting or exiting the game.
    //integer res is used to store the result of the match.
    //variables i and j will be used for various purpose in main function.
     system("color 5");
     //sets system color to magenta.
    do//do wile is used to start or exit new game after every game is finished.
    {
         chance=0;
        printf("\n\t\t\t\t\t\t1)Press 1 to play the game.\n\t\t\t\t\t\t");
        printf("2)Press 2 to exit the game.\n\t\t\t\t\t\t");
        fflush(stdin);
        scanf("%d",&chance);
        //accepts value in integer chance,it is used to ask the user his choice of starting or exiting the game.
        system("cls");
        //clears the screen.
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
         real_time_positions[i][j]='_';
         //sets all positions initially to '_'.
        switch(chance)//switch case will work according to the value in chance variable.
        {
        case 1:
                system("color 2");
                //sets system color to green.
                printf("\n\t\t\t\t\t############## Welcome to TicTacToe ##############\n");
                printf("\n\t\t\t\t\t\tEnter the name of player 1.\n");
                //printf asks to enter the name of first player.
                printf("\t\t\t\t\t\t");
                fflush(stdin);
                //flushes the input stream.
                fgets(name[0],20,stdin);
                //accepts the name of first player with only 20 characters in string name[0].
                fflush(stdin);
                //flushes the input stream.
                i=0;
                i=strlen(name[0]);//variable i is storing the length of string in name[0], strlen is used to find the length of the string.
                if(name[0][i-1]=='\n')//it will check if  fgets has added a newline character at the end of string.
                    name[0][i-1]='\0';//if there is a newline character at the end of the string it will be replaced with NULL character.
                printf("\n\t\t\t\t\t\tEnter the name of player 2.\n");
                //printf asks to enter the name of second player.
                printf("\t\t\t\t\t\t");
                fgets(name[1],20,stdin);
                //accepts the name of first player with only 20 characters in string name[1].
                fflush(stdin);
                //flushes the input stream.
                i=0;
                i=strlen(name[1]);//variable i is storing the length of string in name[0], strlen is used to find the length of the string.
                if(name[1][i-1]=='\n')//it will check if  fgets has added a newline character at the end of string.
                    name[1][i-1]='\0';//if there is a newline character at the end of the string it will be replaced with NULL character.
                Sleep(100);//sends the system to sleep/pauses for 0.1 sec.
                system("cls");//clears the screen.
                printf("\n\t\t\t\t\t############## TicTacToe ##############\n");
                system("color 4");//sets system color to red
                printf("\n\t\t\t\t\t\tThe name of player 1 is ==> %s \n",name[0]);//displays the name of player 1.
                printf("\n\t\t\t\t\t\tThe name of player 2 is ==> %s \n",name[1]);//displays the name of player 2.
                printf("\n\t\t\t\t\t\tPlayer %s will play with ==> O <==\n",name[0]);//displays that player 1 will play with character 'O'.
                printf("\n\t\t\t\t\t\tPlayer %s will play with ==> X <==\n",name[1]);//displays that player 1 will play with character 'X'.
                printf("\n\n");
                printf("\n\t\t\t\t\t\tThe positions will be as following.\n");
                printf("\t\t\t\t\t\tEnter the positions in the game as following.");//displays the instruction to user.
                sample_display();//gives call to the function to display the sample positions.
                printf("\n\t\t\t\t\t\tPress Enter to START the GAME\n\t\t\t\t\t\t");
                getchar();//waits for user user to press enter to start the game.
                fflush(stdin);//flushes the input stream.
                system("cls");//clears the screen.
                system("color 3");//sets system color to cyan.
                sample_display();//displays the sample positions.
                res=getpos();//gives call to the function to run the game and the function will return the result of the game.
                system("cls");//clears the screen.
                real_time_positions_display();//displays the in-game positions.
                system("color 7");//sets system color to light gray.
                if(res==1)//if value in res variable is 1 then the following printf function will display the name of player 1.
                printf("\n\t\t\t\t\t\tPLAYER %s WON\n",name[0]);
                else if(res==2)//if value in res variable is 2 then the following printf function will display the name of player 2.
                printf("\n\t\t\t\t\t\tPLAYER %s WON\n",name[1]);
                else//if value in neither 1 nor 2 then match is tied and the message will be displayed accordingly.
                printf("\n\t\t\t\t\t\tMatch is tied\n");break;
        case 2: exit(0);break;//if users press 2 the game will exit(value was stored in chance variable).
        default :     system("cls");
                     printf("\n\n\n\t\t\t\t\t\t\t\tWrong Option");
                     Sleep(2000);
                    system("cls");//if users anything other than 1 the game will exit(value was stored in chance variable).
        };//switch ends.
    }while(1);//do while will continue until the value in chance variable is 1.
return 0;
}


void sample_display()//this function will display the sample positions for the game.
{
    printf("\n\t\t\t\t\t\tSample Positions\n\n");
    printf("\t\t\t\t\t\t%d | %d | %d\n",sample_positions[0][0],sample_positions[0][1],sample_positions[0][2]);//this will print first row.
    printf("\t\t\t\t\t\t--+---+---\n");
    printf("\t\t\t\t\t\t%d | %d | %d\n",sample_positions[1][0],sample_positions[1][1],sample_positions[1][2]);//this will print second row.
    printf("\t\t\t\t\t\t--+---+---\n");
    printf("\t\t\t\t\t\t%d | %d | %d",sample_positions[2][0],sample_positions[2][1],sample_positions[2][2]);//this will print third row.
    printf("\n\n\n");
}
int getpos()//function to
{
    char X='X',O='O';//variable X will store the character X and variable O will store the character O.
    int i=1,flag=0,chk;//variable i is used for storing the iterations, its will value will increase after each move.
    //variable flag is used to store the value that will specify if the move by the player was valid or invalid.
    while(1)//while loop will continue till the game ends and mets the return condition.
    {
        if(i%2!=0)//if value in variable i is odd player will make the move.
        {
          do//the loop will ask the move/position of next move of the player,it will continue until the proper position in not entered.
          {
               flag=0;

            printf("\n\t\t\t\t %s its your turn, enter the position according to sample positions\n\t\t\t\t\t\t",name[0]);
            //asks the user 1 to enter the positions number.
            scanf("%d",&pos);//stores the position entered by the player.
            fflush(stdin);//flushes the input stream.
            if((pos < 1) || (pos > 9) )//checks if value is less than 1 or greater than 9.
            {
                Sleep(500);//pauses the screen for 0.5 seconds.
                system("cls");//clears the screen.
                 sample_display();//displays the sample positions.
              real_time_positions_display();//displays the sample positions
              printf("\n\t\t\t\t\t\tYou have entered invalid position\n");//displays the message about invalid position..
            }//if condition ends.
        }while( (pos < 1) || (pos > 9));//continues the do-while loop until the entered position is not in between 1 and 9.
          system("cls");//clears the screen.
           flag=enter_value(pos,O);
           //call given to function enter_value which accepts parameter as  position and character to be stored at the position.
           //the value returned by the function is stored in flag variable.
           if(flag!=-1)//if the value is not -1 then it means the character was inserted at its position properly and it -
            i++;//will increment the value of i.
        }//if condition ends
        else//if value of i is even then else condition will execute.
        {
            //else condition will work for player 2 in similar manner the "if" condition worked for player 1.
            //player 2 is assigned variable "X" to play with, so int his condition the character will be X.
            //everything in the else condition is same as that of if condition.
            do
          {
               flag=0;
            printf("\n\t\t\t\t %s its your turn enter the position according to sample positions\n\t\t\t\t\t\t",name[1]);
             scanf("%d",&pos);
            fflush(stdin);
            if((pos < 1) || (pos > 9) )
            {
               Sleep(500);
                system("cls");
                 sample_display();//displays the sample positions.
              real_time_positions_display();//displays the sample positions
              printf("\n\t\t\t\t\t\tYou have entered invalid position\n");
            }
           }while( (pos < 1) || (pos > 9));
           system("cls");
           flag=enter_value(pos,X);//passes the position and character 'X' to the  function.
        if(flag!=-1)
           i++;
        }
        chk=0;
        chk=win();//calls the win function to check the if someone has won or match is tied and the returned result is stored in chk variable.
        if(chk==1)//checks if the value in chk variable is 1, if it is then it will return 1.
            return 1;
        else if(chk==2)//checks if the value in chk variable is 2, if it is then it will return 2.
            return 2;
        else if(chk==3)//checks if the value in chk variable is 2, if it is then it will return 3.
            return 3;
    }
}
int enter_value(int pos,char ch)//accepts the position in pos variable and character to be stored in ch variable.
{
    //then function accepts position and character as parameter and store the character in given position.
  switch(pos)//switch condition will execute the cases according to the value in the pos variable.
   {
    case 1: if(real_time_positions[0][0]=='_')//checks if the value at the position is '_' ,i.e if it is empty
               {//if the condition is satisfied then the following lines will execute.
                real_time_positions[0][0]=ch;//puts the character in given position.
                sample_display();//displays the sample positions.
                real_time_positions_display();//displays the in-game position.
               }
               else
               {//if the condition in else is not satisfied i.e then else will execute
                   //it means that the given position was not empty and hence else will execute.
                     sample_display();
                real_time_positions_display();
                printf("\n\t\t\t\t\t\tYou entered already occupied position\n");//displays the message about invalid position.
                return -1;//returns -1 which cause the calling function to again ask for position.
               }break;
               /*all the below cases will execute in same manner as case with the value in pos variable matching the case and and in -
               turn the case will work for the a specific position accordingly*/
    case 2: if(real_time_positions[0][1]=='_')
                {
                 real_time_positions[0][1]=ch;
                 sample_display();
                 real_time_positions_display();
                }
               else
               {
                     sample_display();
                real_time_positions_display();
                printf("\n\t\t\t\t\t\tYou entered already occupied position\n");
                return -1;
               }break;
    case 3: if(real_time_positions[0][2]=='_')
                {
                 real_time_positions[0][2]=ch;
                 sample_display();
                 real_time_positions_display();
                }
               else
               {
                     sample_display();
                real_time_positions_display();
                printf("\n\t\t\t\t\t\tYou entered already occupied position\n");
                return -1;
               }break;
    case 4: if(real_time_positions[1][0]=='_')
                {
                 real_time_positions[1][0]=ch;
                 sample_display();
                 real_time_positions_display();
                }
               else
               {
                     sample_display();
                real_time_positions_display();
                printf("\n\t\t\t\t\t\tYou entered already occupied position\n");
                return -1;
               }break;
    case 5: if(real_time_positions[1][1]=='_')
               {
                real_time_positions[1][1]=ch;
                sample_display();
                real_time_positions_display();
               }
               else
               {
                     sample_display();
                real_time_positions_display();
                printf("\n\t\t\t\t\t\tYou entered already occupied position\n");
                return -1;
               }break;
    case 6: if(real_time_positions[1][2]=='_')
               {
                real_time_positions[1][2]=ch;
                sample_display();
                real_time_positions_display();
               }
               else
               {
                     sample_display();
                real_time_positions_display();
                printf("\n\t\t\t\t\t\tYou entered already occupied position\n");
                return -1;
               }break;
    case 7: if(real_time_positions[2][0]=='_')
               {
                real_time_positions[2][0]=ch;
                sample_display();
                real_time_positions_display();
               }
               else
               {
                     sample_display();
                real_time_positions_display();
                printf("\n\t\t\t\t\t\tYou entered already occupied position\n");
                return -1;
               }break;
    case 8: if(real_time_positions[2][1]=='_')
               {
                real_time_positions[2][1]=ch;
                sample_display();
                real_time_positions_display();
               }
               else
               {
                     sample_display();
                real_time_positions_display();
                printf("\n\t\t\t\t\t\tYou entered already occupied position\n");
                return -1;
               }break;
    case 9: if(real_time_positions[2][2]=='_')
                {
                 real_time_positions[2][2]=ch;
                 sample_display();
                 real_time_positions_display();
                }
               else
               {
                     sample_display();
                real_time_positions_display();
                printf("\n\t\t\t\t\t\tYou entered already occupied position\n");
                return -1;
               }break;
               };
               return 1;
  }


void real_time_positions_display()
{//function will display the in-game positions
 printf("\n\t\t\t\t\t\tCurrent Positions\n\n");
    printf("\t\t\t\t\t\t%c | %c | %c\n",real_time_positions[0][0],real_time_positions[0][1],real_time_positions[0][2]);
    printf("\t\t\t\t\t\t--+---+---\n");
    printf("\t\t\t\t\t\t%c | %c | %c\n",real_time_positions[1][0],real_time_positions[1][1],real_time_positions[1][2]);
    printf("\t\t\t\t\t\t--+---+---\n");
    printf("\t\t\t\t\t\t%c | %c | %c",real_time_positions[2][0],real_time_positions[2][1],real_time_positions[2][2]);
    printf("\n\n\n");
}
int win()
//function to check if the result of game
{
    int i=0,j=0,sum=0;
    //variable i is used to store the values of row.
    //variable j is used to store the value of columns.
    //following conditions will check if the particular positions hold the character and -
    //will return 1 if the character is O
    //will return 2 if the character id X
    //if the game is tied the function will return 3.
    //if none of the conditions are satisfied function will return 0.
    if(real_time_positions[0][0]=='O' && real_time_positions[0][1]=='O' && real_time_positions[0][2]=='O')
        return 1;
    else if(real_time_positions[1][0]=='O' && real_time_positions[1][1]=='O' && real_time_positions[1][2]=='O')
        return 1;
    else if(real_time_positions[2][0]=='O' && real_time_positions[2][1]=='O' && real_time_positions[2][2]=='O')
        return 1;
    else if(real_time_positions[0][0]=='O' && real_time_positions[1][0]=='O' && real_time_positions[2][0]=='O')
        return 1;
    else if(real_time_positions[0][1]=='O' && real_time_positions[1][1]=='O' && real_time_positions[2][1]=='O')
        return 1;
    else if(real_time_positions[0][2]=='O' && real_time_positions[1][2]=='O' && real_time_positions[2][2]=='O')
        return 1;
    else if(real_time_positions[0][0]=='O' && real_time_positions[1][1]=='O' && real_time_positions[2][2]=='O')
        return 1;
    else if(real_time_positions[0][2]=='O' && real_time_positions[1][1]=='O' && real_time_positions[2][0]=='O')
        return 1;
    else if(real_time_positions[0][0]=='X' && real_time_positions[0][1]=='X' && real_time_positions[0][2]=='X')
        return 2;
    else if(real_time_positions[1][0]=='X' && real_time_positions[1][1]=='X' && real_time_positions[1][2]=='X')
        return 2;
    else if(real_time_positions[2][0]=='X' && real_time_positions[2][1]=='X' && real_time_positions[2][2]=='X')
        return 2;
    else if(real_time_positions[0][0]=='X' && real_time_positions[1][0]=='X' && real_time_positions[2][0]=='X')
        return 2;
    else if(real_time_positions[0][1]=='X' && real_time_positions[1][1]=='X' && real_time_positions[2][1]=='X')
        return 2;
    else if(real_time_positions[0][2]=='X' && real_time_positions[1][2]=='X' && real_time_positions[2][2]=='X')
        return 2;
    else if(real_time_positions[0][0]=='X' && real_time_positions[1][1]=='X' && real_time_positions[2][2]=='X')
        return 2;
    else if(real_time_positions[0][2]=='X' && real_time_positions[1][1]=='X' && real_time_positions[2][0]=='X')
        return 2;
        //following condition checks for tie in the game.
        //so in case all positions get filled and there is no winner the sum of ascii values of all characters will be counted
        //following for loops will count the sum of ascii of all the characters in the real_time_position table.
        //if all positions are filled then the sum of ascii value of all the characters will be 747
        //ascii value of character 'O'(capital O) is 79
        //ascii value of character 'X'(capital X) is 88
        //since game starts with player 1 and player 1 plays with character O and max positions are 9 so -
        //player 1 can get up-to 5 moves
        //while player 2 starts after player 1 with character X, player 2 will get up-to 4 chances
        //so now we have 5 "O" and 4 "X"
        //hence 5*79(ascii value of O) + 4*88(ascii value of X) = 747.
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            sum+=real_time_positions[i][j];
        if(sum==747)//if sum matches the value 747 then function will return 3.
            return 3;
        return 0;//if the none of the above conditions are satisfied then the function will return 0 and the game will continue.
}

