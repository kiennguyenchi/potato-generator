#define CONFIG_CATCH_MAIN
#include "catch.hpp"

#include "../pgprogram.cpp"
TEST_CASE("No Arguments provided")
{
    char* list[1] = {"./pgprogram"};
    REQUIRE(checkArguments(1, list) == "Failed arguments provided");
}
TEST_CASE("Arguments Check")
{
    char* list[2] = {"./pgprogram", "-v"};
    char* list2[2] = {"./pgprogram", "--version"};
    char* list3[2] = {"./pgprogram", "-h"};
    char* list4[2] = {"./pgprogram", "--help"};

    char* list5[3] = {"./pgprogram", "-i", "hello.txt"};
    char* list6[3] = {"./pgprogram", "--input", "hello.txt"};
    char* list7[3] = {"./pgprogram", "-c", "hello.json"}; 
    char* list8[3] = {"./pgprogram", "--config", "hello.json"}; 

    REQUIRE(checkArguments(2, list) == "Potato Generator - Version 0.1");
    REQUIRE(checkArguments(2, list2) == "Potato Generator - Version 0.1");
    REQUIRE(checkArguments(2, list3) == "*Run the program with command: ./pgprogram inputName\nThe inputName is a text file name or a folder name\n*To include a input file/folder, include --input or -i before the file/folder name in the arguments.\n*To specify an config file, use --config or -c before the config filename.\n*To see the version of the program, include --version or -v in the arguments.\n*To need help, include --help or -h in the arguments.\n");
    REQUIRE(checkArguments(2, list4) == "*Run the program with command: ./pgprogram inputName\nThe inputName is a text file name or a folder name\n*To include a input file/folder, include --input or -i before the file/folder name in the arguments.\n*To specify an config file, use --config or -c before the config filename.\n*To see the version of the program, include --version or -v in the arguments.\n*To need help, include --help or -h in the arguments.\n");
    REQUIRE(checkArguments(3, list5) == "hello.txt");
    REQUIRE(checkArguments(3, list6) == "hello.txt");
    REQUIRE(checkArguments(3, list7) == "hello.json");
    REQUIRE(checkArguments(3, list8) == "hello.json");
}

TEST_CASE("Language Arguments Check")
{
    char* list[3] = {"./pgprogram", "-l", "fr"};
    char* list2[3] = {"./pgprogram", "--language", "fr"};
    REQUIRE(checkLanguage(3, list) == "fr");
    REQUIRE(checkArguments(3, list2) == "fr");
}

TEST_CASE("Config files check")
{
    char* list[3] = {"./pgprogram", "-c", "hello.json"};
    char* list2[3] = {"./pgprogram", "--config", "hello.json"}; 
    char* list3[3] = {"./pgprogram", "-c", "hello.txt"}; 
    char* list4[3] = {"./pgprogram", "--config", "hello.txt"}; 
    
    REQUIRE(checkIfConfig(3, list) == true);
    REQUIRE(checkIfConfig(3, list2) == true);
    REQUIRE(checkIfConfig(3, list3) == false);
    REQUIRE(checkIfConfig(3, list4) == false);
}

TEST_CASE("Get language arguments")
{
    char* list[3] = {"./pgprogram", "-l", "fr"};
    char* list2[3] = {"./pgprogram", "--language", "fr"};
    REQUIRE(getLangArgument(3, list) == "fr");
    REQUIRE(getLangArgument(3, list2) == "fr");
}

TEST_CASE("Get output arguments")
{
    char* list[3] = {"./pgprogram", "-o", "lib"};
    char* list2[3] = {"./pgprogram", "--output", "lib"}; 
    REQUIRE(getOutputArgument(3, list) == "lib");
    REQUIRE(getOutputArgument(3, list2) == "lib");
}