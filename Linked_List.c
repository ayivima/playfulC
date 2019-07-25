


#include <stdio.h>
#include <stdlib.h>


typedef int ELEMENT;
typedef struct node
{
    ELEMENT data;
    struct node* next;
} NODE;


int traverseList(NODE *head, int listlen){
	
	if (listlen > 0){
		
		printf("\tList items: [%d", head->data);
				
		if(listlen>1){
			
			NODE* current = head->next;
		
			int i;		
			for(i=0; i<listlen-1; i++){
			
				printf(", %d", current->data);
				current = current->next;
					
			}
			
		}
		
		printf("]\n");
			
	}
	
}



int addNewNode(NODE *head, int newData, int listLength){
	
	
	if (listLength == 0)  /* if the first node has no data, add data to it*/
	{
		head->data= newData;	
	} 
	else  /* append the new node if list is not empty */	
	{
		
		NODE *current = head;
		
		int i;		
		for (i=0; i<listLength-1; i++) /* loop to the last node and assign it to the pointer 'current' */
		{
			
			current = current->next;
			
		}
	
		NODE* newNode = malloc(sizeof(NODE));
		
		newNode->data = newData;
		newNode->next = NULL;
			
		current->next = newNode; /* link new node to the last node */
	
	}
	
	printf("\n\t----------\n\tNew node added to list \n");
			
	return 0;
	
}


int insertNode(NODE* head, int newData, int position){
	
			
		NODE* newNode = malloc(sizeof(NODE)); /*Allocate memory for new node */
		NODE* afterIn; /* pointer to the node that the new node will be inserted before */
		NODE* beforeIn; /* pointer to the node that the new node will be inserted after */
		NODE* current = head; /* assign pointer 'current' to the first node. this will be used in 'for loop' below*/
		
		
		newNode->data = newData; /* assign new data to the new node*/
		
		
		/*Loop to the position of insertion of new node */
		int i;
		for (i=0; i<position; i++){
			
			beforeIn = current; /* get the pointer to the node that will come before the inserted node */
			afterIn = current->next; /* get the pointer to the node that will follow the inserted node */
			current = current->next; 
			
		}
	
		beforeIn->next = newNode;
		newNode->next = afterIn;
		
				
		printf("\n\t----------\n\tNew node successfully inserted at index %d \n", position);
			
		return 0;
	
}


int deleteNode(NODE *head, int position, int listlen){
	
	NODE* current;
	NODE* newHead;
	NODE* afterN; 
	NODE* beforeN;
	NODE* deletable;
	
	
		
		current= head;
			
		int i;
		for (i=0; i<position; i++){
						
			beforeN = current;
			current = current->next;
					
		}
			
		deletable = current;
				
		if (listlen>1){
					
			if (position == 0){
				
				deletable= head->next;
				head->next = deletable->next;
				head->data = deletable->data;
			
			} else {
				
				beforeN->next = deletable->next;
			
			}
			
		}	
							
		free(deletable);
		
	
	printf("\n\t----------\n\tNode Deletion at index %d successful \n", position);
	return 0;
	
}


void showMenu(){
	printf("OPERATIONS MENU\n");
	printf("1 = Add New Node\n");
	printf("2 = Insert New Node\n");
	printf("3 = Delete A Node\n");
	printf("4 = Traverse List & Display Elements\n");
	printf("5 = End Program\n");
	printf("Please enter an operation number >> ");
}

int main(int argc, char *argv[]) {
	
	/* create an empty list */
	NODE* head = malloc(sizeof(NODE));
	
		
	int option = 0;
	int listlen = 0;
	char response; 
		
	entry:
	showMenu();	
	scanf("%d", &option);
	printf("\n");	
	
	if(option>5)
	{
		printf("\nInvalid Entry!\n");
		goto entry;
	}
		
	switch(option){
			
			int theData, position;
						
			case 1:
				printf("--- ADD NEW NODE --- \n");
				printf("Enter new element: ");
				scanf("%d", &theData);
				addNewNode(head, theData, listlen);
				
				listlen++;
				traverseList(head, listlen);
				printf("\tLength of list: %d\n\t----------\n\n", listlen);
				
				system("pause");
				goto entry;
				break;
			
			case 2:
				printf("--- INSERT A NODE --- \n");
				printf("Enter new element: "); 
				scanf("%d", &theData);   /* get the new number to be added */
				printf("Enter position to insert element: "); 
				scanf("%d", &position);   /* get the insertion position */
				
				if ((position < listlen) && (position > 0)) /* check if insertion index(position) is not equal to zero or not greater than the position of last-but-one node*/
				{
					insertNode(head, theData, position); /* proceed with insertion if index(position) is within range*/
					
					listlen++;
					traverseList(head, listlen); 
					printf("\tLength of list: %d\n\t----------\n\n", listlen);
					
				} else {
					printf("Insertion position is out of range \n\n"); /* alert user if index(position) is out of range*/
				}
				
				system("pause");
				goto entry;
				break;
			
			case 3:
				
				printf("--- DELETE A NODE --- \n");
				traverseList(head, listlen);
				printf("\nEnter position from which element should be deleted (0 - %d): ", listlen-1);
				scanf("%d", &position);
				
				if ((position < listlen)&&(position>=0)) /* check if deletion index(position) is not equal to zero or not greater than the position of last-but-one node*/
				{
					deleteNode(head, position, listlen);  /* proceed with deletion if index(position) is within range*/
					/* printf("head: %d\n", head->data); */
					listlen--;
									
					traverseList(head, listlen);
					printf("\tLength of list: %d\n\t----------\n\n", listlen);
					
				} else {
					printf("Deletion position is out of range \n"); /* alert user if index(position) is out of range*/
				}
				
				system("pause");
				goto entry;
				break;
				
			case 4:
				
				printf("--- TRAVERSE LIST & DISPLAY ELEMENTS --- \n");
				printf("\n\t----------\n\tDisplaying List Items...\n", listlen);
				traverseList(head, listlen);
				printf("\tLength of list: %d\n\t----------\n\n", listlen);
				
				system("pause");				
				goto entry;
				break;
				
			case 5:
							
				goto ending;				
				break;
		}
	
	ending:
	printf("Freeing up memory allocated... \n");
	
	if (listlen > 0){
				
		int i;
		for (i=listlen-1; i>=0; i--){
			
			deleteNode(head, i, i + 1);
			
		}
	}
		
	printf("\nProgram ended successfully\n");
	system("pause");
	
	return 0;
}

