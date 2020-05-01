//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

int copyList(node * head, node *& copyRecipient );
int averageEvens(node * head, int & sum, int & avg, int & evenCount);
int smallSums(node * head, int & sum);
int removeTwo(node *& head);
int firstCount(node * head);
int firstCount(node * head, node & first, int & count);
int lastCount( node * head);
int lastCount(node * head, node *& last, int & count);
int countFour(node * head);
int tuckFirst(node *& head);
int tuckFirst(node *& head, node * first);
