/*

WAP TO CALCULATE THE FACTORIAL OF A NUMBER.

*/

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

        int sum,upper;
        void *runner(void *param);
        int main(int argc,char *argv[])
        {
                pthread_t tid;
                pthread_attr_t attr;
                if(argc!=2)
                {
                        fprintf(stderr," Error");
                        return 1;
                }

                if(atoi(argv[1])<0)
                {
                        fprintf(stderr,"Negative input not allowed");
                        return 1;
                }
                pthread_attr_init(&attr);
                pthread_create(&tid,&attr,runner,argv[1]);
                pthread_join(tid,NULL);
        if(upper==0)
			printf("Factorial is \n",1);
		else
			printf("Factorial is %d\n",sum);
		return 0;
	}

void *runner(void *param)
{
	int i;
	upper=atoi(param);
	sum=1;
	for(i=1;i<=upper;i++)
		sum=sum*i;
	pthread_exit(0);
	return 0;
}


/*

OUTPUT



$ cc q3_b.c

$ ./a.out 3



Factorial is 6

*/
