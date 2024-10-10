#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Player{
	int jersyNo;
	char playerName[20];
	int runs,wickets;
	int matchPlayed;
}Player;
int ctr=0,size=5;
void storeData(Player*);
void display(Player*);
void display1(Player );
Player*increaseMemory(Player*);
int searchByname(Player*,char*);
int seachByjersyNo(Player*,int);
void deleteplayerInfo(Player*,int );
void updateplayerInfo(Player*,int);
void sortByRuns(Player*);
void sortByWickets(Player*);
void sortByMatchPlayed(Player*);
void hardcodeValues(Player*);



void main()
{
	Player*play=(Player*)malloc(size*sizeof(Player));
	int choice;
	hardcodeValues(play);
	do{
		printf("\n1.Add Player\n2.Display PlayerInfo\n3.Search Player\n4.Delete player Info\n5.Update Player info\n6.Sort Player Info\n0.exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
				if(ctr!=size)
				{
					storeData(play);
				}else
				{
					printf("\nInsufficient Memory!!...Would you like to increase the memoory:?");
					char ch;
					if(ch=='y'||ch=='Y')
					{
						play=increaseMemory(play);
						storeData(play);	
					}else
					{
						printf("\nInsufficient Memory!!!!");
					}
				}
			}
			break;
			case 2:
				{
					if(ctr==0)
					{
						printf("\nPlayer Info Not Found");
					}
					else
					{
						display(play);
					}
				}
				break;
			case 3:
				{
					if(ctr==0)
					{
						printf("\nPlayer Info Not Found");
					}else
					{
						int ch;
						printf("\nEnter the choice...\n1.SearchByjersyNo\n2.SearchByName");
						scanf("%d",&ch);
						if(ch==1)
						{
							int jersyNo;
							printf("\nEnter The Jersey No:");
							scanf("%d",&jersyNo);
							int index=seachByjersyNo(play,jersyNo);
							if(index==-1)
							{
								printf("\nPlayer Info Not Found!!");	
							}
							else
							{
								display1(play[index]);
							}
						}else if(ch==2)
						{
							char pname[20];
							printf("\nEnter the name of player which you want to search:");
							scanf("%s",&pname);
							int index=searchByname(play,pname);
							if(index==-1)
							{
								printf("\nPlayer Info Not found");
							}
							else
							{
								display1(play[index]);
							}
						}
					}
						
			}break;
			case 4:
				{
					int jersyNo;
					printf("\nEnter the Jersy number which you want to delete from the record:");
					scanf("%d",&jersyNo);
					int index=seachByjersyNo(play,jersyNo);
					if(index==-1)
					{
						printf("\nPlayer Info Not found!!");	
					}
					else
					{
						deleteplayerInfo(play,index);
						printf("\nPlayer info Deleted successfully");
					}
			}
			break;
			case 5:
				{
				  	int jersyNo;
					printf("\nEnter the Jersy number which you want to delete from the record:");
					scanf("%d",&jersyNo);
					int index=seachByjersyNo(play,jersyNo);
					if(index==-1)
					{
						printf("\nPlayer Info Not found!!");	
					}else
					{
						updateplayerInfo(play,index);	
					}
				}break;
			 case 6: {
                int ch;
                printf("\n1.Sort player by runs\n2.Sort student wickets\n3.sort player by match played");
                scanf("%d", &ch);
                if (ch == 1) {
                    sortByRuns(play);
                } else if (ch == 2) {
                    sortByWickets(play);
                }else if(ch==3)
                {
                	sortByMatchPlayed(play);
				}
            }
            break;
		}

		
	}while(choice!=0);
	
}
void hardcodeValues(Player *play) {
    Player p;
    p.jersyNo = 10;
    strcpy(p.playerName, "Sachin");
    p.runs = 101;
    p.wickets = 2;
    p.matchPlayed=3;
    play[ctr++] =p;
 
    p.jersyNo = 7;
    strcpy(p.playerName, "Dhoni");
    p.runs = 125;
    p.wickets = 3;
    p.matchPlayed=2;
    play[ctr++] =p;
  
    p.jersyNo =18;
    strcpy(p. playerName, "Virat");
    p.runs = 145;
    p.wickets = 5;
    p.matchPlayed=7;
    play[ctr++] =p;
    
    p.jersyNo =45;
    strcpy(p.playerName, "Rohit");
    p.runs = 154;
    p.wickets = 7;
    p.matchPlayed=5;
    play[ctr++]=p;
}
void storeData(Player*play)
{
	Player p;
	printf("\nEnter the jersyNo:");
	scanf("%d",&p.jersyNo);
	printf("\nEnter the PlayerName:");
	scanf("%s",&p.playerName);
	printf("\nEnter the runs scored by player:");
	scanf("%d",&p.runs);
	printf("\nEnter the wickets taken by player:");
	scanf("%d",&p.wickets);
	printf("\nEnter the Matches Played By the Player:");
	scanf("%d",&p.matchPlayed);
	play[ctr++]=p;
}
void display(Player*play)
{
	printf("\n-------------------------------------");
    printf("\n | jersyNo | Name | runs | wickets | MatchPlayed |");
    printf("\n-------------------------------------");
    for(int i=0;i<ctr;i++)
    {
    	printf("\n |%.10d |%.12s |%.12d |%.10d| %.10d|",play[i].jersyNo,play[i].playerName,play[i].runs,play[i].wickets,play[i].matchPlayed);
	}
}

void display1(Player p) {
    printf("\njersyNo:%d\nname:%s\nRuns:%d\nwickets:%d\nMatchplayed:%d", p.jersyNo,p.playerName,p.runs,p.wickets,p.matchPlayed);
}
Player*increaseMemory(Player*play)
{	
	int n=5;
	size+=n;
	play=(Player*)realloc(play,size*sizeof(Player));
	return play;
}
int seachByjersyNo(Player*play,int jersyNo)
{
	for(int i=0;i<ctr;i++)
	{
		if(play[i].jersyNo==jersyNo)
			return i;
	}return -1;
}
int searchByname(Player*play,char*pname)
{
	for(int i=0;i<ctr;i++)
	{
		if(strcasecmp(play[i].playerName,pname)==0)
		return i;
	}return -1;
}
void deleteplayerInfo(Player*play,int index)
{
	for(int i=index;i<ctr-1;i++)
	{
		play[i]=play[i+1];
	}
	ctr--;
}
void updateplayerInfo(Player*play,int index)
{
	int ch;
	printf("\n1.update run\n2.UpdateWicket\n3.update match Played");
	scanf("%d",&ch);
	if(ch==1)
	{
		int newruns;
		printf("\nEnter the runs scored by the player:");
		scanf("%d",&newruns);
		play[index].runs+=newruns;
	}
	if(ch==2)
	{
		int newWickets;
		printf("\nEnter the newWickets taken by the player:");
		scanf("%d",&newWickets);
		play[index].wickets+=newWickets;
	}
	if(ch==2)
	{
		int newMatchplayed;
		printf("\nEnter the newWickets taken by the player:");
		scanf("%d",&newMatchplayed);
		play[index].matchPlayed+=newMatchplayed;	
	}
	
}
void sortByRuns(Player*play)
{
	int ch;
	printf("\n1.sortby descending order:\n2.sortby ascending order");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("\nSorting the runs scored by the player in Descending order:");
		Player temps[size];
		for(int i=0;i<ctr;i++)
		{
			temps[i]=play[i];
		}
		for(int i=0;i<ctr;i++)
		{
			for(int j=i+1;j<ctr;j++)
			{
				if(temps[i].runs<temps[j].runs)
				{
					Player temp;
					temp=temps[i];
					temps[i]=temps[j];
					temps[j]=temp;
				}
			}
		}display(temps);
	}else if(ch==2){
		printf("\nSorting the runs scored by the player in Ascending order:");
		Player temps[size];
		for(int i=0;i<ctr;i++)
		{
			temps[i]=play[i];
		}
		for(int i=0;i<ctr;i++)
		{	
			for(int j=i+1;j<ctr;j++)
			{
				if(temps[i].runs>temps[j].runs)
				{
					Player temp;
					temp=temps[i];
					temps[i]=temps[j];
					temps[j]=temp;
				}
			}
		}display(temps);
	}
}
void sortByWickets(Player*play)
{
	int ch;
	printf("\n1.sortby descending order:\n2.sortby ascending order");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("\nSorting the wickets taken by the player in Descending order:");
		Player temps[size];
		for(int i=0;i<ctr;i++)
		{
			temps[i]=play[i];
		}
		for(int i=0;i<ctr;i++)
		{
			for(int j=i+1;j<ctr;j++)
			{
				if(temps[i].wickets<temps[j].wickets)
				{
					Player temp;
					temp=temps[i];
					temps[i]=temps[j];
					temps[j]=temp;
				}
			}
		}display(temps);
	}else if(ch==2){
		printf("\nSorting the wicket taken by the player in Ascending order:");
		Player temps[size];
		for(int i=0;i<ctr;i++)
		{
			temps[i]=play[i];
		}
		for(int i=0;i<ctr;i++)
		{	
			for(int j=i+1;j<ctr;j++)
			{
				if(temps[i].wickets>temps[j].wickets)
				{
					Player temp;
					temp=temps[i];
					temps[i]=temps[j];
					temps[j]=temp;
				}
			}
		}display(temps);
	}
}
void sortByMatchPlayed(Player*play)
{
	int ch;
	printf("\n1.sortby descending order:\n2.sortby ascending order");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("\nSorting the match played by the player in Descending order:");
		Player temps[size];
		for(int i=0;i<ctr;i++)
		{
			temps[i]=play[i];
		}
		for(int i=0;i<ctr;i++)
		{
			for(int j=i+1;j<ctr;j++)
			{
				if(temps[i].matchPlayed<temps[j].matchPlayed)
				{
					Player temp;
					temp=temps[i];
					temps[i]=temps[j];
					temps[j]=temp;
				}
			}
		}display(temps);
	}else if(ch==2){
		printf("\nSorting the match played by player in Ascending order:");
		Player temps[size];
		for(int i=0;i<ctr;i++)
		{
			temps[i]=play[i];
		}
		for(int i=0;i<ctr;i++)
		{	
			for(int j=i+1;j<ctr;j++)
			{
				if(temps[i].matchPlayed>temps[j].matchPlayed)
				{
					Player temp;
					temp=temps[i];
					temps[i]=temps[j];
					temps[j]=temp;
				}
			}
		}display(temps);
	}
}