#!/bin/bash

function testOptions()
{
	echo "[+] testing configuration: $1"
	./configure $1 1>/dev/null && make distcheck 1>/dev/null
	if [ $? -ne 0 ]; then
		echo "************************************************";
		echo ""
		echo "build failed with these options:";
		echo "    $1"
		echo ""
		echo "************************************************";
		exit 1;
	fi
}

testOptions "--with-jack=no  --with-alsa=no  --with-sndfile=no  --with-oss=no"
testOptions "--with-jack=yes --with-alsa=no  --with-sndfile=no  --with-oss=no"
testOptions "--with-jack=no  --with-alsa=yes --with-sndfile=no  --with-oss=no"
testOptions "--with-jack=no  --with-alsa=no  --with-sndfile=yes --with-oss=no"
testOptions "--with-jack=no  --with-alsa=no  --with-sndfile=no  --with-oss=yes"
testOptions "--with-jack=yes --with-alsa=yes --with-sndfile=yes --with-oss=yes --with-lash=no"
testOptions "--enable-realtime"

echo "****"
echo "**** Looks good!"
echo "****"

