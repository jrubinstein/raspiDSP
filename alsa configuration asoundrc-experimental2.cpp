#asound rc new version jrubinstein - experimental with charlies plugin
pcm.!default {
     type plug
     slave.pcm filtereq
}
ctl.!default {
     type hw
     card 0
}
pcm.filtereq {
     type ladspa
     slave.pcm filtercross
     path "/usr/lib/ladspa"
     channels 8
     plugins
     {

        0 {
               label ACDf
               policy none
               input.bindings.0 "Input"
               output.bindings.0 "Output"
               input { controls [28 1 6 120 1 1 1] } #2nd order bass shelf boosting 6db at 120hz
        }
        1{
               label ACDf
               policy none
               input.bindings.0 "Input"
               output.bindings.0 "Output"
               input { controls [26 1 -6 164 4 1 1] } #parametric digital eq cutting 6db at 164hz with q of 4
        }
        2{
               label ACDf
               policy none
               input.bindings.0 "Input"
               output.bindings.0 "Output"
               input { controls [26 1 -6 250 4 1 1] }#parametric digital eq cutting 6db at 164hz with q of 4
        }
        3{
               label ACDf
               policy none
               input.bindings.0 "Input"
               output.bindings.0 "Output"
               input { controls [26 1 6 193 5 1 1] }#parametric digital eq boosting 6db at 193 with q of 5
        }
        4{
               label ACDf
               policy none
               input.bindings.1 "Input"
               output.bindings.1 "Output"
               input { controls [28 1 6 120 1 1 1] }
        }
        5{
               label ACDf
               policy none
               input.bindings.1 "Input"
               output.bindings.1 "Output"
               input { controls [26 1 -6 164 4 1 1] }
        }
        6{
               label ACDf
               policy none
               input.bindings.1 "Input"
               output.bindings.1 "Output"
               input { controls [26 1 -6 250 4 1 1] }
        }
        7{
               label ACDf
               policy none
               input.bindings.1 "Input"
               output.bindings.1 "Output"
               input { controls [26 1 6 193 5 1 1] }
        }
        8{
               label ACDf 
               policy none
               input.bindings.0 "Input"
               output.bindings.0 "Output"
               input { controls [22 1 0 40 1 1 1] } #2nd order highpass at 40 hz to act as subsonic filter
          }
        9{
               label ACDf 
               policy none
               input.bindings.0 "Input"
               output.bindings.0 "Output"
               input { controls [22 1 0 40 1 1 1] } #2nd order highpass at 40 hz
          }
        10{
               label ACDf 
               policy none
               input.bindings.1 "Input"
               output.bindings.1 "Output"
               input { controls [22 1 0 40 1 1 1] } #2nd order highpass at 40 hz to act as subsonic filter
          }
        11{
               label ACDf 
               policy none
               input.bindings.1 "Input"
               output.bindings.1 "Output"
               input { controls [22 1 0 40 1 1 1] } #2nd order highpass at 40 hz
          }
    }
}
pcm.filtercross {
     type ladspa
     slave.pcm speaker
     path "/usr/lib/ladspa"
     channels 8
     plugins
     {
          0 {
               label ACDf #lowpass for woofer output to channel2
               policy none
               input.bindings.0 "Input"
               output.bindings.2 "Output"
               input { controls [21 -1 -10 300 0.5 1 1] }   # [filter type polarity dbgain frequency q]
          }
        1 {
               label ACDf #lowpass for woofer output to channel3
               policy none
               input.bindings.1 "Input"
               output.bindings.3 "Output"
               input { controls [21 -1 -10 300 0.5 1 1] } #2nd order lowpass at 300hz
          }
        2 {
               label ACDf #highpass for tweeter output to channel4
               policy none
               input.bindings.0 "Input"
               output.bindings.4 "Output"
               input { controls [22 -1 -23 3000 1 1 1] } #2nd order highpass at 3000 hz
          }
        3 {
               label ACDf #highpass for tweeter output to channel4  filter 2
               policy none
               input.bindings.0 "Input"
               output.bindings.4 "Output"
               input { controls [22 1 0 3000 1 1 1] } #2nd order highpass at 3000 hz
          }
        4 {
               label ACDf #highpass for tweeter output to channel4
               policy none
               input.bindings.1 "Input"
               output.bindings.5 "Output"
               input { controls [22 -1 -23 3000 1 1 1] } #2nd order highpass at 3000 hz
          }
        5 {
               label ACDf #highpass for tweeter output to channel4  filter 2
               policy none
               input.bindings.1 "Input"
               output.bindings.5 "Output"
               input { controls [22 1 0 3000 1 1 1] } #2nd order highpass at 3000 hz
          }
        6 {
               label ACDf #lowpass1 for mid output to channel0
               policy none
               input.bindings.0 "Input"
               output.bindings.6 "Output"
               input { controls [21 1 -14 3000 0.707 1 1] } # 2nd order lowpass at 3000 hz -4db cut
          }
        7 {
               label ACDf #lowpass2 for mid output to channel0
               policy none
               input.bindings.0 "Input"
               output.bindings.6 "Output"
               input { controls [21 1 0 3000 0.707 1 1] } # 2nd order lowpass at 3000 hz 
          } 
        8 {
               label ACDf #highpass for mid output to channel0
               policy none
               input.bindings.0 "Input"
               output.bindings.6 "Output"
               input { controls [22 1 0 300 0.5 1 1] } # 2nd order highpass at 300 hz
          }  
        9 {
               label ACDf #lowpass1 for mid output to channel1
               policy none
               input.bindings.1 "Input"
               output.bindings.7 "Output"
               input { controls [21 1 -14 3000 0.707 1 1] } # 2nd order lowpass at 3000 hz -4db cut
          }
        10 {
               label ACDf #lowpass2 for mid output to channel1 
               policy none
               input.bindings.1 "Input"
               output.bindings.7 "Output"
               input { controls [21 1 0 3000 0.707 1 1] } # 2nd order lowpass at 3000 hz
          }  
        11 {
               label ACDf #highpass for mid output to channel1
               policy none
               input.bindings.1 "Input"
               output.bindings.7 "Output"
               input { controls [22 1 0 300 0.5 1 1] } # 2nd order highpass at 300 hz 
          }          
     }
}
pcm.speaker {
    type plug
    slave {
     pcm "t-table"  
     channels 8
     rate "unchanged"
    }
}
pcm.t-table  {
    type route
    slave {
     pcm "hw:0,0"
     channels 8
    }
    ttable {
      0.0   0  # audio = left woofer channel = left front
      1.1   0  # channel in.channel out  on/off
      2.0   1  #left bass this gives me the low filter for left woofer onto channel 0 = front left
      3.7   1  #right bass  = SBR
      4.6   1  #left tweeter = SBL 
      5.5   1  #right tweeter = Surr Right 
      6.4   1  #left mid = surr left 
      7.3   1  #right mid = center 
    }
}

pcm.plughw.slave.rate = "unchanged";