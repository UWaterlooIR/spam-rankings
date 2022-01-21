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
    while (EOF != (score = getchar())) 
    {
        if (score == '\n') 
            scanf("clueweb12-%[0-9]%[a-z]-%d-%d%*[\n]",a,b,&file,&record);
        else 
            printf("%d clueweb12-%s%s-%02d-%05d\n",score-28,a,b,file,record++); 
    }
}
