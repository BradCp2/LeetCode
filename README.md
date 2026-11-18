# LeetCode Solutions

A collection of my solutions to LeetCode problems, implemented in C++.

## Repository Structure

Each problem is organised into its own Git branch, modifying the template C++ solution file as the starting point.

- `main` – Base repository containing the initial C++ template.
- `<problem-ID>/<problem-name>` – Individual branches containing solutions to specific problems.

## Usage

### 1. Creating a new problem branch

Start from main to ensure each problem uses the original template.

```
git switch main
git switch -c <problem-ID>/<problem-name>
```

Keep format consistent using 4-digit code and dash separated lowercase problem names, for example:
``` 
git switch -c 0001/two-sum
```

### 2. Develop solution

Modify `Main.cpp` with the solution to the given problem.
```
git switch 0001/two-sum
git add main.cpp
git commit -m "Solution to task 0001/two-sum"
```


Initial push to GitHub:
```
git push -u origin 0001/two-sum
```

Any subsequent pushes:
```
git push
```

### 3. Navigating between problems

```
git switch 0002/add-two-numbers
git switch 0003/longest-substring-wthout-repeated-characters
git switch main
```

## Languages & Tools

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=cplusplus&logoColor=white) ![Git](https://img.shields.io/badge/Git-F05032?style=flat&logo=git&logoColor=white) ![CLion](https://img.shields.io/badge/CLion-000000?style=flat&logo=clion&logoColor=white)
