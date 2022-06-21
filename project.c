	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define MAX 30
	 
	struct emp_data
	{
	    int  empno;
	    char empName[MAX];
	    char dept[MAX];
	   
	    struct emp_data *next;
	};
	 
	/* ********************************************************************/
	/*  Function to insert a node at the start of the linked list.        */
	/*  start: start pointer, id: employee ID, name: employee name        */
	/*  desg: Employee designation                                        */
	/*  Returns the new start pointer.                                    */
	/* ********************************************************************/
	struct emp_data *insert(struct emp_data *start, int id, char name[],char dept[])
	{
	    struct emp_data *temp;
	 
	    temp = (struct emp_data*)malloc(sizeof(struct emp_data));
	 
	    
	    temp->empno = id;
	    strcpy(temp->empName, name);
	    strcpy(temp->dept,dept);
	    
	    temp->next = start;
	    start =  temp ;
	    return(start);
	}
	/*  End of insert() */
	 
	/*  Function to display a node in a linked list */
	void printNode(struct emp_data *p)
	{
	    printf("\n Employee Details...\n");
	    printf("\n Emp No       : %d", p->empno);
	    printf("\n Name           : %s", p->empName);
	    printf("\n department   : %s\n", p->dept);
	    
	    printf("\n-------------------------------------\n");
	}
	/*  End of printNode() */
	 
	/*  ********************************************************/
	/*  Function to deleteNode a node based on employee number */
	/*  start: start pointer, id: Key value                    */
	/*  Returns: the modified list.                            */
	/*  ********************************************************/
	struct emp_data* deleteNode(struct emp_data *start, int id)
	{
	    struct emp_data *ptr;
	    struct emp_data *bptr;
	 
	    if (start->empno == id)
	    {
	        ptr = start;
	        printf("\n Node deleted:");
	        printNode(start);
	        start = start->next;
	        free(ptr);
	        return(start);
	    }
	    for (ptr = start->next, bptr = start; ptr != NULL; ptr = ptr->next,
	bptr = bptr->next)
	    {
	        if (ptr->empno == id)
	        {
	            printf("\n Node deleted:");
	            printNode(ptr);
	            bptr->next = ptr->next;
	            free(ptr);
	            return(start);
	        }
	    }
	    printf("\n Employee Number %d not found ", id);
	    return(start);
	}
	/*  End of deleteNode() */
	 
	/* ****************************************************************/
	/*  Function to search the nodes in a linear fashion based emp ID */
	/*  start: start pointer, key: key ID.                            */
	/* ****************************************************************/
	void search(struct emp_data *start, int key)
	{
	    struct emp_data *ptr;
	 
	    for (ptr = start; ptr != NULL; ptr = ptr -> next)
	    {
	        if (ptr->empno == key)
	        {
	            printf("\n Employee found:");
	            printNode(ptr);
	            return;
	        }
	    }
	    printf("\n Employee Number %d not found ", key);
	}
	/*  End of search() */
	 
	/*  Function to display the linked list */
	void display(struct emp_data  *start)
	{
	    struct emp_data *ptr;
	 
	    for (ptr = start; ptr != NULL; ptr = ptr->next)
	    {
	        printNode(ptr);
	    }
	}
	/*  End of display() */
	 
	
	 
	/*  Function to select the option */

	/*  The main() program begins */
	void main()
	{
	    struct emp_data *linkList;
	    char name[21], dept[30];
	    int choice;
	    int eno;
	 
	    linkList = NULL;
	    printf("\n WELCOME TO PROJECTON EMPLOYEE RECORD USING LINKED LIST  \n");
	    
	    while(1)
	    {    printf("\n---------------------------------------------\n");
	   		 printf("\nPress 1 to INSERT EMPLOYEE DETAILS:       \n");
	    	  printf("\nPress 2 to DELETE A EMPLOYEE DETAILS:      \n");
	   		 printf("\nPress 3 to DISPLAY EMPLOYEES DETAILS:               \n");
	   		 printf("\nPress 4 to SEARCH THE EMPLOYEE IN LIST:                   \n");
	   		 printf("\nPress 5 to EXIT                              \n");
	    	 printf("\n---------------------------------------------\n");
	        /*  choose operation to be performed */
	        printf("\n enter your choice :");
	        scanf("%d",&choice);
	        switch(choice)
	        {
	        case 1:
	            printf("\nEnter the Employee Number  : ");
	            scanf("%d", &eno);
	            printf("\nEnter the Employee name   : ");
	            fflush(stdin);
	            gets(name);
	            printf("\nEnter the Employee Department : ");
	            gets(dept);
	            linkList = insert(linkList, eno, name, dept);
	            break;
	        case 2:
	            printf("\n\n Enter the employee number to be deleted: ");
	            scanf("%d", &eno);
	            linkList = deleteNode(linkList, eno);
	            break;
	        case 3:
	            if (linkList == NULL)
	            {
	                printf("\n List empty.");
	                break;
	            }
	            display(linkList);
	            break;
	        case 4:
	            printf("\n\n Enter the employee number to be searched: ");
	            scanf("%d", &eno);
	            search(linkList, eno);
	            break;
	        case 5: 
				exit(0);
			default:
				printf("\nyou choose wrong option!!\n");
	        }
	    } 
	}

