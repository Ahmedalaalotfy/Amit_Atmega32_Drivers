#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
node* InserInBeg(node* start,int data){
    node*temp=(node*)malloc(sizeof(node));
	if(temp != NULL){
		temp->info=data;
		temp->link=start;
		start=temp;
	}
	return start;
	}
void InserAtE(node* start,int data){ //insert at the end

        node*temp=(node*)malloc(sizeof(node));
		if(temp != NULL){
		node*ptr=start; //تعريف بوينتر  للتنقل داخل الينك ليست
		temp->info=data;
		while(ptr->link!=NULL){
		ptr=ptr->link;
		}
		ptr->link=temp;//البوينتر يشاور على عنوان الداتا الي هضيفها
		temp -> info=data;
		temp->link=NULL;
	}
	}
node* CreatList(node* start){
	int NumberOfNodes,data,counter;
	printf("Enter the number of nodes:");
	scanf("%d",&NumberOfNodes);
	printf("\nEnter the first element to insert:");
	scanf("%d",&data);
	start=InserInBeg(start,data);
	for(counter=1;counter<NumberOfNodes;counter++){
			printf("\nEnter the element number (%d) :",counter+1);
			scanf("%d",&data);
			InserAtE(start,data);
	}
	return start;
}
void DisplayList(node*start){
	node*ptr=start;
	printf("\nthe Linked list elements:");
	while(ptr!=NULL){
		printf("%d \t",ptr->info);
		ptr=ptr->link;
	}
}


