class ThreeAddressCodeGenerator:
    def __init__(self):
        self.code = []
        self.temp_counter = 0

    def generate_code(self, expression):
        self.temp_counter = 0
        self.code = []
        self._parse_expression(expression)
        return self.code
    
    def _parse_expression(self, expression):
        tokens = expression.split()

        if len(tokens) < 3:
            print("Invalid expression!")
            return

        result = tokens[0]
        operator = tokens[1]
        operand = tokens[2]

        self._add_code(result, operator, operand)

        for i in range(3, len(tokens), 2):
            operator = tokens[i]
            operand = tokens[i+1]
            temp_var = 't' + str(self.temp_counter)
            self.temp_counter += 1
            self._add_code(temp_var, operator, operand)
            result = temp_var

    def _add_code(self, result, operator, operand):
        code_line = f'{result} = {operand} {operator} {operand}'
        self.code.append(code_line)


def main():
    expression = input("Enter an arithmetic expression: ")

    generator = ThreeAddressCodeGenerator()
    code = generator.generate_code(expression)

    print("Generated Three-Address Code:")
    for line in code:
        print(line)


if __name__ == '__main__':
    main()
