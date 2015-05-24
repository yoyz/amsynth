> # Building from source #

## Prerequisites ##

In order to successfully compile amsynth you will need the following development packages installed:
  * GTK 2.20.0 or later
  * gtkmm 2.6.0 or later
  * liblo and DSSI (optional)
  * JACK (optional) for audio output
  * ALSA (optional) for midi & audio
  * LASH (optional)
  * libsndfile (optional) for the .WAV file output ability

On debian-based systems, you can install the required packages with the following command:
```
sudo apt-get install autoconf automake libtool pkg-config libgtk2.0-dev libgtkmm-2.4-dev libjack-jackd2-dev libasound-dev liblash-compat-dev dssi-dev liblo-dev libsndfile-dev
```

## Build & Install ##

```
tar -xzvf amsynth-1.4.0.tar.gz
cd amsynth-1.4.0
./configure
make
sudo make install
```

## Build & Install from Git repository ##

```
git clone https://code.google.com/p/amsynth/
cd amsynth
./autogen.sh
./configure
make
sudo make install
```


---


## Build on Mac OS X ##

First, install gtkmm and other dependencies using [homebrew](http://brew.sh/)

```
PKG_CONFIG_PATH=/opt/X11/lib/pkgconfig ./configure --with-lv2=no CFLAGS='-g -O0' LDFLAGS='-framework CoreFoundation -framework CoreAudio -framework CoreMIDI'
```