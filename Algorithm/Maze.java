import java.util.Scanner;

public class Maze {
    static void printMaze(String maze[][]) { // function to print the maze
        for (int r = 0; r < maze.length; r++) { // iterate through rows
            for (int c = 0; c < maze[r].length; c++) { // iterate through columns
                System.out.print(maze[r][c] + "."); // print character on [row][column]
            }
            System.out.println(); // new line at end of maze
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in); // Scanner class to take inputs
        int indexOfO[] = { 0, 0 }; // to keep track of  index of 'O' which is moving thoughout the game, 2 values in array row index and column index
        String maze[][] = { // predefined maze
            { "_", "X", "_", "X", "X" },
            { "_", "X", "_", "X", "W" },
            { "_", "_", "_", "X", "_" },
            { "X", "X", "_", "_", "_" },
            { "_", "_", "_", "X", "X" }
        };
        System.out.println("[Maze Game]");
        maze[0][0] = "O"; // set the initial position of O as [0][0]
        printMaze(maze); // printing maze
        while (maze[1][4] != "O") { // the win is at [1][4], play game until you reach that or hit a wall
            System.out.print("Which direction do you want to move? ");
            String direction = sc.nextLine(); // input direction
            if (direction.equalsIgnoreCase("Up")) { // if direct is up
                if (indexOfO[0] == 0) { // checking for out of bounds
                    System.out.print("You can't move there - it's out of bounds!\n");
                    printMaze(maze);
                    continue; // if input position is out of bounds go to start of loop
                } else {
                    if (maze[indexOfO[0] - 1][indexOfO[1]].equalsIgnoreCase("X")) {  // checking for wall
                        System.out.println("Up You hit a wall - Game Over!");
                        break; // if wall is found then break the loop
                    } else { // move O to one position up
                        maze[indexOfO[0]][indexOfO[1]] = "_"; // make previous position as _
                        maze[indexOfO[0] - 1][indexOfO[1]] = "O"; // make next position as O
                        indexOfO[0]--; // update track of O in indexOfO array,
                        printMaze(maze);
                    }
                }
            } else if (direction.equalsIgnoreCase("Down")) { // if direct is down
                if (indexOfO[0] == 4) { // checking for out of bounds
                    System.out.print("You can't move there - it's out of bounds!\n");
                    printMaze(maze);
                    continue; // if input position is out of bounds go to start of loop
                } else {
                    if (maze[indexOfO[0] + 1][indexOfO[1]].equalsIgnoreCase("X")) { // checking for wall
                        System.out.println("Down You hit a wall - Game Over!");
                        break; // if wall is found then break the loop
                    } else { // move O to one position down
                        maze[indexOfO[0]][indexOfO[1]] = "_"; // make previous position as _
                        maze[indexOfO[0] + 1][indexOfO[1]] = "O"; // make next position as O
                        indexOfO[0]++; // update track of O in indexOfO array,
                        printMaze(maze);
                    }
                }
            } else if (direction.equalsIgnoreCase("Right")) { // if direct is right
                if (indexOfO[1] == 4) { // checking for out of bounds
                    System.out.print("You can't move there - it's out of bounds!\n");
                    printMaze(maze);
                    continue; // if input position is out of bounds go to start of loop
                } else {
                    if (maze[indexOfO[0]][indexOfO[1] + 1].equalsIgnoreCase("X")) { // checking for wall
                        System.out.println("Right You hit a wall - Game Over!");
                        break; // if wall is found then break the loop
                    } else { // move O to one position right
                        maze[indexOfO[0]][indexOfO[1]] = "_"; // make previous position as _
                        maze[indexOfO[0]][indexOfO[1] + 1] = "O"; // make next position as O
                        indexOfO[1]++; // update track of O in indexOfO array,
                        printMaze(maze);
                    }
                }
            } else if (direction.equalsIgnoreCase("Left")) { // if direct is left
                if (indexOfO[1] == 0) { // checking for out of bounds
                    System.out.print("You can't move there - it's out of bounds!\n");
                    printMaze(maze);
                    continue; // if input position is out of bounds go to start of loop
                } else {
                    if (maze[indexOfO[0]][indexOfO[1] - 1].equalsIgnoreCase("X")) { // checking for wall
                        System.out.println("Left You hit a wall - Game Over!");
                        break; // if wall is found then break the loop
                    } else { // move O to one position left
                        maze[indexOfO[0]][indexOfO[1]] = "_"; // make previous position as _
                        maze[indexOfO[0]][indexOfO[1] - 1] = "O"; // make next position as O
                        indexOfO[1]--; // update track of O in indexOfO array,
                        printMaze(maze);
                    }
                }
            } else { // if invalid direct is inputed
                System.out.println(direction + " That's not a valid direction!");
            }
            if (maze[1][4] == "O") { // check if you won
                System.out.println("\nYou win!");
            }
        }
        sc.close();
    }
}