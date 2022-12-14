/*

WAP TO PRINT FIBONACCI SERIES USING PTHREAD LIBRARY.

*/

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

        int sum;
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
			return 0;
	}

	int fibb(int upper)
	{
		if(upper==1)
			return 0;
		else if(upper==2)
			return 1;
		else
			return (fibb(upper-1)+fibb(upper-2));
	}



	void *runner(void *param)
	{	
		int i;
		int upper=atoi(param);
		for(i=1;i<=upper;i++)
		{
			int result=fibb(i);	
			printf("%d ",result);
		}
	}

/*

OUTPUT



$ cc q3_c.c

$ ./a.out 5



result 0 1 1 2 3 



*/
