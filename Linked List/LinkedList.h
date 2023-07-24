#ifndef LinkedList_H_
#define LinkedList_H_
typedef struct n{
    int info;
    struct n* link;
}node;

node* InserInBeg(node* start,int data);
void InserAtE(node* start,int data);
node* CreatList(node* start);
void DisplayList(node*start);
#endif
