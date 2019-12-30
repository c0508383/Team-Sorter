#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include "myArrayList.h"
#include "Team.h"
using namespace std;

class FileIOError:public exception{
    private:
        string msg;
    public:
        FileIOError(string s){msg = s;};
        string what(){return msg;};
};
class InvalidOption:public exception{
    private:
        string msg;
    public:
        InvalidOption(string s){msg = s;};
        string what(){return msg;};
};
class InvalidLine:public exception{
    private:
        string line;
    public:
        InvalidLine(string s){line = s;};
        string what(){
            string msg = "Invalid argument, expected string int int int, on line: " + line;
            return msg;
        };
};

int main(){
    string fileName;
    cin >> fileName;
    ifstream input(fileName);
    ifstream inputO(fileName);

    string inputS;

    try{
        if(!input.is_open()){
            throw FileIOError("Error: Could not open file.");
        }

        int option;
        cin >> option;
        
        if(option < 1 || option > 3){
            throw InvalidOption("Error: Invalid option. Choose from options 1(read doubles file), 2(read string file), 3(read nfl team file).");
        }

        if(option == 1){
            int size;

            getline(input,inputS);
            size = stoi(inputS);

            myArrayList<double> list(size);
            double elem;            

            while(!input.eof()){
                getline(input,inputS);
                elem = stod(inputS);
                try{
                    list.addElement(elem);
                }
                catch (runtime_error &excpt) {
                    cout << excpt.what() << endl;
                }
            }

            list.sort();
            list.print();
        }
    
        if(option == 2){
            int size;

            getline(input,inputS);
            size = stoi(inputS);

            myArrayList<string> list(size);

            while(!input.eof()){
                getline(input,inputS);
                try{
                    list.addElement(inputS);
                }
                catch (runtime_error &excpt) {
                    cout << excpt.what() << endl;
                }
            }

            list.sort();
            list.print();
        }

        if(option == 3){
            int inputI, size;

            getline(input,inputS);
            size = stoi(inputS);

            myArrayList<Team> list(size);

            int lineNo = 0;
            while(!input.eof()){
                lineNo++;
                
                string name, line;
                int wins, ties, losses;
                bool isInt = true;

                try{
                    getline(input,line);
                    istringstream ss(line);

                    ss >> name;

                    ss >> inputS;
                    isInt = (inputS.find_first_not_of( "0123456789" ) == string::npos);
                    if(!isInt || inputS == ""){
                        throw InvalidLine(line);
                    }
                    else{
                        wins = stoi(inputS);
                        inputS = "";
                    }

                    ss >> inputS;
                    isInt = (inputS.find_first_not_of( "0123456789" ) == string::npos);
                    if(!isInt || inputS == ""){
                        throw InvalidLine(line);
                    }
                    else{
                        ties = stoi(inputS);
                        inputS = "";
                    }
                    
                    ss >> inputS;
                    isInt = (inputS.find_first_not_of( "0123456789" ) == string::npos);
                    if(!isInt || inputS == ""){
                        throw InvalidLine(line);
                    }
                    else{
                        losses = stoi(inputS);
                        inputS = "";
                    }

                    Team inputT(name,wins,ties,losses);
                    try{
                        list.addElement(inputT);
                    }
                    catch (runtime_error &excpt) {
                        cout << excpt.what() << endl;
                    }
                }
                catch(InvalidLine &excpt){
                    cout << excpt.what() << endl;
                    continue;
                }
            }

            list.sort();
            list.print();
        }
    }
    catch(FileIOError &excpt){
        cout << excpt.what() << endl;
        exit(0);
    }
    catch(InvalidOption &excpt){
        cout << excpt.what() << endl;
        exit(0);
    }

    return 0;
}