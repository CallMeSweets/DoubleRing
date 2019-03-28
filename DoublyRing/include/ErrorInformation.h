#ifndef ERRORINFORMATION_H
#define ERRORINFORMATION_H

#include<vector>
#include<string>

using namespace std;

class ErrorInformation
{
    public:

    vector<string> errorMessages;
    int errorNumber;



        ErrorInformation(): errorNumber(0){}

        virtual ~ErrorInformation(){}



        void addError(string message){
            errorMessages.push_back(message);
            errorNumber++;
        }

        void showReport(ostream &os){

        os << "Number of errors: " << errorNumber << "\n";

            for(string message: errorMessages){
                os << message << "\n";
            }

        }



};

#endif // ERRORINFORMATION_H
