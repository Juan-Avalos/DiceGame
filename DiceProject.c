//Name: Jaun Avalos
//Group: 3
//Section Lab 503/Lecture 003
//Problem: Project
//Date 5/3/2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Players{
	char name[100];
	int balance; 
	int gain; 
};

struct Players Gamers[10];

int playerCount = 0; 


void initialize()
{
	int i; 
	FILE *fp = fopen("players.txt", "r");
	
	if(fp==NULL){
	    printf("FILE DOES NOT EXIST!");
	    exit(EXIT_FAILURE);
	}

	for(i=0;!feof(fp);i++)
  	{
    fscanf(fp,"%s %d %d", Gamers[i].name, &Gamers[i].balance, &Gamers[i].gain);
    playerCount++;
  	}
}


void changeFile()
{
	
	FILE *obj = fopen("players.txt", "w");
	int i; 
	
	for (i = 0; i<playerCount; i++){
		fprintf(obj, "%s %d %d\n", Gamers[i].name, Gamers[i].balance, Gamers[i].gain); 
	}	
	fclose(obj);
	return; 
	
}

int topup()
{
  char player[100];
  //char catagories[20][100];
  int i, addM, a=0;
  
  printf("Please Enter the player name: ");
  scanf("%s",&player);
  printf("Enter balance you want to add: ");
  scanf("%d",&addM);
  
  
  for(i=0;i<playerCount;i++)//check if player in file
  {
    if(strcmp(Gamers[i].name,player)==0)
    {
      Gamers[i].balance = Gamers[i].balance+addM;
      a=1;
    }
  }

  if(a==0)
  {
    printf("Player not avalible.\n");
  }
  //changeFile();
  return 0;
}


void playgame()
{ // Play game
  int not = 0;
  char player[100];
  int i,dice1,dice2,dicetotal,a=0;
  printf("Please enter your name: \n");
  scanf("%s", &player);//get player
  
  while(1)
  {
    getchar();
    while(1)
    {
      printf("Press Enter to Roll the dice.\n");
      getchar();
      dice1 = rand() % 6 + 1;
      dice2 = rand() % 6 + 1;
      dicetotal = dice1+dice2;
      printf("The values of the dices are %d and %d whose sum is %d.\n", dice1, dice2, dicetotal); 
      for(i=0;i<playerCount;i++)//check if player in file
      {
        if(strcmp(Gamers[i].name,player)==0)
        {
          not = 1;
		     
          if(dicetotal == 7 || dicetotal == 11)
          {
            Gamers[i].balance = Gamers[i].balance + 10; // add 10 to balance
            Gamers[i].gain = Gamers[i].gain + 10; // add 10 to gain
            printf("You win the game. Your current balance is %d.\n", Gamers[i].balance); 
            char again; // play again
            printf("Play another game? y/n ");
            scanf("%s", &again);
            if(again == 'y')
            {
              //getchar();
              a=1;
              continue;
            }
            else
            {
              a=0;
              break;
              //return;
            }
          }
          
          else if(dicetotal == 2 || dicetotal == 3 || dicetotal == 12)
          {
            Gamers[i].balance = Gamers[i].balance-1;
            Gamers[i].gain = Gamers[i].gain-1;
            printf("You lost the game.\n Your current stake is %d.\n", Gamers[i].balance); 
            char again;
            printf("Play another game? y/n ");
            scanf("%s", &again);
            if(again == 'y')
            {                
              //getchar();
              a=1;
              continue;   
            }
            else
            {
              a=0;
              //getchar();
              break;
            }
          } 
           
          else
          {
            int point = dicetotal;
            while(1)
            {
              printf("Press Enter to Roll the dice.\n"); 
              getchar(); 
              dice1 = rand() % 6 + 1;
              dice2 = rand() % 6 + 1;
              dicetotal = dice1+dice2;
              printf("The values of the dices are %d and %d whose sum is %d.\n", dice1, dice2, dicetotal);
              if(dicetotal == point)
              {
                Gamers[i].balance = Gamers[i].balance+10;
                Gamers[i].gain = Gamers[i].gain+10;
                printf("You win the game. Your current balance is %d.\n", Gamers[i].balance); 
                char again;
                printf("Play another game? y/n ");
                scanf("%s", &again);
                if(again == 'y')
                {
                  //getchar();
                  a=1;
                  continue;
                }
                        
                else 
                {
                  a=0;
                  break;
                }
              }
               
              else if(dicetotal == 7)
              {
                Gamers[i].balance = Gamers[i].balance-1; // subtract 1 balance
                Gamers[i].gain = Gamers[i].gain-1; // subtract 1 gain
                printf("You lose the game.\n Your current stake is %d.\n", Gamers[i].balance); 
                char again; // play again
                printf("Play another game? y/n ");
                scanf("%s", &again);
                if(again == 'y')
                {
                  //getchar();
                  a=1;
                  continue;
                }
                        
                else 
                {
                  //gamemenu();
                  a=0;
	                break;
				          //return;
                }
              }
              else
              {
                continue;
              }
            }
            

          }
          break;
          

        }
        
      }
      break;
      
    }
    if(not == 0)
    {
      printf("Player not avalible.\n");
      break;
    }
    else if(a==1)
    {
      continue;
    }
    else
    {    
      //continue;
      //getchar();
      //gamemenu();
      break;
    }
  }
}


int topbalance()
{
  int i,n;
  for(i = 0; i< playerCount; i++)
  {
  	for (n = 0; n < playerCount-1; n++)
    {
  		if (Gamers[n].balance < Gamers[n+1].balance)
      {
  			int temp = Gamers[n].balance;
  			char tempName[10]; 
  			int tempGain = Gamers[n].gain; 
  			//tempName = Gamers[n].name; 
  			sscanf(Gamers[n].name, "%s", tempName);
  			Gamers[n].balance = Gamers[n+1].balance; 
  			Gamers[n].gain = Gamers[n+1].gain;
  			Gamers[n+1].balance = temp; 
  			Gamers[n+1].gain = tempGain;
  			sscanf(Gamers[n+1].name, "%s", Gamers[n].name);
  			sscanf(tempName ,"%s", Gamers[n+1].name);	
		  }
	  }
  }
  
  
  for (i = 0; i< 5; i++)
  	printf("%s %d\n", Gamers[i].name, Gamers[i].balance); 
  return 0;
}

int topgain()
{
  int i,n;
  for(i = 0; i< playerCount; i++)
  {
  	for (n = 0; n < playerCount-1; n++)
    {
  		if (Gamers[n].gain < Gamers[n+1].gain)
      {
  			int temp = Gamers[n].balance;
  			char tempName[10]; 
  			int tempGain = Gamers[n].gain; 
  			//tempName = Gamers[n].name; 
  			sscanf(Gamers[n].name, "%s", tempName);
  			Gamers[n].balance = Gamers[n+1].balance; 
  			Gamers[n].gain = Gamers[n+1].gain;
  			Gamers[n+1].balance = temp; 
  			Gamers[n+1].gain = tempGain;
  			sscanf(Gamers[n+1].name, "%s", Gamers[n].name);
			sscanf(tempName ,"%s", Gamers[n+1].name); 			
		  }
	  }
  }
  
  
  for (i = 0; i< 5; i++)
  	printf("%s %d\n", Gamers[i].name, Gamers[i].gain); 
  return 0;
}


int gamemenu()
{
  int n;
  initialize();
  while(1)
  {
  
    printf("\n0)Top up your balance\n");
    printf("1)Play Game\n");
    printf("2)Top 5 players by balance\n");
    printf("3)Top 5 winners by what they have won\n");
    printf("4)Exit the game\n");
  	printf("\nPlease use number to choose option: ");
  	scanf("%d", &n);
	  	switch(n)
	  	{
	    case 0:
			topup();
	      break;
	    case 1:
			playgame();
        break;
	    case 2:
			topbalance();
			break; 
	    case 3:
	    	//printf("Working on top gain.\n");
			topgain(); 
	    	break; 
			//topgain();
	    case 4:
			printf("Thank You for playing.");
			changeFile();
			exit(0);
			break;
	    default:
			printf("Invalid Number: please use options listed\n");
			gamemenu();
	  	}
	}
  return 0;
}

int main()
{
	gamemenu();
	return 0;
}