#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "jrb.h"
//#include <stdbool.h> //bool gerekirse

int main(int argc, char **argv)
{
	JRB b;
	JRB bn;
    IS file; // girdi dosyası (input struct)
  	char* kelime; 		//kelimelerin tırnaklardan ayrılmış hâli(words'e düzgün atama için)
	char* kod;			//kodların tırnaklardan ayrılmış hâli(words'e düzgün atama için)
	
    if (argc != 2) { fprintf(stderr, "usage: printwords filename\n"); exit(1); 
}
 
    /* Open the file as an inputstruct.  Error check. */

    file = new_inputstruct(argv[1]);
    b = make_jrb();
    
    if (file == NULL) {
    	perror(argv[1]);
    	exit(1);
  	}
	
  	while(get_line(file) >= 0) {
    	
    		if(file->NF != 1){
    			kelime = strtok(file->fields[file->NF-2], "\""); //strtok tırnaklardan ayırıyor
				kod = strtok(file->fields[file->NF-1], "\""); 

    			(void) jrb_insert_str(b, strdup(kelime), new_jval_s(strdup(kod)));
    		}
      	
    }
	
	jrb_traverse(bn,b) {
    	printf("%s\t%s\n", bn->key.s, bn->val.s);	
  	}
	
  	jettison_inputstruct(file);
  	return 0;
}
