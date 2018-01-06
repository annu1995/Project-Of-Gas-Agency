//Header files

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<time.h>
#include<string.h>
#include<stdarg.h>
#include<ctype.h>
#define ARROW_SIZE 5

//Function prototype


void draw_arrow(int x, int y);  //drawing arrow
void draw_bar(int a,int b);     //drawing bar
void read_cust();       //addition of new customer
void list_cust();       //dispaly list of customer
void search_cust() ;     //searching of  customer
void del_cust();       // deletion of any customer
void read_inc();       // addition of incoming customer
void list_inc();       // list of incoming customer
void search_inc();     //searching of incoming customer
void del_inc();     //deletion of any incoming customer
void read_ouc();       // addition of outgoing cust
void list_ouc();       // list of outgoing customer
void search_ouc();     //searching of outgoing customer
void del_ouc();    //deletion of any outgoing  customer
void cyl_stock ();    //report of stock
void cyl_book();     //report of booking
void cyl_rel();      //report of releasing
void cyl_haw();      //report release by hawker
void cyl_urg();      //report release urgently
void book_cust();    //booking of a refill
void comp_cust();    //addition of complain
void rel_cust();   // releasing of refill
void gprint(int *x1,int *y1,char *list,...);//printing of data other than string in graphical mode

// Structures

typedef struct{
	       char tel_no[10],cust_no[6],name[30];
	       char add1[30],add2[30];
	       char city[20];
	     }cust_data;
           cust_data cust; //for new customers
 
typedef struct
  {
    char tv_num[6],tv_date[10],pga_code[10],cust_no[6],
         date_cust[10];
   char l_tran,cust_name[20],cust_add1[30],
        cust_add2[30],cust_city[20];
   char pga_name[30],pga_add1[30],pga_add2[30]
        ,pga_city[20],pga_stat[30];
   char pga_phon[10],cust_tel_no[10];
  }in_cust;
  in_cust in_c;  // for incoming transfer customers
 

typedef struct
  {
   char tv_num[8],tv_date[10],n_g_a_code[10]
       ,cust_no[6];
   char l_tran,cust_name[20],cust_add1[30],
        cust_add2[30], cust_city[20];
   char n_g_a_name[30],n_g_a_add1[30],n_g_a_add2[30],
        n_g_a_city[20],n_g_a_stat[30];
   char n_g_a_phon[10],cust_tel_no[10];
  }ou_cust;
  ou_cust ou_c; // for outgoing transfer customers
  
typedef struct
    {
     int  book_num,prior_num,supp_mode;
     char book_date[9],l_s_date[9],vouc_date[9]
          ,vehi_no[8];
     char urgent,status,cust_num[6],vouc_num[6]
         ,hawk_num[5];
    }refill;
    refill ref; //for refill booking & releasing

typedef struct
    {
     int no_cyl,no_fil_cyl,no_emp_cyl,no_def_cyl;
     float unit_rate;
    }st_cyl;
    st_cyl static stock;//for stock
   
typedef struct
    {
     char cust_num[6],status,r_cyl;
    }comp_cyl;
    comp_cyl comp;//for complain

int count=1,col=1;


// Stating of main function

void main(void)
   {
     int gdriver = DETECT, gmode, errorcode;
     void *arrow,*bars;
     int c=20,d=1,x,y,i,k=0,j=100,l=420,a,b;
     unsigned int size,bsize;
   char  ch,login[]={"GAS"},login1[5],arr[]={"GOLDENGASAGENCY"},
         arr1[3],arr3[]={"HONESTY IS OUR TRADITION"};
    char datebuf[9];
    char timebuf[9];
    clrscr();
     //for taking password
      i=0;
      gotoxy(2,5);
      printf("ENTER PASSWORD:-");
    while(d<=3)
     {
      gotoxy(c+1,5);
      fflush(stdin);
      ch=getch();
      if(ch!=13)
      {
      printf("*");
      login1[i++]=ch;
      c+=1;
      }
     else
     {
     login1[i]='\0';
     if(strcmpi(login1,login)!=0)
     {
      if(d==3)
	  {
	  gotoxy(5,20);
	  printf("THREE    ATTEMPT    FAILS \n    SECURITY BREACH PRESUMED \n    SYSTEM    SHALL    EXIT");
	 delay(3000);
	 exit(0);
     }
       gotoxy(20,20);
       printf("INVALID PASSWORD");
       getch();
       gotoxy(20,5);
       clreol();
       gotoxy(20,20);
       clreol();
       d++;
       c=20;
       i=0;
      }
     else
       d=4;
    }
   }

clrscr();
textcolor(BLACK);
textbackground(WHITE);
gotoxy(25,8);
cprintf("PROJECT           GOLDEN GAS AGENCY");
gotoxy(25,10);
cprintf("COURSE            'A' LEVEL");
gotoxy(25,12);
cprintf("REGISTRATION NO   436580");
gotoxy(25,14);
textcolor(BLACK+BLINK);
cprintf("DEVELOPED BY      SIDDHARTH");
 delay(3000);
  /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
	
     //PRINTING TITLE WITH SOUND

      for(i=0;arr[i]!='\0';i++)
	  {
	    if(i==0)
	    delay(1000);
	    arr1[k++]=arr[i];
	    arr1[k]='\0';
	    sound(500);
	    setcolor(RED);
	      if(i<=5)
	       {
		settextstyle(10,0,1);
		setusercharsize(3, 1, 1, 1);
		outtextxy(j,50,arr1);
	       }
	    if(i>=6 && i<=8)
		{
		settextstyle(10,0,1);
		setusercharsize(3, 1, 1, 1);
		outtextxy(j,150,arr1);
		}
		if(i>=9)
		{
		settextstyle(10,0,1);
		setusercharsize(3, 1, 1, 1);
		outtextxy(j,250,arr1);
		}

	     delay(500);
	     nosound();
	     if(i==0 || i==3 || i==4)
	      j+=45;
	     else
	     j+=85;
	     k=0;
	     if(i==4)
	      j+=45;
	     if(i==5)
	       j=200;
	     if(i==8)
	     j=75;
	    }
	 k=0;
	 j=10;
	 for(i=0;arr3[i]!='\0';i++)
	  {
	    arr1[k++]=arr3[i];
	    arr1[k]='\0';
	    sound(500);
	    setcolor(10);
	    settextstyle(10,0,1);
	    outtextxy(j,l,arr1);
	     delay(500);
	     nosound();
	     j+=25;
	     k=0;
	     }
	setfillstyle(SOLID_FILL,RED);
	bar(290,7,620,30);
	setcolor(CYAN);
	settextstyle(0,0,1);
	outtextxy(300,10,"PRESS ANY KEY TO CONTINUE OR ESC TO EXIT");
       ch=getch();
	  if(ch==27)
	   exit(0);
    clearviewport();
    settextstyle(0,0,1);
   _strdate(datebuf);
   _strtime(timebuf);
top:x = 180;
   y = 115;
   a=220;
   b=108;
   count=1;
   clearviewport();
      draw_bar(a,b);
      draw_arrow(x, y);
      setfillstyle(SOLID_FILL,4);
      bar(500,10,570,35);
      setcolor(1);
      outtextxy(500,15,datebuf);
      outtextxy(500,25,timebuf);
      setcolor(10);
      line(200,62,480,62);
      settextstyle(7,0,1);
      setusercharsize(1,1,1,2);
      outtextxy(230,40,"MAIN  MENU");
      setcolor(3);
      rectangle(160,80,490,310);
      rectangle(155,75,495,315);
      setcolor(BROWN);
      rectangle(0,0,620,460);
      rectangle(3,3,617,457);
      setcolor(10);
      line(90,410,550,410);
      settextstyle(0,0,1);
      setcolor(10);
      outtextxy(150,420,"USE UP AND DOWN ARROW KEY TO SELECT OPTION");
      outtextxy(225,440,"THEN PRESS ENTER KEY");
       /* calculate the size of the image */
      size = imagesize(x, y-ARROW_SIZE, x+(4*ARROW_SIZE), 
                       y+ARROW_SIZE);
      bsize=imagesize(a,b,a+258,b+16);
   /* allocate memory to hold the image */
   arrow = malloc(size);
   bars=   malloc(bsize);
   getimage(x, y-ARROW_SIZE, x+(4*ARROW_SIZE), y+ARROW_SIZE, 
            arrow);
   getimage(a,b,a+258,b+16,bars);

//MAIN MENU WINDOW
    while(1)
     {
	 setcolor(CYAN);
	  outtextxy(230,110,"CUSTOMERS DETAILS");
	  outtextxy(230,130,"INCOMING TRANSFER OF A CUSTOMER");
	  outtextxy(230,150,"OUTGOING TRANSFER OF A CUSTOMER");
	  outtextxy(230,170,"BOOKING OF A REFILL");
	  outtextxy(230,190,"RELEASING REFILL VOUCHERS");
	  outtextxy(230,210,"COMPLAN FROM CUSTOMER");
	  outtextxy(230,230,"REPORTS");
	  outtextxy(230,250,"STOCK");
	  outtextxy(230,270,"EXIT");
	  setfillstyle(SOLID_FILL,CYAN);
	  bar(170,330,480,350);
	  setcolor(1);
	  switch(count)
	   {
 	    case 1:
	     outtextxy(170,340,"STATUS:-   ENTER NEW CUSTOMER");
	     break;
	    case 2:
	     outtextxy(170,340,"STATUS:-   ENTER NEW INCOMING  CUSTOMER");
	     break;
	    case 3:
	     outtextxy(170,340,"STATUS:-   ENTER NEW OUTGOING CUSTOMER");
	     break;
	    case 4:
	     outtextxy(170,340,"STATUS:-   ENTER NEW BOOKING OF REFILL");
	     break;
	    case 5:
	     outtextxy(170,340,"STATUS:-   ENTEER DELIVERY OF REFILL");
	     break;
         case 6:
	     outtextxy(170,340,"STATUS:-   ENTER CMPLAIN FROM CUSTOMER");
	     break;
	    case 7:
	     outtextxy(170,340,"STATUS:-   DAILY REPORT OF TRANSACTION");
	     break;
	    case 8:
	     outtextxy(170,340,"STATUS:-   DETAILS OF STORES STOCK");
	      break;
	    case 9:
	      outtextxy(170,340,"STATUS:-   EXIT FROM PROGRAM");
	    }



//LOOP FOR CLOCK
	while(!kbhit())
	  
       {
	 _strtime(timebuf);
	  setfillstyle(SOLID_FILL,4);
	  bar(500,25,570,35);
	  setcolor(1);
	  outtextxy(500,25,timebuf);
	  delay(100);
	 }

	
     fflush(stdin);
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
       putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
       putimage(a,b,bars,XOR_PUT);
	y +=20;
	b += 20;

       if (y > 280 )
	 {
	  y = 115;
	  b = 108;
	 }
       /* plot new image */
     putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
     putimage(a,b,bars,XOR_PUT);
     }
    if(ch==72)
     {
       count--;
	  if(count==0)
	   count=1;
        /* erase old image */ 
        putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
        putimage(a,b,bars,XOR_PUT);
        y -=20;
        b -=20;
       if (y < 115)
	  {
	   y =115;
	   b=108;
	  }
      /* plot new image */
       putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
       putimage(a,b,bars,XOR_PUT);
     }
    }
      else
	  if(count==9)
	   exit(0);
      else
       break;
 }
//SELECTION WINDOW
 
if(count==1 || count==2 || count==3 )
  {
   start:x=180;
       y=125;
       a=220;
       b=115;
       col=1;
	 clearviewport();
	 draw_arrow(x,y);
	 draw_bar(a,b);
	 setcolor(10);
	 settextstyle(7,0,2);
	 outtextxy(210,40,"SELECT THE OPTION");
	 setcolor(3);
	 settextstyle(0,0,1);
	 rectangle(160,80,490,310);
	 rectangle(155,75,495,315);
	 bar(330,400,640,420);
	  while(1)
	   {
	   setcolor(CYAN);
	   outtextxy(335,410,"USE ARROW & ENTER KEY TO MOVE &SELECT");
	  outtextxy(230,120,"ADD ANY CUSTOMER");
	  outtextxy(230,140,"SEARCH ANY CUSTOMER");
	  outtextxy(230,160,"LIST OF CUSTOMER");
	  outtextxy(230,180,"DELETE ANY CUSTOMER");
	  outtextxy(230,200,"EXIT");
		setfillstyle(SOLID_FILL,CYAN);
		bar(170,330,475,350);
		setcolor(1);
	switch(col)
	{
	case 1:
	  outtextxy(180,340,"STATUS:-   ADD ANY CUSTOMER");
	 break;
	case 2:
	  outtextxy(180,340,"STATUS:-   SEARCH ANY CUSTOMER");
	 break;
	case 3:
	  outtextxy(180,340,"STATUS:-   DISPLAY LIST OF CUSTOMER");
	 break;
	case 4:
	  outtextxy(180,340,"STATUS:-   DELETE ANY CUSTOMER");
	 break;
	case 5:
	  outtextxy(180,340,"STATUS:-   GO TO MAIN MENU");
	 break;
	}
	 ch=getch();
	if(ch==0)
	 {
	 ch=getch();
	 if(ch==80)
	 {
	  col++;
	 if(col==6)
	  col=1;
	 /* erase old image */
	putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
	putimage(a,b,bars,XOR_PUT);
	y += 20;
	b += 20;

       if (y > 212)
	  {
	   y = 125;
	   b = 115;
	  }
      /* plot new image */
	putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
	putimage(a,b,bars,XOR_PUT);
	}
     if(ch==72)
     {
       col--;
    	  if(col==0)
	   col=1;
       /* erase old image */   
       putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
       putimage(a,b,bars,XOR_PUT);
       y =b -= 20;
       if (y < 125)
	  {
	  y = 125;
	  b = 115;
	  }
      /* plot new image */
       putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
       putimage(a,b,bars,XOR_PUT);
     }
    }
      else
	{
	 clearviewport();
	 switch(count)
	  {
	  case 1:
	 if(col==1)
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
	 free(arrow);
	 goto top;
	 }
	 break;
	case 2:
	 if(col==1)
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
	 free(arrow);
	 goto top;
	 }
	break;
	case 3:
	 if(col==1)
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
	   free(arrow);
	   goto top;
	  }
	 }
       goto start;
     }
    }
  }
  

//CALLING BOOKING REFILL FUNCTION

  if(count==4)
     {
      book_cust();
      goto top;
     }

 // CALLING RELEASING REFILL FUNCTION 
   
    if(count==5)
     {
	 rel_cust();
	 goto top;
     }


// CALLING COMPLAIN FUNCTION

    if(count==6)
      {
	  comp_cust();
	  goto top;
      }


// FUNCTION FOR STOCK 
 
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
	  draw_arrow(x,y);
	  draw_bar(a,b);
	  setcolor(10);
	  settextstyle(7,0,2);
	  outtextxy(180,40,"WELCOME TO STOCK MENU");
	  setcolor(3);
	  settextstyle(0,0,1);
	  rectangle(160,80,490,310);
	  rectangle(155,75,495,315);
	  bar(330,400,640,420);
	   while(1)
	   {
	   setcolor(CYAN);
	   outtextxy(335,410,"USE ARROW & ENTER KEY TO MOVE & SELECT");
	   outtextxy(230,120,"NUMBER OF CYLINDER");
	   outtextxy(230,140,"NUMBER OF FILLED CYLINDER");
	   outtextxy(230,160,"UNIT RATE");
	   outtextxy(230,180,"RETURN TO MAIN MENU");
	   setfillstyle(SOLID_FILL,CYAN);
	   bar(170,330,475,350);
 	   setcolor(1);
        switch(col)
	    {
	   case 1:
	    outtextxy(180,340,"STATUS:-  AVILABLE CYLINDERS");
	    break;
	   case 2:
	    outtextxy(180,340,"STATUS:-  NO. OF FILLED CYLINDER");
	    break;
	   case 3:
	    outtextxy(180,340,"STATUS:-  RATE OF EACH CYLINDER");
	    break;
	  case  4:
	  outtextxy(180,340,"STATUS:-   GO TO MAIN MENU");
	   break;
	  }
	   ch=getch();
	  if(ch==0)
	    {
	    ch=getch();
	    if(ch==80)
	     {
	     col++;
	     if(col==5)
	     col=1;
	     /* erase old image */
	     putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
   	     putimage(a,b,bars,XOR_PUT);
	     y += 20;
	     b += 20;
          if (y > 192)
	     {
	      y = 125;
	      b = 115;
	     }
         /* plot new image */
	    putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
	    putimage(a,b,bars,XOR_PUT);
  	   }
        if(ch==72)
        {
        col--;
	    if(col==0)
	    col=1;
           /* erase old image */
	     putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
          putimage(a,b,bars,XOR_PUT);
          y =b -= 20;
         if (y < 125)
	     {
	       y = 125;
	       b = 115;
	     }
      /* plot new image */
       putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
       putimage(a,b,bars,XOR_PUT);
     }
  }
   else
    if(col==4)
      goto top;
    else
    break;
}
    clearviewport();
    flag=0;
    setfillstyle(SOLID_FILL,CYAN);
    rectangle(30,30,520,150);
    switch(col)
     {
      case 1:
      setcolor(CYAN);
      outtextxy(50,50,"ENTER TOATAL NO. OF  CYLINDER");
      do
       {
	gotoxy(43,4);
	setfillstyle(SOLID_FILL,CYAN);
	bar(300,45,500,65);
	scanf("%s",&no_cyl);
	if(strlen(no_cyl)>0)
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
     case 2:
	if(flag1==1)
	   fread(&stock,sizeof(stock),1,fp1);
	else
	  {
	   outtextxy(200,400,"FIRST INSERT TOTAL NO. OF CYLINDER!PRESSENTER");
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
	     if(strlen(no_fil_cyl)>0)
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
	    if(flag==1)
	    if(atoi(no_fil_cyl)+stock.no_fil_cyl > stock.no_cyl)
		{
		outtextxy(200,400,"NOT MORE THAN TOTAL NO. OF CYLINDER");
		x1=490,y1=400;
		gprint(&x1,&y1,"%d",stock.no_cyl);
		flag=0;
		getch();
		setfillstyle(SOLID_FILL,BLACK);
		bar(190,390,530,410);
		}
	    }while(flag==0);
        break;
     case 3:
       setcolor(CYAN);
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
	    if(col==1)
	     if(flag1==1)
	     stock.no_cyl+=atoi(no_cyl);
	    else
         stock.no_cyl=atoi(no_cyl);
	    if(col==2)
	    {
	    if(flag1==1)
	     stock.no_fil_cyl+=atoi(no_fil_cyl);
	    else
	    stock.no_fil_cyl=atoi(no_fil_cyl);
	    stock.no_emp_cyl=stock.no_cyl-     
         stock.no_fil_cyl+stock.no_def_cyl;
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
	  fclose(fp1);
       goto st;
      }

//FOR GENERATING REPORT
    

   if(count==7)
     {
 	 char ch;
      t:x=180;
       y=125;
       a=220;
       b=115;
       col=1;
	  clearviewport();
	  draw_arrow(x,y);
	  draw_bar(a,b);
	  setcolor(10);
	  settextstyle(7,0,2);
	  outtextxy(130,40,"WELCOME COME TO REPORT MENU");
	  setcolor(3);
	  settextstyle(0,0,1);
	  rectangle(160,80,490,310);
	  rectangle(155,75,495,315);
	  bar(330,400,640,420);
	  while(1)
	   {
	   setcolor(CYAN);
	   outtextxy(335,410,"USE ARROW & ENTER KEY TO MOVE & SELECT");
	  outtextxy(230,120,"DAY    WISE STOCK  REPORT");
	  outtextxy(230,140,"DAY    WISE REFILL BOOKING");
	  outtextxy(230,160,"DAY    WISE REFILL RELEASE");
	  outtextxy(230,180,"HAWKER WISE REFILL RELEASE");
	  outtextxy(230,200,"URGENT DELIVERY REPORT");
	  outtextxy(230,220,"RETURN  TO  MAIN   MENU");
	  setfillstyle(SOLID_FILL,CYAN);
	  bar(170,330,475,350);
	  setcolor(1);
	  switch(col)
	 {
	 case 1:
	   outtextxy(180,340,"STATUS:-  AVILABLE CYLINDERS");
	  break;
	 case 2:
	  outtextxy(180,340,"STATUS:-  BOOKINGS OF CYLINDERS");
	  break;
	case 3:
	  outtextxy(180,340,"STATUS:-  DELIVERY OF CYLINDER");
	  break;
	case 4:
	  outtextxy(180,340,"STATUS:-  SUPPLIED BY HAWKER");
	  break;
	case 5:
	  outtextxy(180,340,"STATUS:-  DELIVERY URGENTLY");
	  break;
	case 6:
	  outtextxy(180,340,"STATUS:-   GO TO MAIN MENU");
	  break;
	}
	 fflush(stdin);
	 ch=getch();
	if(ch==0)
	 {
	 ch=getch();
	 if(ch==80)
	 {
	  col++;
	 if(col==7)
	  col=1;
	 /* erase old image */
	putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
	putimage(a,b,bars,XOR_PUT);
	y += 20;
	b += 20;

       if (y > 232)
	  {
	  y = 125;
	  b = 115;
	 }
      /* plot new image */
	putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
	putimage(a,b,bars,XOR_PUT);
	}
     if(ch==72)
     {
       col--;
	if(col==0)
	 col=1;
       
       /* erase old image */
        putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
        putimage(a,b,bars,XOR_PUT);
       y =b -= 20;
       if (y < 125)
	  {
	  y = 125;
	  b = 115;
	  }
      /* plot new image */
       putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
       putimage(a,b,bars,XOR_PUT);
     }
    }
     else
     break;
     }
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
      case 6:goto top;
     }
     goto t;
   }
 }

 //FUNCTION FOR PRINTING UPTO DATE STOCK PRESENT  
  
  void cyl_stock ()
    {
     FILE *fp;
     int x1=65,y1=130;
     clearviewport();
	fp=fopen("STOCK.TXT","rb");
	if(fp==NULL)
	 {
	  outtextxy(50,50,"FILE NOT OPEN");
	  return;
	 }
	  setcolor(10);
       settextstyle(7,0,1);
       setusercharsize(1,1,1,2);
       outtextxy(150,20,"REPORT OF STOCK");
       line(100,50,560,50);
       setcolor(CYAN);
       settextstyle(0,0,1);
	  fseek(fp,0,SEEK_SET);
	  fread(&stock,sizeof(stock),1,fp);
	  rectangle(40,90,620,420);
	 gprint(&x1,&y1,"TOTAL NUMBER OF CYLINDER %d",stock.no_cyl);
	 gprint(&x1,&y1,"TOTAL NUMBER OF FILLED CYLINDER %d",stock.no_fil_cyl);
	 gprint(&x1,&y1,"TOTAL NUMBER OF EMPTY     CYLINDER %d",stock.no_emp_cyl);
	 gprint(&x1,&y1,"TOTAL NUMBER OF DEFECTIVE CYLINDER %d",stock.no_def_cyl);
	 gprint(&x1,&y1,"UMIT  RATE %f",stock.unit_rate);
	 getch();
	 fclose(fp);
     }

 //FUNCTION FOR GENERATING REPORT DAYWISE BOOKING


    void cyl_book()
     {
      char date[12],choice='y';
      int flag,i,n;
      FILE *fp;
      int x1=65,y1=120;
      fp=fopen("REF.TXT","rb");
       clearviewport();
       fseek(fp,0,SEEK_SET);
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
	     } while(flag==0);
	   flag=0;
	   a:clearviewport();
	    setcolor(10);
	    settextstyle(7,0,1);
	    setusercharsize(1,1,1,2);
	    outtextxy(150,20,"REPORT OF BOOKING");
	    line(100,50,560,50);
	    setcolor(CYAN);
	    settextstyle(0,0,1);
	    rectangle(70,70,520,350);
	     while(fread(&ref,sizeof(ref),1,fp)==1)
	      {
	     x1=100,y1=120;
	     if(strcmpi(ref.book_date,date)==0)
		 {
		  gprint(&x1,&y1,"BOOKING NO. %d",ref.book_num);
		  outtextxy(100,140,"BOOKING DATE");
		  outtextxy(300,140,ref.book_date);
		  outtextxy(100,160,"CUSTOMER NO.");
		  outtextxy(300,160,ref.cust_num);
		  outtextxy(100,180,"LAST SUPPLIED DATE");
		   if(strcmpi(ref.l_s_date,"NULL")==0)
		    outtextxy(300,180,"FIRST BOOKING");
		   else
		    outtextxy(300,180,ref.l_s_date);
		    y1=200;
		   gprint(&x1,&y1,"URGENT %c",ref.urgent);
		   gprint(&x1,&y1,"PRIORTY NO. %d",ref.prior_num);
		   outtextxy(200,400,"PRESS ANY KEY TO CONTINUE...");
		   getch();
		   clearviewport();
		   flag=1;
		   }
		  goto a;
		}
	      if(flag==0)
		  {
		   outtextxy(200,400,"NO BOOKING OR INVALID DATE!PRESS ENTER");
		   getch();
		   setfillstyle(SOLID_FILL,BLACK);
		   bar(190,390,550,410);
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
		    outtextxy(192,392,"ENTER (Y/N)");
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
		    rewind(fp);
		  }
	     fclose(fp);
	   }
   

 


//FUNCTION FOR GENERATING REPORT DAYWISE RELEASING
   

    void cyl_rel()
     {
       char date[12],choice='y';
       int flag,x1,y1,i;
       FILE *fp;
       fp=fopen("REF.TXT","rb");
       clearviewport();
	  fseek(fp,0,SEEK_SET);
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
	    } while(flag==0);
	  flag=0;
	  b:clearviewport();
	  setcolor(10);
	  settextstyle(7,0,1);
	  setusercharsize(1,1,1,2);
	  outtextxy(150,20,"REPORT OF REFILL");
	  line(100,50,560,50);
	  setcolor(CYAN);
	  settextstyle(0,0,1);
	  rectangle(70,70,520,350);
	   while(fread(&ref,sizeof(ref),1,fp)==1)
	    {
	     x1=100,y1=120;
	     if(strcmpi(ref.vouc_date,date)==0)
		 {
		  gprint(&x1,&y1,"BOOK NUMBER %d",ref.book_num);
		  outtextxy(100,140,"VOUCHER NO.");
		  outtextxy(300,140,ref.vouc_date);
		  outtextxy(100,160,"VOUCHER NO.");
		  outtextxy(300,160,ref.vouc_num);
		  if(strcmpi(ref.hawk_num,"NULL")!=0)
		   {
		    outtextxy(100,180,"HAWKER NO.");
		    outtextxy(300,180,ref.hawk_num);
		   }
		 else
		  {
		  outtextxy(100,180,"VEHICLE NO.");
		  outtextxy(300,180,ref.vehi_no);
		  }
		  x1=100,y1=220;
		  gprint(&x1,&y1,"SUPPLYING MODE %d",ref.supp_mode);
		  outtextxy(200,400,"PRESS ANY KEY TO CONTINUE...");
		  getch();
		  clearviewport();
		  flag=1;
		 }
		 goto b;
		}
	     if(flag==0)
		  {
		  outtextxy(200,400,"NO RELEASE OR INVALID DATE!PRESS ENTER");
		  getch();
		  setfillstyle(SOLID_FILL,BLACK);
		  bar(190,390,520,410);
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
		    outtextxy(192,392,"ENTER (Y/N)");
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
		 rewind(fp);
	 }
	    fclose(fp);
   }


//FUNCTION FOR GENERATING REPORT HARKER WISE RELEASE
    

   void cyl_haw()
     {
      char date[12],choice='y';
      int flag,i;
      FILE *fp;
      fp=fopen("REF.TXT","rb+");
      clearviewport();
	 fseek(fp,0,SEEK_SET);
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
	   } while(flag==0);
	  flag=0;
	  c:clearviewport();
	   setcolor(10);
	   settextstyle(7,0,1);
	   setusercharsize(1,1,1,2);
	   outtextxy(150,20,"HAWKER WISE RELEASE");
	   line(100,50,560,50);
	   setcolor(CYAN);
	   settextstyle(0,0,1);
	   rectangle(70,70,520,350);
       while(fread(&ref,sizeof(ref),1,fp)==1)
	    {
	     if(strcmpi(ref.vouc_date,date)==0)
		 if(strcmpi(ref.hawk_num,"NULL")!=0)
		  {
		  outtextxy(100,120,"CUSTOMER NO.");
		  outtextxy(300,120,ref.cust_num);
		  outtextxy(100,140,"HAWKER NO.");
		  outtextxy(300,140,ref.hawk_num);
		  outtextxy(100,160,"VOUCHER NO.");
		  outtextxy(300,160,ref.vouc_num);
		  outtextxy(200,400,"PRESS ANY KEY TO CONTINUE...");
		  getch();
		  clearviewport();
		  flag=1;
		  goto c;
		 }
	   }
	     if(flag==0)
		 {
		  outtextxy(200,400,"NO RELEASE OR INVALID DATE!PRESS ENTER");
		   getch();
		   setfillstyle(SOLID_FILL,BLACK);
		   bar(190,390,550,410);
		 }
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
		     outtextxy(192,392,"ENTER (Y/N)");
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
	  rewind(fp);
	}
	fclose(fp);
  }
    

//FUNCTION FOR GENERATING REPORT DAYWISE RELEASED URGENTLY

void cyl_urg()
     {
      char date[12],choice='y';
      int flag=0,i;
      FILE *fp1,*fp2;
      fp1=fopen("REF.TXT","rb");
      fp2=fopen("CUST.TXT","rb");
       clearviewport();
       fseek(fp1,0,SEEK_SET);
       fseek(fp2,0,SEEK_SET);
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
	    } while(flag==0);
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
		   outtextxy(200,400,"PRESS ANY KEY TO CONTINUE...");
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
		  outtextxy(200,400,"NO URGENT DELIVERY OR INVLID DATE!PRESS ENTER");
		  getch();
		  setfillstyle(SOLID_FILL,BLACK);
		  bar(190,390,600,410);
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
		 }
	    fclose(fp1);
	    fclose(fp2);
	   }

//FUNCTION FOR DRAWING BAR
  

   void draw_bar(int a,int b)
    {
     setfillstyle(SOLID_FILL,RED);
     bar(a,b,a+258,b+16);
    }

//FUNCTION FOR DRAWING ARROW


  void draw_arrow(int x, int y)
   {
   /* draw an arrow on the screen */
   moveto(x, y);
   setcolor(3);
   setfillstyle(SOLID_FILL,RED);
   linerel(4*ARROW_SIZE, 0);
   linerel(-2*ARROW_SIZE, -1*ARROW_SIZE);
   linerel(0, 2*ARROW_SIZE);
   linerel(2*ARROW_SIZE, -1*ARROW_SIZE);
   }

//FUNCTION FOR ADDITION OF NEW CUSTOMER
 
void read_cust()
   {
    FILE *fp;
    char ch,choice='y',cust_num1[6],cust_num2[6],cust_num3[6];
    int flag=0,n,i,k;
    while(choice=='y' || choice== 'Y')
     {
	setcolor(10);
	settextstyle(7,0,1);
	setusercharsize(1,1,1,2);
	outtextxy(70,50,"WELCOME TO  CUSTOMER MENU");
	line(50,70,620,70);
	setcolor(CYAN);
	rectangle(40,90,620,380);
	settextstyle(0,0,1);
	outtextxy(100,100,"ENTER CUSTOMER DATA");
	bar(350,140,430,160);
	outtextxy(120,150,"CUSTOMER NO:-");
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
		   i=1,k=0;
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
		       outtextxy(360,150,cust_num1);
		       strcpy(cust.cust_no,cust_num1);
	   flag=0;
	  setcolor(CYAN);
	  outtextxy(120,185,"CUSTOMER NAME:-");
	  do
  	   {
   	    setfillstyle(SOLID_FILL,CYAN);
	    bar(350,175,590,195);
	    fflush(stdin);
	    gotoxy(45,12);
	    gets(cust.name);
	     if(strlen(cust.name)>0)
	       for(i=0;cust.name[i]!='\0';i++)
	        if(cust.name[i]>=65 && cust.name[i]<=90)
	         flag=1;
	        else
	        if(cust.name[i]==' ')
	        i++;
	       else
	        {
	         outtextxy(200,400,"INVALID NAME!TRY AGAIN");
	         getch();
	         setfillstyle(SOLID_FILL,BLACK);
	         bar(190,390,420,410);
	         flag=0;
	         break;
	        }
	       }while(flag==0);
	     flag=0;
	     outtextxy(120,215,"CUSTOMER ADDRESS '1':-");
	    do
	    {
	     setfillstyle(SOLID_FILL,CYAN);
	     bar(350,205,610,225);
	     fflush(stdin);
	     gotoxy(45,14);
	     gets(cust.add1);
	      if(strlen(cust.add1)>0)
	        flag=1;
	      else
	       {
	        outtextxy(200,400,"INVALID ADDRESS!TRY AGAIN");
	        getch();
	        setfillstyle(SOLID_FILL,BLACK);
	        bar(190,390,420,410);
	       }
	     }while(flag==0);
     flag=0;
	outtextxy(120,245,"CUSTOMER ADDRESS '2':-");
	 do
	  {
	    setfillstyle(SOLID_FILL,CYAN);
	    bar(350,235,610,260);
	    gotoxy(45,16);
	    gets(cust.add2);
	    if(strlen(cust.add2)>0)
	     flag=1;
	    else
	    
 
         
         {
	     outtextxy(200,400,"INVALID ADDRESS!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	    }
	 }while(flag==0);
	flag=0;
	outtextxy(120,275,"CUSTOMER CITY:-");
	do
	{
	 setfillstyle(SOLID_FILL,CYAN);
	 bar(350,265,580,290);
	 gotoxy(45,18);
	 gets(cust.city);
	  if(strlen(cust.city)>0)
	  for(i=0;cust.city[i]!='\0';i++)
	  if(cust.city[i]>=65 && cust.city[i]<=90)
	    flag=1;
	  else
	     {
	     outtextxy(200,400,"INVALID CITY!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	     flag=0;
	     break;
	    }
	 }while(flag==0);
	flag=0;
	outtextxy(120,305,"CUSTOMER TELEPHONE NUMBER:-");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	bar(350,295,500,320);
	fflush(stdin);
	gotoxy(45,20);
	gets(cust.tel_no);
	   if(strlen(cust.tel_no)>0)
	   for(i=0;cust.tel_no[i]!='\0';i++)
	  if(cust.tel_no[i]>=48 && cust.tel_no[i]<=57)
	     flag=1;
	   else
	     {
	     outtextxy(200,400,"INVALID TEL NO!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	     flag=0;
	     break;
	    }
	 }while(flag==0);
	flag=0;
	outtextxy(120,335,"DO YOU WANT TO SAVE DATA 'Y/N':-");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	bar(400,330,420,355);
	fflush(stdin);
	gotoxy(52,22);
	ch=getchar();
	 if(ch!='Y' && ch!='N')
	   {
	     outtextxy(200,400,"ENTER(Y/N)");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	   }
	  else
	   flag=1;
	 }while(flag==0);
	clearviewport();
	if(ch=='y' || ch=='Y')
	 {
	 fwrite(&cust,sizeof(cust),1,fp);
	 rectangle(50,50,600,380);
	 setcolor(10);
	 outtextxy(100,100,"SAVE DATA IS:-");
	 setcolor(3);
	 outtextxy(120,148,"CUSTOMER NO:-");
	 outtextxy(340,148,cust.cust_no);
	 outtextxy(120,168,"CUSTOMER NAME:-");
	 outtextxy(340,168,cust.name);
	 outtextxy(120,188,"CUSTOMER ADDRESS '1':-");
	 outtextxy(340,188,cust.add1);
	 outtextxy(120,208,"CUSTOMER ADDRESS '2':-");
	 outtextxy(340,208,cust.add2);
	 outtextxy(120,228,"CUSTOMER CITY:-");
	 outtextxy(340,228,cust.city);
	 outtextxy(120,248,"CUSTOMER TELEPHONE NUMBER:-");
	 outtextxy(340,248,cust.tel_no);
	}
      flag=0;
      outtextxy(120,282,"DO YOU WANT MORE 'Y/N':-");
      do
      {
      setfillstyle(SOLID_FILL,CYAN);
      gotoxy(52,18);
      bar(400,270,425,290);
      fflush(stdin);
      choice=getchar();
      if(choice!='Y' && choice!='N')
	   {
	     outtextxy(200,400,"ENTER(Y/N)");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	   }
	  else
	   {
	   flag=1;
	   fclose(fp);
	   clearviewport();
	   }
       }while(flag==0);
     }
     fclose(fp);
  }


//FUNCTION FOR SEARCHING CUSTOMER 

    void search_cust()
      {
       FILE *fp;
       char name[20],ch='y';
       int flag,x1,y1,i;
       clearviewport();
       fp=fopen("CUST.TXT","rb");
	  if(fp==NULL)
	  {
	  printf("CANNOT OPEN FILE");
	  return;
	  }
	while(ch=='y' || ch=='Y')
	 {
	  setcolor(10);
	  settextstyle(7,0,1);
	  setusercharsize(1,1,1,2);
	  line(50,70,620,70);
	  outtextxy(100,40,"WELCOME TO SEARCH MENU");
	  setcolor(CYAN);
	  settextstyle(0,0,1);
	  rectangle(10,90,620,380);
	  outtextxy(20,115,"ENTER NAME OF CUSTOMER TO SEARCH");
	  flag=0;
	  do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  bar(300,110,600,130);
	  gotoxy(40,8);
	  fflush(stdin);
	  gets(name);
	   if(strlen(name)>0)
	   for(i=0;name[i]!='\0';i++)
	     if(name[i]>=65 && name[i]<=90)
	      flag=1;
	    else
	      if(name[i]==' ')
	       i++;
	    else
	     {
	     outtextxy(200,400,"INVALID 'USE CAPITAL LETTER'!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,520,410);
	     flag=0;
	     break;
	     }
	    }while(flag==0);
	   flag=0;
	  while(fread(&cust,sizeof(cust),1,fp)==1)
	   {
	    if(strcmpi(cust.name,name)==0)
	      {
	       clearviewport();
	       rectangle(50,50,620,380);
	       outtextxy(120,128,"CUSTOMER NO:-");
	       outtextxy(340,128,cust.cust_no);
	       outtextxy(120,148,"CUSTOMER NAME:-");
	       outtextxy(340,148,cust.name);
	       outtextxy(120,168,"CUSTOMER ADDRESS '1':-");
	       outtextxy(340,168,cust.add1);
	       outtextxy(120,188,"CUSTOMER ADDRESS '2':-");
	       outtextxy(340,188,cust.add2);
	       outtextxy(120,208,"CUSTOMER CITY:-");
	       outtextxy(340,208,cust.city);
	       outtextxy(120,228,"CUSTOMER TELEPHONE NUMBER:-");
	       outtextxy(340,228,cust.tel_no);
	  	  flag=1;
		  break;
	     }
	   }
	  if(flag==0)
	     outtextxy(80,200,"RECORD NOT FOUND");
	  outtextxy(95,300,"SEARCH ANOTHER RECORD 'Y/N'");
	  flag=0;
	  
      
      do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  gotoxy(49,19);
	  bar(380,285,400,305);
	  fflush(stdin);
	  ch=getchar();
	    if(ch!='Y' && ch!='N')
	    {
	      outtextxy(200,400,"ENTER(Y/N)");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,450);
	   }
	  else
	   {
	   flag=1;
	   clearviewport();
	   }
	  }while(flag==0);
	  if(ch=='Y')
	   rewind(fp);
	 }
       fclose(fp);
     }

   
//FUNCTION FOR PRINTING LIST OF CUSTOMER
   
   void list_cust()
     {
       FILE *fp;
       int y1,i;
       fp=fopen("CUST.TXT","rb");
	   if(fp==NULL)
	   {
	   printf("CANNOT OPEN FILE");
	   return;
	  }
       sta:y1=100;
       setcolor(10);
       settextstyle(7,0,1);
       setusercharsize(1,1,1,2);
       outtextxy(150,20,"LIST OF CUSTOMERS");
       line(100,50,560,50);
       setcolor(CYAN);
       settextstyle(0,0,1);
   

     
       line(40,65,620,65);
       line(40,95,620,95);
	  outtextxy(60,70,"NUMBER");
       outtextxy(150,70,"NAME");
       outtextxy(310,70,"CUSTOMER CITY");
       outtextxy(530,70,"TELEPHONE NO.");
       while(fread(&cust,sizeof(cust),1,fp)==1)
        {
         if(y1!=400)
	        {
	        outtextxy(62,y1,cust.cust_no);
	        outtextxy(155,y1,cust.name);
	        outtextxy(315,y1,cust.city);
	        outtextxy(535,y1,cust.tel_no);
	        y1+=20;
	        }
        else
	    {
	      outtextxy(80,410,"PRESS ANY KEY TO CONTINUE ...");
	      getch();
	      clearviewport();
	      goto sta;
	    }
       }
       outtextxy(80,410,"PRESS ANY KEY TO RETURN TO MAIN MENU");
      getch();
     }
     
//FUNCTION FOR DELETING ANY CUSTOMER

      void del_cust()
      {
       FILE *fp1,*fp2;
       char name[20],ch='y';
       int flag=0,i;
       fp1=fopen("CUST.TXT","rb+");
	   if(fp1==NULL)
	   {
	    printf("CANNOT OPEN FILE");
	    return;
	   }
       while(ch=='y' || ch=='Y')
       {
       flag=0;
       setcolor(10);
       settextstyle(7,0,1);
       setusercharsize(1,1,1,2);
       line(50,70,620,70);
       outtextxy(100,40,"WELCOME TO DELETE MENU");
       

       
       setcolor(CYAN);
       settextstyle(0,0,1);
       rectangle(10,90,620,380);
       outtextxy(20,115,"ENTER NAME OF CUSTOMER TO DELETE");
	  do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  bar(305,110,600,130);
	  gotoxy(40,8);
	  fflush(stdin);
	  gets(name);
	   if(strlen(name)>0)
	   for(i=0;name[i]!='\0';i++)
	     if(name[i]>=65 && name[i]<=90)
	       flag=1;
	     else
	      if(name[i]==' ')
	       i++;
	    else
	     {
	     outtextxy(200,400,"INVALID 'CAPITAL LETTER'!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,520,410);
	     flag=0;
	     break;
	     }
	    }while(flag==0);

	  flag=0;
	  fp2=fopen("TEMP.TXT","wb");
	   while(fread(&cust,sizeof(cust),1,fp1)==1)
	   {
	    if(strcmpi(cust.name,name)!=0)
	      fwrite(&cust,sizeof(cust),1,fp2);
	   else
	    flag=1;
	   }
	   if(flag==0)
	    outtextxy(80,200,"RECORD NOT FOUND");
	   else
	   outtextxy(80,200,"RECORD DELETED");
	  fclose(fp1);
	  fclose(fp2);
	  remove("CUST.TXT");
	  rename("TEMP.TXT","CUST.TXT");
	  outtextxy(95,295,"DELETE ANOTHER RECORD 'Y/N'");
	
   flag=0;
      do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  gotoxy(49,19);
	  bar(380,285,400,305);
	  fflush(stdin);
	  ch=getchar();
	     if(ch!='Y'&& ch!='N')
	      {
	     outtextxy(200,400,"ENTER(Y/N)");
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
	   if(ch=='Y')
	  fp1=fopen("CUST.TXT","rb+");
	 }
       fclose(fp1);
     }

//FUNCTION FOR ADDITION OF NEW INCOMING CUSTOMER

  void read_inc()
   {
    FILE * fp1,*fp2;
    char cust_num1[6],cust_num2[6],cust_num3[6],str[6];
    char ch,choice='y';
    int x1,y1,flag,i,n,k;
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
     while(choice=='y' || choice== 'Y')
     

  
     {
      fseek(fp1,0,SEEK_END);
      fseek(fp2,0,SEEK_END);
 	 setcolor(10);
	 settextstyle(7,0,1);
	 setusercharsize(1,1,1,2);
	 outtextxy(40,20,"WELCOME TO  INCOMING CUSTOMER MENU");
	 line(30,40,610,40);
	 setcolor(CYAN);
	 rectangle(40,50,620,440);
	 settextstyle(0,0,1);
	 outtextxy(100,60,"ENTER INCOMING CUSTOMER TRANSFER DATA");
	 flag=0;
	 outtextxy(120,85,"TRANSFER VOUCHER NUMBER:-");
	 do
	 {
	 setfillstyle(SOLID_FILL,CYAN);
	 gotoxy(45,6);
	 bar(340,77,600,97);
	 gets(in_c.tv_num);
	  if(strlen(in_c.tv_num)>0)
	    flag=1;
	 else
	  {
	   outtextxy(200,400,"INVALID NUMBER!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   }
	 }while(flag==0);
	outtextxy(120,115,"TRANSFEER VOUCHER DATE:-");
	flag=0;
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,8);
	bar(340,110,600,130);
	fflush(stdin);
	gets(in_c.tv_date);
	  if(strlen(in_c.tv_date)==8)
	     for(i=0;in_c.tv_date[i]!='\0';i++)
	      if(in_c.tv_date[i]>=48 && in_c.tv_date[i]<=57)
		flag=1;
	   else
	   {
	   outtextxy(200,400,"INVALID DATE!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   flag=0;
	   break;
	   }
	  }while(flag==0);
	flag=0;
	outtextxy(120,150,"LOCAL TRANSFER Y/N");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	bar(350,143,365,163);
	gotoxy(45,10);
	in_c.l_tran=getchar();
	   if(in_c.l_tran!='Y' && in_c.l_tran!='N')
	    {
	     outtextxy(200,400,"ENTER(Y/N)");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	    }
	  else
	     flag=1;
	   }while(flag==0);
	flag=0;
	outtextxy(120,180,"CUSTOMER NAME");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	gotoxy(45,12);
	bar(330,174,600,194);
	gets(in_c.cust_name);
	if(strlen(in_c.cust_name)>0)
	   for(i=0;in_c.cust_name[i]!='\0';i++)
	   if(in_c.cust_name[i]>=65 && in_c.cust_name[i]<=90)
	      flag=1;
	   else
	   if(in_c.cust_name[i]==' ')
	      i++;
	else
	  {
	   outtextxy(200,400,"INVALID'USE CAPITAL LETTER'!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,550,420);
	   flag=0;
	   break;
	   }
	 }while(flag==0);
	  flag=0;
	outtextxy(120,210,"CUSTOMER ADDRESS '1'");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,14);
	bar(330,207,600,227);
	gets(in_c.cust_add1);
	if(strlen(in_c.cust_add1)>0)
	  {
	  flag=1;
	 }
	  else
	     {
	     outtextxy(200,400,"INVALID ADDRESS!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	    }
	 }while(flag==0);
	flag=0;
	outtextxy(120,243,"CUSTOMER ADDRESS '2'");
	do
	{
       setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,16);
	bar(330,238,600,258);
	gets(in_c.cust_add2);
	 if(strlen(in_c.cust_add2)>0)
	  {
	   strcpy(cust.add2,in_c.cust_add2);
	   flag=1;
	  }
	  else
	     {
	     outtextxy(200,400,"INVALID ADDRESS!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	    }
	 }while(flag==0);
	flag=0;
	outtextxy(120,280,"CUSTOMER CITY");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,18);
	bar(330,270,600,290);
	gets(in_c.cust_city);
	  if(strlen(in_c.cust_city)>0)
	   for(i=0;in_c.cust_city[i]!='\0';i++)
	   if(in_c.cust_city[i]>=65 && in_c.cust_city[i]<=90)
	      flag=1;
	   else
	   {
	   outtextxy(200,400,"INVALID 'USE CAPITAL LETTER'!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,530,420);
	   flag=0;
	   break;
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,310,"CUSTOMER TELEPHONE NUMBER");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	gotoxy(45,20);
	bar(330,303,600,323);
	gets(in_c.cust_tel_no);
	  if(strlen(in_c.cust_tel_no)>0)
	   for(i=0;in_c.cust_tel_no[i]!='\0';i++)
	    if(in_c.cust_tel_no[i]>=48 && in_c.cust_tel_no[i]<=57)
	     flag=1;
	   else
	     {
	     outtextxy(200,400,"INVALID TEL NO!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	     flag=0;
	     break;
	    }
	 }while(flag==0);
	clearviewport();
	rectangle(40,40,620,440);
	flag=0;
	outtextxy(120,70,"PREVIOUS AGENCY CODE");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,5);
	bar(340,63,600,83);
	gets(in_c.pga_code);
	  if(strlen(in_c.pga_code)>0)
	    flag=1;
	  else
	   {
	   outtextxy(200,400,"INVALID CODE!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,100,"PREVIOUS AGENCY NAME");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	gotoxy(45,7);
	bar(340,95,600,115);
	gets(in_c.pga_name);
	    if(strlen(in_c.pga_name)>0)
	    for(i=0;in_c.pga_name[i]!='\0';i++)
	     if(in_c.pga_name[i]>=65 && in_c.pga_name[i]<=90)
	      flag=1;
	     else
	      if(in_c.pga_name[i]==' ')
		 i++;
	      else
	     {
	   outtextxy(200,400,"INVALID 'USE CAPITAL LETTER'!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,520,410);
	   flag=0;
	   break;
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,135,"PREVIOUS AGENCY ADDRESS '1'");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,9);
	bar(340,125,600,145);
	gets(in_c.pga_add1);
	  if(strlen(in_c.pga_add1)>0)
	    flag=1;
	    else
	     {
	   outtextxy(200,400,"INVALID ADDRESS!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,165,"PREVIOUS AGENCY ADDRESS '2'");
	do
	 {
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,11);
	bar(340,157,600,177);
	gets(in_c.pga_add2);
	  if(strlen(in_c.pga_add2)>0)
	    flag=1;
	    else
	     {
	   outtextxy(200,400,"INVALID CUSTNAME!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,195,"PREVIOUS AGENCY CITY");
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,13);
	bar(340,189,600,209);
	gets(in_c.pga_city);
	   if(strlen(in_c.pga_city)>0)
	    for(i=0;in_c.pga_city[i]!='\0';i++)
	     if(in_c.pga_city[i]>=65 && in_c.pga_city[i]<=90)
	      flag=1;
	     else
	     {
	   outtextxy(200,400,"INVALID 'USE CAPITAL LETTER'!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,520);
	   flag=0;
	   break;
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,230,"PREVIOUS AGENCY STATE");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,15);
	bar(340,221,600,241);
	
       
       gets(in_c.pga_stat);
	  if(strlen(in_c.pga_stat)>0)
	    for(i=0;in_c.pga_stat[i]!='\0';i++)
	     if(in_c.pga_stat[i]>=65 && in_c.pga_stat[i]<=90)
	      flag=1;
	     else
	       if(in_c.pga_stat[i]==' ')
		i++;
	     else
	     {
	   outtextxy(200,400,"INVALID 'USE CPITAL LETTER'!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   flag=0;
	   break;
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,260,"PREVIOUS AGENCY TELEPHONE");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	gotoxy(45,17);
	bar(340,254,600,274);
	gets(in_c.pga_phon);
	   if(strlen(in_c.pga_phon)>0)
	    for(i=0;in_c.pga_phon[i]!='\0';i++)
	     if(in_c.pga_phon[i]>=48 && in_c.pga_phon[i]<=57)
	      flag=1;
	     else
	     {
	   outtextxy(200,400,"INVALID TEL_NO!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   flag=0;
	   break;
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
	  return;
	 }
	}
	else
	    {
	    fseek(fp2,0,SEEK_SET);
	    fread(&cust,sizeof(cust),1,fp2);
	    strcpy(cust_num1,cust.cust_no);
	    }
	    i=1;k=0;
	     while(cust_num1[i]!='\0')
	       cust_num3[k++]=cust_num1[i++];
	       cust_num3[k]='\0';
		while(fread(&cust,sizeof(cust),1,fp2)==1)
			 {
			  strcpy(cust_num2,cust.cust_no);
			  i=1;k=0;
			    while(cust_num2[i]!='\0')
				 cust_num2[k++]=cust_num2[i++];
				  cust_num2[k]='\0';
			 if((atoi(cust_num2)) >= (atoi(cust_num3)))
			     strcpy(cust_num1,cust.cust_no);
			  }
		       i=1,k=0;
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
	bar(340,284,600,304);
	setcolor(WHITE);
	outtextxy(360,285,cust_num1);
	strcpy(cust.cust_no,cust_num1);
	strcpy(in_c.cust_no,cust_num1);
	strcpy(cust.name,in_c.cust_name);
	strcpy(cust.add1,in_c.cust_add1);
	strcpy(cust.add2,in_c.cust_add2);
	strcpy(cust.city,in_c.cust_city);
	strcpy(cust.tel_no,in_c.cust_tel_no);
	setcolor(CYAN);
	outtextxy(120,320,"DATE OF ASSIGNING NUMBER");
	bar(340,316,600,336);
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
	   itoa(d.da_year,str,10);
	   strcat(in_c.date_cust,str);
	   gotoxy(0,16);
	    setcolor(WHITE);
	 outtextxy(350,318,in_c.date_cust);
	flag=0;
	setcolor(CYAN);
	outtextxy(120,355,"DO YOU WANT TO SAVE DATA 'Y/N':-");
	

   do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	bar(400,348,420,368);
	gotoxy(52,23);
	ch=getchar();
	   if(ch!='Y' && ch!='N')
	   {
	   outtextxy(200,400,"ENTER (Y/N)!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	  }
	  else
	  flag=1;
	}while(flag==0);
	clearviewport();
	if(ch=='y' || ch=='Y')
	 {
	fwrite(&in_c,sizeof(in_c),1,fp1);
	fwrite(&cust,sizeof(cust),1,fp2);
	rectangle(20,10,620,420);
	outtextxy(100,30,"SAVE DATA IS:-");
	outtextxy(120,50,"TRANSFER VOUCHER NUMBER:-");
	outtextxy(340,50,in_c.tv_num);
	outtextxy(120,70,"TRANSFEER VOUCHER DATE:-");
	outtextxy(340,70,in_c.tv_date);
	outtextxy(120,90,"LOCAL TRANSFER Y/N:-");
	outtextxy(340,90,in_c.tv_date);
	outtextxy(120,110,"CUSTOMER NUMBER:-");
	outtextxy(340,110,in_c.cust_no);
	outtextxy(120,130,"CUSTOMER NAME:-");
	outtextxy(340,130,in_c.cust_name);
	outtextxy(120,150,"CUSTOMER ADDRESS1:-");
	outtextxy(340,150,in_c.cust_add2);
	outtextxy(120,170,"CUSTOMER ADDRESS '2':-");
	outtextxy(340,170,in_c.cust_add2);
	outtextxy(120,190,"CUSTOMER CITY:-");
	outtextxy(340,190,in_c.cust_city);
	outtextxy(120,210,"CUSTOMER TELEPHONE NUMBER:-");
	outtextxy(340,210,in_c.cust_tel_no);
	outtextxy(120,230,"PREVIOUS AGENCY CODE:-");
	outtextxy(340,230,in_c.pga_code);
	outtextxy(120,250,"PREVIOUS AGENCY ADDRESS '1'");
	outtextxy(340,250,in_c.pga_add1);
	outtextxy(120,270,"PREVIOUS AGENCY ADDRESS '2'");
	outtextxy(340,270,in_c.pga_add2);
	outtextxy(120,290,"PREVIOUS AGENCY CITY");
	outtextxy(340,290,in_c.pga_city);
	outtextxy(120,310,"PREVIOUS AGENCY STATE");
	outtextxy(340,310,in_c.pga_stat);
	outtextxy(120,330,"PREVIOUS AGENCY TELEPHONE");
	outtextxy(340,330,in_c.pga_phon);
	outtextxy(120,350,"ASSIGN CUSTOMER NUMBER");
	outtextxy(340,350,in_c.cust_no);
	outtextxy(120,370,"DATE OF ASSIGNING NUMBER");
	outtextxy(340,370,in_c.date_cust);
	outtextxy(100,390,"PRESS ANY KEY TO RETURN...");
	getch();
	}
       flag=0;
      clearviewport();
      rectangle(60,60,500,150);
       outtextxy(100,80,"DO YOU WANT MORE 'Y/N':-");
      do
      {
      setfillstyle(SOLID_FILL,CYAN);
      gotoxy(46,6);
      bar(357,76,382,96);
      fflush(stdin);
      choice=getchar();
       if(ch!='Y' && ch!='N')
	   {
	   outtextxy(200,400,"INVALID CUSTNAME!TRY AGAIN");
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
       if(ch=='Y')
	rewind(fp2);
     }
     fclose(fp1);
     fclose(fp2);
  }
 
//FUNCTION FOR DISPLAY LIST OF INCOMING CUSTOMER

void list_inc()
     {
       FILE *fp;
       int y1;
	
     
     fp=fopen("IN_CUST.TXT","rb");
	if(fp==NULL)
	 {
	  printf("CANNOT OPEN FILE");
	  return;
	 }
       fseek(fp,0,SEEK_SET);
       sta:y1=100;
       setcolor(10);
       settextstyle(7,0,1);
       setusercharsize(1,1,1,2);
       outtextxy(150,20,"LIST OF CUSTOMERS");
       line(100,50,560,50);
       setcolor(CYAN);
       settextstyle(0,0,1);
       line(20,65,610,65);
       line(20,95,610,95);
	       outtextxy(30,70,"TV_NUM");
	       outtextxy(92,70,"TV_DATE");
	       outtextxy(182,70,"NUMBER");
	       outtextxy(282,70,"NAME");
	       outtextxy(402,70,"CITY");
	       outtextxy(510,70,"TELEPHONE NO.");

   while(fread(&in_c,sizeof(in_c),1,fp)==1)
   {
    if(y1!=400)
	 {
	outtextxy(32,y1,in_c.tv_num);
	outtextxy(90,y1,in_c.tv_date);
	outtextxy(180,y1,in_c.cust_no);
	outtextxy(280,y1,in_c.cust_name);
	outtextxy(400,y1,in_c.cust_city);
	outtextxy(535,y1,in_c.cust_tel_no);
	 y1+=20;
	}
    else
	{
	outtextxy(80,410,"PRESS ANY KEY TO CONTINUE ...");
	getch();
	clearviewport();
	goto sta;
	}
       }
      outtextxy(80,410,"PRESS ANY KEY TO RETURN");
      getch();
     }
 


//FUNCTION FOR SEARCHING INCOMING CUSTOMER

void search_inc()
    {
    FILE *fp;
    char name[20],ch='y';
    int flag=0,x1,y1,i;
	fp=fopen("IN_CUST.TXT","rb");
	if(fp==NULL)
	 {
	  printf("CANNOT OPEN FILE");
	  getch();
	  return;
	 }
	while(ch=='y' || ch=='Y')
	 {
	  setcolor(10);
       settextstyle(7,0,1);
       setusercharsize(1,1,1,2);
       line(50,70,620,70);
       outtextxy(100,40,"WELCOME TO SEARCH MENU");
       setcolor(CYAN);
       settextstyle(0,0,1);
       rectangle(10,90,620,380);
	   flag=0;
	  outtextxy(20,115,"ENTER NAME OF CUSTOMER TO SEARCH");
	  do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  bar(300,106,600,138);
	  gotoxy(40,8);
	  fflush(stdin);
	  gets(name);
	     if(strlen(name)>0)
	       for(i=0;name[i]!='\0';i++)
		if(name[i]>=65 && name[i]<=90)
		  flag=1;
		else
		if(name[i]==' ')
		 i++;
	       else
		 {
		 outtextxy(200,400,"INVALID 'USE CAPITAL LETTER'!TRY  AGAIN");
		 getch();
		 setfillstyle(SOLID_FILL,BLACK);
		 bar(190,390,520,410);
		 flag=0;
		 

           break;
	     }
	  }while(flag==0);
	     flag=0;
	     while(fread(&in_c,sizeof(in_c),1,fp)==1)
	      {
	       if(strcmpi(in_c.cust_name,name)==0)
		  {
		  x1=120,y1=90;
		  clearviewport();
		  rectangle(20,10,620,420);
	       outtextxy(100,30,"SAVE DATA IS:-");
	       outtextxy(120,50,"TRANSFER VOUCHER NUMBER:-");
	       outtextxy(340,50,in_c.tv_num);
	       outtextxy(120,70,"TRANSFEER VOUCHER DATE:-");
	       outtextxy(340,70,in_c.tv_date);
	       gprint(&x1,&y1,"LOCAL TRANSFER Y/N:- %c",in_c.l_tran);
	        outtextxy(120,110,"CUSTOMER NUMBER:-");
	        outtextxy(340,110,in_c.cust_no);
	        outtextxy(120,130,"CUSTOMER NAME:-");
	        outtextxy(340,130,in_c.cust_name);
	        outtextxy(120,150,"CUSTOMER ADDRESS1:-");
	        outtextxy(340,150,in_c.cust_add2);
	        outtextxy(120,170,"CUSTOMER ADDRESS '2':-");
	        outtextxy(340,170,in_c.cust_add2);
	        outtextxy(120,190,"CUSTOMER CITY:-");
	        outtextxy(340,190,in_c.cust_city);
	        outtextxy(120,210,"CUSTOMER TELEPHONE NUMBER:-");
	        outtextxy(340,210,in_c.cust_tel_no);
	        outtextxy(120,230,"PREVIOUS AGENCY CODE:-");
	        outtextxy(340,230,in_c.pga_code);
	        outtextxy(120,250,"PREVIOUS AGENCY CODE:-");
	        outtextxy(340,250,in_c.pga_code);
	        outtextxy(120,270,"PREVIOUS AGENCY ADDRESS '1'");
	        outtextxy(340,270,in_c.pga_add1);
	        outtextxy(120,270,"PREVIOUS AGENCY ADDRESS '2'");
	        outtextxy(340,270,in_c.pga_add2);
	        outtextxy(120,290,"PREVIOUS AGENCY CITY");
	        outtextxy(340,290,in_c.pga_city);
	        outtextxy(120,310,"PREVIOUS AGENCY STATE");
	        outtextxy(340,310,in_c.pga_stat);
    	        outtextxy(120,330,"PREVIOUS AGENCY TELEPHONE");
	        outtextxy(340,330,in_c.pga_phon);
	        outtextxy(120,350,"ASSIGN CUSTOMER NUMBER");
	        outtextxy(340,350,in_c.cust_no);
	        outtextxy(120,370,"DATE OF ASSIGNING NUMBER");
	        outtextxy(340,370,in_c.date_cust);
	        
            
              outtextxy(120,390,"PRESS ANY KEY...");
		    flag=1;
		getch();
		break;
	    }
	   }
	  x1=23,y1=355;
	  if(flag==0)
	  outtextxy(80,200,"RECORD NOT FOUND");
	  else
	  {
	  clearviewport();
	  rectangle(70,70,510,200);
	  y1=95;
	  x1=7;
	  }
	  flag=0;
	  outtextxy(95,y1,"SEARCH ANOTHER RECORD 'Y/N'");
	  do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  gotoxy(49,x1);
	  bar(378,y1,400,y1+20);
	  fflush(stdin);
	  ch=getchar();
	   if(ch!='Y'&&ch!='N')
	     {
	     outtextxy(200,400,"ENTER (Y/N)!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	    }
	   else
	    {
	    flag=1;
	    clearviewport();
	   }
	 } while(flag==0);
	  if(ch=='Y')
	  rewind(fp);
	}
       fclose(fp);
     }

//FUNCTION FOR DELETION OF INCOMING CUSTOMER 

   void del_inc()
     {
       FILE *fp1,*fp2,*fp3,*fp4;
      char name[20],ch='y';
      int flag,i;
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
	while(ch=='y' || ch=='Y')
	 {
	 setcolor(10);
	 settextstyle(7,0,1);
	 setusercharsize(1,1,1,2);
	 line(50,70,620,70);
	 outtextxy(100,40,"WELCOME TO DELETE MENU");
	 setcolor(CYAN);
	 settextstyle(0,0,1);
	 rectangle(10,90,620,380);
	  flag=0;
	   outtextxy(20,115,"ENTER NAME OF CUSTOMER TO DELETE");
	 do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  bar(305,110,600,130);
	  gotoxy(40,8);
	  fflush(stdin);
	  gets(name);
	   if(strlen(name)>0)
	    for(i=0;name[i]!='\0';i++)
		if(name[i]>=65 && name[i]<=90)
		  flag=1;
		else
		if(name[i]==' ')
		 i++;
	       else
		 {
		 outtextxy(200,400,"INVALID 'USE CAPITAL LETTER'!TRY AGAIN");
		 getch();
		 setfillstyle(SOLID_FILL,BLACK);
		 bar(190,390,520,410);
		 
           
           flag=0;
		 break;
		 }
	  }while(flag==0);

	  fp3=fopen("TEMP.TXT","wb");
	   flag=0;
	   while(fread(&in_c,sizeof(in_c),1,fp1)==1)
	   {
	    if(strcmpi(in_c.cust_name,name)!=0)
	      fwrite(&in_c,sizeof(in_c),1,fp3);
	    else
	     flag=1;
	   }
	  fclose(fp1);
	  fclose(fp3);
	 remove("IN_CUST.TXT");
	 rename("TEMP.TXT","IN_CUST.TXT");
	 fp4=fopen("TEMP1.TXT","wb");
	   if(flag==0)
	     outtextxy(80,200,"RECORD NOT FOUND");
	   else
	      {
	       outtextxy(80,200,"RECORD DELETED");
	       while(fread(&cust,sizeof(cust),1,fp2)==1)
		if(strcmpi(cust.name,name)!=0)
		  fwrite(&cust,sizeof(cust),1,fp4);
	       }
	  fclose(fp2);
	  fclose(fp4);
	  remove("CUST.TXT");
	  rename("TEMP1.TXT","CUST.TXT");
	   outtextxy(95,295,"DELETE ANOTHER RECORD 'Y/N'");
	  do
	  {
	  fp1=fopen("IN_CUST.TXT","rb");
	  setfillstyle(SOLID_FILL,CYAN);
	  gotoxy(49,19);
	  bar(380,285,400,305);
	  fflush(stdin);
	  ch=getchar();
	   if(ch!='Y'&& ch!='N')
	    {
	     outtextxy(200,400,"ENTER (Y/N)!TRY AGAIN");
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
	  if(ch=='Y')
	   {
	   fp1=fopen("IN_CUST.TXT","rb");
	   fp2=fopen("IN_CUST.TXT","rb");
	   }
	  }
       fclose(fp1);
     }

//FUNCTION FOR ADDITION OF OUTGOING CUSTOMER

  void read_ouc()
   {
     FILE *fp1,*fp2,*fp3;
     char ch,choice='y',cust_num1[6],tv_num1[6],tv_num2[6],
          tv_num3[6],str[6];
     int flag,flag4,x1,y1,i,k,n;
     struct date d;
     while(choice=='y' || choice== 'Y')
      {
	 setcolor(10);
	 settextstyle(7,0,1);
	 setusercharsize(1,1,1,2);
	 outtextxy(40,20,"WELCOME TO  OUTGOING CUSTOMER MENU");
	 line(30,40,610,40);
	 setcolor(CYAN);
	 rectangle(40,50,620,440);
	 settextstyle(0,0,1);
	 outtextxy(100,60,"ENTER OUTGOING CUSTOMER TRANSFER DATA");
	 outtextxy(120,85,"TRANSFER VOUCHER NUMBER:-");
	 fp1=fopen("OU_CUST.TXT","rb+");
       if(fp1==NULL)
	  {
	   fp1=fopen("OU_CUST.TXT","wb+");
	   strcpy(tv_num1,"T0000");
	    if(fp1==NULL)
	    {
	     printf("CANNOT OPEN FILE");
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
		       i=1,k=0;
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

	
     setcolor(WHITE);
	bar(340,77,600,97);
	outtextxy(345,79,ou_c.tv_num);
	setcolor(CYAN);
	outtextxy(120,115,"TRANSFEER VOUCHER DATE:-");
	gotoxy(45,8);
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
	   itoa(d.da_year,str,10);
	   strcat(ou_c.tv_date,str);
	   bar(340,110,600,130);
	   setcolor(WHITE);
	   outtextxy(350,112,ou_c.tv_date);
	   setcolor(CYAN);
	flag=0;
	outtextxy(120,150,"LOCAL TRANSFER Y/N");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	bar(350,143,365,163);
	gotoxy(45,10);
	ou_c.l_tran=getchar();
	   if(ou_c.l_tran!='Y' && ou_c.l_tran!='N')
	    {
	     outtextxy(200,400,"ENTER(Y/N)");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	    }
	  else
	     flag=1;
	   }while(flag==0);
	flag=0;
	outtextxy(120,180,"ENTER CUSTOMER NO.");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	gotoxy(45,12);
	bar(330,174,600,194);
	gets(cust_num1);
	if(strlen(cust_num1)>0)
	       if(cust_num1[0]!='C')
		   {
		   outtextxy(200,400,"INVALID CUSTOMER NO'C'!TRY AGAIN");
		   getch();
		   }
		else
		{
		 for(i=1;cust_num1[i]!='\0';i++)
		  if(cust_num1[i]>=48 && cust_num1[i]<=57)
		    flag=1;
		  else
		   {
		   outtextxy(200,400,"INVALID CUSTOMER NO!TRY AGAIN");
		   getch();
		   }
		 }
		   setfillstyle(SOLID_FILL,BLACK);
		  bar(170,390,500,410);
	       }while(flag==0);
       strcpy(ou_c.cust_no,cust_num1);
       fp2=fopen("CUST.TXT","rb");
       fseek(fp2,0,SEEK_SET);
       flag4=0;
	while(fread(&cust,sizeof(cust),1,fp2)==1)
	{
	if(strcmpi(cust.cust_no,cust_num1)==0)
	{
	outtextxy(120,210,"CUST NAME");
	outtextxy(340,210,cust.name);
	strcpy(ou_c.cust_name,cust.name);
	outtextxy(120,240,"CUSTOMER ADDRESS '1'");
	outtextxy(340,240,cust.add1);
	strcpy(ou_c.cust_add1,cust.add1);
	outtextxy(120,260,"CUSTOMER ADDRESS '2'");
	outtextxy(340,260,cust.add2);
	strcpy(ou_c.cust_add2,cust.add2);
	outtextxy(120,280,"CUSTOMER CITY");
	outtextxy(340,280,cust.city);
	strcpy(ou_c.cust_city,cust.city);
	outtextxy(120,300,"CUSTOMER TELEPHONE NUMBER");
	outtextxy(340,300,cust.tel_no);
	strcpy(ou_c.cust_tel_no,cust.tel_no);
	outtextxy(100,340,"PRESS ANY KEY...");
	getch();
	clearviewport();
	rectangle(40,40,620,440);
	flag=0;
	outtextxy(120,70,"NEW AGENCY CODE");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,5);
	bar(340,63,600,83);
	gets(ou_c.n_g_a_code);
	  if(strlen(ou_c.n_g_a_code)>0)
	    flag=1;
	  else
	   {
	   outtextxy(200,400,"INVALID CODE!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,100,"NEW AGENCY NAME");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	gotoxy(45,7);
	bar(340,95,600,115);
	gets(ou_c.n_g_a_name);
	    if(strlen(ou_c.n_g_a_name)>0)
	    for(i=0;ou_c.n_g_a_name[i]!='\0';i++)
	     if(ou_c.n_g_a_name[i]>=65 && ou_c.n_g_a_name[i]<=90)
	      flag=1;
	     else
	      if(ou_c.n_g_a_name[i]==' ')
		 i++;
	    else
	  {
	   outtextxy(200,400,"INVALID NAME!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   flag=0;
	   break;
	  }
	 }while(flag==0);
	flag=0;
	outtextxy(120,135,"NEW AGENCY ADDRESS '1'");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,9);
	bar(340,125,600,145);
	gets(ou_c.n_g_a_add1);
	  if(strlen(ou_c.n_g_a_add1)>0)
	    flag=1;
	    else
	     {
	   outtextxy(200,400,"INVALID ADRESS!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,165,"NEW AGENCY ADDRESS '2'");
	do
	 {
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,11);
	bar(340,157,600,177);
	gets(ou_c.n_g_a_add2);
	  if(strlen(ou_c.n_g_a_add2)>0)
	    flag=1;
	    else
	     {
	   outtextxy(200,400,"INVALID ADDRESS!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,195,"NEW AGENCY CITY");
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,13);
	fflush(stdin);
	bar(340,189,600,209);
	gets(ou_c.n_g_a_city);
	  if(strlen(ou_c.n_g_a_city)>0)
	   for(i=0;ou_c.n_g_a_city[i]!='\0';i++)
	    if(ou_c.n_g_a_city[i]>=65 && ou_c.n_g_a_city[i]<=90)
	      flag=1;
	     else
	     {
	   outtextxy(200,400,"INVALID CITY!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   flag=0;
	   break;
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,230,"NEW AGENCY STATE");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	gotoxy(45,15);
	bar(340,221,600,241);
	gets(ou_c.n_g_a_stat);
	  if(strlen(ou_c.n_g_a_stat)>0)
	    for(i=0;ou_c.n_g_a_stat[i]!='\0';i++)
	     if(ou_c.n_g_a_stat[i]>=65 && ou_c.n_g_a_stat[i]<=90)
	      flag=1;
	     else
	       if(ou_c.n_g_a_stat[i]==' ')
		i++;
	     else
	     {
	   outtextxy(200,400,"INVALID STATE!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   flag=0;
	   break;
	   }
	 }while(flag==0);
	flag=0;
	outtextxy(120,260,"NEW AGENCY TELEPHONE");
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	gotoxy(45,17);
	bar(340,254,600,274);
	gets(ou_c.n_g_a_phon);
	   if(strlen(ou_c.n_g_a_phon)>0)
	    for(i=0;ou_c.n_g_a_phon[i]!='\0';i++)
	     if(ou_c.n_g_a_phon[i]>=48 && ou_c.n_g_a_phon[i]<=57)
	      flag=1;
	     else
	     {
	   outtextxy(200,400,"INVALID NO.!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	   flag=0;
	   break;
	   }
	 }while(flag==0);
	 flag4=1;
	break;
	}
       }
       if(flag4==0)
	{
	     outtextxy(200,400,"CUSTOMER NOT FOUND");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(170,390,500,410);
	}

	if(flag4==1)
	{
	outtextxy(120,355,"DO YOU WANT TO SAVE DATA 'Y/N':-");
	flag=0;
	do
	{
	setfillstyle(SOLID_FILL,CYAN);
	fflush(stdin);
	bar(400,348,420,368);
	gotoxy(52,23);
	ch=getchar();
	  if(ch!='Y'&&ch!='N')
	     {
	   outtextxy(200,400,"INVALID CUSTNAME!TRY AGAIN");
	   getch();
	   setfillstyle(SOLID_FILL,BLACK);
	   bar(190,390,420,410);
	 }
	 else
	 flag=1;
	 }while(flag==0);
	clearviewport();
	if(ch=='y' || ch=='Y')
	 {
	 x1=120,y1=90;
	

     
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
	rectangle(20,10,620,420);
	 outtextxy(100,30,"SAVE DATA IS:-");
	 outtextxy(120,50,"TRANSFER VOUCHER NUMBER:-");
	outtextxy(340,50,ou_c.tv_num);
	outtextxy(120,70,"TRANSFEER VOUCHER DATE:-");
	outtextxy(340,70,ou_c.tv_date);
	gprint(&x1,&y1,"LOCAL TRANSFER Y/N:-      %c",ou_c.l_tran);
	outtextxy(120,110,"CUSTOMER NUMBER:-");
	outtextxy(340,110,ou_c.cust_no);
	outtextxy(120,130,"CUSTOMER NAME:-");
	outtextxy(340,130,ou_c.cust_name);
	outtextxy(120,150,"CUSTOMER ADDRESS1:-");
	outtextxy(340,150,ou_c.cust_add1);
	outtextxy(120,170,"CUSTOMER ADDRESS '2':-");
	outtextxy(340,170,ou_c.cust_add2);
	outtextxy(120,190,"CUSTOMER CITY:-");
	outtextxy(340,190,ou_c.cust_city);
	outtextxy(120,210,"CUSTOMER TELEPHONE NUMBER:-");
	outtextxy(340,210,ou_c.cust_tel_no);
	outtextxy(120,230,"PREVIOUS AGENCY CODE:-");
	outtextxy(340,230,ou_c.n_g_a_code);
	outtextxy(120,250,"PREVIOUS AGENCY CODE:-");
	outtextxy(340,250,ou_c.n_g_a_name);
	outtextxy(120,270,"PREVIOUS AGENCY ADDRESS '1'");
	outtextxy(340,270,ou_c.n_g_a_add1);
	outtextxy(120,270,"PREVIOUS AGENCY ADDRESS '2'");
	outtextxy(340,270,ou_c.n_g_a_add2);
	outtextxy(120,290,"PREVIOUS AGENCY CITY");
	outtextxy(340,290,ou_c.n_g_a_city);
	outtextxy(120,310,"PREVIOUS AGENCY STATE");
	outtextxy(340,310,ou_c.n_g_a_stat);
	outtextxy(120,330,"PREVIOUS AGENCY TELEPHONE");
	outtextxy(340,330,ou_c.n_g_a_phon);
	}
       }
       flag=0;
	outtextxy(100,360,"DO YOU WANT MORE 'Y/N':-");
     
  
     do
      {
      setfillstyle(SOLID_FILL,CYAN);
      gotoxy(46,23);
      bar(357,350,380,375);
      fflush(stdin);
      choice=getchar();
       if(choice!='Y'&& choice!='N')
	    {
	     outtextxy(200,400,"ENTER!TRY AGAIN");
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
	}
     fclose(fp1);
     fclose(fp2);
  }

//FUNCTION FOR DISPLAY LIST OF OUTGOING CUSTOMER

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
       sta:y1=110;
       setcolor(10);
       settextstyle(7,0,1);
       setusercharsize(1,1,1,2);
       outtextxy(150,20,"LIST OF CUSTOMERS");
       line(100,50,560,50);
       setcolor(CYAN);
       settextstyle(0,0,1);
       line(20,65,610,65);
       
            line(20,95,610,95);
	       outtextxy(30,70,"TV_NUM");
	       outtextxy(92,70,"TV_DATE");
	       outtextxy(182,70,"NUMBER");
	       outtextxy(282,70,"NAME");
	       outtextxy(402,70,"CITY");
	       outtextxy(510,70,"TELEPHONE NO.");

  while(fread(&ou_c,sizeof(ou_c),1,fp)==1)
   {
   if(y1!=400)
     {
	outtextxy(32,y1,ou_c.tv_num);
	outtextxy(90,y1,ou_c.tv_date);
	outtextxy(180,y1,ou_c.cust_no);
	outtextxy(280,y1,ou_c.cust_name);
	outtextxy(400,y1,ou_c.cust_city);
	outtextxy(535,y1,ou_c.cust_tel_no);
	 y1+=20;
	}
	else
	{
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
 
//FUNCTION FOR SEARCHING OUTGOING CUSTOMER

void search_ouc()
    {
    FILE *fp;
    char name[20],ch='y';
    int flag=0,x1,y1,i;
     fp=fopen("OU_CUST.TXT","rb");
	if(fp==NULL)
	 {
	  printf("CANNOT OPEN FILE");
	  return;
	 }
       setcolor(10);
       settextstyle(7,0,1);
       setusercharsize(1,1,1,2);
       line(50,30,620,30);
       outtextxy(100,10,"WELCOME TO SEARCH MENU");
       setcolor(CYAN);
       settextstyle(0,0,1);
       rectangle(10,70,620,380);
	while(ch=='y' || ch=='Y')
	 {
	  outtextxy(20,115,"ENTER NAME OF CUSTOMER TO SEARCH");
	  do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  bar(300,106,600,133);
	  gotoxy(40,8);
	  fflush(stdin);
	  gets(name);
	     if(strlen(name)>0)
	       for(i=0;name[i]!='\0';i++)
		if(name[i]>=65 && name[i]<=90)
		  flag=1;
		else
		if(name[i]==' ')
		 i++;
	       else
		 {
		 outtextxy(200,400,"INVALID 'USE CAPITAL LETTER'!TRY AGAIN");
		 getch();
		 setfillstyle(SOLID_FILL,BLACK);
		 bar(190,390,520,410);
		 flag=0;
		 break;
	       }
	  }while(flag==0);
	    flag=0;
	     while(fread(&ou_c,sizeof(ou_c),1,fp)==1)
	     {
	    if(strcmpi(ou_c.cust_name,name)==0)
	       {
	       x1=120,y1=90;
		 clearviewport();
		 rectangle(20,10,620,420);
	outtextxy(120,50,"TRANSFER VOUCHER NUMBER:-");
	outtextxy(340,50,ou_c.tv_num);
	outtextxy(120,70,"TRANSFEER VOUCHER DATE:-");
	outtextxy(340,70,ou_c.tv_date);
	gprint(&x1,&y1,"LOCAL TRANSFER Y/N:-      %c",ou_c.l_tran);
	outtextxy(120,110,"CUSTOMER NUMBER:-");
	outtextxy(340,110,ou_c.cust_no);
	outtextxy(120,130,"CUSTOMER NAME:-");
	outtextxy(340,130,ou_c.cust_name);
	outtextxy(120,150,"CUSTOMER ADDRESS1:-");
	outtextxy(340,150,ou_c.cust_add1);
	outtextxy(120,170,"CUSTOMER ADDRESS '2':-");
	outtextxy(340,170,ou_c.cust_add2);
	outtextxy(120,190,"CUSTOMER CITY:-");
	outtextxy(340,190,ou_c.cust_city);
	outtextxy(120,210,"CUSTOMER TELEPHONE NUMBER:-");
	outtextxy(340,210,ou_c.cust_tel_no);
	outtextxy(120,230,"NEW AGENCY CODE:-");
	outtextxy(340,230,ou_c.n_g_a_code);
	outtextxy(120,250,"NEW AGENCY NAME:-");
	outtextxy(340,250,ou_c.n_g_a_name);
	outtextxy(120,270,"NEW AGENCY ADDRESS '1'");
	outtextxy(340,270,ou_c.n_g_a_add1);
	outtextxy(120,290,"NEW AGENCY ADDRESS '2'");
	outtextxy(340,290,ou_c.n_g_a_add2);
	outtextxy(120,310,"NEW AGENCY CITY");
	outtextxy(340,310,ou_c.n_g_a_city);
	outtextxy(120,330,"NEW AGENCY STATE");
	outtextxy(340,330,ou_c.n_g_a_stat);
	outtextxy(120,350,"NEW AGENCY TELEPHONE");
	outtextxy(340,350,ou_c.n_g_a_phon);
		flag=1;
		break;
	      }
	   }
	  if(flag==0)
	   outtextxy(80,200,"RECORD NOT FOUND");
	 flag=0;
	 outtextxy(95,370,"SEARCH ANOTHER RECORD 'Y/N'");
	 do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  gotoxy(49,23);
	  bar(380,351,400,377);
	  fflush(stdin);
	  ch=getchar();
	   if(ch!='Y'&& ch!='N')
	     {
	     outtextxy(200,400,"ENTER (Y/N)!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	    }
	   else
	    {
	    flag=1;
	    clearviewport();
	   }
	 } while(flag==0);
	  
       
       if(ch=='Y')
	  rewind(fp);
	}
	fclose(fp);
     }

//FUNCTION FOR DELETING ANY OUTGOING CUSTOMER

    void del_ouc()
     {
       FILE *fp1,*fp2;
       char name[20],ch='y',i;
       int flag=0;
       fp1=fopen("OU_CUST.TXT","rb");
	if(fp1==NULL)
	 {
	  printf("CANNOT OPEN FILE");
	  return;
	 }
	while(ch=='y' || ch=='Y')
	 {
	 setcolor(10);
       settextstyle(7,0,1);
       setusercharsize(1,1,1,2);
       line(50,70,620,70);
       outtextxy(100,40,"WELCOME TO DELETE MENU");
       setcolor(CYAN);
       settextstyle(0,0,1);
       rectangle(10,90,620,380);
	  flag=0;
	  outtextxy(20,115,"ENTER NAME OF CUSTOMER TO DELETE");
	  do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  bar(300,106,600,133);
	  gotoxy(40,8);
	  fflush(stdin);
	  gets(name);
	     if(strlen(name)>0)
	       for(i=0;name[i]!='\0';i++)
		if(name[i]>=65 && name[i]<=90)
		  flag=1;
		else
		if(name[i]==' ')
		 i++;
	       else
		 {
		 outtextxy(200,400,"INVALID 'USE CAPITAL LETTER'!TRY AGAIN");
		 getch();
		 setfillstyle(SOLID_FILL,BLACK);
		 bar(190,390,520,410);
		 flag=0;
		 break;
	       }
	  }while(flag==0);
	   flag=0;
	   fp2=fopen("TEMP1.TXT","wb");
	   fseek(fp1,0,SEEK_SET);
	   while(fread(&ou_c,sizeof(ou_c),1,fp1)==1)
	   {
	    if(strcmpi(ou_c.cust_name,name)!=0)
	      fwrite(&ou_c,sizeof(ou_c),1,fp2);
	    else
	     flag=1;
	   }
	   if(flag==0)
	     outtextxy(80,200,"RECORD NOT FOUND");
	   else
	     outtextxy(80,200,"RECORD DELETED");
	  fclose(fp1);
	  fclose(fp2);
	   remove("OU_CUST.TXT");
	   rename("TEMP1.TXT","OU_CUST.TXT");
	  flag=0;
	  outtextxy(95,350,"DELETE ANOTHER RECORD 'Y/N'");
	  do
	  {
	  setfillstyle(SOLID_FILL,CYAN);
	  gotoxy(49,23);
	  bar(380,351,400,377);
	  fflush(stdin);
	  ch=getchar();
	   if(ch!='Y'&&ch!='N')
	     {
	     outtextxy(200,400,"ENTER (Y/N)!TRY AGAIN");
	     getch();
	     setfillstyle(SOLID_FILL,BLACK);
	     bar(190,390,420,410);
	    }
	   else
	    {
	    flag=1;
	    clearviewport();
	   }
	 } while(flag==0);
	   if(ch=='Y')
	   fp1=fopen("OU_CUST.TXT","rb");
	}

       fclose(fp1);
     }

//PRINTING DIGIT & CHARACTER IN GRAPHICS MODE

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

//FUNCTION FOR BOOKING OF REFILL

   void book_cust()
   {
    char ch,choice='y';
    int bnum=0,n,i,j,x1,y1,k,d1,m1,y2,date=20;
    char str[6],cust_num1[6],l_date[9],arr[5];
    FILE *fp1,*fp2,*fp3;
    struct date d;
    int flag,flag1=0;
	fp1=fopen("REF.TXT","rb+");
	fp2=fopen("CUST.TXT","rb+");
	if(fp2==NULL)
	 {
	  outtextxy(50,50,"FILE NOT OPEN");
	  return;
	 }

	while(choice=='y' || choice=='Y')
	  {
	setcolor(10);
	settextstyle(7,0,1);
	setusercharsize(1,1,1,2);
	outtextxy(15,40,"WELCOME TO REFILL BOOKING FORM");
	line(10,65,620,65);
	setcolor(3);
	setfillstyle(SOLID_FILL,CYAN);
	rectangle(40,80,620,350);
	rectangle(45,85,615,345);
	settextstyle(0,0,1);
     flag=0;
     outtextxy(65,110,"CUSTOMER NUMBER");


  	    do
	     {
	      setfillstyle(SOLID_FILL,CYAN);
	      bar(300,108,500,128);
	      gotoxy(40,8);
	      fflush(stdin);
	      gets(cust_num1);
		if(cust_num1[0]!='C' || strlen(cust_num1)!=5)
		   {
		    outtextxy(200,400,"INSERT CUSTOMER NO'C0001'!TRY AGAIN");
		    getch();
		    setfillstyle(SOLID_FILL,BLACK);
		    bar(170,390,500,410);
		   }
		else
		 for(i=1;cust_num1[i]!='\0';i++)
		  if(cust_num1[i]>=48 && cust_num1[i]<=57)
		     flag=1;
		 else
		   {
		    outtextxy(180,400,"INSERT CUSTOMER NO.'C0001'!TRY AGAIN");
		    getch();
		    setfillstyle(SOLID_FILL,BLACK);
		    bar(170,390,500,410);
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
		   outtextxy(200,400,"CYLINDER BOOKED ALREADY");
		   getch();
		   setfillstyle(SOLID_FILL,BLACK);
		   bar(170,390,500,410);
		   flag1=1;
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
		   outtextxy(200,400,"CYLINDER BOOK AFTER 20 DAYS");
		   getch();
		   setfillstyle(SOLID_FILL,BLACK);
		   bar(170,390,500,410);
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
	   itoa(d.da_year,str,10);
	   strcat(ref.book_date,str);
	    setcolor(3);
	     flag=0;
	     do
	      {
	       setfillstyle(SOLID_FILL,CYAN);
	       outtextxy(65,160,"URGENT (Y/N)");
	       gotoxy(40,11);
	       bar(303,159,323,179);
	       ref.urgent=getchar();
	       if(ref.urgent!='Y' && ref.urgent!='N')
		{
		 outtextxy(200,400,"ENTER 'Y' OR 'N'");
		 getch();
		 setfillstyle(SOLID_FILL,BLACK);
		 bar(190,390,420,410);
		}
	       else
		flag=1;
	       }while(flag==0);
	       if(ref.urgent=='Y'||ref.urgent=='y')
		 ref.prior_num=1;
	       else
		 ref.prior_num=0;
	       flag=0;
		outtextxy(65,200,"DO YOU WANT TO SAVE BOOKING (Y/N)");
		do
		 {
		  setfillstyle(SOLID_FILL,CYAN);
		  gotoxy(50,13);
		  bar(387,190,407,215);
		  fflush(stdin);
		  ch=getchar();
		   if((ch!='Y' && ch!='N'))
		     {
		      outtextxy(200,400,"ENTER (Y/N)");
		      getch();
		      setfillstyle(SOLID_FILL,BLACK);
		      bar(190,390,420,410);
		     }
		   else
		     flag=1;
		 }while(flag==0);
		 clearviewport();
		if(ch=='y' || ch=='Y')
		 {
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
		  rectangle(50,50,620,400);
		  setcolor(10);
		  outtextxy(100,100,"SAVE DATA IS:-");
		  setcolor(3);
		  x1=120;y1=120;
		  gprint(&x1,&y1,"BOOKING NUMBER %d",ref.book_num);
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
		    gprint(&x1,&y1,"URGENT  %c",ref.urgent);
		    gprint(&x1,&y1,"PRIORTY NUMBER %d",ref.prior_num);
		    fp1=fopen("REF.TXT","rb+");
		  }
		}
	    }
	   }
		flag=0;
		outtextxy(120,275,"DO YOU WANT MORE BOOKING (Y/N)");
		do
		{
		 setfillstyle(SOLID_FILL,CYAN);
		 gotoxy(50,18);
		 bar(383,270,403,290);
		 fflush(stdin);
		 choice=getchar();
		  if(choice!='Y'&& choice!='N')
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
	       }
	    fclose(fp1);
	    fclose(fp2);
	   }

//FUNCTION FOR ADDITION OF COMPLAIN FROM CUSTOMER

   void comp_cust()
	{
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	char cust_num1[15],choice='Y',ch,ch1;
	
        
        int flag,flag1,flag2,i;
	   fp1=fopen("COMP.TXT","rb+");
	     if(fp1==NULL)
	      {
	       fp1=fopen("COMP.TXT","wb+");
	      } 
	   fp2=fopen("CUST.TXT","rb");
	   fp3=fopen("STOCK.TXT","rb+");
	   while(choice=='Y')
	    {
	    setcolor(10);
	    settextstyle(7,0,1);
	    setusercharsize(1,1,1,2);
	    outtextxy(35,20,"WELCOME TO COMPLAIN MENU");
	    line(10,65,620,65);
	    setcolor(3);
	    setfillstyle(SOLID_FILL,CYAN);
	    rectangle(40,80,620,385);
	    rectangle(45,85,615,380);
	    settextstyle(0,0,1);
	    flag=0;
	    outtextxy(65,100,"ENTER '1' FOR COMPLAIN AND '2' FOR RECOVERY");
	    do
	     {
	      setfillstyle(SOLID_FILL,CYAN);
	      fflush(stdin);
	      gotoxy(58,7);
	      bar(450,92,480,118);
	      ch1=getchar();
		if(ch1=='1' || ch1=='2')
		 flag=1;
	       else
		 {
		   outtextxy(200,400,"ENTER (Y/N)");
		   getch();
		   setfillstyle(SOLID_FILL,BLACK);
		   bar(190,390,420,410);
		  }
	       }while(flag==0);
	       flag=0;
	   if(ch1=='1')
	     {
	     outtextxy(65,130,"CUSTOMER NUMBER");
	     do
	      {
	      setfillstyle(SOLID_FILL,CYAN);
	      bar(300,125,430,150);
	      
           
           gotoxy(40,9);
	      fflush(stdin);
	      gets(cust_num1);
		  if(cust_num1[0]!='C')
		   {
		   outtextxy(200,400,"INVALID CUSTOMER NO'C0001'!TRY AGAIN");
		   getch();
		   }
		else
		{
		 for(i=1;cust_num1[i]!='\0';i++)
		  if(cust_num1[i]>=48 && cust_num1[i]<=57)
		   flag=1;
		   else
		   {
		   outtextxy(200,400,"INVALID CUSTOMER NO!TRY AGAIN");
		   getch();
		   break;
		   }
		  }
		  setfillstyle(SOLID_FILL,BLACK);
		  bar(170,390,500,410);
		   }while(flag==0);
	    flag1=0;
	    while(fread(&cust,sizeof(cust),1,fp2)==1)
	    if(strcmpi(cust.cust_no,cust_num1)==0)
	    {
	      flag1=1;
	      break;
	    }
	    if(flag1==0)
	     {
	      outtextxy(200,400,"CUSTOMER NUMBER NOT FOUND");
	      getch();
	      setfillstyle(SOLID_FILL,BLACK);
	       bar(170,390,500,410);
	    }
	    flag2=0;
	   while(fread(&comp,sizeof(comp),1,fp1)==1)
	     if(strcmpi(comp.cust_num,cust_num1)==0)
	       {
		if(comp.status=='N')
		{
		 outtextxy(200,400,"BOOKING ALREADY MADE");
		 flag2=1;
		 getch();
		 setfillstyle(SOLID_FILL,BLACK);
		 
           bar(170,390,500,410);
		}
        }
	      strcpy(comp.cust_num,cust_num1);
	      comp.status='N';
	      comp.r_cyl='N';
	      if(flag1==1)
	       {
	      if(flag2==0)
	       {
		    outtextxy(65,205,"DO YOU WANT TO SAVE DATA");
		   do
		    {
		    setfillstyle(SOLID_FILL,CYAN);
		    bar(348,204,380,225);
		    fflush(stdin);
		    gotoxy(46,14);
		    ch=getchar();
	       if(ch!='Y'&& ch!='N')
		   {
		   outtextxy(200,400,"ENTER (Y/N)");
		   getch();
		   setfillstyle(SOLID_FILL,BLACK);
		   bar(190,390,420,410);
		  }
		  else
		     flag=1;
	     }while(flag==0);
	    }
	     if(ch=='Y')
	      fwrite(&comp,sizeof(comp),1,fp1);
	  }
	}
     if(ch1=='2')
	 {
	  outtextxy(65,130,"CUSTOMER NUMBER");
	    do
	     {
	      setfillstyle(SOLID_FILL,CYAN);
	      bar(300,125,500,150);
	      gotoxy(40,9);
	      fflush(stdin);
	      gets(cust_num1);
		if(cust_num1[0]!='C')
		   {
		   outtextxy(200,400,"INVALID CUSTOMER NO'C'!TRY AGAIN");
		   getch();
		   }
		else
		{
		 for(i=1;cust_num1[i]!='\0';i++)
		  if(cust_num1[i]>=48 && cust_num1[i]<=57)
		   flag=1;
		  else
		   {
		   outtextxy(200,400,"INVALID CUSTOMER NO!TRY AGAIN");
		   getch();
		   break;
		   }
		  }
		  setfillstyle(SOLID_FILL,BLACK);
		  bar(170,390,500,410);
	       }while(flag==0);
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
		outtextxy(65,200,"ENTER 'Y' FOR RETURN OF REFILL OR 'N' FOR NO");
		 do
		   {
		    setfillstyle(SOLID_FILL,CYAN);
		    bar(420,188,460,218);
		    fflush(stdin);
		    gotoxy(55,13);
		    comp.r_cyl=getchar();
		       if(comp.r_cyl!='Y'&&comp.r_cyl!='N')
		       {
			 outtextxy(200,400,"ENTER (Y/N)");
			 getch();
			 setfillstyle(SOLID_FILL,BLACK);
			 bar(190,390,420,410);
			}
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
	     }
	      outtextxy(65,298,"DO YOU WANT BOOKING OF MORE COMPLAIN");
	  do
	    {
		setfillstyle(SOLID_FILL,CYAN);
		bar(378,286,408,312);
		fflush(stdin);
		gotoxy(50,19);
		choice=getchar();
		 if(choice!='Y'&& choice!='N')
		   {
		    outtextxy(200,400,"ENTER (Y/N)");
		    getch();
		    setfillstyle(SOLID_FILL,BLACK);
		    bar(200,390,420,410);
		  }
		  else
		    {
		     flag=1;
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
	   fclose(fp1);
	   fclose(fp2);
	  }
	
//FUNCTION FOR  RELEASING OF REFILL

void rel_cust()
	
    
   {
	char ch,choice='y';
	int book_num1,book,n,x1,y1,i,k,prior;
	char str[10],vouc_num1[6],vouc_num2[6],vouc_num3[6];
	char book_date[8],cust_num[6],l_date[8],urgent,status;
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
	    setcolor(10);
	    settextstyle(7,0,1);
	    setusercharsize(1,1,1,2);
	    outtextxy(35,20,"WELCOME TO DISPATCH MENU");
	    line(10,65,620,65);
	    setcolor(3);
	    setfillstyle(SOLID_FILL,CYAN);
	    rectangle(40,80,620,385);
	    rectangle(45,85,615,380);
	    settextstyle(0,0,1);
	       flag=0;
	       outtextxy(55,90,"ENTER YOUR DATA");
	       outtextxy(65,110,"BOOKING NUMBER");
	      do
	       {
	      setfillstyle(SOLID_FILL,CYAN);
	      bar(300,108,400,128);
	      gotoxy(40,8);
	      fflush(stdin);
	      scanf("%d",&book_num1);
		    book=isdigit(book_num1);
		       if(book==0)
		       flag=1;
		       else
			 {
			  outtextxy(200,400,"INVALID BOOK NO!TRY AGAIN");
			  getch();
			  setfillstyle(SOLID_FILL,BLACK);
			  bar(190,390,420,410);
			 }
		      }while(flag==0);
		 flag=0;
		 flag1=0;
		 fseek(fp1,0,SEEK_SET);
		 while(fread(&ref,sizeof(ref),1,fp1)==1)
		  if(ref.book_num==book_num1)
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
			  i=1;k=0;
			  while(vouc_num1[i]!='\0')
			   vouc_num3[k++]=vouc_num1[i++];
			    vouc_num3[k]='\0';
			while(fread(&ref,sizeof(ref),1,fp1)==1)
			 {
			  strcpy(vouc_num2,ref.vouc_num);
			  i=1;k=0;
			    while(vouc_num2[i]!='\0')
				 vouc_num2[k++]=vouc_num2[i++];
				  vouc_num2[k]='\0';
			 if((atoi(vouc_num2)) >= (atoi(vouc_num3)))
			     strcpy(vouc_num1,ref.vouc_num);
			  }
	
     
             i=1,k=0;
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
		   if(ref.book_num!=book_num1)
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
		
          
              x1=65,y1=190;
		    gprint(&x1,&y1,"URGENT (Y/N):   %c",ref.urgent);
		    gprint(&x1,&y1,"PRIORTY NUMBER: %d",ref.prior_num);
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
			 ref.status='N';
		      else
			 ref.status='A';
		      status=ref.status;
		      x1=65,y1=230;
		      gprint(&x1,&y1,"STATUS %c",ref.status);
		      if(ref.status=='A')
		       {
			outtextxy(300,250,vouc_num1);
			strcpy(ref.vouc_num,vouc_num1);
	   if(ref.prior_num==1)
	   {
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
	   itoa(d.da_year,str,10);
	   strcat(ref.vouc_date,str);
	    }
		outtextxy(300,270,ref.vouc_date);
		flag=0;
		outtextxy(65,290,"HAWKER OR VEHICLE NO OR BY CUST(1/2/3)");
		    setfillstyle(SOLID_FILL,CYAN);
		    bar(483,282,520,308);
		    fflush(stdin);
		    gotoxy(64,19);
		    ch=getchar();
		 if(ch=='1')
		   do
		   {
		    ref.supp_mode=3;
		    outtextxy(65,310,"ENTER HAWKER NUMBER");
		    setfillstyle(SOLID_FILL,CYAN);
		    fflush(stdin);
		    bar(380,302,470,325);
		    gotoxy(50,20);
		    gets(ref.hawk_num);
		    if(ref.hawk_num[0]!='H'|| strlen(ref.hawk_num)!=4)
		       {
		       outtextxy(200,400,"INVALID NO'H001'!TRY AGAIN");
			getch();
			setfillstyle(SOLID_FILL,BLACK);
			bar(190,390,520,410);
		       }
		     else
		      {
		       for(i=1;i<=3;i++)
			 if(ref.hawk_num[i]>=48 && ref.hawk_num[i]<=57)
			    flag=1;
			  else
			  {
			   outtextxy(200,400,"INVALID NO'H001'!TRY AGAIN");
			   flag=0;
			   getch();
			   setfillstyle(SOLID_FILL,BLACK);
			   bar(190,390,520,410);
			  }
		       }
		     }while(flag==0);
		 else
		    if(ch=='2')
		     {
		     outtextxy(65,310,"ENTER VEHICLE NUMBER");
		     setfillstyle(SOLID_FILL,CYAN);
		     bar(380,302,470,325);
		     gotoxy(51,20);
		     fflush(stdin);
		     gets(ref.vehi_no);
		     ref.supp_mode=2;
		     }
		else
		 if(ch!='1'|| ch!='2')
		 {
		 strcpy(ref.hawk_num,"NULL");
		 strcpy(ref.vehi_no,"NULL");
		 ref.supp_mode=1;
		}
	       x1=65,y1=330;
	      if(ref.supp_mode==1)
		  outtextxy(x1,y1,"SELF BY CUSTOMER");
	      if(ref.supp_mode==2)
		  outtextxy(x1,y1,"BY DELIVERY VAN:");
	     if(ref.supp_mode==3)
		  outtextxy(x1,y1,"HAWKER THROUGH  BICYCLE");
		    ref.book_num=book_num1;
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
		   outtextxy(65,350,"PRESS ANY KEY TO CONTINUE...");
		   getch();
	       }
		else
		 {
		  outtextxy(200,400,"CYLINDER OUT OF STOCK");
		  getch();
		  setfillstyle(SOLID_FILL,BLACK);
		  bar(190,390,460,410);
		  fclose(fp2);
		 }
	      }
		 fclose(fp1);
		 fclose(fp3);
		remove("REF.TXT");
		rename("TEMP.TXT","REF.TXT");
	       fp1=fopen("REF.TXT","rb+");
	    }
	       clearviewport();
	       rectangle(70,80,520,150);
	       outtextxy(100,100,"DO YOU WANT MORE FORMS FOR DELIVERY (Y/N)");
	       flag=0;
	       do
	       {
		  setfillstyle(SOLID_FILL,CYAN);
		  bar(460,95,480,122);
		  fflush(stdin);
		  gotoxy(59,7);
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
		 rewind(fp1);
		}
	    fclose(fp1);
	    }

