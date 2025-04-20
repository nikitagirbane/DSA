#include <iostream> 
#include <fstream> 
#include <cstring> 
using namespace std; 
class Emp 
{ 
int empid; 
char name[20]; 
char design[20]; 
f
 loat salary; 
public:  
Emp() 
{ 
empid=0; 
strcpy(name,""); 
strcpy(design,""); 
salary=0.0; 
} 
int acceptempid() 
{ 
return(empid); 
} 
void getdata() 
{ 
cout<<"\nEnter Emp details:"; 
cout<<"\nEnter emp id:"; 
cin>>empid; 
cout<<"Enter emp name : "; 
cin>>name; 
cout<<"Enter Designa on : "; 
cin>>design; 
cout<<"Enter salary: "; 
cin>>salary; 
} 
void display() 
{ 
cout<<"\n Emp Details"; 
cout<<"\n Emp id = "<<empid; 
cout<<"\n Emp Name = "<<name; 
cout<<"\n Designa on = "<<design; 
cout<<"\n Salary = "<<salary; 
} 
}; 
class fileop 
{ 
ifstream fin; 
ofstream fout; 
fstream fs; 
public: 
void insert(); 
void show(); 
void search(int); 
int deleterecord(int); 
int append(int); 
}; 
void fileop::insert() 
{ 
Emp obj; 
obj.getdata(); 
fout.open("data.txt",ios::ate|ios::app); 
fout.write((char*)&obj,sizeof(obj)); 
fout.close(); 
} 
void fileop::show() 
{ 
Emp obj; 
f
 in.open("data.txt"); 
f
 in.seekg(0,ios::beg); 
while(fin.read((char*)&obj,sizeof(obj))) 
{ 
obj.display(); 
} 
f
 in.close(); 
} 
void fileop::search(int rno) 
{ 
Emp obj; 
int flag=0; 
f
 in.open("data.txt"); 
f
 in.seekg(0,ios::beg); 
while(fin.read((char*)&obj,sizeof(obj))) 
{ 
if(obj. acceptempid()==rno) 
{ 
f
 lag=1; 
break; 
} 
} 
f
 in.close(); 
if(flag==1) 
{ 
cout<<"\n Emp found"; 
obj.display(); 
} 
else 
{ 
cout<<"\n Emp not found"; 
} 
} 
int fileop::deleterecord(int rno) 
{ 
Emp obj; 
int flag=0; 
f
 in.open("data.txt"); 
f
 in.seekg(0,ios::beg); 
while(fin.read((char*)&obj,sizeof(obj))) 
{ 
if(obj. acceptempid()==rno) 
{ 
f
 lag=1; 
} 
else 
{ 
fout.write((char*)&obj,sizeof(obj)); 
} 
} 
f
 in.close(); 
fout.close(); 
remove("data.txt"); 
rename("temp.txt","data.txt"); 
return(flag); 
} 
int fileop::append(int rno) 
{ 
Emp obj; 
int flag=0; 
fs.open("data.txt"); 
fs.seekg(0,ios::beg); 
while(fs.read((char*)&obj,sizeof(obj))) 
{ 
if(obj. acceptempid()==rno) 
{ 
f
 lag=1; 
cout<<"\n Enter new details: "; 
obj.getdata(); 
fs.seekp((int)fs.tellg()-sizeof(obj),ios::beg); 
fs.write((char*)&obj,sizeof(obj)); 
} 
} 
fs.close(); 
return(flag); 
}
