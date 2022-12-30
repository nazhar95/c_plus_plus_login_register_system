#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool
isLoggedIn ()
{
    string username, password, un, pw;
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    ifstream read ("C:\\" + username + ".txt");
    getline (read, un);
    getline (read, pw);

    if (un == username && pw == password)
    {
      return true;
    }
    else
    {
      return false;
    }
}

int
main ()
{
  cout << setw (25) << "Welcome to the X System! \n";
  int choice;
  
  cout << "Please choose one of the options below: \n";

  cout << "1 : Register\n2 : Login\nYour choice: ";
  cin >> choice;

  if (choice == 1)
  {
    string username, password;

    cout << "Select a username: ";
    cin >> username;

    cout << "Select a password: ";
    cin >> password;

    ofstream file;
    file.open ("C:\\" + username + ".txt");
    file << username << endl << password;
    file.close ();

    main ();
  }
  else if (choice == 2)
  {
    bool status = isLoggedIn ();

    if (!status)
    {
      cout << "Error: Username or Password is incorrect!" << endl;
      system ("PAUSE");
      return 0;
    }
    else
    {
      cout << "Status: Successfully logged in!" << endl;
      system ("PAUSE");
      return 1;
    }
  }
  
  if(choice!=1 || choice!=2){
     cout << "Error: You have entered an invalid input!" << endl;
     system ("PAUSE");
     return 0;
  }  
}

