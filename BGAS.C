#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<string.h>
#include<stdarg.h>

void draw_bar(int,int,int,int);
void read_cust();
void list_cust();
void search_cust();
void del_cust();
void read_inc();
void list_inc();
void search_inc();
void del_inc();
void read_ouc();
void list_ouc();
void search_ouc();
void del_ouc();
void cyl_stock ();
void cyl_book();
void cyl_rel();
void cyl_haw();
void wel();
void msg(char *);
void cyl_urg();
void book_cust();
void comp_cust();
void rel_cust();
void gprint(int *x1,int *y1,char *list,...);
int count=1,col=1;
char datebuf[9];
char timebuf[9];
unsigned int bsize;
 void *bars;
 int a,b,flag;
#include "fail.h"
void main(void)
{
int gdriver = DETECT, gmode, errorcode;

int c,r,d,x,y,i,ampt;
char ch,login[]={"GAS"},login1[5],arr1[2];
initgraph(&gdriver, &gmode, ".\\BGI\\");
errorcode = graphresult();
if (errorcode != grOk)  /* an eroccred */
	{
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
       getch();
	exit(1);
	}
_strdate(datebuf);
wel();
drsc();
setcolor(2);
settextstyle(0,0,1);
outtextxy(60,450,"Developed By:- APN™");
outtextxy(400,450,"PRESS ESC KEY TO EXIT");
gotoxy(20,23);
printf("PASSWARD :-");
c=32,r=23,d=1,i=0,ampt=0;
       while(d<=3)
	{
     while(!kbhit())
       {
     _strtime(timebuf);
	 gotoxy(20,2);
printf("%s\t\t%s",datebuf,timebuf);
gotoxy(c,r);
}
	fflush(stdin);
	ch=getch();
	 if(ch==27)
	ter();
	 else
	if(d<3)
		{
		printf("*");
		login1[i++]=ch;
		d++; c++;
		}
	else
		{
		printf("*");
		login1[i++]=ch;
		login1[i]='\0';
		ampt+=1;
		if(strcmpi(login1,login)!=0)
			{
			msg("Invalid Passward");
			getch();
			gotoxy(35,25);
			printf("                                 ");
			c=32;
			gotoxy(c,r);
			printf("    ");
			d=1;
			i=0;
			if(ampt==3)
			fail();
			  }
		 else

			d=4;
		}
	}
	msg("Passward Accepted");
ch=getch();
clearviewport();
if(ch==27)
ter();
top:x = 180;
y = 115;
a=170;
b=108;
count=1;
clearviewport();
draw_bar(a,b,258,16);
drsc();
rectangle(160,85,440,310);
rectangle(155,80,445,315);
mmsg(200,"MAIN MENU");
sz(258);
while(1)
	{
	setcolor(CYAN);
	outtextxy(180,110,"CUSTOMER'S DETAILS");
	outtextxy(180,130,"INCOMING TRANSFER OF A CUSTOMER");
	outtextxy(180,150,"OUTGOING TRANSFER OF A CUSTOMER");
	outtextxy(180,170,"BOOKING OF A REFILL");
	outtextxy(180,190,"RELEASING REFILL VOUCHERS");
	outtextxy(180,210,"COMPLAIN FROM CUSTOMER");
	outtextxy(180,230,"REPORTS");
	outtextxy(180,250,"STOCK");
	outtextxy(180,270,"EXIT");
	setfillstyle(SOLID_FILL,CYAN);
	bar(170,330,480,350);
	setcolor(1);

	switch(count)
		{
		case 1 : outtextxy(170,340,"STATUS:- ENTER NEW CUSTOMER");
		break;
		case 2 : outtextxy(170,340,"STATUS:- ENTER NEW INCOMING CUSTOMER");
		break;
		case 3 : outtextxy(170,340,"STATUS:- ENTER NEW OUTGOING CUSTOMER");
		break;
		case 4 : outtextxy(170,340,"STATUS:- ENTER NEW BOOKING OF REFILL");
		break;
		case 5 : outtextxy(170,340,"STATUS:- ENTEER DELIVERY OF REFILL");
		break;
		case 6 : outtextxy(170,340,"STATUS:- ENTER COMPLAIN FROM CUSTOMER");
		break;
		case 7 : outtextxy(170,340,"STATUS:- DAILY REPORT OF TRANSACTION");
		break;
		case 8 : outtextxy(170,340,"STATUS:- DETAILS OF STORES STOCK");
		break;
		case 9 : outtextxy(170,340,"STATUS:- EXIT FROM PROGRAM");
		}
		dt();
	ch=getch();
	if(ch==0)
		{
		ch=getch();
		if(ch==80)
			{
			count++;
			if(count==10)
				count=1;
			/* erase old image */
			setcolor(1);
			putimage(a,b,bars,XOR_PUT);
			y +=20;
			b += 20;

			if (y > 280 )
				{
				y = 115;
				b = 108;
				}
			putimage(a,b,bars,XOR_PUT);
			}
		if(ch==72)
			{
			count--;
			if(count==0)
				count=1;
			putimage(a,b,bars,XOR_PUT);
			y -=20;
			b -=20;
			if (y < 115)
				{
				y =115;
				b=108;
				}
			putimage(a,b,bars,XOR_PUT);
			}
		}
	else
		if(count==9)
		ter();
	else
		      if(ch==13)
		      break;
	}
	/*end of while(1)*/
	/*Draw Customer menu*/
clearviewport();
if(count==1 || count==2 || count==3 )
	{
	start:x=180;
	y=125;
	a=220;
	b=115;
	col=1;
	clearviewport();
	draw_bar(a,b,170,16);
	drsc();
	rectangle(205,95,400,230);
	rectangle(200,90,405,235);
	sz(170);
	mmsg(150,"CUSTOMER DETAIL(s)");
		while(1)
		{
		setcolor(CYAN);
		outtextxy(230,120,"ADD ANY CUSTOMER");
		outtextxy(230,140,"SEARCH ANY CUSTOMER");
		outtextxy(230,160,"LIST OF CUSTOMER");
		outtextxy(230,180,"DELETE ANY CUSTOMER");
		outtextxy(230,200,"EXIT");
		setfillstyle(SOLID_FILL,CYAN);
		bar(170,250,450,270);
		setcolor(1);
		switch(col)
			{
			case 1: outtextxy(180,260,"STATUS:- ADD ANY CUSTOMER");
			break;
			case 2: outtextxy(180,260,"STATUS:- SEARCH ANY CUSTOMER");
			break;
			case 3: outtextxy(180,260,"STATUS:- DISPLAY LIST OF CUSTOMER");
			break;
			case 4: outtextxy(180,260,"STATUS:- DELETE ANY CUSTOMER");
			break;
			case 5: outtextxy(180,260,"STATUS:- GO TO MAIN MENU");
			break;
			}
			dt();
		ch=getch();
		if(ch==0)
			{
			ch=getch();
			if(ch==80)
				{
				col++;
				if(col==6)
					col=1;
				putimage(a,b,bars,XOR_PUT);
				y += 20;
				b += 20;

				if (y > 212)
					{
					y = 125;
					b = 115;
					}
			putimage(a,b,bars,XOR_PUT);
				}
			if(ch==72)
				{
				col--;
				if(col==0)
				col=1;
				putimage(a,b,bars,XOR_PUT);
				y =b -= 20;
				if (y < 125)
					{
					y = 125;
					b = 115;
					}
			putimage(a,b,bars,XOR_PUT);
				}
			}
		else
			if(ch==13)
			{
			clearviewport();
			switch(count)
				{
				case 1: if(col==1)
							read_cust();
						else
							if(col==2)
								search_cust();
							else
								if(col==3)
									list_cust();
								else
									if(col==4)
										del_cust();
									else
										{

										goto top;
										}
				break;
				case 2: if(col==1)
							read_inc();
						else
							if(col==2)
								search_inc();
							else
								if(col==3)
									list_inc();
								else
									if(col==4)
										del_inc();
									else
										{
									       //	free(arrow);
										goto top;
										}
				break;
				case 3: if(col==1)
							read_ouc();
						else
							if(col==2)
								search_ouc();
							else
								if(col==3)
									list_ouc();
								else
									if(col==4)
										del_ouc();
									else
										{
									       //	free(arrow);
										goto top;
										}
				}
			goto start;
			}
		}
	}
clearviewport();

if(count==4)
	{
	book_cust();
	goto top;
	}
if(count==5)
	{
	rel_cust();
	goto top;
	}
if(count==6)
	{
	comp_cust();
	goto top;
	}

if(count==8)
	{
	char ch,choice,no_cyl[6],no_fil_cyl[6],rate[8];
	int flag,flag1,x1,y1;
	FILE *fp1,*fp2;
	st:x=180;
	y=125;
	a=220;
	b=115;
	col=1;
	flag1=1;
	clearviewport();
	fp1=fopen("STOCK.TXT","rb+") ;
	if(fp1==NULL)
		{
		fp1=fopen("STOCK.TXT","wb+") ;
		flag1=0;
		if(fp1==NULL)
			{
			printf("CANNOT OPEN FILE");
			getch();
			return;
			}
		}
	draw_bar(a,b,220,16);
	drsc();
	rectangle(205,95,450,230);
	rectangle(200,90,455,235);
	sz(220);
	getimage(a,b,a+220,b+16,bars);
	mmsg(200,"STOCK MENU");
	settextstyle(0,0,1);
	while(1)
		{
		setcolor(CYAN);
		outtextxy(230,120,"NUMBER OF CYLINDER");
		outtextxy(230,140,"NUMBER OF FILLED CYLINDER");
		outtextxy(230,160,"UNIT RATE");
		outtextxy(230,180,"RETURN TO MAIN MENU");
		setfillstyle(SOLID_FILL,CYAN);
		bar(170,250,475,275);
		setcolor(1);
		switch(col)
			{
			case 1: outtextxy(180,260,"STATUS:-  AVILABLE CYLINDERS");
			break;
			case 2: outtextxy(180,260,"STATUS:-  NO. OF FILLED CYLINDER");
			break;
			case 3: outtextxy(180,260,"STATUS:-  RATE OF EACH CYLINDER");
			break;
			case 4: outtextxy(180,260,"STATUS:-   GO TO MAIN MENU");
			break;
			}
		dt();
		ch=getch();
		if(ch==0)
			{
			ch=getch();
			if(ch==80)
				{
				col++;
				if(col==5)
					col=1;
				putimage(a,b,bars,XOR_PUT);
				y += 20;
				b += 20;
				if (y > 192)
					{
					y = 125;
					b = 115;
					}
				putimage(a,b,bars,XOR_PUT);
				}
			if(ch==72)
				{
				col--;
				if(col==0)
					col=1;
				putimage(a,b,bars,XOR_PUT);
				y =b -= 20;
				if (y < 125)
					{
					y = 125;
					b = 115;
					}
				putimage(a,b,bars,XOR_PUT);
				}
			}
		else
			if(col==4)
				goto top;
			else
				if(ch==13)
				break;
		}
	clearviewport();
	flag=0;
	setfillstyle(SOLID_FILL,CYAN);
	rectangle(30,30,520,150);
	switch(col)
		{
		case 1: setcolor(CYAN);
				outtextxy(50,50,"ENTER TOATAL NO. OF  CYLINDER");
				do
					{
					gotoxy(43,4);
					setfillstyle(SOLID_FILL,CYAN);
					bar(300,45,500,65);
					scanf("%s",&no_cyl);
					if(strlen(no_cyl) > 0)
						for(i=0;no_cyl[i]!='\0';i++)
							{
							if(no_cyl[i]>=48 && no_cyl[i]<=57)
								flag=1;
							else
								{
								outtextxy(200,400,"INVALID ENTRY!TRY AGAIN");
								flag=0;
								getch();
								setfillstyle(SOLID_FILL,BLACK);
								bar(190,390,420,410);
								break;
								}
							}
					}while(flag==0);
		break;
		case 2: if(flag1==1)
				fread(&stock,sizeof(stock),1,fp1);
				else
					{
					outtextxy(200,400,"FIRST INSERT TOTAL NO. OF CYLINDER!PRESS ENTER");
					getch();
					goto st;
					}
				setcolor(CYAN);
				outtextxy(50,50,"ENTER NO. OF  FILLED CYLINDER");
				do
					{
					gotoxy(43,4);
					setfillstyle(SOLID_FILL,CYAN);
					bar(300,45,500,65);
					scanf("%s",&no_fil_cyl);
					if(strlen(no_fil_cyl) > 0)
						for(i=0;no_fil_cyl[i]!='\0';i++)
							{
							if(no_fil_cyl[i]>=48 && no_fil_cyl[i]<=57)
								flag=1;
							else
								{
								outtextxy(200,400,"INVALID ENTRY!TRY AGAIN");
								flag=0;
								getch();
								setfillstyle(SOLID_FILL,BLACK);
								bar(190,390,420,410);
								break;
								}
							}
						if(flag==1 && atoi(no_fil_cyl)+stock.no_fil_cyl > stock.no_cyl)
							{
							outtextxy(200,400,"NOT MORE THAN TOTAL NO. OF CYLINDER");
							x1=490;
							y1=400;
							gprint(&x1,&y1,"%d",stock.no_cyl);
							flag=0;
							getch();
							setfillstyle(SOLID_FILL,BLACK);
							bar(190,390,530,410);
							}
					}while(flag==0);
		break;
		case 3: setcolor(CYAN);
				outtextxy(50,50,"ENTER UNIT RATE OF  CYLINDER");
				do
					{
					setfillstyle(SOLID_FILL,CYAN);
					bar(300,45,500,65);
					gotoxy(43,4);
					gets(rate);
					if(strlen(rate)>0)
						for(i=0;rate[i]!='\0';i++)
							{
							if(rate[i]>=48 && rate[i]<=57)
								{
								flag=1;
								continue;
								}
							else
								if(rate[i]=='.')
									i++;
								else
									{
									outtextxy(200,400,"INVALID ENTRY!TRY AGAIN");
									flag=0;
									getch();
									setfillstyle(SOLID_FILL,BLACK);
									bar(190,390,420,410);
									break;
									}
							}
					}while(flag==0);
		break;
		}
	flag=0;
	setcolor(CYAN);
	outtextxy(50,100,"DO YOU WANT TO SAVE DATA");
	do
		{
		gotoxy(42,7);
		setfillstyle(SOLID_FILL,CYAN);
		bar(320,93,340,113);
		fflush(stdin);
		choice=getchar();
		if(choice!='Y' && choice!='N')
			{
			outtextxy(200,400,"ENTER (Y/N)");
			getch();
			}
		else
			flag=1;
		setfillstyle(SOLID_FILL,BLACK);
		bar(190,390,420,410);
		}while(flag==0);
	if(choice=='Y')
		{
		if(flag1==1)
			fread(&stock,sizeof(stock),1,fp1);
		if(col==1 && flag1==1)
			stock.no_cyl+=atoi(no_cyl);
		else
			stock.no_cyl=atoi(no_cyl);
		if(col==2)
			{
			if(flag1==1)
				stock.no_fil_cyl+=atoi(no_fil_cyl);
			else
				stock.no_fil_cyl=atoi(no_fil_cyl);
			stock.no_emp_cyl=stock.no_cyl-stock.no_fil_cyl+stock.no_def_cyl;
			}
		if(col==3)
			stock.unit_rate=atof(rate);
		fp2=fopen("TEMP.TXT","wb");
		fwrite(&stock,sizeof(stock),1,fp2);
		fclose(fp1);
		fclose(fp2);
		remove("STOCK.TXT");
		rename("TEMP.TXT","STOCK.TXT");
		}
		end:
	fclose(fp1);
	goto st;
	}
if(count==7)
	{
	char ch;
	t:x=180;
	y=125;
	a=190;
	b=115;
	col=1;
	clearviewport();
	draw_bar(a,b,230,16);
	drsc();
	settextstyle(0,0,1);
	rectangle(175,95,430,250);
	rectangle(170,90,435,255);
	mmsg(180,"REPORT MENU");
	sz(230);
	getimage(a,b,a+230,b+16,bars);
	while(1)
		{
		setcolor(CYAN);
		outtextxy(200,120,"TOTAL STOCK REPORT");
		outtextxy(200,140,"DAY WISE REFILL BOOKING");
		outtextxy(200,160,"DAY WISE REFILL RELEASE");
		outtextxy(200,180,"HAWKER WISE REFILL RELEASE");
		outtextxy(200,200,"URGENT DELIVERY REPORT");
		outtextxy(200,220,"RETURN TO MAIN MENU");
		setfillstyle(SOLID_FILL,CYAN);
		bar(170,270,440,290);
		setcolor(1);
		switch(col)
			{
			case 1: outtextxy(180,280,"STATUS:- AVILABLE CYLINDERS");
			break;
			case 2: outtextxy(180,280,"STATUS:- BOOKINGS OF CYLINDERS");
			break;
			case 3: outtextxy(180,280,"STATUS:- DELIVERY OF CYLINDER");
			break;
			case 4: outtextxy(180,280,"STATUS:- SUPPLIED BY HAWKER");
			break;
			case 5: outtextxy(180,280,"STATUS:- DELIVERY URGENTLY");
			break;
			case 6: outtextxy(180,280,"STATUS:- GO TO MAIN MENU");
			break;
			}
		dt();
		ch=getch();
		if(ch==0)
			{
			ch=getch();
			if(ch==80)
				{
				col++;
				if(col==7)
					col=1;
				putimage(a,b,bars,XOR_PUT);
				y += 20;
				b += 20;
				if (y > 232)
					{
					y = 125;
					b = 115;
					}
				putimage(a,b,bars,XOR_PUT);
				}
			if(ch==72)
				{
				col--;
				if(col==0)
					col=1;
			putimage(a,b,bars,XOR_PUT);
				y =b -= 20;
				if (y < 125)
					{
					y = 125;
					b = 115;
					}
			putimage(a,b,bars,XOR_PUT);
				}
			}
		else
			break;
		}//WHILE
	switch(col)
		{
		case 1: cyl_stock();
		break;
		case 2: cyl_book();
		break;
		case 3: cyl_rel();
		break;
		case 4: cyl_haw();
		break;
		case 5: cyl_urg();
		break;
		case 6:	goto top;
		}
	goto t;
	}
}
void cyl_stock ()
{
FILE *fp;
int x1=65,y1=130;
clearviewport();
fp=fopen("STOCK.TXT","rb");
if(fp==NULL)
	{
	outtextxy(50,50,"FILE NOT OPEN");
	getch();
	return;
	}
wmsg(150,"REPORT OF STOCK");
drsc();
rectangle(40,90,590,400);
gotoxy(60,2);
printf("Date : %s",datebuf);
setcolor(CYAN);
settextstyle(0,0,1);
fseek(fp,0,SEEK_SET);
fread(&stock,sizeof(stock),1,fp);
gprint(&x1,&y1,"TOTAL NUMBER OF CYLINDER               %d",stock.no_cyl);
gprint(&x1,&y1,"TOTAL NUMBER OF FILLED CYLINDER        %d",stock.no_fil_cyl);
gprint(&x1,&y1,"TOTAL NUMBER OF EMPTY CYLINDER         %d",stock.no_emp_cyl);
gprint(&x1,&y1,"TOTAL NUMBER OF DEFECTIVE CYLINDER     %d",stock.no_def_cyl);
gprint(&x1,&y1,"UNIT RATE                              %.2f",stock.unit_rate);
getch();
fclose(fp);
}

void cyl_book()
{
char date[12],ch;
int flag,i,n,e,p,cp,tp,pr,r;
FILE *fp;
int x1=65,y1=120;
fp=fopen("REF.TXT","rb");
if(fp==NULL)
	{
	outtextxy(50,50,"FILE NOT OPEN");
	getch();
	return;
	}

clearviewport();
fseek(fp,0,SEEK_SET);
wmsg(120,"DAY WISE REPORT" );
drsc();
rectangle(60,80,590,300);
gotoxy(55,7);
printf("Date : %s",datebuf);
setcolor(CYAN);
	outtextxy(100,110,"DATE (DD/MM/YYYY)");
		flag=0;
	e=0;
	gotoxy(35,8);
	printf("  /  /");
	gotoxy(35,8);
	do
		{
	fflush(stdin);
	 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==11&&ch!=13)
		  sherr("MAX 10 CHARACTER");
		 if(e<=10)
		if((ch>=48&&ch<=57))
		{
		date[e++]=ch;
		printf("%c",ch);
		if(e==2||e==5)
		{
		printf("/");
		date[e++]='/';
		} }
		else
		{
		if(ch==13)
		date[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(35+e-1,8);
		printf(" ");
		gotoxy(35+e-1,8);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		       sherr("INVALID DATE");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	   flag=0;
	clearviewport();
	    i=1;    p=0;cp=1;
while(fread(&ref,sizeof(ref),1,fp)==1)
{
if( strcmpi(ref.book_date,date)==0)
flag=1;
p++;
}
fseek(fp,SEEK_SET,0);
tp=p/20;
if(p%20!=0)
tp++; pr=0;
sta:r=5;
setcolor(10);
settextstyle(7,0,1);
setusercharsize(1,1,1,2);
outtextxy(100,1,"INDIAN GAS AGENCY");
outtextxy(30,15,"LIST OF BOOKINGS OF CYLINDERS");
gotoxy(60,1);
printf("Date : %s",datebuf);
setcolor(CYAN);
settextstyle(0,0,1);
line(8,35,640,35);
line(8,55,640,55);
outtextxy(10,40,"S.No.");
outtextxy(60,40,"BOOKING No.");
outtextxy(165,40,"BOOKING Date");
outtextxy(280,40,"Cust.ID");
outtextxy(350,40,"LAST Supp.Date");
outtextxy(480,40,"URGENT");
outtextxy(550,40,"PRIORTY No.");
setcolor(WHITE);
if(flag)
{
if(pr)
	{
	 gotoxy(4,r);
	printf("%2d",i);
	gotoxy(12,r);
	printf("%d",ref.book_num);
	gotoxy(23,r);
	printf("%s",ref.book_date);
	gotoxy(38,r);
	printf("%s",ref.cust_num);
	gotoxy(45,r);
	if(strcmpi(ref.l_s_date,"NULL")==0)
	printf("FIRST BOOKING");
	else
	printf(ref.l_s_date);
	gotoxy(62,r);
	if(ref.urgent=='Y')
	printf("YES");
	else
	printf("NO");
	gotoxy(73,r);
	printf("%d",ref.prior_num);
	r+=1;   i++;
	pr=0;
	}
while(fread(&ref,sizeof(ref),1,fp)==1)
	{
	delay(200);
	if(r!=25)
	{
	gotoxy(4,r);
	printf("%2d",i);
	gotoxy(12,r);
	printf("%d",ref.book_num);
	gotoxy(23,r);
	printf("%s",ref.book_date);
	gotoxy(38,r);
	printf("%s",ref.cust_num);
	gotoxy(45,r);
	if(strcmpi(ref.l_s_date,"NULL")==0)
	printf("FIRST BOOKING");
	else
	printf(ref.l_s_date);
	gotoxy(62,r);
	if(ref.urgent=='Y')
	printf("YES");
	else
	printf("NO");
	gotoxy(73,r);
	printf("%d",ref.prior_num);
	r+=1;   i++;
	}
	else
	{
	setcolor(CYAN);
	line(8,400,640,400);
	printf("\n\n\n\n\t\t\t\t\t\t\t\t");
	printf("Page %d of %d",cp++,tp);
	setcolor(10);
	outtextxy(80,435,"PRESS ANY KEY TO NEXT PAGE...");
	getch();
	clearviewport();
	pr=1;
	goto sta;
	}
	}
	setcolor(CYAN);
	line(8,400,640,400);
       gotoxy(60,24);
	printf("\n\n\n\n\t\t\t\t\t\t\t\tPage %d of %d",cp++,tp);
	outtextxy(120,430,"PRESS ESC KEY TO CLOSE SCREEN");
	getch();
}
	if(flag==0)
		sherr("NO BOOKING OR INVALID DATE!PRESS ENTER");
		end:
fclose(fp);
}


void cyl_rel()
{
char date[12],choice='y',ch;
int flag,x1,y1,i,e,cp,tp,pr,p,r;

FILE *fp;
fp=fopen("REF.TXT","rb");
if(fp==NULL)
	{
	outtextxy(50,50,"FILE NOT OPEN");
	getch();
	return;
	}
       clearviewport();
fseek(fp,0,SEEK_SET);
wmsg(120,"DAY WISE REPORT" );
drsc();
rectangle(60,80,590,300);
gotoxy(55,7);
printf("Date : %s",datebuf);
setcolor(CYAN);
	outtextxy(100,110,"DATE (DD/MM/YYYY)");
		flag=0;
	e=0;
	gotoxy(35,8);
	printf("  /  /");
	gotoxy(35,8);
	do
		{
	fflush(stdin);
	 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==11&&ch!=13)
		  sherr("MAX 10 CHARACTER");
		 if(e<=10)
		if((ch>=48&&ch<=57))
		{
		date[e++]=ch;
		printf("%c",ch);
		if(e==2||e==5)
		{
		printf("/");
		date[e++]='/';
		} }
		else
		{
		if(ch==13)
		date[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(35+e-1,8);
		printf(" ");
		gotoxy(35+e-1,8);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		       sherr("INVALID DATE");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	   flag=0;
	clearviewport();
	    i=1;    p=0;cp=1;
while(fread(&ref,sizeof(ref),1,fp)==1)
{
if( strcmpi(ref.book_date,date)==0)
flag=1;
p++;
}
fseek(fp,SEEK_SET,0);
tp=p/20;
if(p%20!=0)
tp++; pr=0;
sta:r=5;
setcolor(10);
settextstyle(7,0,1);
setusercharsize(1,1,1,2);
outtextxy(100,1,"INDIAN GAS AGENCY");
outtextxy(30,15,"LIST OF RELEASING OF VOUCHER");
gotoxy(60,1);
printf("Date : %s",datebuf);
setcolor(CYAN);
settextstyle(0,0,1);
line(8,35,640,35);
line(8,55,640,55);
outtextxy(10,40,"S.No.");
outtextxy(60,40,"BOOKING No.");
outtextxy(165,40,"VOUCHER No.");
outtextxy(280,40,"VOUCHER Date");
outtextxy(400,40,"SUPPLY MODE");
outtextxy(510,40,"H/V No.");
//outtextxy(550,40,"PRIORTY No.");
setcolor(WHITE);
if(flag)
{
if(pr)
	{
	 gotoxy(4,r);
	printf("%2d",i);
	gotoxy(12,r);
	printf("%d",ref.book_num);
	gotoxy(23,r);
	printf("%s",ref.vouc_num);
	gotoxy(37,r);
	printf("%s",ref.vouc_date);
	gotoxy(55,r);
	if(ref.supp_mode==1)
	{
	printf("HAWKER");
	gotoxy(65,r);
	printf("%s",ref.hawk_num);
	}
	else
	if(ref.supp_mode==2)
	{
	printf("De.VAN");
	gotoxy(65,r);
	printf("%s",ref.vehi_no);
	}
	else
	printf("SELF");
	r+=1;   i++;
	pr=0;
	}
while(fread(&ref,sizeof(ref),1,fp)==1)
	{
	delay(200);
	if(r!=25)
	{
	 gotoxy(4,r);
	printf("%2d",i);
	gotoxy(12,r);
	printf("%d",ref.book_num);
	gotoxy(23,r);
	printf("%s",ref.vouc_num);
	gotoxy(38,r);
	printf("%s",ref.vouc_date);
	gotoxy(55,r);
	if(ref.supp_mode==1)
	{
	printf("HAWKER");
	gotoxy(65,r);
	printf("%s",ref.hawk_num);
	}
	else
	if(ref.supp_mode==2)
	{
	printf("De.VAN");
	gotoxy(65,r);
	printf("%s",ref.vehi_no);
	}
	else
	printf("SELF");
	r+=1;   i++;
	}
	else
	{
	setcolor(CYAN);
	line(8,400,640,400);
	printf("\n\n\n\n\t\t\t\t\t\t\t\t");
	printf("Page %d of %d",cp++,tp);
	setcolor(10);
	outtextxy(80,435,"PRESS ANY KEY TO NEXT PAGE...");
	getch();
	clearviewport();
	pr=1;
	goto sta;
	}
	}
	setcolor(CYAN);
	line(8,400,640,400);
       gotoxy(60,24);
	printf("\n\n\n\n\t\t\t\t\t\t\t\tPage %d of %d",cp++,tp);
	outtextxy(120,430,"PRESS ESC KEY TO CLOSE SCREEN");
	getch();
}
	if(flag==0)
		sherr("NO BOOKING OR INVALID DATE!PRESS ENTER");
		end:
fclose(fp);
       }

void cyl_haw()
{
char date[12],choice='y',ch;
int flag,i,p,cp,tp,r,e,pr;

FILE *fp;
fp=fopen("REF.TXT","rb+");
if(fp==NULL)
	{
	outtextxy(50,50,"FILE NOT OPEN");
	getch();
	return;
	}
	     clearviewport();
fseek(fp,0,SEEK_SET);
wmsg(120,"DAY WISE REPORT" );
drsc();
rectangle(60,80,590,300);
gotoxy(55,7);
printf("Date : %s",datebuf);
setcolor(CYAN);
	outtextxy(100,110,"DATE (DD/MM/YYYY)");
		flag=0;
	e=0;
	gotoxy(35,8);
	printf("  /  /");
	gotoxy(35,8);
	do
		{
	fflush(stdin);
	 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==11&&ch!=13)
		  sherr("MAX 10 CHARACTER");
		 if(e<=10)
		if((ch>=48&&ch<=57))
		{
		date[e++]=ch;
		printf("%c",ch);
		if(e==2||e==5)
		{
		printf("/");
		date[e++]='/';
		} }
		else
		{
		if(ch==13)
		date[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(35+e-1,8);
		printf(" ");
		gotoxy(35+e-1,8);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		       sherr("INVALID DATE");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	   flag=0;
	clearviewport();
	    i=1;    p=0;cp=1;
while(fread(&ref,sizeof(ref),1,fp)==1)
{
if( strcmpi(ref.book_date,date)==0)
flag=1;
p++;
}
fseek(fp,SEEK_SET,0);
tp=p/20;
if(p%20!=0)
tp++; pr=0;
sta:r=5;
setcolor(10);
settextstyle(7,0,1);
setusercharsize(1,1,1,2);
outtextxy(100,1,"INDIAN GAS AGENCY");
outtextxy(30,15,"LIST OF RELEASING OF VOUCHER");
gotoxy(60,1);
printf("Date : %s",datebuf);
setcolor(CYAN);
settextstyle(0,0,1);
line(8,35,640,35);
line(8,55,640,55);
outtextxy(10,40,"S.No.");
outtextxy(60,40,"HAWKER No.");
outtextxy(165,40,"VOUCHER No.");
outtextxy(280,40,"VOUCHER Date");
outtextxy(400,40,"CUSTOMER ID");
setcolor(WHITE);
if(flag)
{
if(pr)
	{
	 gotoxy(4,r);
	printf("%2d",i);
	gotoxy(12,r);
	printf("%s",ref.hawk_num);
	gotoxy(23,r);
	printf("%s",ref.vouc_num);
	gotoxy(37,r);
	printf("%s",ref.vouc_date);
	gotoxy(55,r);
	printf("%s",ref.cust_num);
	r+=1;   i++;
	pr=0;
	}
while(fread(&ref,sizeof(ref),1,fp)==1)
	{
	delay(200);
	if(r!=25)
	{
		 gotoxy(4,r);
	printf("%2d",i);
	gotoxy(12,r);
	printf("%s",ref.hawk_num);
	gotoxy(23,r);
	printf("%s",ref.vouc_num);
	gotoxy(37,r);
	printf("%s",ref.vouc_date);
	gotoxy(55,r);
	printf("%s",ref.cust_num);
	r+=1;   i++;
	}
	else
	{
	setcolor(CYAN);
	line(8,400,640,400);
	printf("\n\n\n\n\t\t\t\t\t\t\t\t");
	printf("Page %d of %d",cp++,tp);
	setcolor(10);
	outtextxy(80,435,"PRESS ANY KEY TO NEXT PAGE...");
	getch();
	clearviewport();
	pr=1;
	goto sta;
	}
	}
	setcolor(CYAN);
	line(8,400,640,400);
       gotoxy(60,24);
	printf("\n\n\n\n\t\t\t\t\t\t\t\tPage %d of %d",cp++,tp);
	outtextxy(120,430,"PRESS ESC KEY TO CLOSE SCREEN");
	getch();
}
	if(flag==0)
		sherr("NO BOOKING OR INVALID DATE!PRESS ENTER");
		end:
fclose(fp);
}


void cyl_urg()
{
char date[12],choice='y',ch;
int flag=0,i,p,pr,cp,tp,e,r;

FILE *fp,*fp2;
fp=fopen("REF.TXT","rb");
fp2=fopen("CUST.TXT","rb");
if(fp==NULL)
	{
	outtextxy(50,50,"FILE NOT OPEN");
	getch();
	return;
	}
if(fp2==NULL)
	{
	outtextxy(50,50,"FILE NOT OPEN");
	getch();
	return;
	}
clearviewport();
fseek(fp,0,SEEK_SET);
fseek(fp2,0,SEEK_SET);

//	     clearviewport();
//fseek(fp,0,SEEK_SET);
wmsg(120,"DAY WISE REPORT" );
drsc();
rectangle(60,80,590,300);
gotoxy(55,7);
printf("Date : %s",datebuf);
setcolor(CYAN);
	outtextxy(100,110,"DATE (DD/MM/YYYY)");
		flag=0;
	e=0;
	gotoxy(35,8);
	printf("  /  /");
	gotoxy(35,8);
	do
		{
	fflush(stdin);
	 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==11&&ch!=13)
		  sherr("MAX 10 CHARACTER");
		 if(e<=10)
		if((ch>=48&&ch<=57))
		{
		date[e++]=ch;
		printf("%c",ch);
		if(e==2||e==5)
		{
		printf("/");
		date[e++]='/';
		} }
		else
		{
		if(ch==13)
		date[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(35+e-1,8);
		printf(" ");
		gotoxy(35+e-1,8);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		       sherr("INVALID DATE");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	   flag=0;
	clearviewport();
	    i=1;    p=0;cp=1;
while(fread(&ref,sizeof(ref),1,fp)==1)
{
if( strcmpi(ref.book_date,date)==0)
flag=1;
p++;
}
fseek(fp,SEEK_SET,0);
tp=p/20;
if(p%20!=0)
tp++; pr=0;
sta:r=5;
setcolor(10);
settextstyle(7,0,1);
setusercharsize(1,1,1,2);
outtextxy(100,1,"INDIAN GAS AGENCY");
outtextxy(30,15,"LIST OF RELEASING OF VOUCHER");
gotoxy(60,1);
printf("Date : %s",datebuf);
setcolor(CYAN);
settextstyle(0,0,1);
line(8,35,640,35);
line(8,55,640,55);
outtextxy(10,40,"S.No.");
outtextxy(60,40,"CUSTOMER ID");
outtextxy(165,40,"VOUCHER No.");
outtextxy(280,40,"VOUCHER Date");
//outtextxy(400,40,"");
setcolor(WHITE);
if(flag)
{
if(pr)
	{
	if(ref.urgent=='Y')
	{
	 gotoxy(4,r);
	printf("%2d",i);
	gotoxy(12,r);
	printf("%s",ref.cust_num);
	gotoxy(23,r);
	printf("%s",ref.vouc_num);
	gotoxy(37,r);
	printf("%s",ref.vouc_date);
      //	gotoxy(55,r);
       //	printf("%s",ref.cust_num);
	r+=1;   i++;
	pr=0;
	} }
while(fread(&ref,sizeof(ref),1,fp)==1)
	{
	delay(200);
	if(r!=25)
	{
	if(ref.urgent=='Y')
	{
	 gotoxy(4,r);
	printf("%2d",i);
	gotoxy(12,r);
	printf("%s",ref.cust_num);
	gotoxy(23,r);
	printf("%s",ref.vouc_num);
	gotoxy(37,r);
	printf("%s",ref.vouc_date);
      //	gotoxy(55,r);
//	printf("%s",ref.cust_num);
	r+=1;   i++;
	}}
	else
	{
	setcolor(CYAN);
	line(8,400,640,400);
	printf("\n\n\n\n\t\t\t\t\t\t\t\t");
	printf("Page %d of %d",cp++,tp);
	setcolor(10);
	outtextxy(80,435,"PRESS ANY KEY TO NEXT PAGE...");
	getch();
	clearviewport();
	pr=1;
	goto sta;
	}
	}
	setcolor(CYAN);
	line(8,400,640,400);
       gotoxy(60,24);
	printf("\n\n\n\n\t\t\t\t\t\t\t\tPage %d of %d",cp++,tp);
	outtextxy(120,430,"PRESS ESC KEY TO CLOSE SCREEN");
	getch();
}
	if(flag==0)
		sherr("NO BOOKING OR INVALID DATE!PRESS ENTER");
		end:
fclose(fp);
/*
while(choice=='y' || choice=='Y')
	{
	flag=0;
	rectangle(60,40,520,200);
	setcolor(CYAN);
	outtextxy(100,60,"ENTER YOUR DATE");
	do
		{
		setfillstyle(SOLID_FILL,CYAN);
		gotoxy(45,5);
		bar(340,60,460,80);
		fflush(stdin);
		gets(date);
		if(strlen(date)==8)
			for(i=0;date[i]!='\0';i++)
				if(date[i]>=48 && date[i]<=57)
					flag=1;
				else
				{
				outtextxy(200,400,"INVALID ENTRY(DDMMYYYY)!TRY AGAIN");
				flag=0;
				getch();
				setfillstyle(SOLID_FILL,BLACK);
				bar(190,390,480,410);
				break;
				}
		}while(flag==0);
	flag=0;

	d:clearviewport();
	setcolor(10);
	settextstyle(7,0,1);
	setusercharsize(1,1,1,2);
	outtextxy(150,20,"URGENT WISE REPORT");
	line(100,50,560,50);
	setcolor(CYAN);
	settextstyle(0,0,1);
	rectangle(70,70,520,350);

	while(fread(&ref,sizeof(ref),1,fp1)==1)
		{
		if(strcmpi(ref.vouc_date,date)==0 && ref.urgent=='Y')
			{
			while(fread(&cust,sizeof(cust),1,fp2)==1)
				if(strcmpi(ref.cust_num,cust.cust_no)==0)
					{
					outtextxy(100,120,"CUSTOMER NO.");
					outtextxy(300,120,ref.cust_num);
					outtextxy(100,140,"CUSTOMER NAME");
					outtextxy(300,140,cust.name);
					outtextxy(100,160,"CUSTOMER ADDRESS");
					outtextxy(300,160,cust. add1);
					outtextxy(300,180,cust. add2);
					setcolor(10);
					outtextxy(200,400,"PRESS ANY KEY TO CONTINUE...");
					setcolor(CYAN);
					getch();
					clearviewport();
					flag=1;
					}
			rewind(fp2);
			goto d;
			}
		}
	if(flag==0)
		{
		outtextxy(140,400,"NO URGENT DELIVERY OR INVLID DATE!PRESS ENTER");
		getch();
		setfillstyle(SOLID_FILL,BLACK);
		bar(130,390,600,410);
		}
	flag=0;
	outtextxy(85,320,"DO YOU WANT MORE (Y/N)");
	do
		{
		setfillstyle(SOLID_FILL,CYAN);
		gotoxy(45,21);
		bar(350,318,370,338);
		fflush(stdin);
		choice=getchar();
		if(choice!='Y' && choice!='N')
			{
			outtextxy(200,400,"ENTER (Y/N)");
			getch();
			setfillstyle(SOLID_FILL,BLACK);
			bar(190,390,420,410);
			}
		else
			{
			flag=1;
			clearviewport();
			}
		}while(flag==0);
	if(choice=='Y')
		{
		rewind(fp1);
		rewind(fp2);
		}
	}   */
//fclose(fp1);
fclose(fp2);
}



void draw_bar(int a,int b,int l,int w)
{
setfillstyle(SOLID_FILL,RED);
bar(a,b,a+l,b+w);
}
void read_cust()
{
FILE *fp;
char ch,choice='y',cust_num1[6],cust_num2[6],cust_num3[6];
int flag=0,n,i,k;
while(choice=='y' || choice== 'Y')
	{
	clearviewport();
	wmsg(30,"ADD CUSTOMER DETAIL(s) SCREEN");
	drsc();
	rectangle(50,110,600,380);
	setcolor(CYAN);
	outtextxy(120,150,"CUSTOMER NO:-");
	gotoxy(55,8);
	printf("Date : %s",datebuf);
	fp=fopen("CUST.TXT","rb+");
	if(fp==NULL)
		{
		fp=fopen("CUST.TXT","wb+");
		strcpy(cust_num1,"C0000");
		if(fp==NULL)
			{
			printf("CANNOT OPEN FILE");
			return;
			}
		}
	else
		{
		fseek(fp,0,SEEK_SET);
		fread(&cust,sizeof(cust),1,fp);
		strcpy(cust_num1,cust.cust_no);
		}
	i=1;k=0;
	while(cust_num1[i]!='\0')
		cust_num3[k++]=cust_num1[i++];
	cust_num3[k]='\0';
	while(fread(&cust,sizeof(cust),1,fp)==1)
		{
		strcpy(cust_num2,cust.cust_no);
		i=1;k=0;
		while(cust_num2[i]!='\0')
			cust_num2[k++]=cust_num2[i++];
		cust_num2[k]='\0';
		if((atoi(cust_num2)) >= (atoi(cust_num3)))
			strcpy(cust_num1,cust.cust_no);
		}
	i=1;
	k=0;
	while(cust_num1[i]!='\0')
		cust_num2[k++]=cust_num1[i++];
	cust_num2[k]='\0';
	n=atoi(cust_num2);
	n=n+1;
	if(n<10)
		{
		strcpy(cust_num1,"C000");
		strcat(cust_num1,itoa(n,cust_num2,10));
		}
	else
		if(n>=10 && n<100)
			{
			strcpy(cust_num1,"C00");
			strcat(cust_num1,itoa(n,cust_num2,10));
			}
		else
			if(n>=100 && n<1000)
				{
				strcpy(cust_num1,"C0");
				strcat(cust_num1,itoa(n,cust_num2,10));
				}
			else
				if(n>=1000)
					{
					strcpy(cust_num1,"C");
					strcat(cust_num1,itoa(n,cust_num2,10));
					}
	setcolor(WHITE);
	gotoxy(45,10);
	printf("%s",cust_num1);
	strcpy(cust.cust_no,cust_num1);
	flag=0;
	setcolor(CYAN);
	outtextxy(120,185,"CUSTOMER NAME:-");
	gotoxy(45,12);i=0;
	fflush(stdin);
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
	       if(i==31&&ch!=13)
	       sherr("MAX 30 CHARACTER");
	    if(i<=30)
		if((ch>=65&&ch<=90)||ch==' '||ch=='.')
		{
		cust.name[i++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		cust.name[i]='\0';
		if(ch==8&&i>0)
		{
		gotoxy(45+i-1,12);
		printf(" ");
		gotoxy(45+i-1,12);
		i--;
		}
		if(!i||(i&&ch!=13&&ch!=8))
		sherr("INVALID NAME!TRY AGAIN");
			else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
		/*Read Customer address 1*/
	flag=0;i=0;
	outtextxy(120,215,"CUSTOMER ADDRESS '1':-");
		fflush(stdin);
		gotoxy(45,14);
	do
		{
		 ch=getch();
		ch=toupper(ch);
		printf("%c",ch);
		if(ch==27)
		 goto end;
		if(ch==8&&i>0)
		{
		gotoxy(45+i-1,14);
		printf(" ");
		gotoxy(45+i-1,14);
		i--;
		}
		if((ch>=65&&ch<=90)||(ch>=48&&ch<=56)||ch=='/'||ch=='.'||ch=='-'||ch==' ')
		cust.add1[i++]=ch;
		else
		{
		if(ch==13)
		cust.add1[i]='\0';
		if((i&&ch!=13&&ch!=8))

			sherr("INVALID ADDRESS!TRY AGAIN");
		  else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	/*Read customer Adedress 2*/
	flag=0;i=0;
	outtextxy(120,245,"CUSTOMER ADDRESS '2':-");
	gotoxy(45,16);
	do
		{
		 ch=getch();
		ch=toupper(ch);
		printf("%c",ch);
		if(ch==27)
		 goto end;
		 if(ch==8&&i>0)
		{
		gotoxy(45+i-1,16);
		printf(" ");
		gotoxy(45+i-1,16);
		i--;
		}
		if((ch>=65&&ch<=90)||ch==' '||(ch>=48&&ch<=57)||ch=='/'||ch=='.')
		cust.add2[i++]=ch;
		else
		{
		if(ch==13)
		cust.add2[i]='\0';
		if((i&&ch!=13&&ch!=8))
			sherr("INVALID ADDRESS!TRY AGAIN");
		     else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
       flag=0;i=0;
	outtextxy(120,275,"CUSTOMER CITY:-");
	gotoxy(45,18);
		fflush(stdin);
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		if((ch>=65&&ch<=90)||ch==' '||ch=='.')
		{
		cust.city[i++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		cust.city[i]='\0';
		if(ch==8&&i>0)
		{
		gotoxy(45+i-1,18);
		printf(" ");
		gotoxy(45+i-1,18);
		i--;
		}
		if(!i||(i&&ch!=13&&ch!=8))
		       sherr("INVALID CITY!TRY AGAIN");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;i=0;
	outtextxy(120,305,"CUSTOMER TELEPHONE NUMBER:-");
		fflush(stdin);
		gotoxy(45,20);
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		if((ch>=48&&ch<=57))
		{
		cust.tel_no[i++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		cust.tel_no[i]='\0';
		if(ch==8&&i>0)
		{
		gotoxy(45+i-1,20);
		printf(" ");
		gotoxy(45+i-1,20);
		i--;
		}
		if((i&&ch!=13&&ch!=8))
			sherr("INVALID TEL NO!TRY AGAIN");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	/*Save Record in File*/
	flag=0;
	outtextxy(120,335,"DO YOU WANT TO SAVE DATA 'Y/N':-");
	do
		{
		fflush(stdin);
		gotoxy(50,22);
		ch=getch();
		ch=toupper(ch);
		gotoxy(50,22);
		printf("%c",ch);
		gotoxy(50,22);
		if(ch!='Y' && ch!='N')
			{
			outtextxy(200,430,"ENTER(Y/N)");
			getch();
			setfillstyle(SOLID_FILL,BLACK);
			bar(190,400,420,440);
			}
		else
			flag=1;
		}while(flag==0);
	if(ch=='Y')
		{
		fwrite(&cust,sizeof(cust),1,fp);
		}
		else
		goto end;
		gotoxy(20,25);
		printf("                                  ");
		while(!kbhit())
		{
		gotoxy(20,25);
		printf("Record Save");
		delay(200);
		gotoxy(20,25);
		printf("           ");
		delay(200);
		}
		getch();
	}
      end:
fclose(fp);
}
void search_cust()
{
FILE *fp;
char cust_num1[7],ch='y';
int x1,y1,i;
clearviewport();
i=0;
fp=fopen("CUST.TXT","rb");
if(fp==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
while(ch=='y' || ch=='Y')
	{
	 wmsg(200,"SEARCH SCREEN");
	 drsc();
	rectangle(80,90,600,350);
	gotoxy(55,7);
	printf("Date : %s",datebuf);
	setcolor(CYAN);
	outtextxy(120,115,"CUSTOMER ID NUMBER");
	flag=0;
	gotoxy(40,8);
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		if(!i)
		 {
		  cust_num1[i++]=ch;
		  printf("%c",ch);
		  }
		  else
		if((ch>=48&&ch<=57))
		{
		cust_num1[i++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		cust_num1[i]='\0';
		if(ch==8&&i>0)
		{
		gotoxy(40+i-1,8);
		printf(" ");
		gotoxy(40+i-1,8);
		i--;
		}
		if((i&&ch!=13&&ch!=8))
			sherr("INVALID ID NO! TRY AGAIN");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	while(fread(&cust,sizeof(cust),1,fp)==1)
		{
		if(strcmpi(cust.cust_no,cust_num1)==0)
		{
		shrec();
		break;
		}
		}
	if(flag==0)
		outtextxy(180,200,"RECORD NOT FOUND");
	outtextxy(130,300,"SEARCH ANOTHER RECORD 'Y/N'");
	flag=0;
	do
		{
		fflush(stdin);
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y' && ch!='N')
		sherr("ENTER(Y/N)");
			else
			{
			flag=1;
			clearviewport();
			}
		}while(flag==0);
	if(ch=='Y')
	     {
		rewind(fp);
		i=0;
		}
		else
		goto end;
	}
	end:
fclose(fp);
}



void list_cust()
{
FILE *fp;
int p,i,r,tp,cp,pr;
fp=fopen("CUST.TXT","rb");
if(fp==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
    i=1;    p=0;cp=1;
while(fread(&cust,sizeof(cust),1,fp)==1)
p++;
fseek(fp,SEEK_SET,0);
tp=p/20;
if(p%20!=0)
tp++; pr=0;
sta:r=5;
setcolor(10);
settextstyle(7,0,1);
setusercharsize(1,1,1,2);
outtextxy(100,1,"INDIAN GAS AGENCY");
outtextxy(150,15,"LIST OF CUSTOMERS");
gotoxy(60,1);
printf("Date : %s",datebuf);
setcolor(CYAN);
settextstyle(0,0,1);
line(8,35,640,35);
line(8,55,640,55);
outtextxy(10,40,"S.No.");
outtextxy(60,40,"NUMBER");
outtextxy(150,40,"NAME");
outtextxy(400,40,"CITY");
outtextxy(530,40,"TELEPHONE NO.");
setcolor(WHITE);
if(pr)
	{
	gotoxy(4,r);
	printf("%2d",i);
	gotoxy(8,r);
	printf("%s",cust.cust_no);
	gotoxy(16,r);
	printf("%s",cust.name);
	gotoxy(50,r);
	printf("%s",cust.city);
	gotoxy(70,r);
	printf("%s",cust.tel_no);
	r+=1;   i++;
	pr=0;
	}
while(fread(&cust,sizeof(cust),1,fp)==1)
	{
	delay(200);
	if(r!=25)
	{
	gotoxy(4,r);
	printf("%2d",i);
	gotoxy(8,r);
	printf("%s",cust.cust_no);
	gotoxy(16,r);
	printf("%s",cust.name);
	gotoxy(50,r);
	printf("%s",cust.city);
	gotoxy(70,r);
	printf("%s",cust.tel_no);
	r+=1;   i++;
	}
	else
	{
	setcolor(CYAN);
	line(8,400,640,400);
	printf("\n\n\n\n\t\t\t\t\t\t\t\t");
	printf("Page %d of %d",cp++,tp);
	setcolor(10);
	outtextxy(80,435,"PRESS ANY KEY TO NEXT PAGE...");
	getch();
	clearviewport();
	pr=1;
	goto sta;
	}
	}
	setcolor(CYAN);
	line(8,400,640,400);
       gotoxy(60,24);
	printf("\n\n\n\n\t\t\t\t\t\t\t\tPage %d of %d",cp++,tp);
	setcolor(10);
outtextxy(80,435,"PRESS ANY KEY TO CLOSE SCREEN ...");
getch();
fclose(fp);
}
void del_cust()
{
FILE *fp1,*fp2;
char cust_num1[7],ch='y';
int i=0;

fp1=fopen("CUST.TXT","rb+");
if(fp1==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
while(ch=='y' || ch=='Y')
	{
	flag=0;
	wmsg(180,"DELETE SCREEN");
       drsc();
	rectangle(80,90,600,330);
	gotoxy(55,7);
	printf("Date : %s",datebuf);
	setcolor(CYAN);
	outtextxy(200,115,"CUSTOMER ID");
	gotoxy(40,8);
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		 if(!i)
		 {
		  cust_num1[i++]=ch;
		  printf("%c",ch);
		  }
		  else
		if((ch>=48&&ch<=57))
		{
		cust_num1[i++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		cust_num1[i]='\0';
		if(ch==8&&i>0)
		{
		gotoxy(40+i-1,8);
		printf(" ");
		gotoxy(40+i-1,8);
		i--;
		}
		if((i&&ch!=13&&ch!=8))
		sherr("INVALID ID NO! TRY AGAIN");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	while(fread(&cust,sizeof(cust),1,fp1)==1)
		{
		if(strcmpi(cust.cust_no,cust_num1)==0)
		       {
			shrec();
			break;
			}
		}
	if(flag==0)
		      outtextxy(180,250,"RECORD NOT FOUND");
		 else
	{
	outtextxy(180,300,"Are You Sure To Delete ?");
	ch=getch();
	ch=toupper(ch);
	if(ch=='Y')
	{
	setfillstyle(SOLID_FILL,BLACK);
	   bar(180,290,400,310);
	   setcolor(CYAN);
	   rewind(fp1);
	fp2=fopen("TEMP.TXT","wb");
	while(fread(&cust,sizeof(cust),1,fp1)==1)
		if(strcmpi(cust.cust_no,cust_num1)!=0)
			fwrite(&cust,sizeof(cust),1,fp2);
			outtextxy(180,250,"RECORD DELETED");
		fclose(fp1);
	fclose(fp2);
	remove("CUST.TXT");
	rename("TEMP.TXT","CUST.TXT");
	}
	}
		setfillstyle(SOLID_FILL,BLACK);
		bar(180,290,400,310);
	outtextxy(180,300,"DELETE ANOTHER RECORD 'Y/N'");
	flag=0;
	do
		{
		gotoxy(55,19);
		fflush(stdin);
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y'&& ch!='N')
		sherr("ENTER(Y/N)");
		else
			{
			flag=1;
			clearviewport();
			}
		}while(flag==0);
	if(ch=='Y')
		{
		fp1=fopen("CUST.TXT","rb+");
		i=0;
		}
	}
	end:
fclose(fp1);
}
void read_inc()
{
FILE * fp1,*fp2;
char cust_num1[6],cust_num2[6],cust_num3[6],str[6];
char ch,choice='Y';
int x1,y1,flag,i,n,k,e;
struct date d;
fp1=fopen("IN_CUST.TXT","rb+");
fp2=fopen("CUST.TXT","rb+");
if(fp1==NULL)
	{
	fp1=fopen("IN_CUST.TXT","wb+");
	if(fp1==NULL)
		{
		printf("CANNOT OPEN FILE");
		return;
		}
	}
while(choice== 'Y')
	{
	fseek(fp1,0,SEEK_END);
	fseek(fp2,0,SEEK_END);
	e=0;
	wmsg(60,"INCOMING CUSTOMER SCREEN");
	drsc();
	rectangle(40,75,600,400);
     gotoxy(60,2);
	printf("Date : %s",datebuf);
      setcolor(CYAN);
	settextstyle(0,0,1);
	flag=0;
	outtextxy(120,85,"TRANSFER VOUCHER NUMBER:-");
	gotoxy(45,6);
		do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		 if(e==6&&ch!=13)
		 sherr("MAX 6 CHARACTER");
		    if(e<=5||(e==6&&ch==13))
		if((ch>=65&&ch<=92)||(ch>=48&&ch<=57))
		{
		in_c.tv_num[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.tv_num[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,6);
		printf(" ");
		gotoxy(45+e-1,6);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		sherr("INVALID VOUCHER NUMBER");
		      else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	outtextxy(120,115,"TRANSFEER VOUCHER DATE:-");
	flag=0;
	e=0;
	gotoxy(45,8);
	printf("  /  /");
	gotoxy(45,8);
		do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==11&&ch!=13)
		  sherr("MAX 10 CHARACTER");
		 if(e<=10)
		if((ch>=48&&ch<=57))
		{
		in_c.tv_date[e++]=ch;
		printf("%c",ch);
		if(e==2||e==5)
		{
		printf("/");
		in_c.tv_date[e++]='/';
		} }
		else
		{
		if(ch==13)
		in_c.tv_date[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,8);
		printf(" ");
		gotoxy(45+e-1,8);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		       sherr("INVALID VOUCHER DATE");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,150,"LOCAL TRANSFER Y/N");
	e=0;
	do
		{
		fflush(stdin);
		gotoxy(45,10);
		in_c.l_tran=getch();
		if(in_c.l_tran==27)
		goto end;
		in_c.l_tran=toupper(in_c.l_tran);
		printf("%c",in_c.l_tran);
		if(in_c.l_tran!='Y' && in_c.l_tran!='N')
		sherr("ENTER(Y/N)");
			else
			flag=1;
		}while(flag==0);
	flag=0;
	outtextxy(120,180,"CUSTOMER NAME");
	gotoxy(45,12);
	e=0;
		do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		{
		  textbackground(BLACK);
		  textcolor(WHITE);
		  clearviewport();
		 goto end;
		 }
		 if(e==31&&ch!=13)
		 sherr("MAX 30 CHARACTER");
		       if(e<=30)
		if((ch>=65&&ch<=90)||ch==' '||ch=='.')
		{
		in_c.cust_name[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.cust_name[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,12);
		printf(" ");
		gotoxy(45+e-1,12);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		sherr("INVALID CUSTOMER NAME");
		 else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,210,"CUSTOMER ADDRESS '1'");
	gotoxy(45,14);
	e=0;
		do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		 if(e==31&&ch!=13)
		 sherr("MAX 30 CHARACTER");
		     if(e<=30)
		if((ch>=65&&ch<=90)||(ch>=48&&ch<=57)||ch==' '||ch=='.'||ch=='/')
		{
		in_c.cust_add1[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.cust_add1[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,14);
		printf(" ");
		gotoxy(45+e-1,14);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID CUSTOMER ADD1");
			else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,243,"CUSTOMER ADDRESS '2'");
	gotoxy(45,16);
	e=0;
		do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		goto end;
		 if(e==31&&ch!=13)
		 sherr("MAX 30 CHARACTER");
		if(e<=30)
		if((ch>=65&&ch<=90)||(ch>=48&&ch<=57)||ch==' '||ch=='.'||ch=='/')
		{
		in_c.cust_add2[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.cust_add2[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,16);
		printf(" ");
		gotoxy(45+e-1,16);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID CUSTOMER ADDRESS 2");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,280,"CUSTOMER CITY");
	gotoxy(45,18);
	e=0;
		do
		{ fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==31&&ch!=13)
		  sherr("MAX 30 CHARACTER");
		      if(e<=31)
		if((ch>=65&&ch<=90)||ch==' ')
		{
		in_c.cust_city[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.cust_city[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,18);
		printf(" ");
		gotoxy(45+e-1,18);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		sherr("INVALID CITY");
			else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,310,"CUSTOMER TELEPHONE NUMBER");
       gotoxy(45,20);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		 if(e==11&&ch!=13)
		 sherr("MAX 11 CHARACTER");
			else
			if(e<=11)
		if((ch>=48&&ch<=57))
		{
		in_c.cust_tel_no[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.cust_tel_no[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,20);
		printf(" ");
		gotoxy(45+e-1,20);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID TELEPHONE NOMBER");
			else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	clearviewport();
	wmsg(60,"INCOMING CUSTOMER SCREEN");
	drsc();
	rectangle(40,75,600,400);
	gotoxy(60,2);
	printf("Date : %s",datebuf);
	settextstyle(0,0,1);
	setcolor(CYAN);
	flag=0;
	outtextxy(120,85,"PREVIOUS AGENCY CODE");
	gotoxy(45,6);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
	 goto end;
		  if(e==11&&ch!=13)
		  sherr("MAX 10 CHARACTER");
		if(e<=11)
		if((ch>=65&&ch<=92)||(ch>=48&&ch<=57))
		{
		in_c.pga_code[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.pga_code[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,6);
		printf(" ");
		gotoxy(45+e-1,6);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY CODE");
			else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,100,"PREVIOUS AGENCY NAME");
		gotoxy(45,7);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==31&&ch!=13)
		  sherr("MAX 30 CHARACTER");
		       if(e<=31)
		if((ch>=65&&ch<=92)||ch==' '||ch=='.')
		{
		in_c.pga_name[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.pga_name[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,7);
		printf(" ");
		gotoxy(45+e-1,7);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY NAME");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,135,"PREVIOUS AGENCY ADDRESS '1'");
		gotoxy(45,9);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==31&&ch!=13)
		  sherr("MAX 10 CHARACTER");
			if(e<=31)
		if((ch>=65&&ch<=92)||(ch>=48&&ch<=57)||ch==' '||ch=='.'||ch=='/')
		{
		in_c.pga_add1[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.pga_add1[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,9);
		printf(" ");
		gotoxy(45+e-1,9);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY ADDRESS 1");
			else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,165,"PREVIOUS AGENCY ADDRESS '2'");
		gotoxy(45,11);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		 if(e==31&&ch!=13)
		 sherr("MAX 30 CHARACTER");
		if(e<=31)
		if((ch>=65&&ch<=92)||(ch>=48&&ch<=57)||ch==' '||ch=='.'||ch=='/')
		{
		in_c.pga_add2[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.pga_add2[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,11);
		printf(" ");
		gotoxy(45+e-1,11);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID ADDRESS 2");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,195,"PREVIOUS AGENCY CITY");
		gotoxy(45,13);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
	 goto end;
			 if(e==31&&ch!=13)
			 sherr("MAX 30 CHARACTER");
		    if(e<=31)
		if((ch>=65&&ch<=92)||ch==' ')
		{
		in_c.pga_city[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.pga_city[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,13);
		printf(" ");
		gotoxy(45+e-1,13);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY CITY");
			else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,230,"PREVIOUS AGENCY STATE");
		gotoxy(45,15);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
	 goto end;
		  if(e==31&&ch!=13)
		  sherr("MAX 30 CHARACTER");
			if(e<=31)
		if((ch>=65&&ch<=92)||ch==' ')
		{
		in_c.pga_stat[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.pga_stat[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,15);
		printf(" ");
		gotoxy(45+e-1,15);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY STATE");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	outtextxy(120,260,"PREVIOUS AGENCY TELEPHONE");
		gotoxy(45,17);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==11&&ch!=13)
		  sherr("MAX 10 CHARACTER");
		else
		   if(e<=11)
		if(ch>=48&&ch<=57)
		{
		in_c.pga_phon[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		in_c.pga_phon[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,17);
		printf(" ");
		gotoxy(45+e-1,17);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID TELEPHONE NUMBER");
			else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	fp2=fopen("CUST.TXT","rb+");
	if(fp2==NULL)
		{
		fp2=fopen("CUST.TXT","wb+");
		strcpy(cust_num1,"C0000");
		if(fp2==NULL)
			{
			printf("CANNOT OPEN FILE");
			getch();
			return;
			}
		}
	else
		{
		fseek(fp2,0,SEEK_SET);
		fread(&cust,sizeof(cust),1,fp2);
		strcpy(cust_num1,cust.cust_no);
		}
	i=1;
	k=0;
	while(cust_num1[i]!='\0')
		cust_num3[k++]=cust_num1[i++];
	cust_num3[k]='\0';
	while(fread(&cust,sizeof(cust),1,fp2)==1)
		{
		strcpy(cust_num2,cust.cust_no);
		i=1;
		k=0;
		while(cust_num2[i]!='\0')
			cust_num2[k++]=cust_num2[i++];
		cust_num2[k]='\0';
		if((atoi(cust_num2)) >= (atoi(cust_num3)))
			strcpy(cust_num1,cust.cust_no);
		}
	i=1;
	k=0;
	while(cust_num1[i]!='\0')
		cust_num2[k++]=cust_num1[i++];
	cust_num2[k]='\0';
	n=atoi(cust_num2);
	n=n+1;
	if(n<10)
		{
		strcpy(cust_num1,"C000");
		strcat(cust_num1,itoa(n,cust_num2,10));
		}
	else
		if(n>=10 && n<100)
			{
			strcpy(cust_num1,"C00");
			strcat(cust_num1,itoa(n,cust_num2,10));
			}
		else
			if(n>=100 && n<1000)
				{
				strcpy(cust_num1,"C0");
				strcat(cust_num1,itoa(n,cust_num2,10));
				}
			else
				if(n>=1000)
					{
					strcpy(cust_num1,"C");
					strcat(cust_num1,itoa(n,cust_num2,10));
					}
	strcpy(cust.cust_no,cust_num1);
	outtextxy(120,285,"CUSTOMER NUMBER");
	setcolor(WHITE);
	gotoxy(45,19);
	printf("%s",cust_num1);
	strcpy(cust.cust_no,cust_num1);
	strcpy(in_c.cust_no,cust_num1);
	strcpy(cust.name,in_c.cust_name);
	strcpy(cust.add1,in_c.cust_add1);
	strcpy(cust.add2,in_c.cust_add2);
	strcpy(cust.city,in_c.cust_city);
	strcpy(cust.tel_no,in_c.cust_tel_no);
	setcolor(CYAN);
	outtextxy(120,320,"DATE OF ASSIGNING NUMBER");
	getdate(&d);
	if(d.da_day<10)
		{
		strcpy(in_c.date_cust,"0");
		itoa(d.da_day,str,10);
		strcat(in_c.date_cust,str);
		}
	else
		{
		itoa(d.da_day,str,10);
		strcpy(in_c.date_cust,str);
		}
		strcat(in_c.date_cust,"/");
	if(d.da_mon<10)
		{
		strcat(in_c.date_cust,"0");
		itoa(d.da_mon,str,10);
		strcat(in_c.date_cust,str);
		}
	else
		{
		itoa(d.da_mon,str,10);
		strcat(in_c.date_cust,str);
		}
		strcat(in_c.date_cust,"/");
	itoa(d.da_year,str,10);
	strcat(in_c.date_cust,str);
	gotoxy(45,21);
	printf("%s",in_c.date_cust);
	flag=0;
	outtextxy(120,355,"DO YOU WANT TO SAVE DATA 'Y/N':-");
	do
		{
		fflush(stdin);
		gotoxy(52,23);
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y' && ch!='N')
		sherr("ENTER (Y/N)");
			else
			flag=1;
		}while(flag==0);
	clearviewport();
	if(ch=='Y')
		{
		fwrite(&in_c,sizeof(in_c),1,fp1);
		fwrite(&cust,sizeof(cust),1,fp2);
		wmsg(60,"INCOMING CUSTOMER SCREEN");
		outtextxy(100,95,"SAVE DATA IS:-");
	drsc();
	rectangle(40,75,600,400);
	settextstyle(0,0,1);
		gotoxy(60,2);
		printf("Date : %s",datebuf);
		gotoxy(15,8);
		printf("TRANSFER VOUCHER NUMBER");
		gotoxy(45,8);
		printf(":-  %s",in_c.tv_num);
		gotoxy(15,9);
		printf("TRANSFEER VOUCHER DATE");
		gotoxy(45,9);
		printf(":-  %s",in_c.tv_date);
		gotoxy(15,10);
		printf("LOCAL TRANSFER");
		gotoxy(45,10);
		printf(":-  %c",in_c.l_tran);
		gotoxy(15,11);
		printf("CUSTOMER NUMBER");
		gotoxy(45,11);
		printf(":-  %s",in_c.cust_no);
		gotoxy(15,12);
		printf("CUSTOMER NAME");
		gotoxy(45,12);
		printf(":-  %s",in_c.cust_name);
		gotoxy(15,13);
		printf("CUSTOMER ADDRESS1");
		gotoxy(45,13);
		printf(":-  %s",in_c.cust_add1);
		gotoxy(15,14);
		printf("CUSTOMER ADDRESS '2'");
		gotoxy(45,14);
		printf(":-  %s",in_c.cust_add2);
		gotoxy(15,15);
		printf("CUSTOMER CITY");
		gotoxy(45,15);
		printf(":-  %s",in_c.cust_city);
		gotoxy(15,16);
		printf("CUSTOMER TELEPHONE NUMBER");
		gotoxy(45,16);
		printf(":-  %s",in_c.cust_tel_no);
		gotoxy(15,17);
		printf("PREVIOUS AGENCY CODE");
		gotoxy(45,17);
		printf(":-  %s",in_c.pga_code);
		gotoxy(15,18);
		printf("PREVIOUS AGENCY ADDRESS '1'");
		gotoxy(45,18);
		printf(":-  %s",in_c.pga_add1);
		gotoxy(15,19);
		printf("PREVIOUS AGENCY ADDRESS '2'");
		gotoxy(45,19);
		printf(":-  %s",in_c.pga_add2);
		gotoxy(15,20);
		printf("PREVIOUS AGENCY CITY");
		gotoxy(45,20);
		printf(":-  %s",in_c.pga_city);
		gotoxy(15,21);
		printf("PREVIOUS AGENCY STATE");
		gotoxy(45,21);
		printf(":-  %s",in_c.pga_stat);
		gotoxy(15,22);
		printf("PREVIOUS AGENCY TELEPHONE");
		gotoxy(45,22);
		printf(":-  %s",in_c.pga_phon);
		gotoxy(15,23);
		printf("ASSIGN CUSTOMER NUMBER");
		gotoxy(45,23);
		printf(":-  %s",in_c.cust_no);
		gotoxy(15,24);
		printf("DATE OF ASSIGNING NUMBER");
		gotoxy(45,24);
		printf("%s",in_c.date_cust);
		setcolor(CYAN);
		flag=0;
	outtextxy(100,390,"DO YOU WANT MORE 'Y/N':-");
	do
		{
		gotoxy(45,25);
		fflush(stdin);
		choice=getch();
		choice=toupper(choice);
		if(choice!='Y' && choice!='N')
		sherr("ENTER Y/N");
		    else
			{
			flag=1;
			clearviewport();
			}
		}while(flag==0);
	if(choice=='Y')
		rewind(fp2);
	}  }
	end:
fclose(fp1);
fclose(fp2);
}

void list_inc()
{
FILE *fp;
int y1,i,p,cp,tp,pr,r;
fp=fopen("IN_CUST.TXT","rb");
if(fp==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
fseek(fp,0,SEEK_SET);
  i=1;    p=1;cp=1;
while(fread(&in_c,sizeof(in_c),1,fp)==1)
p++;
fseek(fp,0,SEEK_SET);
tp=p/10;
if(p%10!=0)
tp++; pr=0;
sta:r=6;
setcolor(10);
settextstyle(7,0,1);
setusercharsize(1,1,1,2);
outtextxy(100,1,"INDIAN GAS AGENCY");
outtextxy(150,15,"LIST OF INCOMING CUSTOMERS");
gotoxy(60,1);
printf("Date : %s",datebuf);
setcolor(CYAN);
settextstyle(0,0,1);
line(8,35,640,35);
line(8,70,640,70);
outtextxy(10,40,"S.No.");
outtextxy(80,40,"ID");
outtextxy(140,40,"VOUCHER NO.");
outtextxy(250,40,"VOUCHER DATE");
outtextxy(400,40,"AGENCY NAME");
outtextxy(140,55,"NAME");
outtextxy(400,55,"AGENCY CITY");
outtextxy(530,55,"TELEPHONE NO.");
setcolor(WHITE);
if(pr)
	  {
	gotoxy(4,r);
	printf("%2d",i);
	gotoxy(8,r);
	printf("%s",in_c.cust_no);
	gotoxy(16,r);
	printf("%s",in_c.tv_num);
	gotoxy(33,r);
	printf("%s",in_c.tv_date);
	gotoxy(16,r+1);
	printf("%s",in_c.cust_name);
	gotoxy(50,r+1);
	printf("%s",in_c.cust_city);
	gotoxy(70,r+1);
	printf("%s",in_c.cust_tel_no);
	r+=2;
	i++;
	pr=0;
	}
 while(fread(&in_c,sizeof(in_c),1,fp)==1)
	{
	delay(250);
	if(r!=26)
	{
	gotoxy(4,r);
	printf("%2d",i);
	gotoxy(8,r);
	printf("%s",in_c.cust_no);
	gotoxy(16,r);
	printf("%s",in_c.tv_num);
	gotoxy(33,r);
	printf("%s",in_c.tv_date);
	gotoxy(50,r);
	printf("%s",in_c.pga_name);
	gotoxy(16,r+1);
	printf("%s",in_c.cust_name);
	gotoxy(50,r+1);
	printf("%s",in_c.pga_city);
	gotoxy(70,r+1);
	printf("%s",in_c.cust_tel_no);
	r+=2;   i++;
	}
	else
	{
	setcolor(CYAN);
	line(8,400,640,400);
	printf("\n\n\n\t\t\t\t\t\t\t\t");
	printf("Page %d of %d",cp++,tp);
	setcolor(10);
	outtextxy(80,435,"PRESS ANY KEY TO NEXT PAGE...");
	getch();
	clearviewport();
	pr=1;
	goto sta;
	}
	}
	setcolor(CYAN);
	line(8,400,640,400);
       gotoxy(60,24);
	printf("\n\n\n\n\t\t\t\t\t\t\t\tPage %d of %d",cp++,tp);
	setcolor(10);
outtextxy(80,435,"PRESS ANY KEY TO CLOSE SCREEN ...");
getch();
fclose(fp);
}



void search_inc()
{
FILE *fp;
char cust_num1[7],ch='y';
int flag=0,x1,y1,i;

fp=fopen("IN_CUST.TXT","rb");
if(fp==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
	flag=0;
	while(ch=='y' || ch=='Y')
	{
	wmsg(200,"SEARCH SCREEN");
	drsc();
	rectangle(80,90,600,400);
	gotoxy(60,2);
	printf("Date : %s",datebuf);
	setcolor(CYAN);
	settextstyle(0,0,1);
	outtextxy(120,115,"CUSTOMER ID NUMBER");
	flag=0;
	gotoxy(40,8);     i=0;
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(!i)
		 {
		  cust_num1[i++]=ch;
		  printf("%c",ch);
		  }
		  else
		if((ch>=48&&ch<=57))
		{
		cust_num1[i++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		cust_num1[i]='\0';
		if(ch==8&&i>0)
		{
		gotoxy(40+i-1,8);
		printf(" ");
		gotoxy(40+i-1,8);
		i--;
		}
		if((i&&ch!=13&&ch!=8))
		sherr("INVALID ID NO");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	while(fread(&in_c,sizeof(in_c),1,fp)==1)
		{
		if(strcmpi(in_c.cust_no,cust_num1)==0)
		       {
		       increc();
			break;
			}
		}
	if(flag==0)
		outtextxy(180,200,"RECORD NOT FOUND");
	outtextxy(130,407,"SEARCH ANOTHER RECORD 'Y/N'");
	flag=0;
	do
		{
		fflush(stdin);
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y' && ch!='N')
		sherr("ENTER(Y/N)");
		else
			{
			flag=1;
			clearviewport();
			}
		}while(flag==0);
	if(ch=='Y')
	     {
		rewind(fp);
		i=0;
		}
	}
	end:
fclose(fp);
}

void del_inc()
{
FILE *fp1,*fp2,*fp3,*fp4;
char cust_num1[7],ch='y';
int i;

fp1=fopen("IN_CUST.TXT","rb");
if(fp1==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
fp2=fopen("CUST.TXT","rb");
if(fp1==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
      flag=0;
	while(ch=='y' || ch=='Y')
	{
	wmsg(200,"DELETE SCREEN");
	drsc();
	rectangle(80,90,600,400);
	gotoxy(60,2);
	printf("Date : %s",datebuf);
	setcolor(CYAN);
	settextstyle(0,0,1);
	outtextxy(120,115,"CUSTOMER ID NUMBER");
	flag=0;
	gotoxy(40,8);     i=0;
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(!i)
		 {
		  cust_num1[i++]=ch;
		  printf("%c",ch);
		  }
		  else
		if((ch>=48&&ch<=57))
		{
		cust_num1[i++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		cust_num1[i]='\0';
		if(ch==8&&i>0)
		{
		gotoxy(40+i-1,8);
		printf(" ");
		gotoxy(40+i-1,8);
		i--;
		}
		if((i&&ch!=13&&ch!=8))
		sherr("INVALID ID NO");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
	fp3=fopen("TEMP.TXT","wb");
	//flag=0;
		while(fread(&in_c,sizeof(in_c),1,fp1)==1)
		{
		    if(strcmpi(in_c.cust_no,cust_num1)!=0)
			fwrite(&in_c,sizeof(in_c),1,fp3);
			else
				{
			increc();
			outtextxy(130,407,"Are you sure to Delete ? (Y/N)");
			ch=getch();
			if((toupper(ch))=='Y')
			{
			flag=2;
			setfillstyle(SOLID_FILL,BLACK);
			bar(125,405,455,415);
			continue;
			}
			else
			{
			setfillstyle(SOLID_FILL,BLACK);
			bar(125,405,455,415);
			break;
			}
			}
		}

	if(flag==2)
	{
	fclose(fp1);
		fclose(fp3);
		remove("IN_CUST.TXT");
	rename("TEMP.TXT","IN_CUST.TXT");
	fp4=fopen("TEMP1.TXT","wb");
		while(fread(&cust,sizeof(cust),1,fp2)==1)
			if(strcmpi(cust.cust_no,cust_num1)!=0)
				fwrite(&cust,sizeof(cust),1,fp4);
			fclose(fp2);
	fclose(fp4);
	remove("CUST.TXT");
	rename("TEMP1.TXT","CUST.TXT");
	}
	if(flag==0)
		outtextxy(180,200,"RECORD NOT FOUND");
	outtextxy(130,407,"DELETE ANOTHER RECORD 'Y/N'");
	flag=0;
	do
		{
		fflush(stdin);
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y' && ch!='N')
		sherr("ENTER(Y/N)");
		else
			{
			flag=1;
			clearviewport();
			}
		}while(flag==0);
	if(ch=='Y')
	     {
		fp1=fopen("IN_CUST.TXT","rb");
if(fp1==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
fp2=fopen("CUST.TXT","rb");
if(fp1==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
		i=0;
		}
	}
	end:
fclose(fp1);
fclose(fp2);
fclose(fp3);
}

void read_ouc()
{
FILE *fp1,*fp2,*fp3;
char ch,choice='y',cust_num1[7],tv_num1[7],tv_num2[7],tv_num3[7],str[7];
int flag,flag4,i,k,n,e;
struct date d;
st:while(choice=='y' || choice== 'Y')
	{
	clearviewport();
	wmsg(100,"OUTGOING CUSTOMER MENU");
	drsc();
	rectangle(40,75,620,400);
	gotoxy(60,2);
	printf("Date : %s",datebuf);
	setcolor(CYAN);
	settextstyle(0,0,1);
	outtextxy(120,80,"TRANSFER VOUCHER NUMBER:-");
	setcolor(CYAN);
	fp1=fopen("OU_CUST.TXT","rb+");
	if(fp1==NULL)
		{
		fp1=fopen("OU_CUST.TXT","wb+");
		strcpy(tv_num1,"T0000");
		if(fp1==NULL)
			{
			printf("CANNOT OPEN FILE");
			getch();
			return;
			}
		}
	else
		{
		fseek(fp1,0,SEEK_SET);
		fread(&ou_c,sizeof(ou_c),1,fp1);
		strcpy(tv_num1,ou_c.tv_num);
		}
	i=1;k=0;
	while(tv_num1[i]!='\0')
		tv_num3[k++]=tv_num1[i++];
	tv_num3[k]='\0';
	while(fread(&ou_c,sizeof(ou_c),1,fp1)==1)
		{
		strcpy(tv_num2,ou_c.tv_num);
		i=1;k=0;
		while(tv_num2[i]!='\0')
			tv_num2[k++]=tv_num2[i++];
		tv_num2[k]='\0';
		if((atoi(tv_num2)) >= (atoi(tv_num3)))
			strcpy(tv_num1,ou_c.tv_num);
		}
	i=1;
	k=0;
	while(tv_num1[i]!='\0')
		tv_num2[k++]=tv_num1[i++];
	tv_num2[k]='\0';
	n=atoi(tv_num2);
	n=n+1;
	if(n<10)
		{
		strcpy(tv_num1,"T000");
		strcat(tv_num1,itoa(n,tv_num2,10));
		}
	else
		if(n>=10 && n<100)
			{
			strcpy(tv_num1,"T00");
			strcat(tv_num1,itoa(n,tv_num2,10));
			}
		else
			if(n>=100 && n<1000)
				{
				strcpy(tv_num1,"T0");
				strcat(tv_num1,itoa(n,tv_num2,10));
				}
			else
				if(n>=1000)
					{
					strcpy(tv_num1,"T");
					strcat(tv_num1,itoa(n,tv_num2,10));
					}
	strcpy(ou_c.tv_num,tv_num1);
	gotoxy(45,6);
	printf("%s",ou_c.tv_num);
	setcolor(CYAN);
	outtextxy(120,95,"TRANSFEER VOUCHER DATE:-");
	getdate(&d);
	if(d.da_day<10)
		{
		strcpy(ou_c.tv_date,"0");
		itoa(d.da_day,str,10);
		strcat(ou_c.tv_date,str);
			}
	else
		{
		itoa(d.da_day,str,10);
		strcpy(ou_c.tv_date,str);
			}
		 strcat(ou_c.tv_date,"/");
	if(d.da_mon<10)
		{
		strcat(ou_c.tv_date,"0");
		itoa(d.da_mon,str,10);
		strcat(ou_c.tv_date,str);
		}
	else
		{
		itoa(d.da_mon,str,10);
		strcat(ou_c.tv_date,str);
		}
		strcat(ou_c.tv_date,"/");
	itoa(d.da_year,str,10);
	strcat(ou_c.tv_date,str);
	gotoxy(45,7);
	printf("%s",ou_c.tv_date);
	setcolor(CYAN);
	flag=0;
	outtextxy(120,110,"LOCAL TRANSFER Y/N");
	e=0;
	do
		{
		fflush(stdin);
		gotoxy(45,8);
		ou_c.l_tran=getch();
		if(ou_c.l_tran==27)
		goto end;
		ou_c.l_tran=toupper(ou_c.l_tran);
		printf("%c",ou_c.l_tran);
		if(ou_c.l_tran!='Y' && ou_c.l_tran!='N')
		sherr("ENTER(Y/N)");
			else
			flag=1;
		}while(flag==0);
	flag=0;
	outtextxy(120,135,"CUSTOMER NO.");
	gotoxy(45,9);
	i=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		  goto end;
		 if(!i)
		 {
		  cust_num1[i++]=ch;
		  printf("%c",ch);
		  }
		  else
		if((ch>=48&&ch<=57))
		{
		cust_num1[i++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		cust_num1[i]='\0';
		if(ch==8&&i>0)
		{
		gotoxy(45+i-1,9);
		printf(" ");
		gotoxy(45+i-1,9);
		i--;
		}
		if((i&&ch!=13&&ch!=8))
		sherr("INVALID ID NO! TRY AGAIN");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	strcpy(ou_c.cust_no,cust_num1);
	fp2=fopen("CUST.TXT","rb");
	if(fp2==NULL)
		{
		outtextxy(100,300,"CANNOT OPEN CUSTOMER FILE");
		getch();
		return;
		}
	fseek(fp2,0,SEEK_SET);
	flag4=0;
	while(fread(&cust,sizeof(cust),1,fp2)==1)
		{
		if(strcmpi(cust.cust_no,cust_num1)==0)
		{
		outtextxy(120,150,"CUSTOMER NAME");
		gotoxy(45,10);
		printf("%s",cust.name);
		strcpy(ou_c.cust_name,cust.name);
		outtextxy(120,165,"CUSTOMER ADDRESS '1'");
		gotoxy(45,11);
		printf("%s",cust.add1);
		strcpy(ou_c.cust_add1,cust.add1);
		outtextxy(120,180,"CUSTOMER ADDRESS '2'");
		gotoxy(45,12);
		printf("%s",cust.add2);
		strcpy(ou_c.cust_add2,cust.add2);
		outtextxy(120,195,"CUSTOMER CITY");
		gotoxy(45,13);
		printf("%s",cust.city);
		strcpy(ou_c.cust_city,cust.city);
		outtextxy(120,210,"CUSTOMER TELEPHONE NUMBER");
		gotoxy(45,14);
		printf("%s",cust.tel_no);
		strcpy(ou_c.cust_tel_no,cust.tel_no);
		flag=0;
		outtextxy(120,225,"NEW AGENCY CODE");
		gotoxy(45,15);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		 if(e==11&&ch!=13)
		 sherr("MAX 10 CHARACTER");
		    if(e<=11)
		if((ch>=65&&ch<=92)||(ch>=48&&ch<=57))
		{
		ou_c.n_g_a_code[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		ou_c.n_g_a_code[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,15);
		printf(" ");
		gotoxy(45+e-1,15);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY CODE!");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
		flag=0;
		outtextxy(120,240,"NEW AGENCY NAME");
			gotoxy(45,16);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		goto end;
		 if(e==31&&ch!=13)
		 sherr("MAX 30 CHARACTER");
		if(e<=31)
		if((ch>=65&&ch<=92)||ch==' '||ch=='.')
		{
		ou_c.n_g_a_name[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		ou_c.n_g_a_name[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,16);
		printf(" ");
		gotoxy(45+e-1,16);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY NAME!TRY AGAIN");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	flag=0;
		outtextxy(120,260,"NEW AGENCY ADDRESS '1'");
			gotoxy(45,17);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		 if(e==31&&ch!=13)
		 sherr("MAX 10 CHARACTER");
		if(e<=31)
		if((ch>=65&&ch<=92)||(ch>=48&&ch<=57)||ch==' '||ch=='.'||ch=='/')
		{
		ou_c.n_g_a_add1[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		ou_c.n_g_a_add1[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,17);
		printf(" ");
		gotoxy(45+e-1,17);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY ADDRESS 1!");
			else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
		flag=0;
		outtextxy(120,275,"NEW AGENCY ADDRESS '2'");
		gotoxy(45,18);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==31&&ch!=13)
		  sherr("MAX 30 CHARACTER");
		      if(e<=31)
		if((ch>=65&&ch<=92)||(ch>=48&&ch<=57)||ch==' '||ch=='.'||ch=='/')
		{
		ou_c.n_g_a_add2[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		ou_c.n_g_a_add2[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,18);
		printf(" ");
		gotoxy(45+e-1,18);
		e--;
		}
		if((e&&ch!=13&&ch!=8))
		sherr("INVALID ADDRESS 2!");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
		flag=0;
		outtextxy(120,290,"NEW AGENCY CITY");
		gotoxy(45,19);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  if(e==31&&ch!=13)
		  sherr("MAX 30 CHARACTER");
		   if(e<=31)
		if((ch>=65&&ch<=92)||ch==' ')
		{
		ou_c.n_g_a_city[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		ou_c.n_g_a_city[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,19);
		printf(" ");
		gotoxy(45+e-1,19);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY CITY!TRY AGAIN");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
		flag=0;
		outtextxy(120,305,"NEW AGENCY STATE");
		gotoxy(45,20);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		goto end;
		  if(e==31&&ch!=13)
		  sherr("MAX 30 CHARACTER");
		     if(e<=31)
		if((ch>=65&&ch<=92)||ch==' ')
		{
		ou_c.n_g_a_stat[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		ou_c.n_g_a_stat[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,20);
		printf(" ");
		gotoxy(45+e-1,20);
		e--;
		}
		if(!e||(e&&ch!=13&&ch!=8))
		sherr("INVALID AGENCY STATE!");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
		flag=0;
		outtextxy(120,320,"NEW AGENCY TELEPHONE");
		gotoxy(45,21);
       e=0;
	do
		{
		fflush(stdin);
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
			 if(e==11&&ch!=13)
			 sherr("MAX 10 CHARACTER");
		    if(e<=11)
		if(ch>=48&&ch<=57)
		{
		ou_c.n_g_a_phon[e++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		ou_c.n_g_a_phon[e]='\0';
		if(ch==8&&e>0)
		{
		gotoxy(45+e-1,21);
		printf(" ");
		gotoxy(45+e-1,21);
		e--;
		}
			if((!e&&(ch>=65&&ch<=92))||(e&&ch!=13&&ch!=8))
			flag=0;
				else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
		flag4=1;
		break;
		}
	}
if(flag4==0)
	{
	 sherr("CUSTOMER NOT FOUND");
	strcpy(ou_c.tv_num,"T0000");
	fclose(fp2);
	fclose(fp1);
	goto st;
	}

if(flag4==1)
	{
	outtextxy(120,407,"DO YOU WANT TO SAVE DATA 'Y/N':-");
	flag=0;
	do
		{
		fflush(stdin);
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y'&&ch!='N')
		sherr("ENTER (Y/N)");
		else
			flag=1;
		}while(flag==0);

	if(ch=='y' || ch=='Y')
		{
		clearviewport();
		fwrite(&ou_c,sizeof(ou_c),1,fp1);
		fclose(fp1);
		fp3=fopen("TEMP.TXT","wb");
		rewind(fp2);
		while(fread(&cust,sizeof(cust),1,fp2)==1)
			if(strcmpi(cust.cust_no,cust_num1)!=0)
				fwrite(&cust,sizeof(cust),1,fp3);
		fclose(fp2);
		fclose(fp3);
		remove("CUST.TXT");
		rename("TEMP.TXT","CUST.TXT");
		wmsg(100,"OUTGOING CUSTOMER MENU");
		settextstyle(0,0,1);
		setcolor(CYAN);
		outtextxy(100,120,"SAVE DATA IS:-");
		outtextxy(130,407,"DO YOU WANT MORE 'Y/N':-");
		drsc();
		rectangle(40,75,620,400);
		gotoxy(60,2);
		printf("Date : %s",datebuf);
		otcrec();
		}
      flag=0;
do
	{
	gotoxy(46,23);
	fflush(stdin);
	choice=getch();
	choice=toupper(choice);
	if(choice!='Y'&& choice!='N')
	sherr("ENTER Y/N!");
	else
		{
		flag=1;
		clearviewport();
		}
	}while(flag==0);
	}       }
	end:
fclose(fp1);
fclose(fp2);
}

void list_ouc()
{
FILE *fp;
int y1;

fp=fopen("OU_CUST.TXT","rb");
if(fp==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
fseek(fp,0,SEEK_SET);
sta:
y1=110;
setcolor(10);
settextstyle(7,0,1);
setusercharsize(1,1,1,2);
outtextxy(150,20,"INDIAN GAS AGENCY");
outtextxy(60,40,"LIST OF OUTGOING CUSTOMERS");
gotoxy(60,2);
printf("Date : %s",datebuf);
setcolor(CYAN);
settextstyle(0,0,1);
line(2,65,630,65);
line(2,95,630,95);
outtextxy(4,70,"TV_NUM");
outtextxy(60,70,"TV_DATE");
outtextxy(140,70,"NUMBER");
outtextxy(240,70,"NAME");
outtextxy(435,70,"CITY");
outtextxy(540,70,"TELEPHONE NO.");
while(fread(&ou_c,sizeof(ou_c),1,fp)==1)
	{
	if(y1!=400)
		{
		outtextxy(2,y1,ou_c.tv_num);
		outtextxy(55,y1,ou_c.tv_date);
		outtextxy(145,y1,ou_c.cust_no);
		outtextxy(200,y1,ou_c.cust_name);
		outtextxy(420,y1,ou_c.cust_city);
		outtextxy(540,y1,ou_c.cust_tel_no);
		y1+=20;
		}
	else
		{
		setcolor(10);
		outtextxy(80,410,"PRESS ANY KEY TO CONTINUE ...");
		getch();
		clearviewport();
		goto sta;
		}
	}
outtextxy(80,410,"PRESS ANY KEY TO RETURN");
getch();
fclose(fp);
}

void search_ouc()
{
FILE *fp;
char cust_num1[7],ch='y';
int x1,y1,i;

fp=fopen("OU_CUST.TXT","rb");
if(fp==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
while(ch=='y' || ch=='Y')
	{
       wmsg(150,"SEARCH SCREEN");
       drsc();
       rectangle(80,90,600,400);
	setcolor(CYAN);
	settextstyle(0,0,1);
	outtextxy(120,115,"CUSTOMER ID NUMBER");
	gotoxy(60,2);
printf("Date : %s",datebuf);
	flag=0;
	gotoxy(40,8);
	  i=0;
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		goto end;
		 else
		 if(ch==13)
	       {
		cust_num1[i]='\0';
		flag=1;
		}
		else
		if(ch==8&&i>0)
		{
		gotoxy(40+i-1,8);
		printf(" ");
		gotoxy(40+i-1,8);
		i--;
		}
		else
		 if(!i)
		 {
		  cust_num1[i++]=ch;
		  printf("%c",ch);
		  }
		  else
		if((ch>=48&&ch<=57))
		{
		cust_num1[i++]=ch;
		printf("%c",ch);
		}
		}while(flag==0);
	       flag=0;
		while(fread(&ou_c,sizeof(ou_c),1,fp)==1)
		{
		if(strcmpi(ou_c.cust_no,cust_num1)==0)
			{
			wmsg(150,"SEARCH SCREEN");
			drsc();
			rectangle(80,90,600,400);
			gotoxy(60,2);
			printf("Date : %s",datebuf);
			otcrec();
			break;
			}
		}
		setcolor(CYAN);
	if(flag==0)
		outtextxy(180,200,"RECORD NOT FOUND");
	flag=0;
	outtextxy(120,407,"SEARCH ANOTHER RECORD 'Y/N'");
	do
		{
		gotoxy(49,23);
		fflush(stdin);
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y'&& ch!='N')
		sherr("ENTER (Y/N)!");
			else
			{
			flag=1;
			clearviewport();
			}
		} while(flag==0);
	if(ch=='Y')
		rewind(fp);
	}
	end:
fclose(fp);
}

void del_ouc()
{
FILE *fp1,*fp2;
char cust_num1[7],ch='y';
int x1,y1,i;

fp1=fopen("OU_CUST.TXT","rb");
if(fp1==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
while(ch=='y' || ch=='Y')
	{
	wmsg(190,"DELETE SCREEN");
	drsc();
	rectangle(80,90,600,400);
	setcolor(CYAN);
	settextstyle(0,0,1);
	outtextxy(120,115,"CUSTOMER ID NUMBER");
	gotoxy(60,2);
	printf("Date : %s",datebuf);
	flag=0;
	gotoxy(40,8);
	  i=0;
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		 else
		 if(ch==13)
	       {
		cust_num1[i]='\0';
		flag=1;
		}
		else
		if(ch==8&&i>0)
		{
		gotoxy(40+i-1,8);
		printf(" ");
		gotoxy(40+i-1,8);
		i--;
		}
		else
		 if(!i)
		 {
		  cust_num1[i++]=ch;
		  printf("%c",ch);
		  }
		  else
		if((ch>=48&&ch<=57))
		{
		cust_num1[i++]=ch;
		printf("%c",ch);
		}
		}while(flag==0);
	       flag=0;
	fp2=fopen("TEMP.TXT","wb");
	fseek(fp1,0,SEEK_SET);
	while(fread(&ou_c,sizeof(ou_c),1,fp1)==1)
		{
		if(strcmpi(ou_c.cust_no,cust_num1)!=0)
			fwrite(&ou_c,sizeof(ou_c),1,fp2);
		else
			{
			otcrec();
			outtextxy(130,407,"Are you sure to Delete ? (Y/N)");
			ch=getch();
			if((toupper(ch))=='Y')
			{
			flag=2;
			setfillstyle(SOLID_FILL,BLACK);
			bar(125,405,455,415);
			continue;
			}
			else
			{
			setfillstyle(SOLID_FILL,BLACK);
			bar(125,405,455,415);
			break;
			}
			}
		}

	if(flag==2)
	{
	fclose(fp1);
		remove("OU_CUST.TXT");
		fclose(fp2);
	rename("TEMP.TXT","OU_CUST.TXT");
	}
	if(flag==0)
		outtextxy(180,200,"RECORD NOT FOUND");
	outtextxy(130,407,"DELETE ANOTHER RECORD 'Y/N'");
	flag=0;
	do
		{
		fflush(stdin);
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y' && ch!='N')
		sherr("ENTER(Y/N)");
		else
			{
			flag=1;
			clearviewport();
			}
		}while(flag==0);
	if(ch=='Y')
	     {
		fp1=fopen("OU_CUST.TXT","rb");
if(fp1==NULL)
	{
	printf("CANNOT OPEN FILE");
	getch();
	return;
	}
	i=0;
		}
	}
	end:
fclose(fp1);
fclose(fp2);
}

void gprint(int *x1,int *y1,char *list,...)
{
va_list ptr;
char str[100];
va_start(ptr,list);
vsprintf(str,list,ptr);
outtextxy(*x1,*y1,str);
*y1=*y1+20;
va_end(ptr);
}
void book_cust()
{
char ch,choice='y';
int bnum=0,n,i,j,x1,y1,k,d1,m1,y2,date=20;
char str[7],cust_num1[7],l_date[9],arr[5];
FILE *fp1,*fp2,*fp3;
struct date d;
int flag,flag1=0;

fp1=fopen("REF.TXT","rb+");
fp2=fopen("CUST.TXT","rb+");
if(fp2==NULL)
	{
	outtextxy(50,50,"CUSTOMER FILE NOT OPEN");
	getch();
	return;
	}

while(choice=='y' || choice=='Y')
	{
	clearviewport();
	wmsg(120,"REFILL BOOKING SCREEN");
	drsc();
	rectangle(40,80,590,370);
	setcolor(3);
	setfillstyle(SOLID_FILL,CYAN);
	settextstyle(0,0,1);
	flag=0;
	outtextxy(165,115,"CUSTOMER NUMBER");
	gotoxy(60,2);
	printf("Date : %s",datebuf);
	gotoxy(40,8);
	  i=0;
	do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		  else
		 if(ch==13)
	       {
		cust_num1[i]='\0';
		flag=1;
		}
		else
		if(ch==8&&i>0)
		{
		gotoxy(40+i-1,8);
		printf(" ");
		gotoxy(40+i-1,8);
		i--;
		}
		else
		 if(!i)
		 {
		  cust_num1[i++]=ch;
		  printf("%c",ch);
		  }
		  else
		if((ch>=48&&ch<=57))
		{
		cust_num1[i++]=ch;
		printf("%c",ch);
		}
		}while(flag==0);
	flag=0;
	rewind(fp2);
	while(fread(&cust,sizeof(cust),1,fp2)==1)
		if(strcmpi(cust.cust_no,cust_num1)==0)
			{
			flag=1;
			break;
			}
	if(flag==0)
		{
		outtextxy(180,400,"CUSTOMER NOT FOUND");
		getch();
		setfillstyle(SOLID_FILL,BLACK);
		bar(170,390,600,500);
		}
	else
		{
		strcpy(l_date,"NULL");
		flag1=0;
		if(fp1!=NULL)
			{
			fseek(fp1,0,SEEK_SET);
			while(fread(&ref,sizeof(ref),1,fp1)==1)
				{
				if(strcmpi(ref.cust_num,cust_num1)==0)
					if(strcmpi(ref.vouc_date,"NULL")==0)
						{
						sherr("CYLINDER BOOKED ALREADY");
						flag1=1;
						break;
						}
					else
						strcpy(l_date,ref.vouc_date);
				if(ref.book_num>bnum)
					bnum=ref.book_num;
				}
			}
		else
			fp1=fopen("REF.TXT","wb+");
		if(flag1==0)
			{
			k=0;
			bnum=bnum+1;
			if(strcmpi(l_date,"NULL")!=0)
				{
				for(i=0;l_date[i]!='\0';i++)
					{
					if(i<2)
						{
						arr[k++]=l_date[i];
						if(i==1)
							{
							arr[k]='\0';
							d1=atoi(arr);
							k=0;
							}
						}
					else
						if(i<4)
							{
							arr[k++]=l_date[i];
							if(i==3)
								{
								arr[k]='\0';
								m1=atoi(arr);
								k=0;
								}
							}
						else
							arr[k++]=l_date[i];
					}
				arr[k]='\0';
				y2=atoi(arr);
				getdate(&d);
				j=d.da_mon-m1;
				if(j>=2)
					date=21;
				else
					if(d.da_mon>m1 && d.da_year==y2)
						{
						if(d.da_mon==1||d.da_mon==3||d.da_mon==5||d.da_mon==7||d.da_mon==8||d.da_mon==10||d.da_mon==12)
							date=31-(d1+d.da_day);
						else
							if(d.da_mon==4||d.da_mon==6||d.da_mon==9||d.da_mon==11)
								date=30-(d1+d.da_day);
							else
								if(d.da_mon==2&&d.da_year%4==0)
									date=29-(d1+d.da_day);
								else
									date=28-(d1+d.da_day);
						}
					else
						{
						if(d.da_year>y2)
							{
							if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)
								date=d.da_day-d1;
							else
								if(m1==4||m1==6||m1==9||m1==11)
									date=d.da_day-d1;
								else
									if(m1==2 && y1%4==0)
										date=d.da_day-d1;
									else
										date=d.da_day-d1;
							m1++;
							for(i=m1;i>=d.da_mon;i++)
								{
								if(i==d.da_mon)
									{
									date+=d.da_day;
									break;
									}
								else
									{
									if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)
										date+=31;
									else
										if(m1==4||m1==6||m1==9||m1==11)
											date+=30;
										else
											if(m1==2 && y1%4==0)
												date+=29;
											else
												date+=28;
									}
								}
							}
						else
							{
							if(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)
								date=d.da_day-d1;
							else
								if(m1==4||m1==6||m1==9||m1==11)
									date=d.da_day-d1;
								else
									if(m1==2 && y1%4==0)
										date=d.da_day-d1;
									else
										date=d.da_day-d1;
							}
						}
				}
			if(date<20)
				{
				sherr("CYLINDER BOOK AFTER 20 DAYS");
					}
			else
				{
				fp3=fopen("TEMP.TXT","wb");
				rewind(fp1);
				while(fread(&ref,sizeof(ref),1,fp1)==1)
					if(ref.book_num!=bnum)
						fwrite(&ref,sizeof(ref),1,fp3);
				flag=0;
				ref.book_num=bnum;
				strcpy(ref.cust_num,cust_num1);
				getdate(&d);
				if(d.da_day<10)
					{
					strcpy(ref.book_date,"0");
					itoa(d.da_day,str,10);
					strcat(ref.book_date,str);
					}
				else
					{
					itoa(d.da_day,str,10);
					strcpy(ref.book_date,str);
					}
					strcat(ref.book_date,"/");
				if(d.da_mon<10)
					{
					strcat(ref.book_date,"0");
					itoa(d.da_mon,str,10);
					strcat(ref.book_date,str);
					}
				else
					{
					itoa(d.da_mon,str,10);
					strcat(ref.book_date,str);
					}
				 strcat(ref.book_date,"/");
				itoa(d.da_year,str,10);
				strcat(ref.book_date,str);
				setcolor(3);
				flag=0;
				do
					{
					outtextxy(165,150,"URGENT");
					gotoxy(40,10);
					ref.urgent=getchar();
					ref.urgent=toupper(ref.urgent);
					if(ref.urgent!='Y' && ref.urgent!='N')
						{
						sherr("ENTER 'Y' OR 'N'");
						}
					else
						flag=1;
					}while(flag==0);
				if(ref.urgent=='Y'||ref.urgent=='y')
					ref.prior_num=1;
				else
					ref.prior_num=0;
				flag=	0;
				outtextxy(120,407,"DO YOU WANT TO SAVE BOOKING (Y/N)");
				do
					{
					fflush(stdin);
					ch=getch();
					ch=toupper(ch);
					if((ch!='Y' && ch!='N'))
					sherr("ENTER (Y/N)");
					    else
						flag=1;
					}while(flag==0);
				if(ch=='Y')
					{
					clearviewport();
					wmsg(120,"REFILL BOOKING SCREEN");
					drsc();
					rectangle(50,80,620,350);
					settextstyle(0,0,1);
					setcolor(CYAN);
					strcpy(ref.l_s_date,l_date);
					ref.status='\0';
					strcpy(ref.vouc_num,"0000");
					strcpy(ref.vouc_date,"NULL");
					strcpy(ref.hawk_num,"NULL");
					strcpy(ref.vehi_no,"NULL");
					ref.supp_mode=0;
					fwrite(&ref,sizeof(ref),1,fp3);
					fclose(fp1);
					fclose(fp3);
					remove("REF.TXT");
					rename("TEMP.TXT","REF.TXT");
					setcolor(10);
					outtextxy(100,100,"SAVE DATA IS:-");
					setcolor(3);
					x1=120;y1=120;
					gprint(&x1,&y1,"BOOKING NUMBER          %d",ref.book_num);
					outtextxy(120,140,"BOOKING DATE");
					outtextxy(300,140,ref.book_date);
					outtextxy(120,160,"CUSTOMER NUMBER");
					outtextxy(300,160,ref.cust_num);
					outtextxy(120,180,"LAST SUPPLIED DATE");
					if(strcmpi(ref.l_s_date,"NULL")!=0)
						outtextxy(300,180,ref.l_s_date);
					else
						outtextxy(300,180,"FIRST BOOKING");
					y1=200;
					gprint(&x1,&y1,"URGENT                %c",ref.urgent);
					gprint(&x1,&y1,"PRIORTY NUMBER        %d",ref.prior_num);
					fp1=fopen("REF.TXT","rb+");
				flag=0;
	outtextxy(120,407,"DO YOU WANT MORE BOOKING (Y/N)");
	do
		{
		gotoxy(50,18);
		fflush(stdin);
		choice=getch();
		choice=toupper(choice);
		if(choice!='Y'&& choice!='N')
			   sherr("ENTER (Y/N)");
			else
			{
			flag=1;
			clearviewport();
			}
		}while(flag==0);
	}
	else
	goto end;
	}
	}
	}
	}
	end:
fclose(fp1);
fclose(fp2);
}

void comp_cust()
{
FILE *fp1,*fp2,*fp3,*fp4,*fp5;
char cust_num1[15],choice='Y',ch,ch1;
int flag,flag1,flag2,i;

fp1=fopen("COMP.TXT","rb+");
if(fp1==NULL)
	{
	fp1=fopen("COMP.TXT","wb+");
	if(fp1==NULL)
	printf("FILE NOT OPEN");
	getch();
	return(0) ;
	}
fp2=fopen("CUST.TXT","rb");
if(fp2==NULL)
	{
	outtextxy(50,50,"CUSTOMER FILE NOT OPEN");
	getch();
	return;
	}
fp3=fopen("STOCK.TXT","rb+");
while(choice=='Y')
	{
	 wmsg(135,"COMPLAIN SCREEN");
	drsc();
	rectangle(40,80,620,385);
	setcolor(3);
	settextstyle(0,0,1);
	gotoxy(60,2);
	printf("Date : %s",datebuf);
	flag=0;
		outtextxy(100,100,"CUSTOMER NUMBER");
			flag=0;
			       gotoxy(40,7);     i=0;
				do
							{
							 ch=getch();
							ch=toupper(ch);
						if(ch==27)
						 goto end;
							 if(!i)
							 {
							 cust_num1[i++]=ch;
							  printf("%c",ch);
								  }
							  else
							if((ch>=48&&ch<=57))
							{
							cust_num1[i++]=ch;
							printf("%c",ch);
							}
							else
							{
							if(ch==13)
							cust_num1[i]='\0';
								if(ch==8&&i>0)
							{
							gotoxy(40+i-1,7);
							printf(" ");
							gotoxy(40+i-1,7);
								i--;
								}
							if((i&&ch!=13&&ch!=8))
							sherr("INVALID ID NO");
									else
								if(ch!=8)
									flag=1;
										}

									}while(flag==0);
				flag1=0;
		while(fread(&cust,sizeof(cust),1,fp2)==1)
		{
		if(strcmpi(cust.cust_no,cust_num1)==0)
			  {
				flag1=1;
				break;
				}
				}
		if(flag1==0)
	      {
		sherr("CUSTOMER NUMBER NOT FOUND");
		goto end;}

	outtextxy(100,130,"1 FOR COMPLAIN AND 2 FOR RECOVERY");

	do
		{
		fflush(stdin);
		gotoxy(58,9);
		ch1=getch();
		if(ch1==27)
		goto end;
		else
		if(ch1=='1' || ch1=='2')
			 {
			 flag=1;
			 printf("%c",ch1);
			 }
		else
		sherr("ENTER (Y/N)");
		}while(flag==0);
	flag=0;
	if(ch1=='1')
		{
		flag2=0;
		while(fread(&comp,sizeof(comp),1,fp1)==1)
		if(( strcmpi(comp.cust_num,cust_num1)==0) && comp.status=='N')
			{
			sherr("COMPLAIN ALREADY MADE");
			flag2=1;
			}
		strcpy(comp.cust_num,cust_num1);
		comp.status='N';
		comp.r_cyl='N';
		if(flag1==1)
			{
			if(flag2==0)
				{
				outtextxy(165,195,"DO YOU WANT TO SAVE DATA");
				gotoxy(50,13);
				do
					{
					fflush(stdin);
					ch=getch();
					ch=toupper(ch);
					if(ch!='Y'&& ch!='N')
					sherr("ENTER (Y/N)");
					else
					{
					printf("%c",ch);
						flag=1; }
					}while(flag==0);
				}
			if(ch=='Y')
				fwrite(&comp,sizeof(comp),1,fp1);
			}
		}
	if(ch1=='2')
		{
		fp4=fopen("TEMP.TXT","wb");
			while(fread(&comp,sizeof(comp),1,fp1)==1)
			{
			if(strcmpi(comp.cust_num,cust_num1)!=0)
				fwrite(&comp,sizeof(comp),1,fp4);
			else
				{
				fclose(fp1);
				fclose(fp4);
				remove("COMP.TXT");
				rename("TEMP.TXT","COMP.TXT");
				flag=0;
				outtextxy(65,200,"Y FOR RETURN OF REFILL OR N FOR NO");
				gotoxy(50,10);
				do
					{
					fflush(stdin);
				       printf("%c",(comp.r_cyl=getch()));
					comp.r_cyl=toupper(comp.r_cyl);
					if(comp.r_cyl!='Y'&&comp.r_cyl!='N')
					       sherr("ENTER (Y/N)");
					else
						flag=1;
					}while(flag==0);
				}
			if(comp.r_cyl=='Y')
				{
				fp3=fopen("STOCK.TXT","rb+");
				fp5=fopen("TEMP1.TXT","wb");
				fread(&stock,sizeof(stock),1,fp3);
				stock.no_fil_cyl-=1;
				stock.no_def_cyl+=1;
				fwrite(&stock,sizeof(stock),1,fp5);
				fclose(fp3);
				fclose(fp5);
				remove("STOCK.TXT");
				rename("TEMP1.TXT","STOCK.TXT");
				}
			}
			sherr("COMPLAIN NOT MADE");
		}
	outtextxy(165,407,"DO YOU WANT BOOKING OF MORE COMPLAIN");
	gotoxy(65,26);
	do
		{
		fflush(stdin);
		choice=getch();
		choice=toupper(choice);
		printf("%c",choice);
		if(choice!='Y'&& choice!='N')
		sherr("ENTER (Y/N)");
		else
			{
			flag=1;
			getch();
			clearviewport();
			}
		}while(flag==0);
	if(ch1=='2'&& choice=='Y')
		fp1=fopen("COMP.TXT","rb+");
	else
		{
		rewind(fp1);
		rewind(fp2);
		}
	}
	end:
fclose(fp1);
fclose(fp2);
}



void rel_cust()
{
char ch,choice='y';
int bknum1,book,n,x1,y1,i,k,prior;
char str[10],vouc_num1[6],vouc_num2[6],vouc_num3[6];
char book_date[8],cust_num[6],l_date[8],urgent,status ,book_num1[5],*rst;
FILE *fp1,*fp2,*fp3,*fp4;
struct date d;
int flag,flag1=0;

fp1=fopen("REF.TXT","rb+");
if(fp1==NULL)
	{
	outtextxy(50,50,"NO BOOKING MADE");
	getch();
	return;
	}
fp2=fopen("STOCK.TXT","rb+");
if(fp2==NULL)
	{
	printf("FIRST INSERT IN STOCK");
	getch();
	return;
	}

while(choice=='y' || choice=='Y')
	{
	wmsg(135,"DISPATCH SCREEN");
	drsc();
	rectangle(40,80,620,385);
	gotoxy(60,2);
	printf("Date : %s",datebuf);
	setcolor(3);
	setfillstyle(SOLID_FILL,CYAN);
	settextstyle(0,0,1);
	flag=0;
	outtextxy(165,110,"BOOKING NUMBER");
		gotoxy(40,8);
		fflush(stdin);
		i=0;
		do
		{
		 ch=getch();
		ch=toupper(ch);
		if(ch==27)
		 goto end;
		if((ch>=48&&ch<=57))
		{
		book_num1[i++]=ch;
		printf("%c",ch);
		}
		else
		{
		if(ch==13)
		book_num1[i]='\0';
		if(ch==8&&i>0)
		{
		gotoxy(40+i-1,8);
		printf(" ");
		gotoxy(40+i-1,8);
		i--;
		}
		if((i&&ch!=13&&ch!=8))
			sherr("INVALID BOOK NO!");
		else
			if(ch!=8)
			flag=1;
		}
		}while(flag==0);
	       bknum1=atoi(book_num1);
	flag=0;
	flag1=0;
	fseek(fp1,0,SEEK_SET);
	while(fread(&ref,sizeof(ref),1,fp1)==1)
		if(ref.book_num==bknum1)
			{
			flag1=1;
			if(strcmp(ref.vouc_num,"0000")!=0)
				{
				outtextxy(200,400,"CYLINDER ALREADY DISPATCH");
				getch();
				setfillstyle(SOLID_FILL,BLACK);
				bar(190,390,420,410);
				flag=1;
				}
			}
		if(flag1==0)
			{
			outtextxy(200,400,"BOOKING NOT FOUND");
			getch();
			setfillstyle(SOLID_FILL,BLACK);
			bar(190,390,420,410);
			}
		if(flag==0 && flag1!=0)
			{
			rewind(fp1);
			fread(&ref,sizeof(ref),1,fp1);
			strcpy(vouc_num1,ref.vouc_num);
			i=1;
			k=0;
			while(vouc_num1[i]!='\0')
				vouc_num3[k++]=vouc_num1[i++];
			vouc_num3[k]='\0';
			while(fread(&ref,sizeof(ref),1,fp1)==1)
				{
				strcpy(vouc_num2,ref.vouc_num);
				i=1;
				k=0;
				while(vouc_num2[i]!='\0')
					vouc_num2[k++]=vouc_num2[i++];
				vouc_num2[k]='\0';
				if((atoi(vouc_num2)) >= (atoi(vouc_num3)))
					strcpy(vouc_num1,ref.vouc_num);
				}
			i=1;
			k=0;
			while(vouc_num1[i]!='\0')
				vouc_num2[k++]=vouc_num1[i++];
			vouc_num2[k]='\0';
			n=atoi(vouc_num2);
			n=n+1;
			if(n<10)
				{
				strcpy(vouc_num1,"V000");
				strcat(vouc_num1,itoa(n,vouc_num2,10));
				}
			else
				if(n>=10 && n<100)
					{
					strcpy(vouc_num1,"V00");
					strcat(vouc_num1,itoa(n,vouc_num2,10));
					}
				else
					if(n>=100 && n<1000)
						{
						strcpy(vouc_num1,"V0");
						strcat(vouc_num1,itoa(n,vouc_num2,10));
						}
					else
						if(n>=1000)
							{
							strcpy(vouc_num1,"V");
							strcat(vouc_num1,itoa(n,vouc_num2,10));
							}
			fp3=fopen("TEMP.TXT","wb");
			rewind(fp1);
			while(fread(&ref,sizeof(ref),1,fp1)==1)
				if(ref.book_num!=bknum1)
					{
					fseek(fp3,0,SEEK_END);
					fwrite(&ref,sizeof(ref),1,fp3);
					}
				else
					{
					outtextxy(65,130,"BOOKING DATE:");
					outtextxy(300,130,ref.book_date);
					outtextxy(65,150,"CUSTOMER NUMBER:");
					outtextxy(300,150,ref.cust_num);
					outtextxy(65,170,"LAST SUPPLIED DATE:");
					if(strcmp(ref.l_s_date,"NULL")==0)
						outtextxy(300,170,"FIRST BOOKING");
					else
						outtextxy(300,170,ref.l_s_date);
					x1=65;
					y1=190;
					gprint(&x1,&y1,"URGENT :                     %c",ref.urgent);
					gprint(&x1,&y1,"PRIORTY NUMBER:              %d",ref.prior_num);
					outtextxy(65,230,"STATUS:");
					outtextxy(65,250,"VOUCHER NUMBER");
					outtextxy(65,270,"VOUCHER DATE:");
					strcpy(book_date,ref.book_date);
					strcpy(cust_num,ref.cust_num);
					strcpy(l_date,ref.l_s_date);
					urgent=ref.urgent;
					prior=ref.prior_num;
					fseek(fp2,0,SEEK_SET);
					fread(&stock,sizeof(stock),1,fp2);
					if(stock.no_fil_cyl==0)
					       {
						ref.status='N';
						rst="NOT AVALIBLE" ;
						}
					else
					       {
						ref.status='A';
						rst="AVALIBLE";
						}
					status=ref.status;
					x1=65;
					y1=230;
					gprint(&x1,&y1,"STATUS                       %s",rst);
					if(ref.status=='A')
						{
						outtextxy(300,250,vouc_num1);
						strcpy(ref.vouc_num,vouc_num1);
						getdate(&d);
							if(d.da_day<10)
								{
								strcpy(ref.vouc_date,"0");
								itoa(d.da_day,str,10);
								strcat(ref.vouc_date,str);
								}
							else
								{
								itoa(d.da_day,str,10);
								strcpy(ref.vouc_date,str);
								}
								strcat(ref.vouc_date,"/");
							if(d.da_mon<10)
								{
								strcat(ref.vouc_date,"0");
								itoa(d.da_mon,str,10);
								strcat(ref.vouc_date,str);
								}
							else
								{
								itoa(d.da_mon,str,10);
								strcat(ref.vouc_date,str);
								}
								strcat(ref.vouc_date,"/");
							itoa(d.da_year,str,10);
							strcat(ref.vouc_date,str);
							strcat(ref.vouc_date,'\0');
						      outtextxy(300,270,ref.vouc_date);
						flag=0;
						outtextxy(65,290,"HAWKER/DEV. VAN/CUST(1/2/3)");
						fflush(stdin);
						gotoxy(40,19);
						ch=getchar();
							if(ch=='1')
						     {
								flag=0;
							gotoxy(40,20);     i=0;
								ref.supp_mode=1;
								outtextxy(65,310,"HAWKER NUMBER");
							do
							{
							 ch=getch();
							ch=toupper(ch);
						if(ch==27)
						 goto end;
							 if(!i)
							 {
							 ref.hawk_num[i++]=ch;
							  printf("%c",ch);
								  }
							  else
							if((ch>=48&&ch<=57))
							{
							ref.hawk_num[i++]=ch;
							printf("%c",ch);
							}
							else
							{
							if(ch==13)
							ref.hawk_num[i]='\0';
								if(ch==8&&i>0)
							{
							gotoxy(50+i-1,20);
							printf(" ");
							gotoxy(50+i-1,20);
								i--;
								}
							if((i&&ch!=13&&ch!=8))
							sherr("INVALID ID NO");
									else
								if(ch!=8)
									flag=1;
										}
									}while(flag==0);
							}
							else
								if(ch=='2')
									{
									outtextxy(65,310,"DEV. VAN CODE");
									gotoxy(40,20);
									fflush(stdin);
									gets(ref.vehi_no);
									ref.supp_mode=2;
									}
								else
									if(ch!='1'|| ch!='2')
										{
										strcpy(ref.hawk_num,"NULL");
										strcpy(ref.vehi_no,"NULL");
										ref.supp_mode=3;
										}
						ref.book_num=bknum1;
						strcpy(ref.book_date,book_date);
						strcpy(ref.cust_num,cust_num);
						strcpy(ref.l_s_date,l_date);
						ref.urgent=urgent;
						ref.prior_num=prior;
						ref.status=status;
						fseek(fp3,0,SEEK_END);
						fwrite(&ref,sizeof(ref),1,fp3);
						fp4=fopen("TEMP1.TXT","wb");
						rewind(fp2);
						fread(&stock,sizeof(stock),1,fp2);
						stock.no_fil_cyl-=1;
						stock.no_emp_cyl+=1;
						fwrite(&stock,sizeof(stock),1,fp4);
						fclose(fp2);
						fclose(fp4);
						remove("STOCK.TXT");
						rename("TEMP1.TXT","STOCK.TXT");
						setcolor(CYAN);
						outtextxy(165,407,"VOUCHER RELASE");
						outtextxy(165,420,"PRESS ANY KEY TO CONTINUE...");
						getch();
						}
					else
						{
						sherr("CYLINDER OUT OF STOCK");
						fclose(fp2);
						}
					}
			fclose(fp1);
			fclose(fp3);
			remove("REF.TXT");
			rename("TEMP.TXT","REF.TXT");
			fp1=fopen("REF.TXT","rb+");
			}
		setcolor(CYAN);
		clearviewport();
			rewind(fp1);
	}
	end:
fclose(fp1);
}