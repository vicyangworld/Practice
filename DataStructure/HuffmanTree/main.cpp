#include <stdlib.h>
#include "HTree.h"

int main(){
	int arr[]={
			1,2,3,4,5,6,7
		};
	HTree Htree(arr,sizeof(arr)/sizeof(int));
	Htree.View();
	Htree.Incode();
	char cd[] = "010";
	Htree.Decode(cd);
}