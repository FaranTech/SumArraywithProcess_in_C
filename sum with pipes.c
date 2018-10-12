#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
//global variables

int start=0;int end=99;

//function to add 100 elements of array per process with pipe

void add(int *array,int *fd1)
{
	int sum1=0;
	for (int i = start; i <=end; i++) 
	{	array[i]=1;
		sum1=sum1+array[i];
	}
      write(fd1[1], &sum1, sizeof(sum1));
      close(fd1[1]);
      exit(0);

	start=end+1;
	end=end+100;
}

//main

int main()
{
	int ar[10];	//array whose indexes have pipe's values from add function
	int array[1000];	//array of size=1000

	int fd1[2];	//pipe 1
	int cpid;	//child process id

if (pipe(fd1)==-1)
    {
        printf("Pipe Failed" );
        return 1;
    }

	cpid=fork();
	  if (cpid< 0) 
	{
	    printf("failed");
	            return 1;
  	}
	else if (cpid== 0) 
	{
	    	add(array,fd1);
	}
	else
	{
	      wait(NULL);
	      read(fd1[0], &ar[0], sizeof(int));
	      printf("From Child Process: %d\n", 1);
	      close(fd1[0]);
	}

		int fd2[2];	//pipe 2
		if (pipe(fd2)==-1)
		    {
		        printf("Pipe Failed" );
		        return 1;
		    }


		cpid=fork();
		if (cpid< 0) 
		{
		    printf("failed");
		    abort();
  		}
		else if (cpid== 0) 
		{
			add(array,fd2);

		}
		else
		{
		      	wait(NULL);
		      read(fd2[0], &ar[1], sizeof(int));
		      printf("From Child Process: %d\n", 2);
		      close(fd2[0]);
		}
			int fd3[2];	//pipe 3
			if (pipe(fd3)==-1)
    			{
        			printf("Pipe Failed" );
        			return 1;
    			}

			cpid=fork();	
			if (cpid< 0) 
			{
			    printf("failed");
				abort();
  			}
			else if (cpid== 0) 
			{
			    	add(array,fd3);
			}
			else
			{
			      	wait(NULL);
			      read(fd3[0], &ar[2], sizeof(int));
			      printf("From Child Process: %d\n", 3);
			      close(fd3[0]);
			}

				int fd4[2];	//pipe 4
				if (pipe(fd4)==-1)
				    {
				        printf("Pipe Failed" );
					        return 1;
				    }

				cpid=fork();		
				  if (cpid< 0) 
				{
				    printf("failed");
					 abort();
			  	}
				else if (cpid== 0) 
				{
				    	add(array,fd4);
				}
				else
					
				{
				      	wait(NULL);
				      read(fd4[0], &ar[3], sizeof(int));
				      printf("From Child Process: %d\n", 4);
				      close(fd4[0]);
				}

					int fd5[2];	//pipe 5
					if (pipe(fd5)==-1)
    					{
					        printf("Pipe Failed" );
					        return 1;
					}

					cpid=fork();
					  if (cpid< 0) 
					{
					    printf("failed");
					    abort();
				  	}
					else if (cpid== 0) 
					{
					    	add(array,fd5);
					}
					else		
					{
					      	wait(NULL);
					      read(fd5[0],&ar[4], sizeof(int));
					      printf("From Child Process: %d\n", 5);
					      close(fd5[0]);
					}

						int fd6[2];	//pipe 6
						if (pipe(fd6)==-1)
						{
						 	printf("Pipe Failed" );
							return 1;
						}

						cpid=fork();	
						  if (cpid< 0) 
						{
						    printf("failed");
						    abort();
					  	}
						else if (cpid== 0) 
						{
						    	add(array,fd6);
						}
						else		
						{
						      	wait(NULL);
						      read(fd6[0],&ar[5], sizeof(int));
						      printf("From Child Process: %d\n", 6);
						      close(fd6[0]);
						}


							int fd7[2];	//pipe 7
							if (pipe(fd7)==-1)
							{
							        printf("Pipe Failed" );
							        return 1;
							}

							cpid=fork();
							  if (cpid< 0) 
							{
							    printf("failed");
							    abort();
						  	}
							else if (cpid== 0) 
							{
							    	add(array,fd7);
							}
							else		
							{
					      			wait(NULL);
							      read(fd7[0],&ar[6], sizeof(int));
							      printf("From Child Process: %d\n",7);
							      close(fd7[0]);
							}

								int fd8[2];	//pipe 8
								if (pipe(fd8)==-1)
								{
								    printf("Pipe Failed" );
									return 1;
								}

								cpid=fork();
								  if (cpid< 0) 
								{
								    printf("failed");
								    abort();
							  	}
								else if (cpid== 0) 
								{
								    	add(array,fd8);
								}
								else		
								{
								      	wait(NULL);
								      read(fd8[0],&ar[7], sizeof(int));
								      printf("From Child Process: %d\n",8);
								      close(fd8[0]);
								}

									int fd9[2];	//pipe 9
									if (pipe(fd9)==-1)
									{
										printf("Pipe Failed" );
										return 1;
									}

									cpid=fork();
									  if (cpid< 0) 
									{
									    printf("failed");
										  abort();
								  	}
									else if (cpid== 0) 
									{
									    	add(array,fd9);
									}
									else		
									{	
									      	wait(NULL);
									      read(fd9[0],&ar[8], sizeof(int));
									      printf("From Child Process: %d\n",9);
									      close(fd9[0]);
									}

										int fd10[2];	//pipe 10
										if (pipe(fd10)==-1)
										{
											printf("Pipe Failed" );
											return 1;
										}

										cpid=fork();
										  if (cpid< 0) 
										{
										    printf("failed");
										    abort();
									  	}
										else if (cpid== 0) 
										{
											add(array,fd10);
										}
										else		
										{
										      	wait(NULL);
										      read(fd10[0],&ar[9], sizeof(int));
										      printf("From Child Process: %d\n",10);
										      close(fd10[0]);
										}
/*Final Sum Will Print here*/
	int final_Sum=0;
	for(int i;i<10;i++)
	{
		final_Sum+=ar[i];
	}
	printf("SUM = %d\n",final_Sum);

return 0;
}

