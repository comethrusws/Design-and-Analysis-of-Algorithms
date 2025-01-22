import time

def gcd(a, b):
    """Compute the GCD of two numbers using the Euclidean Algorithm."""
    while b:
        a, b = b, a % b
    return a

def main():
    print("Enter two numbers to compute their GCD:")
    num1 = int(input("First number: "))
    num2 = int(input("Second number: "))

    start_declare_time = time.time()
    start_process_time = time.time()

    result = gcd(num1, num2)

    end_process_time = time.time()

    print(f"\nThe GCD of {num1} and {num2} is: {result}")
    print(f"Time when variables were declared: {start_declare_time:.6f} seconds")
    print(f"Time when process started: {start_process_time:.6f} seconds")
    print(f"Time when process ended: {end_process_time:.6f} seconds")

    # calculate and display time taken
    declare_to_process_time = (start_process_time - start_declare_time) * 1000
    process_duration = (end_process_time - start_process_time) * 1000
    total_time = (end_process_time - start_declare_time) * 1000

    print(f"\nTime taken from declaration to process start: {declare_to_process_time:.6f} ms")
    print(f"Time taken for the computation process: {process_duration:.6f} ms")
    print(f"Total time taken: {total_time:.6f} ms")

if __name__ == "__main__":
    main()
