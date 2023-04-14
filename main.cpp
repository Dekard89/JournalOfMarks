
#include <string>
#include "MyFile.h"

int main() {
    string path="C:\\Programming\\projects\\Map\\resourse.txt";
    auto journal= JournalFromFile(path);
    ShowMap(journal);
    string path2="C:\\Programming\\projects\\Map\\export.txt";
    ExportJournalToFile(journal,path2);
    NewStudent(journal,"Vasiliy",3);
    ShowMap(journal);
    UpdateMarks(journal,"Vasiliy",5);
    ShowMap(journal);
    DeleteRecord(journal,"Vasiliy");
    ShowMap(journal);
    auto test= FindStudent(journal,"Ivanov");




    return 0;
}
