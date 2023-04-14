#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

void ShowMap(map<string,vector<string>>journal) {
    for (auto item: journal) {
        cout << item.first << ":";
        for (auto item: item.second)
            cout<< item << " ";
        cout << endl;
        cout<<endl;
    }

}
map<string,vector<string>>JournalFromFile(string path){
   map<string,vector<string>>result;
    vector<string>marks;
    string name;
    string line;
    ifstream file;
    file.open(path);
    if (!file.is_open())
        cerr<<"Error"<<endl;
    while (getline(file,line,'-')){
        name=line;
        while (getline(file,line,' ')){
            marks.push_back(line);
        }
        result.insert(pair<string,vector<string>>(name,marks));
    }
    file.close();
    return result;
}
void ExportJournalToFile(map<string, vector<string>>& journal, string path) {
        ofstream file;
        file.open(path);
        if (!file.is_open())
            cerr << " Error" << endl;
        for (auto item: journal) {
            file << item.first << ":";
            for (auto item: item.second)
                file << item << " ";
            file << endl;
        }
}
void NewStudent(map<string,vector<string>> &journal,string name, int firstmark) {
    vector<string>marks;
    marks.push_back(to_string(firstmark));
    journal.insert(pair<string,vector<string>>(name,marks));
}
void UpdateMarks(map<string,vector<string >>& journal,string name, int newmark){
    journal[name].push_back(to_string(newmark));


    }

void DeleteRecord(map<string,vector<string>> &journal,string name){
    journal.erase(name);
}
vector<string> FindStudent(map<string,vector<string>>& journal,string name) {
    vector<string> error={0,0,0,0};
    if (journal.count(name))
        return journal[name];
    else

        return error;
}