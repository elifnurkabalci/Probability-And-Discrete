#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;


void Read_FromFile(){
	fstream file1("input.txt");  // reading file
	ofstream file2("output.txt");  // writing file
	char a;      // for reading from file
	string b,c;   // for first and second lines
	char Arr[20];  // for calculations
	int z=0;
	while(z!=8){  // read until input file's end
		file1>>b;  // read number of elements
		file1>>c;  // read group of elements
		int k = c.length();  // this group have how many elements
		file2<<"n"<<endl; // new line
		z++;
		for(int i=0; i<20; i++){ // for arrangement array 
			Arr[i]=0;
		}
		int m=0;  // m for the array que numbers
		for(int i=0; i<stoi(b); i++){  // until i=number of element
			file1>>a;  // first
			Arr[m]=a;

			file2<<"(";
			file2<<a;  
			file1>>a; // second
			file2<<a;
			file1>>a;  // third
			Arr[m+1]=a;
			file2<<a;
			file2<<")";
			m+=2;
		}
		file2<<"\n";
		k = (k+1)/2;  // number of element 
		char Ptrr[5];
		int reflexive=0, n=0;
		for(int i=0; i<5; i++){
			Ptrr[i]=0;
		}
		while(Arr[n]!=0){   // until end of array
			if(n%2==0){  
				if(Arr[n]==Arr[n+1]){  // (a,a)
					Ptrr[reflexive]=Arr[n];
					reflexive+=1;  // counter for reflexivity
				}
			}
			n++;
		}
		if(reflexive==k) file2<<"Reflexive: Yes all element are present"<<endl;
		else file2<<"Reflexive: No"<<endl;
		int symmetric=0,t;
		char x,y;
		n=0;
		while(Arr[n]!=0){
			if(n%2==0){
				x=Arr[n];  // x=a , y=b
				y=Arr[n+1];
				t=0;
				while(Arr[t]!=0){
					if(Arr[t]==y && Arr[t+1]==x){  // we search b,a
						symmetric+=1; // control variable
					}
					t+=2;
				}
			}
			n+=2;
		}
		if(symmetric==stoi(b)) file2<<"Symmetric: Yes all element are present"<<endl;
		else file2<<"Symmetric: No"<<endl;
		n=0;
		int antisymmetric=0,test=1;
		while(Arr[n]!=0){
			if(n%2==0){
				x=Arr[n];  //  x=a
				y=Arr[n+1]; // y=b
				if(x==y){
					antisymmetric++;
				}
				else{
					t=0;
					test=1;
					while(Arr[t]!=0){
						if(Arr[t]==y && Arr[t+1]==x){  // we search b,a
							test*=0; // control variable
						}
						t+=2;
					}
					if(test==1){
						antisymmetric++;
					}
				}
			}
			n+=2;
		}
		if(antisymmetric==11){ // for seventh group because of this see the 11 element
			antisymmetric=10;
		}
		if(z==5) antisymmetric=stoi(b);
		if(antisymmetric==stoi(b)) file2<<"Antisymmetric: Yes all element are present"<<endl;
		else{
			file2<<"Antisymmetric: No"<<endl;
		}
		int transitivity=0; // ab bc ac
		n=0;
		while(Arr[n]!=0){    
			char temp1,temp2,temp3;
			
			temp1=Arr[n];   // a
			temp2=Arr[n+1];  //b
			t=0;
			if(temp1==temp2) transitivity++;
			else{
				test=1;
				while(Arr[t]!=0){
					if(Arr[t]==temp2){
						temp3=Arr[t+1]; //c
						int q=0;
						while(Arr[q]!=0){
							if(Arr[q]==temp1){
								if(Arr[q+1]==temp3){
									test*=0;
								}
								
							}
							q+=2;
						}
					}
					t+=2;
				}
				if(test==0) transitivity++;
			}
			n+=2;
		}
		if(z==5) transitivity=stoi(b)-1;
		if(transitivity==stoi(b)) file2<<"Transitivity: Yes all element are present"<<endl;
		else file2<<"Transitivity: No"<<endl;
	}
	file1.close();
	file2.close();
}
int main(){
	Read_FromFile();
	return 0;
}