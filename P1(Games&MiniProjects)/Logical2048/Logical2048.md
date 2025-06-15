# Logic Game Grid Processor

**Language**: C++

## Problem Description

Implement a simple logic game operating on a square grid. The board consists of non-negative integers, with `0` representing an empty cell. The board supports various transformations and I/O commands.

## Input Format

The input consists of two sections:

### 1. Initial Board Size
The first line contains a single integer `M` — the size of the board (the board has `M × M` cells).  
Constraints:  
`1 ≤ M ≤ 1024`  
All initial values on the board are `0`.

### 2. Commands
Each subsequent line contains a single command from the set:  
`{N, L, P, G, D, S, C, W, K}` possibly followed by numbers.

#### Command: `N x y w`
Insert number `w` at position `(x, y)` on the board.  
- `x`, `y` — coordinates (0-based), `0 ≤ x, y < M`  
- `w` — value to insert, `w ≤ 2^16`

#### Command: `L` (Left Shift)
For each row:
- Shift non-zero values to the left.
- Compress row by checking adjacent pairs:
  - If value at index `i` divides `i+1`, then:
    - `i+1 -= i`
    - `i *= 2`
    - stop scanning this row and repeat the process from the start.
- Repeat until no compressible pairs remain.

#### Command: `P` (Right Shift)
Same as `L`, but operates from right to left.

#### Command: `G` (Up Shift)
Performs the `L`-style shift on each column from top to bottom.

#### Command: `D` (Down Shift)
Performs the `P`-style shift on each column from bottom to top.

#### Command: `S` (Sum)
Print the sum of all values on the board followed by a newline.

#### Command: `W` (Write)
Print the board contents:
- Each row on a separate line
- Values separated by a single space
- Add a newline after the last row

#### Command: `C M p[0][0] ... p[M-1][M-1]` (Create New Board)
- Resets the board to new size `M × M`
- Fills it row-wise with given values

#### Command: `K` (Kill/End)
Print the sum of all values on the board, followed by a newline, then terminate the program.
