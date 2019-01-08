//Assuming computer is X, human is O
// X = 1,O = 0, Empty = -1
#include<stdio.h>
int a[3][3];
int b[3][3];
void display()
{
	printf("\n");
	for(int i =0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j] == 1)
				printf("X\t");
			else if(a[i][j] == -1)
				printf("-\t");
			else
				printf("O\t");
		}
		printf("\n\n");
	}
	
}

int evaluate(int b[][3])
{
	for(int i = 0;i<3;i++)
	{
		if(b[i][0]==b[i][1] && b[i][1]==b[i][2])
		{
			if(b[i][0] == 1)
				return 10;
			else if(b[i][0] == 0)
				return -10;
		}
		else if(b[0][i]==b[1][i] && b[1][i]==b[2][i])
		{
			if(b[0][i] == 1)
				return 10;
			else if(b[0][i] == 0)
				return -10;
		}
		else if(b[0][0] == b[1][1] && b[0][0] == b[2][2])
		{
			if(b[0][0] == 1)
				return 10;
			else if(b[0][0] == 0)
				return -10;
		}
		else if(b[0][2] == b[1][1] && b[1][1] == b[2][0])
		{
			if(b[0][2] == 1)
				return 10;
			else if(b[0][2] == 0)
				return -10;
		}
	}
	return 0 ;
}
int isMovesLeft()	//TO CHECK WHETHER MOVES ARE THERE OR THE BOARD IS EMPTY
{
  	  int c = evaluate(a);
  	  if(c==10)
  	 	return 2;
  	  else if(c==-10)
  	 	return 3;
  	 	
  	  else	
    		for (int i = 0; i<3; i++)
        		for (int j = 0; j<3; j++)
        		    if (a[i][j] == -1)
        		        return 1;
    	  return 0;
}		

void play()
{	
		
	for(int i = 0; i<3 ;i++)
	{
		for(int j = 0;j<3; j++)
		{
			b[i][j] = a[i][j];
		}
	}
	
	if(a[1][1]==-1)
		a[1][1] = 1;
	else
	{
		for(int i = 0 ;i<3;i++)	
		{
			for(int j = 0 ;j<3;j++)
			{
				if(b[i][j]==-1)
				{
					b[i][j] = 0;
					int c = evaluate(b);
					b[i][j] = 1;
					int d = evaluate(b);
					b[i][j] = -1;
					if(d==10)
						b[i][j] = d;
					else if(c==-10)
						b[i][j] = c;
				}
			}
		}
		int flag = 0;
		int w = 0;
		int i;
		for(i = 0 ;i<3;i++)	
		{
			for(int j = 0 ;j<3;j++)
			{
				if(b[i][j] == 10)
				{
					a[i][j] = 1;
					flag++;
					break;
				}
					
			}
			if(flag)
			{
				flag = 0;
				break;
			}
		}
		int q = 0;
		
		if(i == 3)
		{
			for(i = 0 ;i<3;i++)	
			{
				for(int j = 0 ;j<3;j++)
				{
					if(b[i][j] == -10)
					{	
						a[i][j] = 1;
						flag++;
						w++;
					}
						
				}
				if(flag)
				{
					flag = 0;
					break;
				}
			}
		}
		
		if(i == 3 && w == 0)
		{
			for( i = 0 ;i<3;i++)	
			{
				for(int j = 0 ;j<3;j++)
				{
					if(a[i][j]==-1)
					{
						q++;
						a[i][j] = 1;
						break;
					}
				}
				if(q == 1)
				{
					q = 0;
					break;
				}
			}
		}
				
			
	}
	
}
void main()
{
	
	for(int i = 0 ;i<3;i++)
	{
		for(int j = 0;j<3 ;j++)
		{	
			a[i][j] = -1;
		}
	}
	display();
	printf("\n");
	int m,n;
	int correct = 0;
	while(isMovesLeft() == 1)
	{
		
		do
		{
			printf("\nPlease enter row number\n");
			scanf("%d",&m);
			printf("\nPlease enter column number\n");
			scanf("%d",&n);
			if(a[m][n] == -1)
			{
				correct = 1;
				a[m][n] = 0;
				
				
			}
		}while(!correct);
		if(isMovesLeft() == 1)
			play();
		else
		{
			printf("\n");
			display();
			printf("\n");
			break;
		}
		printf("\n");
		display();
		printf("\n");
		correct = 0;
	}
	if(isMovesLeft() == 2)
		printf("\nComputer won\n");
	else if(isMovesLeft() == 3)
		printf("\nHuman won\n");
	else if(isMovesLeft()==0)	
		printf("\nDraw\n");
}
