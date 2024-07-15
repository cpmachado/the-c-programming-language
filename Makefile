.PHONY: lint build-all clean-all
DIRS = ch1 ch2 ch3 ch4

# ch5 ch6 ch7 ch8

lint:
	@find . -type f -name "*.c" | xargs cpplint
	@echo done linting

build-all:
	@$(foreach dir, $(DIRS), make -C $(dir);)

clean-all:
	@$(foreach dir, $(DIRS), make -C $(dir) clean;)
