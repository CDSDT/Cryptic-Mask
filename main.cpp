#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <conio.h>

#define NL "\n"

using namespace std;

//----------------------------------------variables
int y=0;
int x=0;
char dir;
string option_input;

int input;
char in_file [999];	
char out_file [999];	
char mask_file [999];

void error(){
	cout<<"The program encountered an error. Try running it as an administrator.";
	NL;
	system("pause");
	exit(0);
}

int done(){
	cout<<"Press any key to exit";
	cin.get();
	exit(0);
}

int mask(){ // ------------------------mask sub
	cout <<"Input file name : ";	
cin>>in_file;
NL;

cout <<"Store files in : ";	
cin>>mask_file;
NL;

cout <<"Output file name : ";	
cin>>out_file;
NL;

		ofstream merge_cmd;
		merge_cmd.open ("merge.cmd");
			if (!merge_cmd){
				error();
			}
			if (merge_cmd){
				merge_cmd<<"@echo off " NL;
				merge_cmd<<"copy /b ";
				merge_cmd <<mask_file;
				merge_cmd <<" ";			
				merge_cmd <<" + ";
				merge_cmd <<in_file;
				merge_cmd <<" ";
				merge_cmd <<out_file;
				merge_cmd.close();
			
				system("merge.cmd");
				system("del merge.cmd");
			}			
			done();
} //-------------------------------------------end of mask sub

int extract(){//------------------------------------------------extract sub
	cout <<"Input file name : ";	
	cin>>in_file;
	NL;
	
	cout <<"Output file name : ";	
	cin>>out_file;
	NL;

                ofstream ext_cmd;
                ext_cmd.open ("ext.cmd");
                        if (!ext_cmd){
                                error;
                        }
                        if (ext_cmd){
                        		ext_cmd<<"@echo off"NL;
                                ext_cmd<<"copy";
                                ext_cmd <<" ";
                                ext_cmd <<in_file;                     
                                ext_cmd <<" ";
                                ext_cmd <<out_file;
                                ext_cmd.close();
                        
                                system("ext.cmd");
                                system("del ext.cmd");
        } 	
        done();
}//------------------------------------------------------------------end of extract sub

int option_screen(){
	cout<<">Type \"-h\" for help"NL;
	cout<<NL;
	cout<<">";
	cin>>option_input;
	if (option_input =="mask") {
		mask();
	}
	else if ( option_input=="M"){
		mask();
	}
	else if ( option_input=="E"){
		extract();
	}
	else if ( option_input=="extract"){
		extract();
	}
	else if ( option_input=="-h"){
		
	}
	else {
		cout<<NL;
		cout<<"Input not recognised. Try again"NL;
		option_screen();
	}
	
}

void display_dir_to_user(){
	 cout<<"dir = ";
	 cout<< dir ;
	 cout<<"\n";
}

void dir_not_found(){
	exit(0);
}

int main(int argc, char** argv) {



	cout<<"		      Code Driven Software Developement Team"NL;

option:	
option_screen();
cout<<NL;

//---------------------------help
	cout<<"M               -mask file"NL;
	cout<<"E    		-Extract from file"NL;
	cout<<"mask            -mask file"NL;
	cout<<"extract    	-mask file"NL;
	cout<<NL;
	system("pause");
goto option;

system("pause");	
	
	return 0;
}
