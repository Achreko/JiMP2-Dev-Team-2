#include <stdio.h>
#include <stdlib.h>

#define COL 4
#define WER 5

//wypisuje gen na stdout
void display(int tab[COL][WER],int gen){
	puts("");
	printf("Gen number = %d\n",gen);
	int i,j;
	for(i=0;i < COL;i++){
		puts("");
		for(j=0;j < WER;j++)
			printf("%d ",tab[i][j]);
	}
	puts("");
}

// tworzy nowa generacje
int next_gen(int tab[COL][WER]){
	int i,j;
	for(i=0 ;i<COL;i++){
		for(j=0;j<WER;j++)
			tab[i][j]++;
	}
}

int main(int argc,char** argv) {
	int amount = argc > 1 ? atoi(argv[1]):2; //il generacji
	int gen = 0; // numer gen
        int arr[COL][WER] = {};
	for(int i=0;i < amount;i++) {
		display(arr,gen++);
		next_gen(arr);
	}
	
	return 0;
}
