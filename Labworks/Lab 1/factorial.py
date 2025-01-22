import time

def factorial(n):
    """Compute the factorial of a number iteratively."""
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

def main():
    print("Enter a number to compute its factorial:")
    num = int(input("Number: "))

    start_declare_time = time.time()

    start_process_time = time.time()

    result = factorial(num)

    end_process_time = time.time()

    print(f"\nThe factorial of {num} is: {result}")
    print(f"Time when variables were declared: {start_declare_time:.6f} seconds")
    print(f"Time when process started: {start_process_time:.6f} seconds")
    print(f"Time when process ended: {end_process_time:.6f} seconds")

    declare_to_process_time = (start_process_time - start_declare_time) * 1000
    process_duration = (end_process_time - start_process_time) * 1000
    total_time = (end_process_time - start_declare_time) * 1000

    print(f"\nTime taken from declaration to process start: {declare_to_process_time:.6f} ms")
    print(f"Time taken for the computation process: {process_duration:.6f} ms")
    print(f"Total time taken: {total_time:.6f} ms")

if __name__ == "__main__":
    main()
