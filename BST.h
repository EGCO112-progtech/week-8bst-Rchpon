// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*              

typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );
//void insertNode_R(TreeNodePtr *t ,int value);
void preOrder(TreeNodePtr treePtr);
void inOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

/*void insertNode_R(TreeNodePtr * t,int value){
   if (*t == NULL) {
      
      TreeNodePtr new_node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
      if (new_node == NULL) {
          printf("Memory allocation failed\n");
          return;
      }
      new_node->data = value;
      new_node->leftPtr = NULL;
      new_node->rightPtr = NULL;
      *t = new_node; 
  } else {
      
      if (value < (*t)->data) {
          insertNode_R(&((*t)->leftPtr), value);
      }
     
      else if (value > (*t)->data) {
          insertNode_R(&((*t)->rightPtr), value);
      }
  }
}*/

void insertNode( BST *b, int value ){
	 TreeNodePtr t = b->root,new_node;
	 int inserted=0;
	new_node =(TreeNodePtr)malloc(sizeof(struct TreeNode));
   
	if(new_node) {
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value; 
		/*First Node*/
		if(!b->root) { b->root=new_node; } 

		else {
            while(!inserted){
               if(t->data >=value){
            /* move/insert to the left*/
                  if(t->leftPtr==NULL) {
                     t=t->leftPtr = new_node;
                     inserted = 1;
               }
               else{t=t->leftPtr;}
            }
            else{
                  /* move/ insert to the right*/
                  if(t->rightPtr==NULL) {
                     t=t->rightPtr = new_node;
                     inserted = 1;
               }
               else{t=t->rightPtr;}
            }
         }//end while	
 	   }//end else;
      b->size++;
   }
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void preOrder(TreeNodePtr treePtr)
{
   if ( treePtr != NULL ) {
   printf("%3d",treePtr->data);
   preOrder( treePtr->leftPtr );
   preOrder( treePtr->rightPtr ); }
}

void postOrder(TreeNodePtr treePtr)
{
   if ( treePtr != NULL ) {
   postOrder( treePtr->leftPtr );
   postOrder( treePtr->rightPtr );
   printf("%3d",treePtr->data); }
}

void printTree(TreeNodePtr root, int space) {
   if (root == NULL) return;

   space += 5;  

   printTree(root->rightPtr, space);

   printf("\n");

   for (int i = 5; i < space; i++) {
       printf(" ");
   }
   printf("%d\n", root->data);

   printTree(root->leftPtr, space);
}