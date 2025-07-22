//Siyabonga Mnguni 40987167

#include <iostream>
#include <fstream>
#include <random>

using namespace std;

//declaring constant variables
const int SIZE = 100;
const double balance = 1650.53;

//declaring a struct that will collect personal details
struct Person
{
    string name;
    string surname;
    int pin;
    int studentNo;
    int cardNumber;
};

//this function will collect personal details
void PersonalDetails(Person* PtrPerson)
{
    //opening a new file
    ofstream WriteOnFile;
    WriteOnFile.open("Personal Details.txt");

    if(WriteOnFile.fail())
    {
        cout << "Unable to open the file\n";
        return;
    }

    cout << "Enter your name: ";
    getline(cin , PtrPerson->name);

    cout << "Enter your Surname: ";
    getline(cin , PtrPerson->surname);

    cout << "Enter your pin: ";
    cin >>PtrPerson->pin;

    cout << "Enter your student number: ";
    cin >> PtrPerson->studentNo;

    //providing the user with a card number;
    PtrPerson->cardNumber = 4508569825632441;

    //writing on the file
    WriteOnFile << "Name :" << PtrPerson->name << "\n";
    WriteOnFile << "Surname :" << PtrPerson->surname << "\n" ;
    WriteOnFile << "Pin :" << PtrPerson->pin << "\n" ;
    WriteOnFile << "Student Number :" << PtrPerson->studentNo << "\n" ;
    WriteOnFile << "Card Number :" << PtrPerson->cardNumber << "\n" ;

    //file will close
    WriteOnFile.close();

    cout << "\n\nInformation successfully gathered...\n\n";

}

//this function will varify users pin
void PinVarification(Person* PtrPerson)
{
    int tempPin;
    cout << "Pin varification\n\n";

    cout << "Enter your pin : ";
    cin >> tempPin;

    while(tempPin != PtrPerson->pin)
    {
        cout << "Incorrect pin , try again\n";
        cout << "Enter your pin : ";
        cin >> tempPin;
    }

    cout << "Pin was valid...\n\n";
}

//this function will withdraw a desired amount entered by the user
double withdraw(Person* PtrPerson , const double balance , double& newBalance)
{

    double withdrawAmount;
    cout << "\n#################################################";
    cout << "\nWITHDRAW\n";
    cout << "#################################################\n\n";
    cout << "Enter the amount you want to withdraw : R";
    cin >> withdrawAmount;

    while (withdrawAmount > balance || withdrawAmount <=0)
    {
        cout << "\nError , invalid amount\n";
        cout << "Please enter a positive amount to be withdrawn " << PtrPerson->name << endl;
        cout << "Your Current balance is : R" << balance << endl;

        cout << "\n\nEnter the amount you want to withdraw : R";
        cin >> withdrawAmount;

    }

       newBalance -= withdrawAmount;
       cout << "\nYour new balance is : R" << newBalance << endl;
       cout << "\nTransaction successful...\n";

   return withdrawAmount;
}

//this function will deposit a desired amount entered by the user
double depositMoney(Person* PtrPerson , const double balance , double& newBalance )
{
    double depositAmount;
    cout << "\n#################################################";
    cout << "\nDEPOSIT MONEY";
    cout << "\n#################################################\n\n";
    cout << "Enter the amount you want to deposit : R";
    cin >> depositAmount;

    while (depositAmount <= 0)
    {
        cout << "\nThe amount to be deposited cannot be negative.\n";
        cout << "Invalid amount...Amount must be greater than 0\n";

        cout << "\nEnter the amount you want to deposit : R";
        cin >> depositAmount;
    }

        newBalance += depositAmount;
        cout << "\nYour new balance is : R" << newBalance << endl;
        cout << "\nTransaction successful...\n";


    return depositAmount;
}

//this function will display the users balance
void displayBalance(Person* PtrPerson , const double balance , double newBalance)
{
    cout << "\n#################################################";
    cout << "\nVIEWING YOUR BALANCE";
    cout << "\n#################################################\n";

    cout << "Available balance : " << newBalance << "\n";
    cout << "#################################################\n\n";
}

//this function will print out the users details
void PrintStatement(Person* PtrPerson , const double balance , double newBalance)
{
    cout << "\n#################################################";
    cout << "\nNORTHWEST-UNIVERSTY STUDENT BANK\n";
    cout << "#################################################\n\n";
    cout << "Name :" << PtrPerson->name << "\n";
    cout << "Surname :" << PtrPerson->surname << "\n";
    cout << "Student Number :" << PtrPerson->studentNo << "\n";
    cout << "Card No :" << PtrPerson->cardNumber;
    cout << "\n\n#################################################\n";
    cout << "Available Balance :" << newBalance << "\n";
    cout << "#################################################\n\n";

    //printing out the statement on the file
    ofstream WriteOnFile;
    WriteOnFile.open("Bank Statement.txt");
    if(WriteOnFile.fail())
    {
        cout << "Unable to open the file\n";
        return;
    }

    WriteOnFile << "\n#################################################";
    WriteOnFile << "\nNORTHWEST-UNIVERSTY STUDENT BANK\n";
    WriteOnFile << "#################################################\n\n";
    WriteOnFile << "Name :" << PtrPerson->name << "\n";
    WriteOnFile << "Surname :" << PtrPerson->surname << "\n";
    WriteOnFile << "Student Number :" << PtrPerson->studentNo << "\n";
    WriteOnFile << "Card No :" << PtrPerson->cardNumber;
    WriteOnFile << "\n\n#################################################\n";
    WriteOnFile << "Available Balance :" << newBalance << "\n";
    WriteOnFile << "#################################################\n\n";

    WriteOnFile.close();

}

int main()
{
    //declating variables
    Person person[SIZE];
    Person* PtrPerson = person;
    int choice;
    double newBalance = balance;
    double WithDrawAmount;
    double DepositAmount;

    cout << "Write your personal into to the bank\nLoading...\n\n";

    //calling the functions
    PersonalDetails(PtrPerson);
    PinVarification(PtrPerson);


    //making use of a do-while loop
    do{
        cout << "\n#########################################################";
        cout << "\n#   WELCOM TO NORTHWEST-UNIVERSTY STUDENT BANK\t\t#\n";
        cout << "#########################################################\n";
        cout << "#\t\t\t\t\t\t\t#\n#\tMenu:\t\t\t\t\t\t#" << endl;
        cout << "#\t1. Withdraw Money\t\t\t\t#" << endl;
        cout << "#\t2. Deposit Money\t\t\t\t#" << endl;
        cout << "#\t3. Display Balance\t\t\t\t#" << endl;
        cout << "#\t4. Print Bank Statement\t\t\t\t# " << endl;
        cout << "#\t5. Exit\t\t\t\t\t\t#" << endl;
        cout << "#\t\t\t\t\t\t\t#\n#########################################################";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)//using case structure to call all of the functions
        {
        case 1:
            WithDrawAmount = withdraw(PtrPerson ,balance , newBalance);
            break;
        case 2:
            DepositAmount = depositMoney(PtrPerson , balance , newBalance);
            break;
        case 3:
            displayBalance(PtrPerson ,balance ,newBalance);
            break;
        case 4:
            PrintStatement(PtrPerson , balance , newBalance);
            break;
        case 5:
            cout << "Thank you for using our bank :) \n\nExiting...\n\n";
            break;
        default:
            cout << "\n\nInvalid input , please enter the correct input.\n\n";

        }

    }while(choice!=5);//the loop will continue until the option is 5



    return 0;
}
