# Competitive Programming Solutions

A repository of my **competitive programming solutions**, organized by competitions such as **Codeforces, ICPC, USACO, LeetCode**, and more.  

## Repository Structure

```
/Solutions
    /Codeforces
    /ICPC
    /USACO
    /LeetCode
manager.bash
template.txt
testcase.txt
```

## Automation Utility (Optional)

The repository includes a **universal Bash script** `manager.bash` that can:

- **Create** a new C++ file from a template.  
- **Compile and run** a C++ file automatically.

### Usage

1. **Set the contest/project folder** in your terminal:

   **Bash / WSL / Linux**
   ```bash
   export CP="/path/to/contest/folder"
   ```

2. **Create a new problem file:**
   ```bash
   ./manager.bash create <filename>
   ```

3. **Compile and run a problem file:**
   ```bash
   ./manager.bash run <filename>
   ```

> The `$CP` variable is temporary for the session, so you can quickly switch between contest folders.

## Input Management

- The script reads input from a global `testcase.txt` file.  
- **Location:** In the main repository path (where `manager.bash` is located). Needs to be **created manually** if the repository is newly copied (it is added to `.gitignore` on purpose).  
- **Usage:** Add or update input for the problem in `testcase.txt` before running.  
- Only one problem input can be active at a time. Update `testcase.txt` for different problems.


## Notes

- Keep `template.txt` as the starter template for new problems.  
- The automation script is optional; manual creation, compilation, and execution of files is always possible.


## Example Workflow

```bash
# Set contest folder
export CP="Solutions/Codeforces/2151"

# Create a new problem file
./manager.bash create A

# Compile and run ProblemA.cpp
./manager.bash run A
```

## Contact Information
| Name           | Phone Number      | Email               | LinkedIn                                    |
|----------------|-------------------|---------------------|---------------------------------------------|
| Andria Beridze | +1 (267) 632-6754 | andria24b@gmail.com | [linkedin.com/in/andriaberidze](https://www.linkedin.com/in/andriaberidze/) |
