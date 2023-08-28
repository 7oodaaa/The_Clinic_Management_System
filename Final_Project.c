/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mahmoud Yasser
 * @brief          : Clinic Management System
 ******************************************************************************
 */

/* ********************** Includes Section Start ********************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* ********************** Includes Section End   ********************** */

/* ********************** Macro Section Start ************************* */
#define MAX_NAME_LENGTH 50
/* ********************** Macro Section End   ************************* */

/* ********************** Global Decleration Section Start ************* */
typedef struct Patient {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    int id;
    struct Patient* next;
} Patient;
typedef struct Slot {
    int slotNumber;
    int PatientId;
    struct Slot* next;
} Slot;
/* ********************** Global Decleration  Section End   ************ */

/* ********************** Global Variables Section Start ************** */
Patient* clinicPatients = NULL;
Slot* ReservedSlots = NULL;
/* ********************** Global Variables  Section End   ************* */

/* ********************** Sub-Program Declerations Section Start ******* */
void ClearScreen();
void ExitProgram();
void SelectMode();
void AdminMode();
void UserMode();
void AddPatient();
bool FindPatient(int id);
void EditPatient();
bool FindSlot(int SlotNum);
bool FindPatientReserveSlot(int PatientId);
void DisplayAvailableSlots();
void ReserveSlot();
void CancelReservation();
void ViewPatientRecord();
void ViewReservations();
Slot* CreateSlot(int SlotNum ,int PatientId);
Patient* CreatePatient(const char* name, int age, char gender, int id);
/* ********************** Sub-Program Declerations Section End ******* */
int main(){
	
	ClearScreen();
    printf("Welcome to the Clinic Management System\n");
    SelectMode();
    return 0;
}
/* ********************** Sub-Program Section Start ************* */
void ClearScreen(){
	
	system("cls");
}
void ExitProgram(){
	
	printf("Exited Successfully!\n");
	exit(0);
}
void SelectMode(){
	int mode;
	while(1)
    {
    	printf("Please Select Mode:-\n");
    	printf("1. Admin Mode\n");
    	printf("2. User Mode\n");
    	printf("3. Exit\n");
    	printf("Enter Your Choice : ");
    	scanf("%d",&mode);
		ClearScreen();
    	switch(mode){
    	case 1:
    		AdminMode();
    		break;
    	case 2:
    		UserMode();
    		break;
    	case 3:
    		ExitProgram();
    		break;
    	default:
            printf("Invalid Choice. Please Try Again.\n");
    	}

    }
}
void AdminMode(){
	
	int times=0,password;
	for(times=0;times<3;)
	{
		printf("Please Enter Your Password : ");
		scanf("%d",&password);
		ClearScreen();
		if(password==1234)
		{
			printf("Login Successful!\n");
            break;
		}
		else
		{
			times++;
			printf("Incorrect Password. Please Try Again.\n");
			
		}
		
	}
	if(times==3)
	{
		printf("Too Many Incorrect Password Attempts. Exiting The Program.\n");
        ExitProgram();
	}
	int choice;
	while(1)
	{
		printf("Admin Mode:-\n");
        printf("1. Add New Patient Record\n");
        printf("2. Edit Patient Record\n");
        printf("3. Reserve a Slot With The Doctor\n");
        printf("4. Cancel Reservation\n");
        printf("5. Log Out\n");
		printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
		ClearScreen();
		switch (choice) {
            case 1:
                AddPatient();
                break;
            case 2:
                EditPatient();
                break;
            case 3:
                ReserveSlot();
                break;
            case 4:
                CancelReservation();
                break;
            case 5:
                printf("Logged out successfully!\n");
                SelectMode();
				break;
			case 6:
                ExitProgram();
				break;
            default:
                printf("Invalid Choice. Please Try Again.\n");
        }
	}
}
void UserMode(){
	
	int choice;
    while (1) 
	{
        printf("User Mode:-\n");
        printf("1. View patient record\n");
        printf("2. View today's reservations\n");
        printf("3. Log Out\n");
		printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
		ClearScreen();
        switch (choice) {
            case 1:
                ViewPatientRecord();
                break;
            case 2:
                ViewReservations();
                break;
            case 3:
                printf("Logged Out Successfully!\n");
                SelectMode();
				break;
			case 4:
                ExitProgram();
				break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
	
}
void AddPatient(){
	
	char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    int id;   
    printf("Enter patient information:\n");
    printf("Name: ");
	scanf("\n");
    scanf("%[^\n]s", name);
    printf("Age : ");
    scanf("%d", &age);
    printf("Gender (M/F): ");
    scanf(" %c", &gender);
    printf("ID  : ");
    scanf("%d", &id);
	if(FindPatient(id)==false)
	{
		Patient* newPatient = CreatePatient(name, age, gender, id);
		if (newPatient == NULL)
		{
			return;
		}

		if (clinicPatients == NULL)
		{
			clinicPatients = newPatient;
		}
		else 
		{
			Patient* current = clinicPatients;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newPatient;
		}
		ClearScreen();

		printf("Patient added successfully!\n");
	}
	else
	{
		ClearScreen();
		printf("ID Is Already Exists .\n");
		
	}

}
bool FindPatient(int id){
    Patient* current = clinicPatients;
    while (current != NULL) {
        if (current->id == id) {
            return true;
        }
        current = current->next;
    }

    return false;
}
void EditPatient(){
	
	int id;
	bool flag=false;
	printf("Please Enter Id : ");
	scanf("%d",&id);
	ClearScreen();
	if(FindPatient(id))
	{
		ClearScreen();
		Patient* current = clinicPatients;
		char name[MAX_NAME_LENGTH];
		int age;
		char gender;
		printf("Name: ");
		scanf("\n");
		scanf("%[^\n]s", name);
		printf("Age: ");
		scanf("%d", &age);
		printf("Gender (M/F): ");
		scanf(" %c", &gender);
		ClearScreen();
		while (current != NULL){
			if (current->id == id) 
				{
					strncpy(current->name, name, MAX_NAME_LENGTH);
					current->age=age;
					current->gender=gender;
					printf("Edited Successfully !\n");
					break;
				}
			current = current->next;
		}
			
	}
	else
	{
		printf("ID Is Not Exists .\n");
		
	}
	
	
}
bool FindSlot(int SlotNum){
    Slot* current = ReservedSlots;
    while (current != NULL) {
        if (current->slotNumber == SlotNum) {
            return true;
        }
        current = current->next;
    }

    return false;
}
bool FindPatientReserveSlot(int PatientId){
    Slot* current = ReservedSlots;
    while (current != NULL) 
	{
        if (current->PatientId == PatientId){
            return true;
        }
        current = current->next;
    }

    return false;
}
void DisplayAvailableSlots() {
    printf("Available Slots:-\n");
    for(int i=1;i<=5;i++)
    {
        if(FindSlot(i)==false)
        {
            switch (i) 
            {
            case 1:
                printf("1. 2    pm    To    2:30 pm\n");
                break;
            case 2:
                printf("2. 2:30 pm    To    3    pm\n");
                break;
            case 3:
                printf("3. 3    pm    To    3:30 pm\n");
                break;
            case 4:
                printf("4. 4    pm    To    4:30 pm\n");
                break;
            case 5:
                printf("5. 4:30 pm    To    5    pm\n");
                break;
            }
        }
    }

    
    
}
void ReserveSlot(){
    int PatientId,SlotNum;
    DisplayAvailableSlots();
    printf("Patient Id  : ");
    scanf("%d",&PatientId);
    printf("Slot Number : ");
    scanf("%d",&SlotNum);
	ClearScreen();
	if(FindPatient(PatientId)==true)
	{
		Slot *NewSlot=CreateSlot(SlotNum,PatientId);
		if (NewSlot == NULL)
		{
			return;
		}
		if(ReservedSlots==NULL)
		{
			ReservedSlots=NewSlot;
		}
		else
		{
			Slot* current=ReservedSlots;
			while(current->next != NULL)
			{
				current=current->next;
			}
			current->next = NewSlot;
		}
		printf("Slot Reserved Successfully!\n");
	}
	else
	{
		printf("Patient Id Is Not Exists .\n");
	}
    
    
}
void CancelReservation(){
	int PatientId;
	printf("Patient Id : ");
	scanf("%d",&PatientId);
	ClearScreen();
	if(FindPatient(PatientId)==true)
	{
		Slot* current = ReservedSlots;
		Slot* temp;
		if(FindPatientReserveSlot(PatientId))
		{
		    Slot* current = ReservedSlots;
			Slot* temp = NULL ;
			if (current != NULL && current->PatientId == PatientId) 
			{
				ReservedSlots = current->next;
				free(current);
				printf("Slot Canceled Successfully!\n");
				return;
			}
			
			while (current != NULL && current->PatientId != PatientId)
			{
				temp = current;
				current = current->next;
			}
			
			temp->next = current->next;
			free(current); 
			
			printf("Slot Canceled Successfully!\n");
	
		}
		
		else
		{
			printf("Patient is Not Reserved Slot .\n");
		}
		
	}
	else
	{
		printf("Patient Id is Not Exists .\n");
	}
	
	
	
}
void ViewPatientRecord(){
	
	int id;
	printf("Please Enter Id : ");
	scanf("%d",&id);
	ClearScreen();
	if(FindPatient(id))
	{
		Patient* current = clinicPatients;
		while (current != NULL)
		{
        if (current->id == id) 
			{
				printf("Name: %s\n", current->name);
				printf("Age: %d\n", current->age);
				printf("Gender: %c\n", current->gender);
				printf("ID: %d\n", current->id);
				int c;
				printf("Please Press 0 To Return ? ");
				scanf("%d",&c);
				if(c==0)
					ClearScreen();
				
				break;
			}
		current = current->next;
		}
	}
	else
	{
		printf("ID Is Not Exists .\n");
	}
	
}
void ViewReservations(){
	Slot* temp=ReservedSlots;
	printf("Reserved Slots:-\n");
	{
		while(temp!=NULL)
		{
			
			switch (temp->slotNumber) 
            {
            case 1:
                printf("Patient Id : %d\t2    pm    To    2:30 pm\n",temp->PatientId);
                break;
            case 2:
                printf("Patient Id : %d\t2:30 pm    To    3    pm\n",temp->PatientId);
                break;
            case 3:
                printf("Patient Id : %d\t3    pm    To    3:30 pm\n",temp->PatientId);
                break;
            case 4:
                printf("Patient Id : %d\t4    pm    To    4:30 pm\n",temp->PatientId);
                break;
            case 5:
                printf("Patient Id : %d\t4:30 pm    To    5    pm\n",temp->PatientId);
                break;
            }
			temp=temp->next;
			
        }
		
    }
	int c;
	printf("Please Press 0 To Return ? ");
	scanf("%d",&c);
	if(c==0)
		ClearScreen();
	
}
Slot* CreateSlot(int SlotNum ,int PatientId){
	Slot* NewSlot=(Slot*)malloc(sizeof(Slot));
	if (NewSlot == NULL) 
	{
        printf("Memory Allocation Failed. Cannot Create A New Slot.\n");
        return NULL;
    }
	NewSlot->slotNumber=SlotNum;
	NewSlot->PatientId=PatientId;
	NewSlot->next=NULL;
	
	return NewSlot;
	
}
Patient* CreatePatient(const char* name, int age, char gender, int id){
	
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (newPatient == NULL) {
        printf("Memory Allocation Failed. Cannot Create A New Patient.\n");
        return NULL;
    }

    strncpy(newPatient->name, name, MAX_NAME_LENGTH);
    newPatient->age = age;
    newPatient->gender = gender;
    newPatient->id = id;
    newPatient->next = NULL;

    return newPatient;
}
/* ********************** Sub-Program Section End ************* */
/*
 ******************************************************************************
 User          Date                 Brief
 ******************************************************************************
 7odaa    	 19Aug2023            All Project
*/
