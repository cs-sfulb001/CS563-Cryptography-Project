#include <fstream>
#include <sys/stat.h>
#include <bitset>
#include <iostream>
#include "tools/StringManip.h"
#include "Encryptions.h"
#include <random>
#include <unordered_map>
#include <iomanip>

/*
Returns phi(factor1*factor2)
*/
int phi(int factor1, int factor2){
    return (factor1-1)*(factor2-1);
}
/*
Grabs a random prime number between 1 and 300
*/
int generatePrime(){
    int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
    int random = rand() % 62;
    return primes[random];
}
/*
Calculates the multiplicative inverse of a in group mod
*/
int multiplicative_inverse(int a, int mod){
    for(int i=1;i<mod;i++){
        if(a*i%mod==1)
            return i;
    }
}
/*
Calculates base^exponet % mod
*/
int powMod(int base, int exponent, int mod){
    std::cout<<"Base: "<<base<<std::endl;
    std::cout<<"Exponent: "<<exponent<<std::endl;
    std::cout<<"mod: "<<mod<<std::endl;
    long int total=1;
    for(long i=0; i < exponent; ++i) {
        total *= base;
        if(total > mod)
            total %= mod;
    }
    std::cout<<"Total: "<<total<<std::endl;
    return total;
}
/*
Generates the keys needed for RSA Encryption
*/
std::pair<std::pair<int, int>,std::pair<int, int>> GenerateKeys(){
    int p, q;
    p = generatePrime();
    q = generatePrime();
    int n = p*q;
    int phiN = phi(p, q);
    int e = generatePrime();
    int d = multiplicative_inverse(e, phiN);
    std::pair<int, int> publicKey=std::pair<int, int>(e, n);
    std::pair<int, int> privateKey=std::pair<int, int>(d, n);
    return std::pair<std::pair<int, int>,std::pair<int, int>>(publicKey, privateKey);
}
/*
Using the RSA method, encrypts the file at the provided path
*/
void RSAEncrypt(std::string filePath){
    srand(time(0));
    std::pair<std::pair<int, int>,std::pair<int, int>> keys;
    keys = GenerateKeys();
    std::ofstream publicKey;
    publicKey.open("Keys/"+fileNameFromPath(filePath));
    publicKey<<keys.first.first<<" "<<keys.first.second;
    publicKey.close();
    std::ifstream file;
    file.open(filePath);
    std::string line;
    std::string Hex;
    int blockLength=0;
    int temp = keys.second.second;
    while(temp>0){
        temp= temp/16;
        blockLength++;
    }
    while(std::getline(file, line)){
        line+="\n";
       Hex+=line;
    }
    file.close();
    std::pair<int, int> privateKey = keys.second;
    std::ofstream encryptedFile;
    encryptedFile.open("Encrypted/"+fileNameFromPath(filePath));
    for(int block=0;block<=Hex.size();block++){
        std::stringstream ss;
        int value = Hex[block];
        long long int encrypted = powMod(value, privateKey.first, privateKey.second);
        ss << std::hex << std::uppercase << encrypted;
        std::string HexValue = ss.str();
        encryptedFile << std::setw(blockLength) << std::setfill('0')<< HexValue;
    }
    encryptedFile.close();
    std::cout<<"Encrypted file avalible at /Encrypted/"<<fileNameFromPath(filePath)<<std::endl;
}
/*
Using the RSA method, Decrypts the encrypted file at the given path
*/
void RSADecrypt(std::string filepath){
    std::ifstream key;
    key.open("Keys/"+fileNameFromPath(filepath));
    std::string line;
    std::getline(key, line);
    key.close();
    std::vector<std::string> stringKey = SplitStringBySpaceOnly(line);
    std::pair<int, int> publicKey;
    publicKey.first = StringtoInt(stringKey[0]);
    publicKey.second = StringtoInt(stringKey[1]);
    std::ifstream encrypted;
    encrypted.open(filepath);
    std::getline(encrypted, line);
    encrypted.close();
    int blockLength=0;
    int temp = publicKey.second;
    std::string Hex = line;
    while(temp>0){
        temp= temp/16;
        blockLength++;
    }
    std::string decryptedValue;
    std::cout<<Hex<<std::endl;
    for(int block=0;block<=Hex.size()/blockLength;block++){
        std::string subHex;
        if(blockLength<Hex.size()-block*blockLength){
            subHex = Hex.substr(block*blockLength, blockLength);
        }
        else{
            subHex = Hex.substr(block*blockLength, Hex.size()-blockLength*block);
        }
        std::stringstream ss;
        ss << std::hex << subHex;
        unsigned int value;
        ss >> value;
        long long int decrypted = powMod(value, publicKey.first, publicKey.second);
        ss << std::hex << std::uppercase << decrypted;
        std::string HexValue = ss.str();
        decryptedValue = decryptedValue + (char)decrypted;
    }
    std::cout<<decryptedValue<<std::endl;
    std::ofstream decryptedFile;
    decryptedFile.open("Decrypted/"+fileNameFromPath(filepath));
    decryptedFile.close();
    std::cout<<"Decrypted file avalible at /Decrypted/"<<fileNameFromPath(filepath)<<std::endl;
}

