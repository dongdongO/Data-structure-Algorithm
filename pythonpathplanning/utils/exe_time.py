from functools import wraps
import time
def exe_time(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
                start_time = time.perf_counter()
                print(f"{func.__qualname__}")
                result = func(*args, **kwargs)
                end_time = time.perf_counter()
                total_time = end_time - start_time

                print(f"{total_time:.6f} seconds\n", flush=True)
                return result
        return wrapper