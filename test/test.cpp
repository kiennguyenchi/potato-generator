#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../HTMLFile.h"

TEST_CASE("Check empty files")
{
    HTMLFile file;
    REQUIRE(file.getURL() == "");
}

TEST_CASE("Check existing files")
{
    HTMLFile file;
    file.openFile("../Sherlock-Holmes-Selected-Stories/Silver Blaze.txt", "fr");
    REQUIRE(file.getTextFile().size() == 0 );
}

TEST_CASE("Check non-existing files")
{
    HTMLFile file;
    file.openFile("../Sherlock-Holmes-Selected-Stories/notafile.txt", "fr");
    REQUIRE(file.getURL() == "");
}
