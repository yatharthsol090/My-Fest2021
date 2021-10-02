def newton_method(number, number_iters = 100):
a = float(number)
for i in range(number_iters):
number = 0.5 * (number + a / number)
return number
a=int(input("Enter the number:"))
print("Square root of number:",newton_method(a))
