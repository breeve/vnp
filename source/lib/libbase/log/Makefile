# SPDX-License-Identifier: BSD-3-Clause
# Copyright(c) 2010-2014 Intel Corporation

include $(RTE_SDK)/mk/rte.vars.mk

SDN_BASE_LIB_LOG=y

# library name
LIB = liblog.so

CFLAGS += -O2 -g
CFLAGS += -I${SDN_ROOT}/include/

# all source are stored in SRCS-y
SRCS-$(SDN_BASE_LIB_LOG) += log.c

include $(RTE_SDK)/mk/rte.extlib.mk
