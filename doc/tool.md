# Overview

# Tester

## RTP packets dump from UDP port

1. mkdir bld; cmake ..; make;

2. ./udpserver

3. ffmpeg -re -i ../../material/sintel.ts -f rtp_mpegts udp://127.0.0.1:8880


# Some commands

ffmpeg -i digits_3600.mp4 -an -vcodec libx264 -crf 23 digits_3600.h264
ffmpeg -i digits_3600.264 -f rtp -vcodec libx264 rtp://10.140.202.208:15000

```
m=video 15000 RTP/AVP 96
a=rtpmap:96 H264
a=framerate:25
c=IN IP4 10.102.7.194
```

ffmpeg -f dshow -i video="Lenovo EasyCamera" -vcodec libx264 -preset:v ultrafast -tune:v zerolatency -f rtp rtp://10.140.202.208:6666>sd.sdp



# Tools

* gstreamer
* ffmpeg
* captool
* rtptool

## library

* boost
* libsrtp
* libavcodec
* lua

```
curl -R -O http://www.lua.org/ftp/lua-5.4.3.tar.gz
tar zxf lua-5.4.3.tar.gz
cd lua-5.4.3
make all test
```

## FAQ

### How to dedode mp4 or avi to yuv

```
ffmpeg -i input.mp4 -c:v rawvideo -pix_fmt yuv420p output.yuv
ffmpeg -i input.avi -c:v rawvideo -pixel_format yuv420p output.yuv
```

### How to cature packets from ip1:port1 to ip2:port2

```
tcpdump -i en0 src host 192.168.1.27 and src port 10000 and dst host 192.168.1.28 and dst port 20000 -w today.pcap
```

### How to push rtp stream to socket from ts file

```
ffmpeg -re -i ../../material/sintel.ts -f rtp_mpegts udp://127.0.0.1:8880

```
### How to push rtp stream from mp4 file

```
ffmpeg \
    -re \
    -i ../../obama_talk.mp4 \
    -an \
    -c:v copy \
    -f rtp \
    -sdp_file video.sdp \
    "rtp://127.0.0.1:5004"
```


### How to concat several wav files to one?

* Method 1:

It's the recommended method

```
ffmpeg -f concat -i mylist.txt -c copy output.wav 
```

mylist.txt:

```
file 'a1.wav'
file 'a2.wav'
```

* Method 2:


```
ffmpeg -i a1.wav -i a2.wav -filter_complex '[0:0][1:0]concat=n=2:v=0:a=1[out]' -map '[out]' a1_a2.wav

```


### How to conver avi to wav

```
ffmpeg -i 1secs_output.avi -vn -acodec pcm_s16le -ar 8000 -ac 1 1secs_output.wav

```

### How to draw a text on a video file
```
ffmpeg -i "a1.mp4" -vf drawtext="fontfile=xxx.ttf: text=Hello World: \
fontcolor=black: fontsize=40: x=10: y=10" -codec:a copy -y "a2.mp4"
```


# ffmpeg usage
## show frames of video file

```
ffprobe -v error -show_frames input.mp4

ffprobe -v error -show_frames ../../material/obama_talk.mp4
```

## count frame of video file

```
ffprobe -v error -count_frames -select_streams v:0 -show_entries stream=nb_frames -of default=nokey=1:noprint_wrappers=1 ../../material/obama_talk.mp4

1269
```

ffprobe -v error -skip_frame nokey -select_streams v:0 -show_entries frame=pkt_pts_time -of csv=print_section=0 ../../material/obama_talk.mp4

## check keyframes of video file

```
ffprobe -v error -show_frames ../../material/obama_talk.mp4 | grep pict_type

ffprobe -v error -select_streams v -show_frames -show_entries frame=pict_type -of csv ../../material/obama_talk.mp4 | grep -n I | cut -d ':' -f 1
```

## covert mp4 to 264 by ffmpeg

```
ffmpeg -i input.mp4 -codec copy -bsf: h264_mp4toannexb -f h264 output.h264
```

e.g.

```
ffmpeg -i ../../material/obama_talk.mp4 -codec copy -bsf: h264_mp4toannexb -f h264 ../../material/obama_talk.h264
```

# codes

```
import binascii
with open('../../material/obama_talk.mp4', 'rb') as fin:
    hexa = binascii.hexlify(fin.read())
    print(hexa[0:1000])
```

# reference
* https://trac.ffmpeg.org/wiki/Encode/H.264
* https://gstreamer.freedesktop.org/documentation/gst-plugins-bad-codecparsers/gsth264parser.html
* https://github.com/leixiaohua1020/h264_analysis
* https://mp.weixin.qq.com/s/LMQKMyt8q4fkittRPSoCaA
* https://github.com/Gosivn/H264Analysis
* https://github.com/halochou/py-h264-decoder
* https://github.com/slhck/h26x-extractor
* https://blog.csdn.net/weixin_41910694/article/details/107661624