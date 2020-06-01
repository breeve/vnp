SUB_MOD = log

all: install_header dpdk_build
	for mode in ${SUB_MOD}; do make -C $$mode || exit; done;

clean: remove_header dpdk_clean
	for mode in ${SUB_MOD}; do make -C $$mode clean || exit; done;

install_header:
	mkdir -p ${SDN_ROOT}/include/base
	for mode in ${SUB_MOD}; do \
		cp -rf $$mode/include/* ${SDN_ROOT}/include/base 2>/dev/null;\
	done;

remove_header:
	rm -rf ${SDN_ROOT}/include/base

dpdk_build:
	make -C ${RTE_SDK} config T=${RTE_TARGET}
	make -C ${RTE_SDK} install T=${RTE_TARGET}

dpdk_clean:
	make -C ${RTE_SDK} clean