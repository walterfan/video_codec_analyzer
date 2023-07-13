/*
 * VideoStream.cpp
 *
 *  Created on: 2021-3-12
 *      Author: Walter Fan
 */

#include "h264_util.h"
#include <cstdio>
#include <cstddef>
#include <cstdlib>
#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>
#include <boost/assert.hpp>


using namespace std;
using namespace boost::program_options;

const uint32_t BUF_SIZE = 10 * 1024 * 1024;


int GetVideoSize(u32 maxFS) {
    if (maxFS >= (2160*3840)/256) { return 2k;}
    else if (maxFS >= (1080*1920)/256) { return STREAM_1080p;}
    else  if (maxFS >= (720*1280)/256) { return STREAM_720p;}
    else if (maxFS >= (360*640)/256) { return STREAM_360p;}
    else if (maxFS >= (180*320)/256) { return  STREAM_180p;}
    else { return STREAM_90p;}
  }


VideoStream::VideoStream(const std::string& fileName):m_fileName(fileName) {
	// TODO Auto-generated constructor stub

}

VideoStream::~VideoStream() {
	// TODO Auto-generated destructor stub
}

VideoStream::VideoStream(VideoStream &&other) {
	// TODO Auto-generated constructor stub


}

VideoStream& VideoStream::operator=(const VideoStream &other) {
	// TODO Auto-generated method stub
	return *this;

}

VideoStream& VideoStream::operator=(VideoStream &&other) {
	// TODO Auto-generated method stub
	return *this;

}

VideoStream::VideoStream(const VideoStream &other) {
	// TODO Auto-generated constructor stub


}

int h264_demo(const variables_map& vm) {

	NALU_t *n;

	uint8_t* buf = (uint8_t*)malloc( BUF_SIZE );

	if (!vm.count("input")) {
		BOOST_LOG_TRIVIAL(trace) << "error: please specify input_file";
		return -1;
	}

	string input_file = vm["input"].as<string>();
	BOOST_LOG_TRIVIAL(trace) << "read " << input_file;

	FILE *fpInput = NULL;
	FILE *fpOutput = stdout;

	fpInput = fopen(input_file.c_str(), "rb+");
	if (fpInput==NULL){
		printf("Open file error\n");
		return -1;
	}

    size_t rsz = 0;
    size_t sz = 0;
    int64_t off = 0;
    uint8_t* p = buf;
	while(!feof(fpInput)) {
		rsz = fread(buf + sz, 1, BUF_SIZE - sz, fpInput);
        if (rsz == 0)
        {
            if (ferror(fpInput)) { 
				fprintf( stderr, "!! Error: read failed: %s \n", strerror(errno)); 
				break; 
			}
     
        }

        sz += rsz;
		break;
	}

	fclose(fpInput);
	return 0;
}
