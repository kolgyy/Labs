cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
								# Если версия установленой программы
								# старее указаной, произайдёт аварийный выход.

		 
project(lab9)			 # имя проекта	


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(inc)			 # указываем, где искать файлы заголовков

add_executable(lab9 main.cpp ) #добавить исполняемый файл
								 