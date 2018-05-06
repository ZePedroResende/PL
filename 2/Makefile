all: clean
	@mkdir -p build/
	@echo "\033[0;31mBuilding binaries...\033[0m"
	@$(MAKE) -C src/um
	@echo "\033[0;32mExercise 1 DONE!\033[0m"
	@$(MAKE) -C src/dois
	@echo "\033[0;32mExercise 2 DONE!\033[0m"
	@$(MAKE) -C src/tres
	@echo "\033[0;32mExercise 3 DONE!\033[0m"
	@$(MAKE) -C src/quatro
	@echo "\033[0;32mExercise 4 DONE!\033[0m"
	@echo "\033[0;31mPreparing files...\033[0m"
	@wget https://github.com/p3rsephone/testDownload/archive/0.2.tar.gz >/dev/null 2>&1
	@tar -xvzf 0.2.tar.gz >/dev/null 2>&1
	@mv testDownload-0.2/html assets
	@rm -rf 0.2.tar.gz testDownload-0.2/ >/dev/null 2>&1
	@echo "\033[0;32mDone!\033[0m"

exec:
	@echo "\033[0;31mBuilding binaries...\033[0m"
	@mkdir -p build/
	@$(MAKE) -C src/um >/dev/null 2>&1
	@echo "\033[0;32mExercise 1 DONE!"
	@$(MAKE) -C src/dois >/dev/null 2>&1
	@echo "Exercise 2 DONE!"
	@$(MAKE) -C src/tres >/dev/null 2>&1
	@echo "Exercise 3 DONE!"
	@$(MAKE) -C src/quatro >/dev/null 2>&1
	@echo "Exercise 4 DONE!"
	@echo "All done!\033[0m"

clean:
	@echo "\033[0;31mCleaning...\033[0m"
	@rm -rf build/ assets/ 0.1.tar.gz html/ >/dev/null 2>&1
	@$(MAKE) -C src/um clean	>/dev/null 2>&1
	@$(MAKE) -C src/dois clean >/dev/null 2>&1
	@$(MAKE) -C src/tres clean >/dev/null 2>&1
	@$(MAKE) -C src/quatro clean >/dev/null 2>&1
