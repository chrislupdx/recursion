#include "list.h" 
int copyList(node * head, node *& copyRecipient) {
   //1. Simple case
   if(!head) //empty list or we reached the end
   {
    copyRecipient = NULL;
       return 0;
   }
    //2. Other case to consider (if we reach the end)

    //3. what needs to be done before going into the smaller subproblem

   //node * new_copy = new node;
    copyRecipient = new node; //copyREcipient is alias for for the head of the new list
    
    copyRecipient->data = head->data; //copy data into new node
    //makea recursive call of copyList, passing in head->next and copy_recipient
    return 1 + copyList(head->next, copyRecipient->next);
}

int averageEvens(node * head, int & sum, int & avg, int & evenCount) {
   if(!head) return 0;      //check if we need to zero anythig

                            //on the way through the list
    if(head->data % 2 == 0)
    {
        evenCount += 1; //if we initialiize sum, avg, or evenCount in here, we'll lose that to the stack frame
        sum += head->data;  //add the data into the sum
    }
   
   int count = 1 + averageEvens(head->next, sum, avg, evenCount); //this counts for each time the function is called, does this actually do an evencount?

   //on the way back from the list

    avg = sum / evenCount;
   
    return count;
}

//sum al of the data less than 10 in a LLL
int smallSums(node * head, int & sum)
{
    if(!head) return 0;  //check if there are any edge casees

    //on the way through the list
    if(head->data < 10)
    {
    sum += head->data; 
    }

    smallSums(head->next, sum);
    
    //on the way back from the list
    return 1;
}

//remove every data item == 2 in a LLL
int removeTwo(node *& head)
{
   if(!head) return 0;

    //on the way through the list
    //oh my! do we skip stuff?
    removeTwo(head->next);
    
   //one the way back from the list
   //what would it be like do delete on the return trip?

    if(head->data == 2) // remove this node if it's yeah
    {                   //I think we need a prev
        node * temp = head->next; //this points to null if we do it after the resursive call (we're at the tail, pinting to null)
        delete head;
        head = temp; //put it back together
    }    

    return 1;
} 

//count the # of items that are the same as the 1st int firstCount(node * head, node * first, int & count) {
int firstCount(node * head, node * first, int & count ){
    if(!head) return 0; //check if there are caveats //on the way through the list 
    if(head->data == first->data)
    {
    count++;
    }
    
    firstCount(head->next, first, count);
    //on the way back from the list
    return 1;
}

int firstCount(node * head)
{
    if(!head) return 0;
    node * first = head;
    int count = 0; 
    //on the way through the list
    firstCount(head, first, count);
    //on the way back from the list
    return count;
}

int lastCount(node * head, int & lastData) //find last
{
    if(!head) return 0;
    //on the way through the list
    if(head->next == NULL)
    {
        lastData = head->data;
    }
    int finalCall = lastCount(head->next, lastData); //final call will hold the value of the number of nodes that match the last data item in the rest of the list
    //on the way back through the list
    if(head->data == lastData)
    {
        finalCall++;
    }
    return finalCall; //LOOK AT THIS AWESOMENESS
}

int lastCount(node * head)
{
    if(!head) return 0;
    //on the way through the list
    int lastData = 0;
    int count =+ lastCount(head, lastData); //if a match, add to count hopefully
    //on the way back from the list
    return count;
}

int countFour(node * head) //count items 4 or greater
{
    if(!head) return 0; 
    //on the way through the list
        
    int count =+ countFour(head->next);
   
    //on the way back
    if(head->data >= 4)
    {
    count++;
    }
    return count;
}

//This is the wrapper, it'll remove the first node
int tuckFirst(node *& head) // remove the first node 
{
    if(!head) return 0;
    node * first = new node; //provision a new node
    first->data = head->data; //copy data into new node
    
    node * next = head->next;
    delete head; 
    head = next;
    tuckFirst(head, first);    
    
    return 1;
}

int tuckFirst(node *& head, node * first) //first is passed as zero
{
    while(!head) return 0;
    //on the way to the end
       
    tuckFirst(head->next, first); //reach last
   
    if(head->next == NULL) //if we are at the last
    {
        head->next = first;
        first->next = NULL; 
    }
   
   //on the way back 
    
        return 1; 
}


