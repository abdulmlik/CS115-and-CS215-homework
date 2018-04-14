#include<iostream>
#include <cmath>

void    exp();  
double  exp(double,int) ;
long    fact(int) ;


using namespace std;

int main()
 {

  char input ;
   
  while (true)
  {

   system("cls");

   cout << "\t\t\t\tName          : Lutfi Salem " << endl ;
   cout << "\t\t\t\tStudent number: *********** "        << endl ;

   cout << "\t\t\t\n\nChoose one of the following options\n" << endl ;
   cout << "\t\t\t1. Exp    Function" << endl ;
   cout << "\t\t\t2. Exit" << endl ;

   cout << " your input " ;
   cin.get(input);

   switch (input)
   {
    case '1':   exp();  break;
    case '2':   exit(0) ;
    default :   cerr << "***error*** invalid input\n " ;
   } //  switch (input)
  }  //while (true)
  
  return 0;
  
 } // main

void exp()
{
  int  n;
  double x;
  cout<<"Enter the value of x : ";
  cin>>x;

  cout<<"Enter the value of n : ";
  cin>>n;
   
  cout<<"\nexp ("<< x<<" ) =" << exp(x,n)<<  endl;
  cout<< "The value of exp( " << x << " ) using library function = " << exp(x) << endl  ;

  system("pause") ;	
}  // exp()

long fact(int n)
{ if ( n ==0 || n==1 ) return 1;
  return n*fact(n-1);
} 
double exp(double x,int n )
{
  int i;
  double sum=1;
  
  for( int i=1;i<=n;i+=1)
   { 
   	sum+=(pow(x,i)/fact(i));
   }
  return sum ;	
} // exp(float,int)


