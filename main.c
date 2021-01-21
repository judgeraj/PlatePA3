/*
Rajpreet Judge
CSE 222
Nick Macias
02/13/2020

Nick This program is one where I take the most pride in doing... let me tell you why
during this 6ish hour adventure of coding this program 1-2 days before its due I had ate about 10 oranges, a bag of chips
like 5 water bottles, one jamba juice and a bowl of peanut butter... also one grapefruit that I mistook for an orange again!

That is not why I take pride inthis program but instead I wish i listened and started it a lot earlier and regret not doing that, I take pride inthis one
because during the trouble shooting hours I dont think Ive ever had anything snap into place like the knowledge of passing these points and etc did
when the pieces of this program started to work I was gaining energy like it went hand in hand, the more the program started to work the more power I got in real life.

Soon enough I turned about 3 pages of warnings and errors into a working program by trying to understand what the compiler was actually telling me. 

All in all I think I learned the most from this PA and also from PA2

Program description:
This program is a license plate database in which the user can search for certain license plates and dump cells with license plates in them or just dump the whole hashtable to display all the plates
in the table. the program also frees the memory that gets allocated after exiting.
*/

#include<stdio.h> //Im literally eating peanut butter with a spoon from a bowl....
#include<string.h> //these are your std libaries 
#include<stdlib.h>//^^^
#include"stuff.c" //this is just function prototypes and the structure for a struct node

int main(int argc, char**argv) { //this is the main function that for somereason returns an int but also takes important command line arguments

  int size = 100; //defaulty sizey

  if((argc != 2) && (argc != 3)){ // if the user only enters one command to too many commands 
    printf("ERROR: %s textfile [hashsize]\n", argv[0]); //this error message will pop up
    return 0; // return 0 for some random reason LOL
  }
  
  if(argc == 3) {  //if the user has 3 arguments we need to check to see if they a valid size
    if(1 != sscanf(argv[2],"%d",&size)) {
      printf("ERROR: %s is not valid\n", argv[2]);//printing/checking to see if the user entered a valid int
      return 0;
    }
    if(size <= 0) {
      printf("ERROR: %s is not valid\n", argv[2]); //seeing if thet entered a number over 0
      return 0;
    }
  }

  printf("Database name is <%s>\n Size = %d\n", argv[1], size); //telling the user the database program is reading from

//error checking for command lines are done------------------
  hashEntry *table;

  table = hashInit(size); //calling hasinit to fill the table with pointers to sentinels i think lol

//reading the database time

  FILE *fp = fopen(argv[1],"r"); //opening the file with read only permissions
 
  if(fp == NULL) { //if the file is not a valid file
    printf("ERROR: %s is not a valid database file", argv[1]); //print error message and then return
    return 0; //returning here for invalid
  }
  char temp[256]; //using this a the temo variable for reading into the table from files

  while(fgets(temp,256,fp) != NULL) { //adding until the file retunrs null
    char plate[32], first[32], last[32];
    sscanf(temp, "%s %s %s", plate, first, last); //parsing the input from the file
    hashAdd(table,plate,first,last); //calling hashAdd and passing it the information
  }
  fclose(fp); //closing the file so I can sleep at night knowing I am not suffering from memory leaks
  printf("Done reading database\n"); 

//Done with reading database-------------------------------------

  char input[120];
  int cellnum;

  printf("Enter plate number or legal command: "); //i mean pretty self explainatory 

  while(fgets(input,120,stdin) != NULL) { //llooping until the user gets tired of ticketing peoples license plates

    input[strlen(input)-1] = '\0'; //removing new line from the user inputed strings

    char fn[50], ln[50]; //do i pass these as first and last
//      printf("------------------------------------\n");

    if(strcmp(input,"*LOAD") == 0) {//user enters *LOAD
      hashLoad(table); //should print each cell with the number of plates stored in each
      printf("------------------------------------\n");
    }
    else if(strcmp(input,"*DUMP") == 0) //user enters *DUMP
    {
      printf("------------------------------------\n");
      for(int i = 0; i < (size-1); i++) { //iterate through hole table and dump contents
        hashDump(table, i);
      }
      printf("------------------------------------\n");
    }
    else if(sscanf(input,"*DUMP %d", &cellnum) == 1) //user enters *DUMP also checking to savethe number entered
    {
      printf("------------------------------------\n");
      printf("Contents of cell %d\n", cellnum);
      if((cellnum < size) && (cellnum >= 0)) { //is it a valid cellnum?
        hashDump(table, cellnum); //calling hashDump with the cell number 
        printf("------------------------------------\n");
      }       
      if(cellnum >= size)  //if the cell number is bigger than the actual size then its not valid and get newnumber
        printf("Cell number entered not valid\n");
    }
    else
    { //we know plate number was entered here if the rest are skipped   
      if(hashFind(table, input, fn, ln) == 1) { //how do i pass hashFind first and last if the user only enters the plate number which in this case is "input"
        printf("First name: %s\nLast name: %s\n", fn, ln); //printing the name attached to that plate
      }
      else
        printf("Plate not found\n"); //we didnt find that plate 
    }
  printf("Enter Plate or Command: "); //in the night i hear them talk the coldest story ever told!
  }
  printf("Freeing the Allocated Memory\n");

  hashFree(table); //calling hasFree to free the memory

  printf("Memory free'd\n"); //informing the user lol

  return 0;

} //WE ARE DONE AND HAVE OVER CAME!
