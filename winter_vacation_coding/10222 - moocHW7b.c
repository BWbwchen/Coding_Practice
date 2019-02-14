#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


typedef struct Menu{
    char name[51];
    float price;
    float review;
    int  num_reviews;
} Menu;

int compare(const void *a, const void *b)
{
    Menu *ia, *ib;
    ia = *(Menu **)a;
    ib = *(Menu **)b;
    
    if(ia->price > ib->price){
    	return -1;
    }else if(ia->price < ib->price){
 		return 1;
    }else{
   		return 0;
   	}
}

int my_strcmp(char *s1, char *s2)
{
    int i, a = 0, b = 0;    
    for(i = 0; i < strlen(s1); ++i){
    	++a;
    	if(s1[i] == ' '){
    		--a;
    		break;
    	}
    }
    for(i = 0; i < strlen(s2); ++i){
    	++b;
    	if(s2[i] == ' '){
    		--b;
    		break;
    	}
    }

    if(a < b){
    	return strncmp(s1, s2, a);
    }else{
    	return strncmp(s1, s2, b);
    }
}
int compare_name(const void *a, const void *b)
{
    
    Menu *ia, *ib;
    ia = *(Menu **)a;
    ib = *(Menu **)b;

    if (my_strcmp(ia->name, ib->name) == 0){
//		same brand
//  notice !! cannot return the difference of float value directly     
    	if(fabs(ia->review - ib->review) < 0.01){
//    		equal
	    	if(ia->price < ib->price){
	    		return -1;
	    	}else if(ia->price > ib->price){
	    		return 1;
	    	}else{
	    		return 0;
	    	}
	    }else{
	    	if(ia->review > ib->review){
	    		return -1;
	    	}else if(ia->review < ib->review){
	    		return 1;
	    	}else{
	    		return 0;
	    	}
	    }
    }else{
    	my_strcmp(ia->name, ib->name);
    }
}



void show_Menu(Menu *item)
{
    printf("%s, ", item->name);
    printf("$%.2f, ", item->price);
    printf("%.1f\n", item->review);
}


int main (int argc, char* argv[]){
	#ifdef DEBUG
	freopen ("test.in", "r", stdin);
	#endif

	Menu **items;
	int i, j;
    int ndata, nqueries;
    float lower, upper;
    int num;

	scanf("%d", &ndata);
    while (getchar() !='\n');

    items = (Menu**) malloc(sizeof(Menu*) * ndata);

    for (i=0; i<ndata; i++) {
        items[i] = (Menu*) malloc(sizeof(Menu));
        fgets(items[i]->name, 31, stdin);
        items[i]->name[strlen(items[i]->name)-1] = 0;
        scanf("%f", &items[i]->price);
        scanf("%f", &items[i]->review);
        scanf("%d", &items[i]->num_reviews);
        while (getchar() !='\n');
    }

    scanf("%d", &nqueries);
    while (getchar() !='\n');

//	sort by price
    qsort(items, ndata, sizeof(Menu *), compare);

    for (i=0; i<nqueries; i++) {
    	scanf("%f%f", &lower, &upper);
        printf("%.2f<=price<=%.2f\n", lower, upper);

        int begin = -1, len = 0;
        for(j = 0; j < ndata; ++j){
        	if((lower < items[j]->price && items[j]->price < upper)/*if not equal to the border*/
        		|| ((items[j]->price - lower)<0.01 && (upper - items[j]->price)<0.01)/*if equal*/ ){
        		if(begin == -1) begin = j;
        		++len;
        	}
        }

        qsort(items+begin, len, sizeof(Menu *), compare_name);

        for(j = begin; j < begin+len; ++j){
        	show_Menu(items[j]);
        }
    }
   	for (i=0; i<ndata; i++) {
        free(items[i]);
    }
  	free(items);
  	
	return 0;
}
