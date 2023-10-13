COMMAND = g++ -Wall -O3 *.cpp src/*.cpp -o main -pthread

## FOR THE FIRST TIME
compile: 
	@$(COMMAND)

## EACH TIME YOU OPEN THE CONSOLE -- This will allow your console to display the special char
set_code_page:
	@chcp 65001

## DISPLAY MENU
menu:
	@main

## THREAD POOL

thread_pool_2x2:
	@main 2 3

thread_pool_3x3:
	@main 3 3

thread_pool_4x4:
	@main 4 3

thread_pool_5x5:
	@main 5 3

thread_pool_6x6:
	@main 6 3

thread_pool_7x7:
	@main 7 3

thread_pool_8x8:
	@main 8 3

## THREAD VECTOR
thread_vector_2x2:
	@main 2 4

thread_vector_3x3:
	@main 3 4

thread_vector_4x4:
	@main 4 4

thread_vector_5x5:
	@main 5 4

thread_vector_6x6:
	@main 6 4

thread_vector_7x7:
	@main 7 4

thread_vector_8x8:
	@main 8 4


## ITERATIVE
iterative_2x2:
	@main 2 2

iterative_3x3:
	@main 3 2

iterative_4x4:
	@main 4 2

iterative_5x5:
	@main 5 2

iterative_6x6:
	@main 6 2

iterative_7x7:
	@main 7 2

iterative_8x8:
	@main 8 2

## RECURSIVE
recursive_2x2:
	@main 2 1

recursive_3x3:
	@main 3 1

recursive_4x4:
	@main 4 1

recursive_5x5:
	@main 5 1

recursive_6x6:
	@main 6 1

recursive_7x7:
	@main 7 1

recursive_8x8:
	@main 8 1

clean:
	del /F main.exe
