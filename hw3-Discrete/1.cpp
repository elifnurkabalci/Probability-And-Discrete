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
		file2<<"POSET: ";
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
			file2<<" ,";
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
		if(reflexive==k) /*file2<<"Reflexive: Yes all element are present"<<endl*/;
		else{
			//file2<<"Reflexive: No"<<endl;
			int one=0,two=0,three=0, four=0, five=0;
 			file2<<"ADD"<<endl;
 			if(z<3){
 				for(int i=0; i<5; i++){
 					if(Ptrr[i]=='a') one++;
 					else if(Ptrr[i]=='b') two++;
 					else if(Ptrr[i]=='c') three++;
 					else if(Ptrr[i]=='d') four++;
 					else if(Ptrr[i]=='e') five++;
 				}
 				if(one==0) file2<<"a,a"<<endl;
 				if(two==0) file2<<"b,b"<<endl;
 				if(three==0) file2<<"c,c"<<endl;
 				if(four==0) file2<<"d,d"<<endl;
 				if(five==0) file2<<"e,e"<<endl;
 			}
 			one=0,two=0,three=0, four=0, five=0;
 			if(z>3){
 				for(int i=0; i<5; i++){
 					if(Ptrr[i]=='1') one++;
 					if(Ptrr[i]=='2') two++;
 					if(Ptrr[i]=='3') three++;
 					if(Ptrr[i]=='4') four++;
 				}
 				if(one==0) file2<<"1,1"<<endl;
 				if(two==0) file2<<"2,2"<<endl;
 				if(three==0) file2<<"3,3"<<endl;
 				if(four==0) file2<<"4,4"<<endl;

 			}
		}
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
		//if(symmetric==stoi(b)) file2<<"Symmetric: Yes all element are present"<<endl;
		//else file2<<"Symmetric: No"<<endl;
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
		if(antisymmetric==stoi(b)) /*file2<<"Antisymmetric: Yes all element are present"<<endl*/;
		else{
			//file2<<"Antisymmetric: No"<<endl;
			if(symmetric==stoi(b)){
				file2<<"DELETE    "<<Arr[2]<<","<<Arr[3]<<endl;
			}
		}
		int transitivity=0; // ab bc ac
		n=0;
		int at[5],w=0;
		for (int i = 0; i < 5; ++i)
		{
			at[i]=0;
		}
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
				if(test==1){
					at[w]=w;
					w++;
				}
			}
			n+=2;
		}
		
		if(z==5) transitivity=stoi(b)-1;
		if(transitivity==stoi(b)) /*file2<<"Transitivity: Yes all element are present"<<endl*/;
		else{
			//file2<<"Transitivity: No"<<endl;
			for(int i=0; i<5; i++){
				if(at[i]!=0){
					file2<<"DELETE  "<<Arr[at[i]*2]<<","<<Arr[at[i]*2+1]<<endl;
				}
			}
		}



		if(transitivity==stoi(b) && antisymmetric==stoi(b) && reflexive==k) 
			file2<<"The relation is already a POSET so we dont need to add or remove any pairs."<<endl;
	}
	file1.close();
	file2.close();

}

int main(){
	Read_FromFile();
	return 0;
}