* I-Frame:  Info frame关键信息帧
 - IDR: Instant Decoder Refresh frames  一个要在包内传输的帧, 1st I frame
 - GDR: Gradual Decoder Refresh frames 可分割更小的帧以更小的时间间隔发送
 - LTRP: Long-Term Reference Picture frames 可供长期参考校正的帧

* P-Frame: Predictive Frames 预测帧

* B-Frame: Bidirectional Predictive Frames 双向预测帧

* SEI (Supplemental Enhancement Information)
补充增强信息”，提供了向视频码流中加入额外信息的方法。

* SPS(Sequence Parameter Set)
序列参数集”。SPS中保存了一组编码视频序列(Coded Video Sequence)的全局参数。因此该类型保存的是和编码序列相关的参数。

* PPS (Picture Parameter Set)
图像参数集”。该类型保存了整体图像相关的参数。

* AU(Access Unit):
访问单元，它是一个或者多个NALU的集合，代表了一个完整的帧。

* GOP – Group of Pictures
A group of pictures (GOP) comprises a successive set of pictures which starts with a key picture
