*This project has been created as part of the 42 curriculum by grcharle*

# **Description**

The project consists of simulating a round table in which special *users*, called philosophers are given 3 simple tasks:
- To eat
- To sleep
- To think

These tasks are never to be done simultaniously.
And also, in order to eat, one must use **(2) two forks**, meaning that another philosopher will be forced to wait until the previous one, returns its assigned fork to the table.
This increases the probability that one philospher could **die** of starvation.
Likewise, if a **minimum number of feeding** is provided, then the program must stop once every single philosopher has hearched that goal.

> Example:
> **`./philo 1 800 100 100 3`**
> Philosopher **1** should die at *800 ms*

> Example:
> **`./philo 5 300 200 100 2`**
> Philosopher **4** should die at *300 ms*

> Example:
> **`./philo 4 300 200 100 10`**
> All philosopher should have eaten *10 times*

# **Instructions**

The programm takes the following arguments :
- <u>number of philosophers</u> : the number of philosophers and the number of forks.

- <u>time to die</u> **(in milliseconds)** : if a philosopher has not started eating within *time_to_die* milliseconds since the start of their last meal or the start of the simulation, he dies.

- <u>time to eat</u> **(in milliseconds)** : the time it takes for a philosopher to eat. During that time, they will need to hold two fork.

- <u>time to sleep</u> **(in milliseconds)** : the time a philosopher will spend sleeping.

- <u>number of times each philosopher must eat</u> (optional argument) : if all philosophers have eaten at least *number_of_times_each_philosopher_must_eat* times, the simulation stop. If no specified, the simulation stops when a philosopher dies.

# **Ressources**

- [(VIDEO) Introduction To Threads (pthreads)](https://www.youtube.com/watch?v=ldJ8WGZVXZk)
- [(DOC) pthread_create(3) - Linux man page](https://linux.die.net/man/3/pthread_create)
- [(VIDEO) Mutex Introduction (pthreads)](https://www.youtube.com/watch?v=raLCgPK-Igc)
- [(DOC) pthread_mutex_lock(3p) - Linux manual page](https://www.man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [(VIDEO) Deadlocks in C](https://www.youtube.com/watch?v=LjWug2tvSBU)
- [(TEST) 42philogramm](https://github.com/sugoidesune/42philogramm)
- [(TEST) philosophers_tester](https://github.com/AntonioSebastiaoPedro/philosophers_tester)
