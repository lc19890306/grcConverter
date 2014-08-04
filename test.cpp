#include <gnuradio/analog/sig_source_f.h>
#include <gnuradio/audio/sink.h>
#include <gnuradio/blocks/add_ff.h>
#include <gnuradio/top_block.h>

int main() {
  gr::top_block_sptr tb = gr::make_top_block("top_block");
  int samp_rate = 48000;
  gr::blocks::add_ff::sptr blocks_add_xx_0 = gr::blocks::add_ff::make(1);
  gr::audio::sink::sptr audio_sink_0 = gr::audio::sink::make(samp_rate);
  gr::analog::sig_source_f::sptr analog_sig_source_x_0 = gr::analog::sig_source_f::make(samp_rate, gr::analog::GR_COS_WAVE, 350, 0.1);
  gr::analog::sig_source_f::sptr analog_sig_source_x_1 = gr::analog::sig_source_f::make(samp_rate, gr::analog::GR_COS_WAVE, 440, 0.1);
  tb->connect(analog_sig_source_x_0, 0, blocks_add_xx_0, 0);
  tb->connect(analog_sig_source_x_1, 0, blocks_add_xx_0, 1);
  tb->connect(blocks_add_xx_0, 0, audio_sink_0, 0);
  tb->run();

  return 0;
}
