#include<iostream>
#include<windows.h>
#include<dos.h>
#include<stdio.h>
#include<cstdlib>
#include<string>
#include<conio.h>
#include<sstream>
#include<mysql.h>
#include<cstdio>
#include<stdlib.h>


using namespace std;
// Global Variable

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
int qstate=0,qstate1=0,qstate2=0;
// Global Variable End

COORD coord={0,0};
void gotoxy(int x,int y)
{
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int snackspr,maggipr,sdpr,snacks;
int snacksqty,maggiqty,sdqty;
void billpage();
void empjump();
void billjump();
void handlecust();
class login;
class store;

class order;
class billing;
class store
{
public:
string item;
string name;
int amt;
int ch;
int rate;
int qty=0;
void mnginvt();
void storepageswitch();
void price();
void viewinvt();
void quantity();
void storepage()
{
storepageswitch();
}
};
void store::storepageswitch()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     PLEASE UPDATE THE PRICE AND QUANTITY OF"<<endl;
cout<<"     ITEMS IN MANAGE INVENTORY BEFORE PROCEEDING"<<endl<<endl;
cout<<"     1. MANAGE INVENTORY"<<endl;
cout<<"     2. VIEW INVENTORY"<<endl;
cout<<"     3. TAKE ORDER"<<endl;
cout<<"     4. EXIT"<<endl<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
while(ch!=1||ch!=2||ch!=3)
{
switch(ch)
{
case 1:
mnginvt();
break;
case 2:
viewinvt();
break;
case 3:
handlecust();
break;
case 4:
exit(0);
default:
cout<<endl<<"     INVALID CHOICE"<<endl<<endl;
cout<<"     ENTER CHOICE"<<endl<<endl;
cout<<"     ";cin>>ch;
}
}
}
void store::mnginvt()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     1. EDIT PRICE"<<endl;
cout<<"     2. ENTER QUANTITY"<<endl<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
while(ch!=1||ch!=2)
{
switch(ch)
{
case 1:
price();
break;
case 2:
quantity();
break;
default:
cout<<endl<<"     INVALID CHOICE"<<endl<<endl;
cout<<"     ENTER CHOICE"<<endl<<endl;
cout<<"     ";cin>>ch;
}
}
}
void store::price()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     CURRENT INVENTORY"<<endl;
cout<<"     "<<"ITEM"<<" - "<<"PRICE"<<endl;
cout<<"     ------------"<<endl;
    int snacks;
    if(conn){
cout<<endl<<"     ENTER PRICE OF SNACKS"<<endl;
cout<<"     ";cin>>snacks;cout<<endl;
stringstream ss;
        ss << "UPDATE price1 SET price = "<< snacks << " WHERE name = '" << "snacks" << "'";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
    }
    int maggipr;
    if(conn){
cout<<"     ENTER PRICE OF MAGGI"<<endl;
cout<<"     ";cin>>maggipr;cout<<endl;
stringstream ss1;
        ss1 << "UPDATE price1 SET price = "<< maggipr << " WHERE name = '" << "maggi" << "'";
        string query = ss1.str();
        const char* q = query.c_str();
        qstate1 = mysql_query(conn, q);
    }
    int sdpr;
    if(conn){
cout<<"     ENTER PRICE OF SOFT DRINK"<<endl;
cout<<"     ";cin>>sdpr;cout<<endl;
       stringstream ss2;
        ss2 << "UPDATE price1 SET price = "<< sdpr << " WHERE name = '" << "softdrink" << "'";
        string query = ss2.str();
        const char* q = query.c_str();
        qstate2 = mysql_query(conn, q);
    }

system("CLS");cout<<endl;
gotoxy(40,0);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     NEW INVENTORY"<<endl;
cout<<"     "<<"ITEM"<<" - "<<"PRICE"<<endl;
cout<<"     ------------"<<endl;
if(conn){
        int qstate = mysql_query(conn, "SELECT name,price FROM price1");

        if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){

                    cout <<row[0] <<"\t | \t" << row[1] <<"\t | \t" << endl << endl;
             }
        }
    }
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();storepage();
}
void store::quantity()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     CURRENT INVENTORY"<<endl;
//ifstream currqty("QUANTITY.txt");
cout<<"     "<<"ITEM"<<" - "<<"QUANTITY"<<endl;
cout<<"     ---------------"<<endl;
    if(conn)
    {
cout<<endl<<"     ENTER QUANTITY OF SNACKS"<<endl;
cout<<"     ";cin>>snacksqty;cout<<endl;
        stringstream ss;
        ss << "UPDATE quantity SET quan = "<< snacksqty<< " WHERE name = '" << "snacks" << "'";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
    }
    if(conn)
    {
cout<<"     ENTER QUANTITY OF MAGGI"<<endl;
cout<<"     ";cin>>maggiqty;cout<<endl;
stringstream ss1;
        ss1 << "UPDATE quantity SET quan = "<< maggiqty<< " WHERE name = '" << "maggi" << "'";
        string query = ss1.str();
        const char* q = query.c_str();
        qstate1 = mysql_query(conn, q);
    }
    if(conn)
    {
cout<<"     ENTER QUANTITY OP SOFT DRINK"<<endl;
cout<<"     ";cin>>sdqty;cout<<endl;
stringstream ss2;
        ss2 << "UPDATE quantity SET quan = "<< sdqty<< " WHERE name = '" << "softdrink" << "'";
        string query = ss2.str();
        const char* q = query.c_str();
        qstate2 = mysql_query(conn, q);
    }
system("CLS");

gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     NEW INVENTORY"<<endl;
cout<<"     "<<"ITEM"<<" - "<<"QUANTITY"<<endl;
cout<<"     --------------------"<<endl;
 if(conn){
        int qstate = mysql_query(conn, "SELECT name,quan FROM quantity");

        if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){

                    cout <<row[0] <<"\t | \t" << row[1] <<"\t | \t" << endl << endl;
             }
        }
}
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
storepage();
}
void store::viewinvt()
{
     if(conn){
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     PRICE OF ITEMS IN CANTEEN"<<endl;
cout<<"     ITEM - PRICE"<<endl;
cout<<"     ------------"<<endl;
int qstate = mysql_query(conn, "SELECT name,price FROM price1");

        if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){

                    cout <<row[0] <<"\t | \t" << row[1] <<"\t | \t" << endl << endl;
             }
        }
cout<<endl<<"     QUANTITY OF ITEMS IN CANTEEN"<<endl;
cout<<"     ITEM - QUANTITY"<<endl;
cout<<"     ---------------"<<endl;
        int qstate1 = mysql_query(conn, "SELECT name,quan FROM quantity");

        if(!qstate1){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){

                    cout <<row[0] <<"\t | \t" << row[1] <<"\t | \t" << endl << endl;
             }
        }
     }
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
storepage();
}
class billing
{
public:
string name;
int cost1,cost2,cost3,qty,totalcost;
store s;
int amt;
char dec;
void viewstat();
void clearstat();
billing()
{
cost1=0;
cost2=0;
cost3=0;
}
void bill1(int qty)
{
      int qstate = mysql_query(conn,"SELECT price FROM price1"" where name='snacks'");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
cost1=0;
cost1=atoi(row[0])*qty;
}
}
}
void bill2(int qty)
{
    int qstate = mysql_query(conn,"SELECT price FROM price1"" where name='maggi'");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
cost2=0;
cost2=atoi(row[0])*qty;
}
}
}
void bill3(int qty)
{
    int qstate = mysql_query(conn,"SELECT price FROM price1"" where name='softdrink'");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
cost3=0;
cost3=atoi(row[0])*qty;
}
}
}
void bill()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
totalcost=cost1+cost2+cost3;
cout<<"     ENTER NAME OF CUSTOMER"<<endl;
cout<<"     ";cin>>name;cout<<endl;
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     BILL : PAY FOLLOWING AMOUNT "<<endl;
cout<<"     CUSTOMER NAME : "<<name<<endl;
cout<<"     TOTAL COST IS : "<<"$"<<totalcost<<endl;;
cout<<"     THANK YOU HADRAMOUT"<<endl;
stringstream streamtotalcost;
    string stotalcost;
    streamtotalcost << totalcost;
    streamtotalcost >> stotalcost;
string ss = "insert into salesrecord (name, tamount) values ('"+name+"','"+stotalcost+"')";
        const char* q = ss.c_str();
        qstate = mysql_query(conn, q);
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
billpage();
}
};
void billing::viewstat()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     NAME - AMOUNT"<<endl;
cout<<"     -------------"<<endl;
int qstate = mysql_query(conn, "SELECT * FROM salesrecord");

        if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){

                    cout << row[0] <<"\t | \t" << row[1] <<"\t | \t"  << endl << endl;
             }
        }
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
empjump();
}
void billing::clearstat()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     CLEAR SALES RECORD [Y/y]"<<endl;
cout<<"     ";cin>>dec;
if(dec=='Y'|| dec=='y')
{
string delete_query = "truncate table salesrecord";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);
cout<<endl<<"     SALES RECORD CLEARED"<<endl;
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
empjump();
}
else
{
cout<<endl<<"     SALES RECORD ARE NOT CLEARED"<<endl;
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
empjump();
}
}
class order
{

public:

int tqty;
string titem;
billing b;
int invtqty;
string invtitem;
char dec;
int ch;
int qty;
void orderitem1();
void orderitem2();
void orderitem3();
void orderpageswitch();
void orderpage()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     1. SNACKS"<<endl;
cout<<"     2. MAGGI"<<endl;
cout<<"     3. SOFT DRINK"<<endl;
cout<<"     4. EXIT"<<endl<<endl;
cout<<"     ENTER ITEM TO ORDER"<<endl;
cout<<"     ";cin>>ch;
orderpageswitch();
}
};
void order::orderpageswitch()
{
while(ch!=1||ch!=2||ch!=3||ch!=4)
{
switch(ch)
{
case 1:
orderitem1();
break;
case 2:
orderitem2();
break;
case 3:
orderitem3();
break;
case 4:
exit(0);
break;
default:
cout<<endl<<"     INVALID CHOICE"<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
}
}
}
void order::orderitem1()
{
    int qstate = mysql_query(conn,"SELECT AVG(quan) FROM quantity"" where name='snacks'");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
cout<<"     ENTER QUANTITY"<<endl;
cout<<"     ";cin>>qty;cout<<endl;
if (atoi (row[0]) >= qty)
{
        stringstream ss;
        int result=atoi(row[0])-qty;
        ss << "UPDATE quantity SET quan = "<<result<< " WHERE name = '" << "snacks" << "'";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

b.bill1(qty);
cout<<"     ORDER ANOTHER ITEM [Y/y]"<<endl;
cout<<"     ";cin>>dec;
if(dec=='Y'||dec=='y')
{
orderpage();
}
else
{
b.bill();
}
}
else
{
cout<<endl<<"     NOT AVAILABLE"<<endl;
cout<<"     SELECT ANOTHER ITEM"<<endl;
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     ITEM - QUANTITY"<<endl;
cout<<"     ---------------"<<endl;
int qstate = mysql_query(conn, "SELECT name,quan FROM quantity");

        if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){

                    cout <<row[0] <<"\t | \t" << row[1] <<"\t | \t" << endl << endl;
             }
        }

cout<<endl<<"     PRESS ANY KEY FOR NEW ORDER"<<endl;
cout<<"     ";_getch();
orderpage();
}
}
}
}
void order::orderitem2()
{
    int qstate = mysql_query(conn,"SELECT AVG(quan) FROM quantity"" where name='maggi'");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
cout<<"     ENTER QUANTITY"<<endl;
cout<<"     ";cin>>qty;cout<<endl;
if(atoi(row[0])>=qty){
    stringstream ss;
        int result=atoi(row[0])-qty;
        ss << "UPDATE quantity SET quan = "<<result<< " WHERE name = '" << "maggi" << "'";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

b.bill2(qty);
cout<<"     ORDER ANOTHER ITEM [Y/y]"<<endl;
cout<<"     ";cin>>dec;
if(dec=='Y'||dec=='y')
{
orderpage();
}
else
{
b.bill();
}
}
else
{
cout<<endl<<"     NOT AVAILABLE"<<endl;
cout<<"     SELECT ANOTHER ITEM"<<endl;
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     ITEM - QUANTITY"<<endl;
cout<<"     ---------------"<<endl;
int qstate = mysql_query(conn, "SELECT name,quan FROM quantity");

        if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){

                    cout <<row[0] <<"\t | \t" << row[1] <<"\t | \t" << endl << endl;
             }
        }
cout<<endl<<"     PRESS ANY KEY FOR NEW ORDER"<<endl;
cout<<"     ";_getch();
orderpage();
}
}
}
}
void order::orderitem3()
{
    int qstate = mysql_query(conn,"SELECT AVG(quan) FROM quantity"" where name='softdrink'");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
cout<<"     ENTER QUANTITY"<<endl;
cout<<"     ";cin>>qty;cout<<endl;
if(atoi(row[0])>=qty){
        stringstream ss;
        int result=atoi(row[0])-qty;
        ss << "UPDATE quantity SET quan = "<<result<< " WHERE name = '" << "softdrink" << "'";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
b.bill3(qty);
cout<<"     ORDER ANOTHER ITEM [Y/y]"<<endl;
cout<<"     ";cin>>dec;
if(dec=='Y'||dec=='y')
{
orderpage();
}
else
{
b.bill();
}
}
else
{
cout<<endl<<"     NOT AVIALABLE"<<endl;
cout<<"     SELECT ANOTHER ITEM"<<endl;
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     ITEM - QUANTITY"<<endl;
cout<<"     ---------------"<<endl;
int qstate = mysql_query(conn, "SELECT name,quan FROM quantity");

        if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){

                    cout <<row[0] <<"\t | \t" << row[1] <<"\t | \t" << endl << endl;
             }
        }
cout<<endl<<"     PRESS ANY KEY FOR NEW ORDER"<<endl;
cout<<"     ";_getch();
orderpage();
}
}
}
}
class employee
{
public:
int ch,age;
char name[50];
long int sal;
void addemp();
void displayemp();
void removeemp();
void editemp();
void emppageswitch();
void emppage()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     1. DISPLAY ALL EMPLOYEE DETAILS"<<endl;
cout<<"     2. ADD NEW EMPLOYEE DETAILS"<<endl;
cout<<"     3. REMOVE OLD EMPLOYEE DETAILS"<<endl;
cout<<"     4. VIEW SALES RECORD"<<endl;
cout<<"     5. CLEAR SALES RECORD"<<endl;
cout<<"     6. STOREPAGE"<<endl;
cout<<"     7. EXIT"<<endl<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
emppageswitch();
}
};
void employee::emppageswitch()
{
while(ch!=1||ch!=2||ch!=3||ch!=4||ch!=5)
{
switch(ch)
{
case 1:
displayemp();
break;
case 2:
addemp();
break;
case 3:
removeemp();
break;
case 4:
{
billing b1;
b1.viewstat();
}
break;
case 5:
{
billing b2;
b2.clearstat();
}
case 6:
{
store s;
s.storepage();
}
break;
case 7:
exit(0);
break;
default:
cout<<endl<<"     INVALID CHOICE"<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
}
}
}
void employee::addemp()
{
system("CLS");
    int age,sal;
        string name,pass;
        stringstream streamage, streamsal;
    string sage, ssal;
    streamage << age;
    streamage >> sage;
    streamsal << sal;
    streamsal >> ssal;

gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     ENTER NAME OF EMPLOYEE"<<endl;
cout<<"     ";cin>>name;
cout<<"     ENTER AGE OF EMPLOYEE"<<endl;
cout<<"     ";cin>>sage;
cout<<"     ENTER SALARY OF EMPLOYEE"<<endl;
cout<<"     ";cin>>ssal;
cout<<"     ENTER PASSWORD OF EMPLOYEE"<<endl;
cout<<"     ";cin>>pass;
        string ss = "insert into emp (name, age, salary, pass) values ('"+name+"','"+sage+"','"+ssal+"','"+pass+"')";
        const char* q = ss.c_str();
        qstate = mysql_query(conn, q);

cout<<endl<<"     EMPLOYEE ADDED"<<endl;
cout<<endl<<"     PRESS ANY KEY TO CONTINUE";
cout<<"     ";_getch();
emppage();
}
void employee::displayemp()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
        int qstate = mysql_query(conn, "SELECT * FROM emp");

        if(!qstate){
            res = mysql_store_result(conn);
                cout<<"EMPLOYEE |\t AGE\t |\tSALARY\t|\tPASSWORD\t |"<<endl;
                    cout<<"---------------------------------------------------------------------"<<endl;
            while(row = mysql_fetch_row(res)){

                    cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<"\t | \t"  << endl << endl;
             }
        }
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
emppage();
}
void employee::removeemp()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
        string tname;
cout<<"     ENTER THE NAME OF EMPLOYEE WISH TO REMOVE"<<endl;
cout<<"     ";cin>>tname;

        stringstream ss;
        ss << "DELETE FROM emp " << " WHERE name = '" << tname << "'";
         string query = ss.str();

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

cout<<endl<<"     EMPLOYEE REMOVED"<<endl;
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
emppage();
}
class login
{
public:
string pass="";
int ch;
char c;
void loginpageswitch();
void homepageswitch();
void employeelogin();
void ownerlogin();
void regpageswitch();
void ownerreg();
void emp();
void own();
void homepage()
{
system("CLS");
gotoxy(40,1);cout<<"WELCOME TO HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"----------------------------"<<endl<<endl;
cout<<"     1. REGESTER"<<endl;
cout<<"     2. LOGIN"<<endl;
cout<<"     3. EXIT"<<endl<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
homepageswitch();
}
void regpage()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     1. OWNER REGESTER"<<endl;
cout<<"     2. EXIT"<<endl<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
regpageswitch();
}
void loginpage()
{
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     1. OWNER LOGIN"<<endl;
cout<<"     2. EMPLOYEE LOGIN"<<endl;
cout<<"     3. EXIT"<<endl<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
loginpageswitch();
}
};
void login::homepageswitch()
{
while(ch!=1||ch!=2 ||ch!=3)
{
switch(ch)
{
case 1:
regpage();
break;
case 2:
loginpage();
break;
case 3:
exit(0);
break;
default:
cout<<endl<<"     INVALID CHOICE"<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
}
}
}
void login::regpageswitch()
{
while(ch!=1||ch!=2||ch!=3)
{
switch(ch)
{
case 1:
ownerreg();
break;
case 2:
exit(0);
break;
default:
cout<<endl<<"     INVALID CHOICE"<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
}
}
}
void login::loginpageswitch()
{
while(ch!=1||ch!=2||ch!=3)
{
switch(ch)
{
case 1:
ownerlogin();
break;
case 2:
employeelogin();
break;
case 3:
exit(0);
break;
default:
cout<<endl<<"     INVALID CHOICE"<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
}
}
}
void login::ownerreg()
{
    string owner,pass;
cout<<"     ";cout<<"ENTER THE OWNER NAME:\n";
cout<<"     ";cin>>owner;
cout<<"     ";cout<<"ENTER THE PASSWARD:\n";
cout<<"     ";cin>>pass;
string ss = "insert into own1 (name, pass) values ('"+owner+"','"+pass+"')";
        const char* q = ss.c_str();
        qstate = mysql_query(conn, q);

login e;
e.homepage();
}

void login::ownerlogin()
{
    string pass1="",towner;
    cout<<"     ENTER OWNER NAME"<<endl;
    cout<<"     ";cin>>towner;
                string ss = "select pass from own1 where name like '%"+towner+"%'";
                const char* qn = ss.c_str();
                qstate = mysql_query(conn, qn);
            if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){
            cout<<endl<<"     ENTER OWNER PASSWORD"<<endl;
cout<<"     ";c=_getch();
while(c!=13)
{
pass1.push_back(c);
cout<<"*";
c=_getch();
}
if(pass1==row[0]){
cout<<endl<<"     OWNER ACCESS GRANTED"<<endl;
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
own();
}
else
{
cout<<endl<<"     INVALID PASSWORD"<<endl;
}
}
}
}
void login::employeelogin()
{
string pass="",tname;
    cout<<"     ENTER EMPLOYEE NAME"<<endl;
    cout<<"     ";cin>>tname;
                string ss = "select pass from emp where name like '%"+tname+"%'";
                const char* qn = ss.c_str();
                qstate = mysql_query(conn, qn);
            if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){
cout<<"     ENTER EMPLOYEE PASSWORD"<<endl;
cout<<"     ";c=_getch();
while(c!=13)
{
pass.push_back(c);
cout<<"*";
c=_getch();
}
if(pass==row[0])
{
cout<<endl<<"     EMPLOYEE ACCESS GRANTED"<<endl;
cout<<endl<<"     PRESS ANY KEY TO CONTINUE"<<endl;
cout<<"     ";_getch();
emp();
}
else
{
cout<<endl<<"     INVALID PASSSWORD"<<endl;
}
}
}
}
void login::emp()
{
store s;
s.storepage();
}
void login::own()
{
employee e;
e.emppage();
}
void billpage()
{
int ch;
system("CLS");
gotoxy(40,1);cout<<"HADRAMOUT CANTEEN";
gotoxy(40,2);cout<<"-----------------"<<endl<<endl;
cout<<"     1. NEW ORDER"<<endl;
cout<<"     2. EXIT"<<endl<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
while(ch!=1||ch!=2)
{
switch(ch)
{
case 1:
{
order o;
o.orderpage();
}
break;
case 2:
exit(0);
break;
default:
cout<<endl<<"     INVALID CHOICE"<<endl;
cout<<"     ENTER CHOICE"<<endl;
cout<<"     ";cin>>ch;
}
}
}
void handlecust()
{
order o;
o.orderpage();
}
void billjump()
{
billing b;
b.viewstat();
}
void empjump()
{
employee e;
e.emppage();
}

int main()
{
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"192.168.56.1","ahmed","ahmed","project",0,NULL,0);
system("title CANTEEN MANAGEMENT SYSYTEM");
system("color 71");
login l;
l.homepage();
return 0;
}
