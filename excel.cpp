#include<iostream>
#include<String>
#define rows 4
#define columns 6
using namespace std;
void print_excel(int excel[rows][columns]);
void set_value(int excel[rows][columns],string input, int value);
int sum(int excel[rows][columns],string input,string input2,string location);
int subtract(int excel[rows][columns],string input,string input2,string location);
int Bubble_Descending(int excel[rows][columns],string input,string input2);
int Bubble_Ascending(int excel[rows][columns],string input,string input2);
int Min(int excel[rows][columns],string input,string input2);
int Max(int excel[rows][columns],string input,string input2);
int main(){
	
string str;
string str2;
string str3;
	
int excel[rows][columns] = {0};
int value;	
int choice;	
	
while(true){

cout<<"\n1.Elementry arithmetic\n2.set value\n3.sorting\n4.print Excel\n5.Min\n6.Max\n7.Exit\n";	

cin>>choice;
				
		
if(choice == 1){

while(true){
	
cout<<"\n\n1.sum\t2.subtract\t3.back to menu\n\n";	
cin>>choice;	
if(choice == 1){
cout<<"\nFrom:\n";
cin>>str;
cout<<"\nTo:\n";
cin>>str2;
cout<<"\nLocation:\n";
cin>>str3;
sum(excel,str,str2,str3);
}else if(choice == 2){
cout<<"\nFrom:\n";
cin>>str;
cout<<"\nTo:\n";
cin>>str2;
cout<<"\nLocation:\n";
cin>>str3;
subtract(excel,str,str2,str3);
}else if(choice == 3){
break;	
}else
cout<<"the option you choosed does not exist!";
}
}
	
	
else if(choice == 2){	
cout<<"\nlocation:\n";
cin>>str;
cout<<"\nvalue:\n";
cin>>value;
set_value(excel,str,value);
}


else if(choice == 3){
cout<<"\n1.Ascending\n2.Descending\n";
cin>>choice;
cout<<"\nFrom:\n";
cin>>str;
cout<<"\nTo:\n";
cin>>str2;
if(choice == 1)
Bubble_Ascending(excel,str,str2);
else if(choice == 2)
Bubble_Descending(excel,str,str2);
else
cout<<"the option you choosed does not exist!";
}	


else if(choice == 4){	
print_excel(excel);		
}

else if(choice == 5){
cout<<"\nFrom:\n";
cin>>str;
cout<<"\nTo:\n";
cin>>str2;
Min(excel,str,str2);
}	


else if(choice == 6){
cout<<"\nFrom:\n";
cin>>str;
cout<<"\nTo:\n";
cin>>str2;
Max(excel,str,str2);
}	

	
else if(choice == 7){	
break;	
}


else
cout<<"the option you choosed does not exist!";	

}	
	
	
	
return 0;	
	
	
}



void set_value(int excel[rows][columns],string input, int value){

char column_index_c;	
string row_index_c = " ";	
int k;
int row_index = 0;
column_index_c = input[0];
int column_index = int(column_index_c);	
column_index = column_index - 65;	
	
for(int i = 1;i < input.length(); i++){
row_index_c[i-1] = input[i];	
}	

for(int j = 0; j < row_index_c.length(); j++){
	k = int ((row_index_c[j]) - 48);
	row_index = row_index + k;
	row_index = row_index * 10;
	}
    row_index = row_index/10;
	row_index--;
	//cout<<row_index;	
	if ( ( row_index<rows and row_index>=0 ) and ( column_index<columns and column_index >= 0 ) ){
    if(value >= -99 and value <= 999){
	excel[row_index][column_index] = value;
	
}else
cout<<"\nthe input is more than 999!\n";
}else
cout<<"\nthe location you have selected does not exist!\n";

}









///////////////////////////////////////////////
int sum(int excel[rows][columns],string input,string input2,string location){



char column_index_c , column_index_c_2;	
string row_index_c = " ";	
string row_index_c_2 = " ";
int k,k2;
int row_index = 0 , row_index2 = 0;
column_index_c = input[0];
column_index_c_2 = input2[0];
int column_index = int(column_index_c);	
column_index = column_index - 65;	

int column_index2 = int(column_index_c_2);	
column_index2 = column_index2 - 65;	
	
for(int i = 1;i < input.length(); i++){
row_index_c[i-1] = input[i];	
}	

for(int i = 1;i < input2.length(); i++){
row_index_c_2[i-1] = input2[i];	
}	


for(int j = 0; j < row_index_c.length(); j++){
	k = int ((row_index_c[j]) - 48);
	row_index = row_index + k;
	row_index = row_index * 10;
	}
    row_index = row_index/10;
	row_index--;
	
	if (not( ( row_index<rows and row_index>=0 ) and ( column_index<columns and column_index >= 0 ) ) ){
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}

    
for(int j = 0; j < row_index_c_2.length(); j++){
	k = int ((row_index_c_2[j]) - 48);
	row_index2 = row_index2 + k;
	row_index2 = row_index2 * 10;
	}
    row_index2 = row_index2/10;
	row_index2--;
	
	if ( ( row_index2<rows and row_index2>=0 ) and ( column_index2<columns and column_index2 >= 0 ) ){

int result = 0;

if (row_index == row_index2 and column_index < column_index2){

for(int i = column_index ;i <= column_index2 ;i++)	
result = result + excel[row_index][i]; 	

set_value(excel,location,result);	
	
}else if(row_index < row_index2 and column_index == column_index2){
	
for(int i = row_index ;i <= row_index2 ;i++)	
result = result + excel[i][column_index]; 	
	
set_value(excel,location,result);	
	
}else{
cout<<"you have selected wrong pattern or wrong locations";
return -1;		
}


}else{
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}





	
return 0;
	
}


int subtract(int excel[rows][columns],string input,string input2,string location){

char column_index_c , column_index_c_2;	
string row_index_c = " ";	
string row_index_c_2 = " ";
int k,k2;
int row_index = 0 , row_index2 = 0;
column_index_c = input[0];
column_index_c_2 = input2[0];
int column_index = int(column_index_c);	
column_index = column_index - 65;	

int column_index2 = int(column_index_c_2);	
column_index2 = column_index2 - 65;	
	
for(int i = 1;i < input.length(); i++){
row_index_c[i-1] = input[i];	
}	

for(int i = 1;i < input2.length(); i++){
row_index_c_2[i-1] = input2[i];	
}	


for(int j = 0; j < row_index_c.length(); j++){
	k = int ((row_index_c[j]) - 48);
	row_index = row_index + k;
	row_index = row_index * 10;
	}
    row_index = row_index/10;
	row_index--;
	
	if (not( ( row_index<rows and row_index>=0 ) and ( column_index<columns and column_index >= 0 ) ) ){
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}

    
for(int j = 0; j < row_index_c_2.length(); j++){
	k = int ((row_index_c_2[j]) - 48);
	row_index2 = row_index2 + k;
	row_index2 = row_index2 * 10;
	}
    row_index2 = row_index2/10;
	row_index2--;
	
	if ( ( row_index2<rows and row_index2>=0 ) and ( column_index2<columns and column_index2 >= 0 ) ){



if (row_index == row_index2 and column_index < column_index2){

int result = excel[row_index][0];

for(int i = column_index+1 ;i <= column_index2 ;i++)	
result = result - excel[row_index][i]; 	

set_value(excel,location,result);	
	
}else if(row_index < row_index2 and column_index == column_index2){
	
int result = excel[0][column_index];	
	
for(int i = row_index+1 ;i <= row_index2 ;i++)	
result = result - excel[i][column_index]; 	
	
set_value(excel,location,result);	
	
}else{
cout<<"you have selected wrong pattern or wrong locations";
return -1;		
}


}else{
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}





	
return 0;
	
}




int Bubble_Descending(int excel[rows][columns],string input,string input2){


   char column_index_c , column_index_c_2;	
string row_index_c = " ";	
string row_index_c_2 = " ";
int k,k2;
int row_index = 0 , row_index2 = 0;
column_index_c = input[0];
column_index_c_2 = input2[0];
int column_index = int(column_index_c);	
column_index = column_index - 65;	

int column_index2 = int(column_index_c_2);	
column_index2 = column_index2 - 65;	
	
for(int i = 1;i < input.length(); i++){
row_index_c[i-1] = input[i];	
}	

for(int i = 1;i < input2.length(); i++){
row_index_c_2[i-1] = input2[i];	
}	


for(int j = 0; j < row_index_c.length(); j++){
	k = int ((row_index_c[j]) - 48);
	row_index = row_index + k;
	row_index = row_index * 10;
	}
    row_index = row_index/10;
	row_index--;
	
	if (not( ( row_index<rows and row_index>=0 ) and ( column_index<columns and column_index >= 0 ) ) ){
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}

    
for(int j = 0; j < row_index_c_2.length(); j++){
	k = int ((row_index_c_2[j]) - 48);
	row_index2 = row_index2 + k;
	row_index2 = row_index2 * 10;
	}
    row_index2 = row_index2/10;
	row_index2--;
	
	if ( ( row_index2<rows and row_index2>=0 ) and ( column_index2<columns and column_index2 >= 0 ) ){

   int i, j; 
   int temp = 0; 

if (row_index == row_index2 and column_index < column_index2){

for (i = column_index; i < column_index2+1 ; i++) 
   { 
     for (j = column_index; j < column_index2-i; j++) 
     { 
        if (excel[row_index][j] > excel[row_index][j+1]) 
        { 
           temp = excel[row_index][j];
           excel[row_index][j] = excel[row_index][j+1];
           excel[row_index][j+1] = temp;
        } 
     } 

   }  
	
}else if(row_index < row_index2 and column_index == column_index2){
	
for (i = row_index; i < row_index2+1 ; i++) 
   { 
     for (j = row_index; j < row_index2-i; j++) 
     { 
        if (excel[j][column_index] > excel[j+1][column_index]) 
        { 
           temp = excel[j][column_index];
           excel[j][column_index] = excel[j+1][column_index];
           excel[j+1][column_index] = temp;
        } 
     } 

   }  	
	
}else{
cout<<"you have selected wrong pattern or wrong locations";
return -1;		
}


}else{
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}


return 0;
	
}


int Bubble_Ascending(int excel[rows][columns],string input,string input2){


   char column_index_c , column_index_c_2;	
string row_index_c = " ";	
string row_index_c_2 = " ";
int k,k2;
int row_index = 0 , row_index2 = 0;
column_index_c = input[0];
column_index_c_2 = input2[0];
int column_index = int(column_index_c);	
column_index = column_index - 65;	

int column_index2 = int(column_index_c_2);	
column_index2 = column_index2 - 65;	
	
for(int i = 1;i < input.length(); i++){
row_index_c[i-1] = input[i];	
}	

for(int i = 1;i < input2.length(); i++){
row_index_c_2[i-1] = input2[i];	
}	


for(int j = 0; j < row_index_c.length(); j++){
	k = int ((row_index_c[j]) - 48);
	row_index = row_index + k;
	row_index = row_index * 10;
	}
    row_index = row_index/10;
	row_index--;
	
	if (not( ( row_index<rows and row_index>=0 ) and ( column_index<columns and column_index >= 0 ) ) ){
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}

    
for(int j = 0; j < row_index_c_2.length(); j++){
	k = int ((row_index_c_2[j]) - 48);
	row_index2 = row_index2 + k;
	row_index2 = row_index2 * 10;
	}
    row_index2 = row_index2/10;
	row_index2--;
	
	if ( ( row_index2<rows and row_index2>=0 ) and ( column_index2<columns and column_index2 >= 0 ) ){

   int i, j; 
   int temp = 0; 

if (row_index == row_index2 and column_index < column_index2){

for (i = column_index; i < column_index2+1 ; i++) 
   { 
     for (j = column_index; j < column_index2-i; j++) 
     { 
        if (excel[row_index][j] < excel[row_index][j+1]) 
        { 
           temp = excel[row_index][j];
           excel[row_index][j] = excel[row_index][j+1];
           excel[row_index][j+1] = temp;
        } 
     } 

   }  
	
}else if(row_index < row_index2 and column_index == column_index2){
	
for (i = row_index; i < row_index2+1 ; i++) 
   { 
     for (j = row_index; j < row_index2-i; j++) 
     { 
        if (excel[j][column_index] < excel[j+1][column_index]) 
        { 
           temp = excel[j][column_index];
           excel[j][column_index] = excel[j+1][column_index];
           excel[j+1][column_index] = temp;
        } 
     } 

   }  	
	
}else{
cout<<"you have selected wrong pattern or wrong locations";
return -1;		
}


}else{
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}

	
return 0;
	
}


int Min(int excel[rows][columns],string input,string input2){




   char column_index_c , column_index_c_2;	
string row_index_c = " ";	
string row_index_c_2 = " ";
int k,k2;
int row_index = 0 , row_index2 = 0;
column_index_c = input[0];
column_index_c_2 = input2[0];
int column_index = int(column_index_c);	
column_index = column_index - 65;	

int column_index2 = int(column_index_c_2);	
column_index2 = column_index2 - 65;	
	
for(int i = 1;i < input.length(); i++){
row_index_c[i-1] = input[i];	
}	

for(int i = 1;i < input2.length(); i++){
row_index_c_2[i-1] = input2[i];	
}	


for(int j = 0; j < row_index_c.length(); j++){
	k = int ((row_index_c[j]) - 48);
	row_index = row_index + k;
	row_index = row_index * 10;
	}
    row_index = row_index/10;
	row_index--;
	
	if (not( ( row_index<rows and row_index>=0 ) and ( column_index<columns and column_index >= 0 ) ) ){
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}

    
for(int j = 0; j < row_index_c_2.length(); j++){
	k = int ((row_index_c_2[j]) - 48);
	row_index2 = row_index2 + k;
	row_index2 = row_index2 * 10;
	}
    row_index2 = row_index2/10;
	row_index2--;
	
	if ( ( row_index2<rows and row_index2>=0 ) and ( column_index2<columns and column_index2 >= 0 ) ){

int min = 99999;

if (row_index == row_index2 and column_index < column_index2){

for(int i = column_index ;i <= column_index2 ;i++)	
if (min >= excel[row_index][i]) 	
min = excel[row_index][i];

cout<<"\nMin = "<<min<<"\n";	
	
}else if(row_index < row_index2 and column_index == column_index2){
	
for(int i = row_index ;i <= row_index2 ;i++)	
if(min >= excel[i][column_index])
min = excel[i][column_index]; 	

cout<<"\nMin = "<<min<<"\n";	
	
}else{
cout<<"you have selected wrong pattern or wrong locations";
return -1;		
}


}else{
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}




	
return 0;
	
}


int Max(int excel[rows][columns],string input,string input2){




   char column_index_c , column_index_c_2;	
string row_index_c = " ";	
string row_index_c_2 = " ";
int k,k2;
int row_index = 0 , row_index2 = 0;
column_index_c = input[0];
column_index_c_2 = input2[0];
int column_index = int(column_index_c);	
column_index = column_index - 65;	

int column_index2 = int(column_index_c_2);	
column_index2 = column_index2 - 65;	
	
for(int i = 1;i < input.length(); i++){
row_index_c[i-1] = input[i];	
}	

for(int i = 1;i < input2.length(); i++){
row_index_c_2[i-1] = input2[i];	
}	


for(int j = 0; j < row_index_c.length(); j++){
	k = int ((row_index_c[j]) - 48);
	row_index = row_index + k;
	row_index = row_index * 10;
	}
    row_index = row_index/10;
	row_index--;
	
	if (not( ( row_index<rows and row_index>=0 ) and ( column_index<columns and column_index >= 0 ) ) ){
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}

    
for(int j = 0; j < row_index_c_2.length(); j++){
	k = int ((row_index_c_2[j]) - 48);
	row_index2 = row_index2 + k;
	row_index2 = row_index2 * 10;
	}
    row_index2 = row_index2/10;
	row_index2--;
	
	if ( ( row_index2<rows and row_index2>=0 ) and ( column_index2<columns and column_index2 >= 0 ) ){

int max = -99999;

if (row_index == row_index2 and column_index < column_index2){

for(int i = column_index ;i <= column_index2 ;i++)	
if (max <= excel[row_index][i]) 	
max = excel[row_index][i];

cout<<"\nMax  = "<<max<<"\n";	
	
}else if(row_index < row_index2 and column_index == column_index2){
	
for(int i = row_index ;i <= row_index2 ;i++)	
if(max <= excel[i][column_index])
max = excel[i][column_index]; 	

cout<<"\nMax  = "<<max<<"\n";	
	
}else{
cout<<"you have selected wrong pattern or wrong locations";
return -1;		
}


}else{
cout<<"\nthe location you have selected does not exist!\n";
return -1;
}




	
return 0;
	
}


void print_excel(int excel[rows][columns]){
	
char c;
int number_of_digits;

cout<<endl;
for (int i=65;i<65+columns;i++){
c = i;
for(int j = 1;j<=7;j++){
if (i == 65 and j == 6)
break;
cout<<" ";
}
cout<<c;		
}	

cout<<"\n\n-+";
for(int i = 0; i < columns; i++)	
cout<<"-------+";
	

for(int i = 0;i<rows;i++){
cout<<"\n\n"<<i+1<<"|";	
for(int j = 0;j<columns;j++){
if(excel[i][j] >= 0 and excel[i][j] <=9)	
cout<<"   "<<excel[i][j]<<"   |";
else if((excel[i][j] > 9 and excel[i][j] <=99) or (excel[i][j] < 0 and excel[i][j] >=-9))
cout<<"  "<<excel[i][j]<<"   |";
else if((excel[i][j] > 99 and excel[i][j] <=999) or (excel[i][j] < -9 and excel[i][j] >=-99))
cout<<"  "<<excel[i][j]<<"  |";
}
cout<<"\n\n-+";
for(int i = 0; i < columns; i++)	
cout<<"-------+";
	
}

}	
