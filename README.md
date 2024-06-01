# philosophers

![42-philosophers](https://socialify.git.ci/julienhouyet/42-philosophers/image?logo=https%3A%2F%2Fgithub.com%2Fayogun%2F42-project-badges%2Fraw%2Fmain%2Fbadges%2Fphilosophersm.png&name=1&owner=1&pattern=Circuit%20Board&theme=Auto)

# Introduction

Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.

At [42 School](https://github.com/42School), almost every project must be written in accordance to the [Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf), the school's coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.

## :zap: Usage

To use this project, compile the project and run the program with the following arguments :

number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

* **number_of_philosophers:** The number of philosophers and also the number
of forks.

* **time_to_die (in milliseconds):** If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

* **time_to_eat (in milliseconds):** The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

* **time_to_sleep (in milliseconds):** The time a philosopher will spend sleeping.

* **number_of_times_each_philosopher_must_eat (optional argument):** If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.


Example :

```shell
$ ./philo 4 410 200 200
```

###  :electric_plug: Installation

To install the project, clone this repository :

```shell
$ git@github.com:julienhouyet/42-philosophers.git
```

###  :package: Commands

To compile the project, run :

```shell
$ make
```

To re-compile the project  :

```shell
$ make re
```

To wipes all object files :

```shell
$ make clean
```

To delete the project and all object files

```shell
$ make fclean
```