//patientinfo.h

#include<iostream>
using namespace std;

/*-------------------------------------------------------------------CLASSES--------------------------------------------------------------------*/
//		BASE CLASS

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
		string	code_by;				//stores name 	of dev of program
		
		char 	wardroom[10];			//store input 			for wardnumber		of patient
		const 	static int null = 0;	//const number			for perameterized constructor
		
/*----------------------------------------------------------------Functions----------------------------------------------------------------------*/

		void 	check();				//function is called 	if patient has any serious illness
		string 	check(string);			//function is called	to check if the input id already selected
		void 	outputmain();			//function is called 	in start to get output of admin menu
		void 	doctors();				//function is called	to add new doctors to the hospital's record
		void 	publicuse();			//function is called	in start to get output of public menu
		friend void takeinput();		//function is called 	to take input of patient's info
		
		void	start()					//function is called	to print folloiwng lines at the start of program
		{
			cout << "\n\t\t\tWelcome To Superior Hospital\t\n";
		}
		
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~End of Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		
/*--------------------------------------------------------------Constructors---------------------------------------------------------------------*/
		patientinfo()								//Default Constructor
		{
			cout << "\t\t-------------------------------------------"<<endl;
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


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~End of CLASSES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
