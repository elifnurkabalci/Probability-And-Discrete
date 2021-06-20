#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

void ReadFromFile(int Arr[20][16]){
    ifstream file;
    string a;
    file.open("manufacturing_defects.txt");
    for(int i=0; i<20; i++){
        for(int j=0; j<16; j++){
            //I take the element form file with string, because of arrangement
            file>>a;  
            Arr[i][j]=stoi(a);  // turn into integer  
        }
    }
    file.close();
}
double MeanValue(double Ptr[5][2]){
    double result;
    double Mnvl=0.0;
    for(int i=0; i<5; i++){
        Mnvl+=Ptr[i][0]*i; // 
    }
    result=Mnvl/280;
    cout<<"Lambda= "<<result<<endl;
    return result;
}
void Poisson_Distribution(double mean, double Ptr[5][2]){
    int factorial=1;
    for(int i=0; i<5; i++){
        for(int j=1; j<=i; ++j){
            factorial *=j;
        }
        Ptr[i][1]= 280*(pow(mean,i)*exp(-mean))/(double)factorial;
        factorial=1;
    }
}
void NumberOfDefect(int Arr[20][16],double Ptr[5][2]){
    for(int i=0; i<5; i++){
        Ptr[i][0]=0.0;  // fill with zero
    }
    for(int i=0; i<20; i++){
        for(int j=2; j<16; j++){
            if(Arr[i][j]==0){ //number of zero
                Ptr[0][0]++;  
            }
            else if(Arr[i][j]==1){ // number of one
                Ptr[1][0]++;
            }
            else if(Arr[i][j]==2){ // number of two
                Ptr[2][0]++;
            }
            else if(Arr[i][j]==3){ // number of three
                Ptr[3][0]++;
            }
            else if(Arr[i][j]==4){ //number of four
                Ptr[4][0]++;
            }
        }
    }
    Poisson_Distribution(MeanValue(Ptr),Ptr);

}
void Output(double Ptr[5][2]){
    cout<<"Part-A"<<endl;
    cout<<"Case"<<"\t"<<"Count"<<endl;
    for(int i=0; i<5; i++){
        cout<<i<<"\t"<<Ptr[i][0]<<endl;
    }
    cout<<"Part-C"<<endl;
    cout<<"Case"<<"\t"<<"Real"<<"\t"<<"Predicted"<<endl;
    for(int i=0; i<5; i++){
        cout<<i<<"\t"<<Ptr[i][0]<<"\t"<<Ptr[i][1]<<endl;
    }
}
void WriteInFile(double Ptr[5][2]){
    ofstream file;
    file.open("graph.csv");
    for(int i=1; i<5; i++){
        file<<Ptr[i][0]<<","<<Ptr[i][1]<<endl;
    }
    file.close();
}
int main(){
    int Arr[20][16];
    double Ptr[5][2];
    ReadFromFile(Arr);
    NumberOfDefect(Arr,Ptr);
    Output(Ptr);
    WriteInFile(Ptr);
    return 0;
}