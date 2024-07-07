.PHONY: lint
lint:
	@find . -type f -name "*.c" | xargs cpplint
	@echo done linting
