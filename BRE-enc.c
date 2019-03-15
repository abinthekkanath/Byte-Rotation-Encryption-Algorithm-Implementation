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

	int ke[4][4],mpt[4][4],mp[4][4];
	int cpk[4][4],chr[4][4],cvr[4][4];
	printf("\n Enter plain text\n");
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
	mp[i][j]=chr2num(m[i][j]);
	
	
	/*= { 18,1,25,13,15,14,4,19,21,9,20,9,14,7,19,0 };*/
	printf("\n Mp =\n");
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",mp[i][j]);
	printf("\n ");
    }

	int k[4][4]= { 25,15,3,9,20,7,13,8,5,18,22,17,21,12,26,24 };

	
printf("\n K =\n");
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",k[i][j]);
	printf("\n");
	
	
    }
    printf("\n**********ENCRYPTION**********\n");
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
	mpt[i][j]=mp[j][i];
	
	printf("\n Mpt =\n");
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",mpt[i][j]);
	printf("\n");
    }

	
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	cpk[i][j]=mpt[i][j]+ke[i][j];
	
	printf("\n Cpk =\n");
	
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",cpk[i][j]);
	printf("\n");
    }
	printf("\n----------Horizontal Rotation---------\n");
	i=0;j=0;l=0;
	t1=cpk[0][0];
	while(j<=2)
	{
		chr[i][l]=cpk[i][j+1];
		j++;
		l++;
	}
	chr[i][l]=t1;
	
	i=1;j=0;l=0;
	t1=cpk[1][0];
	t2=cpk[1][1];
	while(j<=1)
	{
		chr[i][l]=cpk[i][j+2];
		j++;
		l++;
	}
	chr[i][l]=t1;l=l+1;chr[i][l]=t2;
	
	
	i=2;j=0;l=0;
	t1=cpk[2][0];
	t2=cpk[2][1];
	t3=cpk[2][2];
	while(j<=0)
	{
		chr[i][l]=cpk[i][j+3];
		j++;
		l++;
	}
	chr[i][l]=t1;l=l+1;chr[i][l]=t2;l=l+1;chr[i][l]=t3;
	
	i=3;j=0;
	while(j<4)
	{
		chr[i][j]=cpk[i][j];
		j++;
	}
	printf("\n Chr =\n");
	
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",chr[i][j]);
	printf("\n");
    }
    
    	printf("\n----------Vertical Rotation---------\n");
	i=0;j=0;l=0;
	t1=chr[0][0];
	while(i<=2)
	{
		cvr[l][j]=chr[i+1][j];
		i++;
		l++;
	}
	cvr[l][j]=t1;
	
	i=0;j=1;l=0;
	t1=chr[0][1];
	t2=chr[1][1];
	while(i<=1)
	{
		cvr[l][j]=chr[i+2][j];
		i++;
		l++;
	}
	cvr[l][j]=t1;l=l+1;cvr[l][j]=t2;
	
	
	i=0;j=2;l=0;
	t1=chr[0][2];
	t2=chr[1][2];
	t3=chr[2][2];
	while(i<=0)
	{
		cvr[l][j]=chr[i+3][j];
		i++;
		l++;
	}
	cvr[l][j]=t1;l=l+1;cvr[l][j]=t2;l=l+1;cvr[l][j]=t3;
	
	i=0;j=3;
	while(i<4)
	{
		cvr[i][j]=chr[i][j];
		i++;
	}
	printf("\n Cvr =\n");
	
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf(" %d",cvr[i][j]);
	printf("\n");
    }
    printf("\n");
    printf("CipherText:");
    for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
	printf("%c",num2char(cvr[i][j]));
	
    }
	}

