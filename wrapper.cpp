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
void run_assignment_03(){
    system("cd /d .\\assignment_03 && mst.exe");
}

int main()
{
    int choice;

    cout << "Press 1 for Assignment 1\n";
    cout << "Press 2 for Assignment 2\n";
    cout<< "Press 3 for Assignment 3\n";
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
    else if(choice == 3){
        run_assignment_03();
    }
    else
    {
        cout << "Invalid choice\n";
    }

    return 0;
}