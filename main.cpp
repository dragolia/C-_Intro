/* David Ragolia
 * Ryan Trackenburg
 *2/14/17
 * Ajith Kumar
 * This was made using Clion
 */



#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

bool primeFunc(int prime);//problem 2
int sumFunc(int sum1, int sum2); //problem 3
int collatz(); //problem 4
void leapFunc(); //question 5
void printX(int size); //problem 6
void collatz2(int small, int big); // problem 7

int main() {
    cout << "Hello, World!" << endl; // problem 1
    cout<<"************ problem 2 ******************"<<endl;
    cout<<primeFunc(2)<<endl;
    cout<<primeFunc(4)<<endl;
    cout<<primeFunc(7)<<endl;
    cout<<"************ problem 3 ******************"<<endl;
    cout<<sumFunc(2,5)<<endl;
    cout<<sumFunc(1,10)<<endl;
    cout<<"************ problem 4 ******************"<<endl;
    cout<<collatz()<<endl;

    cout<<"************ problem 5 ******************"<<endl;
    leapFunc();
    cout<<"************ problem 6 ******************"<<endl;
    cout<<"test 1"<<endl;
    printX(5);
    cout<<"test 2"<<endl;
    printX(7);
    cout<<"test 3"<<endl;
    printX(6);
    cout<<"************ problem 7 ******************"<<endl;
    cout<<"test 1"<<endl;
    collatz2(3,5);
    cout<<"test 2"<<endl;
    collatz2(2,7);
    cout<<"test 3"<<endl;
    collatz2(1,10);



    return 0;
}
// find whether or not an input is a prime
// a number is a prime if and only if it is divisible by one and itself
bool primeFunc(int prime){
    int divis = 1; // what we use to divide
    int whole =0; // store succeful division
    while (divis<=prime){ // run a loop until divis == prime
        if (prime%divis==0){
            whole++; // evertime remainder is 0 whole increase by 1
        }
        divis++;
    }
    if (whole<=2){
        return true;
    }
    else if (whole >2){
        return false;
    }
}
int sumFunc(int sum1, int sum2){ // add all the integer between sum1 and 2
    int lower = min(sum1,sum2);//decide which integer is lower in value
    int higher = max(sum1,sum2);// decide which is higher in value
    int lower1 = lower+1;
    int sum=0;
    while(lower1<higher){//add all the integer between the bottom and top value
        sum+=lower1;
        lower1++;
    }
    sum = sum+lower+higher;//add the bottom and top value
    return sum;
}
int collatz(){//use a series of rules to reduce any positive number to 1
    int count=0;
    int num;
    cout<<"input any positive number"<<endl;
    cin >> num;
    while(num!=1){
        if(num%2==0){//if even divide by 2
            num/=2;
        }
        else{//if odd multiply by 3 and add by 1
            num=(num*3)+1;
        }
        cout<<num<<endl;
        cout<<count<<endl;
        count++;
    }
    return count;
}

void leapFunc(){
    int year =2017;
    int year2=year+400;
    while (year<=year2){
        if (year % 4 == 0){ // if divisible by 4 go to the next statement, if not it not a leap year.
            if (year % 100 ==0){ //if divisible by 100 go to next statement, if not then it a leap year
                if (year % 400==0){ // If divisible then it a leap year if not then it not a leap year.
                    cout<<"It a leap year"<<endl;
                    cout<<year<<endl;
                    year++;
                }
                else{//not a leap year
                    year++;
                }
            }
            else{//leap year
                cout<<"It a leap year"<<endl;
                cout<<year<<endl;
                year++;
            }
        }
        else {//not a leap year
            year++;
        }
    }

}
/*when testing problem 6 I ecounter an error when the size was 3.
 * It would display question mark symbol next to the x. I showed it to Ajit Kumar
 * and we couldn't fingure out what wrong with it. other then that the function work good.
 *
 */

void printX(int size){ // print an x using astrix
    if (size%2==0){//if the size is even round up by 1
        size++;
    }
    char star[size];//create a array

    for (int i=0;i<size;i++){//create the first and last astrix on a line
        star[i]='*';
        star[abs(size-1-i)]='*';
        for(int j=0;j<size;j++){// create the space between astrix
            if (j==i||j==abs(size-1-i)){

            }
            else {
                star[j]=' ';
            }
        }

        cout<<star<<endl;

    }

}

void collatz2(int small, int big){
    int num;
    while(small<=big) {
        num=small;
        cout<<num<<endl;

        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;

            } else {
                num = (num * 3) + 1;

            }

        }
        cout<<"collatz conjecture is still working"<<endl;
        small++;
    }
}