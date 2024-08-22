#include <iostream>
#include <string>
using namespace std;

class customer
{
public:
    string name;
    int account_id;
    double amount;
    string address;
    customer *next;

    customer()
    {
        next = NULL;
    }
};

class accounts
{
public:
    int id = 0;

    void show(customer **head)
    {
        customer *temp = *head;
        cout << "Name: " << temp->name << "\n";
        cout << "Your account id is: " << temp->account_id << "\n";
        cout << "Your stored address is: " << temp->address << "\n";
        cout << "Amount at your account is: " << temp->amount << "\n";
    }

    void new_account(customer **head)
    {
        customer *cus = new customer();

        string name;
        string address;
        double amount;
        cout << "-------- Customer Information Field --------\n";
        cout << "\n";
        cout << "i)   Enter account holder name: ";
        cin.ignore();
        getline(cin, name);
        cout << "ii)  Enter current residential address: ";
        getline(cin, address);

        bool valid = false;
        while (valid != true)
        {
            cin.clear();
            cout << "iii) Enter amount for your account in numbers: ";
            cin >> amount;
            cout << "\n";
            if (!cin)
            {
                cout << "Error: Only numerical values input is allowed\n ";
                cin.clear();
                cin.ignore();
                valid = false;
            }
            else
            {
                valid = true;
            }
        }
        cout << "\n";

        cus->name = name;
        cus->address = address;
        cus->account_id = ++id;
        cus->amount = amount;

        if (!cus)
        {
            cout << "Your system storage is not sufficient to add the new account!\n ";
        }
        else if (*head == NULL)
        {
            *head = cus;
            show(&cus);
            cout << endl;
            cout << "    Account is successfully created! \n";
        }
        else
        {
            cus->next = *head;
            *head = cus;
            show(&cus);
            cout << endl;
            cout << "    Account is successfully created! \n";
        }
    }

    void deposit(customer **head)
    {
        customer *temp = *head;
        cout << "Your current account balance is: " << temp->amount << "\n";
        double new_amount;
        bool valid = false;
        while (valid != true)
        {
            cin.clear();
            cout << "Enter amount for deposit in your account: ";
            cin >> new_amount;
            cout << "\n";
            if (!cin)
            {
                cout << "Error: Only numerical values input is allowed\n ";
                cin.clear();
                cin.ignore();
                valid = false;
            }
            else
            {
                valid = true;
            }
        }
        temp->amount = temp->amount + new_amount;
        cout << "Your new account balance is: " << temp->amount << "\n";
    }

    void credit(customer **head)
    {
        customer *temp = *head;
        cout << "Your current account balance is: " << temp->amount << "\n";
        double credit_amount;

        bool valid = false;
        bool valid1 = false;
        while (valid1 != true)
        {
            while (valid != true)
            {
                cin.clear();
                cout << "Enter amount to credit through your account: ";
                cin >> credit_amount;
                cout << "\n";
                if (!cin)
                {
                    cout << "Error: Only numerical values input is allowed\n ";
                    cin.clear();
                    cin.ignore();
                    valid = false;
                }
                else
                {
                    valid = true;
                }
            }

            if (credit_amount > temp->amount)
            {
                cout << "Required credit is not present in your account balance !!!\n";
                valid1 = false;
                valid = false;
            }
            else
            {
                temp->amount = temp->amount - credit_amount;
                cout << "Your new account balance is: " << temp->amount << "\n";
                valid1 = true;
            }
        }
    }

    int exist_account(customer **head, int account_id)
    {
        customer *temp = *head;
        while (temp != NULL)
        {
            if (temp->account_id == account_id)
            {
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return -1;
        }
        cout << "\n";
        int choise;
        cout << "-------- Customer Account Services --------\n";
        cout << "\n";
        cout << "i)   For account details enter 1\n";
        cout << "ii)  For deposit of amount enter 2\n";
        cout << "iii) To credit from account enter 3\n";
        bool valid = false;
        while (valid != true)
        {
            cin.clear();
            cout << "Please enter your choise: ";
            cin >> choise;
            cout << "\n";

            if (!cin)
            {
                cout << "Error: Only numerical values input is allowed\n ";
                cin.clear();
                cin.ignore();
                valid = false;
            }
            else
            {
                valid = true;
            }
        }
        cout << "\n";
        if (choise == 1)
        {
            show(&temp);
        }
        else if (choise == 2)
        {
            deposit(&temp);
        }
        else if (choise == 3)
        {
            credit(&temp);
        }
        return 0;
    }

    void delete_exist_account(customer **head, int account_id)
    {
        customer *temp = *head;
        customer *temp1 = *head;

        int exits = 0;
        while (temp1 != NULL)
        {
            if (temp1->account_id == account_id)
            {
                exits = 1;
                break;
            }
            temp1 = temp1->next;
        }

        if (exits == 1)
        {
            while (temp != NULL)
            {
                if (temp->account_id == account_id)
                {
                    *head = temp->next;
                    cout << "\n    Successfully deleted!!! \n";
                    break;
                }
                else if (temp->next->account_id == account_id)
                {
                    if (temp->next->next == NULL)
                    {
                        temp->next = NULL;
                        cout << "\n    Successfully deleted!!! \n";
                        break;
                    }
                    else
                    {
                        temp->next = temp->next->next;
                        cout << "\n    Successfully deleted!!! \n";
                        break;
                    }
                }
                temp = temp->next;
            }
        }
        else
        {
            cout << "\n     Your account is not found!!!\n ";
        }
    }

    void total_no_of_account(customer **head)
    {
        customer *temp = *head;
        int count = 0;
        bool exist = false;
        while (temp != NULL)
        {
            count++;
            exist = true;
            cout << "Name: " << temp->name << "\n";
            cout << "Your account id is: " << temp->account_id << "\n";
            cout << "Your stored address is: " << temp->address << "\n";
            cout << "Amount at your account is: " << temp->amount << "\n";
            cout << endl;
            temp = temp->next;
        }
        if (exist == false)
        {
            cout << "No bank account present in our bank data base!!! \n";
        }
        else
        {
            cout << "Total no.of bank account(s) exists is: " << count << "\n";
        }
    }
};

main()
{
    int choise = 1;
    customer *head = NULL;
    accounts acc;
    string password;

    while (choise != 0)
    {
        cout << "\n";
        cout << "\n";
        cout << "--------------------< Banking Management System >--------------------\n";
        cout << "\n";
        cout << "i)   For make a new account enter 1\n";
        cout << "ii)  For existing customer account services enter 2\n";
        cout << "iii) For existing customer account deletion enter 3\n";
        cout << "iv)  For Data Base of bank customer accounts enter 4\n";
        cout << "v)   For exit the system enter any random key except above ones!  \n";
        cout << "\n";
        cout << "Please enter your choise: ";
        cin >> choise;
        cout << "----------------------------------------------------------------------\n";
        cout << "\n";
        if (choise == 0)
        {
            break;
        }
        else if (choise == 1)
        {
            acc.new_account(&head);
        }
        else if (choise == 2)
        {
            int id;
            cout << "To start with services enter your pin to land into your account: ";
            cin >> id;
            int y_n;
            y_n = acc.exist_account(&head, id);
            if (y_n == -1)
            {
                cout << "Your entered pin is incorrect or your account have not found!\n";
            }
        }
        else if (choise == 3)
        {
            int id;
            cout << "To delete any account enter the pin for required account to be deleted: ";
            cin >> id;
            acc.delete_exist_account(&head, id);
        }
        else if (choise == 4)
        {
            cout << "Before access into our data base enter password: ";
            cin.ignore();
            getline(cin, password);
            if (password == "Admin")
            {
                cout << endl;
                acc.total_no_of_account(&head);
            }
            else
            {
                cout << "Wrong password or access denied!!! \n";
            }
        }
    }
    cout << "System is shutting down...\n";
    cout << "We are thankful to you for using our system :)\n";
    cout << "\n";
}
