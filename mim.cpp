#include<bits/stdc++.h>
#include<cstdlib>
#include <iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;
void intro();
void menu();

//---------------------------PASSWARD---------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
class passward
{
private:
  char username[20];
  char pass[12];
public:
    void fix_pass();
};

void passward::fix_pass()
{
    cout<<"________________________\n";
    cout<<"|                       |\n";
    cout<<"|       LOG IN          |\n";
    cout<<"|_______________________|\n";
    cout<<"\n \n \n";
    cout<<"\t\t---------------------------------------------------------\n";
    cout<<"\t\t---------------------------------------------------------\n";
    cout<<"\n\n\n";
    cout <<"ENTER USERNAME : ";
    cin>>username;
    cout<<"\nENTER PASSWARD  : ";
    char ch;
    int i=0,j=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            pass[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                cout<<"\b \b";
            }
        }
        else if(ch==32||ch==9)
        {
            continue;
        }
        else
        {
            pass[i]=ch;
            i++;
            cout<<"*";
            if(i==10)
            break;
        }

    }
    pass[i]='\0';
    cout<<"\n";
    if(strcmp(username,"jarnaz")==0&&(strcmp(pass,"digital")==0))
    {
        cout<<"";
    }
    else
    {
        cout<<"\n\n !!Sorry Try Again.....\n"<<endl;
        getch();
        system("cls");
        fix_pass();
        system("cls");

    }
}

//___________________________________________________________________________________
//_____________________________DOCTORS DATABASE STARTED FROM HERE____________________
//___________________________________________________________________________________
class doctor
{
private:
    int docid;
    char Q[20],age[20],exp[20],city[20],special[20];
    char name[20];
    int id;
public:
    doctor()
    {
        docid=0;
    }
    int ret_id()
    {
        return id;
    }
    void add_doc_info();
    void detail();
    void write_docinfo_file();
    void search_file_doc();
    void view_doc_data_detail();
    void delete_doc_data();
    void update_docinfo(char *t);
};
void doctor::add_doc_info()
{
    int i,en;
    cout<<"\n\n";
    cout<<"\t--------------------------------------------------------------\n";
    cout<<"\t--------------------------------------------------------------\n\n";
    cout<<"\t\t Enter the doctor information :\n\n";
    en=1;
    for(i=1;i<=en;i++)
    {
    cout<<"Enter Doctor ID : ";
    cin>>id;
    cout<<"Enter Doctor Name : ";
    cin>>name;
    cout<<"Enter Doctor Age : ";
    cin>>age;
    cout<<"Enter Doctor Qualification : ";
    cin>>Q;
    cout<<"Enter Doctor Specialization : ";
    cin>>special;
    cout<<"Enter Doctor Experience : ";
    cin>>exp;
    cout<<"Enter Doctor city : ";
    cin>>city;
    cout<<"\n\n";
    docid++;
    }
}

void doctor::detail()
{
    int i;
    if(docid==0)
    {
        cout<<" \n\n\n OOPS!!!! "<<"\n\n";
        cout<<"Note:- No Record To Display Plz Go Back And Enter Some Entries…… "<<"\n";
    }
    else
    {
        cout<<"\n";
        cout<<"\n\t"<<name<<"\t \t"<<id<<"\t \t"<<special<<"\t \t \t"<<age<<"\n";
        cout<<"\n";
    }
}
//_______________________________________________________________________________
//__________________________FOUND DOCTORS FILES________________________________________
//_______________________________________________________________________________

void doctor::write_docinfo_file()
{
   ofstream out;
    out.open("doctor.txt",ios::app|ios::binary);
    out.write((char*)this,sizeof(*this));
    out.close();
}

void doctor::view_doc_data_detail()
{
     ifstream in;
    in.open("doctor.txt",ios::in|ios::binary);
    if(!in)
    cout<<"\nfile not found";
    else
    {
        in.read((char*)this,sizeof(*this));
        while(!in.eof())
        {
            detail();
            in.read((char*)this,sizeof(*this));
        }
        in.close();
    }
}

void doctor::search_file_doc()
{
    cout<<"\n\n";
    cout<<"\t--------------------------------------------------------------\n";
    cout<<"\t--------------------------------------------------------------\n\n";
    cout<<"\t\t Enter the doctors id to display Record :";
    int n,c=0;
    cin>>n;
    ifstream in;
    in.open("doctor.txt",ios::in);
    in.read((char*)this,sizeof(*this));
    while(!in.eof())
    {
        if(n==id)
        {
            c=1;
            cout<<"\n\n";
            cout<<"1.Doctor ID   :"<<id<<"\n";
            cout<<"2.Doctor Name :"<<name<<"\n";
            cout<<"3.Doctor Age  :"<<age<<"\n";
   cout<<"4.Doctor Qualification :"<<Q<<"\n";
  cout<<"5.Doctor Specialization :"<<special<<"\n";
      cout<<"6.Doctor Experience :"<<exp<<"\n";
            cout<<"8.Doctor city :"<<city<<"\n";
        }
        in.read((char*)this,sizeof(*this));
    }
        if(c==0)
            cout<<"\n\n\t\t Sorry record not found....\n";
        in.close();
}
void doctor:: delete_doc_data()
{
    cout<<"\n\n";
    cout<<"\t--------------------------------------------------------------\n";
    cout<<"\t--------------------------------------------------------------\n\n";
    cout<<"\t\t Enter the id of Doctor : \n";
    int n;
    cin>>n;
    ifstream in;
    ofstream out;
    in.open("doctor.txt",ios::binary);
    if(!in)
    cout<<"\nfile not found";
    else
    {
        out.open("tempdoctor.txt",ios::binary);
        while(in.read((char*)this,sizeof(*this)))
        {
            if(ret_id()!=n)
                out.write((char*)this,sizeof(*this));
        }
        in.close();
        out.close();
        remove("doctor.txt");
        rename("tempdoctor.txt","doctor.txt");
    }

}

 void doctor::update_docinfo(char *t)
 {
     int c=0;
     fstream f;
    f.open("doctor.txt",ios::in | ios::out | ios::ate | ios::binary);
    f.seekg(0);
    while(f.read((char*)this,sizeof(*this)))
    {
        if(!strcmp(t,name))
        {
            add_doc_info();
			int pos=(-1)*static_cast<int>(sizeof(*this));
			f.seekp(pos,ios::cur);
            f.write((char*)this,sizeof(*this));
            cout<<"\n\n\n\tRecord Updated......\n";
            f.read((char*)this,sizeof(*this));
            c++;
        }
        else
        {
            if(c==0)
            cout<<"\n\n\t Oops..Record Not Found ...\n";
        }
    }
    f.close();
}

//_________________________________________________________________________________________________
//____________________________PATIENTS DATABASE STARTED FROM HERE__________________________________
//_________________________________________________________________________________________________
class patient
{
private:
    int id1,patid1;;
char name[20],age[20],city[20],dis[20],room[20],sym[20],con[20],date[20],charg[20],bill[20];
public:
    patient()
    {
        patid1=0;
    }
    int retp_id1()
    {
        return id1;
    }
    void add_pat_info();
    void patient_detail();
    void delete_pat_data(char *d);
    void pat_bill();
    void pat_data_store_file();
    void all_pat_detail_file2();
    void search_file_pat(char *p);
    void update_patinfo(char *t);
};
//_________________________________________________________________________________
//_________________________________________________________________________________
//_____________________[[PATEINTS FILES DEFINATIONS]]______________________________

void patient:: pat_data_store_file()
{
    ofstream out;
    out.open("patient.txt",ios::app|ios::binary);
    out.write((char*)this,sizeof(*this));
    out.close();
}

void patient::all_pat_detail_file2()
{
    ifstream in;
    in.open("patient.txt",ios::in|ios::binary);
    in.read((char*)this,sizeof(*this));
    if(!in)
    cout<<"\n\n\tfile not found \n";
    else
    {
    while(!in.eof())
    {
        patient_detail();
        in.read((char*)this,sizeof(*this));
    }
    in.close();
    }

}
void patient::search_file_pat(char *p)
{
    int c=0;
    ifstream in;
    in.open("patient.txt",ios::in|ios::binary);
    in.read((char*)this,sizeof(*this));
    while(!in.eof())
    {
        if(!strcmp(p,name))
        {
            c=1;
            cout<<"\n\n";
            cout<<"1.Patients ID             :  "<<id1<<endl;
            cout<<"2.Patients Name           :  "<<name<<endl;
            cout<<"3.Patients Age            :  "<<age<<endl;
            cout<<"4.Patients Disease        :  "<<dis<<endl;
            cout<<"5.Patients Symptoms       :  "<<sym<<endl;
            cout<<"6.Patients Room No.       :  "<<room<<endl;
            cout<<"7.condition Before Admit  :  "<<con<<endl;
            cout<<"8.Patients ADMIT Date     :  "<<date<<endl;
            cout<<"9.Patients Room Charge    :  "<<charg<<endl;
            cout<<"10. Medicine charge       :  "<<bill<<endl;
            cout<<" \n\n\t Press Any KEY To choose another Option…. ";
        }
        in.read((char*)this,sizeof(*this));
    }
        if(c==0)
            cout<<"\n Sorry record not found....\n";
        in.close();
}


//_______________________________________________________________________________
//_______________________________________________________________________________
//_________________[[PATEINTS FUNCTIONS DEFINATIONS ARE HERE]]___________________

void patient::add_pat_info()
{
    int i,n;
    n=1;
    cout<<"\n\n";
    cout<<"\t--------------------------------------------------------------\n";
    cout<<"\t--------------------------------------------------------------\n\n";
    cout<<"\t\t Enter the patient information : \n\n";
    cout<<"\n";
    for(i=1;i<=n;i++)
    {
    cout<<" 1.Enter Patients ID               :" ;
    cin>>id1;
    cout<<" 2.Enter patients Name             :" ;
    cin>>name;
    cout<<" 3.Enter patients Age              :" ;
    cin>>age;
    cout<<" 4.Enter patients Disease          :" ;
    cin>>dis;
    cout<<" 5.Enter patients Symptoms         :" ;
    cin>>sym;
    cout<<" 6.Enter Patients Room No.         :" ;
    cin>>room;
    cout<<" 7.Patients condition Before Admit :" ;
    cin>>con;
    cout<<" 8.Enter patients ADMIT Date       :" ;
    cin>>date;
    cout<<" 9.Enter Patients Room Charge      :" ;
    cin>>charg;
    cout<<" 10.Enter Patients Medicine charge :" ;
    cin>>bill;
    patid1++;
cout<<"\n";
cout<<"You filled all Entries of "<<i<<" patient successfully"<<"\n";
}
}

void patient:: patient_detail()
{
    int i;
    if(patid1==0)
    {
        cout<<" \n\n\n OOPS!!!! "<<"\n\n";
        cout<<"Note:- No Record To Display...\n";
        cout<<"Plz Go Back And Enter Some Entries...\n";
    }
    else
    {
        for(i=0;i<patid1;i++)
        {
            cout<<id1<<"\t\t"<<name<<"\t\t"<<dis<<"\t\t "<<date<<"\t\t\t"<<age<<"\n";
            cout<<"\n";
        }
    }
}

void patient:: delete_pat_data(char *d)
{
    ifstream in;
    ofstream out;
    in.open("patient.txt",ios::binary);
    if(!in)
    cout<<"\nfile not found";
    else
    {
        out.open("temppatient.txt",ios::binary);
        while(in.read((char*)this,sizeof(*this)))
        {
            if(strcmp(d,name))
                out.write((char*)this,sizeof(*this));
        }
        in.close();
        out.close();
        remove("patient.txt");
        rename("temppatient.txt","patient.txt");
    }

}
void patient::update_patinfo(char *t)
 {
     int c=0;
     fstream f;
    f.open("patient.txt",ios::in | ios::out | ios::ate | ios::binary);
    f.seekg(0);
    while(f.read((char*)this,sizeof(*this)))
    {
        if(!strcmp(t,name))
        {
            add_pat_info();
			int pos=(-1)*static_cast<int>(sizeof(*this));
			f.seekp(pos,ios::cur);
            f.write((char*)this,sizeof(*this));
            cout<<"\n\n\n\tRecord Updated......\n";
            //f.read((char*)this,sizeof(*this));
            c++;
        }
        else
        {
            if(c==0)
            cout<<"\n\n\t Oops..Record Not Found ...\n";
        }
    }
    f.close();
}
//__________________________________________________________
//__________________________________________________________
//________________GENERATE PATIENTS DATA____________________
//__________________________________________________________

class report
{
    char blood[10],hcv[10],hiv[10],cole[10],hemo[10],ecg[30],cag[30],bp[10],name[30],date[10];
    int id2;
public:
     void generate_pat_report_store_file();
     void generate_report_function_store();
     void generate_report_search_pat();

};

void report::generate_pat_report_store_file()
{
    ofstream out;
    out.open("report.txt",ios::app|ios::binary);
    out.write((char*)this,sizeof(*this));
    out.close();
}

void report::generate_report_function_store()
{
    int i,n;
    n=1;
    cout<<"\n\n";
    cout<<"\t--------------------------------------------------------------\n";
    cout<<"\t--------------------------------------------------------------\n\n";
    cout<<"\t\t Add the patient report information :\n\n";
    cout<<"\n";
    for(i=1;i<=n;i++)
    {
    cout<<" 1. ID              : ";
    cin>>id2;
    cout<<" 2. Name            : ";
    cin>>name;
    cout<<" 3. Blood group     : ";
    cin>>blood;
    cout<<" 4. cholesterol     : ";
    cin>>cole;
    cout<<" 5. HCV             : ";
    cin>>hcv;
    cout<<" 6. HIV             : ";
    cin>>hiv;
    cout<<" 7. Haemoglobin     : ";
    cin>>hemo;
    cout<<" 8. ECG             : " ;
    cin>>ecg;
    cout<<" 9. CAG             : " ;
    cin>>cag;
    cout<<" 10. Blood Pressure : ";
    cin>>bp;
    cout<<" 11. DATE           : ";
    cin>>date;
    cout<<"\n";
    cout<<"You filled all report information of patient successfully"<<"\n";
    }
}

void report::generate_report_search_pat()
{
    cout<<"\n\n";
    cout<<"\t\t Enter the patient id for display Reports :";
    int c=0,n;
    cin>>n;
    ifstream in;
    in.open("report.txt",ios::in|ios::binary);
    in.read((char*)this,sizeof(*this));
    while(!in.eof())
    {
        if(n==id2)
        {
            c=1;
            cout<<"\n\n";
            cout<<" 1. ID                 : "<<id2<<endl;
            cout<<" 2. Name               : "<<name<<endl;
            cout<<" 3. Blood group        : "<<blood<<endl;
            cout<<" 4. cholesterol        : "<<cole<<endl;
            cout<<" 5. HCV                : "<<hcv;
            cout<<" 6. HIV                : "<<hiv<<endl;
            cout<<" 7. Haemoglobin        : "<<hemo<<endl;
            cout<<" 8. ECG                : "<<ecg<<endl ;
            cout<<" 9. CAG                : "<<cag<<endl ;
           cout<<" 10. Blood Pressure     : "<<bp<<endl;
            cout<<" 11. DATE              : "<<date<<endl;
        }
        in.read((char*)this,sizeof(*this));
    }
        if(c==0)
            cout<<"\n Sorry record not found....\n";
        in.close();
}


//___________________________________________________________
//_______________MAIN MENU STARTED FROM HERE_________________
//___________________________________________________________

int main()
{
    intro();
    system("color F0");
    passward p;
    p.fix_pass();
    system("cls");
    menu();
    return 0;

}
//___________________________________________________________
//______________________MENU FUNCTION DEFINATION________________
//___________________________________________________________

void menu()
{
    //system("color F9");
    int ch1,b1,b2,b3,b4;
    doctor d;
    patient t;
    report r;
    char nam[20];
    x:
    cout<<"\n\n";
    cout<<"\n\t\t  ~~WELCOME TO CARDIALOGIST SECTION ~~\n";
    cout<<"\n";
    cout<<"\t\t ________________________________________\n";
    cout<<"\t\t|                                        |\n";
    cout<<"\t\t|                                        |\n";
    cout<<"\t\t|1. Enter into Doctors DataBase          |\n";
    cout<<"\t\t|2. Enter into Patients DataBase         |\n";
    cout<<"\t\t|3. Generate Patients Report             |\n";
    cout<<"\t\t|4 .Exit                                 |\n";
    cout<<"\t\t|                                        |\n";
    cout<<"\t\t|________________________________________|\n";
    cout<<"\n\n";
    cout<<"\t--------------------------------------------------------------\n";
    cout<<"\t--------------------------------------------------------------\n\n";
    cout<<"\n\nPlease Enter Your choice :"<<" ";
    cin>>ch1;
    system("cls");
    switch(ch1)
    {
        case 1:
            cout<<"\n\n";
            cout<<"\n\t\t  ***Welcome TO Doctors Database ***   \n";
            cout<<"\t\t ________________________________________\n";
            cout<<"\t\t|                                        |\n";
            cout<<"\t\t|                                        |\n";
            cout<<"\t\t|1. Add New Doctors Information          |\n";
            cout<<"\t\t|2. Detail OF ALL The Doctors            |\n";
            cout<<"\t\t|3. Search Doctors Information           |\n";
            cout<<"\t\t|4. Delete Doctors Data                  |\n";
            cout<<"\t\t|5. update doctor data                   |\n";
            cout<<"\t\t|6. Back To The Main Menu                |\n";
            cout<<"\t\t|                                        |\n";
            cout<<"\t\t|________________________________________|\n";
            cout<<"\n\n";
            cout<<"\t--------------------------------------------------------------\n";
            cout<<"\t--------------------------------------------------------------\n\n";
            cout<<"\n\nPlease Enter Your choice :"<<" ";
            cin>>b1;
            switch(b1)
            {
                case 1:
                    system("cls");
                    d.add_doc_info();
                    d.write_docinfo_file();
                    system("cls");
                    cout<<" \n__Press Any Key For Go Back......";
                    getch();
                    system("cls");
                    goto x;
                    break;
                case 2:
                    system("cls");
                    cout<<"\n";
                    cout<<"\t \t  DETAILS OF DOCTORS IN CARDIALOGIST SECTION \n";
                    cout<<"\t-----------------------------------------------------------"<<"\n \n";
                    cout<<"\t-----------------------------------------------------------"<<"\n \n";
                    cout<<"\n\t"<<"NAME"<<"\t \t"<<"ID"<<"\t \t"<<"specialization"<<"\t \t"<<"Age"<<"\n \n";
                    d.view_doc_data_detail();
                    cout<<"\n";
                    cout<<" \n__Press Any Key For Go Back......";
                    getch();
                    system("cls");
                    goto x;
                    break;
                case 3:
                    system("cls");
                    d.search_file_doc();
                    cout<<"\n";
                    cout<<" \n__Press Any Key For Go Back......";
                    getch();
                    system("cls");
                    goto x;
                    break;
                case 4:
                    system("cls");
                    d.delete_doc_data();
                    cout<<"\n";
                    cout<<" \n__Press Any Key For Go Back......";
                    getch();
                    system("cls");
                    goto x;
                    break;
                case 5:
                    system("cls");
                    cout<<"\n Enter the name :\n";
                    cin.ignore();
                    cin.getline(nam,19);
                    d.update_docinfo(nam);
                    cout<<"\n";
                    cout<<" \n__Press Any Key For Go Back......";
                    getch();
                    system("cls");
                    goto x;
                    break;
                default:
                    system("cls");
                    menu();
                    getch();
                    break;
            }
            break;
    case 2:
        system("cls");
         char pname[20];
        cout<<"\n\n";
        cout<<"\n\t\t *** Welcome To Patients DataBase ***  \n";
        cout<<"\t\t ________________________________________\n";
        cout<<"\t\t|                                        |\n";
        cout<<"\t\t|                                        |\n";
        cout<<"\t\t|1 . Add New Patients Information        |\n";
        cout<<"\t\t|2 . Detail OF ALL The Patients          |\n";
        cout<<"\t\t|3 . Search Patients Information         |\n";
        cout<<"\t\t|4 . Delete Patient Data                 |\n";
        cout<<"\t\t|5 . Update Patient Data                 |\n";
        cout<<"\t\t|6 . GO BACK                             |\n";
        cout<<"\t\t|                                        |\n";
        cout<<"\t\t|________________________________________|\n";
        cout<<"\n\n";
        cout<<"\t--------------------------------------------------------------\n";
        cout<<"\t--------------------------------------------------------------\n\n";
        cout<<"\n\nPlease Enter Your choice :"<<" ";
        cin>>b2;
        switch(b2)
        {
            case 1:
                system("cls");
                t.add_pat_info();
                t.pat_data_store_file();
                cout<<" \n__Press Any Key For Go Back......";
                getch();
                system("cls");
                goto x;
                break;
            case 2:
                system("cls");
                cout<<"\n";
                cout<<"\t \t  Details Of All The Patient In The Hospital \n";
                cout<<"\t------------------------------------------------------------"<<"\n \n";
                cout<<"\t------------------------------------------------------------"<<"\n \n";
                cout<<"ID"<<"\t\t"<<"NAME"<<"\t\t"<<"illness"<<"\t\t"<<"ADMITTED Date"<<"\t \t"<<"Age"<<"\n";
                cout<<"\n";
                t.all_pat_detail_file2();
                cout<<" \n__Press Any Key For Go Back......";
                getch();
                system("cls");
                goto x;
                break;
            case 3:
                system("cls");
                 cout<<"\n\n";
                 cout<<"\t--------------------------------------------------------------\n";
                 cout<<"\t--------------------------------------------------------------\n\n";
                 cout<<"\t\t Enter the patient name to display Record :";
                cin.ignore();
                cin.getline(pname,19);
                t.search_file_pat(pname);
                cout<<"\n";
                cout<<" \n__Press Any Key For Go Back......";
                getch();
                system("cls");
                goto x;
                break;
            case 4:
                system("cls");
                cout<<"\n\n";
                cout<<"\t--------------------------------------------------------------\n";
                cout<<"\t--------------------------------------------------------------\n\n";
                cout<<"\t\t Enter the patient name for delete Record :";
                cin.ignore();
                cin.getline(pname,19);
                t.delete_pat_data(pname);
                cout<<"\n";
                cout<<" \n__Press Any Key For Go Back......";
                getch();
                system("cls");
                goto x;
                break;
            case 5:
                system("cls");
                cout<<"\n\n";
                cout<<"\t--------------------------------------------------------------\n";
                cout<<"\t--------------------------------------------------------------\n\n";
                cout<<"\t\t Enter the patient name for update Record :";
                cin.ignore();
                cin.getline(pname,19);
                t.update_patinfo(pname);
                cout<<"\n";
                cout<<" \n__Press Any Key For Go Back......";
                getch();
                system("cls");
                goto x;
                break;
            default:
                system("cls");
                menu();
                getch();
                break;
            }
         break;
    case 3:
        system("cls");
        cout<<"\n\n";
        cout<<"\n\t\t Welcome to Generate The Patients Reports \n";
        cout<<"\t\t ________________________________________\n";
        cout<<"\t\t|                                        |\n";
        cout<<"\t\t|                                        |\n";
        cout<<"\t\t|1 . Add  Patients Reports               |\n";
        cout<<"\t\t|2 . Search Patients Reports             |\n";
        cout<<"\t\t|3 . EXIT                                |\n";
        cout<<"\t\t|4 . GO BACK                             |\n";
        cout<<"\t\t|                                        |\n";
        cout<<"\t\t|________________________________________|\n";
        cout<<"\n\n";
        cout<<"\t--------------------------------------------------------------\n";
        cout<<"\t--------------------------------------------------------------\n\n";
        cout<<"\n\nPlease Enter Your choice :"<<" ";
        cin>>b3;
        switch(b3)
        {
            case 1:
                system("cls");
                r.generate_report_function_store();
                r.generate_pat_report_store_file();
                cout<<" \n__Press Any Key For Go Back......";
                getch();
                system("cls");
                goto x;
                break;
            case 2:
                system("cls");
                r.generate_report_search_pat();
                cout<<"\n";
                cout<<" \n__Press Any Key For Go Back......";
                getch();
                system("cls");
                goto x;
                break;
           case 3:
                system("cls");
                exit(0);
                break;
           default:
                system("cls");
                menu();
                getch();
                break;
            }
    default:
        system("COLOR F2");
        system("cls");
        cout<<"\n\n";
        cout<<"\t____________________________________________________________"<<"\n \n";
        cout<<"\t____________________________________________________________"<<"\n \n";
        cout<<"\n";
        cout<<"\t\t\t THANK YOU \n\n";
        break;
    }
}
void intro()
{
    system("COLOR F2");
    cout<<("\n\t              ______           ");
    cout<<("\n\t             |_    _|             ");
    cout<<("\n\t!--------!     |  |     !--------!");
    cout<<("\n\t!--!  !--!  ___|  |___  !--!  !--!");
    cout<< "\n\t   !  !    |__________|    !  !       ";
    cout<< "\n\t   !  !        |  |        !  !       ";
    cout<< "\n\t   !  !    B   |  |  A     !  !       ";
    cout<< "\n\t   !  !       _|  |_       !  !       ";
    cout<<("\n\t   !  !      |______|      !  !       ");
    cout<<("\n\t   !  !________|  |________!  !       ");
    cout<<("\n\t   !___________|  |___________!       ");
    cout<<("\n\t              _|  |_                ");
    cout<<("\n\t             |______|                 ")<<endl;
    cout<<"\n\n\n\n\tMADE BY : Jaima Jarnaz";
	cout<<"\t\n\n\tID : 17203065";
	cout<<"\t\n\n\tProgram : BCSE";
	Sleep(2000);
	system("cls");
}
