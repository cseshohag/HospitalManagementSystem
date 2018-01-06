#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
char privilage='\0';
void main_menu();
void menu_for_user();
class all
{
private:

struct address
{
int house;
char city[30];
char state[30];
char street[30];
char country[30];
};

struct patient_info
{
address AD1;
int sex;
int reg_no;
int bld_group;
char name[50];
int martial_status;
}PI[100];
int task;
protected:
void exit_function();
void enter_patient_info();
void show_patient_detail();
public:
void tasks();
void tasks_user();
//void recycle_bin();
void delete_entry();
//void billing();
void after_delete_options();
int s_group;
int s_choice;
int en_del_index;
int delete_choice;
char ch;
char answer;
char answer1;
char s_city[30];
char exit_answer;
char delete_confirm;
//char after_search_answer;
};


class temp1
{
public:
int m,i,j,k,d,e,f,rem,temp,count,regis,entry,serial,attempt,current,index;
int d_index,ssi_count,show_count,delete_show,current_year,delete_count;
int entry_index[100];
char enter_now,duplicate_answer,delete_all_confirm,restore_all_confirm;
temp1()
{
i=0;j=0; d=0; e=0; f=0;
serial=0;
current=0;
d_index=0;
ssi_count=0;
show_count=0;
delete_show=0;
delete_count=0;
};
};

all A1;
temp1 T1;

/*********************************************************/

void userchk()
{
char passuser[]={"123"};
char passadmin[]={"11111"};
char s1[15];
int i=0;
char ch='\0';
char s2[15];
int us_choice;
int us_check;
cout<<"\nEnter choice\n 1 - Admin \n 2 - User \n";
cin>>us_choice;
if(us_choice==1)
{
cout<<" Enter password\n";
while(ch!=13)
{
ch=getch();
s1[i++]=ch;
cout<<"*";
}
s1[i-1]='\0';
us_check = stricmp(passadmin,s1);
if(us_check==0)
{
cout<<"\nWelcome administrator";
privilage = 'a';
main_menu();
}
else
{
cout<<"\nEntered password is wrong\n";
cout<<"\nPlease Choose the correct User Mode \nEnter correct password";
userchk();
}
}
if(us_choice==2)
{
cout<<"Enter password\n";
while(ch!=13)
{
ch=getch();
s2[i++]=ch;
cout<<"*";
}
s2[i-1]='\0';
us_check = stricmp(passuser,s2);
if(us_check==0)
{
cout<<"Welcome user";
privilage = 'u';
menu_for_user();
}
else
{
cout<<"Entered password is wrong";
}
}
}
/*********************************************************/

void main_menu(){
    system("color 3f");
    system("cls");
    T1.count=0;
    for(T1.m=1;T1.m<=100;T1.m++)
    {
    T1.entry_index[T1.m]=-1;
    }
    cout<<"\t\t\t\t WELCOME TO"<<"\n";
    cout<<"\n\n\t\t\t***HOSPITAL MANAGEMENT SOFTWARE***"<<"\n";
    cout<<"\n\t\t\t\t BY TEAM - A  "<<"\n";
    A1.tasks();
}

void menu_for_user(){
    system("color 79");
    system("cls");
    T1.count=0;
    for(T1.m=1;T1.m<=100;T1.m++)
    {
    T1.entry_index[T1.m]=-1;
    }
    cout<<"\t\t\t\t WELCOME TO"<<"\n";
    cout<<"\n\n\t\t\t***HOSPITAL MANAGEMENT SOFTWARE***"<<"\n";
    cout<<"\n\t\t\t\t BY TEAM - A  "<<"\n";
    A1.tasks_user();
}
int main(){
    userchk();
//main_menu();


return 0;
}


void all::tasks()
{
    system("cls");
    T1.attempt=0;
    T1.d_index=0;
    cout<<"\n\n\t\t\t ***Hospital Management Tasks***"<<"\n";
    cout<<"\n";
    cout<<"\n\n\tPlease select a task to do..."<<"\n";
    cout<<"\n\n\t1. Enter a new patient information "<<"\n";
    cout<<"\t2. View detail of existing patient "<<"\n";
    cout<<"\t3. Delete entry "<<"\n";
    cout<<"\t4. Exit "<<"\n\n\n";
    cout<<"\a Enter your task serial : ";
    cin>>task;
    switch(task)
    {
    case 1:{
    A1.enter_patient_info();
    break;
    }
    case 2:{
    A1.show_patient_detail();
    break;
    }

    case 3:{
    A1.delete_entry();
    break;
    }

    case 4:{
    A1.exit_function();
    break;
    }
    default:
    cout<<"\n\n\n\n\n\tInvalid task serial !!!"<<"\n";
    cout<<"\tValid options are 1-6 !!!"<<"\n";
    cout<<"\tPress any key to return to the main task menu....\a"<<"\n";
    getch();
    A1.tasks();
    }
return ;
}

void all::tasks_user()
{
T1.attempt=0;
T1.d_index=0;
cout<<"\n\n\t\t\t ***Hospital Management Tasks***"<<"\n";
cout<<"\n";
cout<<"\n\n\tPlease select a task to do..."<<"\n";
cout<<"\t1. View detail of existing patient "<<"\n";
cout<<"\t2. Exit "<<"\n\n\n";
cout<<"\a Enter your task serial : ";
cin>>task;
switch(task)
{
case 1:{
A1.show_patient_detail();
break;
}
case 2:{
A1.exit_function();
break;
}
default:
cout<<"\n\n\n\n\n\tInvalid task serial !!!"<<"\n";
cout<<"\tValid options are 1-6 !!!"<<"\n";
cout<<"\tPress any key to return to the main task menu....\a"<<"\n";
getch();
A1.tasks_user();
}
return ;
}


void all::enter_patient_info()
{
if(T1.current==100)
{
cout<<"\n\n\n\t Database is full !!! ";
cout<<"\n\t Sorry, you cannot enter any more information !!! ";
cout<<"\n\t Information of maximum 100 patients can be entered !!!! ";
cout<<"\n\t Press any key to return to the main menu....\a ";
getch();
A1.tasks();
}
answer='y';
if(T1.count==0)
T1.serial=1;
else
T1.i=T1.serial;
for(T1.i=T1.serial;answer=='y'||answer=='Y';T1.i++)
{
cout<<"\a";
T1.current++;
PI[T1.i].reg_no=T1.i;
T1.temp=T1.serial;
T1.entry_index[T1.i]=1;
cout<<"\n\n\t ***ENTERING INFORMATION FOR PATIENT SERIAL NUMBER "<<T1.i<<" ***"<<"\n";
cin.get(ch);
cout<<"\nRegistration Number : "<<PI[T1.i].reg_no<<"\n\n";
cout<<"Enter the name of patient : ";
cin.getline(PI[T1.i].name,50);
while(strlen(PI[T1.i].name)==0)
{
cout<<"\a\nPlease enter a name : ";
cin.getline(PI[T1.i].name,50);
cout<<"\n";
}
for(T1.k=1;T1.k<T1.serial;T1.k++)
{
if(strcmp(PI[T1.i].name,PI[T1.k].name)==0)
{
if(T1.entry_index[T1.k]==0)
continue;
else
{
T1.current-=1;
cout<<"\n\n\n\tThe patient is already admitted in the hospital !!!";
cout<<"\n\tWant to view info of this registration number in detail (Y/N) : \a";
cin>>T1.duplicate_answer;
while(T1.duplicate_answer!='Y'&&T1.duplicate_answer!='y'&&T1.duplicate_answer!='N'&&T1.duplicate_answer!='n')
{
cout<<"\n\t\aPlease re enter a correct option (Y/N) : ";
cin>>T1.duplicate_answer;
}
if(T1.duplicate_answer=='y'||T1.duplicate_answer=='Y')
{
T1.entry_index[T1.i]=-1;
T1.regis=T1.k;
T1.d_index=1;
A1.show_patient_detail();
}
else
{
A1.tasks();
}
}
}
}
cout<<"\nSex ( 1-Male , 2-Female ) : ";
cin>>PI[T1.i].sex;
while(PI[T1.i].sex!=1&&PI[T1.i].sex!=2)
{
cout<<"\a\nInvalid input for sex of patient !!!";
cout<<"\nSex : ";
cin>>PI[T1.i].sex;
}
cout<<"\nMartial status( 1-Married , 2-Single ) : ";
cin>>PI[T1.i].martial_status;
while(PI[T1.i].martial_status<1||PI[T1.i].martial_status>2)
{
cout<<"\a\nInvalid input for martial status !!!"<<"\n";
cout<<"Enter a valid martial status : "<<"\n";
cin>>PI[T1.i].martial_status;
}
cin.get(ch);
cout<<"\n *** Blood group ***"<<"\n";
cout<<" 1. A+ "<<"\n";
cout<<" 2. A- "<<"\n";
cout<<" 3. B+ "<<"\n";
cout<<" 4. B- "<<"\n";
cout<<" 5. AB+ "<<"\n";
cout<<" 6. AB- "<<"\n";
cout<<" 7. O+ "<<"\n";
cout<<" 8. O- "<<"\n";
cout<<"\nEnter a blood group : ";
cin>>PI[T1.i].bld_group;
switch(PI[T1.i].bld_group)
{
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
case 8:
break;
default:
while(PI[T1.i].bld_group!=1&&PI[T1.i].bld_group!=2&&
PI[T1.i].bld_group!=3&&PI[T1.i].bld_group!=4&&
PI[T1.i].bld_group!=5&&PI[T1.i].bld_group!=6&&
PI[T1.i].bld_group!=7&&PI[T1.i].bld_group!=8)
{
cout<<"\aInvalid input !!!"<<"\n";
cout<<"Please enter a valid Blood Group : "<<"\n";
cin>>PI[T1.i].bld_group;
}
}
cin.get(ch);
cout<<"\n\n ***ENTERING ADDRESS**"<<"\n\n";
cout<<"House number : ";
cin>>PI[T1.i].AD1.house;
while(PI[T1.i].AD1.house<=0)
{
cout<<"\a\nInvalid input for house number !!!";
cout<<"\nAgain enter the house number : ";
cin>>PI[T1.i].AD1.house;
}
cin.get(ch);
cout<<"Street : ";
cin.getline(PI[T1.i].AD1.street,30);
while(strlen(PI[T1.i].AD1.street)==0)
{
cout<<"\a\nPlease enter a street : ";
cin.getline(PI[T1.i].AD1.street,50);
cout<<"\n";
}
cout<<"City : ";
cin.getline(PI[T1.i].AD1.city,30);
while(strlen(PI[T1.i].AD1.city)==0)
{
cout<<"\a\nPlease enter a city : ";
cin.getline(PI[T1.i].AD1.city,50);
cout<<"\n";
}
cout<<"State : ";
cin.getline(PI[T1.i].AD1.state,30);
while(strlen(PI[T1.i].AD1.state)==0)
{
cout<<"\a\nPlease enter a state : ";
cin.getline(PI[T1.i].AD1.state,50);
cout<<"\n";
}
cout<<"Country : ";
cin.getline(PI[T1.i].AD1.country,30);
while(strlen(PI[T1.i].AD1.country)==0)
{
cout<<"\a\nPlease enter a country : ";
cin.getline(PI[T1.i].AD1.country,50);
cout<<"\n";
}
cout<<"\n\nWant to enter information for another patient (Y/N) ? ";
cin>>answer;
while(answer!='Y'&&answer!='y'&&answer!='N'&&answer!='n')
{
cout<<"\a\nPease re-enter a correct option (Y/N) : ";
cin>>answer;
}
cout<<"\n";
T1.count++;
T1.serial++;
}
A1.tasks();
}


void all::show_patient_detail()
{
if(T1.d_index==1)
{
T1.d_index=0;
cout<<"\n\n";
goto direct;
}
if(T1.current==0)
{
cout<<"\n\n\n";
cout<<"\tDatabase is empty !!!"<<"\n";
cout<<"\tPlease enter some information first. "<<"\n";
cout<<"\n\n\tDo you want to enter now (Y/N) : \a";
cin>>T1.enter_now;
while(T1.enter_now!='Y'&&T1.enter_now!='y'&&T1.enter_now!='N'&&T1.enter_now!='n')
{
cout<<"\a\n\tPlease enter a correct option (Y/N) : ";
cin>>T1.enter_now;
}
if(T1.enter_now=='y'||T1.enter_now=='Y')
A1.enter_patient_info();
else
A1.tasks();
}
cout<<"\n\t\t****** CURRENT DATEBASE ENTRIES ******\n\n";
cout<<"\t\tRegistration no. Name of patient\n\n";
for(T1.j=1;T1.j<100;T1.j++)
{
if(T1.entry_index[T1.j]==1)
cout<<"\t\t "<<T1.j<<" "<<PI[T1.j].name<<"\n";
else
continue;
}
cout<<"\n\n\t\tPress 0 to return to main menu.... ";
cout<<"\n\n\nEnter registration number whose details you want to see : ";
cin>>T1.regis;
cout<<"\n\n";
cin.get(ch);
if(T1.regis==0)
A1.tasks();
T1.show_count++;
direct:
if(T1.regis<=0)
{
cout<<"\n\n\tSorry, invalid registration number ";
cout<<"\n\tRegistration number starts from 1. ";
cout<<"\n\n\tPress any key to continue..... \a";
getch();
A1.show_patient_detail();
}
if(T1.regis>0&&T1.regis<T1.serial&&T1.entry_index[T1.regis]==0)
{
cout<<"\n\tSorry, the patient has left the hospital.";
cout<<"\n\tPress any key to continue..."<<"\n";
getch();
}
if((T1.regis<0||T1.regis>=T1.serial)&&T1.entry_index[T1.regis]==-1)
{
cout<<"\n\n\tSorry, the registration number is invalid ."<<"\n";
T1.entry=T1.serial-1;
if(T1.entry==1)
cout<<"\tOnly 1 record has been added .\n";
else
cout<<"\tOnly "<<T1.entry<<" records have been added .\n";
}
if(T1.regis>0&&T1.regis<T1.serial&&T1.entry_index[T1.regis]==1)
{
cout<<"\n\t ***INFORMATION FOR PATIENT REGISTRATION NUMBER "<<T1.regis<<"***\n\n";
cout<<"\tName : "<<PI[T1.regis].name<<"\n";
cout<<"\tSex : ";
if(PI[T1.regis].sex==1)
cout<<"Male "<<"\n";
if(PI[T1.regis].sex==2)
cout<<"Female "<<"\n";
cout<<"\tBlood Group : ";
switch(PI[T1.regis].bld_group)
{
case 1:
cout<<"A+\n";
break;
case 2:
cout<<"A-\n";
break;
case 3:
cout<<"B+\n";
break;
case 4:
cout<<"B-\n";
break;
case 5:
cout<<"AB+\n";
break;
case 6:
cout<<"AB-\n";
break;
case 7:
cout<<"O+\n";
break;
case 8:
cout<<"O-\n";
} //end of switch
cout<<"\tMarital Status : ";
if(PI[T1.regis].martial_status==1)
cout<<"Married "<<"\n";
else
cout<<"Single "<<"\n";
cout<<"\n\t **ADDRESS**"<<"\n";
cout<<"\n\tHouse no. : "<<PI[T1.regis].AD1.house;
cout<<"\n\tStreet : "<<PI[T1.regis].AD1.street;
cout<<"\n\tCity : "<<PI[T1.regis].AD1.city;
cout<<"\n\tState : "<<PI[T1.regis].AD1.state;
cout<<"\n\tCountry : "<<PI[T1.regis].AD1.country;
}
T1.d_index=0;
cout<<"\n\n\n\n\tWant to view detail of another patient(y/n) : ";
cin>>answer1;
while(answer1!='Y'&&answer1!='y'&&answer1!='N'&&answer1!='n')
{
cout<<"\a\tPease re-enter a correct option (Y/N) ? ";
cin>>answer1;
}
if(answer1=='Y'||answer1=='y')
A1.show_patient_detail();
else
A1.tasks();
}


void all::delete_entry()
{
if(T1.current==0)
{
cout<<"\n\n\n";
cout<<"\tDatabase is empty !!!"<<"\n";
cout<<"\tPlease enter some information first. "<<"\n";
cout<<"\n\n\tDo you want to enter now (Y/N) : \a";
cin>>T1.enter_now;
while(T1.enter_now!='Y'&&T1.enter_now!='y'&&T1.enter_now!='N'&&T1.enter_now!='n')
{
cout<<"\a\n\tPlease re-enter a correct option (Y/N) : ";
cin>>T1.enter_now;
}
if(T1.enter_now=='y'||T1.enter_now=='Y')
A1.enter_patient_info();
else
A1.tasks();
}
cout<<"\n\t\t ***CURRENT DATABASE ENTRIES***\n\n";
cout<<"\t\tRegistration no. Name of patient\n\n";
for(T1.j=1;T1.j<T1.serial;T1.j++)
{
if(T1.entry_index[T1.j]==0)
continue;
if(T1.entry_index[T1.j]==1)
{
T1.delete_show++;
cout<<"\t\t "<<T1.j<<" "<<PI[T1.j].name<<"\n";
}
}
if(T1.delete_show==0)
{
cout<<"\n\tDatabase is currently empty!!!\a";
cout<<"\n\tPress any key to continue....";
getch();
A1.tasks();
}
cout<<"\n\n\tPress 0 to return to main menu and 101 to delete all entries... ";
cout<<"\n\n\n\t Or enter the registration no. from 1 to 100 you want to delete ? ";
cin>>en_del_index;
if(en_del_index==101)
{
cout<<"\n\tWarning : You are about to delete all entries !!!\a";
cout<<"\n\tAre you sure you want to do this : ";
cin>>T1.delete_all_confirm;
while(T1.delete_all_confirm!='Y'&&T1.delete_all_confirm!='y'&&T1.delete_all_confirm!='N'&&T1.delete_all_confirm!='n')
{
cout<<"\n\tSorry, wrong input !!!";
cout<<"\n\tPlease enter a valid choice (Y/N) : \a";
cin>>T1.delete_all_confirm;
}
if(T1.delete_all_confirm=='y'||T1.delete_all_confirm=='Y')
{
for(T1.f=1;T1.f<=100;T1.f++)
{
if(T1.entry_index[T1.f]==1)
{
T1.current--;
T1.entry_index[T1.f]=0;
}
}
cout<<"\n\n\tAll entries have been succesfully deleted!!!";
cout<<"\n\tPress any key to return to the main menu...\a";
getch();
A1.tasks();
}
else
{
cout<<"\n\tNo entries have been deleted.";
cout<<"\n\tPress any key for more options....";
getch();
A1.after_delete_options();
}
}
if(en_del_index==0)
A1.tasks();
if(en_del_index>0&&en_del_index<T1.serial&&T1.entry_index[en_del_index]==1)
{
cout<<"\n\n\tAre you sure you want to delete entry "<<en_del_index<<" (Y/N) ? ";
cin>>delete_confirm;
while(delete_confirm!='Y'&&delete_confirm!='y'&&delete_confirm!='N'&&delete_confirm!='n')
{
cout<<"\a\n\tPease re-enter a correct option (Y/N) ? ";
cin>>delete_confirm;
}
if(delete_confirm=='y'||delete_confirm=='Y')
{
T1.entry_index[en_del_index]=0;
T1.current--;
cout<<"\n\tEntry succesfully deleted.\n";
cout<<"\tPress any key to continue.....\a";
getch();
A1.after_delete_options();
}
else
{
T1.entry_index[en_del_index]=1;
cout<<"\n\tEntry not deleted ";
cout<<"\n\tPress any key to continue.......";
getch();
A1.after_delete_options();
}
}
if(en_del_index>0&&en_del_index<T1.serial&&T1.entry_index[en_del_index]==0)
{
cout<<"\n\n\tSorry, the patient has already left the hospital ."<<"\n";
cout<<"\n\tPress any key to continue...\a"<<"\n";
getch();
A1.delete_entry();
}
else
{
cout<<"\n\n\tSorry, Invalid registration number ."<<"\a\n";
T1.entry=T1.serial-1;
if(T1.entry==1)
cout<<"\tOnly 1 record has been added .\n";
else
cout<<"\tOnly "<<T1.entry<<" records were added and "<<T1.current<<" are present now.\n";
cout<<"\tPress any key to continue..."<<"\n";
getch();
A1.delete_entry();
}
}


void all::after_delete_options()
{
cout<<"\n\t\tWHAT DO YOU WANT TO DO NOW ?";
cout<<"\n\t\t1. Delete more entries ";
cout<<"\n\t\t2. Return to main menu "<<"\n";
cout<<"\n\t\tPlease enter your choice : ";
cin>>delete_choice;
while(delete_choice!=1&&delete_choice!=2)
{
cout<<"\a\n\n\tSorry, wrong choice .";
cout<<"\n\tValid choices are 1 and 2. ";
cout<<"\n\tPlease re-enter your choice : ";
cin>>delete_choice;
}
switch(delete_choice)
{
case 1:
A1.delete_entry();
break;
case 2:
A1.tasks();
}
}


void all::exit_function()
{
if(T1.serial==0)
{
cout<<"\n\n\n\n\tYou have not used the software.";
cout<<"\n\tIt is recommended that you should not exit.";
cout<<"\n\tPress any key to continue......\a";
getch();
cout<<"\n\n\n\tAre you sure you want to exit (Y/N) ? ";
cin>>exit_answer;
while(exit_answer!='Y'&&exit_answer!='y'&&exit_answer!='N'&&exit_answer!='n')
{
cout<<"\n\n\tInvalid input !!! ";
cout<<"\n\tPease re-enter a correct option (Y/N) : \a";
cin>>exit_answer;
}
if(exit_answer=='y'||exit_answer=='Y')
{
cout<<"\a";
exit;
}
else
A1.tasks();
}
cout<<"\n\n\n\t\t\t ***SOFTWARE DETAILS***\n";
cout<<"\n\n\tDeveloper : Shohag, Alamin, Sadiya, Abir, Kaiser, Tarek"<<"\n";
cout<<"\n\n\tBangladesh University of Business and Technology\n";
cout<<"\tProgramming Language : C++ "<<"\n";
cout<<"\n\n\n\tPress any key to continue........"<<"\n";
getch();
exit(0);
}
