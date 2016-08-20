all:
	make -C minizip
	make -C pcre-8.20
	make -C libxml2-2.7.8
	make -C boost_1_47_0
	make -C collada-dom-2.3.1/dom

clean:
	make -C minizip clean
	make -C pcre-8.20 clean
	make -C libxml2-2.7.8 clean
	make -C boost_1_47_0 clean
	make -C collada-dom-2.3.1/dom clean
