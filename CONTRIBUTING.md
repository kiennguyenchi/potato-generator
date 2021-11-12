System Requirements
===================

*   C++17 Compiler (Visual Studio Code)
*   MINGW (Optional)

How To Run
==========

### Compiling

g++ pgprogram.cpp HTMLFile.h HTMLFile.cpp MainPage.h MainPage.cpp -o pgprogram --std=c++17

### Without specified arguments

On CMD, enter command **pgprogram _fname_**. (Where fname is the name of a file/folder)

### With specified arguments:

<table>
    <tr>
        <td>Option 1</td>
        <td>Option 2</td>
        <td>Functionality</td>
    </tr>
    <tr>
        <td>--input</td>
        <td>-i</td>
        <td>Specify input argument with file/folder name</td>
    </tr>
    <tr>
        <td>--help</td>
        <td>-h</td>
        <td>See the instructions how to run program</td>
    </tr>
    <tr>
        <td>--version</td>
        <td>-v</td>
        <td>See the updated version of the program</td>
    </tr>
</table>

### Format the code

*   Install clang-format
```
npm install clang-format
```
*   Create .clang-format file
```
clang-format.exe -style=llvm -dump-config > .clang-format
```
*   Download [Clang Format Editor](https://clangpowertools.com/CHANGELOG.html) to test custom format.
*   Run the editor on the whole project with style WebKit
```
clang-format -i -style=WebKit *.cpp *.h
```

*   clang-format on VS Code

	*   Install clang-format extension
	*	Shift+Alt+F to format your current file

### Check the code usability

*   Install linter [clang-tidy](https://blog.wholetomato.com/2021/01/08/a-brief-introduction-to-clang-tidy-and-its-role-in-visual-assist/)
*   Run the tool 
```
clang-tidy --checks='modernize*, readability*' filename.cpp -- -std=c++17
```
*   Fix the error
*   clang-tidy on VS Code

	*   Install clang-tidy extension
	*   It will read through your file and show errors/warnings

### Testing

*   Download *catch.hpp* from [Catch2 Repo](https://github.com/catchorg/Catch2) (already in test folder)
*   Add *test#.cpp* file (# represents for number accordingly)
*   Execute *g++ ./test/test#.cpp -o test# --std=c++17*
*   See the results in the Output
