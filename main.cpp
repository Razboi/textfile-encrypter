#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

void encrypt(const char *  filename) {
	char c;
	char *password = new char[101];
	std::ifstream file;
	std::ofstream enc_file;
	file.open(filename);
	enc_file.open("enc_tmp.txt");
	std::cout << "Password:\n";
	std::cin >> password;
	for (int i = 0, j = 0; file.get(c); i++, j++) {
		if (j > (int)strlen(password) - 1) {
			j = 0;
		}
		int encrypted_char = c + password[j];
		//std::cout << c << "-->" << encrypted_char << "\n";
		enc_file << (char)encrypted_char;
	}
	file.close();
	enc_file.close();
	rename("enc_tmp.txt", filename);
	std::cout << "***Encryption complete***\n";
}

void decrypt(const char * filename) {
	char c;
	char *password = new char[101];
	std::ifstream file;
	std::ofstream dec_file;
	file.open(filename);
	dec_file.open("dec_tmp.txt");
	std::cout << "Password:\n";
	std::cin >> password;
	for (int i = 0, j = 0; file.get(c); i++, j++) {
		if (j > (int)strlen(password) - 1) {
			j = 0;
		}
		int decrypted_char = c - password[j];
		//std::cout << c << "-->" << decrypted_char << "\n";
		dec_file << (char)decrypted_char;
	}
	file.close();
	dec_file.close();
	rename("dec_tmp.txt", filename);
	std::cout << "***Decryption complete***\n";
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