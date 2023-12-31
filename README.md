# C-HESS

### What is C-HESS?
C-HESS is a terminal application with a pseudo-GUI that allows you to play chess alone and online via tcp/ip socket communication.

![game preview](/images/game2.png)

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
gcc bishop.c chess.c movePieces.c printBoard.c tower.c calculateMoves.c methods.c king.c queen.c checkmate.c knight.c pawn.c printMenu.c moveCounters.c -o chess
```
You should now have a binary compiled version of the program in your directory, regardless of the approach you took for the last step. If that is the case, then just type

```
./chess
```
in the terminal and you should be ready to go. You should now see the application main menu in the terminal

![Menu page](/images/menu.png)

### Run multiplayer C-HESS:

The process for compiling the source code of the multiplayer version of the game is very similar, however when it comes to running it some things will change. We start again by moving inside the directory "onlineChess". Here we will then run
```
make
```
as before. This time, however, make will compile the source code into two different executables, one named "client" and one named "server". Again, if makefile doesn't work, you can copy-paste the following two lines in the terminal to compile the two executables:
```
gcc bishop.c methods.c server3.c movePieces.c printBoard.c tower.c calculateMoves.c king.c queen.c checkmate.c knight.c pawn.c printMenu.c -o server
```
```
gcc bishop.c methods.c client3.c movePieces.c printBoard.c tower.c calculateMoves.c king.c queen.c checkmate.c knight.c pawn.c printMenu.c -o client
```
As the names suggest, the server will have to run the server binary file and the client will have to run the client one. In particular, the server needs to run the server executable and specify the port on which will listen for connections:

```
./server "port number"
```
While the client will have to run the client executable and specify the IP address of the machine where the server process holds, alongside with the port on which said machine is listening

```
./client "ip address" "port number"
```
You are now ready to play online chess in your terminal via TCP/IP socket, enjoy!
![game preview](/images/gamepreview.gif)

### How to move pieces:
As of now, only the following positional convention is supported: any piece on the board is represented by an ordered couple of positive integers [row,column]:
both of them range between 0 and 7. In order to move a piece from a point to another, we use the following syntax:
```
xy x'y'
```
where x is the initial row, y is the inital column, x' is the ending row and y' is the ending column. 
Let's make an example: suppose we have the board
```
			 	 |♜ ||♞ ||♝ ||♛ ||♚ ||♝ ||♞ ||♜ |
			 	 |♟ ︎||♟ ︎||♟ ︎||♟ ︎||♟ ︎||♟ ︎||♟ ︎||♟ ︎|
			 	 |  ||  ||  ||  ||  ||  ||  ||  |
			 	 |  ||  ||  ||  ||  ||  ||  ||  |
			 	 |  ||  ||  ||  ||  ||  ||  ||  |
			 	 |  ||  ||  ||  ||  ||  ||  ||  |
			 	 |♙ ||♙ ||♙ ||♙ ||♙ ||♙ ||♙ ||♙ |
			 	 |♖ ||♘ ||♗ ||♕ ||♔ ||♗ ||♘ ||♖ |
```
and we want to move the 4th black pawn 2 units forwards. As we said earlier, the pawn is univocally determined by a couplet [row,column]. In this case row = 6 because our pawn is a distance of 6 blocks away from the top corner of the board, and the column = 3 because the pawn is at a distance of 3 units from the left corner of the board. To move our piece we will then use the command
```
63 43
```
The result of this move will be
```
			 	 |♜ ||♞ ||♝ ||♛ ||♚ ||♝ ||♞ ||♜ |
			 	 |♟ ︎||♟ ︎||♟ ︎||♟ ︎||♟ ︎||♟ ︎||♟ ︎||♟ ︎|
			 	 |  ||  ||  ||  ||  ||  ||  ||  |
			 	 |  ||  ||  ||  ||  ||  ||  ||  |
			 	 |  ||  ||  ||♙ ||  ||  ||  ||  |
			 	 |  ||  ||  ||  ||  ||  ||  ||  |
			 	 |♙ ||♙ ||♙ ||  ||♙ ||♙ ||♙ ||♙ |
			 	 |♖ ||♘ ||♗ ||♕ ||♔ ||♗ ||♘ ||♖ |
```


## License

[MIT](LICENSE)

## Code of conduct 
[Code of conduct](CODE_OF_CONDUCT.md)
