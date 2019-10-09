Set App = CreateObject("LeCroy.XStreamDSO")

App.SaveRecall.Waveform.SaveTo = "File"
App.SaveRecall.Waveform.SaveSource = "All Displayed"
App.SaveRecall.Waveform.TraceTitle = "Trace"
App.SaveRecall.Waveform.WaveFormat = "Binary"
App.SaveRecall.Waveform.AutoSave = "Off"

App.SaveRecall.Waveform.WaveformDir = "D:\Calibration"