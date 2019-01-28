/*
*Run ID : 57339
*Jason Flynn : 201037312
*Assignment One Comp 281
*/

// include standered i/o library 
#include <stdio.h>
 
// main thread
int main() {
  int a, b, temp, intOne, intTwo, largComFact, lowComMult;
 
  scanf("%d", &intOne) ; // scans in first intiger 
  scanf("%d", &intTwo); // scans in second intiger 
 
  a = intOne; // gives a value of first int
  b = intTwo; // givs b value of second int 
 
	// whal the value of be is not = to zoero continue loop 
  while (b != 0) {
    temp = b; // makes temp = to second int 
    b = a % b; // second int = to the remander of second int divided by first int 
    a = temp; // a now equal to origanal value of second int 
  }
 
  // once b = 0 a will be = largest commen factor 
  largComFact = a;
  // lowest comen multiplyer = origonal value of first int * origanal valu of second int 
  // devided by the final value of a 
  lowComMult = (intOne*intTwo)/largComFact ;
 
  printf("%d ", largComFact); // print LCF
  printf("%d ", lowComMult);  // print LCM 
 
  return 0;
}