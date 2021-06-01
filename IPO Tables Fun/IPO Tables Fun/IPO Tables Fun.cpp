//system("cls"); is used throughout the program to clear the console and make the output more readable
#include <iostream>
#include <math.h>
#include <string>

//namespace for convenient code
using namespace std;

//initialize variables
string sName, sInput, sInput2;
int iNumOne, iNumTwo, iInput, iModded, iSelect;
double rPercent, iMark;
bool bExit;

int main()
{
    //initialize boolean for loop exit
    bExit = false;

    cout << "Hello World! We have 3 programs inplimented here. Type 1, 2, or 3 to start it!\n";
    cout << "If you wish to leave, type out the word 'Exit' to close the program.\n";

    //start loop
    do
    {
        //user input
        cout << "\nWhich program do you wish to use?\n";
        getline(cin,sInput);

        //error trap to differentiate between string and integer input
        try
        {
            //cpmvert input to integer
            iSelect = stoi(sInput);

            //detect which program the user wants to use
            switch (iSelect) 
            {
                case 1:
                {
                    //bool for exiting loop and error message
                    bool validNumber = false;

                    //loop for input convenience
                    while (validNumber == false)
                    {
                        //Input
                        cout << "\nWhat is your name?\n";
                        cin >> sName;

                        cout << "What is your mark out of 50?\n";
                        getline(cin, sInput);
                        getline(cin, sInput);

                        //Error trap if user did not enter number
                        try
                        {
                            //convert input to float (I know it says integer)
                            iMark = stoi(sInput);
                            
                            //check for invalid input
                            if ((iMark > 50) or (iMark < 1))
                            {
                                system("cls");
                                cout << "Please enter a number greater than 0 and less than 61.\n";
                            }
                            else
                            {
                                //process
                                rPercent = iMark / 50 * 100;

                                //output
                                system("cls");
                                cout << "Hello " << sName << ", your mark is " << iMark << "/50, resulting in a percentage of " << rPercent << "%!\n";
                                validNumber = true;
                            }
                        }

                        //error message
                        catch (invalid_argument const& e)
                        {
                            system("cls");
                            cout << "Please enter a valid number!\n";
                        }
                    }
                }
                    break;
                    //

                case 2:
                {
                    //bool for loop exit
                    bool validNumber = false;

                    //loop for input convenience
                    while (validNumber == false)
                    {
                        //input
                        cout << "\nWhat is the first number?\n";
                        getline(cin, sInput);
                        cout << "What is the second number?\n";
                        getline(cin, sInput2);

                        //error trap
                        try
                        {
                            //convert input
                            iNumOne = stoi(sInput);
                            iNumTwo = stoi(sInput2);

                            //process input and output accordingly
                            system("cls");
                            if (iNumOne > iNumTwo)
                            {
                                cout << "The bigger number is " << iNumOne << ".\n";
                            }
                            else
                            {
                                cout << "The bigger number is " << iNumTwo << ".\n";
                            }

                            validNumber = true;
                        }

                        //error message
                        catch (invalid_argument const& e)
                        {
                            system("cls");
                            cout << "Please give valid numbers!\n";
                        }
                    }
                }
                    break;

                case 3:
                {
                    //input
                    cout << "Give me a number.\n";
                    getline(cin, sInput);

                    //error trap
                    try
                    {
                        //convert input
                        iInput = stoi(sInput);
                        iModded = iInput % 2;
                        system("cls");

                        //process and output
                        if (iModded == 0)
                        {
                            cout << iInput << " is equal.\n";
                        }
                        else
                        {
                            cout << iInput << " is not equal.\n";
                        }

                    }

                    //error message
                    catch (invalid_argument const& e)
                    {
                        system("cls");
                        cout << "Please enter a valid number!\n";
                    }
                }                    
                    break;

                //error message
                default:
                    cout << "Please enter a valid number.\n";
                    break;
            }
        }

        //if string was used for base input this happens
        catch (invalid_argument const& e)
        {
            //check if user wants to exit
            if (sInput == "Exit")
            {
                bExit = true;
            }
            else
            {
                //clear console for clearity
                system("cls");
                cout << "Did you try to exit? Type 'Exit' to exit the program.\n";
            }
        }
    }while (bExit == false); // loop exit condition
}
