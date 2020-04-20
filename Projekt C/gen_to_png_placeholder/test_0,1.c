#include <stdio.h>
#include <stdlib.h>

#define DIM = 3

//wypisuje gen na stdout
void display(int tab[3][3],int gen){
	printf("Gen number = %d\n",gen);
	int i,j;
	for(i=0;i<3;i++){
		puts("");
		for(j=0;j<3;j++)
			printf("%d ",tab[i][j]);
	}
	puts("");
}

// tworzy nowa generacje
int* next_gen(int** tab,int *gen){
	gen++;
	int i,j;
	for(i=0 ;i<2;i++){
		for(j=0;j<2;j++)
			tab[i][j]++;
	}
}

int main(int argc,char** argv) {
	int gen = 0; // numer gen
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int amount = argc > 1 ? atoi(argv[1]):2; //il generacji
	display(arr,gen);	
	
	return 0;
}
