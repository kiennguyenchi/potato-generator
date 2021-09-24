Potato Generator
================

This is a C++ Static Site Generator (SSG) tool.

Author
======

Chi Kien Nguyen

Features
========

*   With a folder input, the tool creates a main HTML page containing links to each site.
*   With a text file input, the tool creates a single HTML page.
*   The tool generates h1 tag for title of each site.
*   The tool uses stylesheet for better format on websites.
*   The tool also supports to convert Markdown file.

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

Examples
========

### Run the program with --help, -h, --version and -v

![](./images/Command(1).JPG)

### Run the program with --input, -i, and no arguments

![](./images/Command(2).JPG)

Generated Websites
==================

[Websites](https://gifted-brattain-2278d4.netlify.app/sherlock-holmes-selected-stories/sherlock-holmes-selected-stories)

License
=======

[MIT License](https://opensource.org/licenses/MIT)
