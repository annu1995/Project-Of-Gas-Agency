typedef struct cust_data
	{
	char tel_no[12],cust_no[6],name[31];
	char add1[31],add2[31];
	char city[21];
	}cust_data;
cust_data cust;
typedef struct
	{
	char tv_num[7],tv_date[11],pga_code[11],cust_no[7],date_cust[11];
	char l_tran,cust_name[31],cust_add1[31],cust_add2[31],cust_city[21];
	char pga_name[31],pga_add1[31],pga_add2[31],pga_city[21],pga_stat[31];
	char pga_phon[12],cust_tel_no[12];
	}in_cust;
in_cust in_c;
typedef struct
	{
	char tv_num[8],tv_date[13],n_g_a_code[10],cust_no[6];
	char l_tran,cust_name[20],cust_add1[30],cust_add2[30],cust_city[20];
	char n_g_a_name[30],n_g_a_add1[30],n_g_a_add2[30],n_g_a_city[20],n_g_a_stat[30];
	char n_g_a_phon[12],cust_tel_no[12];
	}ou_cust;
ou_cust ou_c;
typedef struct
	{
	int book_num,prior_num,supp_mode;
	char book_date[11],l_s_date[11],vouc_date[11],vehi_no[8];
	char urgent,status,cust_num[7],vouc_num[7],hawk_num[5];
	}refill;
refill ref;
typedef struct
	{
	int no_cyl,no_fil_cyl,no_emp_cyl,no_def_cyl;
	float unit_rate;
	}st_cyl;
st_cyl static stock;
typedef struct
	{
	char cust_num[6],status,r_cyl;
	}comp_cyl;
comp_cyl comp;
void drsc()
{
setcolor(14);
rectangle(0,0,getmaxx(),getmaxy());
rectangle(5,5,getmaxx()-5,getmaxy()-5);
line(5,getmaxy()-40,getmaxx()-5,getmaxy()-40);
  }
  void sherr(char * msg)
  {
	  outtextxy(200,420,msg);
			getch();
			setfillstyle(SOLID_FILL,BLACK);
			bar(190,420,500,430);
			flag=0;
			}
  void ter()
   {
	 textbackground(BLACK);
	 textcolor(WHITE);
	 closegraph();
	 exit(0);
	 }
  void dt()
  {
	while(!kbhit())
       {
       flushall();
     _strtime(timebuf);
	 gotoxy(20,2);
printf("%s\t\t%s",datebuf,timebuf);
}
	fflush(stdin);
	}
	void mmsg(int x, char * mg)
	{
	setcolor(10);
settextstyle(7,0,1);
setusercharsize(1,1,1,2);
outtextxy(135,35,"INDIAN GAS AGENCY");
outtextxy(x,55,mg);
settextstyle(0,0,1);
outtextxy(80,450,"USE UP AND DOWN ARROW KEY TO MOVE AND ENTER KEY TO SELECT");
	  }
	   void wmsg(int x, char * mg)
		{
	setcolor(10);
settextstyle(7,0,1);
setusercharsize(1,1,1,2);
outtextxy(135,35,"INDIAN GAS AGENCY");
outtextxy(x,55,mg);
settextstyle(0,0,1);
outtextxy(200,450,"PRESS ESC KEY TO CLOSE SCREEN");
	  }


	  void sz(int l)
	  {
	  bsize=imagesize(a,b,a+l,b+16);
bars=malloc(bsize);
getimage(a,b,a+l,b+16,bars);
		 }
void fail()
	{
				clearviewport();
				gotoxy(25,10);
				printf("MAXIMUM ATTEMPTS FAILS");
				gotoxy(25,11);
				printf("SECURITY BREACK PRESUMED");
				gotoxy(29,12);
				printf("APPLICATION EXIT");
				while(!kbhit())
				{
				_strtime(timebuf);
				gotoxy(1,1);
				printf("Date :%s\t\tTime :%s\t\t\tPRESS ANY KEY TO EXIT",datebuf,timebuf);
				}
				clearviewport();
				textbackground(BLACK);
				textcolor(WHITE);
				closegraph();
				exit(0);
				}
void shrec()
{
			gotoxy(16,10);
			printf("CUSTOMER NAME");
			gotoxy(45,10);
			printf("%s",cust.name);
			delay(200);
			gotoxy(16,11);
			printf("CUSTOMER ADDRESS '1'");
			gotoxy(45,11);
			printf("%s",cust.add1);
			delay(200);
			gotoxy(16,12);
			printf("CUSTOMER ADDRESS '2'");
			gotoxy(45,12);
			printf("%s",cust.add2);
			delay(200);
			gotoxy(16,13);
			printf("CUTOMER CITY");
			gotoxy(45,13);
			printf("%s",cust.city);
			delay(200);
			gotoxy(16,14);
			printf("CUSTOMER TELEPHONE NUMBER");
			gotoxy(45,14);
			printf("%s",cust.tel_no);
			flag=1;
			delay(200);
		       //	break;
	    }
	    void increc()
		{
			gotoxy(16,10);
			printf("Transfer Voucher No.");
			gotoxy(45,10);
			printf("%s",in_c.tv_num);
			gotoxy(16,11);
			printf("Transfer Voucher Date.");
			gotoxy(45,11);
			printf("%s",in_c.tv_date);
			gotoxy(16,12);
			printf("Local Transfer.");
			gotoxy(45,12);
			printf("%c",in_c.l_tran);
			gotoxy(16,13);
			printf("Customer Name");
			gotoxy(45,13);
			printf("%s",in_c.cust_name);
			gotoxy(16,14);
			printf("Customer Address 1");
			gotoxy(45,14);
			printf("%s",in_c.cust_add1);
			gotoxy(16,15);
			printf("Customer Address 2");
			gotoxy(45,15);
			printf("%s",in_c.cust_add2);
			gotoxy(16,16);
			printf("Customer City");
			gotoxy(45,16);
			printf("%s",in_c.cust_city);
			gotoxy(16,17);
			printf("Customer Telephone No.");
			gotoxy(45,17);
			printf("%s",in_c.cust_tel_no);
			gotoxy(16,18);
			printf("Previous Agency Code");
			gotoxy(45,18);
			printf("%s",in_c.pga_code);
			gotoxy(16,19);
			printf("Previous Agency Name");
			gotoxy(45,19);
			printf("%s",in_c.pga_name);
			gotoxy(16,20);
			printf("Previous Agency Address 1");
			gotoxy(45,20);
			printf("%s",in_c.pga_add1);
			gotoxy(16,21);
			printf("Previous Agency Address 2");
			gotoxy(45,21);
			printf("%s",in_c.pga_add2);
			gotoxy(16,22);
			printf("Previous Agency City");
			gotoxy(45,22);
			printf("%s",in_c.pga_city);
			gotoxy(16,23);
			printf("Previous Agency Stat");
			gotoxy(45,23);
			printf("%s",in_c.pga_stat);
			gotoxy(16,24);
			printf("Previous Agency Telephone No.");
			gotoxy(45,24);
			printf("%s",in_c.pga_phon);
			gotoxy(16,25);
			printf("Customer Assigne Date");
			gotoxy(45,25);
			printf("%s",in_c.date_cust);
				flag=1;
			     }
void otcrec()
		{
			gotoxy(16,10);
			printf("Transfer Voucher No.");
			gotoxy(45,10);
			printf("%s",ou_c.tv_num);
			gotoxy(16,11);
			printf("Transfer Voucher Date.");
			gotoxy(45,11);
			printf("%s",ou_c.tv_date);
			gotoxy(16,12);
			printf("Local Transfer.");
			gotoxy(45,12);
			printf("%c",ou_c.l_tran);
			gotoxy(16,13);
			printf("Customer Name");
			gotoxy(45,13);
			printf("%s",ou_c.cust_name);
			gotoxy(16,14);
			printf("Customer Address 1");
			gotoxy(45,14);
			printf("%s",ou_c.cust_add1);
			gotoxy(16,15);
			printf("Customer Address 2");
			gotoxy(45,15);
			printf("%s",ou_c.cust_add2);
			gotoxy(16,16);
			printf("Customer City");
			gotoxy(45,16);
			printf("%s",ou_c.cust_city);
			gotoxy(16,17);
			printf("Customer Telephone No.");
			gotoxy(45,17);
			printf("%s",ou_c.cust_tel_no);
			gotoxy(16,18);
			printf("New Agency Code");
			gotoxy(45,18);
			printf("%s",ou_c.n_g_a_code);
			gotoxy(16,19);
			printf("New Agency Name");
			gotoxy(45,19);
			printf("%s",ou_c.n_g_a_name);
			gotoxy(16,20);
			printf("New Agency Address 1");
			gotoxy(45,20);
			printf("%s",ou_c.n_g_a_add1);
			gotoxy(16,21);
			printf("New Agency Address 2");
			gotoxy(45,21);
			printf("%s",ou_c.n_g_a_add2);
			gotoxy(16,22);
			printf("New Agency City");
			gotoxy(45,22);
			printf("%s",ou_c.n_g_a_city);
			gotoxy(16,23);
			printf("New Agency Stat");
			gotoxy(45,23);
			printf("%s",ou_c.n_g_a_stat);
			gotoxy(16,24);
			printf("New Agency Telephone No.");
			gotoxy(45,24);
			printf("%s",ou_c.n_g_a_phon);
			gotoxy(16,25);
			flag=1;
			 }


void msg(char *ms)
{
gotoxy(35,25);
printf("Press any key to Countinue...");
		 while(!kbhit())
		 {
	gotoxy(35,24);
printf("%s",ms);
delay(200);
gotoxy(35,24);
printf("                 ");
delay(200);
}
}
     void wel()
	{
	int i,k=0,j=100;
	char arr[]={"INDIANGASAGENCY"},arr1[2];
	settextstyle(10,0,1);
	setusercharsize(3, 1, 1, 1);
	setcolor(2);
for(i=0;arr[i]!='\0';i++)
	{
	arr1[k++]=arr[i];
	arr1[k]='\0';
	if(i<=5)
		outtextxy(j,40,arr1);
	else
		if(i>=6 && i<=8)
		outtextxy(j,130,arr1);
	   else
	if(i>=9)
		outtextxy(j,220,arr1);
	if(i==4)
		j+=95;
	else
	if(i==5)
		j=200;
	else
	if(i==8)
		j=75;
	else
	if(i==0 || i==3)
		j+=35;
	else
		j+=85;
	k=0;
	}
	}