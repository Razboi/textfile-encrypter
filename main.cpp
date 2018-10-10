#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

void encrypt(const char *  filename) {
	char c;
	std::ifstream file;
	std::ofstream enc_file;
	file.open(filename);
	enc_file.open("enc_tmp.txt");
	for (int i = 0; file.get(c); i++) {
		int encrypted_char = (int)c + 1;
		//std::cout << c << "-->" << (char)encrypted_char << "\n";
		enc_file << (char)encrypted_char;
	}
	file.close();
	enc_file.close();
	rename("enc_tmp.txt", filename);
	std::cout << "***Encryption complete***\n";
}

void decrypt(const char * filename) {
	char c;
	std::ifstream file;
	std::ofstream dec_file;
	file.open(filename);
	dec_file.open("dec_tmp.txt");
	for (int i = 0; file.get(c); i++) {
		int decrypted_char = (int)c - 1;
		//std::cout << c << "-->" << (char)decrypted_char << "\n";
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