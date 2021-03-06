/*
#
# this config file was automatically generated
# using lirc-0.8.6(default) on Fri Sep 10 22:02:46 2010
#
# contributed by
#
# brand:                       TV LG 42"LD420
# model no. of remote control: AKB72915207
# devices being controlled by this remote:
#

begin remote

  name  LG_AKB72915207
  bits           16
  flags SPACE_ENC|CONST_LENGTH
  eps            30
  aeps          100

  header       9056  4448
  one           601  1647
  zero          601   538
  ptrail        601
  repeat       9081  2199
  pre_data_bits   16
  pre_data       0x20DF
  gap          108229
  toggle_bit_mask 0x0

      begin codes
          KEY_POWER                0x10EF                    #  Was: power
          energy                   0xA956
          avmode                   0x0CF3
          input                    0xD02F
          tvrad                    0x0FF0
          KEY_1                    0x8877                    #  Was: 1
          KEY_2                    0x48B7                    #  Was: 2
          KEY_3                    0xC837                    #  Was: 3
          KEY_4                    0x28D7                    #  Was: 4
          KEY_5                    0xA857                    #  Was: 5
          KEY_6                    0x6897                    #  Was: 6
          KEY_7                    0xE817                    #  Was: 7
          KEY_8                    0x18E7                    #  Was: 8
          KEY_9                    0x9867                    #  Was: 9
          KEY_0                    0x08F7                    #  Was: 0
          KEY_LIST                 0xCA35                    #  Was: list
          q.view                   0x58A7
          KEY_VOLUMEUP             0x40BF                    #  Was: vol_up
          KEY_VOLUMEDOWN           0xC03F                    #  Was: vol_down
          KEY_CHANNELUP            0x00FF                    #  Was: ch_up
          KEY_CHANNELDOWN          0x807F                    #  Was: ch_down
          KEY_FAVORITES            0x7887                    #  Was: fav
          ratio                    0x9E61
          KEY_MUTE                 0x906F                    #  Was: mute
          KEY_MENU                 0xC23D                    #  Was: menu
          KEY_INFO                 0xD52A                    #  Was: guide
          q.menu                   0xA25D
          KEY_UP                   0x02FD                    #  Was: up
          KEY_DOWN                 0x827D                    #  Was: down
          KEY_LEFT                 0xE01F                    #  Was: left
          KEY_RIGHT                0x609F                    #  Was: right
          KEY_OK                   0x22DD                    #  Was: ok
          KEY_BACK                 0x14EB                    #  Was: back
          KEY_INFO                 0x55AA                    #  Was: info
          KEY_EXIT                 0xDA25                    #  Was: exit
          KEY_RED                  0x4EB1                    #  Was: red
          KEY_GREEN                0x8E71                    #  Was: green
          ellow                    0xC639
          KEY_BLUE                 0x8679                    #  Was: blue
          exit2                    0x04FB
          t.opt                    0x847B
          KEY_SUBTITLE             0x9C63                    #  Was: subtitle
          KEY_STOP                 0x8D72                    #  Was: stop
          KEY_PLAY                 0x0DF2                    #  Was: play
          KEY_PAUSE                0x5DA2                    #  Was: pause
          KEY_REWIND               0xF10E                    #  Was: <<
          KEY_FORWARD              0x718E                    #  Was: >>
          simplink                 0x7E81
      end codes

end remote
*/

#include <IRremoteESP8266.h>
#include <Arduino.h>

unsigned long TV_CODE_TO_SEND;

void tv_send_code(unsigned long code, IRsend *irsend)
{
  //for (int i=0;i<3;i++){
    irsend->sendLG(code, 32);
    //delay(40);
  //}
}

void tv_power_on(IRsend *irsend)
{
  TV_CODE_TO_SEND = 0x20DF10EF;
  tv_send_code(TV_CODE_TO_SEND, irsend);
}

void tv_power_off(IRsend *irsend)
{
  TV_CODE_TO_SEND = 0x20DF10EF;
  tv_send_code(TV_CODE_TO_SEND, irsend);
}

void tv_volume(int delta, IRsend *irsend)
{
  if (delta < 0) {
    delta = -1*delta;
    TV_CODE_TO_SEND = 0x20DFC03F;
    for (int i=0;i<delta;i++) {
      tv_send_code(TV_CODE_TO_SEND, irsend);
      delay(200);
    }
  } else if (delta > 0) {
    TV_CODE_TO_SEND = 0x20DF40BF;
    for (int i=0;i<delta;i++) {
      tv_send_code(TV_CODE_TO_SEND, irsend);
      delay(200);
    }
  }
}
