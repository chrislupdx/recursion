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

//count the # of items that are the same as the 1st
