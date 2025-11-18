#include "tools/Choices.h"
#include "Tools/StringManip.h"
#include <iostream>
#include <filesystem>
#include "Encryptions.h"

int main(int argc, char* argv[]){
    if(argc < 3){
        std::cout<<"Too few arguments for a command line call"<<std::endl;
        std::cout<<"Input no aruments for a command line interface or use the command line call as such: \"Program encrypt/decrypt (path of File/Dir)"<<std::endl;
    }
    if(argc>=3){
        std::string mode(argv[1]);
        stringFormatCapitalized(mode);
        std::string filePath(argv[2]);
        if(mode=="Encrypt"){
            RSAEncrypt(filePath);
        }
        else if(mode=="Decrypt"){
            RSADecrypt(filePath);
        }
    }
}
