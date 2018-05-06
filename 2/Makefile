all: clean
	@mkdir -p build/
	@echo "Building binaries..."
	@$(MAKE) -C src/um
	@echo "Exercise 1 DONE!"
	@$(MAKE) -C src/dois
	@echo "Exercise 2 DONE!"
	@$(MAKE) -C src/quatro
	@echo "Exercise 4 DONE!"
	@echo "Preparing files..."
	@wget https://github.com/p3rsephone/testDownload/archive/0.1.tar.gz >/dev/null 2>&1
	@tar -xvzf 0.1.tar.gz >/dev/null 2>&1
	@mv testDownload-0.1/html assets
	@rm -rf 0.1.tar.gz testDownload-0.1/ >/dev/null 2>&1
	@echo "Done!"

exec:
	@echo "Building binaries..."
	@mkdir -p build/
	@$(MAKE) -C src/um >/dev/null 2>&1
	@echo "Exercise 1 DONE!"
	@$(MAKE) -C src/dois >/dev/null 2>&1
	@echo "Exercise 2 DONE!"
	@$(MAKE) -C src/quatro >/dev/null 2>&1
	@echo "Exercise 4 DONE!"
	@echo "All done!"

clean:
	@echo "Cleaning..."
	@rm -rf build/ assets/ 0.1.tar.gz html/ >/dev/null 2>&1
	@$(MAKE) -C src/um clean	>/dev/null 2>&1
	@$(MAKE) -C src/dois clean >/dev/null 2>&1
	@$(MAKE) -C src/quatro clean >/dev/null 2>&1