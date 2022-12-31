#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<iomanip>
using namespace std;

//int Pres=0, Abs=0;
int date,month,year;
int n,m,a,c,l;
int s=5;
int g;
string filename = "attx.txt";
string temp = "tmp.txt";

int datecheck();
int attendenter();
void attendancestatus();
void studentnames();
int attendancerates();
int session();
void foutnameP();
void foutnameA();
void showrecord();
void deleting();

struct Class {
	char classname[30];
	char teachername[40];
	int hh,mm;
};
int main() {
	cout<<endl<<"\t\t=======PRESS ANY KEY TO ENTER THE ATTENDANCE SYSTEM======="<<endl<<endl;
	g = getch();
	while(g) {
		int p;
		cout<<endl<<"Please Input Your Choice: "<<endl<<endl;
		cout<<"1. Mark Attendance"<<endl
		    <<"2. Show Attendance Record"<<endl
		    <<"3. Delete all records"<<endl<<endl
		    <<"==>Your Choice: ";
		cin>>p;
		cout<<endl;
		if(p==1) {
			ofstream fout(filename, ios::app);
			Class info;
			cout<<"=>Please type in class name: ";
			cin.getline(info.classname, 30);
			cin.getline(info.classname, 30);
			fout<<endl<<"Class name : "<<"\t"<<info.classname;
			cout<<endl;
			fout<<endl;
			cout<<"=>Please type in teacher name: ";
			cin.getline(info.teachername, 40);
			fout<<"Teacher name : "<<"\t"<<info.teachername;
			cout<<endl;
			cout<<"=>Please type in time in 24hrs format: ";
			cin>>info.hh>>info.mm;
			fout<<endl<<"Time : "<<"\t"<<info.hh;
			fout<<":"<<info.mm;
			cout<<endl<<endl;
			fout<<endl<<endl;

			cout<<"\t<->-<->-<->-<->-<-> Student Attendance System <->-<->-<->-<->-<->"<<endl<<endl;
			attendenter();
			fout.close();
		} else if(p==2) {
			showrecord();
			cout<<endl;
		} else if(p==3) {
			deleting();
			cout<<"\t\t******ALL RECORDS ARE DELETED******"<<endl;
		} else {
			cout<<"Please Input The Correct Choice!!!\a\a\a"<<endl<<endl
			    <<"Press Any Key To Input Choice again ";
			getch();
			cout<<endl<<endl;
		}
		cout<<endl<<"   =======ENTER 1 TO GO BACK TO MAIN SCREEN ELSE 0 FOR EXIT======= : ";
		cin>>g;
		cout<<endl;
		system("cls");
	}

}

int datecheck() { //date checking
	if(month== 1||month==3||month==5||month==7||month==8||month==10||month==12) {
		if(date>31||date==0) {
			c=0;
		} else {
			c=1;
		}
	}
	if(month== 4||month==6||month==9||month==11) {
		if(date>30 ||date==0) {
			c=0;
		} else {
			c=1;
		}
	}
	if(month==2) {
		if(date>29||date==0) {
			c=0;
		} else {
			c=1;
		}
	}
	if(month>12||month==0||year==0)	c=0;
	return c;
}

int attendenter() { //update the attendance
	cout<<"\t\t=======PRESS ANY KEY TO ENTER THE SYSTEM======="<<endl;
	g = getch();
	cout<<endl;
	while(g) {
		cout<<endl<<"==>Enter DATE/MONTH/YEAR: "<<endl;
		cin>>date>>month>>year;
		cout<<endl;
		c = datecheck();  //checking the date accuracy
		switch(c) { //gives if the given date is correct or not and update
			case 0:
				cout<<"Please enter::VALID DATE::\a\a\a"<<endl<<endl;
				break;
			case 1:
				cout<<"=====> PLEASE INPUT SESSION NUMBER =========> : ";
				cin>>n;
				m = n+s;
				cout<<endl;
				while(n<m) {
					cout<<"Select a student to update the attandance"<<endl<<endl;
					cout<<" 1. Samnang Pheng"<<endl
					    <<" 2. Mongkol Heng"<<endl
					    <<" 3. Vathanak Sry"<<endl
					    <<" 4. Sethyreach Ouk"<<endl
					    <<" 5. Marathon Moul"<<endl;
					cout<<"\nPlease choose by input student number: ";
					cin>>l;
					cout<<endl;
					if((l>0) && (l<6)) {
						studentnames();
						m--;
					} else {
						cout<<"\t\t  !!!!!! Invalid Student Number !!!!!!\a\a\a"<<endl<<endl;
					}

				}

				cout<<"   =======ENTER 1 TO UPDATE OTHER ATTENDANCE ELSE 0 FOR EXIT======= : ";
				cin>>g;
				cout<<endl;
				system("cls");

				break;
			default://To exit
				exit(0);
		}

	}
}

void studentnames() { //list all student name with status of P/A function
	if(l==1) {
		cout<<" 1. Samnang Pheng :"<<endl<<endl;
		attendancestatus();
	}
	if(l==2) {
		cout<<" 2. Mongkol Heng: "<<endl<<endl;
		attendancestatus();
	}
	if(l==3) {
		cout<<" 3. Vathanak Sry: "<<endl<<endl;
		attendancestatus();
	}
	if(l==4) {
		cout<<" 4. Sethyreach Ouk: "<<endl<<endl;
		attendancestatus();
	}
	if(l==5) {
		cout<<" 5. Marathon Moul: "<<endl<<endl;
		attendancestatus();
	}
}

void attendancestatus() { //update as P/A
	cout<<"->ENTER '1' IF PRESENT ELSE '0' TO UPDATE THE STATUS OF SESSION "<<n<<" : ";
	cin>>a;
	if(a==1) {
//                Pres++;
		cout<<"   ......................................................................"<<endl<<endl;
		cout<<"                         :::UPDATED AS PRESENT:::"<<endl<<endl;
		cout<<"   ......................................................................"<<endl<<endl;
	} else {
//                Abs++;
		cout<<"   ......................................................................"<<endl<<endl;
		cout<<"                          :::UPDATED AS ABSENT:::"<<endl<<endl;
		cout<<"   ......................................................................"<<endl<<endl;
	}
	cout<<endl;
	cout<<"              ::::::ATTENDANCE OF THE DAY IS UPDATED AS:::::"<<endl;
	cout<<endl<<endl;
	cout<<"DD/MM/YY    ";
	cout<<endl<<endl;
	ofstream fout(filename, ios::app);
	cout<<date<<"/"<<month<<"/"<<year<<"\t";
	fout<<date<<"/"<<month<<"/"<<year<<"\t";
	fout<<"Session"<<"|"<<n<<"|";
	if(a==1) foutnameP();
	else foutnameA();
	cout<<endl<<endl;
	fout<<endl;
	cout<<endl;
	cout<<endl;
	fout.close();
}

void foutnameP() { //write student names to txt file (Present)
	ofstream fout(filename, ios::app);
	if(l==1) {
		cout<<l<<"."<<"Samnang Pheng";
		fout<<l<<"."<<"Samnang Pheng"<<setw(5);
		cout<<" P "<<"     ";
		fout<<" P "<<" ";
	} else if(l==2) {
		cout<<l<<"."<<"Mongkol Heng";
		fout<<l<<"."<<"Mongkol Heng"<<setw(6);
		cout<<" P "<<"     ";
		fout<<" P "<<" ";
	} else if(l==3) {
		cout<<l<<"."<<"Vathanak Sry";
		fout<<l<<"."<<"Vathanak Sry"<<setw(6);
		cout<<" P "<<"     ";
		fout<<" P "<<" ";
	} else if(l==4) {
		cout<<l<<"."<<"Sethyreach Ouk";
		fout<<l<<"."<<"Sethyreach Ouk"<<setw(4);
		cout<<" P "<<"     ";
		fout<<" P "<<" ";
	} else if(l==5) {
		cout<<l<<"."<<"Marathon Moul";
		fout<<l<<"."<<"Marathon Moul"<<setw(5);
		cout<<" P "<<"     ";
		fout<<" P "<<" ";
	}
}

void foutnameA() { //write student names into txt file (Absent)
	ofstream fout(filename, ios::app);
	if(l==1) {
		cout<<l<<"."<<"Samnang Pheng";
		fout<<l<<"."<<"Samnang Pheng"<<setw(5);
		cout<<" A "<<"     ";
		fout<<" A "<<" ";
	} else if(l==2) {
		cout<<l<<"."<<"Mongkol Heng";
		fout<<l<<"."<<"Mongkol Heng"<<setw(6);
		cout<<" A "<<"     ";
		fout<<" A "<<" ";
	} else if(l==3) {
		cout<<l<<"."<<"Vathanak Sry";
		fout<<l<<"."<<"Vathanak Sry"<<setw(6);
		cout<<" A "<<"     ";
		fout<<" A "<<" ";
	} else if(l==4) {
		cout<<l<<"."<<"Sethyreach Ouk";
		fout<<l<<"."<<"Sethyreach Ouk"<<setw(4);
		cout<<" A "<<"     ";
		fout<<" A "<<" ";
	} else if(l==5) {
		cout<<l<<"."<<"Marathon Moul";
		fout<<l<<"."<<"Marathon Moul"<<setw(5);
		cout<<" A "<<"     ";
		fout<<" A "<<" ";
	}
	fout.close();

}

void showrecord() { //display all records in txt file
	ifstream filename;
	filename.open("attx.txt");
	string line;
	while(!filename.eof()) {
		getline(filename,line);
		cout<<"\t\t"<<line<<endl;
	}
	filename.close();
}

void deleting() { //delete all record in txt file
	string line, name;
	ifstream filename;
	ofstream temp;
	filename.open("attx.txt");
	temp.open("tmp.txt");
	while (getline(filename, line)) {
		filename.close();
		temp.close();
		remove("attx.txt");
		rename("tmp.txt", "attx.txt");
	}
}
