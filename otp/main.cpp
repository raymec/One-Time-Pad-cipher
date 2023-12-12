
#include <iostream>
#include <string>
#include <vector>

std::string OTP_encrypt(std::string& str, std::vector<int>& keys) {

    std::string cipher_txt;
    for (int i = 0; i < str.length(); i++) {
        if (isalnum(str[i])) {

            cipher_txt += (((toupper(str[i])) - 65 + keys[i]) % 26 + 65);
        }
        else {
            cipher_txt += str[i];
        }
    }
    return cipher_txt;
}

std::string OTP_decrypt(std::string& str, std::vector<int>& keys) {

    std::string plain_txt;
    for (int i = 0; i < str.length(); i++) {
        if (isalnum(str[i])) {

            // keys can reach very high numbers so we want to % 26 first
            // to keep it in bounds between A-Z
            // additionally, subtracting can produce negative numbers
            // so add 26 to avoid negative numbers

            plain_txt += (((((toupper(str[i]) - 65) - (keys[i] % 26)) + 26) % 26) + 65);
        }
        else {
            plain_txt += str[i];
        }
    }
    return plain_txt;
}

int main()
{
    srand(unsigned(time(NULL)));

    std::vector<int> v;
    std::string text = "Halo Reach fell";

    for (int i = 0; i < text.size(); i++) {
        int key = (rand() % 100) + 1;
        v.push_back(key);
    }

    // key
    std::cout << "key: ";
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    std::string cipher_txt = OTP_encrypt(text, v);
    std::cout << "cipher text: " << cipher_txt << std::endl;

    std::string plain_txt = OTP_decrypt(cipher_txt, v);
    std::cout << "plain text: " << plain_txt << std::endl;
}


