# 🖥️ Operating System Lab Algorithms

A comprehensive collection of Operating System algorithms and concepts implemented in C. This repository is designed to help students understand OS internals through practical, runnable examples.

## 📚 About

This repository contains implementations of important Operating System concepts in C, created primarily for:
- Lab practice and exam preparation
- Understanding system programming concepts
- Bridging the gap between theory and practical implementation

All programs are written in a simple, structured way to make OS concepts accessible and experiment-friendly.

## 📂 What's Inside

The repository covers essential OS topics including:

### Process Management
- Process creation using `fork()`, `wait()`, `exec()` family
- Process synchronization
- Zombie and orphan processes

### Interprocess Communication (IPC)
- Pipes (named and unnamed)
- Shared memory
- Message queues
- Signals

### Thread Programming
- Thread creation and management
- Race condition demonstrations
- Thread synchronization

### Synchronization Mechanisms
- Mutex locks
- Semaphores
- Condition variables

### Classical Problems
- Producer-Consumer problem
- Readers-Writers problem
- Dining Philosophers problem
- Sleeping Barber problem

### Memory Management
- Page replacement algorithms (FIFO, LRU, Optimal)
- Memory allocation strategies

## 🚀 Getting Started

### Prerequisites
- Linux-based operating system (Debian/Ubuntu recommended)
- GCC compiler
- Basic knowledge of C programming

### Compilation

For regular C programs:
```bash
gcc filename.c -o output
./output
```

For programs with threads:
```bash
gcc filename.c -o output -lpthread
./output
```

For programs using math library:
```bash
gcc filename.c -o output -lm
./output
```

### Directory Structure
```text
os-lab-algorithms/
├── process-management/
├── ipc/
├── threads/
├── synchronization/
├── classical-problems/
├── memory-management/
└── README.md
```

### 🤝 Contributing
Contributions are welcome! Whether you're fixing bugs, improving documentation, or adding new examples, your help makes this resource better for everyone.

### Ways to Contribute
- ✨ Add new OS program examples
- 📝 Improve code comments and documentation
- 🐛 Fix bugs or optimize existing implementations
- 🔧 Add better synchronization solutions
- 📚 Enhance explanations and theory links

### Contribution Process

1. Fork the repository
2. Clone your fork:
```bash
git clone https://github.com/your-username/os-lab-algorithms.git
```
3. Create a new branch:
```bash
git checkout -b feature/your-feature-name
```
4. Make your changes
5. Commit with clear messages:
```bash
git commit -m "Add: Brief description of your changes"
```
6. Push to your fork:
```bash
git push origin feature/your-feature-name
```
7. Open a Pull Request

### Guidelines
- Maintain consistent folder structure
- Write clean, readable code with comments
- Include brief explanations for complex logic
- Avoid uploading compiled binaries
- Test your code before submitting

### ⭐ Why This Repo?
Operating Systems can feel theoretical sometimes. This repository bridges that gap by providing:

- Working examples you can run and modify
- Practical demonstrations of theoretical concepts
- A foundation for building more complex OS projects

If you find this helpful, consider starring the repository ⭐ and sharing it with fellow learners!

### 📝 License
This project is open source and available under the [MIT License](LICENSE).

## Happy Learning! 🚀
