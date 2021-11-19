#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../HTMLFile.h"

TEST_CASE("Check getTitle()")
{
    HTMLFile file; 
    file.openFile("./Sherlock-Holmes-Selected-Stories/Silver Blaze.txt", "eng");
    REQUIRE(file.getTitle() == "Silver Blaze");
}

