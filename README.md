# PJTerm
![Fastfetch](https://github.com/user-attachments/assets/cf09e7ff-1e64-4fa4-b468-3958fab379c6)
This is a terminal that I built using a guide by DonnieWest of Code Koalas which can be found here: https://codekoalas.com/blog/build-your-own-minimal-terminal
Full credit goes to him.

I made this to learn how the Qt library works.

## Installation
This program only works with Linux and has not been tested on MacOS X

1. Clone the repository with `git clone https://github.com/PJTerm`
2. Go into the root directory with `cd PJTerm`
3. Run the build script using `./build.sh`
4. Now you can run the program PJTerm by clicking on the binary file in a file manager or by running `./PJTerm` in another terminal

## Usage
As of now, the desktop doesn't recognize the terminal. For some reason, even putting it in `/usr/local/bin` did nothing, so we have to use `./PJTerm` in the directory where it was installed instead

You can change certain aspects of the terminal like the colorschemes by manually changing it in settings.h and then recompiling.

## Credits
DonnieWest's article on Code Koalas https://codekoalas.com/blog/build-your-own-minimal-terminal
