import random
import argparse

def generate_unique_sequence(count, start=-5000, end=5000):
	numbers = random.sample(range(start, end + 1), count)
	return numbers

def format_sequence(numbers):
	return ' '.join(map(str, numbers))

def main():
	parse = argparse.ArgumentParser("Generate")
	parse.add_argument("size", type=int, help="Size")
	args = parse.parse_args()
	numbers = generate_unique_sequence(args.size)
	formatted_numbers = format_sequence(numbers)
	print(f"{formatted_numbers}")
if __name__ == "__main__":
	main()
