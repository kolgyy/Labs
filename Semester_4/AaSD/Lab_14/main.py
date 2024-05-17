import time  # Импорт модуля времени

# Константы
B = 13
Q = 256

def get_hash(pattern: str) -> int:
    # Функция для создания хеша
    global B, Q  # Используем глобальные константы
    m = len(pattern)
    result = 0
    for i in range(m):
        result = (B * result + ord(pattern[i])) % Q  # По формуле высчитываем хеш.
    return result

def search_patterns_in_text(main_text: str, pattern: str) -> list:
    global B, Q
    pattern_len = len(pattern)  # Длины текста и шаблона
    main_text_len = len(main_text)
    
    multiplier = 1
    for i in range(1, pattern_len):
        multiplier = (multiplier * B) % Q  # Найдем максимальную степень b (для формулы)
    
    pattern_hash = get_hash(pattern)  # Ищем хеш паттерна и первой подстроки, которая равна длине паттерна в тексте
    main_text_hash = get_hash(main_text[:pattern_len])
    
    indices = []  # Массив для хранения индексов первых элементов у образов
    t0 = time.time()
    
    for index_symbol in range(main_text_len - pattern_len + 1):
        if pattern_hash == main_text_hash:  # Проверяем, верны ли хеши
            if main_text[index_symbol: index_symbol + pattern_len] == pattern:  # Убеждаемся, что все одинаково, добавляем индексы
                indices.append(index_symbol)
        
        if index_symbol < main_text_len - pattern_len:
            main_text_hash = ((main_text_hash - ord(main_text[index_symbol]) * multiplier) * B + ord(main_text[index_symbol + pattern_len])) % Q # Новый хеш, чтоб перейти к новой части
            if main_text_hash < 0:
                main_text_hash += Q
    
    t1 = time.time()
    print(f"Result: {len(indices)}; The running time of the algorithm is equal to: {t1 - t0}")
    
    return indices

pattern = input("Введите подстроку: ")
with open("input.txt", encoding="utf-8") as file_read:
    main_text = file_read.read()

found_indices = search_patterns_in_text(main_text, pattern)
print("Индексы первых символов найденных образцов:", found_indices)
