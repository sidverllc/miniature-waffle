#pragma once
#define _USE_MATH_DEFINES
#include <Windows.h>
#include <mmeapi.h>
#include <math.h>

#pragma comment(lib, "Winmm.lib")

#define _SAMPLES 44100
#define _FREQUENCY 523.25

class GenSound
{
public:
	void play();
private:
};

void GenSound::play() {
	WAVEFORMATEX* t = new WAVEFORMATEX();
	t->wFormatTag = WAVE_FORMAT_PCM;
	t->nChannels = 1;
	t->nSamplesPerSec = _SAMPLES;
	t->nAvgBytesPerSec = _SAMPLES;
	t->nBlockAlign = 1;
	t->wBitsPerSample = 8;
	t->cbSize = 0;

	HWAVEOUT wOut;

	MMRESULT result = waveOutOpen(&wOut, WAVE_MAPPER, t, NULL, NULL, CALLBACK_NULL);
	delete t;

	char* pBuffer = new char[44100]();




	WAVEHDR* pWavHeader = new WAVEHDR();
	pWavHeader->dwBufferLength = _SAMPLES;
	pWavHeader->dwFlags = WHDR_BEGINLOOP;
	pWavHeader->lpData = pBuffer;

	double angle = 0.0;

	result = waveOutPrepareHeader(wOut, pWavHeader, sizeof(WAVEHDR));
	for (int z = 0; z < 10000; z++) {
		int x = 0;
		for (int i = 0; i < _SAMPLES; i++) {
			pBuffer[i] = (char)(sin(angle) * 50.0);
			angle = angle + (((2.0 * M_PI) * _FREQUENCY) / _SAMPLES);

		}

		result = waveOutWrite(wOut, pWavHeader, sizeof(WAVEHDR));
	}
	result = waveOutClose(wOut);

	delete[] pBuffer;
	delete pWavHeader;
}

