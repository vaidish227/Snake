#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int width=50,height=50,gameOver;
int x,y,fruitx,fruity,score,flag;
int tailX[100],tailY[100];
int CountTail=0;
//funbction for gameover,  position of snake ,  for genrating fruit
// initial function
void setup()
{

  gameOver=0;
//var for snake
  x=width/2;
  y=height/2;
 
 
 // var for fruit  
   label1:
  fruitx=rand()%35;
  if(fruitx==0)
   {
  	goto label1;
   }
   
   label2:
  fruity=rand()%25;
  if(fruity==0)
   {
  	goto label2;
   } 
    score=0;
}


// function for draw board
void draw()
 {
 	 int i,j,k;
 	 system("cls");
 	 printf("\n\t\t\t\tScore = %d\n",score);   
 	 printf("\n\n\n");
    
 	 for(i=0;i<width;i++)
 	{
 		//system("color 1");
	 printf("\t\t");
	   for(j=0;j<width;j++)
	   {
	   	   if(i==0||i==height-1||j==0||j==width-1)
	   	    {
	   	    	
			  printf("#");
		    }
		   else
		   { 
		       // for printing snake (in blank space)
		    	if(i==x && j==y)
		        {
                  system("color 4F");
                  printf("O");
                }
                //for printing (generating) fruit
				else if(i==fruitx && j==fruity)
				{   
					printf("*");
				}
				else		    	
			        {
			        	int ch=0;
			        	for(k=0;k<CountTail;k++) //pair of i nd j
			        	{
			        		if(i==tailX[k] && j==tailY[k])
			        		{
			        		
			        			printf("8");
			        			ch=1;
							}
						}
						if(ch==0)
			       	    printf(" ");
				    }
	       	}
       }
       printf("\n");
    } 
 }
 
 
    
 // input function for moving snake
void input()
{
	if(kbhit())// kbhit is function keyboard hit function
	{
		switch(getch())
		{
			case 'a': //aswz
			  flag=1; //flag variable check the pressed key(aswz) 
			  break;
			case 's':
			  flag=2;
			  break;
			case 'w':
				flag=3;
				break;
			case 'z':
				flag=4;
				break;
			case 'x':
			  gameOver=1;
			  break;	
		}
	}
 } 

// logic for moving snake in (??) directioon
void logic()
{
	
  /// increase the size of snake
	int i;
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	
	for(i=1;i<CountTail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	
//----------------------------------------------//

	switch(flag)//flag var check the pressed key 
	{
	
		case 1: /*direction of snake in all cases A*/
		    y--; // y decrement means user wants to move in left direction
		    break;
		case 2:  //S
			y++; // x increment means user wants to move in right direction
			break;
		case 3:  //W
			x--; // x decrement5 means user wants to move in upward direction
			break;
		case 4:  //Z
		    x++; // y increment means user wants to move in downward direction
			break;	
		default:
		break;	
	}
	// for game over
	if(x<0||x>width||y<0||y>height)
	 gameOver=1;
	 
	 //
	 
	 for(i=0;i<CountTail;i++)
	 {
	 	if(x==tailX[i] && y==tailY[i])
	 	gameOver=1;
	 }
	 // for change position of fruit nd genrate new fruit
	if(x==fruitx && y==fruity)
	{
		  label3:
          fruitx=rand()%15;
          if(fruitx==0)
          {
         	goto label3;
         	
          }
   
          label4:
          fruity=rand()%50;
          if(fruity==0)
          {
        	goto label4;
        	score+=10;
        	//CountTail++;
          }
		  score+=10;
		   CountTail++;
   }  
}

// main function
int main()
{

	int m,n;
	char c;
		label5:
	setup();
	
	while(!gameOver) /* we have set initial value of gameover=1 when condition is true game is play continue 
	                     "(!gameOver) GAME OVER" when gameover is not = to 1 game over */
	{
		draw();
	    input();
	    logic();
	     ///for speed of snake
	    for(m=0;m<1000;m++)
	    {
		  for(n=0;n<10000;n++){
		  }
		}
		for(m=0;m<1000;m++)
		{
			for(n=0;n<10000;n++)
			{
				
			}
		}
		for(m=0;m<1000;m++)
		{
			for(n=0;n<10000;n++)
			{
				
			}
		}
		//sleep(1);
	}
	printf("\n\n\t\tPress Y to continue again :");
	scanf("%c",&c);
	if(c=='y' || c=='Y')
	goto label5;
	return 0;
}
