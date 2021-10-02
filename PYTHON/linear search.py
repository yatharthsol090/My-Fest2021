def linearSearch(arr, key):
for i in range(len(arr)):
if arr[i] == key:
return i
return -1
arr =[]
n = int(input("enter the length:"))
for i in range(n):
x= int(input("enter the elements of array "))
arr.append(x)
key = int(input("enter the value to be searched :"))
result = linearSearch(arr, key)
if(result == -1):
print("Element not found")
else:
print("Element found at index: ", result)
