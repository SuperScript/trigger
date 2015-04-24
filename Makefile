all :
	$(MAKE) -C src it

clean :
	$(MAKE) -C src clean

install :
	package/install

dist :
	sh src/tarsource.sh

