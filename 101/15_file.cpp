#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Create and write to a file
    ofstream Myfile("example.txt");
    if (Myfile.is_open())
    {
        Myfile << "God is Great" << endl;
        Myfile << "God is absolute!!!" << endl;
        Myfile.close();
    }
    else
    {
        cout << "Unable to open file for writing";
        return 1;
    }
    ifstream MyfileRead("example.txt");
    string line;
    if (MyfileRead.is_open())
    {
        while (getline(MyfileRead, line))
        {
            cout << line << endl;
        }
        MyfileRead.close();
    }
    else
    {
        cout << "Unable to open file for reading";
        return 1;
    }
    return 0;
}