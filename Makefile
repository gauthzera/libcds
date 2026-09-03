libcds.a: build/cds_vector.o build/cds_list.o build/cds_queue.o build/cds_stack.o build/cds_hash.o build/cds_bst.o build/cds_avl.o build/cds_trie.o
	ar rcs libcds.a build/cds_vector.o build/cds_list.o build/cds_queue.o build/cds_stack.o build/cds_hash.o build/cds_bst.o build/cds_avl.o build/cds_trie.o

build:
	mkdir -p build

build/cds_vector.o: include/cds_vector.h src/cds_vector.c | build
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/cds_vector.c -o build/cds_vector.o

build/cds_list.o: include/cds_list.h src/cds_list.c | build
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/cds_list.c -o build/cds_list.o

build/cds_queue.o: include/cds_queue.h src/cds_queue.c | build
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/cds_queue.c -o build/cds_queue.o

build/cds_stack.o: include/cds_stack.h src/cds_stack.c | build
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/cds_stack.c -o build/cds_stack.o

build/cds_hash.o: include/cds_hash.h src/cds_hash.c | build
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/cds_hash.c -o build/cds_hash.o

build/cds_bst.o: include/cds_bst.h src/cds_bst.c | build
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/cds_bst.c -o build/cds_bst.o

build/cds_avl.o: include/cds_avl.h src/cds_avl.c | build
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/cds_avl.c -o build/cds_avl.o

build/cds_trie.o: include/cds_trie.h src/cds_trie.c | build
	gcc -Wall -Wextra -Wpedantic -Iinclude -c src/cds_trie.c -o build/cds_trie.o

clean:
	rm -rf build libcds.a

.PHONY: clean