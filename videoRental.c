#pragma warning(disable:4996)
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define Max_name_len 30
#define Def_fname "Video.cau"
#define Max_Customer 30
#define Max_Video 30

typedef struct  _Rental_Return Rental_Return;
struct  _Rental_Return {
	int num;

	int returned;
	char Customer_Num;
	char RentalNum;
	int CusNum;
	int RentalDate[3];
	int Datetobereturned[3];
	int ReturnDate[3];
	int TotalLateFee;

};


typedef struct _Customer Customer;
struct _Customer {
	int num;

	char name[Max_name_len];
	char Social_Security_Number[Max_name_len];
	char phone_Number[Max_name_len];
	char add[Max_name_len];
};


typedef struct _Video Video;
struct _Video {
	int num;

	char name[Max_name_len];
	char genre[Max_name_len];
	char Rental_Fee[Max_name_len];
	char Register_date[Max_name_len];
	int Returned;
	int Latefee;

};




Customer *custom[Max_Customer];
Video*video[Max_Video];
Rental_Return*rrurn[Max_Video];
int totalNum = 0;
void Init();
void Run();
void Exit();

int main()
{
	Init();
	Run();
	Exit();
	system("pause");
	return 0;
}

void Init()
{
	FILE *fp = fopen(Def_fname, "r");
	if (fp)
	{
		int i = 0;
		while (1)
		{
			if (fread(&i, sizeof(int), 1, fp) < 1)
			{
				break;
			}
			custom[i] = (Customer *)malloc(sizeof(Customer));
			fread(custom[i], sizeof(Customer), 1, fp);

		}
		i = 0;
		while (1)
		{
			if (fread(&i, sizeof(int), 1, fp) < 1)
			{
				break;
			}
			video[i] = (Video *)malloc(sizeof(Video));
			fread(video[i], sizeof(Video), 1, fp);

		}

		i = 0;
		while (1)
		{
			if (fread(&i, sizeof(int), 1, fp) < 1)
			{
				break;
			}
			rrurn[i] = (Rental_Return *)malloc(sizeof(Rental_Return));
			fread(rrurn[i], sizeof(Rental_Return), 1, fp);

		}
		fclose(fp);
	}
}

int SelectMenu();

void NCustomRegis();

void FindCustomer();
void Fullview();


void NVideoRegis();


void FindVideo();
void VideoFullview();

void RentalServie();
void ReturnService();
void Closing();

void Run() {
	int key = 0;
	while ((key = SelectMenu()) != 0) {

		switch (key) {
		case 1:	NCustomRegis(); break;
		case 2: FindCustomer(); break;
		case 3: Fullview(); break;
		case 4: NVideoRegis(); break;
		case 5:FindVideo(); break;
		case 6: VideoFullview(); break;
		case 7:RentalServie(); break;
		case 8:ReturnService(); break;

		default: printf("No number. \n"); break;
		}
	}
}


int getnum();
int SelectMenu() {
	system("cls");
	printf("Video rental Management Program 0:Exit \n");
	printf(" 1:NewCustomer Registeration \n 2:Customer information inquiary \n 3:Vie all customer information \n 4: New video registeration \n 5: View video information \n 6: View full video information \n 7:Rental service \n 8:Return service \n");
	printf("\n------------------------------ \n------------------------------ \n");
	return getnum();
}

int getnum() {
	int num = 0;
	if (scanf_s("%d", &num) == 0)
	{
		char buf[256];
		gets_s(buf, sizeof(buf));
	}
	return num;
}

void NCustomRegis() {
	int num = 0;
	Customer *bui = 0;
	printf("Customer number to add(1-%d):", Max_Customer);
	num = getnum();

	if ((num < 1) || (num > Max_Customer))
	{
		printf("Out of range.\n");
		return;
	}
	bui = custom[num - 1];
	if (bui) {
		printf("THere are already materials. \n");
		return;
	}
	bui = (Customer*)malloc(sizeof(Customer));
	bui->num = num;
	printf("Name: ");
	scanf_s("%s", bui->name, Max_name_len);
	printf("Social Security Number: ");
	scanf_s("%s", bui->Social_Security_Number, Max_name_len);
	printf("Phone Number: ");
	scanf_s("%s", bui->phone_Number, Max_name_len);
	printf("Customer ADDRESS: ");
	scanf_s("%s", bui->add, Max_name_len);


	custom[num - 1] = bui;
}



void ViewCus(Customer*bui);
void FindCustomer() {
	int num = 0;
	Customer *bui = 0;

	printf("검색할 고객 번호(1-%d): ", Max_Customer);
	num = getnum();
	if ((num < 1) || (num > Max_Customer))

	{
		printf("Customer number to search.\n");
		return;
	}

	bui = custom[num - 1];
	if (bui == 0)
	{
		printf("Customer data not added. Please add customer data first.\n");
		return;
	}
	ViewCus(bui);
	system("pause");

}

void ViewCus(Customer*bui)
{

	printf("\n");
	printf("=== customer name: %s\n", bui->name);
	printf("=== department name: %s\n", bui->Social_Security_Number);
	printf("=== phone Number: %s\n", bui->phone_Number);
	printf("=== customer address: %s\n", bui->add);

}

void Fullview() {
	int i = 0;
	for (i = 0; i < Max_Customer; i++)
	{
		if (custom[i])
		{
			printf("Number[%d]", i + 1);
			ViewCus(custom[i]);
		}
	}
	system("pause");
}


void NVideoRegis() {
	int num = 0;
	Video *bui = 0;
	Rental_Return *ren = 0;
	printf("Video number to add(1-%d):", Max_Video);
	num = getnum();

	if ((num < 1) || (num > Max_Video))
	{
		printf("Out of range.\n");
		return;
	}
	bui = video[num - 1];
	if (bui) {
		printf("THere are already materials. \n");
		return;
	}
	bui = (Video*)malloc(sizeof(Video));
	bui->num = num;
	ren = (Rental_Return*)malloc(sizeof(Rental_Return));
	ren->num = num;
	ren->returned = 0;
	printf("Name: ");
	scanf_s("%s", bui->name, Max_name_len);
	printf("genre of the Video: ");
	scanf_s("%s", bui->genre, Max_name_len);
	printf("Rental fee for the video: ");
	scanf_s("%s", bui->Rental_Fee, Max_name_len);
	printf("Register date: ");
	scanf_s("%s", bui->Register_date, Max_name_len);
	printf("Late Fee for this video:");
	scanf("%d", &bui->Latefee);
	bui->Latefee = ren->returned;
	video[num - 1] = bui;
	rrurn[num - 1] = ren;
	totalNum++;

	system("pause");

}



void ViewVi(Video*bui, Rental_Return*ren);
void FindVideo() {
	int num = 0;
	Video *bui = 0;
	Rental_Return *ren = 0;

	printf("검색할 해당 비디오 번호(1-%d): ", Max_Video);
	num = getnum();
	if ((num < 1) || (num > Max_Video))

	{
		printf("Video number to search.\n");
		return;
	}

	bui = video[num - 1];
	ren = rrurn[num - 1];
	if (bui == 0)
	{
		printf("Video data not added. Please add video data first.\n");
		return;
	}
	ViewVi(bui, ren);
	system("pause");

}

void ViewVi(Video*bui, Rental_Return*ren)
{

	printf("\n");
	printf("=== Video name: %s\n", bui->name);
	printf("=== genre of the Video: %s\n", bui->genre);
	printf("=== Rental Fee: %s\n", bui->Rental_Fee);
	printf("=== Register Date: %s\n", bui->Register_date);
	printf("=== rented or not: %d\n", ren->returned);
	printf("=== late fee for this video: %d\n", bui->Latefee);


}

void VideoFullview() {
	int i = 0;
	for (i = 0; i < Max_Video; i++)
	{
		if (video[i])
		{
			printf("Number[%d]", i + 1);
			ViewVi(video[i], rrurn[i]);
		}
	}
	system("pause");
}

void RentalServie() {
	;
	int numvi = 0;
	int numcus = 0;
	printf("videos you can rent now");
	for (int i = 0; i < totalNum; i++) {
		if (rrurn[i]->returned == 0)
		{
			printf(" \n %d", i + 1);
			ViewVi(video[i], rrurn[i]);
		}
	}

	printf("Enter the number of the video you want to rent:");
	scanf("%d", &numvi);
	rrurn[numvi - 1]->returned = 1;
	printf("Rental date: year:");
	scanf("%d", &rrurn[numvi - 1]->RentalDate[0]);
	printf("month:");
	scanf("%d", &rrurn[numvi - 1]->RentalDate[1]);
	printf(" day:");
	scanf("%d", &rrurn[numvi - 1]->RentalDate[2]);
	printf("\n");
	printf("Date to be return");
	rrurn[numvi - 1]->Datetobereturned[0] = rrurn[numvi - 1]->RentalDate[0];
	rrurn[numvi - 1]->Datetobereturned[1] = rrurn[numvi - 1]->RentalDate[1];
	int k = 0;
	k = rrurn[numvi - 1]->RentalDate[2] + 7;
	rrurn[numvi - 1]->Datetobereturned[2] = k;

	printf("Retrun date \nyear:%d month:%d day:%d \n(it have to be returned in a week)\n", rrurn[numvi - 1]->RentalDate[0], rrurn[numvi - 1]->RentalDate[1], rrurn[numvi - 1]->RentalDate[2]);
	printf("customer number:");
	scanf("%d", &numcus);
	rrurn[numvi - 1]->Customer_Num = numcus;
}
void ReturnService() {

	int numvi = 0;

	printf("videos needed to be returned");
	for (int i = 0; i < totalNum; i++) {
		if (rrurn[i]->returned == 1)
		{
			printf("\n %d \n", i + 1);
			ViewVi(video[i], rrurn[i]);
		}
	}

	printf("Enter the number of the video you want to return:");
	scanf("%d", &numvi);
	rrurn[numvi - 1]->returned = 0;
	printf("\n");
	printf("Return date: year:");
	scanf_s("%d", &rrurn[numvi - 1]->ReturnDate[0]);
	printf("month:");
	scanf("%d", &rrurn[numvi - 1]->ReturnDate[1]);
	printf(" day:");
	scanf("%d", &rrurn[numvi - 1]->ReturnDate[2]);
	printf("\n");
	int a = 0;
	a = rrurn[numvi - 1]->ReturnDate[2];
	int b = 0;
	b = rrurn[numvi - 1]->Datetobereturned[2];
	int c = 0;
	c = video[numvi - 1]->Latefee;
	if (a - b> 7)
	{
		printf("Return fee: %d", (a - b)*c);
	}
	system("pause");

}
void Exit()
{
	FILE *fp = fopen(Def_fname, "w");
	if (fp)
	{
		int i = 0;
		for (i = 0; i < Max_Customer; i++)
		{
			if (custom[i])
			{
				fwrite(&i, sizeof(int), 1, fp);
				fwrite(custom[i], sizeof(Customer), 1, fp);
				free(custom[i]);
			}
		}
		for (i = 0; i < Max_Video; i++)
		{
			if (video[i])
			{
				fwrite(&i, sizeof(int), 1, fp);
				fwrite(video[i], sizeof(Video), 1, fp);
				free(video[i]);
			}
		}
		for (i = 0; i < Max_Video; i++)
		{
			if (rrurn[i])
			{
				fwrite(&i, sizeof(int), 1, fp);
				fwrite(rrurn[i], sizeof(Rental_Return), 1, fp);
				free(rrurn[i]);
			}
		}
		fclose(fp);
	}
}