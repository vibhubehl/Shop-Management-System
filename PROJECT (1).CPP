#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
class complaint
	{
	int num;
	public:
	int shopno;
	void upgrade()
		{
		num+=1;
		}
	void entry(int a)
		{
		shopno=a;
		num=0;
		}
	void display(int a)
		{
		if(a==1)
		cout<<"\n Shop number is "<<shopno<<" and shortage cases are "<<num;
		if(a==2)
		cout<<"\n Shop number is "<<shopno<<" and corruption cases are "<<num;
		}
	};
class demand
	{
	int grain,milk,oil;
	public:
	int shopno;
	void entry(int a,int b,int c,int d)
		{
		shopno=a;
		grain=b;
		milk=c;
		oil=d;
		}
	void display()
		{
		cout<<"\n Ration shop no. is "<<shopno<<" grain is "<<grain<<" oil is "<<oil<<" milk is "<<milk;
		}
	void comp(int& a,int& b,int& c,int& d)
		{
		a=shopno;
		b=grain;
		c=milk;
		d=oil;
		}
	};
void customer()
{
complaint obj,obj1;
int a,b;
cout<<"\n Welcome to Customer Care";
int ans;
while(ans!=3)
	{
	cout<<"\n 1. Register shortages"<<"\n 2. Register corruption"<<"\n Press 3 to exit";
	cin>>ans;
	if(ans==1)
		{
		cout<<"\n Enter ration shop number";
		cin>>a;
		ofstream fout("temp.txt");
		ifstream fin("shortage.txt");
		while(!fin.eof())
			{
			fin.read((char*)&obj1,sizeof(complaint));
			if(obj1.shopno==a)
				{
				obj1.upgrade();
				fout.write((char*)&obj1,sizeof(complaint));
				}
			else
			fout.write((char*)&obj1,sizeof(complaint));
			}
		fin.close();
		fout.close();
		remove("shortage.txt");
		rename("temp.txt","shortage.txt");
		cout<<"\n Complaint has been registered";
		}
	if(ans==2)
		{
		cout<<"\n Enter ration shop number";
		cin>>a;
		ofstream fout("temp.txt");
		ifstream fin("corruption.txt");
		while(!fin.eof())
			{
			fin.read((char*)&obj1,sizeof(complaint));
			if(obj1.shopno==a)
				{
				obj1.upgrade();
				fout.write((char*)&obj1,sizeof(complaint));
				}
			else
			fout.write((char*)&obj1,sizeof(complaint));
			}
		fin.close();
		fout.close();
		remove("corruption.txt");
		rename("temp.txt","corruption.txt");
		cout<<"\n Complaint has been registered";
		}
	}
}
void hoffice()
{
demand obj,obj1;
int a,b,c,d;
char password[20];
cout<<"\n Please enter password";
gets(password);
if(strcmp(password,"hoffice")==0)
cout<<"\n Correct password.Welcome";
else
	{
	cout<<"\n Wrong password,program is terminating.";
	exit(0);
	}
int ans,flag=0;
while(ans!=7)
	{
	cout<<"\n 1. Register new shop"<<"\n 2. Display supply list"<<"\n 3. Display demand list"<<"\n 4. Display sold list"<<"\n 5. Display shortage list"<<"\n 6. Display corruption list"<<"\n Press 7 to exit";
	cin>>ans;
	if(ans==1)
		{
		cout<<"Enter the Shop number,initial grain(in KG), milk(in L), oil(in L)";
		cout<<"\n Make sure the shop no doesn't exist already";
		cin>>a>>b>>c>>d;
		obj.entry(a,b,c,d);
		ifstream fin("supply.txt");
		while(!fin.eof())
			{
			fin.read((char*)&obj1,sizeof(demand));
			if(obj1.shopno==obj.shopno)
			flag=1;
			}
		if(flag==1)
			{
			cout<<"Shop has already been registered use different shop number";
			break;
			}
		ofstream fout("supply.txt",ios::app);
		fout.seekp(0,ios::end);
		fout.write((char*)&obj,sizeof(demand));
		fout.close();
		obj.entry(a,0,0,0);
		fout.open("demand.txt",ios::app);
		fout.seekp(0,ios::end);
		fout.write((char*)&obj,sizeof(demand));
		fout.close();
		fout.open("sold.txt",ios::app);
		fout.seekp(0,ios::end);
		fout.write((char*)&obj,sizeof(demand));
		fout.close();
		complaint obj1;
		obj1.entry(a);
		fout.open("corruption.txt",ios::app);
		fout.seekp(0,ios::end);
		fout.write((char*)&obj1,sizeof(complaint));
		fout.close();
		fout.open("shortage.txt",ios::app);
		fout.seekp(0,ios::end);
		fout.write((char*)&obj1,sizeof(complaint));
		fout.close();
		cout<<"\n List has been updated";
		}
	if(ans==2)
		{
		ifstream fin("supply.txt");
		while(!fin.eof())
			{
			fin.read((char*)&obj,sizeof(demand));
			obj.display();
			}
		fin.close();
		}
	if(ans==3)
		{
		ifstream fin("demand.txt");
		while(!fin.eof())
			{
			fin.read((char*)&obj,sizeof(demand));
			obj.display();
			}
		fin.close();
		}
	if(ans==4)
		{
		ifstream fin("sold.txt");
		while(!fin.eof())
			{
			fin.read((char*)&obj,sizeof(demand));
			obj.display();
			}
		fin.close();
		}
	if(ans==5)
		{
		complaint obj2;
		ifstream fin("shortage.txt");
		while(!fin.eof())
			{
			fin.read((char*)&obj2,sizeof(complaint));
			obj2.display(1);
			}
		fin.close();
		}
	if(ans==6)
		{
		complaint obj2;
		ifstream fin("corruption.txt");
		while(!fin.eof())
			{
			fin.read((char*)&obj2,sizeof(complaint));
			obj2.display(2);
			}
		fin.close();
		}


	}
}
void rshop()
{
demand obj,obj1,obj2,temp;
int a,b,c,d,a1,a2,b1,b2,c1,c2,d1,d2;
char pass[20];
cout<<"\n Enter password";
gets(pass);
	if(strcmp(pass,"rshop")==0)
	cout<<"Correct password";
	else
	{
	cout<<"\n Wrong password, program terminating";
	exit(0);
	}
int ans;
while(ans!=5)
	{

	cout<<"\n 1.Enter Demand"<<"\n 2. Display demands"<<"\n 3.Enter Item sold"<<"\n 4.Display items sold"<<"\n Press 5 to exit";
	cin>>ans;
	if(ans==1)
		{
		ofstream fout("temp.txt",ios::out);
		ifstream fin("demand.txt",ios::in);
		ifstream fsup("supply.txt");
		ifstream fsold("sold.txt");
		fout.seekp(0,ios::end);
		cout<<"\n Enter Ration shop number,amount of grain(in KG),milk (in litre),and oil(in Litre)";
		cin>>a>>b>>c>>d;
		obj.entry(a,b,c,d);
		while(!fsup.eof())
			{
			fsup.read((char*)&obj1,sizeof(demand));
			if(obj.shopno==obj1.shopno)
			break;
			}
		while(!fsold.eof())
			{
			fsold.read((char*)&obj2,sizeof(demand));
			if(obj2.shopno==obj.shopno)
			break;
			}
		obj1.comp(a1,b1,c1,d1);
		obj2.comp(a2,b2,c2,d2);
		if(a1==a2&&b1==b2&&c1==c2&&d1==d2)
			{
			obj1.entry(a,0,0,0);
			while(!fsup.eof())
				{
				fsup.read((char*)&temp,sizeof(demand));
				if(obj1.shopno==temp.shopno)
				fout.write((char*)&obj1,sizeof(demand));
				else
				fout.write((char*)&temp,sizeof(demand));
				}
			fout.close();
			fsup.close();
			remove("supply.txt");
			rename("temp.txt","supply.txt");
			fout.open("temp.txt");
			obj2.entry(a,0,0,0);
			while(!fsold.eof())
				{
				fsold.read((char*)&temp,sizeof(demand));
				if(obj2.shopno==temp.shopno)
				fout.write((char*)&obj2,sizeof(demand));
				else
				fout.write((char*)&temp,sizeof(demand));
				}
			fout.close();
			fsold.close();
			remove("sold.txt");
			rename("temp.txt","sold.txt");
			fout.open("temp.txt");
			while(!fin.eof())
				{
				fin.read((char*)&temp,sizeof(demand));
				if(obj.shopno==temp.shopno)
				fout.write((char*)&obj,sizeof(demand));
				else
				fout.write((char*)&temp,sizeof(demand));
				}
			fin.close();
			fout.close();
			remove("demand.txt");
			rename("temp.txt","demand.txt");
			}
		else
		cout<<"\n All items have not been sold. You cannot request right now";
		}
	if(ans==2)
		 {
		 ifstream fin("demand.txt");
		 cout<<"\n Enter ration shop number";
		 cin>>a;
		 fin.seekg(0,ios::beg);
		 cout<<"\n Demand List is";
		 while(!fin.eof())
			{
			fin.read((char*)&obj,sizeof(demand));
			if(obj.shopno==a)
			obj.display();
			}
		 fin.close();
		 }
	if(ans==3)
		{
		ifstream fin("sold.txt");
		ofstream fout("temp.txt");
		cout<<"\n Enter Shop number the grain, milk and oil sold in total";
		cin>>a>>b>>c>>d;
		obj1.entry(a,b,c,d);
		while(!fin.eof())
			{
			fin.read((char*)&temp,sizeof(demand));
			if(temp.shopno==obj1.shopno)
			fout.write((char*)&obj1,sizeof(demand));
			else
			fout.write((char*)&temp,sizeof(demand));
			}
		fin.close();
		fout.close();
		remove("sold.txt");
		rename("temp.txt","sold.txt");
		}
	if(ans==4)
		 {
		 ifstream fin("sold.txt");
		 cout<<"\n Enter ration shop number";
		 cin>>a;
		 fin.seekg(0,ios::beg);
		 cout<<"\n Sold List is";
		 while(!fin.eof())
			{
			fin.read((char*)&obj,sizeof(demand));
			if(obj.shopno==a)
			obj.display();
			}
		 fin.close();
		 }
	}
}
void main()
{
clrscr();
int choice;
cout<<"\n 1. Ration Shop"<<"\n 2. Customer"<<"\n 3. Head office"<<"\n 4. To know about the program";
cin>>choice;
if(choice==1)
rshop();
if(choice==2)
customer();
if(choice==3)
hoffice();
if(choice==4)
	{
	cout<<"Ration shop program consists of three users"<<"\n 1. is Head office which gives you ability to register new ration shops into "<<"\n the system.It also allows you to see demand,supply,sold,shortage and corruption list"<<"\n 2. Is Ration Shop. It allows you to make a demand ,enter items sold and "<<"\n check lists such as demand,supply and sold lists"<<"\n Note that you cannnot make a demand request till the time all the things are sold"<<"\n Once all the things are sold you can request demand new items and your supply and sold lists will be reset to 0"<<"\n 3.Customer care allows you to register complaints"<<"\n if you are a new user start with head office and first register new ration shops";
	}

getch();
}

