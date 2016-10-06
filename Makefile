THIS_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

SAMPLE_DIRS := $(shell find  $(THIS_DIR) -mindepth 1 -maxdepth 1 -type d)

all:

define SAMPLE_TEMPLATE

ifeq ($(wildcard $(1)/Makefile),)

$(2): $(1)/$(2)

$(2)_clean:
	rm -f $(1)/$(2) $(1)/*.o $(1)/*.d

$(2)_OBJS := $$(patsubst %.c,%.o,$$(wildcard $(1)/*.c))

$(2)_CFLAGS := $(shell find $(1) -name CFLAGS -exec cat {} \;)

$(1)/%.o: $(1)/%.c
	$$(CC) -MD $$(CFLAGS) $$($(2)_CFLAGS) -o $$@ -c $$< 

$(1)/$2: $$($(2)_OBJS)
	$$(CC) -o $$@ $$<

-include $(1)/*.d

else

$(2):
	$(MAKE) -C $(1)

$(2)_clean:
	$(MAKE) -C $(1) clean

endif

.PHONY: $(2) $(2)_clean

all: $(2)
clean: $(2)_clean

endef

$(foreach d, $(SAMPLE_DIRS), \
	$(eval $(call SAMPLE_TEMPLATE,$(d),$(notdir $(d)))))
