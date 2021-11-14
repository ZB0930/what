#include<stdio.h>
int main()
{
	int n,i,j,a;
    char x;
	while(scanf("%d %c",&n,&x)!=EOF)
	{
		if(a%2==0)
      {  a=n/2;
		for(j=1;j<=a;j++)
        {

			for(i=1;i<=n;i++)
			{
				printf("%c",x);
			}
			printf("\n");
        }

        }
        if(a%2==1)
        {a=n/2+1;
            for(j=1;j<=a;j++)

			{for(i=1;i<=n;i++)
			{
				printf("%c",x);
            }
            printf("\n");
			}

	  }


}
}
