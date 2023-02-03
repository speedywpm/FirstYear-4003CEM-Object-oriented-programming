import sys

def main():
	print('What is your age?')
	age = int(input())

	if age < 5:
		print("You're a baby")
	elif age >= 13 and age <= 18:
		print("You're a teenager")

	if age >= 16:
		print("You can drive")
	
	if age >= 18:
		print("You can vote")

if __name__ == '__main__':
	sys.exit(main())
