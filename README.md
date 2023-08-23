# Deadlock Handler

This repository contains a C++ implementation of the Banker's algorithm, which is used to avoid deadlock in a system. The program allows processes to request and release resources, and the banker will grant a request only if it leaves the system in a safe state. If a request would lead to an unsafe state, it will be denied. The program also includes a test program to validate the code, which takes the initial number of available resources, the maximum need, and the actually allocated resources for each process.

The main features of the project are:
- It uses four data structures to keep track of the resources: available, maximum, allocation, and need.
- It reads the initial values of these data structures from text files.
- It calculates the need matrix and the new available vector based on the input values.
- It checks if the system is in a safe state using a safety algorithm.
- It allows the user to enter requests and releases of resources by processes and updates the data structures accordingly.
- It handles deadlock situations by applying a recovery algorithm that chooses a victim process and forces it to release resources until the system reaches a safe state.

## How to run the project

To run the project, you need to have a C++ compiler installed on your system. You can use any IDE or command-line tool to compile and run the project. The main file of the project is `main.cpp`, which includes the header file `Banker.h` that contains the class definition and declaration of the Banker class. The Banker class has methods for reading input from files, calculating need matrix, checking safe state, handling requests and releases, and displaying data structures.

The input files are located in the `files` folder and have the following names and formats:

- `allocate.txt`: This file contains the allocation matrix, which shows the amount of each resource currently allocated to each process. Each row represents a process and each column represents a resource. The values are separated by spaces. For example:

  ```
  0 1 0
  2 0 0
  3 0 2
  2 1 1
  0 0 2
  ```

This means that there are five processes (P0, P1, P2, P3, P4) and three resources (R1, R2, R3) in the system. Process P0 has one unit of R2 allocated, process P1 has two units of R1 allocated, and so on.

- `max.txt`: This file contains the maximum matrix, which shows the maximum demand of each resource by each process. The format is similar to `allocate.txt`. For example:

  ```
  50 5 3
  3 2 2
  9 0 2
  2 2 2
  4 3 3
  ```

This means that process P0 can request up to 50 units of R1, five units of R2, and three units of R3 in total. Process P1 can request up to three units of each resource in total, and so on.

- `available.txt`: This file contains the available vector, which shows the number of available units of each resource in the system. The values are separated by spaces. For example:

  ```
  3 3 2
  ```

This means that there are three units of R1, three units of R2, and two units of R3 available in the system.

To run the project, you need to make sure that these files are in the same folder as `main.cpp` and `Banker.h`. You can also modify these files to change the input values for testing purposes.

After compiling and running the project, you will see an output screen that shows the initial state of the system and asks you to enter a command. You can enter one of the following commands:

- `RQ <process#> <r1> <r2> <r3>`: This means that a process requests resources. You need to specify the process number (starting from zero) and the number of units of each resource requested (separated by spaces). For example:

  ```
  RQ 0 1 0 0
  ```

This means that process P0 requests one unit of R1 and no units of R2 and R3. The program will add this request to the need matrix for P0 and check if granting this request will leave the system in a safe state. If yes, then the program will update the allocation matrix and the available vector accordingly and display them on the screen. If no, then the program will deny this request and display a message saying that it is unsafe.

- `RL <process#> <r1> <r2> <r3>`: This means that a process releases resources. You need to specify the process number (starting from zero) and the number of units of each resource released (separated by spaces). For example:

  ```
  RL 1 2 0 0
  ```

This means that process P1 releases two units of R1 and no units of R2 and R3. The program will check if the release resources are less than or equal to the allocated resources for P1 and if so, then the program will subtract this release from the allocation matrix and the need matrix for P1 and update the available vector accordingly and display them on the screen. If not, then the program will display a message saying that the release is invalid.

- `Recover`: This means that the program will try to recover from a deadlock situation. The program will apply a recovery algorithm that chooses a victim process based on some criteria (such as priority, how much longer to complete, resources used, resources needed, etc.) and forces it to release all its allocated resources. The program will then check if the system is in a safe state after this release. If yes, then the program will display the updated data structures on the screen. If no, then the program will choose another victim process and repeat the same procedure until the system reaches a safe state or there are no more processes left. The program will also display the chosen victim processes and the reasons for choosing them on the screen.

- `Quit`: This means that you want to exit the program. The program will close the application and terminate.

## Example output

Here is an example output of running the project with the given input files:

```
Enter Number of Processes : 5
Enter Number of Resources : 3
Available Vector
3 3 2
Allocation Matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Maximum Matrix
50 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Need Matrix
50 4 3
1 2 2
6 0 0
0 1 1
4 3 1

Safe Staaaaaaaaaaaaaaaaaaaaaaaaaaaaate
```

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the GitHub repository.

## Acknowledgment

The project is inspired by the concepts of disk scheduling algorithms in advanced operating systems course in my faculty.


## License

This program is licensed under the [MIT License](LICENSE.md).
