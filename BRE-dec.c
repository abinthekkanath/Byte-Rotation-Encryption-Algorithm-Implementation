#include<stdio.h>
#include<stdio.h>

int chr2num(char c)
{
	int re1,re2=26;
	
	if(c>='a' && c<='z')
	return (c-'a'+1);
	if(c>='1' && c<='9')
	return ((c-'1'+27));
	if(c=='0') return 0;
	}
	
char num2char(int c)
{
	int re1,re2=26;
	
	if(c>=1 && c<=26)
	return (c+'a'-1);
	if(c>=27 && c<=35)
	return ((c+'0'-27));
	if(c==0) return '0';
	}
void main()
{
	
	int i,j,l,t1,t2,t3;
	char m[4][4];

	int ke[4][4],mpt[4][4],mp[4][4],c[4][4];
	int cpk[4][4],chr[4][4],cvr[4][4],cp[4][4];
    printf("\n Enter cipher text\n");
   for(i=0;i<4;i++)
	{for(j=0;j<4;j++)
	scanf("%c",&m[i][j]);
}
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %c",m[i][j]);
	printf("\n");
    }
    
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	c[i][j]=chr2num(m[i][j]);
    	printf("\n C =\n");
	
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",c[i][j]);
	printf("\n");
    }
    
    printf("\n----------Vertical Rotation---------\n");
	
	i=0;j=0;l=3;
	t1=c[0][0];
	t2=c[1][0];
	t3=c[2][0];
	while(i<=0)
	{
		chr[i][j]=c[i+3][j];
		i++;
		l--;
	}
	chr[i][j]=t1;i++;chr[i][j]=t2;i++;chr[i][j]=t3;
	
	i=0;j=1;l=2;
	t1=c[0][1];
	t2=c[1][1];
	while(i<=1)
	{
		chr[i][j]=c[i+2][j];
		i++;
		l--;
	}
	chr[i][j]=t1;i++;chr[i][j]=t2;
	
		i=0;j=2;l=1;
	t1=c[0][2];
	
	while(i<=2)
	{
		chr[i][j]=c[i+1][j];
		i++;
		l--;
	}
	chr[i][j]=t1;
	
	i=0;j=3;
	while(i<4)
	{
		chr[i][j]=c[i][j];
		i++;
	}
	
	printf("\n Chr =\n");
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",chr[i][j]);
	printf("\n");
    }
    
       printf("\n----------Horizontal Rotation---------\n");
	
	i=0;j=0;l=3;
	t1=chr[0][0];
	t2=chr[0][1];
	t3=chr[0][2];
	while(j<=0)
	{
		cvr[i][j]=chr[i][j+3];
		j++;
		l--;
	}
	cvr[i][j]=t1;j++;cvr[i][j]=t2;j++;cvr[i][j]=t3;
	
	i=1;j=0;l=2;
	t1=chr[1][0];
	t2=chr[1][1];
	while(j<=1)
	{
		cvr[i][j]=chr[i][j+2];
		j++;
		l--;
	}
	cvr[i][j]=t1;j++;cvr[i][j]=t2;
	
		i=2;j=0;l=1;
	t1=chr[2][0];
	
	while(j<=2)
	{
		cvr[i][j]=chr[i][j+1];
		j++;
		l--;
	}
	cvr[i][j]=t1;
	
	i=3;j=0;
	while(j<4)
	{
		cvr[i][j]=chr[i][j];
		j++;
	}
	
	printf("\n Cvr =\n");
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",cvr[i][j]);
	printf("\n");
    }
   
   	int k[4][4]= { 25,15,3,9,20,7,13,8,5,18,22,17,21,12,26,24 };

	
printf("\n K =\n");
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",k[i][j]);
	printf("\n");
}
    for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	ke[i][j]=k[i][j]%2;
	
	printf("\n Ke =\n");
	
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",ke[i][j]);
	printf("\n");
    }
    
    	
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	mpt[i][j]=cvr[i][j]-ke[i][j];
	
	printf("\n mpt =\n");
	
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",mpt[i][j]);
	printf("\n");
    } 
    
    
    for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	mp[i][j]=mpt[j][i];
	
	printf("\n Mp =\n");
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",mp[i][j]);
	printf("\n");
    }
      printf("PlainText:");
    for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf("%c",num2char(mp[i][j]));
	
    }
}
