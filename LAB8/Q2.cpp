//Implementation of the question
#include<stdlib.h>
#include<cstdio>
class Tree{
    private:
    struct node{
          int data;
          struct node *right;
          struct node *left;
    };
    node *root;

    public:
 Tree()
 { 
    //Constructor
    root=NULL;
  }
void insert(char direction,int num);
void preorder();
void inorder();
void postorder();
int search(int num);
};
int main(){
    Tree t;
    int choice,num;
    char direction;
    do{
        //Menu
        printf("\nMENU\n");
        printf("1.Insertion\n");
        printf("2.Preorder\n");
        printf("3.Inorder\n");
        printf("4.Postorder\n");
        printf("5.Search\n");
        printf("6.Exit\n");
        printf("Enter the choice from the above Menu to perform the respective operation on the Tree:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&num);
                t.insert(direction,num);
                break;
            case 2:
                printf("Preorder Traversal: ");
                t.preorder();
                break;
            case 3:
                printf("Inorder Traversal: ");
                t.inorder();
                break;
            case 4:
                printf("Postorder Traversal: ");
                t.postorder();
                break;
            case 5:
                printf("Enter the number to be searched: ");
                scanf("%d",&num);
                if((t.search(num))!=0){
                    printf("Integer '%d' found in the tree.\n",num);
                }
                else{
                    printf("Integer '%d' not found",num);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!Try again\n");
 
        }
    }while(choice!=6);
    return 0;
}
//Function for insertion into the binary tree
void Tree :: insert(char direction,int num){
    struct node *new_node=(node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->left=NULL;
    new_node->right=NULL;
    if(root==NULL){
        root=new_node;
    }
    else{
        node *temp=root;
        while(true){
            printf("Do you want to Insert at Left(L) or right (R) of %d: ",temp->data);
            scanf(" %c",&direction);
            if((direction=='L'||direction=='l')){
                if(temp->left==NULL){
                    temp->left=new_node;
                    break;
                }
                else{
                    temp=temp->left;
                }
            }
            else if((direction=='R'||direction=='r')){
                if(temp->right==NULL){
                    temp->right=new_node;
                    break;
                }
                else{
                    temp=temp->right;
                }
            }else{
                printf("Invalid chpoice.Please enter L or R.\n");
            }
        }
}
}

//Traverses from Root Left and right
void Tree::preorder() {
        if (root == NULL) {
            printf("Tree is empty.\n");
            return;
        }
        struct node *stack[100]; 
        int top = -1;
    
        stack[++top] = root; 
    
        while (top >= 0) {
            struct node *temp = stack[top--]; 
            printf(" %d ", temp->data);
            if (temp->right != NULL) {
                stack[++top] = temp->right;
            }
            if (temp->left != NULL) {
                stack[++top] = temp->left;
            }
        }
        printf("\n");
    }
    
//Traverses from Left Root Right
void Tree::inorder(){
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    struct node *stack[100];
    int top = -1;
    struct node *temp = root;
    while (temp != NULL || top >= 0) {
        while (temp != NULL) {
            stack[++top] = temp;
            temp = temp->left;
        }
        temp = stack[top--];
        printf(" %d ", temp->data);
        temp = temp->right;
    }
    printf("\n"); 
}

//Traversers from Left Right Root
void Tree::postorder(){
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    struct node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct node *temp = stack1[top1--];
        stack2[++top2] = temp;
        if (temp->left != NULL) {
            stack1[++top1] = temp->left;
        }
        if (temp->right != NULL) {
            stack1[++top1] = temp->right;
        }
    }
    while (top2 >= 0) {
        printf(" %d ", stack2[top2--]->data);
    }
    printf("\n");
}

//Function to search for the given value
int Tree::search(int num){
   node *temp=root;
   while(temp!=NULL){
    if(temp->data==num) return 1;
    if(num<temp->data){
        temp=temp->left;
    }
    else{
        temp=temp->right;
    }
   }
return 0;
}
