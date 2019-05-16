#define FS 48000
#define SMPL_BFR_SIZE 1024

#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <al.h>
#include <alc.h>
#include <windows.h>


#pragma comment(lib, "OpenAL32.lib")

int main() {
	//åƒÇ—èoÇµ
	ALCdevice* device = alcOpenDevice(nullptr);
	ALCcontext* context = alcCreateContext(device,nullptr);
	alcMakeContextCurrent(context);
	
	//ò^âπåƒÇ—èoÇµ
	ALCdevice* capture_device = alcCaptureOpenDevice(nullptr,FS,AL_FORMAT_MONO16,SMPL_BFR_SIZE);
	float rec_cnt = 0;
	int rec_sec = 0;
	std::vector<ALshort> rec_data;

	//ò^âπäJén
	std::system("PAUSE");
	std::cout << "start rec!" << std::endl;
	alcCaptureStart(capture_device);

	while (TRUE) {
		ALint sample;
		alcGetIntegerv(capture_device, ALC_CAPTURE_SAMPLES, sizeof(sample), &sample);
		std::vector<ALshort> buffer(sample);
 		if (sample > 0) {;
			alcCaptureSamples(capture_device, (ALCvoid*)&buffer[0], sample);
			for(int s = 0; s < sample; s++){
				rec_data.push_back(buffer[s]);
			}
			if(GetAsyncKeyState(VK_SPACE)){
				for (int s = 0; s < sample; s++) {
					rec_data.push_back(buffer[s]);
				}
				break;
			}
		}
	}
	// ò^âÊí‚é~
	alcCaptureStop(capture_device);
	std::cout << "Stop Rec" << std::endl;

	std::ofstream opf("rec.txt");

	for (int i=0; i < rec_data.size();i++) {
		opf << rec_data[i];
		opf << "\n";
	}
	opf.close();

	rec_sec = (rec_data.size() / FS)*1000;

	ALuint buffer_id;
	alGenBuffers(1, &buffer_id);

	ALuint source_id;
	alGenSources(1, &source_id);


	alBufferData(
		buffer_id,
		AL_FORMAT_MONO16,
		&rec_data[0],
		rec_data.size()*sizeof(ALshort),
		FS
		);


	alSourcei(source_id,AL_BUFFER,buffer_id);
	//çƒê∂
	std::cout << "âΩÇ©ÉLÅ[ÇâüÇ∑Ç∆ò^âπÇµÇΩÇ‡ÇÃÇçƒê∂ÇµÇ‹Ç∑ÅD" << std::endl;
	system("PAUSE");
	
	alSourcePlay(source_id);
	std::this_thread::sleep_for(std::chrono::milliseconds(rec_sec));
	std::cout << "Fin!" << std::endl;
	

	//
	alDeleteSources(1,&source_id);
	alDeleteBuffers(1,&buffer_id);

	//OpenAL
	alcCaptureCloseDevice(capture_device);
	alcCloseDevice(device);
}