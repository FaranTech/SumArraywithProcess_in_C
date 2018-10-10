#include<stdio.h>
#include<stdlib.h>
int sum2=0;int start=0;int end=99;
void add(int *array)
{
	int sum1=0;
	for (int i = start; i <=end; i++) 
	{	array[i]=1;
		sum1=sum1+array[i];
	}
sum2=sum2+sum1;
start=end+1;
end=end+100;
printf("%d",sum2);
printf("\n");

	
}
int main()
{

int array[1000];
	int cpid=fork();
	  if (cpid< 0) 
	{
	    printf("failed");
	    abort();
  	}
	else if (cpid== 0) 
	{
	    	add(array);
		cpid=fork();
		if (cpid< 0) 
		{
		    printf("failed");
		    abort();
  		}
		else if (cpid== 0) 
		{
		    	add(array);
			cpid=fork();
			  if (cpid< 0) 
			{
			    printf("failed");
				abort();
  			}
			else if (cpid== 0) 
			{
			    	add(array);
				cpid=fork();
				  if (cpid< 0) 
				{
				    printf("failed");
					cpid=fork();
				    abort();
			  	}
					else if (cpid== 0) 
					{
					    	add(array);
						cpid=fork();
						  if (cpid< 0) 
						{
						    printf("failed");
						    abort();
					  	}
						else if (cpid== 0) 
						{
						    	add(array);
							cpid=fork();
							  if (cpid< 0) 
							{
							    printf("failed");
							    abort();
						  	}
							else if (cpid== 0) 
							{
							    	add(array);
								cpid=fork();
								  if (cpid< 0) 
								{
								    printf("failed");
								    abort();
							  	}
								else if (cpid== 0) 
								{
								    	add(array);
									cpid=fork();
									  if (cpid< 0) 
									{
									    printf("failed");
									    abort();
								  	}
										else if (cpid== 0) 
										{
										    	add(array);
											cpid=fork();
										  if (cpid< 0) 
										{
										    printf("failed");
											  abort();
									  	}
											else if (cpid== 0) 
											{
											    	add(array);
												cpid=fork();
												  if (cpid< 0) 
												{
												    printf("failed");
												    abort();
											  	}
												else if (cpid== 0) 
												{
												    	add(array);
													cpid=fork();

												}

											}

										}

									}

								}

							}

						}

					}

				}

			}
return 0;
}

