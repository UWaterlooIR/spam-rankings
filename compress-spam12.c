#include <stdio.h>
#include <string.h>
#include <assert.h>

char a[1000],b[1000];
int score;
int file,record;
int prevFile=0,prevRecord=0;

/* 82 clueweb12-0716wb-21-00000 */

main()
{
    while (5 == scanf("%d clueweb12-%[0-9]%[a-z]-%d-%d",&score,a,b,&file,&record)) 
    {
        if (file != prevFile || record != prevRecord+1) 
            printf("\nclueweb12-%s%s-%02d-%05d\n",a,b,file,record); 
        putchar(score+28);
        prevFile = file;
        prevRecord = record ;
    }
}
