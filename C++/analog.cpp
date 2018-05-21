#include <iostream>

using namespace std;


namespace SerialInterfaceApi
{
  class Data_Capture
  {
  private:
    bool cont_fpga_spi_endianness;
    int cont_fpga_spi_frequency;
    bool cont_fpga_spi_clock_phase;
    bool cont_fpga_spi_clock_pol;
    int fpga_adc_spi_endianness;
    int fpga_adc_spi_frequency;
    bool fpga_adc_spi_clock_phase;
    bool fpga_adc_clock_pol;
    typedef enum DEBUG_MODE{NORMAL, MODE_1};
    int resolution;
    int sample_rate;
    const int sram_present;
    int sram_enable;
    int number_channels;
    vector<int> sub_channel(number_channels);
    map<int, double> data;
    int active_channels;
    int adc_activate[N];
  public:
    Data_Capture();//private variables are initialized with defaults
    bool configure_cont_fpga_spi(bool clock_phase, bool clock_pol,int frequency,bool endianness);
    bool configure_cont_fpga_spi(bool clock_phase, clock_pol, bool frequency, bool endianness);
    bool configure_adc(int slave_id,int debug_mode,int resolution,int number_channels,int sample_rate );
    bool fpga_sram_enable(int sram_enable);
    bool simple_data_capture(int slave_id, int active_channels, double time);
    bool simple_data_capture(int slave_id, int active_channels, int number_of_samples);
    bool deep_data_capture(int slave_id, int active_channels, int number_of_samples);
    bool read_data(int channel, int sub_channel);
    bool read_data(int channel);
    bool read_data();

    }
  };
}
