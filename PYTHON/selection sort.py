def selectionSort(arr,n):
for i in range(len(arr)):
min_index = i
for j in range(i+1, len(arr)):
if arr[min_index] > arr[j]:
min_index = j
arr[i], arr[min_index] = arr[min_index], arr[i]
arr =[]
n = int(input("enter the length: "))
for i in range(n):
x= int(input("enter the elements of array "))
arr.append(x)
selectionSort(arr,n)
print(arr[0:])
