/////////////////////////////////////////////////////
//     implementation file for the air line header //
//
////////////////////////////////////////////////////
#include "airline.h"
//////////////////////

void Get_str(char *str)
{
	char ch;
	int i=0;
	while((ch=getche())!='\r')
	{   
		if(i==(MAX-1))
		{
			cout<<endl<<"String OVERFLOW Cant able to enter more charz...";
			cout<<endl<<"Press any key.."<<endl;
			getch();
			break;
		}
		if(ch==8)
		{
			i--;
			continue;
		}
		str[i]=ch;
		i++;
	}
	str[i]='\0';
	cout<<endl;
}
///////////////////////////////
void gotoXY(int x,int y)
{
    static HANDLE hOut;
    static bool First = TRUE;
    COORD Position;
    if(First)
    {
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        First = FALSE;
    }
    Position.X = x;
    Position.Y = y; 
    SetConsoleCursorPosition(hOut,Position);
}
void setcolor(WORD color)
{
static HANDLE hOut;
static bool First = TRUE;

    if(First)
    {
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        First = FALSE;
    }

SetConsoleTextAttribute(hOut,color);
}

//////////////////////////////
//   list class
//////////////////////////////
void LIST::Insertnode(int TYPE)
{
	
bool check=false;
long nic;
char em[MAX],Pas[MAX];
cout<<endl;
  if(nofs==Max_seats)
  {
   setcolor(0x0004);
   cout<<endl<<"NO Seat for This Flight is Available....";
   cout<<endl<<"Press any key for main menu...";
   getch();
   return;
  }
   Newptr=new person();
   nofs++;
   if(TYPE==1)
   {
	   Newptr->getticket().set_Ticket("December 04 2014","December 20 2014",10000,tno++);
	   Newptr->getflight().set_flight("10:00 am","Amsterdam","sunday","AP100");
   }
   if(TYPE==2)
   {
	   Newptr->getticket().set_Ticket("December 04 2014","December 20 2014",20000,tno++);
	   Newptr->getflight().set_flight("11:00 am","italy","monday","AP200");
   }
   if(TYPE==3)
   {
	   Newptr->getticket().set_Ticket("December 04 2014","December 20 2014",30000,tno++);
	   Newptr->getflight().set_flight("12:00 pm","USA","tuesday","AP300");
   }
   if(TYPE==4)
   {
	   Newptr->getticket().set_Ticket("December 04 2014","December 20 2014",40000,tno++);
	   Newptr->getflight().set_flight("1:00 pm","UK","wendsday","AP400");
   }

	//////////////////////
	if(First==NULL)
	{
		First=Newptr;
	}
	else
	{
		Current=First;
		while(Current->getnext()!=NULL)
			Current=Current->getnext();
		Current->setnext(Newptr);
	}
	///////////////////////
	Newptr->Fillname();
	Newptr->FillAdd();
I:
	cout<<"Enter his/her NIC no(long int):";
	cin>>nic;
    check=checkid(nic);
	if(check)
	{
		cout<<endl<<"NIC no already exist..."<<endl;
		cout<<"Press any key to reEntre NIC no..."<<endl;
		getch();
		goto I;
	}
	else
	Newptr->FillNic(nic);
	Newptr->FillAge();

E:
	cout<<"Enter his/her Email id(MAX:30)(char*):";
	Get_str(em);
    check=checkEid(em);
	if(check)
	{
		cout<<endl<<"Email id already exist..."<<endl;
		cout<<"Press any key to reEntre Email id no..."<<endl;
		getch();
		goto E;
	}
	else
		Newptr->FillEmail(em);
	P:
	cout<<"Enter his/her PassPort No(MAX:30)(char*):";
	Get_str(Pas);
    check=checkpid(Pas);
	if(check)
	{
		cout<<endl<<"Passport No already exist..."<<endl;
		cout<<"Press any key to reEntre Passport no..."<<endl;
		getch();
		goto P;
	}
	else
		Newptr->FillPass(Pas);

        Newptr->setnext(NULL);
        setcolor(0x0006);
	    cout<<"***********Ticket Info**************"<<endl;
	    setcolor(0x0002);
		Newptr->getflight().Display_Flight();
		setcolor(0x0006);
	    cout<<"***********Flight Info**************"<<endl;
	    setcolor(0x0002);
		Newptr->getticket().Display_Ticket();
		setcolor(0x0006);
	    cout<<"*************End Information************"<<endl;	
		setcolor(0x0003);
		cout<<endl<<"Press any key to return...";
		getch();

}
///////////////////////////////////////////////////////////////
bool LIST::checkid(long nic)
{
	person *temp;
	temp=First;
	while(temp!=NULL)
	{
		if(temp->getnic()==nic)
			return true;
	    else
			temp=temp->getnext();
	}
	return false;
}
///////////////////////////////////////////////////////////////
bool LIST::checkEid(char *eid)
{
	person *temp;
	temp=First;
	while(temp!=NULL)
	{
		if(strcmp(temp->getemail(),eid)==0)
			return true;
	    else
			temp=temp->getnext();
	}
	return false;
}
///////////////////////////////////////////////////////////////
bool LIST::checkpid(char *pid)
{
	person *temp;
	temp=First;
	while(temp!=NULL)
	{
		if(strcmp(temp->getpass(),pid)==0)
			return true;
	    else
			temp=temp->getnext();
	}
	return false;
}
///////////////////////////////////////////////////////////////
void LIST::PrintList()
{   

	int n=0;
	if(First==NULL)
	{
		cout<<"List is Empty.."<<endl;
		cout<<"Press any key to return,...";
		getch();
		return;
	}
    //cout<<First<<" "<<Newptr;getch();
	Current=First;
    //cout<<First<<" "<<Current;getch();
	while(Current!=NULL)
	{
	 system("CLS");
	 cout<<endl<<"Record no:"<<++n;
     Current->printinfo();
	 cout<<endl<<"Press Enter to See Next Record...";
	 cout<<endl<<"and any other key to return to menu...!";
	 char ch;
	 ch=getch();
	 if(ch==13){
	 Current=Current->getnext();
	 }
	 else
	 {
		 return;
	 }
	}
}
////////////////////////////////////////////////////////////////
void LIST::Searchnode()
{  
	long temp;
	int i;
	bool flag=0;
	cout<<"Enter NIC no:";
	cin>>temp;
	Current=First;
	Prev=Current;
	while(Current!=NULL)
	{
	if(Current->getnic()==temp)
	{
 	    flag=true;
		break;
	}
	else
	{
	Prev=Current;
	Current=Current->getnext();
	flag=false;
	}
	}//end while loop.
	if(!flag)
	{
		cout<<endl<<"Record not found......"<<endl;
		cout<<"Press any key to return to main menu...";
		getch();
		return;
	}
	else{
	while(1){
		Current->printinfo();
		cout<<"1)Edit Record"<<endl;
		cout<<"2)Delete Record"<<endl;
		cout<<"3)Back to main menu.."<<endl;
		cin>>i;
		switch(i)
		{
		case 1:
			Editnode();
			break;
		case 2:
			Deletenode();
			return;
		case 3:
			return;
		default:
			cout<<"Enter a Valid Choice....";
		    
		}
	}
	}
}//end searchnode..
/////////////////////////////////
void LIST::Deletenode()
{
person *temp;
if(Current==First)//& prev==first
{
	temp=Prev;
	First=Prev->getnext();
}
else
{
	temp=Current;
	Prev->setnext(Current->getnext());
}
delete temp;
nofs--;
cout<<endl<<"Successfully Deleted....";
cout<<endl<<"Press any key to return to main menu.."<<endl;
getch();

}
/////////////////////////////////
void LIST::Editnode()
{
	char ch;
	char EM[MAX],Pas[MAX];
	long nic;
	bool check=false;
	cout<<"Edit Name(y/n)?:";
	cin>>ch;
	if(ch=='y'||ch=='Y')
		Current->Fillname();
	cout<<"Edit NIC(y/n)?:";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		Current->FillNic(0);
   i:
	cout<<"Enter his/her NIC no:";
	cin>>nic;
    check=checkid(nic);
	if(check)
	{
		cout<<endl<<"NIC no already exist..."<<endl;
		cout<<"Press any key to reEntre NIC no..."<<endl;
		getch();
		goto i;
	}
	else
		Current->FillNic(nic);
	}
	cout<<"Edit Age(y/n)?:";
	cin>>ch;
	if(ch=='y'||ch=='Y')
		Current->FillAge();
	cout<<"Edit Address(y/n)?:";
	cin>>ch;
	if(ch=='y'||ch=='Y')
		Current->FillAdd();
	cout<<"Edit Email(y/n)?:";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		Current->FillEmail(" ");
e:
	cout<<"Enter his/her Email id(MAX:30):";
	Get_str(EM);
    check=checkEid(EM);
	if(check)
	{
		cout<<endl<<"Email id already exist..."<<endl;
		cout<<"Press any key to reEntre Email id no..."<<endl;
		getch();
		goto e;
	}
	else
		Current->FillEmail(EM);
	}
    cout<<"Edit PassPort info(y/n)?:";
    cin>>ch;
    if(ch=='y'||ch=='Y')
	{
		Current->FillPass(" ");
p:
	cout<<"Enter his/her PassPort No(MAX:30):";
	Get_str(Pas);
    check=checkpid(Pas);
	if(check)
	{
		cout<<endl<<"Passport No already exist..."<<endl;
		cout<<"Press any key to reEntre Passport no..."<<endl;
		getch();
		goto p;
	}
	else
		Newptr->FillPass(Pas);	
	}
}
////////////////////////////////////////
void LIST::Free()
{
	person *temp;
		   while(First!=NULL)
		   {
			   temp=First;
			   First=First->getnext();
			   delete temp;
		   }
		   Current=NULL;
		   Newptr=NULL;
		
}
//////////////////////////////////////////
void LIST::Writelisttofile(char *filename)
{
	fstream out;
	out.open(filename,ios::out|ios::trunc|ios::binary);
	if(!out)
	{
		cout<<endl<<"Cant Able to open the file :"<<filename;
		cout<<endl<<"Press any key to return..."<<endl;
		getch();
		return;
	}
	else
	{
		Current=First;
		while(Current!=NULL)
		{
			out.write((char*)Current,sizeof(person));
			Current=Current->getnext();
			if(!out)
			{
				cout<<endl<<"Error while writing....";
				cout<<endl<<"Press any key...";
		        getch();
				out.close();
				return;
			}
		}
		cout<<endl<<"File "<<filename<<"is Written...";	
	    out.close(); 
	}
		
}
////////////////////////////////////////////////////////
void LIST::Readlistfromfile(char *filename)
{
    
	fstream in;
 	person *temp=NULL;
	in.open(filename,ios::in|ios::binary);
	if(!in)
	{
		cout<<endl<<"Cant Able to open the file :"<<filename;
		cout<<endl<<"Press any key to return to main menu..."<<endl;
		getch();

		return;
	}
	else
	{
    
	   temp=new person();
       in.read((char*)temp,sizeof(person));
	   if(!in)
	   {
        cout<<endl<<"NO Records found in "<<filename;
		delete temp;
		First=NULL;
		in.close();
		return;
	   }
	   First=temp;
	   nofs++;
	   tno++;
	   Current=temp;
	   while(1)
	   {
		  temp=new person();
		  Current->setnext(temp);
          in.read((char*)Current->getnext(),sizeof(person));
          if(in.eof())
		  {
			  Current->setnext(NULL);
			  break;
		  }
		  else
		  {
		  tno++;
		  nofs++;
		  Current=Current->getnext();
		  }
		  
           
	   }

     in.close();

	}
}
//////////////////End List implementations////////////////

//////////////////////////////////////////////////////////
void Reservation::RunProgram()
{
int ch;
char c='0';
setcolor(0x0002);
readallfiles();
setcolor(0x0002);
while(1)
{
 system("CLS");
 cout<<"1)Record Entry";
 cout<<endl<<"2)Admin Options";
 cout<<endl<<"3)Exit";
 setcolor(0x0006);
 cout<<endl<<"Enter ur choice:";
 cin>>ch;
 if(ch==1)
	 enterFR();
 else if(ch==2)
	 AdminOp();
 else if(ch==3)
 {
again:
	system("CLS");
	setcolor(0x0005);
	cout<<"SAVE CHANGES 'y' OR 'n':";
    cin>>c;
	if(c=='y')
	{
		writeallfiles();
		exit(0);
	}
	else if(c=='n')
	{
		exit(0);
	}
	else
		goto again;
  }
 else 
 {   
	 setcolor(0x0004);
	 cout<<endl<<"Wrong input..!";
	 cout<<endl<<"Press any key to re-enter choice...";
	 getch();
 }

}
}
////////////////////////////////////
void Reservation::enterFR()
{
int ch; 
while(1)
{
 system("CLS");
 setcolor(0x0005);
 cout<<"1)Flight To Amsterdam"<<"(Available seats:"<<f1.availableseats()<<")";
 cout<<endl<<"2)Flight to Italy"<<"(Available seats:"<<f2.availableseats()<<")";
 cout<<endl<<"3)Flight to USA"<<"(Available seats:"<<f3.availableseats()<<")";
 cout<<endl<<"4)Fligth To UK"<<"(Available seats:"<<f4.availableseats()<<")";
 cout<<endl<<"5)EXIT to previous menu";
 setcolor(0x0006);
 cout<<endl<<"Enter ur choice:";
 cin>>ch;
 if(ch==1)
	 f1.Insertnode(1);
 else if(ch==2)
	 f2.Insertnode(2);
 else if(ch==3)
	f3.Insertnode(3);
  else if(ch==4)
	f4.Insertnode(4);
  else if(ch==5)
	  return;
  else 
 {   
	 setcolor(0x0004);
	 cout<<endl<<"Wrong input..!";
	 cout<<endl<<"Press any key to re-enter choice...";
	 getch();
 }

}
}
//////////////////////////////////////
void Reservation::AdminOp()
{
int ch;
while(1)
{
 system("CLS");
 setcolor(0x0002);
 cout<<"1)Display Flight Records";
 cout<<endl<<"2)Search and Edit";
 cout<<endl<<"3)Exit to previous menu";
 setcolor(0x0006);
 cout<<endl<<"Enter ur choice:";
 cin>>ch;
 if(ch==1)
	 Printrec();
 else if(ch==2)
	 Searchnedit();
  else if(ch==3)
	  return;
  else 
 {
	 setcolor(0x0004);
	 cout<<endl<<"Wrong input..!";
	 cout<<endl<<"Press any key to re-enter choice...";
	 getch();
 }

}

}
//////////////////////////////////////
void Reservation::Printrec()
{
int ch;
while(1)
{
 system("CLS");
 setcolor(0x0002);
 cout<<"1)Display Flight To Amsterdam Recs";
 cout<<endl<<"2)Display Flight to Italy Recs";
 cout<<endl<<"3)Display Flight to USA Recs";
 cout<<endl<<"4)Display Fligth To UK Recs";
 cout<<endl<<"5)EXIT to previous menu";
 setcolor(0x0006);
 cout<<endl<<"Enter ur choice:";
 cin>>ch;
 if(ch==1)
	 f1.PrintList();
 else if(ch==2)
	 f2.PrintList();
 else if(ch==3)
	 f3.PrintList();
  else if(ch==4)
	  f4.PrintList();
  else if(ch==5)
	  return;
  else 
 {   
	 setcolor(0x0004);
	 cout<<endl<<"Wrong input..!";
	 cout<<endl<<"Press any key to re-enter choice...";
	 getch();
 }

}

}
////////////////////////////////////////////////////
void Reservation::Searchnedit()
{
int ch;
while(1)
{
 system("CLS");
 setcolor(0x0002);
 cout<<"1)Search n Edit Flight To Amsterdam Recs";
 cout<<endl<<"2)Search n Edit Flight to Italy Recs";
 cout<<endl<<"3)Search n Edit Flight to USA Recs";
 cout<<endl<<"4)Search n Edit Fligth To UK Recs";
 cout<<endl<<"5)EXIT to previous menu";
 setcolor(0x0006);
 cout<<endl<<"Enter ur choice:";
 cin>>ch;
 if(ch==1)
	 f1.Searchnode();
 else if(ch==2)
	 f2.Searchnode();
 else if(ch==3)
	 f3.Searchnode();
  else if(ch==4)
	  f4.Searchnode();
  else if(ch==5)
	  return;
  else 
 {   
	 setcolor(0x0004);
	 cout<<endl<<"Wrong input..!";
	 cout<<endl<<"Press any key to re-enter choice...";
	 getch();
 }

}




}