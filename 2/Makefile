all: clean
	@mkdir -p build/
	$(MAKE) -C src/um
	$(MAKE) -C src/dois
	@echo "Preparing files..."
	@wget https://github.com/p3rsephone/testDownload/archive/0.1.tar.gz >/dev/null 2>&1
	@tar -xvzf 0.1.tar.gz >/dev/null 2>&1
	@mv testDownload-0.1/html assets
	@rm -rf 0.1.tar.gz testDownload-0.1/
	@echo "Done!"

exec:
	@mkdir -p build/
	$(MAKE) -C src/um
	$(MAKE) -C src/dois

clean:
	@rm -rf build/ assets/ 0.1.tar.gz html/
	$(MAKE) -C src/um clean	
	$(MAKE) -C src/dois clean
