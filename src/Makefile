
default: it

alloc.o: \
default.o.build \
compile \
alloc.c \
alloc.h \
error.h
	sh makefile.build default.o.build alloc.o alloc

alloc_re.o: \
default.o.build \
compile \
alloc_re.c \
alloc.h \
byte.h
	sh makefile.build default.o.build alloc_re.o alloc_re

buffer.o: \
default.o.build \
compile \
buffer.c \
buffer.h
	sh makefile.build default.o.build buffer.o buffer

buffer_2.o: \
default.o.build \
compile \
buffer_2.c \
buffer.h
	sh makefile.build default.o.build buffer_2.o buffer_2

buffer_put.o: \
default.o.build \
compile \
buffer_put.c \
buffer.h \
str.h \
byte.h \
error.h
	sh makefile.build default.o.build buffer_put.o buffer_put

buffer_write.o: \
default.o.build \
compile \
buffer_write.c \
buffer.h
	sh makefile.build default.o.build buffer_write.o buffer_write

byte_copy.o: \
default.o.build \
compile \
byte_copy.c \
byte.h
	sh makefile.build default.o.build byte_copy.o byte_copy

byte_diff.o: \
default.o.build \
compile \
byte_diff.c \
byte.h
	sh makefile.build default.o.build byte_diff.o byte_diff

chkshsgr: \
default.build \
chkshsgr=x \
load \
chkshsgr.o
	sh makefile.build default.build chkshsgr chkshsgr

chkshsgr.o: \
default.o.build \
compile \
chkshsgr.c
	sh makefile.build default.o.build chkshsgr.o chkshsgr

choose: \
default.build \
choose=s \
makeinclude \
makescrip \
warn-auto.sh \
choose.sh
	sh makefile.build default.build choose choose

compile: \
default.build \
conf-cc \
print-compile.sh \
systype \
warn-auto.sh
	sh makefile.build default.build compile compile

env.o: \
default.o.build \
compile \
env.c \
str.h \
env.h
	sh makefile.build default.o.build env.o env

error.o: \
default.o.build \
compile \
error.c \
error.h
	sh makefile.build default.o.build error.o error

error_str.o: \
default.o.build \
compile \
error_str.c \
error.h
	sh makefile.build default.o.build error_str.o error_str

fifo.o: \
default.o.build \
compile \
fifo.c \
hasmkffo.h \
fifo.h
	sh makefile.build default.o.build fifo.o fifo

fmt_ulong.o: \
default.o.build \
compile \
fmt_ulong.c \
fmt.h
	sh makefile.build default.o.build fmt_ulong.o fmt_ulong

hasflock.h: \
hasflock.h.build \
choose \
compile \
load \
tryflock.c \
hasflock.h1 \
hasflock.h2
	sh makefile.build hasflock.h.build hasflock.h 

hasmkffo.h: \
hasmkffo.h.build \
choose \
compile \
load \
trymkffo.c \
hasmkffo.h1 \
hasmkffo.h2
	sh makefile.build hasmkffo.h.build hasmkffo.h 

hassgact.h: \
hassgact.h.build \
choose \
compile \
trysgact.c \
hassgact.h1 \
hassgact.h2
	sh makefile.build hassgact.h.build hassgact.h 

hassgprm.h: \
hassgprm.h.build \
choose \
compile \
trysgprm.c \
hassgprm.h1 \
hassgprm.h2
	sh makefile.build hassgprm.h.build hassgprm.h 

hasshsgr.h: \
hasshsgr.h.build \
choose \
compile \
tryshsgr.c \
hasshsgr.h1 \
hasshsgr.h2 \
chkshsgr \
warn-shsgr
	sh makefile.build hasshsgr.h.build hasshsgr.h 

haswaitp.h: \
haswaitp.h.build \
choose \
compile \
load \
trywaitp.c \
haswaitp.h1 \
haswaitp.h2
	sh makefile.build haswaitp.h.build haswaitp.h 

home: \
home.build
	sh makefile.build home.build home 

iopause.h: \
iopause.h.build \
choose \
compile \
load \
trypoll.c \
iopause.h1 \
iopause.h2
	sh makefile.build iopause.h.build iopause.h 

iopause.o: \
default.o.build \
compile \
iopause.c \
select.h \
uint64.h \
tai.h \
taia.h \
iopause.h
	sh makefile.build default.o.build iopause.o iopause

it: \
default.build \
it=d \
trigger-pull \
trigger-wait \
trigger-listen
	sh makefile.build default.build it it

load: \
default.build \
conf-ld \
print-load.sh \
warn-auto.sh
	sh makefile.build default.build load load

lock_ex.o: \
default.o.build \
compile \
lock_ex.c \
hasflock.h \
lock.h
	sh makefile.build default.o.build lock_ex.o lock_ex

lock_exnb.o: \
default.o.build \
compile \
lock_exnb.c \
hasflock.h \
lock.h
	sh makefile.build default.o.build lock_exnb.o lock_exnb

makeinclude: \
default.build \
makeinclude.sh \
warn-auto.sh
	sh makefile.build default.build makeinclude makeinclude

makelib: \
default.build \
print-ar.sh \
systype \
warn-auto.sh
	sh makefile.build default.build makelib makelib

makescrip: \
default.build \
warn-auto.sh \
print-makescrip.sh \
conf-scrip \
home
	sh makefile.build default.build makescrip makescrip

mkfile: \
default.build \
mkfile=d \
it \
rts
	sh makefile.build default.build mkfile mkfile

ndelay_off.o: \
default.o.build \
compile \
ndelay_off.c \
ndelay.h
	sh makefile.build default.o.build ndelay_off.o ndelay_off

ndelay_on.o: \
default.o.build \
compile \
ndelay_on.c \
ndelay.h
	sh makefile.build default.o.build ndelay_on.o ndelay_on

open_append.o: \
default.o.build \
compile \
open_append.c \
open.h
	sh makefile.build default.o.build open_append.o open_append

open_read.o: \
default.o.build \
compile \
open_read.c \
open.h
	sh makefile.build default.o.build open_read.o open_read

open_write.o: \
default.o.build \
compile \
open_write.c \
open.h
	sh makefile.build default.o.build open_write.o open_write

pathexec_env.o: \
default.o.build \
compile \
pathexec_env.c \
gen_alloc.h \
stralloc.h \
alloc.h \
str.h \
byte.h \
env.h \
pathexec.h
	sh makefile.build default.o.build pathexec_env.o pathexec_env

pathexec_run.o: \
default.o.build \
compile \
pathexec_run.c \
error.h \
gen_alloc.h \
stralloc.h \
str.h \
env.h \
pathexec.h
	sh makefile.build default.o.build pathexec_run.o pathexec_run

prot.o: \
default.o.build \
compile \
prot.c \
hasshsgr.h \
prot.h
	sh makefile.build default.o.build prot.o prot

rts: \
default.build \
rts=d \
it
	sh makefile.build default.build rts rts

scan_uint.o: \
default.o.build \
compile \
scan_uint.c \
scan.h
	sh makefile.build default.o.build scan_uint.o scan_uint

scan_ulong.o: \
default.o.build \
compile \
scan_ulong.c \
scan.h
	sh makefile.build default.o.build scan_ulong.o scan_ulong

select.h: \
select.h.build \
choose \
compile \
trysysel.c \
select.h1 \
select.h2
	sh makefile.build select.h.build select.h 

sgetopt.o: \
default.o.build \
compile \
sgetopt.c \
buffer.h \
sgetopt.h \
subgetopt.h
	sh makefile.build default.o.build sgetopt.o sgetopt

sig.o: \
default.o.build \
compile \
sig.c \
sig.h
	sh makefile.build default.o.build sig.o sig

sig_block.o: \
default.o.build \
compile \
sig_block.c \
sig.h \
hassgprm.h
	sh makefile.build default.o.build sig_block.o sig_block

sig_catch.o: \
default.o.build \
compile \
sig_catch.c \
sig.h \
hassgact.h
	sh makefile.build default.o.build sig_catch.o sig_catch

sig_pause.o: \
default.o.build \
compile \
sig_pause.c \
sig.h \
hassgprm.h
	sh makefile.build default.o.build sig_pause.o sig_pause

str_chr.o: \
default.o.build \
compile \
str_chr.c \
str.h
	sh makefile.build default.o.build str_chr.o str_chr

str_diff.o: \
default.o.build \
compile \
str_diff.c \
str.h
	sh makefile.build default.o.build str_diff.o str_diff

str_len.o: \
default.o.build \
compile \
str_len.c \
str.h
	sh makefile.build default.o.build str_len.o str_len

str_start.o: \
default.o.build \
compile \
str_start.c \
str.h
	sh makefile.build default.o.build str_start.o str_start

stralloc_cat.o: \
default.o.build \
compile \
stralloc_cat.c \
byte.h \
gen_alloc.h \
stralloc.h
	sh makefile.build default.o.build stralloc_cat.o stralloc_cat

stralloc_catb.o: \
default.o.build \
compile \
stralloc_catb.c \
gen_alloc.h \
stralloc.h \
byte.h
	sh makefile.build default.o.build stralloc_catb.o stralloc_catb

stralloc_cats.o: \
default.o.build \
compile \
stralloc_cats.c \
byte.h \
str.h \
gen_alloc.h \
stralloc.h
	sh makefile.build default.o.build stralloc_cats.o stralloc_cats

stralloc_eady.o: \
default.o.build \
compile \
stralloc_eady.c \
alloc.h \
gen_alloc.h \
stralloc.h \
gen_allocdefs.h
	sh makefile.build default.o.build stralloc_eady.o stralloc_eady

stralloc_opyb.o: \
default.o.build \
compile \
stralloc_opyb.c \
gen_alloc.h \
stralloc.h \
byte.h
	sh makefile.build default.o.build stralloc_opyb.o stralloc_opyb

stralloc_opys.o: \
default.o.build \
compile \
stralloc_opys.c \
byte.h \
str.h \
gen_alloc.h \
stralloc.h
	sh makefile.build default.o.build stralloc_opys.o stralloc_opys

stralloc_pend.o: \
default.o.build \
compile \
stralloc_pend.c \
alloc.h \
gen_alloc.h \
stralloc.h \
gen_allocdefs.h
	sh makefile.build default.o.build stralloc_pend.o stralloc_pend

strerr.o: \
default.o.build \
compile \
strerr.c \
gen_alloc.h \
stralloc.h \
strerr.h
	sh makefile.build default.o.build strerr.o strerr

strerr_die.o: \
default.o.build \
compile \
strerr_die.c \
buffer.h \
strerr.h
	sh makefile.build default.o.build strerr_die.o strerr_die

strerr_sys.o: \
default.o.build \
compile \
strerr_sys.c \
error.h \
strerr.h
	sh makefile.build default.o.build strerr_sys.o strerr_sys

subgetopt.o: \
default.o.build \
compile \
subgetopt.c \
subgetopt.h
	sh makefile.build default.o.build subgetopt.o subgetopt

systype: \
default.build \
find-systype.sh \
trycpp.c \
x86cpuid.c
	sh makefile.build default.build systype systype

taia_add.o: \
default.o.build \
compile \
taia_add.c \
uint64.h \
tai.h \
taia.h
	sh makefile.build default.o.build taia_add.o taia_add

taia_approx.o: \
default.o.build \
compile \
taia_approx.c \
uint64.h \
tai.h \
taia.h
	sh makefile.build default.o.build taia_approx.o taia_approx

taia_frac.o: \
default.o.build \
compile \
taia_frac.c \
uint64.h \
tai.h \
taia.h
	sh makefile.build default.o.build taia_frac.o taia_frac

taia_less.o: \
default.o.build \
compile \
taia_less.c \
uint64.h \
tai.h \
taia.h
	sh makefile.build default.o.build taia_less.o taia_less

taia_now.o: \
default.o.build \
compile \
taia_now.c \
uint64.h \
tai.h \
taia.h
	sh makefile.build default.o.build taia_now.o taia_now

taia_sub.o: \
default.o.build \
compile \
taia_sub.c \
uint64.h \
tai.h \
taia.h
	sh makefile.build default.o.build taia_sub.o taia_sub

taia_uint.o: \
default.o.build \
compile \
taia_uint.c \
uint64.h \
tai.h \
taia.h
	sh makefile.build default.o.build taia_uint.o taia_uint

trigger-listen: \
default.build \
trigger-listen=x \
load \
trigger-listen.o \
unix.a
	sh makefile.build default.build trigger-listen trigger-listen

trigger-listen.o: \
default.o.build \
compile \
trigger-listen.c \
str.h \
byte.h \
fmt.h \
scan.h \
exit.h \
prot.h \
open.h \
wait.h \
gen_alloc.h \
stralloc.h \
alloc.h \
buffer.h \
error.h \
strerr.h \
subgetopt.h \
sgetopt.h \
pathexec.h \
sig.h \
uint64.h \
tai.h \
taia.h \
iopause.h \
env.h \
fifo.h \
ndelay.h
	sh makefile.build default.o.build trigger-listen.o trigger-listen

trigger-pull: \
default.build \
trigger-pull=x \
load \
trigger-pull.o \
unix.a
	sh makefile.build default.build trigger-pull trigger-pull

trigger-pull.o: \
default.o.build \
compile \
trigger-pull.c \
strerr.h \
error.h \
ndelay.h \
exit.h \
sig.h \
open.h
	sh makefile.build default.o.build trigger-pull.o trigger-pull

trigger-wait: \
default.build \
trigger-wait=x \
load \
trigger-wait.o \
unix.a
	sh makefile.build default.build trigger-wait trigger-wait

trigger-wait.o: \
default.o.build \
compile \
trigger-wait.c \
strerr.h \
open.h \
exit.h \
ndelay.h \
fifo.h \
iopause.h \
sig.h \
uint64.h \
tai.h \
taia.h \
subgetopt.h \
sgetopt.h \
scan.h \
wait.h \
pathexec.h
	sh makefile.build default.o.build trigger-wait.o trigger-wait

uint64.h: \
uint64.h.build \
choose \
compile \
load \
tryulong64.c \
uint64.h1 \
uint64.h2
	sh makefile.build uint64.h.build uint64.h 

unix.a: \
default.a.build \
unix=l \
makelib \
alloc.o \
alloc_re.o \
buffer.o \
buffer_2.o \
buffer_put.o \
buffer_write.o \
byte_copy.o \
byte_diff.o \
env.o \
error.o \
error_str.o \
fifo.o \
fmt_ulong.o \
iopause.o \
lock_ex.o \
lock_exnb.o \
ndelay_off.o \
ndelay_on.o \
open_append.o \
open_read.o \
open_write.o \
pathexec_env.o \
pathexec_run.o \
prot.o \
scan_uint.o \
scan_ulong.o \
sgetopt.o \
sig.o \
sig_block.o \
sig_catch.o \
sig_pause.o \
str_chr.o \
str_len.o \
str_start.o \
str_diff.o \
stralloc_cat.o \
stralloc_catb.o \
stralloc_cats.o \
stralloc_eady.o \
stralloc_opyb.o \
stralloc_opys.o \
stralloc_pend.o \
strerr.o \
strerr_die.o \
strerr_sys.o \
subgetopt.o \
taia_add.o \
taia_approx.o \
taia_frac.o \
taia_less.o \
taia_now.o \
taia_sub.o \
taia_uint.o \
wait_nohang.o \
wait_pid.o
	sh makefile.build default.a.build unix.a unix

wait_nohang.o: \
default.o.build \
compile \
wait_nohang.c \
haswaitp.h
	sh makefile.build default.o.build wait_nohang.o wait_nohang

wait_pid.o: \
default.o.build \
compile \
wait_pid.c \
error.h \
haswaitp.h
	sh makefile.build default.o.build wait_pid.o wait_pid

clean:
	rm -f \
	alloc.o \
	alloc_re.o \
	buffer.o \
	buffer_2.o \
	buffer_put.o \
	buffer_write.o \
	byte_copy.o \
	byte_diff.o \
	chkshsgr \
	chkshsgr.o \
	choose \
	compile \
	env.o \
	error.o \
	error_str.o \
	fifo.o \
	fmt_ulong.o \
	hasflock.h \
	hasmkffo.h \
	hassgact.h \
	hassgprm.h \
	hasshsgr.h \
	haswaitp.h \
	home \
	iopause.h \
	iopause.o \
	it \
	load \
	lock_ex.o \
	lock_exnb.o \
	makeinclude \
	makelib \
	makescrip \
	mkfile \
	ndelay_off.o \
	ndelay_on.o \
	open_append.o \
	open_read.o \
	open_write.o \
	pathexec_env.o \
	pathexec_run.o \
	prot.o \
	rts \
	scan_uint.o \
	scan_ulong.o \
	select.h \
	sgetopt.o \
	sig.o \
	sig_block.o \
	sig_catch.o \
	sig_pause.o \
	str_chr.o \
	str_diff.o \
	str_len.o \
	str_start.o \
	stralloc_cat.o \
	stralloc_catb.o \
	stralloc_cats.o \
	stralloc_eady.o \
	stralloc_opyb.o \
	stralloc_opys.o \
	stralloc_pend.o \
	strerr.o \
	strerr_die.o \
	strerr_sys.o \
	subgetopt.o \
	systype \
	taia_add.o \
	taia_approx.o \
	taia_frac.o \
	taia_less.o \
	taia_now.o \
	taia_sub.o \
	taia_uint.o \
	trigger-listen \
	trigger-listen.o \
	trigger-pull \
	trigger-pull.o \
	trigger-wait \
	trigger-wait.o \
	uint64.h \
	unix.a \
	wait_nohang.o \
	wait_pid.o
