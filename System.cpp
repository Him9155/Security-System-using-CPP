#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std ;

int main(){
    int a , i=0 ;
    string text , old , password1 , password2 , pass, name, password0 , age , user , word, word1 ;
    string creds[2],cp[2] ;

    cout << " Security System " << endl ;
    cout << "_________________" << endl << endl ;
    cout << " Register " << endl ;
    cout << " Login " << endl ;
    cout << " Change Password " << endl ;
    cout << " End Program " << endl << endl ;

    do{
        cout << endl ;
        cout << "Enter your choice : " ;
        cin >> a ;

        switch(a){
            case 1 : {
                cout << "-------Register---------" << endl << endl ;
                cout << "Please enter your username: " ;
                cin >> name ;
                cout << "Please enter your password: " ;
                cin >> password0 ;
                cout << "Enter your age: " ;
                cin >> age ;
                
                ofstream of1 ; // of1 is an object of class ofstream . ofstream is used to open a file to write something in it;instream class is used to open a file to read something in it.
                of1.open("file.txt") ;
                if(of1.is_open()){
                    //is_open-- it will keep the file open until the operation is getting executed i.e. all the details are submitted.
                    of1 << name << endl ;
                    of1 << password0 ;
                    cout << "Registration Successful" << endl ;
                }

                break ;
            }

            case 2 :{
                i = 0 ;

                cout << "----------Login-----------" << endl << endl ;

                ifstream of2 ;
                of2.open("file.txt") ;
                cout << "Please enter the username: " ;
                cin >> user ;
                cout << "Please enter the password: " ;
                cin >> pass ;

                if(of2.is_open()){
                    while(!of2.eof()){ // end of file function means when it reaches end of file it return 0 else returns 1 ;
                        while(getline(of2,text)){ // here it will read the file line by line
                            istringstream iss(text) ;  // here it will stream the string. (stream) is like a pipe through which data flows continuously and store it into a extraction operator which will bw used further 
                                iss>> word ;  // extraction operator to store
                                creds[i] = word ;   // in this array the word is getting stored
                                i++ ;
                        }

                        if(user == creds[0] && pass == creds[1]){
                            cout << "----log in successful----" << endl << endl ;

                            cout << "Details: " << endl ;
                            cout << "Username: " + name << endl ;
                            cout << "Password: " + pass << endl ;
                            cout << "Age: " + age << endl ;
                        }
                        else{
                            cout << endl << endl ;
                            cout << "Incorrect Credentials" << endl ;
                            cout << " 1. Press 2 to login " << endl ;
                            cout << " 2. Press 3 to change the password " << endl ;
                            break ;
                        }
                    }
                }
                break ;
            }

            // case 3 : {
            //     i = 0 ;

            //     cout << "----------Change Password------------" << endl ;

            //         ifstream of0("file.txt");
            //         if (!of0.is_open()) {
            //         cout << "Error opening file for changing password." << endl;
            //         break;
            //         }
                    
            //         // of0.open("file.txt") ;
            //         cout << "Enter the old password: " ;
            //         cin >> old ;
            //         if(of0.is_open()){
            //                 while(of0.eof()){
            //                     while(getline(of0,text)){
            //                         istringstream iss(text) ;
            //                         iss >> word1 ;
            //                         cp[i] = word1 ;
            //                         i++ ;
            //                     }

            //                     if(old == cp[1]){
            //                         of0.close() ;

            //                         ofstream of1 ;
            //                         if(of1.is_open()){
            //                             cout << "Enter your new password: " ;
            //                             cin >> password1 ;
            //                             cout << "Enter your password again: " ;
            //                             cin >> password2 ;

            //                             if(password1 == password2){
            //                                 of1 << cp[0] << endl ;
            //                                 of1 << password1 ;
            //                                 cout << "Password changed Successfully" << endl ;
            //                             }
            //                             else{
            //                                 of1 << cp[0] << endl ;
            //                                 of1 << old ;
            //                                 cout << "Password do not match"<< endl ;
            //                             }
            //                         }

            //                     }
            //                     else{
            //                         cout << "Please enter a valid password" ;
            //                         break ;
            //                     }
            //                 }
                        
            //         }
            //         break ;
            // }
            case 3: {
                i = 0;
                cout << "----------Change Password------------" << endl;

                ifstream of0("file.txt");
                if (!of0.is_open()) {
                    cout << "Error opening file for changing password." << endl;
                    break;
                }

                cout << "Enter the old password: ";
                cin >> old;

                while (getline(of0, text)) {
                    if (i < 2) {
                        cp[i] = text;
                    } else {
                        age = text;
                    }
                    i++;
                }
                of0.close();

                if (old == cp[1]) {
                    cout << "Enter your new password: ";
                    cin >> password1;
                    cout << "Enter your password again: ";
                    cin >> password2;

                    if (password1 == password2) {
                        ofstream of1("file.txt");
                        if (of1.is_open()) {
                            of1 << cp[0] << endl;
                            of1 << password1 << endl;
                            of1 << age << endl;
                            of1.close();
                            cout << "Password changed successfully." << endl;
                        } else {
                            cout << "Error opening file for updating password." << endl;
                        }
                    } else {
                        cout << "Passwords do not match. Try again." << endl;
                    }
                } else {
                    cout << "Please enter a valid password." << endl;
                }
                break;
            }

            case 4 :{
                cout << "------------ThankYou!-------------" << endl << endl;
                break ;
            }

            default: {
                cout << "Enter a Valid choice" ;
            }
        }
    }
    while(a!=4) ;
    
    return 0 ;
    
}