# 🎵 Playlist Shuffler (C++ - DSA)

A command-line **Music Playlist Shuffler** implemented in **C++** for a 3rd semester Data Structures & Algorithms (DSA) project.  
The playlist is implemented as a **doubly-linked list** and supports adding songs, deleting songs, undoing the last delete, shuffling the playlist, and displaying songs.

---

## 🔹 Features
- Add songs to the playlist (tail insertion)
- Delete a song by name (stores last deleted for undo)
- Undo the last deleted song (restores to tail)
- Shuffle the playlist (Fisher–Yates-like shuffle on node pointers)
- Display the playlist

---

## 🧠 Data structures & algorithms used
- **Doubly-linked list** for playlist representation (efficient insert/delete)
- **Shuffle** implemented by copying node pointers to an array and performing Fisher–Yates shuffle (O(n) time, O(n) extra space)
- Undo uses a `lastDeleted` pointer to restore the last removed node

---

## ⚠️ Platform notes
This code uses `conio.h`, `getch()` and `system("cls")`, which are **Windows-specific** (MinGW/Visual Studio). On Linux/macOS you may need to:
- Remove `conio.h` and replace `getch()` with `std::cin.get()` or an equivalent.
- Replace `system("cls")` with `system("clear")` or avoid using `system()` for portability.

---

## ▶️ How to compile & run (Windows / MinGW)
```bash
g++ main.cpp -o playlist_shuffler
playlist_shuffler.exe
