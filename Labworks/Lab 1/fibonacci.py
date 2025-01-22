import time

def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1

    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

def main():
    print("Enter a number to compute the nth Fibonacci number:")
    num = int(input("Number: "))

    start_declare_time = time.time()

    start_process_time = time.time()

    result = fibonacci(num)

    end_process_time = time.time()

    print(f"\nThe {num}th Fibonacci number is: {result}")
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
