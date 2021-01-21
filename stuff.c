/*
Rajpreet Judge
CSE 222
Nick Macias
02/13/2020
Just to makes the program look cleaner basically
*/
struct node { //creating our structure for our nodes
  char *plate; //where plate numbers are stored
  char *first; //where first names
  char *last; //where last names
  struct node *next;
};

typedef struct node* hashEntry;
//just function prototypes imnot gunna bother commenting the rest
int hash(char *);
hashEntry *hashInit(int);
void hashAdd(hashEntry *, char *, char *, char *);
int hashFind(hashEntry *, char *, char *, char *);
void hashLoad(hashEntry *);
void hashDump(hashEntry *, int);
void hashFree(hashEntry *);

struct node *listInit();
void listAdd(struct node *, char *, char *, char *);
int listFind(struct node *, char *, char *, char *);
int listLen(struct node *);
void listPrint(struct node *);
void listFree(struct node *);


