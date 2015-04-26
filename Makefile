all :
	$(MAKE) -C src it
	$(MAKE) -C doc it

clean :
	$(MAKE) -C src clean
	$(MAKE) -C doc clean

install :
	package/install

dist :
	sh src/tarsource.sh

