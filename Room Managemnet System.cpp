
 #include <iostream>
#include <fstream>
#include <string>

using namespace std;


void login();
void registr();


const int maxrow = 50 ;

string CustomerID[maxrow] = {};
string RoomType  [maxrow] = {};
string RoomNo    [maxrow] = {};
string CustomerName[maxrow]={};
string Opshion   [maxrow]={};
string RoomPrice [maxrow] = {};


void OpenFile()
	
	{
		string line;
		ifstream myfile ( "Moon Hotel C++");
		if (myfile.is_open())
		
			{
				int x=0;
				while (getline(myfile, line))
				
					{
						int l = line.length();
						CustomerID  [x] = line.substr(0,4);
						RoomType[x] = line.substr(12,8);
						RoomNo	[x] = line.substr(5,2);
						CustomerName[x]=line.substr(6,5);
						Opshion[x]=line.substr(2,0);
						RoomPrice[x]= line.substr(8,3);
						
						x++;
							 
					}				
				
			}
			else
			{
				cout <<"Managed to Open the Document !!!"<<endl;
			}
	}
	
	void Bookroom ()
	{
		char cmID   [100];
		char rmType [100];
		char rmNo   [100];
		char cmName [100];
		char opshion[100];
		char rmpr   [100];
		
			
			cin.ignore();
			
		cout<<"~ Enter the Customer ID  (CustomerID - Max 100 )       =: ";
		cin.getline(cmID , 100);
		cout<<"  "<<endl;
		
		cout<<"~ Enter the Room Type  (Single Room/Double Room/Twin Room/Family Room/Standard Room/Deluxe Room)                        =: ";
		cin.getline(rmType , 100);
		cout<<"  "<<endl;
		
		cout<<"~ Enter the Number of Rooms (RoomNo - Max 100) =: ";
		cin.getline(rmNo , 100);
		cout<<"  "<<endl;
		
		cout<<"~ Enter the Customer Name  =: ";
		cin.getline(cmName , 100);
		cout<<"  "<<endl;
		
		cout<<"~ Enter the Customer Opshion (AC/NON AC/,Dinner) =: ";
		cin.getline( opshion, 100);
		cout<<"  "<<endl;
		
		cout<<"~ Enter the Price of Rooms =: ";
		cin.getline(rmpr , 100000);
		cout<<"  "<<endl;
		
			
			for (int x=0 ; x<maxrow ; x++)
				{
					if (CustomerID[x]== "\0 ")
						{
					
							CustomerID  [x]     =cmID ;
							RoomType    [x]     =rmType;
							RoomNo      [x]     =rmNo ;
							CustomerName[x]     =cmName;
							Opshion     [x]     =opshion;
							RoomPrice   [x]     =rmpr;
							break;
						
						}
				}
		
		}
		
	void  ViewRoom (string search)
	
	{
		char cmID   [100];
		char rmType [100];
		char rmNo   [100];
		char cmName [100];
		char opshion[100];
		char rmpr   [100];
		
		int counter = 0;
		
		for ( int x = 0 ; x<maxrow ; x++)
			{
				if (CustomerID[x]==search)
				
				{
					
						counter++;
						
						cout<<"Type of the Room Name        :=" ;
						cin.getline(rmType, 100);
						RoomType[x]=rmType;
						
						cout<<"Number of the room           := ";
						cin.getline(rmNo , 100);
						RoomNo[x]=rmNo;
						
						cout<<"Name of the Customer         := ";
						cin.getline(cmName , 100);
						CustomerName[x]=cmName;
						
						cout<<"Price of the room 			:= ";
						cin.getline(rmpr , 100000);
						RoomPrice[x]=rmpr;
						
						cout << " ...Updated with success !!!... "<<endl;
					
				}
						
			}
			
			if (counter == 0)
			
			{
				cout << "#######The Room ID is fictitious !!!####### "<<endl;
			}
			
	}	
	
	void DeleteRoom (string search)	
	{
		int counter = 0 ;
		for (int x=0 ; x<maxrow ; x++)
		{
			if (CustomerID[x]==search)
			{
				counter++;
				
					counter++;
					
					RoomType    [x]="";
					CustomerID	[x]="";
					RoomNo	    [x]="";
					CustomerName[x]="";
					RoomPrice   [x]="";
				
				cout << " ****Deleted with success!!!**** " <<endl;
				break;
			}
		}
			
		if (counter==0)
			{
				cout << "##### There isn't a Room ID Number!!#####";
				
			}
	}

 	void SearchRoom (string search)
 	{
 		system ("CLS ");
		cout<< " Moon Hotels Details "<<endl;
		cout<< "=================================================="<<endl;
		
		int counter=0;
		for(int x=0 ; x<maxrow ; x++)
		{
			if (CustomerID[x]== search)
			{
				counter++;
				cout<<"  "<<counter<<"  "<<CustomerID[x]<< "   "<<RoomType[x]<<"   "<<RoomNo[x]<<"  "<<CustomerName[x]<<"  "<<Opshion[x]<<"    "<<RoomPrice[x]<<endl;
				break;
			}
		}
		if (counter==0)
			{
				cout<<" .......No Room Found!!!....... !!!" <<endl;	 
			}
		cout<<"==========================================================="<<endl;	 
	}
	
	void ShowRoom()
	
	{
		system ("CLS");
		cout<<"                                 ~~~~~~~~~~~Moon Hotels List~~~~~~~~~~~~ "<<endl;
		cout<< "             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		
		int counter =0 ;
		cout <<" | Customer ID| Room Type | Room No:k| Customer Name| Opshion |  Room Price "  <<endl<<"    =============================================================\n";
		for (int x=0 ; x<maxrow ; x++)
		{
			if (CustomerID[x] != "\0")
			{
				counter++;
					cout<<"  "<<counter<<"  "<<CustomerID[x]<< "   "<<RoomType[x]<<"   "<<RoomNo[x]<<"  "<<CustomerName[x]<<"  "<<Opshion[x]<<"    "<<RoomPrice[x]<<endl;		
			
			}
		}
		if (counter==0)
		{
			
		    cout<< "                            Kindly notify us in case there are any issues\n" <<endl;
			cout<< "                              	Email : dulas@gmail.com  " <<endl;
			cout<< "                               	  Mobile : +94 778 123 456 " <<endl;
			cout<< "                                   	  Thank You !!!\n" <<endl;
		}
		
		cout<<"                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
	
		
	}
	
	void SaveFile()
	{
		ofstream myfile;
		myfile.open("database.txt");
		for(int x=0 ; x<maxrow ; x++)
		{
			if (CustomerID[x]== "\0")
			{
				break;
			}
		else	
			{
				myfile<<CustomerID[x] + " "+ RoomType[x] +" "+ RoomNo[x] + " "+ CustomerName[x]  +" " + Opshion[x] +" " + RoomPrice[x ]<<endl;
			}
		
		}
	}
	
	
int main()

{

	int Start;
	
	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Hello~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    cout<<"************************************** Welcome to  Moon Hotel *******************************************\n\n";
    cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<"********************************************* MENU ********************************************************\n\n";
	cout<<" \n\t\t\t\t\t1 . Sign UP "<<endl;
	cout<<" \n\t\t\t\t\t2 .View Opshion "<<endl;

	
	cout<<"\n\t~~Enter the selection:= ";
	cin>>Start;
		switch (Start)
			{
				case 1:
					system("CLS");
					break;
				case 2:
					 ShowRoom();
					break;
						
				default:	
					system("CLS");          
                    main();	
			}




	int choice;
		
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    cout<<"**************************************  Welcome to the Moon Hotel  *******************************************\n\n";
    cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<"********************************************* MENU *********************************************************\n\n";
        
        cout<<"\t\t\t\t\t1.LOGIN"<<endl;
        cout<<"\t\t\t\t\t2.REGISTER"<<endl;
        cout<<"\t\t\t\t\t3.Exit"<<endl;
        cout<<"\n\n\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                
                case 3:

                        cout<<"//@//@//@ We appreciate you use our software //@//@//@\n";
                        break;
                default:
                        system("CLS");
                        cout<<"You tried it incorrectly. Please try again..\n"<<endl; 
                        main();
        }
      
	  
	    
}
void login()
{
		
	 
        int count;
        string user,pass,u,p;
        system("CLS");
        cout<<"\n~~~~~~~~~~~~~~~~~~ Please enter the following details ~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"\n\n\t\t ~ USERNAME :";
        cin>>user;
        cout<<"\n\n\t\t ~ PASSWORD :";
        cin>>pass;
        
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("CLS");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello  "<<user<< " Welcome to Moon Hotel "<<"\n~~~~~~~~~~~~~~~~~~LOGIN SUCCESS~~~~~~~~~~~~~~~~~~\nWe're glad that you're here.\nThanks for logging in\n";
    	 }
    	 
    	      else
       {
               cout<<"\nLOGIN ERROR\nPlease check your Username and Password\n";
               main();

               
       }

 	std :: cout <<" Moon ";
	int Option;
	string CMID;
	system (" CLS ");
	OpenFile();
	

		do 
			{	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n "<<endl;
			  	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Welcome To to Moon Hotel ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n "<<endl;
			  	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n "<<endl;
			  	 
		
			  	 
				cout << " \t\t\t\t\t 1 - Book a Room   " <<endl;
				cout << " \t\t\t\t\t 2 - View Customer Record  " <<endl;
				cout << " \t\t\t\t\t 3 - Delete Customer Record   " <<endl;
				cout << " \t\t\t\t\t 4 - Search customer Record  " <<endl;
				cout << " \t\t\t\t\t 5 - Display Room List   " <<endl;
				cout << " \t\t\t\t\t 6 - Save and exit Records   " <<endl;
				cout<<""<<endl;cout<<endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" <<endl;
				
				cout << "Please  Select an Option =: ";
				cin>>Option;
				
				cout<<endl;
				
					switch (Option)
						{
							case 1 :
							Bookroom();
									system (" CLS ");
									break;
									
							case 2 :
									cin.ignore();
									cout<<"Enter the Customer ID of which room to be updated :=";
									getline(cin,CMID);
									(CMID);
									system("CLS");
									
									break;		
							case 3:
									cin.ignore();
									cout<<"Enter the Customer ID of which room to be deleted:=";
									getline(cin, CMID);
									DeleteRoom(CMID);
									system("CLS");
									cout<<"  "<<endl;
									break;
									
							case 4 :
									cin.ignore();
									cout<<"Enter the Customer ID of which room to be searched:=";
									getline(cin,CMID);
									SearchRoom(CMID);
									cin.ignore();
									system("CLS");
									cout<<"  "<<endl;
									break;
													
							
							case 5 : ShowRoom();
									break;	
									
					
							
						}
			} while (Option !=6);
			

			
				SaveFile();
				cout<< "..............Exit.............Saved to file !!!! "<<endl<<endl; //final 
				cout<< "~~~~~~~~~~~  Thank You !!! ~~~~~~~~~~ " <<endl;
			  	
      		
    
                cin.get();

             
                main();

   
}


void registr()
{
        
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the USERNAME :=";
        cin>>reguser;
        cout<<"\nEnter the PASSWORD :=";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nSuccessfully Resgistered\n";
        main();
        
        
}

