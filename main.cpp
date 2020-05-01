#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    //node * new_copy = NULL; 
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    //int sum = 0;
  //  int avg = 0;
  //  int evenCount = 0;
   //   removeTwo(head); 
   // smallSums(head, sum);
   // averageEvens(head, sum, avg, evenCount);
   //cout << "sum is " << sum << endl;
   // cout << " avg is " << avg << endl;
   // cout << "evenCount is " << evenCount << endl;
   // cout << firstCount(head) << "is number of 1s" << endl;  
    cout << lastCount(head) << "is number of matching lasts" << endl; 
   
   display(head); //redisplay the list after your function
    destroy(head); 
    return 0;
}
