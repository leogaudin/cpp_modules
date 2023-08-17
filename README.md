<div align="center">
	<h1>🆙 CPP Modules</h1>
</div>

## Before reading

⚠️ **I'm not going to explain the specificities of C++** in this README, because it would be too long for anyone to read, that I would do it less well than online resources, and that I have better things to do.

Only guidelines on the exercises logic will be provided.

## Module 00

### ex00: Megaphone

#### Instructions

> Just to make sure that everybody is awake, write a program that behaves as follows:

```bash
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

#### Explanations

Well this one is pretty simple obviously, it's the very beginning of our C++ learning.

Read the subject, of course, but as a summary, here are the main rules that will make a difference in the way we're going to code this:

* **No norme**, which means `for` loops and all those things are allowed now (it's still ugly)
* The **Standard Library is allowed**, so all the small tasks we had to code ourselves can be used natively now (here `toupper`)
* `printf`, `alloc` and `free` are prohibited, so writing to the standard output has to be done with the ugly `std::cout`

That said, you can clearly code this tiny capitalisation program yourself (if not well congrats for not having been fired yet):

1. Go through every argument
2. Go through every letter of every argument and print their `toupper` equivalent
3. Fix 1-2 things to stick with the subject and you can advance to the next level

### ex01: My Awesome PhoneBook

#### Instructions

> Welcome to the 80s and their unbelievable technology! Write a program that behaves like a crappy awesome phonebook software.
>
> You have to implement two classes:
>
> * **PhoneBook**
>	* It has an array of contacts.
>	* It can store a maximum of **8 contacts**. If the user tries to add a 9th contact, replace the oldest one by the new one.
>	* Please note that dynamic allocation is forbidden.
>
> * **Contact**
>	* Stands for a phonebook contact.
>
> In your code, the phonebook must be instantiated as an instance of the **PhoneBook** class. Same thing for the contacts. Each one of them must be instantiated as an instance of the **Contact** class. You’re free to design the classes as you like but keep in mind that anything that will always be used inside a class is private, and that anything that can be used outside a class is public.

#### Explanations

This one is pretty fastidious to do, but not that complicated.

> ⚠️ ...if you already learned Object-Oriented Programming before.
>
> If you never did, you can spend some hard time trying to understand the whole concept.
>
> If you did, with Java for example, you only have to understand the ugly C++ syntax and the particularities

You just have to respect the precise layout requirements of the subject, but otherwise you have built-in functions for most of the annoying things:

* `std::setw(n)` to set the width of a field, with automatically right-aligned text
* `std::getline` with `std::cin` to get some user input
* `.empty()`, `.length()`, `.compare()` and all the string methods that are magic when coming from the previous projects

Other than that, this exercise is quite repetitive, in coding and testing, with `std::cout`s everywhere, but the complexity is pretty low.

### ex02: The Job of Your Dreams

#### Instructions

> Today is your first day at GlobalBanksters United. After successfully passing the re- cruitment tests (thanks to a few Microsoft Office tricks a friend showed you), you joined the dev team. You also know the recruiter was amazed by how quickly you installed Adobe Reader. That little extra made all the difference and helped you defeat all your opponents (aka the other applicants): you made it!
>
> Anyway, your manager just gave you some work to do. Your first task is to recreate a lost file. Something went wrong and a source file was deleted by mistake. Unfortunately, your colleagues don’t know what Git is and use USB keys to share code. At this point, it would make sense to leave this place right now. However, you decide to stay. Challenge accepted!
>
> Your fellow developers give you a bunch of files. Compiling tests.cpp reveals that the missing file is Account.cpp. Lucky you, the header file Account.hpp was saved. There is also a log file. Maybe you could use it in order to understand how the Account class was implemented.
>
> You start to recreate the Account.cpp file. In only a few minutes, you code a few lines of pure awesome C++. After a couple of failed compilations, your program passes the tests. Its output matches perfectly the one saved in the log file (except for the timestamps which will obviously differ since the tests saved in the log file were run before you were hired).
>
> Damn, you’re impressive!

**😮‍💨 Summary because all the subject is unclear and way too long:**

1. Download the files (`Account.hpp`, `tests.cpp` and `19920104_091532.log`) from the intra and put them in your folders
2. Look at `Account.hpp` and see what functions are not implemented
3. Try to implement them while compiling `tests.cpp` and comparing its output with `19920104_091532.log` (step-by-step, otherwise you'll get lost)

#### Explanations

Here is the beginning of the instructions in `tests.cpp`:
```cpp
Account::displayAccountsInfos();
std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
```

When you look at the log, you see that the first infos are:
```log
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] index:2;amount:957;created
[19920104_091532] index:3;amount:432;created
[19920104_091532] index:4;amount:1234;created
[19920104_091532] index:5;amount:0;created
[19920104_091532] index:6;amount:754;created
[19920104_091532] index:7;amount:16576;created

[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
[19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
[19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
[19920104_091532] index:3;amount:432;deposits:0;withdrawals:0
[19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
[19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
[19920104_091532] index:6;amount:754;deposits:0;withdrawals:0
[19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0
```

In order, this corresponds to:

1. The log when the Account objects are **constructed**
2. The **`displayAccountsInfos()`** log
3. The **`displayStatus()`** executed for every Account object log

So now you know that the **constructor**, for example, displays:

1. `[timestamp] `
2. index:
3. `account_index`
4. ;amount:
5. `account_amount`
6. ;created

Repeat this analysis for the rest of the log, and after a bit of trial and error you should get the correct output and be done with this.

## Module 01

### ex00: BraiiiiiiinnnzzzZ

#### Instructions

> First, implement a **Zombie** class. It has a string private attribute name.
> Add a member function `void announce( void );` to the Zombie class. Zombies announce themselves as follows:
>
> *name: BraiiiiiiinnnzzzZ...*
>
> For a zombie named Foo, the message would be:
>
> *Foo: BraiiiiiiinnnzzzZ...*
>
> Then, implement the two following functions:
> * `Zombie* newZombie( std::string name );`
>
> 	* It creates a zombie, name it, and return it so you can use it outside of the function scope.
>
> * `void randomChump( std::string name );`
>
> 	* It creates a zombie, names it, and the zombie announces itself.
>
> Now, what is the actual point of the exercise? You have to determine in what case it’s better to allocate the zombies on the stack or heap.
>
> Zombies must be destroyed when you don’t need them anymore. The destructor must print a message with the name of the zombie for debugging purposes.

#### Explanations

Well given that you should understand classes, objects, instantiation and all now, this exercise is pretty simple and doesn't really have a goal.

However it is pretty useful to understand how memory is allocated and freed depending on the methods we use.

> ⚠️ Don't forget to print a message with the zombie's name in the class destructor!
>
> If you don't this whole exercise is useless.

To see by yourself and make your own assumptions, once you're done implementing the 2-3 things required, you can design your `main.cpp` like that:

```cpp
Zombie *zombie_heap = newZombie("Romuald");
zombie_heap->announce();

Zombie zombie_stack("Bernard");
zombie_stack.announce();

randomChump("Bernardeau");
return (0);
```

Compile, execute it and look at the output, and you'll have a better knowledge about how things work inside.

### ex01: Moar brainz!

#### Instructions

> Time to create a **horde of Zombies**!
> Implement the following function in the appropriate file:
>
> `Zombie* zombieHorde( int N, std::string name );`
>
> It must allocate N Zombie objects in a single allocation. Then, it has to initialize the zombies, giving each one of them the name passed as parameter. The function returns a pointer to the first zombie.
>
> Implement your own tests to ensure your `zombieHorde()` function works as expected. Try to call `announce()` for each one of the zombies.
>
> Don’t forget to `delete` all the zombies and check for **memory leaks**.

#### Explanations

First copy all your `ex00` folder and delete the `newZombie` and `randomChump` files and functions.

Then the only thing you need to do is adding the necessary function:

1. Instantiate the objects in one instruction: luckily, `new` supports arrays of objects
2. Add a member method to set a zombie's name, and call it in a `for` loop
3. Return the array

> 💡 When you create your `main` for testing, note that `delete` also supports arrays

### ex02: HI THIS IS BRAIN

#### Instructions

> Write a program that contains:
>
> * A string variable initialized to "HI THIS IS BRAIN".
> * `stringPTR`: A pointer to the string.
> * `stringREF`: A reference to the string.
>
> Your program has to print:
> * The memory address of the string variable.
> * The memory address held by `stringPTR`.
> * The memory address held by `stringREF`.
>
> And then:
>
> * The value of the string variable.
> * The value pointed to by `stringPTR`.
> * The value pointed to by `stringREF`.
>
> That’s all, no tricks. The goal of this exercise is to demystify references which can seem completely new. Although there are some little differences, this is another syntax for something you already do: address manipulation.

#### Explanations

Again, the goal of this exercise is not to build something but rather understand concepts, so I'll just say that:

* `type name` is how you declare variables normally
* `type* namePTR` is how you declare a pointer
* `type& nameREF` is how you declare a reference

> 💡 A reference is associated to a variable, whereas a pointer simply looks the address' value of a variable, and will keep it like that.

### ex03: Unnecessary violence

#### Instructions



#### Explanations



### ex04

#### Instructions



#### Explanations



### ex05

#### Instructions



#### Explanations



### ex06

#### Instructions



#### Explanations



## Module 02



## Module 03



## Module 04



## Module 05



## Module 06



## Module 07



## Module 08



## Module 09



## Credits

*🙇🏻‍♂️ This project is based on the work of SOMEONE.*

Link to [SOMEONE'S WORK](https://github.com/)
