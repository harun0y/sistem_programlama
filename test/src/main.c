/* Use the fields library to print each word on standard input, labeled with its line number. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
//#include <stdbool.h> //bool gerekirse

int main(int argc, char **argv)
{
    IS file; // girdi dosyası (input struct)
  	char *words[500];    //kelimelerin tutulduğu dizi
 	int wordFreq[500] = {0}; //kelimelerin tekrar değerlerinin tutulduğu dizi
	int sayac = 0; 	     //kelime sayacı
    if (argc != 2) { fprintf(stderr, "usage: printwords filename\n"); exit(1); 
}
 
    /* Open the file as an inputstruct.  Error check. */

    file = new_inputstruct(argv[1]);
    if (file == NULL) {
    	perror(argv[1]);
    	exit(1);
  	}
	
  	while(get_line(file) >= 0) {
    	for (int i = 0; i < file->NF; i++) {
    		words[sayac] = strdup(file->fields[i]); //strdup duplicate
      		for(int j = 0; sayac >= 1 && j < sayac; j++){     		
      			if(strcmp(words[sayac], words[j]) == 0){  //strcmp compare eşitse 0 döndürür
      				wordFreq[j] += 1;
      				sayac -= 1;
      			}   		
      		}
			sayac += 1;
    	}
    }
    
	printf("\nj-kelime-freq\n");
	
	for (int j = 0; j < sayac; j++) {
		printf("%d=>%s:%d\n", j, words[j], wordFreq[j]);
 	}

  	jettison_inputstruct(file);
  	return 0;
}
