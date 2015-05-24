# Installation #

Many Linux distributions include amsynth in their package repositories. This is definitely the easiest way to get up and running, although probably will not get you the latest version of amsynth.

For those of you running Ubuntu, you can get more recent builds of amsynth though the [amsynth PPA](https://launchpad.net/~nick-nickdowell/+archive/amsynth-master-daily) or the [KXStudio PPA](https://launchpad.net/~kxstudio-team/+archive/plugins).

For those of you who are a little more adventurous, I would recommend [building and installing amsynth from source](BuildingFromSource.md).


# Running #

## Requirements ##

In order to get the best from amsynth you will need a **MIDI keyboard** of some description. The most convenient choice is probably a keyboard with a built-in USB-MIDI interface, but make sure it's Linux compatible!

## Running amsynth with JACK ##

I would strongly recommend using amsynth in combination with the **[JACK audio system](http://jackaudio.org/)**. While it can be slightly more confusing to newcomers, it offers the best performance and ability to run music application side-by-side.

In this example I will be using [QJackCtl](http://qjackctl.sourceforge.net/) to control JACK, as it makes things easier.

### 1. Start the JACK audio server ###

> - Run **`qjackctl`** from the command line, or from your applications menu.

> - Press the **Setup** button and check that it is using the correct audio device. Also check that "MIDI Driver" is set to **`seq`**.

> - Press the **Start** button. If there is an error message, then check your configuration.

![http://wiki.amsynth.googlecode.com/git/amsynth_jack_step1.png](http://wiki.amsynth.googlecode.com/git/amsynth_jack_step1.png)

### 2. Start amsynth ###

> - Run **`amsynth`** from the command line, or from your application menu.

### 3. Test audio output ###

> - Press and hold amsynth's **Audition** button. You should hear some sound.

> - If you cannot hear any sound, try running **`jack_simple_client`** from the command line. If you can't hear anything, then

### 4. Connect MIDI ###

> - Press the **Connect** button in QJackCtl

> - Select the **MIDI** tab

> - **Connect** `system:midi_capture_X` to `amsynth:midi_in`. Note that MIDI messages from your device may not arrive on the first midi\_capture port, so try them one by one.

> - Play some notes on your keyboard, and you should hear some sound! If not, then go back a step and try connecting any other MIDI capture ports available on your system.

![http://wiki.amsynth.googlecode.com/git/amsynth_jack_step2.png](http://wiki.amsynth.googlecode.com/git/amsynth_jack_step2.png)