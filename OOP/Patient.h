//Composition 
//Patient.h

#include<iostream>
using namespace std;

class Patient
{
	private:
		string ID_NO;
	
	public:
		Patient(string number)
		{
			ID_NO = number;
		}
		
		void Show()
		{
			cout << "\t\t   Coded By: Rasikh Ali ( " << ID_NO << " )" << endl;
		}
		
		~Patient()
		{
			
		}
};

class Info
{
	public:
		Patient calling;		//	Embedded Object
		
		Info(): calling("BSEM-F19-060")
		{
			cout << "\t\t-------------------------------------------" << endl;
		}
		
		void Show()
		{
			calling.Show();
		}
		
		~Info()
		{
			
		}
};
