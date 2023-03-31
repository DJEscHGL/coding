#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int counter, size = 0;
    fstream fout; string value;
    string pathF("f.txt");
    string pathG("g.txt");
    cout << "Input positive/negative numbers count" << endl;
    cin >> counter;
    fout.open(pathF, fstream::in | fstream::out | fstream::app);
    if (!fout.is_open())
    {
        cout << "cannot open F file" << endl;
    }
    else
    {
        cout << "Input positive/negative numbers" << endl;
        for (int i = 0; i < counter; i++)
        {
        cin >> value;
        fout << value;
        fout << endl;
        }
        while (!fout.eof())
        {
            //value = "";
            fout >> value;
            cout << value << endl;
        }            

        /*int* arr = new int[size];*/
    }
    fout.close();
    return 0;

}

