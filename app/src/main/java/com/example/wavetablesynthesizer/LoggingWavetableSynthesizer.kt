package com.example.wavetablesynthesizer

import android.util.Log

class LoggingWavetableSynthesizer : WavetableSynthesizer {

  private var isPlaying = false

  override fun play() {
    Log.d("LoggingWavetableSynthesizer", "play() called.")
    isPlaying = true
  }

  override fun stop() {
    Log.d("LoggingWavetableSynthesizer", "stop() called.")
    isPlaying = false
  }

  override fun isPlaying(): Boolean {
    return isPlaying
  }

  override fun setFrequency(frequencyInHz: Float) {
    Log.d("LoggingWavetableSynthesizer", "Frequency set to $frequencyInHz Hz.")
  }

  override fun setVolume(volumeInDb: Float) {
    Log.d("LoggingWavetableSynthesizer", "Volume set to $volumeInDb dB.")
  }

  override fun setWavetable(wavetable: Wavetable) {
    Log.d("LoggingWavetableSynthesizer", "Wavetable set to $wavetable")
  }
}