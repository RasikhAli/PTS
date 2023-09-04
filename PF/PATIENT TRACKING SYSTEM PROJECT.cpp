/*
	Program Includes:
		-> Constructors
			--> Default Constructor
			--> Constructor & Destructor
			--> Paramterized Constructor
			--> Copy Constructor
			--> Constructor Overloading
			
		-> Classes
			--> private & public access specifiers
			--> const, static data members
			--> Friend Function
			--> Inline Function
			--> Function Overloading
			
		-> Comments	
*/

#include<iostream>					//library		to input/output
#include<string>					//library		to take whole strings in variable
#include<fstream>					//library		to read/write from/to a file
#include<ctime>						//library		to store the current time in file
using namespace std;

/*--------------------------------------------------------------Global Variables----------------------------------------------------------------*/

int  input;							//input of 		menu 			choices
int  staffinput;					//input of 		staff menu 		choices
int  dchoice;						//input of		disease menu 	choices
char temp[20];						//store data	for temporary purpose from file
void takeinput();					//function is made friend with class patientinfo

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~End of Global Varibles~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*-------------------------------------------------------------------CLASSES--------------------------------------------------------------------*/

class patientinfo
{
	private:
		string 	id;						//store input 	for id assigned 			of patient
		char 	name[20];				//store input 	for name 					of patient
		char 	address[100];			//store input 	for address 				of patient
		char 	contact[10];			//store input 	for contact number 			of patient
		char 	age[5];					//store input 	for age						of patient
		char 	gender[8];				//store input 	for gender					of patient
		char 	blood_gp[5];			//store input 	for blood group				of patient
		char 	disease_past[50];		//store input 	for any diesease in past 	of patient
		char 	add_date[20];			//store input 	for addmission date 		of patient in hospital
		
	public:
		char 	wardroom[10];			//store input 			for wardnumber		of patient
		const 	static int null = 0;	//const number			for perameterized constructor
		
/*----------------------------------------------------------------Functions----------------------------------------------------------------------*/

		void 	check();				//function is called 	if patient has any serious illness
		string 	check(string);			//function is called	to check if the input id already selected
		void 	outputmain();			//function is called 	in start to get output of admin menu
		void 	doctors();				//function is called	to add new doctors to the hospital's record
		void 	publicuse();			//function is called	in start to get output of public menu
		friend void takeinput();		//function is called 	to take input of patient's info
		
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~End of Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
/*--------------------------------------------------------------Constructors---------------------------------------------------------------------*/
		patientinfo()								//Default Constructor
		{
			cout << "\t\t___________________________________________"<<endl;
			cout << "\n\t\t\tWelcome To Superior Hospital\t\n";
		}
		patientinfo(const int o)					//Perameterized constructor		to display wrong selection of Patient's Location & time assigning
		{
			if(o == 0)
			{
				cout << "\n\t\t\t Wrong Selection..." << endl;
				system("pause");
				system("cls");
			}
		}
		patientinfo(const patientinfo &copy)		//Copy constructor
		{
			cout << "\n\t\t Select Again... \n";
		}
		~patientinfo()								//Destructor
		{
			
		}
		
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~End of Constructors~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
};


class add_doc
{
	public:
		char adocname[50];
		char aspecial[50];
		char doctorname[50];	
};
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~End of CLASSES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*----------------------------------------------------------------Main Body-----------------------------------------------------------------------*/

int main()
{
	patientinfo callfun;			// Default 	Constructor
	time_t curr_time;
	string username,pass;
	int selection;
	system("color 09");
	
	startingmenu:
		
	cout      << "\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
	cout      << "\n\t\t\t press 1 for Public use \n";
	cout      << "\t\t\t press 2 for admin use \n";
    cout      << "\t\t\t ";
	cin       >> selection;
	system("CLS");
	if ( selection == 1 )
	{
		callfun.publicuse();
	}
	else if ( selection == 2)
	{
	    login:
			
		cout   <<"\n\n\n\t\t\t Enter username : ";
		cin    >>        username;
		cout   <<        endl;
		cout   <<"\t\t\t Enter password : ";
		cin    >>        pass;
		system("CLS");
		if ( username == "engineers" && pass == "0007" )
		{		
			do
			{
				system("color 09");
				callfun.outputmain(); //calling outputmain for MAIN MENU
				cout<< "                      ";
				cin >> input;
				system("CLS");
				
				// Admiting a Patient8
				if(input == 1)
				{
					takeinput();
				}

				else if (input == 2)
				{
					fstream pat_location;
					
					patientlocation:
						
					pat_location.open("records.txt", ios::in);
					if (!pat_location)
					{
						cout << "\t\t\t File Not Found \n";
					}
					else
					{
						string info;
						string id;
						string find;
						char choice;
						int selection;
						cout << "\n\t\t\t Enter Patient's ID : ";
						cin >> id;
						
						patientid:
							
						while(!pat_location.eof())
						{
							getline(pat_location,info);
							if(id == info)
							{
								fstream pat_record;
								pat_record.open("patloc.txt", ios::app);
								for (int i=1; i<=10; i++)
								{
									pat_record << info << endl;
									getline (pat_location, info);
								}
								
								patientlocationmainmenu:
									
								cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
								cout << "\t\t\t Patient's Location : \n";
								cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
								cout << "\t\t\t 1. Reception \n";
								cout << "\t\t\t 2. In Ward   \n";
								cout << "\t\t\t 3. In Operation Theater \n";
								cout << "\t\t\t 4. Go Back \n";
								cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
								cout << "\t\t\t Your Selection ? : ";
								cin  >> selection; 
								switch(selection)
								{
									case 1:
									{
										int cas;
										cout << "\n\t\t\t Is The Patient at Reception ? (y/n) : ";
										cin >> choice;
										if(choice == 'y' || choice == 'Y')
										{
											if (info == "Patient's Location : ")
											{
												pat_record << "Patient's Location & Time : \n";
												
												patientlocationsubmenu:
													
												cout << "\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
												cout << "\t\t\t 1. Entry Time \n";
												cout << "\t\t\t 2. Time At Reception \n";
												cout << "\t\t\t 3. Go Back \n";
												cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
												cout << "\n\t\t\t Your Choice ? : ";
												cin >> cas;
												switch(cas)
												{
													case 1:
													{
														curr_time = time(NULL);
														tm *tm_local = localtime(&curr_time);
														pat_record << "\t Entered At      : ";
														pat_record << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
														goto patientlocationsubmenu;
														break;
													}
													case 2:
													{
														curr_time = time(NULL);
														tm *tm_local = localtime(&curr_time);
														pat_record << "\t At Reception At : ";
														pat_record << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
														break;
													}
													case 3:
													{
														system("cls");
														goto patientlocationmainmenu;
														break;
													}
												}
												cout << "\n\t\t\t Location Stored in File...\n";
											}
										}
										else if (choice == 'n' || choice == 'N')
										{
											pat_location.close();
											goto patientlocation;
										}
										break;
									}
									case 2:
									{
										int cas;
										cout << "\n\t\t\t Is The Patient in his ward ? (y/n) : ";
										cin >> choice;
										if(choice == 'y' || choice == 'Y')
										{
											if (info == "Patient's Location : ")
											{	
												pat_record << "Patient's Location & Time : \n";
												
												patientlocationsubmenu2:
													
												cout << "\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
												cout << "\t\t\t 1. Entry Time \n";
												cout << "\t\t\t 2. Time At Reception \n";
												cout << "\t\t\t 3. Time of Entering Ward \n";
												cout << "\t\t\t 4. Go Back \n";
												cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
												cout << "\n\t\t\t Your Choice ? : ";
												cin >> cas;
												switch(cas)
												{
													case 1:
													{
														curr_time = time(NULL);
														tm *tm_local = localtime(&curr_time);
														pat_record << "\t Entered At      : ";
														pat_record << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
														goto patientlocationsubmenu2;
														break;
													}
													case 2:
													{
														curr_time = time(NULL);
														tm *tm_local = localtime(&curr_time);
														pat_record << "\t At Reception At : ";
														pat_record << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
														goto patientlocationsubmenu2;
														break;
													}		
													case 3:
													{
														getline (pat_location, info);
														curr_time = time(NULL);
														tm *tm_local = localtime(&curr_time);
														pat_record << info << "  At : ";
														pat_record << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
														break;
													}
													case 4:
													{
														system("cls");
														goto patientlocationmainmenu;
														break;
													}
												}
												cout << "\n\t\t\t Location Stored in File...\n";
											}
										}
										else if (choice == 'n' || choice == 'N')
										{
											pat_location.close();
											goto patientlocation;
										}
										break;
									}
									case 3:
									{
										int cas;
										cout << "\n\t\t\t Is The Patient in Operation Theater ? (y/n) : ";
										cin >> choice;
										if(choice == 'y' || choice == 'Y')
										{
											if (info == "Patient's Location : ")
											{
												pat_record << "Patient's Location & Time : \n";
												
												patientlocationsubmenu3:
													
												cout << "\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
												cout << "\t\t\t 1. Entry Time \n";
												cout << "\t\t\t 2. Time At Reception \n";
												cout << "\t\t\t 3. Time Of Entering Operation Theather \n";
												cout << "\t\t\t 4. Go Back \n";
												cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
												cout << "\n\t\t\t Your Choice ? : ";
												cin >> cas;
												switch(cas)
												{
													case 1:
													{
														curr_time = time(NULL);
														tm *tm_local = localtime(&curr_time);
														pat_record << "\t Entered At      : ";
														pat_record << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
														goto patientlocationsubmenu3;
														break;
													}
													case 2:
													{
														curr_time = time(NULL);
														tm *tm_local = localtime(&curr_time);
														pat_record << "\t At Reception At : ";
														pat_record << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
														goto patientlocationsubmenu3;
														break;
													}		
													case 3:
													{
														curr_time = time(NULL);
														tm *tm_local = localtime(&curr_time);
														pat_record << "\t In Operation Theater At : ";
														pat_record << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
														break;
													}
													case 4:
													{
														system("cls");
														goto patientlocationmainmenu;
														break;
													}
												}
												cout << "\n\t\t\t Location Stored in File...\n";
											}
										}
										else if (choice == 'n' || choice == 'N')
										{
											pat_location.close();
											goto patientlocation;
										}
										break;
									}
									case 4:
									{
										system("cls");
										goto startingmenu;
										break;
									}
									default:
										patientinfo wrong(callfun.null);				//	Parameterized 	Constructor
										patientinfo select = wrong;						//	Copy 			Constructor
										goto patientlocationmainmenu;
										break;
								}
							}
							else
							{
								goto patientid;
							}
						}
					}
					system("pause");
					system("cls");
				}
	
				// Info About The Patients in Hospital
				else if ( input == 3)
				{
					system("color 0B");
					fstream pat_record;
	    			pat_record.open("records.txt", ios::in);
	    			
	    			if(!pat_record)
	    			{
	    				cout<<"\n\t\t\t Such File Does Not Exist... \n";
					}
		
					else
					{
						cout<<"\n\n\n\n.................................... Information of All admited Patients ................................\n\n\n\n";
						string info;
			
						// output of all patient record by opening record.txt
						while (!pat_record.eof())
						{
							getline(pat_record, info);                  //getline(cin, string)
							cout<<"\t\t\t"<<info<<"\n";
						}
					}	
					pat_record.close();
	    			cout << endl;
					cout << "Press 1 to go back"<<endl;
					cin >> input;
					system("CLS");
				}
	
				// Output of Specific 
				else if( input == 4 )
				{
					system("color 0C");
					fstream pat_record;

	    			pat_record.open("records.txt", ios::in);
	    
	    			if(!pat_record)
	    			{
	    				cout<<"\n\t\t\t Such File Does Not Exist... \n";
					}
		
					else
					{   
						cout<<"\n\n\n\n........................................ Information of Patient ....................................\n\n\n\n";
						string info;
						char copyid[20];
						int i=1;
						cout<<"Enter Patient's ID : ";
						cin >> copyid;
			
						while (!pat_record.eof())
						{
							getline(pat_record, info);                  //getline(cin, string)
							if(info == copyid)
							{
								for(i=1; i<=11; i++)
								{
									cout << info << endl;
									getline(pat_record, info);
								}	
							}
						}
					}
					pat_record.close();
					cout <<endl;
					cout << "Press 1 to go back"<<endl;
					cin >> input;
					system("CLS");
				}
	
				// Output of Specific patient if Doctore is assigned
				else if( input == 5 )
				{
					system("color 0C");
					fstream pat_record;
		
	   				pat_record.open("patrec.txt", ios::in);
	    
	    			if(!pat_record)
	    			{
	    				cout<<"\n\t\t\t Such File Does Not Exist... \n";
					}
		
					else
					{   
						cout<<"\n\n\n\n........................................ Information of Patient ....................................\n\n\n\n";
						string info;
						char copyid[20];
						int i=1;
						cout<<"Enter Patient's ID : ";
						cin >> copyid;
			
						while (!pat_record.eof())
						{
							getline(pat_record, info);                  //getline(cin, string)
							if(info == copyid)
							{
								for(i=1; i<=11; i++)
								{
									cout << info << endl;
									getline(pat_record, info);
								}	
							}
						}
					}
		
					pat_record.close();
					cout <<endl;
					cout << "Press 1 to go back"<<endl;
					cin >> input;
					system("CLS");
				}
				
				// STAFF WORK
				else if ( input == 6 )
				{
					system("color 0B");
					cout << "\t\t\t--------------------------------------------  " << endl;
					cout << "\t\t\t     WELCOME TO THE STAFF WORK                " << endl;
					cout << "\t\t\t--------------------------------------------\n" << endl;
					cout << "\t\t\t 1.   Assign new Ward to a Patient            " << endl;
					cout << "\t\t\t 2.   Assign a Doctor to a Patient            " << endl;
					cout << "\t\t\t 3.   Serious illness or Disease              " << endl;
					cout << "\t\t\t 4.   Add More Doctors                        " << endl;
					cout << "\t\t\t--------------------------------------------  " << endl;
					cout << "\n\t\t\t      Your Selection ? : ";
					cin >> staffinput;
					cout << endl;			
					system("CLS");
					
					switch (staffinput)
					{
						
						// Assign Ward to a Patient
						case 1:
						{
							fstream pat_record;
							pat_record.open("records.txt", ios::in);
							if(!pat_record)
							{
								cout<<"\n\t\t No Such File Found... \n";
							}
	
							else
							{
								cout<<"\n\n\n\n.................................... Information of Patient....................................\n\n\n\n";
								string info;
								patientinfo in;
								char copyid[20];
								int i=1;
								cout << "Enter Patient's ID : ";
								cin  >> copyid;
								
								while (!pat_record.eof())
								{
									getline(pat_record, info);                  //getline(cin, string)
									if(info == copyid)
									{
										fstream wardrm;
										wardrm.open("patward.txt", ios::app);  // to save patient's data to another file
										for(i=1; i<=10; i++)
										{
											cout << info << endl;
											wardrm << info << endl;          // saving patient's data to patient.txt
											getline(pat_record, info);
										}
					    				cout << "\n\t\t\t Ward No. : ";
										cin.ignore();
										cin.getline(in.wardroom, 10);
										wardrm << "Ward No. : " << in.wardroom << "\n";
										wardrm.close();
									}
								}
								pat_record.close();
							}
							break;
						}
						
						// Assign a New Doctor to a Newly Admit Patient
						case 2:
						{
							fstream pat_record;
							cin.ignore();
							pat_record.open("patward.txt", ios::in);	
							if(!pat_record)
							{
								cout<<"\n\t\t\t Error while opening the file \n";
							}				
							else
							{
								cout<<"\n\n\n\n.................................... Information ....................................\n\n\n\n";
								string info;
								add_doc add;
								char copyid[20];
								int i=1;
								cout << "Enter Patient's ID : ";
								cin  >> copyid;
								
								while (!pat_record.eof())
								{
									getline(pat_record, info);                  //getline(cin, string)
									if(info == copyid)
									{
										fstream final_rec;
										final_rec.open("patrec.txt", ios::app);  // to save patient's data to another file
										final_rec << endl;
										for(i=1; i<=11; i++)
										{
											cout << info << endl;
											final_rec << info << endl;          // saving patient's data to patient.txt
											getline(pat_record, info);
									
											if(info == "Doc Assigned : not assigned")
											{
												cout << "\n\t\t\t Assign Doctor : ";
												cin.ignore();
												cin.getline(add.doctorname, 50);
												final_rec << "Doc Assigned : " << add.doctorname << "\n";
												getline(pat_record, info);
											}
										}
										final_rec.close();
									}
								}
								pat_record.close();
							}
							break;
						}
			    
						// if patient had serious illness or disease
						case 3:
						{
							callfun.check();
							break;
						}
			    
						// add more doctors
						case 4:
						{
							callfun.doctors();
							break;
						}
						default:
							cout << "\t\t No Such Selection Exists..." << endl;
							cout << "\t\t ---------------------------" << endl;
					}
	    			cout <<endl;
					cout <<endl;
					cout << "\t\t Press 1 to go back"<<endl;
					cin >> input;
					system("CLS");
   				}
   				
    			// opning records from different files
				else if ( input == 7 )
				{
					system("color 0E");
					fstream pat_record;
		
					cout<<"\n\n\t\t\t Enter the file name to be opened (records.txt or patward.txt or patrec.txt) : ";                     
        			cin.ignore();
        			gets(temp);
        			system("cls");
	    			pat_record.open(temp, ios::in);
	    
	    			if(!pat_record)
	    			{
	    				cout<<"\n\t\t\t Such File Does Not Exist... \n";
					}
		
					else
					{
						cout<<"\n\n\n\n........................................ Information in "<<temp<<" ....................................\n\n\n\n";
						string info;
			
						while (!pat_record.eof())
						{
							getline(pat_record, info);                  //getline(cin, string)
							cout<<"\t\t\t"<<info<<"\n";
						}
					}
		
					pat_record.close();
	    			cout << endl;
					cout << "Press 1 to go back"<<endl;
					cin >> input;
					system("CLS");
				}
				
				else if (input == 8)
				{
					goto startingmenu;
				}
	
				else if ( input == 9 )
				{
					system("color F0");
					cout << "\t\t\t\t________________________________________________"<<endl;
					cout << "\n\n";
					cout << "\t\t\t\t              THANK YOU FOR USING  " << endl;
					cout << endl;
					cout << "\t\t\t\t                       OUR  " << endl;
					cout << endl;
					cout << "\t\t\t\t            PATIENT TRACKING SYSTEM " << endl;
					cout << endl;
				}
				
				cout << endl;
				cout << endl;
				cout << endl;
			}while(input==1||input==2||input==3||input==4||input==5||input==6||input==7||input==8);
		}
    	else
    	{
    		system("color 0C");
        	cout    <<"\n\n\t\t\t username or password is incorrect try again \n";
        	goto login;
    	}
	}
    else
    {
    	int num;
	
    	cout   << "your selection is wrong press 1 to go back or press any key to exit program \n";
    	cin    >>num;
    	if(num == 1)
    	{
    		goto startingmenu;
		}
	}
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~End of Main Body~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*--------------------------------------------------------------Functions' Body-------------------------------------------------------------------*/

string patientinfo :: check(string patid)
{
	string store;
	fstream record;
	checkidoccuring:
	record.open("records.txt", ios::in);
	while(!record.eof())
	{
		getline(record,store);
		if(store == patid)
		{
			string store2;
			store2 = store;
			
			cout << "\n\t\t\t Id already taken, Please Enter Another Id : ";
			cin >> patid;
			if (store2 == patid)
			{
				record.close();
				goto checkidoccuring;
			}
		}
	}
	return patid;
	record.close();
}


void patientinfo :: publicuse()
{
	patientinfoid:
	
	int m;
	string ch;
	cout << "\n\t\t*********************************************************************\n";
	cout << "\n\t\t\t You can find patient if you know patient's ID \n";
	cout << "\n\t\t\t";
	system("CLS");
	//if( ch == "yes" )

	system("color 0C");
    fstream pat_record;
    pat_record.open("patloc.txt", ios::in);
   
    if(!pat_record)
    {
    	cout<<"\n\t\t\t Such File Does Not Exist... \n";
	}
	
	else
	{   
		cout<<"\n\n\n\n........................................ Information of Patient ....................................\n\n\n\n";
		string info;
		char copyid[20];
		int i=1;
		cout<<"Enter Patient's ID : ";
		cin >> copyid;
		
		while (!pat_record.eof())
		{
			getline(pat_record, info);                  //getline(cin, string)
			if(info == copyid)
			{
				for(i=1; i<=14; i++)
				{
					cout << info << endl;
					getline(pat_record, info);
				}	
			}
		}
	}
	pat_record.close();
	cout <<endl;
	
	int input2;
	cout  << "\t\t\t Press 1 if you want to find again or press any key to exit \n";
	cin   >>  input2;
	system("CLS");
	if (input2 == 1 )
	{
	    goto patientinfoid;
	}
	else
	{
	   cout   << "\t\t\t Thanks for using our program Take care ";
	}
}
	


void patientinfo :: doctors()
{
	ofstream doc_record;
	doc_record.open("doctors.txt", ios::app);
	
	if(!doc_record)
	{
		cout << "\n\t\t\tError while opening the file\n";
	}
	
	else
	{
		add_doc d;
		cout       << "\n\t\t\t********************************************************************\n";
		doc_record << "\n********************************************************************\n";//fn1353 st
		cin.ignore();
		
		cout       << "\n\t\t\t Doctor's Specialization : ";
		gets(d.aspecial);
		doc_record << d.aspecial<<"\n";
		
        cout       << "\n\t\t\t Doctor's Name : ";
		gets(d.adocname);
		doc_record << d.adocname<<"\n";
		
		cout       << "\n\t\t\t********************************************************************\n";
		doc_record << "\n********************************************************************\n\n";
        cout       << "\n\t\t\tInformation Saved Successfully\n";
	}	
	doc_record.close();
}

inline void patientinfo :: check()
{
	fstream operate;
	cout<<"\n\n\t\t\t Enter the file name to be opened (record.txt or patward.txt or patrec.txt) : ";                       // record.txt
    cin.ignore();
    gets(temp);
    system("cls");
	operate.open(temp, ios::in);
	
	if(!operate)
	{
		cout << "\n\t\t\tError while opening the file\n";
	}
	
	else
	{
		cout<<"\n\n\n\n.................................... Information in "<<temp<<" ....................................\n\n\n\n";
		string info;
		patientinfo a;
		char copyid[20];
		int i=1;
		cout << "Enter Patient's ID : ";
		cin  >> copyid;
		
		while (!operate.eof())
		{
			getline(operate, info);                  //getline(cin, string)
			if(info == copyid)
			{
				fstream final_rec;
				final_rec.open("patope.txt", ios::app);  // to save patient's data to another file
				for(i=1; i<=7; i++)
				{
					cout << info << endl;
					final_rec << info << endl;          // saving patient's data
					getline(operate, info);
					
					if(info == "Any disease or illness : yes")
					{
						cout << info << endl;
						
						seriousmenu:
							
						cout << "\n\t\t\t--------------------------------------------" << endl;
						cout << "\t\t\t 1.   See a Doctor 					    	 " << endl;
						cout << "\t\t\t 2.   Route to Hospital			             " << endl;
						cout << "\t\t\t 3.   Terminate                               " << endl;
						cout << "\t\t\t--------------------------------------------  " << endl;
						cout << "\n\t\t\t      Your Selection ? : ";
						cin.ignore();
						cin >> staffinput;
						system("CLS");
						switch (staffinput)
						{
							case 1:
							{
								fstream doc_record;
								doc_record.open("doctors.txt", ios::in);
								
								if (!doc_record)
								{
									cout<<"\n\t\t\t Error while opening the file \n";
								}
								
								else
								{
									string info;
									char copy[50];
									int i=1;
									cout << "\n\t\t\t Specialization of Doctor related to disease/illness : ";
									cin >> copy;
									
									while (doc_record.good())
									{
										getline(doc_record,info);
										if (info == copy)
										{
											cout << "\n\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
											cout << "\n\t\t\t Doctor That You Should Visit \n";
											cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
											cout << "\n\t\t\t Doctor is Specialized in : ";
											cout << info << endl;
											getline(doc_record, info);
											cout << "\t\t\t Doctor's Name : ";
											cout << info << endl;
											cout << "\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
										}
									}
								}
								goto seriousmenu;
								break;	
							}	
							case 2:
							{
								cout << "\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
								cout << "\t\t\t6km Raiwind Rd, OPF Society, LHR.\n";
								cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

								goto seriousmenu;
								break;
							}
						}
					}	
				}
				final_rec.close();
			}
		}
	}	
	operate.close();
}

void patientinfo :: outputmain()
{
	fstream main_screen;
	main_screen.open("mainmenu.txt", ios::in);
	
	if(!main_screen)
	{
		cout << "\n\t\t\t Error while opening the file \n";
		cout << "\n\t\t\t Creating Own 'mainmenu.txt' file \n";
		system("pause");
		system("cls");
		
		// Writing in mainmenu.txt
		main_screen.open("mainmenu.txt", ios::out);
		main_screen << "                 --------------------------------------------------------        " << endl;
        main_screen << "                              Welcome To Superior Hospital                       " << endl;
        main_screen << "                 --------------------------------------------------------        " << endl;
        main_screen << "                      Please Select an option from the given options             " << endl;
        main_screen << "                 --------------------------------------------------------        " << endl;
        main_screen << "                      1 .      Admit a Patient                                   " << endl;
        main_screen << "                      2 .      Update Location of Patient                  		 " << endl;
        main_screen << "                      3 .      Info About Existing All Patients                  " << endl;
		main_screen << "                      4 .      Info About A Specific Patient                     " << endl;
		main_screen << "                      5 .      Info About A Specific Patient if Specific doctor is assigned " << endl;
		main_screen << "                      6 .      STAFF WORK                                        " << endl;
		main_screen << "                      7 .      Opening records from different files              " << endl;
		main_screen << "                      8 .      Go Back to Main Screen                            " << endl;
		main_screen << "                      9 .      Termiate Program                                  " << endl;
		main_screen << "                                                                                 " << endl;
		main_screen << "                               Or press any key to exit the program              " << endl;
		main_screen << "                                                                                 " << endl;
		main_screen << "                               Your Selection is ? :" << endl;
		
		// output on screen
		cout        << "                 --------------------------------------------------------        " << endl;
        cout        << "                              Welcome To Superior Hospital                       " << endl;
        cout        << "                 --------------------------------------------------------        " << endl;
        cout        << "                      Please Select an option from the given options             " << endl;
        cout        << "                 --------------------------------------------------------        " << endl;
        cout        << "                      1 .      Admit a Patient                                   " << endl;
        cout	    << "                      2 .      Update Location of Patient                  		 " << endl;
        cout        << "                      3 .      Info About Existing All Patients                  " << endl;
		cout        << "                      4 .      Info About A Specific Patient                     " << endl;
		cout        << "                      5 .      Info About A Specific Patient if Specific doctor is assigned " << endl;
		cout        << "                      6 .      STAFF WORK                                        " << endl;
		cout        << "                      7 .      opening records from different files              " << endl;
		cout	    << "                      8 .      Go Back to Main Screen                            " << endl;
		cout        << "                      9 .      Termiate Program                                  " << endl;
		cout        << "                                                                                 " << endl;
		cout        << "                               Or press any key to exit the program              " << endl;
		cout        << "                                                                                 " << endl;
		cout        << "                               Your Selection is ? :" << endl;
        
	}
	
	else
	{
		string info;
		cout << endl;
		
		// for output on screen by opening mainmenu.txt
		
		while (main_screen.good())
		{
			getline(main_screen, info);
			cout << info << endl;
		}
	}
	main_screen.close();
}

void takeinput()
{
	system("color 0A");
	ofstream pat_record;
	pat_record.open("records.txt", ios::app);
	
	if (!pat_record)
	{
		cout<<"\nError while opening the file\n";
    }
    
    else
    {
		patientinfo a; 
    	cout       << "\n\t\t\t********************************************************************\n";
		pat_record << "\n********************************************************************\n";//fn1353 st
		cin.ignore();
	
		cout       << "\n\t\t\t Patient ID : ";
		cin >> a.id;
		pat_record << a.check(a.id) << "\n";
		cin.ignore();
		
	    cout       << "\n\t\t\t Name : ";
	    pat_record << "Name : ";
		gets(a.name);
		pat_record << a.name<<"\n";
	
        cout       << "\n\t\t\t Address : ";
		pat_record << "Address : ";
		gets(a.address);
		pat_record << a.address<<"\n";
	
        cout       << "\n\t\t\t Contact Number : ";
		pat_record << "Contact Number : ";
		gets(a.contact);
		pat_record << a.contact<<"\n";
	
	    cout       << "\n\t\t\t Age : ";
		pat_record << "Age : ";
		gets(a.age);
		pat_record << a.age<<"\n";
	
	    cout       << "\n\t\t\t Gender : ";
		pat_record << "Gender : ";
		gets(a.gender);
		pat_record << a.gender<<"\n";
	
	    cout       << "\n\t\t\t Blood Group : ";
		pat_record << "Blood Group : ";
		gets(a.blood_gp);
		pat_record << a.blood_gp<<"\n";
	
	    cout       << "\n\t\t\t Any Major disease suffered earlier or Any Serious Illness (type yes if any): ";
		pat_record << "Any disease or illness : ";
		gets(a.disease_past);
		pat_record << a.disease_past<<"\n";
		
		cout       << "\n\t\t\t Date of Registration : ";
		pat_record << "Date of Registration : ";
		gets(a.add_date);
		pat_record << a.add_date<<"\n";
		
		pat_record << "Doc Assigned : not assigned";
		pat_record << "\n";
		
		pat_record << "Patient's Location : ";
		pat_record << "\n";
		
		selectcondition:
			
		int pcond;
        cout       << "\n                              Select one condition \n";
        cout       << "                 --------------------------------------------------------" << endl;   
        cout       << "                 1_If patient condition is serious and need Emergency \n";
        cout       << "                 2_If patient condition is Normal \n";
        
		cin        >> pcond;
		cin.ignore();
		system("CLS");
		cout<<"\n\n\n\n\n";
        
        if(pcond == 1)
	    {
        	cout     << "\n\t\t\t Your patient room no. is 32 Emergency room\n";
        	pat_record  <<"Patient Assigned in Emergency room\n";
	    }
		else if(pcond == 2)
	   {
		    cout       << "\n\t\t\t Please chose your disease \n";
		    cout       <<"--------------------------------------------------------------------\n";
		    cout       <<"                      1_ Diabetes \n";
		    cout       <<"                      2_ Allergies and asthma \n";
		    cout       <<"                      3_ Celiac disease \n";
		    cout       <<"                      4_ Relapsing polychondritis \n";
			cout       <<"                      5_ Scleroderma \n";
		    cout       <<"                      6_ Liver Disease \n";
		    cout       <<"                      7_ Infectious diseases \n";
			cout       <<"                      8_ Cancer \n";
			cout       <<"                      9_ Heart disease \n";
			cout       <<"                      10_ Multiple sclerosis \n";
			cout       <<"                      11_ Crohn's disease and ulcerative colitis \n";
			cout       <<"                      12_ lupus \n";
			cout       <<"                      13_ Rheumatoid arthritis \n";
			cin        >> dchoice;
			system("CLS");
			cout<<"\n\n\n\n\n";
			if( dchoice == 1 )
			{
				cout<<"\t\t\t Your patient assigned room is 055 \n";
				pat_record  <<"Assigned room : 055 \n";
			}
			if( dchoice == 2 )
			{
				cout<<"\t\t\t Your patient assigned room is 056 \n";
				pat_record  <<"Assigned room : 056 \n";
			}
			if( dchoice == 3 )
			{
				cout<<"\t\t\t Your patient assigned room is 057 \n";
				pat_record  <<"Assigned room : 057 \n";
			}
			if( dchoice == 4 )
			{
				cout<<"\t\t\t Your patient assigned room is 058 \n";
				pat_record  <<"Assigned room : 058 \n";
			}
			if( dchoice == 5 )
			{
				cout<<"\t\t\t Your patient assigned room is 059 \n";
				pat_record  <<"Assigned room : 059 \n";
			}
			if( dchoice == 6 )
			{
				cout<<"\t\t\t Your patient assigned room is 060 \n";
				pat_record  <<"Assigned room : 060 \n";
			}
			if( dchoice == 7 )
			{
				cout<<"\t\t\t Your patient assigned room is 061 \n";
				pat_record  <<"Assigned room : 061 \n";
			}
			if( dchoice == 8 )
			{
				cout<<"\t\t\t Your patient assigned room is 062 \n";
				pat_record  <<"Assigned room : 062 \n";
			}
			if( dchoice == 9 )
			{
				cout<<"\t\t\t Your patient assigned room is 063 \n";
				pat_record  <<"Assigned room : 063 \n";
			}
			if( dchoice == 10 )
			{
				cout<<"\t\t\t Your patient assigned room is 064 \n";
				pat_record  <<"Assigned room : 064 \n";
			}
			if( dchoice == 11 )
			{
				cout<<"\t\t\t Your patient assigned room is 065 \n";
				pat_record  <<"Assigned room : 065 \n";
			}
			if( dchoice == 12 )
			{
				cout<<"\t\t\t Your patient assigned room is 066 \n";
				pat_record  <<"Assigned room : 066 \n";
			}
			if( dchoice == 13 )
			{
				cout<<"\t\t\t Your patient assigned room is 067 \n";
				pat_record  <<"Assigned room : 067 \n";
			}
				
		}
		else
	    {
			cout       <<"\n\t\t\t Your Option is wrong. Please Try again \n";
			cout       << endl;
			goto selectcondition;
		}
		cout       << "\n\t\t\t********************************************************************\n";
		pat_record << "\n********************************************************************\n\n";
        cout       << "\n\t\t\tInformation Saved Successfully\n";
    }
	pat_record.close();
	
	cout       << "\t\t\t Your Patient is succesfully admited "<<endl;
	cout       << endl;
		
	cout       << "\t\t\t Press 1 to go back"<<endl;
	cin        >> input;
	system("CLS");		
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~End of Functions' Body~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

