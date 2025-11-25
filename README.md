# 📝 Exam Rank 03 — 42 School

This repository contains my work for **Exam Rank 03** at 42, where the subject is randomly chosen between two core projects: **ft_printf** or **get_next_line**.
The goal is to implement one of these functions **from scratch** under strict time constraints.

---

## 📌 Overview

During the exam, you must complete **one** of the following:

### **1️⃣ ft_printf**

Reimplement a simplified version of `printf()` supporting several format specifiers.
The challenge focuses on handling:

* Variadic arguments
* Formatting logic
* Memory & buffer safety
* Clean and modular C code

### **2️⃣ get_next_line**

Write a function that returns one line at a time from a file descriptor.
The challenge includes:

* Static variables
* Efficient buffer handling
* Edge-case management
* Memory allocation & leak-free logic

You don't know which one you’ll get until the exam starts, making preparation essential.

---

## 🧪 How to Test

### **For ft_printf**

```bash
gcc -Wall -Wextra -Werror *.c -o test
./test
```

### **For get_next_line**

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c -o gnl_test
./gnl_test < file.txt
```

Feel free to adjust BUFFER_SIZE during testing.

---

## 🎯 Purpose

This exam demonstrates:

* Ability to write robust C code under pressure
* Clean handling of memory & edge cases
* Mastery of key 42 fundamentals
* Fast debugging and reliable implementation

