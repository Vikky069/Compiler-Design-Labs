import re

def remove_comments_and_whitespace(file_path, output_file_path):
    with open(file_path, 'r') as file:
        content = file.read()

    # Remove single-line comments
    content = re.sub(r'(?<!\\)(#.*?$)', '', content, flags=re.MULTILINE)

    # Remove whitespace and empty lines
    content = re.sub(r'\s+', ' ', content)
    content = re.sub(r'^\s*$', '', content, flags=re.MULTILINE)

    with open(output_file_path, 'w') as output_file:
        output_file.write(content)

# Usage example
input_file_path = 'input.py'
output_file_path = 'output.py'
remove_comments_and_whitespace(input_file_path, output_file_path)
