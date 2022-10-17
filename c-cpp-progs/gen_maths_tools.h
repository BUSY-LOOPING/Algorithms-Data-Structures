/*
	Name: firstheaderfile.h
	Author: dhruv yadav
	Date: 17/12/20 20:13
	Description: unit conversion programs converted to programs and placed in header file
*/
#include <iostream>
#include <cmath>

using namespace std;

float inch_foot(float inch) {
	
	float inch_foot=0.0;
	inch_foot=static_cast<float>(inch)/12;
	
	return inch_foot;
} 
 float inch_centimeter(float inch)  {
 	
 	float inch_centimeter=0.0;
 	inch_centimeter=inch*2.54;
 	
 	return inch_centimeter;
 }
 
 float inch_yard(float inch)  {

 	float inch_yard=0.0;
 	inch_yard=static_cast<float>(inch)/36;
 	
 	return inch_yard;
 }
 	
 float inch_meter(float inch)  {
 	
 	float inch_meter=0.0;
 	inch_meter=inch*0.0254;
 	
 	return inch_meter;
 }
 
 float fahrenheit_celsius(float fahrenheit)  {
 	
 	float fahrenheit_celsius=0.0;
 	fahrenheit_celsius=static_cast<float>(5)/9*(fahrenheit-32);
 	
 	return fahrenheit_celsius;
 }
 
 float radian_degree(float radian) {
 	
 	float radian_degree=0.0;
 	radian_degree=static_cast<float>(180)*7*radian/22;
 	
 	return radian_degree;
 }
 
 float meter_centimeter(float meter) {
 	
 	float meter_centimeter=0.0;
 	meter_centimeter=static_cast<float>(100)*meter;
 	
 	return meter_centimeter;
 }
 
 float degree_radian(float degree)  {
 	
 	float degree_radian=0.0;
 	degree_radian=static_cast<float>(22)*degree/(7*180);
 	
 	return degree_radian;
 }
 
 float celsius_fahrenheit(float celsius) {
 	
 	float celsius_fahrenheit=0.0;
 	celsius_fahrenheit=celsius*1.8+32;
 	
 	return celsius_fahrenheit;
 }
 
 
 int factorial(int n) {
	int i=1;
	for (int j=1;j<=n;j++) //factorial function is also added to the header file firstheaderfile.h
	//we can also initialize j with 2 instead of 1.
	i=i*j;
	return i;
 }
 
 
 int permutation(int n,int r) {
	int P=1; 
	P=factorial(n)/factorial(n-r);
	return P;
	
}//permutation function

int combination(int n,int r)  {
	int C=1;
	C=factorial(n)/(factorial(n-r)*factorial(r));
	return C;
	
}//combination function	


int nth_term_gp(int a,int r,int n)  {
	int T=a*(pow(r,(n-1)));
	return T;
}


bool leapyear(int year)  {
	
	if(year%4==0)
	{
		if(year%100==0)
		{
			if(year%400==0)
			return 1;
			else return 0;
		}
		else return 1;
	}
	else return 0;
}//leapyear function(returns 1 if leap year else returns 0)

bool check_prime(int n)  {
	if (n==2)  return 1;
	if (n<=1) return 0;
	for (int i=2;i<n;i++)
	{
		if (n%i==0)  
		return 0;		
	}
	return 1;
}


int num_reverse(int n) {
	int arr[100]={0};
	int i=0,rev=0;
	while (n>0)  //while loop to initialize digits from the rightmost side to the elements of the array beginning from arr[0]
	{
		arr[i]=(n%10);
		n/=10;
		i++;
	}
	i--; // done since i has 1 value more as the control exits the loop thus to compensate
	for (int j=0;j<=i;j++) //for loop to read the values of the array arr[] from arr[0] till arr[i] 
	{
		rev+=arr[j];
		rev*=10;
	}
	rev=rev/10; // done since rev has an extra 0 as the control exits the loop. thus to compensate
	return rev;
} //num_reverse function

int sum_digits (int n) {
	int sum=0;
	while (n>0)  //while loop to get last digit of n (while removing that digit every iteration)and then adding it to the sum
	{
		sum+=(n%10);
		n/=10;
	}
	return sum;
}// sum_digits function

int product_digits (int n) {
	if (n==0) return 0;
	int product=1;
	while (n>0)  //while loop to get last digit of n (while removing that digit every iteration)and then multiplying it to product
	{
		product*=(n%10);
		n/=10;
	}
	
	return product;
}// product_digits function

void first_nprime(int n) {
	int m=0;
	for (unsigned int i=1;i<=10000;i++)
	{
		if (check_prime(i)==1&&m<n)
		{
			m+=1;
			cout <<i<<'\t';
		}
	}
	return;

}//first_nprime function

void primefactors (int primefact[],int n)  {
	int j=0,m=n;
	for (int i=2;i<=n;)
	{
		if (check_prime(i)) {
		if (m%i==0)
		{
		m=m/i;
		primefact[j]=i;
		j++;
	    }
		else i++; }
		else i++; //outer if else
	} //forloop
	return;
}//primefactors function

void factors (int fact[], int n)  {
	int j=0;
	for (int i=1;i<=n;i++)
	{
		if (n%i==0)
		{
			fact[j]=i;
			j++;
		}// if-else condition to check for factors
	}// forloop 
	return;
}//factors function

int gcd(int n1,int n2) {
	int gcd=1;
	for (int i=1;i<=n1&&i<=n2;i++)  //forloop to increment value of i till the smallest of the two numbers-n1 and n2.
	{
		if (n1%i==0&&n2%i==0)
		gcd=i; //if i perfectly divides both n1 and n2, it is assigned to gcd
	}//for loop
    return gcd;
}

int lcm(int n1,int n2) {
	int m=0;
	m=(n1>n2)?n1:n2;
	while(1)
	{
		if ((m%n1==0)&&(m%n2==0))
		return m;
		else
		m++;
	}
}

bool check_palindrome(string s) {
    int size=s.size();
    char ch;
    for (int i=0;i<size;i++)
    {
        if (s[i]!=s[size-i-1]) return 0;
    }
    return 1;
}

