 # Get Next Line - 42 School Project 📜

## Introduction 💡

**Get Next Line** (GNL) is a project at **42 School**, where the goal is to create a function that reads and returns a line from a file descriptor, even when reading from a very large file or a slow input source. The function should be memory-efficient and handle multiple file descriptors.

The function must behave exactly like this: each call to `get_next_line()` returns the next line of a file, until the end is reached. 📂

## How it Works ⚙️

The `get_next_line` function works by reading a file (or standard input) line by line until the end of the file (EOF). It uses a buffer to manage and store data temporarily while reading.

Here’s how the function behaves:
1. Reads data from the file descriptor (fd) and stores it in a buffer.
2. Appends any leftover data from the previous read.
3. Extracts the next line (terminated by a newline character `\n`) and returns it.
4. Repeats the process until the end of the file.

## Functions Implemented 🛠️

The project involves creating the following key functions:
- **get_next_line:** The main function that reads from a file descriptor and returns the next line.
- **Helper functions:** To manage string manipulation and memory, such as:
  - `ft_strjoin` (joins two strings)
  - `ft_strlen` (finds the length of a string)
  - `ft_strchr` (searches for a character in a string)
  - `ft_strdup` (duplicates a string)

## Installation 📦

To compile and test **get_next_line**, follow these steps:

1. Clone the repository:
   ```bash
   git clone git@github.com:AnnLvu/get_next_line_42.git
   cd get_next_line
2. Comile the get_next_line
   make        # Compiles the GNL library ⚒️
   make clean  # Cleans up object files 🧹
   make fclean  # Full cleanup of generated files 🧼
   make re     # Rebuild everything from scratch 🔄
Now you're ready to use the get_next_line library in your project! 🚀


   
