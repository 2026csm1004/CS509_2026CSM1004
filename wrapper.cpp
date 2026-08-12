#include <iostream>
#include <cstdlib>

using namespace std;

void run_assignment_01()
{
    system("cd /d .\\assignment_01 && driver.exe");
}

void run_assignment_02()
{
    system("cd /d .\\assignment_02 && shortest_path.exe");
}

int main()
{
    int choice;

    cout << "Press 1 for Assignment 1\n";
    cout << "Press 2 for Assignment 2\n";
    cout << "Enter choice: ";

    cin >> choice;

    if(choice == 1)
    {
        run_assignment_01();
    }
    else if(choice == 2)
    {
        run_assignment_02();
    }
    else
    {
        cout << "Invalid choice\n";
    }

    return 0;
}