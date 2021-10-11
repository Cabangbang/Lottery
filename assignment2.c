/*
Assignment2 - Lotto Game
Program that simulates a lottery,
Displays a menu with 6 options
1 = select 6 numbers,
2 = display the 6 numbers to the user,
3 = put the 6 numbers in ascending order,
4 = compare the 6 numbers with the winning numbers and display the result,
5 = show the frequency of what numbers where chosen
6 = exit the program.


Author: Raphael Bien Cabangbang
Student no.: c19464094
Date: 26/02/20(started), 07/03/20(ended)
OS: Windows 10
Compiler: mingw(gcc) - Code::Blocks
*/


//headers
#include <stdio.h>
#include <stdlib.h>

#define SIZE 6          //size of selected number array
#define FREQ_SIZE 43    //size of number frequency array

//function signatures
int num_select(int[]);
int num_frequency(int[], int[]);
int display_num(int[]);
int num_sort(int[]);
int num_compare(int[], int[]);
int display_frequency(int[]);
//end of function signatures


int main()
{
    int input;                      //decides what the user wants to do
    int numbers[SIZE]={0};          //Array that stores users inputed numbers
    int condition=0;                //condition that allows the user to do the other options
    int frequency[FREQ_SIZE]={0};   //stores the numbers the user enters and keeps track of their frequency
    int lotto[SIZE]={1,3,5,7,9,11}; //the winning lotto numbers that the users inputed numbers will be compared to


    while(1)  //will display the menu after each user input
    {
        //basic menu telling the user what each case will do
        printf("\n\n~~~~~~~~~Lotto~~~~~~~~\n\n");
        printf("1. Select numbers\n");
        printf("2. Display selected numbers\n");
        printf("3. Sort numbers in increasing order\n");
        printf("4. Compare numbers with Lotto numbers\n");
        printf("5. Frequency of chosen numbers\n");
        printf("6. Exit program\n\n");
        printf("Your input:");


        scanf("%d", &input);        //takes the users input

        switch(input)
        {
            case 1:     //user selects numbers
            {
                num_select(numbers);               //funtion that asks the user to enter 6 numbers, and stores them in an array
                num_frequency(frequency, numbers); //function that keeps track of what numbers were entered and stores them in a frequency array

                condition = 1;                     //allows the user to access the other program options

                break;
            }

            case 2:     //program displays the user's selected numbers
            {
                if(condition==1)    //won't allow the user to select this option unless they first select their numbers
                {
                    display_num(numbers);           //function that displays the users entered numbers
                }
                else
                {
                    printf("\nyou did not select your numbers\n");
                }
                break;
            }

            case 3:     //program bubble sorts the user's numbers
            {
                if(condition==1)    //won't allow the user to select this option unless they first select their numbers
                {
                   num_sort(numbers);               //function that sorts the users entered numbers using BUBBLE SORT
                }
                else
                {
                    printf("\nyou did not select your numbers\n");
                }
                break;
            }

            case 4:     //program compares the user's numbers to the winning lotto numbers
            {

                if(condition==1)    //won't allow the user to select this option unless they first select their numbers
                {
                    num_compare(numbers, lotto);    //function that compares the users entered numbers to the winning lotto numbers
                }
                else
                {
                    printf("\nyou did not select your numbers\n");
                }
                break;
            }

            case 5:     //program displays the numbers the user entered in case 1, and how often they appear
            {
                if(condition==1)    //won't allow the user to select this option unless they first select their numbers
                {
                    display_frequency(frequency);   //function that displays the frequency of the numbers the user has enetered
                }
                else
                {
                    printf("\nyou did not select your numbers\n");
                }
                break;
            }
            case 6:     //exits the program
            {
                return 0;                           //exits program
            }
            default:
            {
                printf("\ninvalid input\n");        //default reponce if a number not displayed is enetered
            }

        }
    }
    //while(input!=6);    //makes sure the program doesn't close unless 6 is selected
}


/*----------------------------------FUNCTIONS--------------------------------*/

//implement functin num_select - stores the user's entered numbers
int num_select(int *numbers)
{

    int i;
    int j;


    printf("\nEnter 6 numbers between 1-42 inclusive\n");


    for(i=0;i<SIZE;i++)
    {
        scanf("%d", (&*(numbers+i)));

        if(*(numbers+i)<1||*(numbers+i)>42)             //makes sure the user inputs numbers between 1 & 42 inclusive
        {
            printf("invalid number, please re-enter a valid number\n");
            i--;        //this puts the for loop back so that the invalid number isn't stored in the array
        }
        for(j=0;j<i;j++)
        {
            if(*(numbers+i) == *(numbers+j))            //makes sure that the same number hasnt already been selected
            {
                printf("You entered the number twice, please enter another number\n");
                i--;    //this puts the for loop back so that the invalid number isn't stored in the array
            }
         }
    }
}


//implement function num_frequency - stores the number in a array, in the posion they appear between 1 - 42, ex.(user enters 3, increases the 4th element in the frequency[FREQ_SIZE] array by 1)
int num_frequency(int *freq_arr, int *numbers)
{
    int i;


    for(i=0;i<SIZE;i++)
    {
        (*(freq_arr+(*(numbers+i))))++; //inccreases the number selected by 1 in the frequency array
    }
}

//implement display_num - displays the user's entered numbers
int display_num(int *display)
{
    int i;


    printf("\n\nThese are the numbers you entered: ");

    for(i=0;i<SIZE;i++)
    {
        printf("%d ", *(display+i));
    }
}


//implement num_sort - Bubble sorts the user's numbers in ascending order
int num_sort(int *sort)
{

    int i, j, swap=0;


    for(i=0;i<SIZE-1;i++)
    {
        for(j=0;j<SIZE-i-1;j++)
        {
            if(*(sort+j) > *(sort+(j+1)))   //if the next numbers is smaller it will replace the previous number with the next
            {
                swap = (*(sort+j));
                (*(sort+j)) = *(sort+(j+1));
                (*(sort+(j+1))) = swap;
            }
        }
    }
    printf("\nYour chosen numbers have been sorted\n");
}


//implement num_compare - compares the user's numbers with the winning numbers and displays the prize
int num_compare(int *numbers, int*lotto)
{
    int i;
    int j;
    int counter=0; //keeps track of how many of the user's numbers match the winning numbers


    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(*(numbers+i)==*(lotto+j))
               {
                   counter++; //increases 8if the user's numbers match any winning number
               }
        }
    }


    printf("\n\nThe winning lotto numbers: ");
    for(i=0;i<SIZE;i++)
    {
        printf("%d ", *(lotto+i));      //displays winning lotto numbers
    }


    printf("\nYour entered numbers: ");
    for(i=0;i<SIZE;i++)
    {
        printf("%d ", *(numbers+i));    //displays user's entered numbers
    }


    printf("\nMatch:%d ",counter);
//if statements that tell the user how many numbers matched and the prize they won
    if(counter==3)
    {
        printf("You won a Cinema Pass");
    }
    else if(counter==4)
    {
        printf("You won a Weekend Away");
    }
    else if(counter==5)
    {
        printf("You won a New Car");
    }
    else if(counter==6)
    {
        printf("You won the Jackpot");
    }
    else
    {
        printf("No prize won");
    }
//end if else statements
}


//implement display_frequency - displays the frequency of the numbers the user enters in case 1
int display_frequency(int *dis_freq)
{
    int i;


    for(i=0;i<FREQ_SIZE;i++)
    {
        if(*(dis_freq+i) > 0) //if statement that will only print the numbers in the frequency array that appear atleast once
        {
            printf("number %d has been selected %d times \n", i, *(dis_freq+i));
        }
    }
}

/*----------------------------------FUNCTIONS--------------------------------*/
