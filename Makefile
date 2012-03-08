# -*- mode: makefile; coding: utf-8 -*-

all %:
	make -C src $@

clean:
	@-dh_clean
