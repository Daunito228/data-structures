def summ(arr):
    if len(arr)==1:
        return arr[0]
    return arr[0] + summ(arr[1:])

arr = [2, 34, 34, 12, 1]
print(summ(arr))