# C-HESS

### What is C-HESS?
C-HESS is a terminal application with a pseudo-GUI that allows you to play chess alone and online via tcp/ip socket communication.

### How to install and run C-HESS:

To install and run C-HESS, first download the code in the repo by clicking the green button "code" and then the button "download zip".

![code button location](/images/img1.png)
![download button location](/images/img2.png)

Once the source code is downloaded, before running the application, make sure the gcc compiler is installed on your computer (if you're on a UNIX-based system you most likely won't have to worry about it).
Assuming now that the latter hypothesis is satisfied, let's see how to actually run the application.

#### Run single player C-HESS:

In order to run single player C-HESS, whilst in the terminal, move to the directory /code inside the downloaded source code.
Once you're there, run the following command
```
make
```
If the command doesn't work (i.e if makefile doesn't work on the target computer for some reason), then just copy the following line to compile the program into an executable (yes it's pretty long).
```
gcc bishop.c chess.c movePieces.c printBoard.c tower.c calculateMoves.c methods.c king.c queen.c checkmate.c knight.c pawn.c printMenu.c -o chess
```
You should now have a binary compiled version of the program in your directory, regardless of the approach you took for the last step. If that is the case, then just type

gcc bishop.c chess.c movePieces.c printBoard.c tower.c calculateMoves.c methods.c king.c queen.c checkmate.c knight.c pawn.c printMenu.c -o organized
```
./chess
```
in the terminal and you should be ready to go. You should now see the application main menu in the terminal
