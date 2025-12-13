/*

This C Program plays a Beep Sound on Linux, using Pipewire

1. Install Prerequisites:
sudo pacman -S pipewire pkgconf base-devel

2. Compile the Source:
gcc -o beep beep.c $(pkg-config --cflags --libs libpipewire-0.3) -lm

3. Run the Program:
./beep

*/

#include <pipewire/pipewire.h>
#include <spa/param/audio/format-utils.h>
#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846
#define DEFAULT_RATE 44100
#define DEFAULT_CHANNELS 2
#define BEEP_FREQ 440.0
#define VOLUME 0.5

// A struct to hold the state of our sound generation
struct data {
    struct pw_main_loop *loop;
    struct pw_stream *stream;
    double accumulator; // Tracks the phase of the sine wave
    int samples_played;
    int max_samples;
};

// This callback runs whenever PipeWire needs more audio data
static void on_process(void *userdata) {
    struct data *d = userdata;
    struct pw_buffer *b;
    struct spa_buffer *buf;
    float *dst;
    int n_frames, stride;

    // 1. Dequeue a buffer to write into
    if ((b = pw_stream_dequeue_buffer(d->stream)) == NULL) {
        pw_log_warn("out of buffers: %m");
        return;
    }

    buf = b->buffer;
    
    // 2. Get the pointer to the memory where we should write audio
    if ((dst = buf->datas[0].data) == NULL)
        return;

    // Calculate how many frames we can write (buffer size / stride)
    stride = sizeof(float) * DEFAULT_CHANNELS;
    n_frames = buf->datas[0].maxsize / stride;

    // 3. Fill the buffer with Sine Wave data
    for (int i = 0; i < n_frames; i++) {
        // Calculate sine wave value
        float val = sin(d->accumulator) * VOLUME;
        
        // Write to both channels (Left + Right)
        for (int c = 0; c < DEFAULT_CHANNELS; c++)
            *dst++ = val;

        // Advance phase
        d->accumulator += 2 * M_PI * BEEP_FREQ / DEFAULT_RATE;
        if (d->accumulator >= 2 * M_PI)
            d->accumulator -= 2 * M_PI;
        
        d->samples_played++;
    }

    // 4. Update buffer info and queue it back to PipeWire
    buf->datas[0].chunk->offset = 0;
    buf->datas[0].chunk->stride = stride;
    buf->datas[0].chunk->size = n_frames * stride;

    pw_stream_queue_buffer(d->stream, b);

    // 5. Stop after 1 second
    if (d->samples_played >= d->max_samples) {
        pw_main_loop_quit(d->loop);
    }
}

// Events struct (we only need the process callback)
static const struct pw_stream_events stream_events = {
    .version = PW_VERSION_STREAM_EVENTS,
    .process = on_process,
};

int main(int argc, char *argv[]) {
    struct data data = { 0 };
    const struct spa_pod *params[1];
    uint8_t buffer[1024];
    struct spa_pod_builder b = SPA_POD_BUILDER_INIT(buffer, sizeof(buffer));

    // 1. Initialize PipeWire
    pw_init(&argc, &argv);

    // 2. Create a main loop
    data.loop = pw_main_loop_new(NULL);
    data.max_samples = DEFAULT_RATE * 1; // 1 second duration

    // 3. Create a simple stream
    // "beep" is the name, PW_STREAM_PLAYBACK indicates we are outputting sound
    data.stream = pw_stream_new_simple(
        pw_main_loop_get_loop(data.loop),
        "simple-beep",
        pw_properties_new(PW_KEY_MEDIA_TYPE, "Audio",
                          PW_KEY_MEDIA_CATEGORY, "Playback",
                          NULL),
        &stream_events,
        &data);

    // 4. Build the Audio Format (Float 32-bit, 44.1kHz, Stereo)
    // PipeWire uses SPA (Simple Plugin API) for parameters
    params[0] = spa_format_audio_raw_build(&b, SPA_PARAM_EnumFormat,
        &SPA_AUDIO_INFO_RAW_INIT(
            .format = SPA_AUDIO_FORMAT_F32, // Float is standard for PipeWire
            .rate = DEFAULT_RATE,
            .channels = DEFAULT_CHANNELS));

    // 5. Connect the stream
    pw_stream_connect(data.stream,
                      PW_DIRECTION_OUTPUT,
                      PW_ID_ANY,
                      PW_STREAM_FLAG_AUTOCONNECT | // Auto-connect to default speakers
                      PW_STREAM_FLAG_MAP_BUFFERS | // Map memory for us
                      PW_STREAM_FLAG_RT_PROCESS,   // Real-time processing
                      params, 1);

    // 6. Run the loop (blocks until pw_main_loop_quit is called)
    pw_main_loop_run(data.loop);

    // 7. Cleanup
    pw_stream_destroy(data.stream);
    pw_main_loop_destroy(data.loop);
    pw_deinit();

    return 0;
}
