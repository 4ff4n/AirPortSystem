#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

////////////////////////////////
void Get_str(char *);
const int MAX=20;
const int Max_seats=20;
/////////////////////////////////
void gotoXY(int ,int);
void setcolor(WORD);
//////////////////////////////////////
class flight{


	char flight_time[MAX];
    char distination_name[MAX];
    char  day_of_flight[MAX];
	char  plan_id[MAX];
public:
	flight()
	{
     *flight_time=NULL;
     *distination_name=NULL;
     *day_of_flight=NULL;
	 *plan_id=NULL;
	}
  void set_flight(char *tf,char *dn,char *dof,char *pid)
	{
		strcpy(flight_time,tf);
		strcpy(distination_name,dn);
		strcpy(day_of_flight,dof);
		strcpy(plan_id,pid);
	}

	/////////////////////////////////
  void Display_Flight()
  {
    cout<<"FLIGHT TIME        :"<<flight_time<<endl;
	cout<<"DISTINATION        :"<<distination_name<<endl;
	cout<<"DAY OF FLIGHT      :"<<day_of_flight<<endl;
    cout<<"PLANE ID           :"<<plan_id<<endl; 
  }

};

/////////////////////////////////
class Ticket
{

   int T_no;
   char date[MAX];
   char valid_up_to[MAX];
   int price;
   /////////////////////
public:
   Ticket()
   {
	T_no=0;  
    date[0]=NULL;
    valid_up_to[0]=NULL;
    price=0;  
   }
   //////////////////////////
 void set_Ticket(char *d,char *vut,int p,int tno)
  {
	  strcpy(date,d);
	  strcpy(valid_up_to,vut);
	  price=p;
	  T_no=tno;
  }

  /////////////////////////////
  void Display_Ticket()
  {
    cout<<"TICKET NO          :"<<T_no<<endl;
	cout<<"PRICE              :"<<price<<endl;
	cout<<"ISSUE ON           :"<<date<<endl;
    cout<<"VALID UPTO         :"<<valid_up_to<<endl; 
  }
};
//////////////////////////////////////////////////
class person
{
	char name[MAX];
	long Nic_N;
	char  Address[MAX];
	char  E_mailid[MAX];
	char PassP_no[MAX];
	int age;
    ////////person essential properties///////////
	flight f;
	Ticket t;
	person *next;//for que and list implementations
    //////////////////////////////////////////////

public:
	person()
	{   
		*name=NULL;
		Nic_N=0;
		*Address=NULL;
		*E_mailid=NULL;
		*PassP_no=NULL;
		age=0;
		next=NULL;
	} 
    /////////////////////////////////////////////////////
	void Fillname()
	{
		cout<<"Enter Name (char*): ";
		Get_str(name);
	}
	void FillAdd()
	{
		cout<<"Enter Address (char*) : ";
		Get_str(Address);
	}

	void FillPass(char *p)
	{
		strcpy(PassP_no,p);
	}
	void FillEmail(char *ptr)
	{
		strcpy(E_mailid,ptr);
	}
	void FillNic(long n)
	{
		Nic_N=n;
	}
	void FillAge()
	{
		cout<<"Enter Age (int):";
		cin>>age;
	}
	////////////////////////////////////////////////////
	flight &getflight()
	{
		return f;
	}
	Ticket &getticket()
	{
		return t;
	}
	char *getname()
	{
		return name;
	}
	long getnic()
	{
		return Nic_N;
	}
	char *getaddr()
	{
		return Address;
	}
	char *getemail()
	{
		return E_mailid;
	}
	char *getpass()
	{
		return PassP_no;
	}
	long getage()
	{
		return age;
	}
	person *getnext()
	{
		return next;
	}
	void  setnext(person *ptr)
	{
		next=ptr;
	}
    


	/////////////////////////////////////////////////////
    void printinfo()
	{
	cout<<endl;
	setcolor(0x0003);
	cout<<"**************************************"<<endl;
    cout<<"NAME          :"<<getname()<<endl;
	cout<<"AGE           :"<<getage()<<endl;
	cout<<"NIC           :"<<getnic()<<endl;
    cout<<"NIC           :"<<getpass()<<endl;
	cout<<"ADDRESS       :"<<getaddr()<<endl;
	cout<<"EMAIL ID      :"<<getemail()<<endl;
	setcolor(0x0006);
	cout<<"***********Ticket Info**************"<<endl;
	setcolor(0x0002);
    t.Display_Ticket();
	setcolor(0x0006);
	cout<<"***********Flight Info**************"<<endl;
	setcolor(0x0002);
	f.Display_Flight();
	setcolor(0x0006);
	cout<<"*************End Information************"<<endl;	
	}
 
};
////////////////////////////////////////////////////////////
//List implementations here
////////////////////////////////////////////////////////////
class LIST{
public:
        person *First;
		person *Current;
		person *Newptr;
		person *Prev;
		int tno;
		int nofs;
//////////////////////////////
		LIST()
		{
			First=Current=Newptr=Prev=NULL;
			tno=1000;
			nofs=0;

		}
////////////////////////////////
		LIST(person* P)//for setting listz first pointer to required address at dec time.
		{
			First=P;
		}
/////////////////////////////////
       void Insertnode(int Type);
	   void PrintList();
	   void Deletenode();
	   void Searchnode();
	   void Editnode();
	   void Free();
	   bool checkid(long);
	   bool checkEid(char *);
	   bool checkpid(char *);
	   void Writelisttofile(char *);
	   void Readlistfromfile(char *);
	   int availableseats()
	   {
		   return Max_seats-nofs;
	   }
/////////////////////////////////
	   ~LIST()
	   {   
		   person *temp;
		   while(First!=NULL)
		   {
			   temp=First;
			   First=First->getnext();
			   delete temp;
		   }
	   }//deleting list from RAM.
/////////////////////////////////////
};
///////////////////End List Class///////
class Reservation
{
LIST f1,f2,f3,f4;
public:
Reservation()
{

}
~Reservation()
{
}
//////////////////////////////////////////
void writeallfiles(){

	f1.Writelisttofile("AMSTERDAM.dat");
	f2.Writelisttofile("ITALY.dat");
	f3.Writelisttofile("USA.dat");
	f4.Writelisttofile("UK.dat");
}
/////////////////////////////////////////
void readallfiles(){
	system("CLS");
	cout<<"READING DATABASE...!";

	cout<<endl<<endl;
	Sleep(100);
	cout<<endl<<"Reading AMSTERDAM.dat";
	f1.Readlistfromfile("AMSTERDAM.dat");
	Sleep(100);
    cout<<endl<<"Reading ITALY.dat";
	f2.Readlistfromfile("ITALY.dat");
	Sleep(100);
    cout<<endl<<"Reading USA.dat";
	f3.Readlistfromfile("USA.dat");
	Sleep(100);
	cout<<endl<<"Reading UK.dat";
	f4.Readlistfromfile("UK.dat");
	Sleep(100);
	setcolor(0x0001);
	cout<<endl<<"Complete!";
	cout<<endl<<"Press any key to continue...";
	getch();
	return;
}
//////////////////////////////////////////
void RunProgram();
void enterFR();
void AdminOp();
void Printrec();
void Searchnedit();
};
//////////////////////////////////////////





       		

