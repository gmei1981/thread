#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//for thread test 

#define BUFF_SIZE 8

//int wptr = 0 ;
//int rptr = 0 ;
int usedw = 0;

/*
void cycle_cnt(int* cnt,int value) {
		*cnt = *cnt+1 ;
		if( *cnt >= value )
				*cnt=0;
}
*/

void* producer() {
		while(1) {
				if( usedw <= BUFF_SIZE-1 ) {
						sleep(2) ;
						usedw = usedw + 1 ; 
						printf("producer with %d usedw\n",usedw) ;
				}
				else
						sleep(1) ;
		}
		return NULL ;
}

void* consumer() {
		while(1) {
				if( usedw >= 2+1 ) { //at least two 
						sleep(5) ;
						usedw = usedw - 2 ; 
						printf("\tconsumer with %d usedw\n",usedw) ;
				} else
						sleep(1) ;
		}
		return NULL ;
}

int main() {
		pthread_t pro,con ;
		int ret1,ret2 ;
		printf("creating 2 threads\n") ;
		ret1 = pthread_create(&pro,NULL,producer,NULL) ;
		ret2 = pthread_create(&con,NULL,consumer,NULL) ;

		if( (ret1!=0) || (ret2!=0) ) {
				printf("thread creation failure\n") ;
				exit(EXIT_FAILURE) ;
		} else {
				printf("thread creation success\n") ;
		}

		pthread_join(pro, NULL);
		pthread_join(con, NULL);
		
		printf("main thread exit\n") ;
		exit(EXIT_SUCCESS) ;
}
