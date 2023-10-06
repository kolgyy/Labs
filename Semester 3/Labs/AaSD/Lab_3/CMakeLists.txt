cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									
set(PROJECT_NAME prime_factorization)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)



add_executable("${PROJECT_NAME}" main.cpp
		
)
											