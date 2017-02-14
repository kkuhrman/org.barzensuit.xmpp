# org.barzensuit.xmpp

# Installation Defaults

autotools will install libraries in /usr/local/lib and programs in /usr/local/bin
by default. This should go without saying (but the frequency of posts relating to 
"cannot open shared object file: No such file or directory" indicates otherwise):
It may be necessary to add your installation dir to your PATH:

e.g. [#] PATH=$PATH:/usr/local/bin

It may also be necessary to rebuild your shared object cache with ldconfig:

e.g. [#] sudo ldconfig /usr/local/lib

(@see man ldconfig for more on ldconfig)