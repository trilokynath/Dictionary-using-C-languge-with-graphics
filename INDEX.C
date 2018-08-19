#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>

int stringcmp(char *word,char *search)
{
	int identifier=0,i=0;
	while(search[i]!=NULL)
	{
		if(word[i]==search[i++])
			identifier=1;
		else
			return 0;
	}
	return identifier;
}
int main()
{
	char word[20],search[20],mean[1000],a,filename[15]="data/a.txt",character[2]="\0\0";
	int i,gd,gm=DETECT,line[2],x,y;
	FILE *fptr;
	detectgraph(&gm,&gd);
	initgraph(&gm,&gd,"Data");
	setcolor(15);
	setlinestyle(1,0,4);
	rectangle(0,0,getmaxx(),getmaxy());
	setbkcolor(6);
	do{
	cleardevice();
	setcolor(2);
	settextstyle(8,0,3);
	outtextxy(12,5,"Enter the Word to search:");
	i=0;
	do{
	search[i]=getch();
	if(search[i]==' '||search[i]=='\r')
	{
		break;
	}
	character[0]=search[i];
	outtextxy(400+i*20,5,character);
	i++;
	}while(1);
	search[i]='\0';
	strlwr(search);
	filename[5]=search[0];
	if (search[0] >= 'a' && search[0] <= 'z')
	 search[0] = search[0] - 32;
	fptr=fopen(filename,"r");
	while(fgets(word,strlen(search)+1,fptr))
	{
		i=0;
		while((mean[i++]=fgetc(fptr))!='\n') ;
		mean[i]=fgetc(fptr);
		if(stringcmp(word,search))
		{
			cleardevice();
			settextstyle(10,0,4);
			setcolor(15);
			rectangle(20,15,500,80);
			setcolor(14);
			outtextxy(50,5,word);
			i=0;
			line[0]=0;
			line[1]=0;
			setcolor(1);
			settextstyle(6,0,1);
			while(mean[i]!='\n')
			{
				character[0]=mean[i++];
				y=100+20*line[1];
				x=200+line[0]*10;
				outtextxy(x,y,character);
				if(i%40==0)
				{
					line[0]=0;
					line[1]++;
				}
				line[0]++;
			}
			fclose(fptr);
		}
	}

		setcolor(13);
		settextstyle(6,0,4);
		outtextxy(100,400,"Press enter to search again");
		a=getche();
	}while(a=='\r');
	fclose(fptr);
	closegraph();
	return 0;
}