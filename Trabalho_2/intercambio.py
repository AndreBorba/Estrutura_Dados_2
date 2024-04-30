def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j][0] > arr[min_idx][0] or (arr[j][0] == arr[min_idx][0] and arr[j][1] < arr[min_idx][1]):
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i][0] > R[j][0] or (L[i][0] == R[j][0] and L[i][1] < R[j][1]):
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

def select_students(T, students, num_bolsas):
    if T == 1:
        selection_sort(students)
    elif T == 2:
        merge_sort(students)
    
    selected_students = []
    for student in students:
        if student[1] <= 10 and num_bolsas > 0:
            selected_students.append(student[2])
            num_bolsas -= 1
    
    return selected_students

T = int(input())
N, M = map(int, input().split())

students = []
for _ in range(N):
    ai, bi, name = input().split()
    ai = float(ai)
    bi = int(bi)
    students.append((ai, bi, name))

selected_students = select_students(T, students, M)

print(len(selected_students))
for student in selected_students:
    print(student)
