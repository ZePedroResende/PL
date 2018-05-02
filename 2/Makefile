all: 
	$(MAKE) -C src
	@echo "Preparing files..."
	@mkdir -p build/
	@wget https://github.com/p3rsephone/testDownload/archive/0.1.tar.gz >/dev/null 2>&1
	@tar -xvzf 0.1.tar.gz >/dev/null 2>&1
	@mv testDownload-0.1/html .
	@rm -rf 0.1.tar.gz testDownload-0.1/
	@echo "Done!"

clean:
	@rm -rf build/ html/ 0.1.tar.gz
