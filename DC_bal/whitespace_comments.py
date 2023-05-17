import re

def remove_comments_and_whitespace(code):
    # Remove single-line comments
    code = re.sub(r'(?<!\\)(#.*?$)', '', code, flags=re.MULTILINE)

    # Remove whitespace and empty lines
    code = re.sub(r'\s+', ' ', code)
    code = re.sub(r'^\*$', '', code, flags=re.MULTILINE)

    return code

# Get input from the user
code = input("Enter the Python code: ")

# Remove comments and whitespace
modified_code = remove_comments_and_whitespace(code)

# Display the modified code
print("Modified code:")
print(modified_code)
