# 🎮 Tic Tac Toe in C

This is a **Tic Tac Toe** game built in **C programming language**, designed for both **2-player mode** and **vs Computer mode**, with creative features like **difficulty levels**, **score tracking**, and a clean **board display** after every move.

## 🧠 Features

* ✅ **Two Modes**:

  * 👥 Play with a Friend
  * 🤖 Play against Computer

* ✅ **Difficulty Levels for AI**:

  * 🟢 Easy: Random moves
  * 🔴 Hard: Blocks player's winning moves

* ✅ **Score Tracking**:

  * Tracks wins for Player 1, Player 2 / Computer, and draws across rounds

* ✅ **Play Again Option**:

  * After every match, the user can choose to play again or exit

* ✅ **Real-Time Board Display**:

  * The Tic Tac Toe grid updates **live after every move**
  * Uses a clear and visually aligned board format

## 🛠️ Tech Used

| Component      | Details                          |
| -------------- | -------------------------------- |
| Language       | C (GCC compiler)                 |
| Compiler       | `gcc` (MinGW / TDM-GCC / Linux)  |
| Platform       | Cross-platform (Windows, Linux)  |
| IDE (optional) | Visual Studio Code, Code::Blocks |

## 🚀 How to Compile & Run

### 🔧 Compile

**On Windows:**

bash
gcc tictactoe.c -o tictactoe.exe

**On Linux/macOS:**

bash
gcc tictactoe.c -o tictactoe

### ▶️ Run

**On Windows:**

bash
./tictactoe.exe

**On Linux/macOS:**

bash
./tictactoe

## 📌 Highlights

* Clean and modular function structure
* User-friendly symbol input (`X` or `O`)
* Dynamically updating game board
* Uses `toupper()` and `rand()` from `<ctype.h>` and `<stdlib.h>`
* AI uses **basic defensive logic** in Hard mode

## 📁 File Structure

├── tictactoe.c        # Main source file
├── README.md          # This file

## 🧑‍💻 Author

Made by Nikhil Tiwari

> Feel free to fork, improve, and use this for your college or hobby projects

## 📜 License

This project is licensed under the **MIT License** – free to use and modify
