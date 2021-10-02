def binary_search(arr, n):
low = 0
high = len(arr) - 1
mid = 0
while low <= high:
mid = int((high + low) / 2)
if arr[mid] < n:
low = mid + 1
elif arr[mid] > n:
high = mid - 1
else:
return mid
# element was not present in the list, return -1
return -1
arr =[]
m = int(input("enter the length of list:"))
for i in range(m):
x= int(input("enter the elements of list "))
arr.append(x)
n = int(input("enter the value to be searched :"))
result = binary_search(arr, n)
if result != -1:
print("Element is present at index", str(result))
else:
print("Element is not present in list")
