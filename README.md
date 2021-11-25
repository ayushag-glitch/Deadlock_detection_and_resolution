# Deadlock_detection_and_resolution

To run the file:
Go to terminal on the location of the folder and to compile, enter on the command prompt:
gcc main.c -lpthread -o ipc_demo
To execute, enter:
./ipc_demo [No. of Resources] [Instances of each resource] [Number of threads] [Deadlock check interval] [Heuristic number(either enter 1(for heuristic 1) or any other number(for the second heuristic))]

Heuristic 1:
Terminates all the threads in Deadlock

Heuristic 2:
Terminates the thread which is in deadlock, and has maximum number of allocated resources. The operation happens till the deadlock condition is not broken.

Command prompt output for heuristic 1:
    Input: ./ipc_demo 5 4 8 7 5 2 8 2 1
    SAMPLE 1:
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 1
        Time is: 0.
        The threads in deadlock are: 1 2 3 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 2
        Time is: 2.
        The threads in deadlock are: 1 2 3 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 3
        Time is: 4.
        The threads in deadlock are: 1 2 3 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled
        Worker thread 1 resources fulfilled
        Worker thread 1 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 4
        Time is: 6.
        The threads in deadlock are: 1 2 3 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 5
        Time is: 8.
        The threads in deadlock are: 1 2 3 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 6
        Time is: 10.
        The threads in deadlock are: 1 2 3 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 7
        Time is: 12.
        The threads in deadlock are: 1 2 3 4 7 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 8
        Time is: 14.
        The threads in deadlock are: 1 2 3 4 7 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 8
        Time is: 14.
        The threads in deadlock are: 1 2 3 4 7 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 1 resources fulfilled
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled
        Worker thread 6 resources fulfilled
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 
        Worker thread 6 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 9
        Time is: 16.
        The threads in deadlock are: 2 3 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 1 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 10
        Time is: 18.
        The threads in deadlock are: 2 3 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        No deadlock found at time 20
        No deadlock found at time 22
        No deadlock found at time 24
        No deadlock found at time 26
        No deadlock found at time 28
        ^C

    SAMPLE 2:
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        No deadlock found at time 0
        No deadlock found at time 2
        No deadlock found at time 4
        No deadlock found at time 6
        No deadlock found at time 8
        No deadlock found at time 10
        No deadlock found at time 12
        No deadlock found at time 14
        ^C

    SAMPLE 3:
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 1
        Time is: 0.
        The threads in deadlock are: 1 2 4 5 7 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 1 resources fulfilled
        Worker thread 1 moving to next
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 2
        Time is: 2.
        The threads in deadlock are: 1 2 4 5 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 3
        Time is: 4.
        The threads in deadlock are: 1 4 5 7 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 4 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 4
        Time is: 6.
        The threads in deadlock are: 1 4 5 7 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 2 resources fulfilled
        Worker thread 4 moving to next
        A worker thread is started/reinitiated 
        Worker thread 2 moving to next
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled
        No deadlock found at time 8
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 5
        Time is: 10.
        The threads in deadlock are: 2 4 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 6
        Time is: 12.
        The threads in deadlock are: 2 4 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 7
        Time is: 14.
        The threads in deadlock are: 2 4 
        Attempting to resolve by method 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        No deadlock found at time 16
        No deadlock found at time 18
        No deadlock found at time 20
        No deadlock found at time 22
        ^C




FOR Heuristic 2:
At times, the function is not able to eliminate the deadlock, please run repeated iterations.
SAMPLE 1:
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 3 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 1
        Time is: 0.
        The threads in deadlock are: 2 4 5 
        Attempting to resolve by method 2
        Thread eliminated 1
        Thread eliminated 3
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 3 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 2
        Time is: 2.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2
        Thread eliminated 5
        A worker thread is started/reinitiated 
        Worker thread 3 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 3
        Time is: 4.
        The threads in deadlock are: 1 2 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 2
        Thread eliminated 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 5 resources fulfilled
        Worker thread 7 resources fulfilled
        Worker thread 7 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 4
        Time is: 6.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2
        Thread eliminated 2
        Thread eliminated 3
        A worker thread is started/reinitiated 
        Thread eliminated 5
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 5 moving to next
        A worker thread is started/reinitiated 
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 5
        Time is: 8.
        The threads in deadlock are: 1 2 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 1
        Thread eliminated 5
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 6
        Time is: 10.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2

        A deadlock is found. Number of times deadlock detected: 7
        Time is: 12.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2

        A deadlock is found. Number of times deadlock detected: 8
        Time is: 14.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2
        Worker thread 7 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 9
        Time is: 16.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 10
        Time is: 18.
        The threads in deadlock are: 1 2 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 1
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 11
        Time is: 20.
        The threads in deadlock are: 1 2 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 1
        Thread eliminated 2
        A worker thread is started/reinitiated 
        Thread eliminated 3
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled
        Worker thread 2 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 12
        Time is: 22.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2
        Thread eliminated 7
        Thread eliminated 5
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 2 moving to next
        A worker thread is started/reinitiated 
        Worker thread 3 resources fulfilled
        Worker thread 7 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 13
        Time is: 24.
        The threads in deadlock are: 1 2 4 5 
        Attempting to resolve by method 2
        Thread eliminated 1
        Thread eliminated 3
        A worker thread is started/reinitiated 
        Thread eliminated 5
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 14
        Time is: 26.
        The threads in deadlock are: 1 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 2
        Thread eliminated 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 3 resources fulfilled
        Worker thread 2 resources fulfilled
        Worker thread 3 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 15
        Time is: 28.
        The threads in deadlock are: 1 2 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 5
        Thread eliminated 1
        A worker thread is started/reinitiated 
        Thread eliminated 7
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 2 moving to next
        A worker thread is started/reinitiated 
        Worker thread 5 resources fulfilled
        Worker thread 7 resources fulfilled
        Worker thread 5 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 16
        Time is: 30.
        The threads in deadlock are: 1 2 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 3
        Thread eliminated 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 17
        Time is: 32.
        The threads in deadlock are: 1 2 3 4 7 
        Attempting to resolve by method 2
        Thread eliminated 5
        Thread eliminated 1
        A worker thread is started/reinitiated 
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled
        Worker thread 2 resources fulfilled
        Worker thread 2 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 18
        Time is: 34.
        The threads in deadlock are: 1 2 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 5
        A worker thread is started/reinitiated 
        Worker thread 7 moving to next
        Worker thread 2 resources fulfilled
        A worker thread is started/reinitiated 
        Worker thread 2 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 19
        Time is: 36.
        The threads in deadlock are: 1 2 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 1
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 20
        Time is: 38.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2

        A deadlock is found. Number of times deadlock detected: 21
        Time is: 40.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2
        Thread eliminated 2
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 22
        Time is: 42.
        The threads in deadlock are: 1 2 3 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 1
        A worker thread is started/reinitiated 
        Thread eliminated 2
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled

        A deadlock is found. Number of times deadlock detected: 23
        Time is: 44.
        The threads in deadlock are: 1 2 3 4 5 
        Attempting to resolve by method 2
        Thread eliminated 2
        A worker thread is started/reinitiated 
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 
        Worker thread 2 resources fulfilled
        Worker thread 2 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 24
        Time is: 46.
        The threads in deadlock are: 1 2 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 1
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 25
        Time is: 48.
        The threads in deadlock are: 1 2 4 5 
        Attempting to resolve by method 2
        Thread eliminated 2
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 26
        Time is: 50.
        The threads in deadlock are: 2 4 5 
        Attempting to resolve by method 2
        Thread eliminated 1
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 

        A deadlock is found. Number of times deadlock detected: 27
        Time is: 52.
        The threads in deadlock are: 1 2 4 5 7 
        Attempting to resolve by method 2
        Thread eliminated 1
        A worker thread is started/reinitiated 
        Worker thread 7 resources fulfilled
        Worker thread 7 moving to next
        A worker thread is started/reinitiated 
        No deadlock found at time 54
        No deadlock found at time 56
        No deadlock found at time 58
        No deadlock found at time 60
        No deadlock found at time 62
        ^C
    
In other iterations of the second heuristic, it was found that generally, the second heuristic takes more time to eliminate deadlocks i.e., 
the deadlock elimination is somewhat fragile, and deadlocks repeat very often.
