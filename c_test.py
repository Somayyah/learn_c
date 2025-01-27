import subprocess
import sys

def compile_c_program(c_file):
    """Compile the C program using gcc."""
    result = subprocess.run(['gcc', c_file, '-o', c_file.replace('.c', '')], stderr=subprocess.PIPE)
    if result.returncode != 0:
        print(f"Compilation failed: {result.stderr.decode('utf-8')}")
        sys.exit(1)

def run_c_program(program_name, input_data):
    """Run the compiled C program with the given input and return its output."""
    result = subprocess.run([f'./{program_name}'], input=input_data.encode('utf-8'), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if result.returncode != 0:
        print(f"Runtime error: {result.stderr.decode('utf-8')}")
        sys.exit(1)
    
    # Decode the output using 'latin-1' to handle any byte value
    return result.stdout.decode('latin-1').strip()

def parse_test_cases(test_file):
    """Parse the test cases from the .txt file."""
    with open(test_file, 'r') as file:
        content = file.read().strip()
    
    # Split into individual test cases
    test_cases = []
    for test_case in content.split('\n\n'):  # Test cases are separated by double newlines
        if not test_case.strip():
            continue
        parts = test_case.split('---')  # Input and expected output are separated by '---'
        if len(parts) != 2:
            print(f"Invalid test case format: {test_case}")
            sys.exit(1)
        input_data, expected_output = parts

        # Handle special case: "(empty input)"
        if input_data.strip() == "(empty input)":
            input_data = ""  # Set input to an empty string
        else:
            # Interpret escape sequences in input
            input_data = input_data.strip().encode('utf-8').decode('unicode_escape')

        # Handle special case: "(no output expected)"
        if expected_output.strip() == "(no output expected)":
            expected_output = ""  # Set expected output to an empty string
        else:
            # Interpret escape sequences in expected output
            expected_output = expected_output.strip().encode('utf-8').decode('unicode_escape')

        test_cases.append((input_data, expected_output))
    return test_cases

def main():
    if len(sys.argv) != 2:
        print("Usage: python test_c_program.py <c_program_name>")
        sys.exit(1)

    c_program_name = sys.argv[1]
    c_file = f"{c_program_name}.c"
    test_file = f"{c_program_name}.txt"

    # Compile the C program
    compile_c_program(c_file)

    # Parse test cases from the .txt file
    test_cases = parse_test_cases(test_file)

    # Initialize counters
    total_tests = len(test_cases)
    passed_tests = 0

    # Run each test case
    for i, (input_data, expected_output) in enumerate(test_cases, 1):
        print(f"Running test case {i}...")
        actual_output = run_c_program(c_program_name, input_data)

        # Compare actual output with expected output
        if actual_output == expected_output:
            print(f"Test case {i} passed!")
            passed_tests += 1
        else:
            print(f"Test case {i} failed!")
            print(f"Input:\n{input_data}")
            print(f"Expected output:\n{expected_output}")
            print(f"Actual output:\n{actual_output}")
        print()

    # Calculate and print the total score
    if total_tests > 0:
        score = (passed_tests / total_tests) * 100
        print(f"Total score: {score:.2f}% ({passed_tests}/{total_tests} test cases passed)")
    else:
        print("No test cases found.")

if __name__ == "__main__":
    main()