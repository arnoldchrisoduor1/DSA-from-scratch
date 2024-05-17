import random

num1 = [random.randint(1, 100) for _ in range(10)]
num2 = [random.randint(1, 100) for _ in range(10)]

result = [x * y for x, y in zip(num1, num2)]

print(result)

result = { i: [ x * y for y in num2 ] for i, x in enumerate(num1) }
print(result)