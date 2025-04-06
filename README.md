# 📅 Count Days Without Meetings - C++ Solution
 
This project calculates how many days an employee is available without any scheduled meetings, given a list of overlapping meeting intervals.

---

## 🧠 Problem Statement

You are given:
- A positive integer `days` representing the total number of working days.
- A 2D array `meetings`, where each element is a pair `[start_i, end_i]`, representing a scheduled meeting (inclusive of both start and end day).

Your task is to count how many days **do not** have any scheduled meetings, considering that meetings can **overlap**.

---

## 🛠️ Approach

1. **Sort** all meeting intervals by their start day.
2. **Merge** overlapping intervals into consolidated blocks of meeting days.
3. Calculate the total number of **meeting days** from the merged intervals.
4. Subtract the meeting days from the total available days to get the number of **free days**.

---

### Sample Interaction:
```
Enter total number of days: 10
Enter number of meetings: 3
Enter meetings (start and end day for each meeting):
5 7
1 3
9 10
Number of days without meetings: 2
```

## ✅ Features

- Handles overlapping meetings efficiently.
- Clean and readable C++ implementation.
- Optimized with O(N log N) complexity.
- Accepts dynamic input from the user via terminal.

---

## 🧩 Concepts Used

- Sorting
- Greedy Interval Merging
- Vector manipulation
- C++ Standard Library
