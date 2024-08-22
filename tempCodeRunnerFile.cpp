d!!!\n ";
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