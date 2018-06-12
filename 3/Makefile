all:
	@cd src/ > /dev/null 2>&1
	@$(MAKE) -C src/
	@cd ../ > /dev/null 2>&1
	@echo "\033[0;31mPreparing files...\033[0m"
	@wget https://github.com/p3rsephone/testDownload/archive/0.2.tar.gz >/dev/null 2>&1
	@tar -xvzf 0.2.tar.gz >/dev/null 2>&1
	@mv testDownload-0.2/html assets
	@rm -rf 0.2.tar.gz testDownload-0.2/ >/dev/null 2>&1
	@echo "\033[0;32mDone!\033[0m"

clean:
	@echo "\033[0;31mCleaning...\033[0m"
	@rm -rf assets/ 0.2.tar.gz >/dev/null 2>&1
	@$(MAKE) -C src/ clean
