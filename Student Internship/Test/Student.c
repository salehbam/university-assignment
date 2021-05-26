#include<stdio.h>
int size = 0;
int ssn;
char name[50];
char surname[50];
char cellNo[20];
char email[50];
char homeAddress[200];
char city[20];
char company[50];
char companyAdress[200];
char companyLocation[50];
char companyPhone[20];
char companyEmail[20];
char beginningDate[20];
char endingDate[20];
int workdays;

void main()
{
	while (1) {
		int choice;
		printf("\n-------- Menu --------- \n");
		printf("1. Show list\n");
		printf("2. Show Student details\n");
		printf("3. Enter a student details\n");
		printf("0. To Exit.\n");
		scanf("%d", &choice);
		if (choice == 0)
		{
			return 0;
		}
		if (choice == 1) {
			showAll();
		}
		else if (choice == 2) {
			printf("Enter student Id: ");
			int id;
			scanf("%d", &id);
			show(id);
		}
		else {
			add();
		}
	}
	

}
void showAll() {
	if (size == 0) {
		printf("No Students in the list.\n");
		return;
	}
	printf("Id\t\tName\n");
	for (int i = 0; i < size; i++) {
		printf("&d\t\t%s.",i, name);
	}
}
void show(int id) {
	if (id >= size) {
		printf("No Student in the list.\n");
		return;
	}
	printf("School Number: %d\n", ssn);
	printf("Name: %s\n", name);
	printf("Surname: %s\n", surname);
	printf("Phone No: %s\n", cellNo);
	printf("Email: %s\n", email);
	printf("Home Address: %s\n",  homeAddress);
	printf("City: %s\n",  city);
	printf("Company: %s\n",  company);
	printf("Company Address: %s\n",  companyAdress);
	printf("Company location: %s\n",  companyLocation);
	printf("Company phone no: %s\n",  companyPhone);
	printf("Company email: %s\n",  companyEmail);
	printf("Beginning date: %s\n",  beginningDate);
	printf("Ending date: %s\n",  endingDate);
	printf("Total work days: %d\n",  workdays);
}
void save() {
	FILE* fp = fopen("details.txt", "a");
	if (fp == NULL) {
		printf("File cant be created. Data is not saved.");
		return;
	}
	char str[10000];

	sprintf(str, "%d %s %s %s %s %s %s %s %s %s %s %s %s %s %d\n",  ssn,  name,
		 surname,  cellNo,  email,  homeAddress,  city,
		 companyAdress,  companyAdress,  companyLocation,  companyPhone,
		 companyEmail,  beginningDate,  endingDate,  workdays);
	fwrite(str, strlen(str), 1, fp);
	fclose(fp);
}
void add() {
	printf("Enter Details\n");
	printf("School Number: ");
	scanf("%d", ssn);
	getchar();
	printf("Name: ");
	fgets( name, sizeof( name), stdin);
	strtok( name, "\n");
	printf("Surname: ");
	fgets( surname, sizeof( surname), stdin);
	strtok( name, "\n");
	printf("Phone No: ");
	fgets( cellNo, sizeof( cellNo), stdin);
	strtok( name, "\n");
	printf("Email: ");
	fgets( email, sizeof( email), stdin);
	strtok( name, "\n");
	printf("Home Address: ");
	fgets( homeAddress, sizeof( homeAddress), stdin);
	strtok( name, "\n");
	printf("City: ");
	fgets( city, sizeof( city), stdin);
	strtok( name, "\n");
	printf("Company: ");
	fgets( company, sizeof( company), stdin);
	strtok( name, "\n");
	printf("Company Address: ");
	fgets( companyAdress, sizeof( companyAdress), stdin);
	strtok( name, "\n");
	printf("Company location: ");
	fgets( companyLocation, sizeof( companyLocation), stdin);
	strtok( name, "\n");
	printf("Company phone no: ");
	fgets( companyPhone, sizeof( companyPhone), stdin);
	strtok( name, "\n");
	printf("Company email: ");
	fgets( companyEmail, sizeof( companyEmail), stdin);
	strtok( name, "\n");
	printf("Beginning date DD/MM/YYYY: ");
	fgets( beginningDate, sizeof( beginningDate), stdin);
	strtok( name, "\n");
	printf("Ending date DD/MM/YYYY: ");
	fgets( endingDate, sizeof( endingDate), stdin);
	strtok( name, "\n");
	printf("Total work days: ");
	scanf("%d", & workdays);
	size++;
	save();
}
