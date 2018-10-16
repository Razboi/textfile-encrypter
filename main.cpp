#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

void sum_password(std::string password, int *password_sum) {
	*password_sum = 0;
	for (unsigned int i = 0; i < password.size(); i++) {
		*password_sum += (int)password[i];
	}
}

int encrypt(const char *filename) {
	char c;
	std::string password;
	int password_sum = 0;

	std::ifstream file;
	std::ofstream enc_file;
	file.open(filename);
	enc_file.open("enc_tmp.txt");

	std::cout << "Password:\n";
	std::cin >> password;
	sum_password(password, &password_sum);
// Loop through the password using each letter to encrypt the file characters
	for (int i = 0, j = 0; file.get(c); i++, j++) {
		if (j > (int)password.size()) {
			j = 0;
		}
		int encrypted_char = c + password[j] + password_sum;
		enc_file << (char)encrypted_char;
	}
	file.close();
	enc_file.close();
	rename("enc_tmp.txt", filename);
	std::cout << "***Encryption complete***\n";
	return 0;
}

int decrypt(const char *filename) {
	char c;
	std::string password;
	int password_sum = 0;

	std::ifstream file;
	std::ofstream dec_file;
	file.open(filename);
	dec_file.open("dec_tmp.txt");

	std::cout << "Password:\n";
	std::cin >> password;
	sum_password(password, &password_sum);
// Loop through the password using each letter to decrypt the file characters
	for (int i = 0, j = 0; file.get(c); i++, j++) {
		if (j > (int)password.size()) {
			j = 0;
		}
		int decrypted_char = c - password[j] - password_sum;
		dec_file << (char)decrypted_char;
	}
	file.close();
	dec_file.close();
	rename("dec_tmp.txt", filename);
	std::cout << "***Decryption complete***\n";
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		std::cout << "Invalid usage. Use: -option filename\n";
		return 0;
	}
	if ((std::string)argv[1] == "-e") {
		encrypt(argv[2]);
	} else if ((std::string)argv[1] == "-d") {
		decrypt(argv[2]);
	}
}
