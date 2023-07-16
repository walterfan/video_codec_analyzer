# Overview

It is for Video Codec Analysis.

* examples
* tools

## compile

```
mkdir build
cd build
cmake ..
make
```

## test

```
// step 1
./udpserver 8888 dump.dat 1000

// step 2
ffmpeg \
    -re \
    -i ../obama_talk.mp4 \
    -an \
    -c:v copy \
    -f rtp \
    -sdp_file video.sdp \
    "rtp://127.0.0.1:5004"

// step 3
./media_parser ../../media/bld/dump.dat |more

```



# Documents

* [H264 Codec](./doc/h264.md)
* [Terminology](./doc/terms.md)
* [Tools](./doc/tools.md)

# Reference
* [H.264-202108.pdf](./refer/H.264-202108.pdf)
* [H264_T.Wiegand.pdf](./refer/H264_T.Wiegand.pdf)
* [rfc6184.pdf](./refer/rfc6184.pdf)
* [av1 spec](https://github.com/AOMediaCodec/av1-spec)
* [av1 RTP spec](https://aomediacodec.github.io/av1-rtp-spec/)

# Libraries
* https://github.com/cisco/openh264
