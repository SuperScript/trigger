
default: it

attribute.conf: \
attribute.conf.build \
../package/name \
../package/path \
../package/versions
	sh makefile.build attribute.conf.build attribute.conf 

develop.html: \
default.html.build \
develop.txt \
asciidoc.conf \
webpage.conf \
attribute.conf
	sh makefile.build default.html.build develop.html develop

index.html: \
default.html.build \
index.txt \
asciidoc.conf \
webpage.conf \
attribute.conf
	sh makefile.build default.html.build index.html index

install.html: \
default.html.build \
install.txt \
asciidoc.conf \
webpage.conf \
attribute.conf
	sh makefile.build default.html.build install.html install

it: \
default.build \
it=d \
index.html \
install.html \
trigger-listen.html \
trigger-pull.html \
trigger-wait.html \
trigger-listen.1 \
trigger-pull.1 \
trigger-wait.1 \
develop.html \
asciidoc.css
	sh makefile.build default.build it it

mkfile: \
default.build \
mkfile=d \
it
	sh makefile.build default.build mkfile mkfile

trigger-listen.html: \
default.html.build \
trigger-listen.txt \
asciidoc.conf \
webpage.conf \
attribute.conf
	sh makefile.build default.html.build trigger-listen.html trigger-listen

trigger-pull.html: \
default.html.build \
trigger-pull.txt \
asciidoc.conf \
webpage.conf \
attribute.conf
	sh makefile.build default.html.build trigger-pull.html trigger-pull

trigger-wait.html: \
default.html.build \
trigger-wait.txt \
asciidoc.conf \
webpage.conf \
attribute.conf
	sh makefile.build default.html.build trigger-wait.html trigger-wait

trigger-listen.1: trigger-listen.txt
	sh makefile.build default.1.build trigger-listen.1 trigger-listen

trigger-pull.1: trigger-pull.txt
	sh makefile.build default.1.build trigger-pull.1 trigger-pull

trigger-wait.1: trigger-wait.txt
	sh makefile.build default.1.build trigger-wait.1 trigger-wait

clean:
	rm -f \
	attribute.conf \
	develop.html \
	index.html \
	install.html \
	it \
	mkfile \
	trigger-listen.html \
	trigger-pull.html \
	trigger-wait.html \
	trigger-listen.1 \
	trigger-pull.1 \
	trigger-wait.1
