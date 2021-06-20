# My miscellaneous scripts

C projects can be compiled with
```
gcc -O3 -o <file> <file>.c
```

## uhex.c and hex.c

Convert text to hexadecimal character codes

uhex.c is a simple implementation of UTF-8 as described in [Wikipedia](https://en.wikipedia.org/wiki/UTF-8#Encoding).
hex.c ignores unicode and just converts bytes.

Both take input from STDIN and output to STDOUT. There are no command line options. Usage example:

```
echo üäö |./uhex
```

Warning: there is absolutely no error checking, all kinds of problems are possible with incorrect input. I recommend using proper libraries for bigger projects.

## dmenu_steam

dmenu_steam is a bash script that can be used to launch Steam games without opening your Steam library. You can bind it to a hotkey in your window manager of choice.

Dependencies: steam (of course), [dmenu](https://tools.suckless.org/dmenu/) and [steamcmd](https://developer.valvesoftware.com/wiki/SteamCMD)

Steamcmd is somewhat inconsistent, and might freeze. When that happens, killall steamcmd, start steam normally to make sure it is updated and try again.

## ffwebcam

Stream local videos, online videos with youtube-dl or even streams to virtual webcam and microphone devices. Tested with Discord, but should in theory work with other applications like Zoom or Teams as well.

### Dependencies:

- ffmpeg
- v4l2loopback kernel module
- youtube-dl (optional)

### You most likely already have these: 

- pulseaudio and pactl
- sudo

### Usage: 

```
ffwebcam <video file or url>
```

ffwebcam has to be started from a terminal, because you have to give your password in order to load v4l2loopback. Do NOT run ffwebcam itself with sudo.

After you have started it, go to Discord or whatever you are using, and select the virtual webcam ("Dummy video device") and the virtual microphone ("Unix FIFO source").

If nothing is reading from the virtual microphone, ffmpeg might freeze. This is normal, and it will continue working normally as soon as something starts reading from it. While it's frozen, you can force quit it by pressing CTRL+C four times.

