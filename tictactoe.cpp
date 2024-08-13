#include<iostream>
using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int col;
char token = 'x';
bool tf = false;
string n1;
string n2;

void func1(){





    cout<<" |      |   \n";
cout<<space[0][0]<<"|   "<<space[0][1]<<"  |"<<space[0][2]<<"  \n";
    cout<<"_|______|_   \n"; 
    cout<<" |      |   \n";  
cout<<space[1][0]<<"|   "<<space[1][1]<<"  |"<<space[1][2]<<"  \n";
    cout<<"_|______|_   \n";
    cout<<" |      |   \n"; 
cout<<space[2][0]<<"|   "<<space[2][1]<<"  |"<<space[2][2]<<"  \n";
    cout<<" |      |   \n";

};

void func2(){
    int digit;

    if(token=='x'){
        cout<<n1<<"Please enter digit";
        cin>>digit;
    }

     if(token=='0'){
        cout<<n2<<"Please enter digit";
        cin>>digit;
    }


    if(digit==1){
        row=0;
        col=0;
    }

    if(digit==2){
        row=0;
        col=1;
    }

    if(digit==3){
        row=0;
        col=2;
    }

    if(digit==4){
        row=1;
        col=0;
    }

    if(digit==5){
        row=1;
        col=1;
    }


    if(digit==6){
        row=1;
        col=2;
    }


     if(digit==7){
        row=2;
        col=0;
    }


    if(digit==8){
        row=2;
        col=1;
    }


    if(digit==9){
        row=2;
        col=2;
    }

    else if(digit<1 || digit>9){
        cout<<"Invalid";
    }


   if(token=='x' && space[row][col]!='x' && space[row][col] != '0'){
    space[row][col]='x';
    token='0';
   }

   else if(token=='0' && space[row][col]!='x' && space[row][col] != '0'){
    space[row][col]='0';
    token='x';
   }

   else{
    cout<<"There is no empty space"<<endl;
    func2();
   }
  func1();
}

bool func3(){
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]){
            return true;
        }

        if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0]){
            return true;
        }

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(space[i][j]!='x' &&  space[i][j] != '0'){
                    return false;
                }
            }
        }
    }

    tf = true;
    return true;
}


int main(){


cout<<" ********Tic-Tac-Toe Game"<<endl;
cout<<"Enter the name of first player : \n";
    getline(cin,n1);
    cout<<"Enter the name of second player : \n";
    getline(cin,n2);


    while(!func3()){
        func1();
        func2();
        func3();
    }


    if(token=='x' && tf == false){
        cout<<n2<<" wins"<<endl;
    }

    else if(token=='0' && tf==false){
        cout<<n1<<" wins"<<endl;
    }

    else{
        cout<<"Its draw"<<endl;
    }
}    


