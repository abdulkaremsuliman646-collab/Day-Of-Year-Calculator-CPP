# 📅 Robust Day-of-Year Calculator in C++

A modular C++ console application that computes the cumulative day count from January 1st to any valid target date, featuring real-time input sanitization and Gregorian leap year arithmetic.

## 🚀 Key Engineering Highlights

- **Context-Aware Input Validation:** Unlike naive implementations that allow generic $1\text{--}31$ day bounds, this application dynamically binds acceptable day input directly to the exact target month and year ($\text{1 to } \text{NumberOfDaysInAMonth}(Month, Year)$).
- **Gregorian Leap Logic:** Accurately accounts for century leap exceptions ($Year \pmod{400} == 0 \lor (Year \pmod{4} == 0 \land Year \pmod{100} \neq 0)$) to determine February's boundary ($28$ vs $29$ days).
- **Bounded Summation ($O(N)$):** Bounded procedural accumulation loop running exclusively over completed months ($m < Month$) before applying the day offset, eliminating out-of-range iterations.
- **Single-Responsibility Architecture:** Modular functional design separating user input sanitization, lookup tables, and calendar arithmetic.

## 🛠️ Tech Stack
- **Language:** C++
- **Paradigms:** Procedural Programming, Defensive Programming / Input Validation, Date Arithmetic
