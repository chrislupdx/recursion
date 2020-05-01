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

//int lastCount(node * head, node *& last, int & count) //find last
//{
//    if(!head) return 0;
//
//    //on the way through the list
//    if(head->next == NULL)
//    {
//        last = head;
//    }
//    
//    lastCount(head->next, last, count); //it doesn't know what last is
//    //on the way back through the list
//    if(head->data == last->data)
//    {
//        count++;
//    }
//    return 0; 
//}
//
//int lastCount(node * head)
//{
//    if(!head) return 0;
//    node * last = NULL;
//    //on the way through the list
//    //int count = 0; 
//    int count += lastCount(head, last, count); //if a match, add to count hopefully
//    //on the way back from the list
//    return count;
//}

//count the number of items in the list that same as last //I don't think this works bc we blow our load getting to the last already and everything is weird stackframes
//int lastCount(node * head) //This wrapper grabs the last 
//{
//    if(!head) return 0;
//    node * last = NULL; //on the way through the list
//    if(head->next == NULL) //if at the last
//    {
//        last = head;
//    } 
//   // int count = 1 + lastCount(head->next); //count # of items in LLL
//    lastCount(head, last, count); 
//    
//    //if(head->data != last->data)
//    //{
//    //    std::cout << "return " << head->data << endl; 
//    //    count--;
//    //}
//    return count;
//}
//
//int lastCount(node * head, node * last, int & count) //this decrements the count so only matches remain
//{
//    if(!head) return 0;
//    std::cout << "count is " << count << endl; 
//   
//    //on the way to through the list? (or is it backwards)
//    if(head->data != last->data) //it's segfaulting here??
//    {
//        std::cout << "bad match" << endl; 
//        //count--;
//    }
//    
//    lastCount(head->next, last, count);
//   
//    //on the way back 
//    
//    return count;
//}
