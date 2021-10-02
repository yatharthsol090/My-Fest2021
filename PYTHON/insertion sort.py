def insertionSort(arr):
for i in range(1, len(arr)):
key = arr[i]
j = i-1
while j >=0 and key < arr[j] :
arr[j+1] = arr[j]
j -= 1
arr[j+1] = key
arr =[]
n = int(input("Enter the length: "))
for i in range(n):
x= int(input("Enter the elements of array "))
arr.append(x)
insertionSort(arr)
print(arr[0:])
