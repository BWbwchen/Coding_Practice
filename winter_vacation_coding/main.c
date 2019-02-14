#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    
    return strcmp(ib->name, ia->name);
}

int compare_sec(const void *a, const void *b)
{
    
    Menu *ia, *ib;
    ia = *(Menu **)a;
    ib = *(Menu **)b;
//  notice ! can not return the difference of float value directly     
    if(fabs(ia->review - ib->review) < 0.01){
//    	    equal
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
    char query[51];

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

//	sort by name
    qsort(items, ndata, sizeof(Menu *), compare);

    for (i=0; i<nqueries; i++) {
    	char temp[51];
		scanf("%31s", temp);
		while (getchar() !='\n');

		int begin = -1, len = 0;

		for(j = 0; j < ndata; ++j){
			if(strncmp(temp, items[j]->name, strlen(temp))==0 && begin==-1){
				begin = j;
				++len;
			}else if(strncmp(temp, items[j]->name, strlen(temp))==0){
				++len;
			}
		}
	
		qsort(items+begin, len, sizeof(Menu *), compare_sec);
		
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
