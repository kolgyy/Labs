def subset_sum_greedy(numbers, target_sum):    # Функция для нахождения подмножества с суммой, используя жадный алгоритм
    numbers.sort(reverse=True)  # Сортировка чисел по убыванию
    subset = []  # Инициализация пустого подмножества
    current_sum = 0  # Инициализация текущей суммы подмножества
    # Выбор чисел для подмножества
    for num in numbers:  # Перебираем числа из списка
        if current_sum + num <= target_sum:  # Если добавление числа не превысит целевую сумму
            subset.append(num)  # Добавляем число к подмножеству
            current_sum += num  # Увеличиваем текущую сумму
    return subset, current_sum  # Возвращаем найденное подмножество и его сумму

# Пример использования функции
numbers = [3, 34, 4, 12, 5, 2]
target_sum = 15
subset, sum_value = subset_sum_greedy(numbers, target_sum)  # Находим подмножество и его сумму

if sum_value == target_sum:  # Если найденное подмножество имеет целевую сумму
    print(f"Найдено подмножество с суммой {target_sum}: {subset}")
else:
    print(f"Не удалось найти подмножество с суммой {target_sum}")
    print(f"Ближайшее найденное подмножество: {subset}")
    print(f"Сумма найденного подмножества: {sum_value}")
