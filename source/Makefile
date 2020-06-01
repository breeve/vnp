SUB_MOD = lib

all:
	for mode in ${SUB_MOD}; do \
		make -C $$mode; \
	done

clean:
	for mode in ${SUB_MOD}; do \
		make -C $$mode clean; \
	done	