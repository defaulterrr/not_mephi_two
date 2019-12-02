#include <vector>
#include <iostream>
using namespace std;

struct Command{
    string wholeCommand;
    vector<string> commandList;

    Command(string command){
        if (command.empty()) {} else {
        this->wholeCommand = command;   
        wholeCommand += ' ';
        analyze();
        }
    }

    string getLevel(int index){
        if (index >= commandList.size()) {
            return nullptr;
        } 
        else
            return commandList[index];
    }

    string base(){
        if (commandList.size()>0)
        return commandList[0];
        else return string();
    }

private:
    void analyze(){
        string minimalWhiteSpace = string();
        for (unsigned int i=0; i< wholeCommand.size()-1;i++){
            if(wholeCommand[i] != ' ' && wholeCommand[i]!='\n'){
                minimalWhiteSpace += wholeCommand[i];
            }
            else if (wholeCommand[i]==' ' && wholeCommand[i+1]!= ' '){
                minimalWhiteSpace += wholeCommand[i];
            }
            else if (wholeCommand[i+1]!=' ' && wholeCommand[i+2] == '\n') {
                minimalWhiteSpace += wholeCommand[i+1];
            }

        }

        minimalWhiteSpace += ' ';
        if(minimalWhiteSpace[0] == ' ') {} else
        {minimalWhiteSpace = ' ' + minimalWhiteSpace;}

        for (unsigned int i=0;i<minimalWhiteSpace.size();i++){
            int first = minimalWhiteSpace.find_first_of(' ',i);
            int last = minimalWhiteSpace.find_first_of(' ',first+1);
            i = first;
            int length = last - first;
            string message = minimalWhiteSpace.substr(first+1,length);
            if (message == "") {} else
            {commandList.push_back(message);}
        }
        for (int i = 0; i < commandList.size(); i++) {
            string message = commandList[i].substr(0,commandList[i].size()-1);
            commandList[i] = message;
        }
    }
    
};