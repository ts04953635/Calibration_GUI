Set App = CreateObject("LeCroy.XStreamDSO")
App.Display.NumSegmentsDisplayed = 100000
App.Display.StartSegment = 1
App.Display.ScreenSaveEnable = True
App.Display.ScreenSaveTimeout = 60

App.Acquisition.Channels(1).View = True
App.Acquisition.C1.UseGrid = "YT1"
App.Acquisition.C1.Coupling = "DC50"
App.Acquisition.C1.VerScale = 0.05
App.Acquisition.C1.VerOffset = -0.15

App.Acquisition.TriggerMode = "Normal"
App.Acquisition.Trigger.Type = "Edge"
App.Acquisition.Trigger.Source = "C1"
App.Acquisition.Trigger.Line.Slope = "Positive"
App.Acquisition.Trigger.C1.Level = 0.0025
App.Acquisition.Trigger.FindLevel


App.Acquisition.Horizontal.SampleMode = "RealTime"
App.Acquisition.Horizontal.NumSegments = 10
App.Acquisition.Horizontal.Maximize = "SetMaximumMemory"
App.Acquisition.Horizontal.ActiveChannels = "Auto"
App.Acquisition.Horizontal.MaxSamples = 10000000

App.Acquisition.Horizontal.HorScale = 0.00000002
App.Acquisition.Horizontal.HorOffset = -0.00000006
