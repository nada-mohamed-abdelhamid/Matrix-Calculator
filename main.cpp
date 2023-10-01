#include <iostream>
#include<math.h>
using namespace std;

void Add_matrix(int row,int column ,long long matrix_A [][10],long long matrix_B[][10]) //the matrix will be declared with the max range of dimensions
{   long long result_matrix [10][10];
    for(int i=0;i<row;i++)
    {
        for(int j=0; j<column;j++)

         { result_matrix[i][j]=matrix_A[i][j]+matrix_B[i][j];
            cout<<result_matrix[i][j]<<" ";}
      cout<<endl;
    }
}


void Sub_matrix(int row,int column ,long long  matrix_A [][10],long long matrix_B[][10]) //the matrix will be declared with the max range of dimensions
{  long long  result_matrix [10][10];
    for(int i=0;i<row;i++)
    {
        for(int j=0; j<column;j++)

         { result_matrix[i][j]=matrix_A[i][j]-matrix_B[i][j];
            cout<<result_matrix[i][j]<<" ";}
      cout<<endl;
    }
}


void Multiplying_matrix (int row_A,int row_B,int column_A,int column_B,long long matrix_A[][10],long long  matrix_B[][10])//1st of A * each column of B
{
    long long result_matrix[10][10]={0};  //result[row_A][column_B]
    for (int i=0;i<row_A;i++)
    {  for(int j=0;j<column_B;j++)
       {  for(int n=0;n<row_B;n++) //or column_A they both are equal
         {
             result_matrix[i][j]+=matrix_A[i][n]*matrix_B[n][j];}
       cout<<result_matrix[i][j]<<" ";       }
   cout<<endl;   }
}
long long Determinant_of_Matrix( long long  matrix[10][10], int n) {  // n is number of columns or rows (they are equal already)
   long long determinant_result = 0;
   long long  submatrix[10][10];

   if(n==1)
      return(matrix[0][0]);
   else if (n == 2)  //if size of the matrix is 2x2 calculate the determinant directly
      return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {                         //not 2x2 ! Calculate the determinant recursively
                                // calculate the inner determinant (the matrix is getting smaller till 2x2) and then multiply it with the outer value
      for (int k = 0; k < n; k++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
               int subj = 0;
               for (int j = 0; j < n; j++) {
                  if (j == k)
                  continue;
                  submatrix[subi][subj] = matrix[i][j];
                  subj++;
               }
               subi++;

            }
            determinant_result = determinant_result + (pow(-1, k) * matrix[0][k] * Determinant_of_Matrix( submatrix, n - 1 ));
      }
   }
   return determinant_result;
}




int main()
  {
      int error_flag=0;
      int no_repeat_flag =0;

    long long  matrix_A[10][10]={0} ; //initialization
    long long matrix_B[10][10] ={0};
    int row_A=0,column_A=0 ,row_B=0 ,column_B=0 ;

cout<<"Please enter dimensions of Matrix A:"<<endl;
cin>>row_A>>column_A;


cout<<"Please enter dimensions of Matrix B:"<<endl;
cin>>row_B>>column_B;




cout<<"Please enter values of Matrix A:"<<endl;
for(int i=0; i<row_A;i++)
  {  for(int j=0;j<column_A;j++){
      cin>> matrix_A[i][j];
     if(matrix_A[i][j]>100 || matrix_A[i][j]<-100)
     {
 error_flag=1; //enter the loop to choose quit

 }
} }

if(error_flag==0){  //to avoid asking for B's values if A's values have an ' out of range' error
cout<<"Please enter values of Matrix B:"<<endl;
for(int i=0; i<row_B;i++)
  {  for(int j=0;j<column_B;j++){
      cin>>matrix_B[i][j];
     if(matrix_B[i][j]>100 || matrix_B[i][j]<-100)
      {    error_flag=1;
}
 }}
}

  int operation_no ;   //the operation type that the user will choose


while(no_repeat_flag==0){

if (error_flag==1) //if it was at the end of the loop and it is true , after quiting and getting thank you ,it will print the operation in invalid again
{
    cout<<"The operation you chose is invalid for the given matrices."<<endl;
    error_flag=0;
}
cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
  cin>>operation_no;


switch(operation_no)
{
case 1:
    //Addition of two matrices
if((row_A!=row_B) || (column_A!=column_B))
{
   error_flag=1;
}else {
Add_matrix(row_A,column_A,matrix_A,matrix_B) ;
}
    break ;


case 2:
    //Subtraction of two matrices
if((row_A!=row_B) || (column_A!=column_B))
{
error_flag=1;
}
else{
Sub_matrix(row_A,column_A,matrix_A,matrix_B) ;}
    break;



case 3:
    //Multiplication of two matrices
if(column_A==row_B) /* Make sure that the the number of columns in the 1st one equals the number of rows in the 2nd one.
    (The pre-requisite to be able to multiply)*/
{
    Multiplying_matrix(row_A,row_B,column_A,column_B,matrix_A,matrix_B);
 }
else {
error_flag=1;
}
    break;



case 4:
    //Division of two matrices
    break;

case 5:
    //Determinant of matrix A
if(column_A==row_A){   //it has to be a square matrix
   long long result =Determinant_of_Matrix(matrix_A,row_A) ;
   cout<<result<<endl;
}
else
    error_flag=1;

    break;

case 6:
    //Determinant of matrix B
    if(column_B==row_B){ // it has to be a square matrix
    long long result =Determinant_of_Matrix(matrix_B,row_B) ;
    cout<<result<<endl;
}
else
    error_flag=1;
    break ;

case 7:
    //Quit
    cout<<"Thank you!"<<endl;
    no_repeat_flag =1;
    break;

default :
    //error for choosing number out of the range
error_flag=1;
    break;
}


  }
    return 0;
}
