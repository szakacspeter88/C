/*
This C source plays a Beep Sound on Linux using ALSA

1. Install Prerequisites
sudo pacman -S alsa-lib pipewire-alsa

2. Compile the Source
gcc beep.c -o beep -lasound -lm

3. Execute it:
./beep
*/

#include <alsa/asoundlib.h>
#include <math.h>
#include <stdio.h>

#define PCM_DEVICE "default"
#define SAMPLE_RATE 44100
#define DURATION_SEC 1
#define FREQ_HZ 440.0   // A4 note
#define VOLUME 0.5      // 0.0 to 1.0

int main() {
    snd_pcm_t *pcm_handle;
    int err;
    int pcm;

    // 1. Open the PCM device in playback mode
    if ((err = snd_pcm_open(&pcm_handle, PCM_DEVICE, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        fprintf(stderr, "ERROR: Can't open \"%s\" PCM device. %s\n",
                PCM_DEVICE, snd_strerror(err));
        return 1;
    }

    // 2. Set parameters: S16_LE (standard 16-bit), 1 channel (mono), 44100Hz
    // The last parameter is latency in microseconds (0.5s here)
    if ((err = snd_pcm_set_params(pcm_handle,
                                  SND_PCM_FORMAT_S16_LE,
                                  SND_PCM_ACCESS_RW_INTERLEAVED,
                                  1,
                                  SAMPLE_RATE,
                                  1,
                                  500000)) < 0) {
        fprintf(stderr, "ERROR: Can't set parameters. %s\n", snd_strerror(err));
        return 1;
    }

    // 3. Generate the Sine Wave Buffer
    int total_frames = SAMPLE_RATE * DURATION_SEC;
    short *buffer = (short *)malloc(total_frames * sizeof(short));

    if (!buffer) {
        fprintf(stderr, "ERROR: Not enough memory\n");
        return 1;
    }

    for (int i = 0; i < total_frames; i++) {
        // Generate sine wave: amplitude * sin(2 * PI * freq * time)
        // We scale to 32000 (near max of 16-bit signed integer which is 32767)
        double sample = sin(2.0 * M_PI * FREQ_HZ * ((double)i / SAMPLE_RATE));
        buffer[i] = (short)(sample * 32000 * VOLUME);
    }

    // 4. Write the audio data to the device
    printf("Playing %d Hz beep for %d second...\n", (int)FREQ_HZ, DURATION_SEC);
    pcm = snd_pcm_writei(pcm_handle, buffer, total_frames);

    if (pcm == -EPIPE) {
        printf("Underrun occurred\n");
        snd_pcm_prepare(pcm_handle);
    } else if (pcm < 0) {
        printf("ERROR. Can't write to PCM device. %s\n", snd_strerror(pcm));
    }

    // 5. Clean up
    snd_pcm_drain(pcm_handle); // Wait for playback to finish
    snd_pcm_close(pcm_handle);
    free(buffer);

    return 0;
}
