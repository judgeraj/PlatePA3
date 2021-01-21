/*
Rajpreet Judge
CSE 222
Nick Macias
Hash.c file contains all the hash functions for PA3 which is a license plate database
02/13/2020
I do not want to brag or toot my own horn in any way at all but I would like to say I did this program in 10 hours (DO NOT RECCOMEND IT) never again
*/

#include<stdio.h> //this is normal...
#include<string.h>//i put everything I might need up here
#include<stdlib.h>//same ehre
#include"stuff.c"// this was an amazing discovery.. I think me learning to make this is honestly better than pizza

int hashlen; //table size used within this file

//not done 100% ---- now its done
int hash(char *plate) { //I would love to play some games right now 

  int sum = 0; //i did this program while ingesting wayyyyy too many calories
  int length = strlen(plate); //I am surprised my weight hasnt skyrocketed

  for(int i = 0; i < length; i++) {  // doing a for loopy
    sum = (sum + (i+5)*plate[i])%(hashlen); // adding up these ascii numby's and ill meet you in lumby (runescape reference)
  } 
  sum = sum; // this was useless but I prefer longer code/functions

  return (sum); //returning the sum to wahtever is calling this
}


//--------------------------------------------------
							
hashEntry *hashInit(int len) {// i was gunna draw a panda and stuff in here but that was gunna take forever
 	 			  
  hashEntry *table = malloc(len*sizeof(hashEntry));//
						//
  hashlen = len; //making the hashlen set to len hehehe
  for(int i = 0; i < (len); i++) //for loops are a godsend
    table[i] = listInit(); // initializing the tabley 
 
  return (table); //returning a table not a wooden table hehe
}
  
//--------------------------------------------------

void hashAdd(hashEntry *table, char *plate, char *first, char *last) { //this is the hashAdd function 

  int loc = hash(plate); //could do this in 1 line but who would do such a thing??
  listAdd(table[loc],plate,first,last); //these being super short functions made me worried

  return; // every1 likes to return
}

int hashFind(hashEntry *table, char *plate, char *first, char *last) { //hashFind function that I did do in one line
  
  return(listFind(table[hash(plate)],plate,first,last)); //I got a whole chicken roasting and im smelling it....killing my stomach right now
}

//-----------------------------------------------------

void hashLoad(hashEntry *table) { //I like how these functions are calling other fuctions that something call another function that calls a function

  for(int i = 0; i < hashlen; i++) { //man most of these funcitons are just for loops danggg dawwgg
    printf("Entry %d: length=%d\n", i, listLen(table[i])); //printy printy printy
  } //close that curly!
  
  return; //returning statement
}

//---------------------------------------------------

void hashDump(hashEntry *table, int cellNum) { //this just prints flipping the whole table

  listPrint(table[cellNum]); //calling listprint to dump the whole database onto the screen you wont be able to even read all of them
 
  return; //return from another 1 line function

}

void hashFree(hashEntry *table) { //this will free all the allocated memory

  for(int i = 0; i < hashlen; i++) { //I am watching UFC fights while fixing this program
    listFree(table[i]); //easy call to listFree
  }
  free(table); //now lets free the table
  return; //return from this functiony
} //final closing curly in this file im gunna cry











