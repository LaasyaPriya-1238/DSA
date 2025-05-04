//Program to implement graph using adjacency matrix
#include <cstdio>
#include<iostream>
using namespace std;
class graph{
    private:
    int numvertices;
    int matrix[20][20];
    public:
    graph(int vertices){
        if(numvertices>20){
            cout<<"Max allowed vertices 20"<<"\n";
            vertices = 20;
        }
        numvertices = vertices;
        for(int i=0;i<numvertices;i++){
            for(int j=0;j<numvertices;j++){
                matrix[i][j]=0;
            }
        }
    }
    int insert(int,int);
    int delete1(int,int);
    int search(int,int);
    void display();
};
int main(){
    int choice;
    int src;
    int dest;
    int vertices;
    cout<<"Enter number of vertices:";
    cin>>vertices;
    graph g1(vertices);
    while(1){
        printf("Enter 1 for insert\nEnter 2 for delete\nEnter 4 for search\n");
        printf("Enter 4 for display\nEnter 5 for exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the src vertex to insert:");
            scanf("%d",&src);
            printf("Enter the dest vertex: to insert");
            scanf("%d",&dest);
            g1.insert(src,dest);
            break;
            case 2:
            printf("Enter the src vertex to delete:");
            scanf("%d",&src);
            printf("Enter the dest vertex to delete:");
            scanf("%d",&dest);
            g1.delete1(src,dest);
            break;
            case 3:
            printf("Enter the src vertex to search for:");
            scanf("%d",&src);
            printf("Enter the dest vertex to search for:");
            scanf("%d",&dest);
            g1.search(src,dest);
            break;
            case 4:
            g1.display();
            break;
            case 5:
            return 0;
            default:
            printf("Enter valid choice\n");
        }
        printf("\n");
        printf("\n");
    }
    return 0;
}
//Function to insert elements
int graph::insert(int src,int dest){
    if(src > numvertices || src < 0 || dest > numvertices || dest < 0){
        cout<<"Enter valid src and dest values";
        return -1;
    }
    matrix[src][dest] = 1;
    matrix[dest][src] = 1;
    cout<<"inserted successfully!!!";
    return 1;
}
//Function to delete elements
int graph::delete1(int src,int dest){
    if(src > numvertices || src < 0 || dest > numvertices || dest < 0){
        cout<<src<<"and/or"<<dest<<"vertices dont exist"<<"\n";
        return -1;
    }
    if(matrix[src][dest]!=1){
        cout<<src<<"and"<<dest<<"are not connected"<<"\n";
        return -1;
    }
    matrix[src][dest] = 0;
    matrix[dest][src] = 0;
    return 1;
}
//Function to search for elements
int graph::search(int src,int dest){
    if(src > numvertices || src < 0 || dest > numvertices || dest < 0){
        cout<<src<<"and/or"<<dest<<"vertices dont exist"<<"\n";
        return -1;
    }
    if(matrix[src][dest] == 1){
        cout<<"Edge exists between"<<src<<"and"<<dest<<"\n";
        return 1;
    }
    cout<<"Edge does not exist between"<<src<<"and"<<dest<<"\n";
    return -1;
}
//Function to display elements
void graph::display(){
    for(int i=0;i<numvertices;i++){
        cout<<i<<"   ";
    }
    cout<<"\n";
    for(int i=0;i<numvertices;i++){
        cout<<i<<"   ";
        for(int j=0;j<numvertices;j++){
            cout<<matrix[i][j]<<"   ";
        }
        cout<<"\n";
    }
}