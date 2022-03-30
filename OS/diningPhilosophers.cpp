// dining philosophers problem
// suppose there are 5 philosophers and one source of unlimited food which only one philosopher can eat at a time
// to eat, a philosopher needs 2 forks neccessarily but there are only five forks
// This is a resouce allocation and memory access problem.

// solved using semaphores
// each fork is a semaphore
// deadlock can occur in this solution. See the gate Smasher video
// We must use some methods to avoid Deadlock and make the solution work
    //  a. Allow at most 4 ph. To be sitting simultaneously.
    //  b. Allow a ph. To pick up his fork only if both forks are available and to do this, he must
    //  pick them up in a critical section (atomically).
    //  c. Odd-even rule.
    //  an odd ph. Picks up first his left fork and then his right fork, whereas an even ph. Picks
    //  up his right fork then his left fork.
