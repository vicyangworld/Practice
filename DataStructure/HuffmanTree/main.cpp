#include "HTree.h"

int main(){
	int arr[]={
			1,2,3,4,5,6,7
		};
	HTree Htree(arr,sizeof(arr)/sizeof(int));
	Htree.View();
	getchar();
}
