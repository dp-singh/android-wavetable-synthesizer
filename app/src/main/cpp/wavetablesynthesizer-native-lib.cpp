#include <jni.h>
#include <memory>
#include "Log.h"
#include "WavetableSynthesizer.h"

extern "C" {
    JNIEXPORT jlong JNICALL
    Java_com_thewolfsound_wavetablesynthesizer_NativeWavetableSynthesizer_create(JNIEnv* env, jobject obj) {
        auto synthesizer = std::make_unique<wavetablesynthesizer::WavetableSynthesizer>();

        if (not synthesizer) {
            LOGD("Failed to create the synthesizer.");
            synthesizer.reset(nullptr);
        }

        return reinterpret_cast<jlong>(synthesizer.release());
    }

    JNIEXPORT void JNICALL
    Java_com_thewolfsound_wavetablesynthesizer_NativeWavetableSynthesizer_delete(JNIEnv* env, jobject obj, jlong synthesizerHandle) {
        auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer*>(synthesizerHandle);

        if (not synthesizer) {
            LOGD("Attempt to destroy an unitialized synthesizer.");
            return;
        }

        delete synthesizer;
    }

    JNIEXPORT void JNICALL
    Java_com_thewolfsound_wavetablesynthesizer_NativeWavetableSynthesizer_setFrequency(JNIEnv* env, jobject obj, jlong synthesizerHandle, jfloat frequencyInHz) {
        auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer*>(synthesizerHandle);
        const auto nativeFrequency = static_cast<float>(frequencyInHz);

        if (synthesizer) {
            synthesizer->setFrequency(nativeFrequency);
        } else {
            LOGD("Synthesizer not created. Please, create the synthesizer first by calling create().");
        }
    }
}
