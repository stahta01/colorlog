SHELL:=/bin/bash
prefix=/usr/local

prog:
	-rm -rf build
	-mkdir build
	@cd build ;\
	cmake .. ;\
	make ;

install: prog
	install -m 0755 build/colorlog $(prefix)/bin

clean:
	-rm -rfv build/
	-rm -fv $(shell find . | grep ~$$)