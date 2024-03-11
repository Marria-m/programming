#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void check_valid_Affine_Cipher(string user_text, bool& is_valid) {
    is_valid = true;
    for (int i = 0; i < user_text.length(); i++) {
        if (!isalpha(user_text[i]) && !isspace(user_text[i])) {
            cout << "Invalid statement. Please enter another statement (contains only a to z)" << endl;
            is_valid = false;
            break;
        }
    }
}

void valid_number_Affine_Cipher(string number, bool& is_valid) {
    is_valid = true;
    for (int i = 0; i < number.length(); i++) {
        if (!isdigit(number[i])) {
            cout << "Please enter a valid number" << endl;
            is_valid = false;
            break;
        }
    }
}


void encrypt_Affine_Cipher(string statement, int factor, int sub_add) {
    string cipher_txt;
    // iterate through each character in the plaintext
    for (int i = 0; i < statement.length(); i++) {
        // if the character is an alphabet
        if (isalpha(statement[i])) {
            // get the index of the character in the alphabet
            int ind = (int) toupper(statement[i]) - 65;

            // perform the encryption operation
            int enc = ((factor * ind) + sub_add) % 26;

            // append the encrypted character to the ciphertext
            cipher_txt += char(enc + 65);

        }
            // if the character is not an alphabet
        else {
            // append the character to the ciphertext as it is
            cipher_txt += statement[i];
        }
    }

    // print the ciphertext
    cout << cipher_txt << endl;
}

void decrypt_Affine_Cipher(string statement, int sub_add, int coefficient) {
    string decipher_txt;
    // iterate through each character in the ciphertext
    for (int i = 0; i < statement.length(); i++) {
        // if the character is an alphabet
        if (isalpha(statement[i])) {
            // get the index of the character in the alphabet
            int ind = (int) toupper(statement[i]) - 65;

            // perform the decryption operation
            int dec = (ind - sub_add) * coefficient % 26;

            // if the decrypted index is negative
            if (dec < 0){
                // convert it to positive and subtract 26 from it
                dec = (abs(dec) % 26) - 26;

                // append the deciphered character
                decipher_txt += char(abs(dec) + 65);
            }
            // if decrypted index is greater than or equal 0
            else {
                dec %= 26;

                // append the deciphered character
                decipher_txt += char(dec + 65);
            }


        }
            // if the character is not an alphabet
        else {
            decipher_txt += statement[i];
        }
    }

    // print the decipher text
    cout << decipher_txt << endl;
}

int main() {
    // variables to store the values of factor, sub_add, and coefficient
    string x, y, z;
    int factor, sub_add, coefficient;

    // welcome message
    cout << "welcome to Affine Cipher" << endl;

    // variables to store the plaintext and ciphertext
    string statement;

    // infinite loop to perform encryption or decryption until the user chooses to exit
    while (true) {
        string choice;
        cout << "1) encryption" << endl << "2) decryption" << endl << "3) Exit" << endl;
        cin >> choice;

        // if the user chooses to encrypt the plaintext
        if (choice == "1") {
            // Ignore the newline character in the input buffer
            cin.ignore();
            // get the plaintext from the user
            cout << "enter your statement \n";
            getline(cin, statement);

            // check valid statement
            bool is_valid_statement = true;
            check_valid_Affine_Cipher(statement, is_valid_statement);
            if (!is_valid_statement) {
                continue;
            }


            // get the values of factor, sub_add, and coefficient from the user
            cout << "(factor * coefficient) reminder of 26 should be equal to 1 \n";
            cout << "Enter the value of factor: \n";
            cin >> x;
            valid_number_Affine_Cipher(x, is_valid_statement);
            if (!is_valid_statement) {
                continue;
            }
            else {
                factor = stoi(x);
            }
            cout << "Enter the value of sub_add: \n";
            cin >> y;
            valid_number_Affine_Cipher(y, is_valid_statement);
            if (!is_valid_statement) {
                continue;
            }
            else {
                sub_add = stoi(y);
            }
            cout << "Enter the value of coefficient: \n";
            cin >> z;
            valid_number_Affine_Cipher(z, is_valid_statement);
            if (!is_valid_statement) {
                continue;
            }
            else {
                coefficient = stoi(z);
            }

            if ((factor * coefficient) % 26 != 1){
                cout << "invalid, please enter a valid number for factor and coefficient \n";
                continue;
            }

            encrypt_Affine_Cipher(statement, factor, sub_add);
        } else if (choice == "2") {
            // ignore the newline character in the input buffer
            cin.ignore();

            // get the ciphertext from the user
            cout << "enter your statement \n";
            getline(cin, statement);

            // check valid statement
            bool is_valid_statement = true;
            check_valid_Affine_Cipher(statement, is_valid_statement);
            if (!is_valid_statement) {
                continue;
            }

            // get the values of factor, sub_add, and coefficient from the user
            cout << "(factor * coefficient) reminder of 26 should be equal to 1 \n";
            cout << "Enter the value of factor: \n";
            cin >> x;
            valid_number_Affine_Cipher(x, is_valid_statement);
            if (!is_valid_statement) {
                continue;
            }
            else {
                factor = stoi(x);
            }
            cout << "Enter the value of sub_add: \n";
            cin >> y;
            valid_number_Affine_Cipher(y, is_valid_statement);
            if (!is_valid_statement) {
                continue;
            }
            else {
                sub_add = stoi(y);
            }
            cout << "Enter the value of coefficient: \n";
            cin >> z;
            valid_number_Affine_Cipher(z, is_valid_statement);
            if (!is_valid_statement) {
                continue;
            }
            else {
                coefficient = stoi(z);
            }

            if ((factor * coefficient) % 26 != 1){
                cout << "invalid, please enter a valid number for factor and coefficient \n";
                continue;
            }

            decrypt_Affine_Cipher(statement, sub_add, coefficient);
        }
            // if the user choose to exit the program
        else if (choice == "3") {
            cout << "exiting...";
            // stop the program
            break;
        }
            // if the user entered an invalid choice
        else {
            // print an error message
            cout << "enter a valid choice \n";
        }
    }
    return 0;
}