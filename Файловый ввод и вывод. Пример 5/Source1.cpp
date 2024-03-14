#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isValidHTML(const string& filename)
{
    fstream file(filename, ios::in);
    if (!file.is_open())
    {
        cout << "Unable to open file " << filename << endl;
        return false;
    }

    int tagCounter = 0;
    string line;

    while (getline(file, line))
    {
        for (size_t i = 0; i < line.size(); i++)
        {

            char& c = line[i];

            if (c == '<')
            {
                tagCounter++;
            }
            else if (c == '>')
            {
                tagCounter--;
            }
            if (tagCounter < 0)
            {
                cout << "Error: Unmatched '>' found" << endl;
                cout << "Total errors found: " << tagCounter << endl;
                file.close();
                return false;
            }
        }
    }

    if (tagCounter > 0)
    {
        cout << "Error: Not all tags closed" << endl;
        cout << "Total errors found: " << tagCounter << endl;
        file.close();
        return false;
    }

    file.close();
    return true;
}

int main()
{
    string filename;
    cout << "Enter HTML file name: ";
    cin >> filename;

    if (isValidHTML(filename))
    {
        cout << "HTML file is valid." << endl;
    }
    else
    {
        cout << "HTML file is not valid." << endl;
    }

    return 0;
}
