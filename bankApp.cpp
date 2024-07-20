#include <bits/stdc++.h>

using namespace std;

// ===============================================================================
// following things given me into the question paper
// time is around 1h 45m i guess not sure coz not written in question paper
// this is question for round 4 at RK office it self
// you can use your mobile phone or not even internet in this question
// ===============================================================================

// set of account number unique and 10 digit long
// set of adhar card number unique and 12 digit long
// set of pan card number unique and as per formate(length , type of char)
// address proof (any document as link)
// account type (saving , business)
// account balance cant be negative
// make emi calculator for loan
// one can open new account in our bank by default bank balance is 1000
// make a feature for deposit
// make a feature for transfer money to theres account
// one feature for last 365 day bank statement
// one user can open more than one account in the bank

// ===============================================================================

// this is the code i wrote in 1h 30m all above points are not properly coved but still got selected coz you can do all of those within 1.5h
// Best wishes to you for interview 😉

// ===============================================================================




// following is user defined datatype to hold info of account
struct AccountInfo
{
    int id;
    string name;
    string adharNum;
    string panNum;
    string type;
    int balance;
    // Transaction history;        defined but not completed
};
// following is user defined datatype to hold info of transaction
struct Transaction
{
    int fromId;
    int toId;
    int amount;
};


// following is an array to store all account
vector<AccountInfo> allAccount;

// following is an mapping 10 digit account num to account 
// this never got used coz time is completed 
map<string , AccountInfo> accNum_to_info_mapping;


// following is an mapping to store all transactions
map<int, Transaction> allTransactions;



// following function is to debug my coz to see code is working or not so i print all account info by using following code
void debugAccount()
{
    for (auto acc : allAccount)
    {

        cout << endl;
        cout << "###################################################" << endl;
        cout << "=> id     : " << acc.id << endl;
        cout << "=> name   :" << acc.name << endl;
        cout << "=> adhar  :" << acc.adharNum << endl;
        cout << "=> pan    :" << acc.panNum << endl;
        cout << "=> type   :" << acc.type << endl;
        cout << "=> balance:" << acc.balance << endl;
        cout << "###################################################" << endl;
        cout << endl;
    }
}

void createAccountDisplay()
{

    cout << "*************************************************" << endl;
    cout << "*                 Create Account                *" << endl;
    cout << "*************************************************" << endl;

    cout << " Enter your name : ";
    string name;
    cin >> name;
    cout << endl;

    cout << " Enter your adhar number : ";
    string adhar;
    cin >> adhar;
    cout << endl;

    if (adhar.size() != 12)
        cout << "Invalid Adhar number" << endl;
    for (auto c : adhar)
    {
        if (c < '0' && c > '9')
            cout << "Invalid Adhar number" << endl;
    }
    cout << " Enter your pan number : ";
    string pan;
    cin >> pan;
    cout << endl;

    cout << " Enter account type (saving , business) : ";
    string type;
    cin >> type;
    cout << endl;

    AccountInfo ai;
    ai.id = allAccount.size();
    ai.name = name;
    ai.adharNum = adhar;
    ai.panNum = pan;
    ai.type = type;
    ai.balance = 1000;

    cout << "*************************************************" << endl;
    cout << " Your account number  =  " << allAccount.size() << endl;
    cout << "*************************************************" << endl;
    allAccount.push_back(ai);
    debugAccount();

    // cout << "*                                               *" << endl;
    // cout << "*                                               *" << endl;
    // cout << "*                                               *" << endl;
    // cout << "*************************************************" << endl;
};
void depositMoneyDisplay()
{

    cout << "*************************************************" << endl;
    cout << "*               Deposit Money                   *" << endl;
    cout << "*************************************************" << endl;
    cout << " enter your account id : ";
    int from;
    cin >> from;
    cout << endl;

    cout << " enter your amount : ";
    int amt;
    cin >> amt;
    cout << endl;

    Transaction t;
    t.toId = from;
    t.fromId = from;
    t.amount = amt;

    allAccount[from].balance += amt;
    // allAccount[to].balance + amt;

    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << " Transaction success !!!" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

    debugAccount();
};
void transferMoneyDisplay()
{

    cout << "*************************************************" << endl;
    cout << "*               Deposit Money                   *" << endl;
    cout << "*************************************************" << endl;
    cout << " enter your account id : ";
    int from;
    cin >> from;
    cout << endl;

    cout << " enter receiver account id : ";
    int to;
    cin >> to;
    cout << endl;

    cout << " enter your amount : ";
    int amt;
    cin >> amt;
    cout << endl;
    int afterBalance = allAccount[to].balance - amt;
    if (afterBalance < 1000)
        cout << "Error : Please deposit atleast 1000 rs." << endl;

    Transaction t;
    t.toId = to;
    t.fromId = from;
    t.amount = amt;

    allAccount[from].balance -= amt;
    allAccount[to].balance += amt;

    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << " Transaction success !!!" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

    debugAccount();
};

// following function you have to make i couldn't coz of time limit so its just defined not implemented so use your brain, how you can implement those

void statementDisplay() {};
void emiCalculator() {};


void display1()
{
    cout << "*************************************************" << endl;
    cout << "*                                               *" << endl;
    cout << "*                Welcome to Bank                *" << endl;
    cout << "*                                               *" << endl;
    cout << "*   1. Create Account                           *" << endl;
    cout << "*   2. Deposit money                            *" << endl;
    cout << "*   3. Transfer Money                           *" << endl;
    cout << "*   4. EMI Calculator                           *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
    cout << "*                                               *" << endl;
    cout << "*   Enter the number  : ";
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
        createAccountDisplay();
        break;
    case 2:
        depositMoneyDisplay();
        break;
    case 3:
        transferMoneyDisplay();
        break;
    case 4:
        emiCalculator();
        break;
    default:
        cout << "Invalid Choice !!!" << endl;
    }
}

int main()
{
    while (1)
    {
        display1();
    }

    return 0;
}