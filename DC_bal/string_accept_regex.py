import re

def is_string_accepted(regular_expression, string):
    pattern = re.compile(regular_expression)
    match = re.fullmatch(pattern, string)
    if match:
        return True
    else:
        return False


def main():
    # Define the regular expression
    regular_expression = r'a+b*'

    # Prompt the user for a string
    string = input("Enter a string: ")

    # Check if the string is accepted by the regular expression
    if is_string_accepted(regular_expression, string):
        print("The string is accepted.")
    else:
        print("The string is rejected.")


if __name__ == '__main__':
    main()
