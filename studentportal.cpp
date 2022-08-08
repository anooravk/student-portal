#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>


using namespace std;


ofstream transcript;
void cgpaCalculator(int numberOfCourses,int sem, string name){system("CLS");
	int i;
	float cgpa=0,totalCreditHours=0;
    	string nameOfCourses[numberOfCourses];
    	string gradeOfCourse[numberOfCourses];
    	float creditPoints,gpaPerCourse[numberOfCourses],creditHoursOfCourses[numberOfCourses];
    	
    		transcript.open("transcript.txt", std::ofstream::out | std::ofstream::trunc);
    			if(transcript.is_open()){
    				transcript<<"-------------------------------------------------------------------------------------------"<<endl;
				transcript<<"                        "<<"******TRANSCRIPT******"<<endl;
				transcript<<"-------------------------------------------------------------------------------------------"<<endl;
				transcript<<"           Student name :"<<name<<"                      "<<"Semester number :"<<sem<<endl;
				transcript<<endl;
				transcript<<endl;
				transcript<<"---------------------------------------------------------------------------------------------"<<endl;
			      transcript<<"Subjects"<<"                   "<<"||"<<"        Grade"<<endl;
			      transcript<<"---------------------------------------------------------------------------------------------"<<endl;
    			
    			
    			for(i=0; i<numberOfCourses; i++){
    				cout<<"Enter the names of courses :"<<endl;
    				cin>>nameOfCourses[i];
    				cout<<"Name of "<<i<<" Course is :"<<nameOfCourses[i]<<endl;
		
			cout<<"Enter the credit hours of courses :"<<endl;
			
				cin>>creditHoursOfCourses[i];
    				cout<<"Credit hours of "<<nameOfCourses[i]<<" are :"<<creditHoursOfCourses[i]<<endl;
	
			cout<<"Enter the grades obtained in courses :"<<endl;
			
				cin>>gradeOfCourse[i];
    				cout<<"Grade obtained in "<<nameOfCourses[i]<<" is :"<<gradeOfCourse[i]<<endl;
			    
			
			    if(gradeOfCourse[i]=="A"){
			    
			    		creditPoints=4.00;}
                       else if(gradeOfCourse[i]=="A-"){
			     
			    		creditPoints=3.66;}
			    else if(gradeOfCourse[i]=="B+"){
			    
			    		creditPoints=3.33;}
                       else if(gradeOfCourse[i]=="B"){
			     
			    		creditPoints=3.00;}
			    	else if(gradeOfCourse[i]=="B-"){
				    
			    		creditPoints=2.66;}
		else if(gradeOfCourse[i]=="C+"){
		
			    		creditPoints=2.33;}
			    	else if(gradeOfCourse[i]=="C"){
				    
			    		creditPoints=2;}
			    	else if(gradeOfCourse[i]=="C-"){
				    
			    		creditPoints=1.66;}
			  else if(gradeOfCourse[i]=="D+"){
			  
			    		creditPoints=1.33;}
	             else if(gradeOfCourse[i]=="D"){
			 
	             creditPoints=1.00;}
                  else if(gradeOfCourse[i]=="F"){
			
			    		creditPoints==0;}
			    	else {
				    
			    	cout<<"incorrect entry"<<endl;}
			    
			
				gpaPerCourse[i]=creditHoursOfCourses[i]*creditPoints;
				cout<<"GPA obtained in "<<nameOfCourses[i]<<" is "<<gpaPerCourse[i]<<endl;
			
			      transcript<<nameOfCourses[i]<<"                   "<<"||             "<<gradeOfCourse[i]<<endl;
				transcript<<endl;
			
				}
				for(int i=0; i<numberOfCourses; i++){
					cgpa=cgpa+gpaPerCourse[i];
					totalCreditHours=creditHoursOfCourses[i]+totalCreditHours;
					
				}  	transcript<<"---------------------------------------------------------------------------------------------"<<endl;
				transcript<<"Total credit hours :"<<totalCreditHours<<"                        "<<"CGPA: "<<cgpa/totalCreditHours<<endl;
				transcript<<"---------------------------------------------------------------------------------------------"<<endl;
					
				cout<<"Total credit hours are :"<<totalCreditHours<<endl;
				cout<<"cgpa is :"<<cgpa/totalCreditHours;
				transcript.close();
				
					
				ShellExecute( NULL,"open","transcript.txt",NULL,NULL,SW_NORMAL);
}}


string encryptPassword(){
	const int maxPasswordLength=15;
	char password[maxPasswordLength+1];
	char ch;
	int characterPosition=0;
	cout<<"Please enter your passowrd 1-15 length:";
	while(1){
		ch=getch();
		if(ch==13){
			break;
		} else if(ch==8){
		if(characterPosition>0){
			characterPosition--;
			password[characterPosition]='\0';
			cout<<"\b \b";}
		} else if (ch==32 || ch==9){
			continue;
		} else{
			if(characterPosition<maxPasswordLength){
				password[characterPosition]=ch;
				characterPosition++;
				cout<<"*";
			} else{
				cout<<"your password exceeds the max password length,only first "<<maxPasswordLength<<" will be considered ";
				break;
			}
		}
	}
	
	password[characterPosition]='\0';
	cout<<endl;
	if(strlen(password)==0){
		cout<<"no password entered"<<endl;
	} 
	return password;
}
	

void deleteFile(){
	string deleteLine;
	string line;
	ifstream in("record.csv");
	if(!in.is_open()){
		cout<<"input file failed to open \n";
	}
	ofstream out("outfile.csv");
	cout<<"please select the vassel you'd like to remove"<<endl;
	cin>>deleteLine;
	while(getline(in,deleteLine)){
		if(line != deleteLine)
		out<<line<<endl;
	}
	in.close();
	out.close();
	remove("record.csv");
	rename("outfile.csv","record.csv");
	cout<<"\nchages has sucessfully been made .... data saved\n"<<endl;
}

int main(){
	mainmenu:system("CLS");
	int option, studentMenuOption, adminMenuOption, editChoice;
	string username,password;
	string studentName, gurdianName, studentUsername, studentPassword, studentDob;
    	int studentAge, studentSemester;
    	char studentSection,choice,studentAttendence,recordChoice,whereTo;
    	ofstream attendence;
    	ofstream record;
    	ofstream data;
    	ofstream users;
    	
      cout<<"WELCOME TO STUDENT PORTAL"<<endl;
      cout<<"1. Login as admin"<<endl;
      cout<<"2. Login as student"<<endl;
      cout<<"3. Calculate GPA and print transcript"<<endl;
      cout<<"4. Exit"<<endl;
      cout<<"Select how do you want to login: "<<endl;
      cin>>option;
      switch(option){
      	case 1: {
		system("CLS");
		
      		
      	      cout<<"you have 3 max tries"<<endl;
			 for(int i=0; i<3; i++){
      		cout<<"Username : "; 
      		cin>>username;
      		cout<<"Password : "; 
      		password=encryptPassword();
      	
			if (username=="admin" && password=="12341234"){
      	 	
		    	cout<<"\n1. Add a record"<<endl;
		    	cout<<"2. Check attendence"<<endl;
		    	cout<<"3. Edit a record"<<endl;
		    	cout<<"4. Delete a record"<<endl;
		    	cout<<"5. Check record"<<endl;
		    	cout<<"6. Exit"<<endl;
		    	cout<<"Enter what you want to do? ";
		    	cin>>adminMenuOption;
		    	break;
		    	
			} else {
				cout<<"\nretry\n\n";
			} }
} 
	    switch(adminMenuOption){
    		case 1:
    		{
			    system("CLS");
    		
			    	cout<<"Enter student name?";
    			cin>>studentName;
    			cout<<"Enter student's gurdian name?";
    			cin>>gurdianName;
    			cout<<"Enter student's age?";
    			cin>>studentAge;
    			cout<<"Enter student's username?";
    			cin>>studentUsername;
    			cout<<"Enter student's password?";
    			cin>>studentPassword;
    			cout<<"Enter student's current sesmester?";
    			cin>>studentSemester;
    			cout<<"Enter student's date of birth?";
    			cin>>studentDob;
    			cout<<"Enter student's section?";
    			cin>>studentSection;
    		      cout<<"Do you wan to save this record?"<<endl;
    		      cout<<"Y/N?";
    		      cin>>choice;
    		      if (choice=='Y' || 'y'){
    		      	
				users.open("users.csv",fstream::app)	;
				if(users.is_open()){
					users<<"USERNAMES AND PASSWORDS"<<endl;
					users<<"usernames , passwords "<<endl;
					users<<studentUsername<<","<<studentPassword<<endl;
					users.close();
				}
				ShellExecute( NULL,"open","users.csv",NULL,NULL,SW_NORMAL);
				
				data.open("data.txt",fstream::app)	;
				if(data.is_open()){
			
					data<<"usernames  passwords "<<endl;
					data<<studentUsername<<"     "<<studentPassword<<endl;
					data.close();
				}
				ShellExecute( NULL,"open","data.txt",NULL,NULL,SW_NORMAL);
				
				record.open("record.csv",fstream::app);
    			if(record.is_open()){
				record<<"WELCOME TO YOUR RECORD"<<endl;
				record<<"Student name , Gurdian name , Student age , Semester , Section"<<
			      ", Date of birth "<<endl;
			      record<<studentName<<","<<gurdianName<<","<<studentAge<<","<<studentSemester<<","
				<<studentSection<<","<<studentDob<<endl;
				cout<<endl;	
				record.close();
				ShellExecute( NULL,"open","record.csv",NULL,NULL,SW_NORMAL);
			      }
			}else{
				cout<<"The password or username entered is incorrect. ";
			}  
goto mainmenu;
break;	}

			
			case 2:system("CLS");
			      	ShellExecute( NULL,"open","attendence.csv",NULL,NULL,SW_NORMAL);
					cout<<"what do you wish to do next ?"<<endl;
				cout<<"go back to mainmenu or continue with admin login menu ?"<<endl;
				cout<<"press m or M for mainmenu?"<<endl;
				cin>>whereTo;
				if(whereTo=='m'|| whereTo=='M'){
					goto mainmenu;}
				else{
					exit(-1);
				}
			      	break;
			case 3:system("CLS");
			           cout<<"Do you want to edit the record?"<<endl;
				     cout<<"Y/N?";
				     cin>>choice;
				     if(choice=='Y'||'y'){
				     	cout<<"1. Student name"<<endl;
				     	cout<<"2. Gurdian name"<<endl;
				     	cout<<"3. Student age"<<endl;
				     	cout<<"4. Student semester"<<endl;
				     	cout<<"5. Student section"<<endl;
				     	cout<<"6. Student date of birth"<<endl;
				     	cout<<"7. Student username"<<endl;
				     	cout<<"8. Student password"<<endl;
				     	cout<<"9. Exit";
				     	cout<<"What data do you want to edit?"<<endl;
				     	cin>>editChoice;
				     	switch(editChoice){
				     		case 1:
				     			cout<<"Enter student name?";
    							cin>>studentName;
    							break;
    						case 2:
    							cout<<"Enter student's gurdian name?";
    							cin>>gurdianName;
    							break;
    						case 3:
    							cout<<"Enter student's age?";
    							cin>>studentAge;
    							break;
    						case 4:
    							cout<<"Enter student's current sesmester?";
    							cin>>studentSemester;
    							break;
    						case 5:
    							cout<<"Enter student's section?";
    							cin>>studentSection;
    							break;
    						case 6:
    							cout<<"Enter student's date of birth?";
    			                        cin>>studentDob;
    							break;
    						case 7:
						      cout<<"Enter student's username?";
    							cin>>studentUsername;
    							break;
    						case 8:
    							cout<<"Enter student's password?";
    							cin>>studentPassword;
    							break;
    						case 9:
    						      cout<<"what do you wish to do next ?"<<endl;
				cout<<"go back to mainmenu or continue with admin login menu ?"<<endl;
				cout<<"press m or M for mainmenu?"<<endl;
				cin>>whereTo;
				if(whereTo=='m'|| whereTo=='M'){
					goto mainmenu;}
				else{
					exit(-1);
				}
    							break;
    							}}
    		case 4:system("CLS");
    			deleteFile();
    			ShellExecute( NULL,"open","record.csv",NULL,NULL,SW_NORMAL);
    		cout<<"what do you wish to do next ?"<<endl;
				cout<<"go back to mainmenu or continue with admin login menu ?"<<endl;
				cout<<"press m or M for mainmenu?"<<endl;
				cin>>whereTo;
				if(whereTo=='m'|| whereTo=='M'){
					goto mainmenu;}
				else{
					exit(-1);
				}
							    
		case 5:system("CLS");
			ShellExecute( NULL,"open","record.csv",NULL,NULL,SW_NORMAL);
			cout<<"what do you wish to do next ?"<<endl;
				cout<<"go back to mainmenu or continue with admin login menu ?"<<endl;
				cout<<"press m or M for mainmenu?"<<endl;
				cin>>whereTo;
				if(whereTo=='m'|| whereTo=='M'){
					goto mainmenu;}
				else{
					exit(-1);
				}
		case 6: system("CLS");
		 goto mainmenu;}
	      case 2:


                  {system("CLS");	
			    cout<<"username?"<<endl;cin>>username;
			    cout<<"password?"<<endl;cin>>password;
			
			bool test,test1;
			ofstream data;
	data.open("data.txt",fstream::app);
    			if(data.is_open()){
				data<<studentUsername<<" "<<studentPassword<<endl;
				cout<<endl;	
				record.close();
				ShellExecute( NULL,"open","data.txt",NULL,NULL,SW_NORMAL);
			      }
   ifstream sdata;
	sdata.open("data.txt");
	if(sdata.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	string search;
	search=username;
	bool isFound=0;
	while(!sdata.eof())
	{
		string temp = "";
		getline(sdata,temp);
		for(int i=0;i<search.size();i++)
		{
			if(temp[i]==search[i])
				isFound = 1;
			else
			{
				isFound =0;
				break;
			}
		}
			

		if(isFound)
		{ 
			 test=true;}
			 
		
				
			while(test==true ){
				
				
				cout<<"\n1. Mark attendence"<<endl;
				cout<<"2. Check attendence"<<endl;
		    	cout<<"3. Exit"<<endl;
		    	cout<<"Enter what you want to do? ";
		    	cin>>studentMenuOption;	switch(studentMenuOption){
		    		case 1:system("CLS");
		    			cout<<"\nEnter your name:";
		    			cin>>studentName;
		    			cout<<"Enter 'P' for present and 'A' for absent:"<<endl;
		    			cin>>studentAttendence;
	    		      	attendence.open("attendence.csv",fstream::app);
					if(attendence.is_open()){
					attendence<<"Name , Attendence"<<endl;	
					attendence<<studentName<<"  , "<<studentAttendence<<endl;
					cout<<endl;
					attendence.close();}
						cout<<"what do you wish to do next ?"<<endl;
				cout<<"go back to mainmenu or continue with admin login menu ?"<<endl;
				cout<<"press m or M for mainmenu?"<<endl;
				cin>>whereTo;
				if(whereTo=='m'|| whereTo=='M'){
					goto mainmenu;}
				else{
					exit(-1);
				}
				
						
			      case 2:system("CLS");
			      	ShellExecute( NULL,"open","attendence.csv",NULL,NULL,SW_NORMAL);
			     cout<<"what do you wish to do next ?"<<endl;
				cout<<"go back to mainmenu or continue with admin login menu ?"<<endl;
				cout<<"press m or M for mainmenu?"<<endl;
				cin>>whereTo;
				if(whereTo=='m'|| whereTo=='M'){
					goto mainmenu;}
				else{
					exit(-1);
				}
				break;
					case 3:
				 goto mainmenu;
				}
			    }
	      
	 }

	if(sdata.eof()&&(!isFound))
	{
		cout << "Name not found!\n";}
	break;	}

	
    		case 3:
    		{ system("CLS");
			int Courses,semester;
			string name;
    			cout<<"Enter your name :"<<endl;
    			cin>>name;
    			cout<<"Enter your semester :"<<endl;
    			cin>>semester;
    			cout<<"Enter number of courses :"<<endl;
    			cin>>Courses;
    	       	cgpaCalculator(Courses,semester,name);
    	       cout<<"what do you wish to do next ?"<<endl;
				cout<<"go back to mainmenu or continue with admin login menu ?"<<endl;
				cout<<"press m or M for mainmenu?"<<endl;
				cin>>whereTo;
				if(whereTo=='m'|| whereTo=='M'){
					goto mainmenu;}
				else{
					exit(-1);
				}
    			
             }

    		case 4:system("CLS");
    			goto mainmenu;}
    	
		
      		
		    return 0;}
