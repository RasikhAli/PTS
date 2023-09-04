//Coded.h

#include<iostream>
using namespace std;


//		DERIVED CLASS

class Coded: protected patientinfo
{
	public:
		string Name_of_Dev = " Rasikh Ali ";
		
		void Codeby()
		{
			code_by = Name_of_Dev;
			
			cout << "\t\t\t\t\t\t\t\t\t\t\t CODED BY : " << code_by << endl;
		}
};
