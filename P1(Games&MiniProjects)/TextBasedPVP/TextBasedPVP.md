# Simple RPG Game (C++)

**Language**: C++

## Problem Statement

Design and implement the beginning of a very simple RPG game. For now, do not use the keyword `virtual`. All constants (like damage or healing values) can be freely chosen.

## Requirements

### 1. Characters
Each character should have:
- Health points (HP)
- Stamina points
- Base damage value
- A backpack (max size: 16 items)

Characters should be able to:
- Use an item from their backpack on themselves or another character
- Have their current state printed (e.g., health, stamina, inventory)

### 2. Items
Items are split into the following types:

#### a) Small Health Potions
- Can be used once
- Restore a fixed amount of HP

#### b) Large Health Potions
- Can be used twice
- Each use restores a fixed amount of HP

#### c) Small Stamina Potions
- Can be used once
- Restore a fixed amount of stamina

#### d) Large Stamina Potions
- Can be used twice
- Each use restores a fixed amount of stamina

#### e) Weapons
- When used:
  - Reduce HP of the **target character** by (weapon damage + user's base damage)
  - Reduce **user's stamina** by a fixed cost

## Output and Demonstration

- Print status of characters after item usage
- Include a simple `main()` function to demonstrate gameplay (create two characters, give them items, use items on each other)

## File Structure

Write all the code in a single `.cpp` file containing:
- `#include` headers
- Item classes
- Character class
- `main()` function demonstrating the features
