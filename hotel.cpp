#include<windows.h>
#include<time.h>
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>



void addrecord();
void listrecord();
void editrecord();
void deleterecord();
void searchrecord();




struct CustomerDetails
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char checkin[10];
	char checkout[10];
}cus;



int main(){


char customername;
	char choice;

	system("cls");
    printf("  \n\n\n\n\n\n\n\t\t====== HOTEL DATABASE MANAGEMENT PROJECT ======\n\n\n\n\n\n");
    system("pause");


 system("cls");
	while (1)
	{
		system("cls");

		printf("  \n\t\t\t\t----MAIN MENU----\n\n\n\n");

		printf(" \n Option 1 >\tBook a room\n");

		printf(" \n Option 2 >\tView Customer Record\n");

		printf(" \n Option 3 >\tDelete Customer Record\n");

		printf(" \n Option 4 >\tSearch Customer Record\n");

		printf(" \n Option 5 >\tEdit Record\n");

		printf(" \n Option 6 >\tExit\n");


		   printf("\n\n\n\t\t\tPlease Enter Your Option: ");
                choice=_getche();





		switch(choice)
		{
			case '1':
				addrecord();break;
			case '2':
				listrecord();break;
			case '3':
				deleterecord();break;
			case '4':
				searchrecord();break;
			case '5':
				editrecord();break;
			case '6':
				system("cls");


				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n\t\t Press any key to continue");
				_getch();
		}
	}
}


void addrecord()
{
	FILE *f;
	char test;
	f=fopen("cusdetails.txt","a+");

	while(1)
	{



		system("cls");
		printf("\n\t\t\tEnter Customer Details\n\n");

		printf("Enter Room number >");
		scanf("%s",cus.roomnumber);
printf("\n");
		printf("Enter Name >");
		scanf("%s",cus.name);
		printf("\n");
		printf("Enter Address >");
		scanf("%s",cus.address);
		printf("\n");
		printf("Enter Phone Number >");
		scanf("%s",cus.phonenumber);
		printf("\n");
		printf("Enter Nationality >");
		scanf("%s",cus.nationality);
		printf("\n");
		printf("Enter Email >");
		scanf(" %s",cus.email);
		printf("\n");
		printf("Enter Checkin[date] >");
		scanf("%s",&cus.checkin);
		printf("\n");
		printf("Enter Checkout[date] >");
		scanf("%s",&cus.checkout);
		fwrite(&cus,sizeof(cus),1,f);


		printf("\n\n\t\t\t Room is successfully booked !!!\n\n");
		printf("\n Press ENTER key to EXIT \n\n\tANY OTHER KEY TO ADD ANOTHER CUSTOMER DETAILS\n");
		test=_getche();
		if(test==13)
			break;

	}
	fclose(f);
}




void listrecord()
{
	FILE *f;
	int i;
	int flag=1;

if((f=fopen("cusdetails.txt","r"))==0)
		exit(0);
	
system("cls");

	while(fread(&cus,sizeof(cus),1,f)==1)
	{
flag=0;
printf("\nROOM NO >%s \n\nNAME >%s \n\nADDRESS >%s \n\nPHONENUMBER >%s \n\nNATIONALITY >%s  \n\nEMAIL >%s  \n\nCheckin[date] >%s  \n\nCheckout[date] >%s\n\n",cus.roomnumber,cus.name , cus.address , cus.phonenumber ,cus.nationality ,cus.email,cus.checkin, cus.checkout);
for(i=0;i<50;i++)
		printf("-");
		printf("\n\n");
	}

if(flag==1)
{
printf("\n\n\tNOT FOUND!!!!!\n");
printf("\n\n ENTER TO CONTINUE");

	}
_getch();
	fclose(f);
}





void deleterecord()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("cusdetails.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Room Number to deleted from database: ");

	scanf("%s",roomnumber);
	while(fread(&cus,sizeof(cus),1,f)==1)
	{
		if(strcmp(cus.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
	
	}
	if(i==1)
	{
		printf("\n\n Records of Customer not found!!\n");

printf("\n\n ENTER TO CONTINUE");
		_getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("cusdetails.txt");
	rename("temp.txt","cusdetails.txt");
	printf("\n\nRecords Customer is successfully removed....");
	
	
	_getch();
}





void searchrecord()
{
    int i;
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("cusdetails.txt","r+");


	printf("Enter Room number of the customer to search : ");
	scanf("%s", roomnumber);
	while(fread(&cus,sizeof(cus),1,f)==1)
	{
		
		if(strcmp(cus.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\t\t\tRecord Found\n ");
			printf("\nRoom Number >\t%s",cus.roomnumber);
			printf("\nName >\t%s",cus.name);
			printf("\nAddress >\t%s",cus.address);
			printf("\nPhone number >\t%s",cus.phonenumber);
			printf("\nNationality >\t%s",cus.nationality);
			printf("\nEmail >\t%s",cus.email);
			printf("\nCheckin[date] >\t%s",cus.checkin);
			printf("\nCheckout[date] >\t%s\n",cus.checkout);
for(i=0;i<50;i++)
		printf("-");
		printf("\n\n");
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!!!\n");
		printf("\n\n ENTER TO CONTINUE");

	}
	_getch();
	fclose(f);
}








void editrecord()
{
	FILE *f;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(cus);
	if((f=fopen("cusdetails.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%s",roomnumber);
fflush(stdin);
	while(fread(&cus,sizeof(cus),1,f)==1)
	{
		if(strcmp(cus.roomnumber,roomnumber)==0)
		{
			k=0;
			printf("\nEnter Room Number >");
			gets(cus.roomnumber);
			printf("\nEnter Name >");

			scanf("%s",&cus.name);
			printf("\nEnter Address >");
			scanf("%s",&cus.address);
			printf("\nEnter Phone number >");
			scanf("%d",&cus.phonenumber);
			printf("\nEnter Nationality >");
			scanf("%s",&cus.nationality);
	
			printf("\nEnter Email >");
			scanf("%s",&cus.email);
			printf("\nEnter Checkin[date] >");
			scanf("%s",&cus.checkin);
			printf("\nEnter Checkout[date] >");
			scanf("%s",&cus.checkout);

			fseek(f,-size,SEEK_CUR);  //to go to desired position infile
			fwrite(&cus,size,1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		_getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	_getch();
}
}













