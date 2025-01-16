#include<stdio.h>
#include<stdlib.h>
#define size 5
class hash
{
    struct node
    {
        int data;
        struct node *next;
    };
    int cur;
    struct node *adjacencylist[size];
    struct node *head;
    public:
    hash()
    {
        for (int i=0;i<size;i++)
        {
            adjacencylist[i]=NULL;
        }
        cur=0;
    }
    int insert (int u,int v);
    void display();
    void ldis(struct node *head);
    int search(int v);
    int del(int v);
};

int main()
{
    hash h1;
    int choice;
    while(1)
    {
        printf("\n(1) Insert");
        printf("\n(2) Delete");
        printf("\n(3) Search");
        printf("\n(4) Display");
        printf("\n(5) Exit");
        printf("\n Enter your choice");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
            int v11,v12;
            printf("Enter the vertex 1:");
            scanf("%d",&v11);
            printf("Enter the vertex 2:");
            scanf("%d",&v12);
            if(h1.insert(v11,v12))
            {
               printf("Element is inserted successfully");
            }
            else
            {
                printf("fail");
            }
            break;

            case 2:
            int v21;
            printf("Enter the vertex to be deleted");
            scanf("%d",&v21);
            if(h1.del(v21))
            {
                printf("Number is deleted successfully");
            }
            else
            {
                printf("Element is not present");
            }
            break;

            case 3:
            int v3;
            printf("Enter the vertex to search");
            scanf("%d",&v3);
            
            if(h1.search(v3))
            {
                printf("Element is found");
            }
            else
            {
                printf("Element is not found");
            }
            break;

            case 4:
            h1.display();
            break;
            
            case 5:
            return 0;
        }
    
    }
}

//method to insert the element
int hash:: insert(int v1,int v2)
{
    struct node *newnode1=(struct node *)malloc(sizeof(struct node));
    struct node *newnode2=(struct node *)malloc(sizeof(struct node));
    
    newnode1->data=v1;
    newnode1->next=NULL;
    newnode2->data=v2;
    newnode2->next=NULL;

    for (int i=0;i<cur;i++)
    {
        if(adjacencylist[i]->data==v1)
        {
            for(int k=0;k<cur;k++)
            {
                if(adjacencylist[k]->data==v2)
                {
                struct node *temp=adjacencylist[i];
                while(temp->next!=NULL)
                { 
                temp=temp->next;
                }
                temp->next=newnode2;
                return 1;
                }
            }
            adjacencylist[cur]=newnode2;
            cur++;
            return 1;
        }
        if(adjacencylist[i]->data==v2)
        {
            for(int k=0;k<cur;k++)
            {
                if(adjacencylist[k]->data==v1)
                {
                struct node *temp=adjacencylist[i];
                while(temp->next!=NULL)
                { 
                temp=temp->next;
                }
                temp->next=newnode1;
                return 1;
                }
            }
            adjacencylist[cur]=newnode1;
            cur++;
            return 1;
        }
    }
    if(v1==v2)
    {
        adjacencylist[cur]=newnode1;
        adjacencylist[cur]->next=newnode2;
        cur++;
        return 1;
    }
    adjacencylist[cur]=newnode1;
    adjacencylist[cur+1]=newnode2;
    cur+=2;
    return 1;
}

// method to display
void hash:: display()
{
   for(int i=0;i<cur;i++)
   {
    printf("%d\t",adjacencylist[i]->data);
   }
}

// method to delete the element
int hash:: del(int v)
{
    for (int i=0;i<cur;i++)
    {
        if(adjacencylist[i]->data==v)
        {
            adjacencylist[i]=NULL;
            for (int k=i;k<cur;k++)
            {
                adjacencylist[k]=adjacencylist[k+1];
            }
            cur--;
            return 1;
        }
    }
    return 0;
}
//method to search

int hash::search(int v)
{
    for (int i=0;i<cur;i++)
    {
        if(adjacencylist[i]->data==v)
        {
            return 1;
        }
    }
    return 0;
}