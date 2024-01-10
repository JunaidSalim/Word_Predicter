#include <iostream>
#include <string>
#include <map>
#include <chrono>
#include <thread>
#include <vector>
#include <conio.h>
#include <algorithm>
using namespace std;

void printMap(map<string, int> M)
{
    for (auto i : M)
    {
        cout << endl
             << i.first << " " << i.second;
    }
}

bool isNotRepeated(vector<string> v, string s)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == s)
        {
            return 0;
        }
    }
    return 1;
}

vector<string> Suggestions(map<string, int> M)
{
    vector<int> keys;
    vector<string> suggestions;
    for (auto i : M)
    {
        keys.push_back(i.second);
    }
    sort(keys.begin(), keys.end());
    if (keys.size() > 4)
    {
        for (int i = keys.size() - 1; i >= keys.size() - 4; i--)
        {
            for (auto j : M)
            {
                if (keys[i] == j.second && isNotRepeated(suggestions, j.first))
                {
                    suggestions.push_back(j.first);
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = keys.size() - 1; i >= 0; i--)
        {
            for (auto j : M)
            {
                if (keys[i] == j.second && isNotRepeated(suggestions, j.first))
                {
                    suggestions.push_back(j.first);
                    break;
                }
            }
        }
    }
    return suggestions;
}

int main()
{
    map<string, int> map;
    vector<string> suggestions;
    vector<string> vect;
    string word;
    bool check = false;
    char choice;
    cout << "START TYPING: Press Enter Instead  of Spacebar when you complete a word\n";
    while (1)
    {
        if (vect.size() >= 1)
        {
            for (int i = 0; i < vect.size(); i++)
            {
                cout << vect[i] << " ";
            }
        }
        cin >> word;
        vect.push_back(word);
        map[word]++;
    suggest:
        suggestions = Suggestions(map);
        if (check)
        {
            system("cls");
            for (int i = 0; i < vect.size(); i++)
            {
                cout << vect[i] << " ";
            }
            check = false;
        }

        if (suggestions.size() >= 4)
        {
            cout << "\033[15;0H"
                 << "Press Ctrl + A)" << suggestions[0] << "\tCtrl + B)" << suggestions[1] << "\tCtrl + C)" << suggestions[2] << "\tCtrl + D)" << suggestions[3] << std::flush;
            cout << endl
                 << "Esc to Exit OR ENTER/SPACEBAR to skip\n";
            choice = getch();
        }
        else
        {
            if (suggestions.size() == 3)
            {
                cout << "\033[15;0H"
                     << "Press Ctrl + A)" << suggestions[0] << "\tCtrl + B)" << suggestions[1] << "\tCtrl + C)" << suggestions[2] << std::flush;
                cout << endl
                     << "Esc to Exit OR ENTER/SPACEBAR to skip\n";
                choice = getch();
            }
            if (suggestions.size() == 2)
            {
                cout << "\033[15;0H"
                     << "Press Ctrl + A)" << suggestions[0] << "\tCtrl + B)" << suggestions[1] << std::flush;
                cout << endl
                     << "Esc to Exit OR ENTER/SPACEBAR to skip\n";
                choice = getch();
            }
            if (suggestions.size() == 1)
            {
                cout << "\033[15;0H"
                     << "Press Ctrl + A)" << suggestions[0] << std::flush;
                cout << endl
                     << "Esc to Exit OR ENTER/SPACEBAR to skip\n";
                choice = getch();
            }
        }

        if (choice == 1)
        {
            vect.push_back(suggestions[0]);
            map[suggestions[0]]++;
            check = true;
            goto suggest;
        }
        else if (choice == 2)
        {
            vect.push_back(suggestions[1]);
            map[suggestions[1]]++;
            check = true;
            goto suggest;
        }
        else if (choice == 3)
        {
            vect.push_back(suggestions[2]);
            map[suggestions[2]]++;
            check = true;
            goto suggest;
        }
        else if (choice == 4)
        {
            vect.push_back(suggestions[3]);
            map[suggestions[3]]++;
            check = true;
            goto suggest;
        }
        else if (choice == 27)
        {
            break;
        }
        else
        {
            system("cls");
        }
        system("cls");
    }
}