# FAQs #



&lt;hr&gt;



## Help - I can't hear any sound! ##

See [Getting Started](QuickStartGuide.md)

## Why doesn't the "Virtual Keyboard" menu item work? ##

This menu item launches an external program called **`vkeybd`** - please make sure `vkeybd` is installed.

Additionally, this functionality **requires ALSA MIDI**, so is not available if configured to use OSS MIDI.

If you can run `vkeybd` from the command line, amsynth is using ALSA MIDI, but the menu item is still disabled or does nothing; then you have found a bug! Please [report it](http://code.google.com/p/amsynth/issues/).

## Can I run amsynth without the GUI? ##

**Yes!**

You can run the amsynth DSSI or LV2 plug-in from a command-line host program like `jack-dssi-host` or `jalv`.

With the latest code, you can also run the amsynth application in a GUI-less mode, like so:

```
$ AMSYNTH_NO_GUI=1 amsynth
```

## Qtractor crashes when I try to open the amsynth LV2 plug-in ##

Please update to the latest version of the `suil` library