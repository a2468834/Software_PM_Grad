#include<stdio.h>
#include<stdlib.h>

int num1,num2,num3,max,low1,low2;

int main()
{
	while(1)
	{
		printf("Please key 3 integers\n");
		scanf("%d%d%d",&num1,&num2,&num3);
		max=num1;
		if(num2>max)
		{
			max=num2;
			if(num3>max)
			{
				max=num3;
				low1=num1;
				low2=num2;
			}
			else low1=num1,low2=num3;
			
		}
		else if(num3>max)
		{
			max=num3;
			low1=num1;
			low2=num2;
		}
		else low1=num2,low2=num3;
		
		if( (max>0) && (low1>0) && (low2>0) && (max<low1+low2) )
		{
			if( (max==low1) || (max==low2) || (low1==low2) )
			{
			    if( (max==low1) && (max==low2) )
			    {
			        printf("%d %d %d can construct a triangle",num1,num2,num3);
			        printf("\n%d %d %d are the side length of regular triangle\n", num1,num2,num3); 
		        }
		        else if(max*max==(low1*low1+low2*low2))
		        {
		        	printf("%d %d %d can construct a triangle",num1,num2,num3);
		        	printf("\n%d %d %d are the side length of isosceles right triangle\n",num1,num2,num3);
		        }
		        else 
		        {
				    printf("%d %d %d can construct a triangle",num1,num2,num3);
				    printf("\n%d %d %d are the side length of isosceles triangle\n",num1,num2,num3);
			    }
		    }
		
			else if(max*max==(low1*low1+low2*low2))
			{
				printf("%d %d %d can construct a triangle",num1,num2,num3);
				printf("\n%d %d %d are the side length of right triangle\n",num1,num2,num3);
			}
			else if(max<(low1+low2))
			{
				printf("%d %d %d can construct a triangle",num1,num2,num3);
				printf("\n%d %d %d are the side length of normal triangle\n",num1,num2,num3);
			}
			else printf("%d %d %d can not construct a triangle\n",num1,num2,num3);
	    }
	    else printf("%d %d %d can not construct a triangle\n",num1,num2,num3);
	}

}
