// Calibration_GUI.cpp: 主要專案檔。

#include "stdafx.h"
#include "Form1.h"

using namespace Calibration_GUI;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// 建立任何控制項之前，先啟用 Windows XP 視覺化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// 建立主視窗並執行
	Application::Run(gcnew Form1());
	return 0;
}
void __clrcall Form1::CalPC(String^ trcFN,double trig,int Mode){
	//AllocConsole();
	//Console::WriteLine("0:AP File Mode 1:File Mode");
	double Samplerate;
	//String^ CaliTime;
	vector<double> CaliPos(0);
	vector<double> CalArea(0);
	if (File::Exists(trcFN) == true){
		//Console::WriteLine("資料檔案存在!!");
		try{
			FileStream^ fs = gcnew FileStream(trcFN, FileMode::Open);
			BinaryReader^ br = gcnew BinaryReader(fs);
			array<Char>^ Data = gcnew array<Char>(50);
			br->Read( Data, 0, Data->Length );
			String^ s = gcnew String(Data);	
			int WAVEDESC = s->IndexOf( "WAVEDESC" );
			int aCOMM_TYPE	= WAVEDESC+ 32;
			int aWAVE_DESCRIPTOR = WAVEDESC+ 36;
			int aUSER_TEXT = WAVEDESC+ 40;
			int aTRIGTIME_ARRAY = WAVEDESC+ 48;
			int aWAVE_ARRAY_COUNT = WAVEDESC+ 116;
			int aVERTICAL_GAIN = WAVEDESC+ 156;
			int aVERTICAL_OFFSET = WAVEDESC+ 160;
			int aHORIZ_INTERVAL = WAVEDESC+ 176;
			__int16 COMM_TYPE = ReadWord(br,aCOMM_TYPE);
			__int32 WAVE_DESCRIPTOR = ReadLong(br,aWAVE_DESCRIPTOR);
			__int32 USER_TEXT = ReadLong(br,aUSER_TEXT);
			__int32 TRIGTIME_ARRAY = ReadLong(br,aTRIGTIME_ARRAY);
			__int32 WAVE_ARRAY_COUNT = ReadLong(br,aWAVE_ARRAY_COUNT);
			float VERTICAL_GAIN = ReadFloat(br,aVERTICAL_GAIN);
			float VERTICAL_OFFSET = ReadFloat(br,aVERTICAL_OFFSET);
			float HORIZ_INTERVAL = ReadFloat(br,aHORIZ_INTERVAL);
			br->BaseStream->Position = WAVEDESC + WAVE_DESCRIPTOR + USER_TEXT + TRIGTIME_ARRAY;
			Samplerate = 1/HORIZ_INTERVAL;
			//Console::WriteLine("SampleRate : {0}",Samplerate);
			double MIPoint = Samplerate*2/1000000.0;
			//Console::WriteLine("FPoint : {0}",Convert::ToString(MIPoint/2));
			double LastPos = 0.0;
			//double MaxAmp = 0.0;
			#pragma omp parallel for
			for (int i=0;i<WAVE_ARRAY_COUNT;i++){
				double amp;
				switch (COMM_TYPE){
				case 0:
					amp = br->ReadByte();
					break;
				default:
					amp = br->ReadInt16();
					break;
				}
				amp = VERTICAL_GAIN * (amp) - VERTICAL_OFFSET;
				CalArea.resize(CalArea.size()+1);
				/*if(Mode == "0" || Mode == "2"){
					CalArea[CalArea.size()-1] = amp;
				}else{
					CalArea[CalArea.size()-1] = Math::Abs(amp);
				}*/
				CalArea[CalArea.size()-1] = Math::Abs(amp);
				//if (amp>MaxAmp){MaxAmp=amp;}
				if (Math::Abs(amp) >= trig){
					if (i>LastPos+MIPoint/2*3){
						CaliPos.resize(CaliPos.size()+1);						
						CaliPos[CaliPos.size()-1] = i;
						LastPos = i;
					}
				}
			}
			br->Close();
			fs->Close();
			//Console::WriteLine("==========Statistics==========");
			double IntegerArea=0.0;
			#pragma omp parallel for
			for (int i=0;i<(int)CalArea.size();i++){
				IntegerArea=IntegerArea+CalArea[i];
			}
			//Console::WriteLine("LeCroy_View (Nano): {0}",Convert::ToString(IntegerArea/Samplerate*Nano));						
			double CaliPC = IntegerArea/Samplerate/Impedance*Pico;
			//Console::WriteLine("CaliPC (Pico): {0}",Convert::ToString(CaliPC));
			//Console::WriteLine("=======每根Pulse資料=======");
				double UnitArea = 0.0;
			if(Mode == 1){
				for(int i=0;i<(int)CaliPos.size();i++){
					//Console::WriteLine("    ==No."+Convert::ToString(i+1)+" Pulse==");
					int StartPos = (int)(CaliPos[i]-MIPoint*3/10);
					//Console::WriteLine("Pulse_Start_Pos : {0}",Convert::ToString(StartPos));
					double TempUnitArea = UnitArea;
					for(int j=0;j<MIPoint;j++){
						UnitArea = UnitArea+CalArea[StartPos+j];
					}
					double PulseArea = UnitArea-TempUnitArea;
					//Console::WriteLine("Pulse_Area : {0}",Convert::ToString(PulseArea));
					//Console::WriteLine("    LeCroy_View (Pico): {0}",Convert::ToString(PulseArea/Samplerate*Pico));
					double PulsePC=PulseArea/Samplerate/Impedance*Pico;
					//Console::WriteLine("    Pulse_PC (Pico): {0}",Convert::ToString(PulsePC));
				}
			}else{
				CaliPos.resize(CaliPos.size()+1);
				UnitArea=IntegerArea;
			}
			//Console::WriteLine("==========Final Data==========");
			//Console::WriteLine("Total_Pulse_Area : {0}",Convert::ToString(UnitArea));
			//Console::WriteLine("LeCroy_View (Pico): {0}",Convert::ToString(UnitArea/Samplerate*Pico));
			double UnitPC=UnitArea/Samplerate/Impedance*Pico;
			//Console::WriteLine("Total_Pulse_PC (Pico): {0}",Convert::ToString(UnitPC));
			double UnitPCAvg=UnitPC/(int)CaliPos.size();
			//Console::WriteLine("CaliPos.size(): {0}",Convert::ToString((int)CaliPos.size()));
			//Console::WriteLine("Pulse_PC_Avg (Pico): {0}",Convert::ToString(UnitPCAvg));
			this->label2->Text = Convert::ToString(UnitPC*Impedance/1.5);
		}catch(Exception^ e){
			Console::WriteLine(e->Message);
		}
	}
}
__int16 __clrcall Form1::ReadWord(BinaryReader^ br,int addr)
{
	br->BaseStream->Position=addr;
	__int16 s = br->ReadInt16();
	return s;
}
__int32 __clrcall Form1::ReadLong(BinaryReader^ br,int addr)
{
	br->BaseStream->Position=addr;
	__int32 s = br->ReadInt32();
	return s;
}
float __clrcall Form1::ReadFloat(BinaryReader^ br,int addr)
{
	br->BaseStream->Position=addr;
	float s = br->ReadSingle();
	return s;
}
