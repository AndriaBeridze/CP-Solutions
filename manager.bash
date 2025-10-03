#!/bin/bash

# ------------------------- Universal C++ Manager Script -------------------------
# This script can either:
#   1. Initialize a new C++ file from template (create)
#   2. Compile & run an existing C++ file with optional input redirection (run)
#
# Usage:
#   ./manager.bash create <filename>
#   ./manager.bash run <filename>
# ------------------------------------------------------------------------

# Default project path (current directory)
COMPILE_PATH="${CP:-.}"
ACTION="$1"     # create or run
FILENAME="$2"   # base name of C++ file
TEMPLATE_FILE="template.txt"
INPUT_FILE="testcase.txt"

# Validate action
if [[ -z "$ACTION" || -z "$FILENAME" ]]; then
    echo "Usage: $0 <create|run|push> <filename>"
    exit 1
fi

SOURCE_FILE="${FILENAME}.cpp"
EXECUTABLE_FILE="${FILENAME}.exe"

# ------------------------- CREATE ACTION -------------------------
if [[ "$ACTION" == "create" ]]; then
    # Create project directory if it doesn't exist
    if [[ ! -d "$COMPILE_PATH" ]]; then
        echo "Directory $COMPILE_PATH does not exist. Creating it now."
        mkdir -p "$COMPILE_PATH"
    fi

    # Check template file
    if [[ ! -f "$TEMPLATE_FILE" ]]; then
        echo "Error: Template file '$TEMPLATE_FILE' not found."
        exit 1
    fi

    # Copy template to new source file
    cp "$TEMPLATE_FILE" "$COMPILE_PATH/$SOURCE_FILE"
    echo "Initialized '$COMPILE_PATH/$SOURCE_FILE' from '$TEMPLATE_FILE'."

# ------------------------- RUN ACTION -------------------------
elif [[ "$ACTION" == "run" ]]; then
    # Check source file
    if [[ ! -f "$COMPILE_PATH/$SOURCE_FILE" ]]; then
        echo "Error: Source file '$COMPILE_PATH/$SOURCE_FILE' not found."
        exit 1
    fi

    # Check input file
    if [[ ! -f "$INPUT_FILE" ]]; then
        echo "Error: Input file '$INPUT_FILE' not found."
        exit 1
    fi

    # Compile
    clear
    echo "Compiling '$COMPILE_PATH/$SOURCE_FILE'..."
    g++ -o "$COMPILE_PATH/$EXECUTABLE_FILE" "$COMPILE_PATH/$SOURCE_FILE"

    if [[ $? -ne 0 ]]; then
        echo "Compilation failed. Please check your code."
        exit 1
    fi

    # Run executable with input
    echo "Compilation successful. Running the program..."
    echo "--------------------------------------------------------"
    echo
    "$COMPILE_PATH/$EXECUTABLE_FILE" < "$INPUT_FILE"
    echo
    echo "--------------------------------------------------------"

    # Cleanup
    echo "Cleaning up..."
    rm "$COMPILE_PATH/$EXECUTABLE_FILE"
    echo "Deleted binary: '$COMPILE_PATH/$EXECUTABLE_FILE'"

    read -n 1 -s -r -p "Press any key to continue"
    clear

# ------------------------- PUSH ACTION -------------------------
# ------------------------- PUSH ACTION -------------------------
elif [[ "$ACTION" == "push" ]]; then
    # Check source file
    if [[ ! -f "$COMPILE_PATH/$SOURCE_FILE" ]]; then
        echo "Error: Source file '$COMPILE_PATH/$SOURCE_FILE' not found."
        exit 1
    fi
    
    REL_PATH=$(realpath --relative-to="Solutions/" "$COMPILE_PATH/$SOURCE_FILE")
    echo "Preparing to push '$REL_PATH' to git repository."

    # Ask for validation
    echo "You are about to add and push the file: '$REL_PATH'"
    read -p "Is this path correct? [y/N]: " CONFIRM

    if [[ "$CONFIRM" != "y" && "$CONFIRM" != "Y" ]]; then
        echo "Aborting push."
        exit 0
    fi

    # Stage file
    git add "$COMPILE_PATH/$SOURCE_FILE"

    # Commit with message
    git commit -m "Solve $REL_PATH"

    # Push
    git push
    echo "File '$REL_PATH' has been committed and pushed successfully."

    read -n 1 -s -r -p "Press any key to continue"
    clear

# ------------------------- INVALID ACTION -------------------------
else
    echo "Invalid action: '$ACTION'. Use 'create', 'run', or 'push'."
    exit 1
fi
