/*
Rajpreet Judge
CSE 222
Nick Macias
02/13/2020
List.c file
This file contains all of the list functions that the hash functions live off of without these this program is uselss
*/
#include<stdio.h> //I mean you cant get a haircut
#include<string.h> //with out hair right?
#include<stdlib.h> //you can write code that works without these
#include"stuff.c" //well except for this one its the outlier here. this just contains prototypes and struct delc
		//blanky blanky space I might be going crazy right now
  		//IN THE END IT DOESNT EVEN MATTERRRRRRR
struct node *listInit() { // I HAD TO FALL TO LOSE IT ALLLLLLLL

  struct node *sent; //creating a sentinel node for each spot in the table within this fantasstic function

  sent = malloc(sizeof(struct node)); //calling malloc to allocate memory
  sent->next = NULL; //setting next feelds to null
  return (sent); //returning sentinel

} //SO THE PROGRAM CAN RUN WITH IT!!!! RICK ROLLED

//-------------------------------------------------

void listAdd(struct node*sent, char *plate, char *first, char *last) { // listAdd adds to the linkedlists

  struct node *newnode; //creating a new node
  
  newnode = malloc(sizeof(struct node)); // allocating memory for the new node 
					// this function made my screws loose then I tightened them back and now I CANNOT LOSE
  newnode->next = sent->next; //sent next field equals new nodes next
  sent->next = newnode;

  newnode->plate = malloc(strlen(plate)+1); //I am 90% sure i do notneed to add 1 but I did it anyways LOL
  newnode->first = malloc(strlen(first)+1); //possibly could just replace with malloc(32)
  newnode->last = malloc(strlen(last)+1); //possibly could just replace with malloc(32)

  strcpy(newnode->plate, plate); //assigning the plate first and last iunt hise 3 nxt staements 
  strcpy(newnode->first, first); // I am soo happy Im done atleast I think Im done HEHEHE
  strcpy(newnode->last, last); //in the face of Adversity WE MUST OVERCOME!!

  return; //we got er added into the list

}

//----------------------------------------

int listFind(struct node*sent, char *plate, char *first, char *last) { //I am listening to pretty hype music right now and I am very tempted to steal my own laptop
  
  struct node *newnode = sent->next;  //this is very similiar to the our search function from PA2 and pretty much just assignes the names which PA2 didnt do
 
  while(newnode != NULL) {
    if(strcmp(plate,newnode->plate) == 0) { // found it
      strcpy(first, newnode->first);
      strcpy(last, newnode->last);
      return 1; //retuning 1 for found the person so I can give them a ticket
    }
  newnode = newnode->next; //stepping throught the list
  }
  return 0; //returning 0 because the guy has a fake license plate and we need to arrest him
}

//------------------------------

void listPrint(struct node*sent) { //this just is EXACTLY THE SAME PRINT FUNCTION as PA2

  struct node *newnode = sent->next; //You know the deal already with this line

  while(newnode != NULL) { //looping until NULL
    printf("Plate: <%s>  Name: %s, %s\n", newnode->plate, newnode->first, newnode->last); //printing the Plate, name instead of a number
    newnode = newnode->next; //stepping through
  }
  return; //done with the printy's
}

//---------------------------------

int listLen(struct node *sent) { //I PUT MY LIFE INTO THIS

  struct node *newnode = sent->next; //well not really but I did spend a lot of time on this program for starting iton wedsnesday this week
  int i = 0; // variable i is not equal to 0 but it gets changes like right way LOL
  
  while(newnode != NULL) { //this server is lagging so hard right now, I want to just stop and not turn it in
    i++;
    newnode = newnode->next; //steeping throught list
  }
  return (i); //returnbing the variable i so we can tell how much nodes are in this lsit

}  
    
//-------------------------  
void listFree(struct node *sent) { //this function frees the allocated memory which gave me a headache becasue i had a heck of a time finding out why its not freeing everything

  struct node *freeme, *temp;  // this fucntion is very similiar to PA2 also, creating 2 nodes
  
  temp = sent->next; //assigning temp to equal sent next
  
  while(temp != NULL) { //looping until null
    freeme = temp; //dont want to free the node  lol we still need it
    temp = temp->next; // stepping through
    free(freeme->first); //freeing the first
    free(freeme->last); //freeing the last 
    free(freeme->plate); //freeing the palte
    free(freeme); //freeing that node
  }
  free(sent); //freeing the sentinel of that list
}




