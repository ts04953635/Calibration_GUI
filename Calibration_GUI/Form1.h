#pragma once

namespace Calibration_GUI {

	using namespace std;
	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	#define Impedance 50.0		//阻抗
	#define Pico 1000000000000.0		//阻抗
	#define Nano 1000000000.0		//阻抗
	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}
	public:
		void __clrcall Form1::CalPC(String^ trcFN,double trig,int mode);
		__int16 __clrcall Form1::ReadWord(BinaryReader^ br,int addr);
		__int32 __clrcall Form1::ReadLong(BinaryReader^ br,int addr);
		float __clrcall Form1::ReadFloat(BinaryReader^ br,int addr);
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  comboBox1;







	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"載入示波器設定";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->button2->Location = System::Drawing::Point(0, 60);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L"計算P.C.值(Calibrator)";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label1->Location = System::Drawing::Point(100, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"示波器顯示數值:";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label2->Location = System::Drawing::Point(100, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(232, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Test Data";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label2->TextChanged += gcnew System::EventHandler(this, &Form1::label2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label3->Location = System::Drawing::Point(100, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(232, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"──────────────";
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label4->Location = System::Drawing::Point(100, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(232, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"/ 50 Ω";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label5->Location = System::Drawing::Point(100, 101);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(232, 20);
			this->label5->TabIndex = 6;
			this->label5->Text = L"P.C.";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->button3->Location = System::Drawing::Point(0, 120);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 60);
			this->button3->TabIndex = 7;
			this->button3->Text = L"計算P.C.值(PD Pulse)";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->button4->Location = System::Drawing::Point(0, 180);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 60);
			this->button4->TabIndex = 8;
			this->button4->Text = L"歷史紀錄";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Location = System::Drawing::Point(100, 121);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(232, 120);
			this->panel1->TabIndex = 9;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"5", L"20", L"100", L"500"});
			this->comboBox1->Location = System::Drawing::Point(90, 42);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(57, 24);
			this->comboBox1->TabIndex = 6;
			// 
			// label10
			// 
			this->label10->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label10->Location = System::Drawing::Point(169, 65);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 20);
			this->label10->TabIndex = 5;
			this->label10->Text = L"0";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label9->Location = System::Drawing::Point(85, 85);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(60, 20);
			this->label9->TabIndex = 4;
			this->label9->Text = L"1";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label9->TextChanged += gcnew System::EventHandler(this, &Form1::label9_TextChanged);
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label8->Location = System::Drawing::Point(0, 65);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 20);
			this->label8->TabIndex = 3;
			this->label8->Text = L"0";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label8->TextChanged += gcnew System::EventHandler(this, &Form1::label8_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 9));
			this->label7->Location = System::Drawing::Point(70, 70);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(94, 12);
			this->label7->TabIndex = 1;
			this->label7->Text = L"X   ─────  =";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->label6->Location = System::Drawing::Point(3, 10);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(228, 16);
			this->label6->TabIndex = 0;
			this->label6->Text = L"局部放電量    比值   實際放電量";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 241);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Calibration";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ CaliSetPath = Directory::GetCurrentDirectory()+"\\CaliSet.vbs";
			 Process^ myProcess = gcnew Process;
			 try{
				myProcess->StartInfo->UseShellExecute = true;
				myProcess->StartInfo->FileName = CaliSetPath;
				myProcess->StartInfo->CreateNoWindow = true;
				myProcess->Start();
			}catch ( Exception^ e ){
				Console::WriteLine( e->Message );
			}
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Directory::CreateDirectory("D:\\Calibration");
			 String^ CaliSetPath = Directory::GetCurrentDirectory()+"\\Save.vbs";
			 Process^ myProcess = gcnew Process;
			 try{
				 myProcess->StartInfo->UseShellExecute = true;
				 myProcess->StartInfo->FileName = CaliSetPath;
				 myProcess->StartInfo->CreateNoWindow = true;
				myProcess->Start();
			}catch ( Exception^ e ){
				Console::WriteLine( e->Message );
			}
			 Sleep(1000);
			 array<System::String^>^ TrcFiles;
			 TrcFiles = Directory::GetFiles("D:\\Calibration","*.trc");
			 String^ trcFN = Convert::ToString(TrcFiles[0]);
			 DateTime LastFileTime = Directory::GetCreationTime(TrcFiles[0]);
			 for(int i=0;i<(int)TrcFiles->Length;i++){
				 if(DateTime::Compare(Directory::GetCreationTime(TrcFiles[i]),LastFileTime) >= 0){
					 trcFN = Convert::ToString(TrcFiles[i]);
					 LastFileTime = Directory::GetCreationTime(TrcFiles[i]);
				 }	
			 }
			 String^ CaliTime = DateTime::Now.ToString("yyyyMMdd_HHmmss");
			 String^ MovePath = Directory::GetCurrentDirectory()+"\\Cali"+CaliTime+".trc";
			 File::Move(trcFN,MovePath);
			 trcFN = MovePath;
			 double trig = 0.0;
			 int Mode = 0;
			 Form1::CalPC(trcFN,trig,Mode);
			 this->label9->Text = Convert::ToString(Math::Round(Convert::ToDouble(this->label2->Text)/50.0,2));
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 Directory::CreateDirectory("D:\\Calibration");
			 String^ CaliSetPath = Directory::GetCurrentDirectory()+"\\Save.vbs";
			 Process^ myProcess = gcnew Process;
			 try{
				 myProcess->StartInfo->UseShellExecute = true;
				 myProcess->StartInfo->FileName = CaliSetPath;
				 myProcess->StartInfo->CreateNoWindow = true;
				myProcess->Start();
			}catch ( Exception^ e ){
				Console::WriteLine( e->Message );
			}
			 Sleep(1000);
			 array<System::String^>^ TrcFiles;
			 TrcFiles = Directory::GetFiles("D:\\Calibration","*.trc");
			 String^ trcFN = Convert::ToString(TrcFiles[0]);
			 DateTime LastFileTime = Directory::GetCreationTime(TrcFiles[0]);
			 for(int i=0;i<(int)TrcFiles->Length;i++){
				 if(DateTime::Compare(Directory::GetCreationTime(TrcFiles[i]),LastFileTime) >= 0){
					 trcFN = Convert::ToString(TrcFiles[i]);
					 LastFileTime = Directory::GetCreationTime(TrcFiles[i]);
				 }	
			 }
			 String^ CaliTime = DateTime::Now.ToString("yyyyMMdd_HHmmss");
			 String^ MovePath = Directory::GetCurrentDirectory()+"\\PD"+CaliTime+".trc";
			 File::Move(trcFN,MovePath);
			 trcFN = MovePath;
			 double trig = 0.0;
			 int Mode = 0;
			 Form1::CalPC(trcFN,trig,Mode);
			 this->label8->Text = Convert::ToString(Math::Round(Convert::ToDouble(this->label2->Text)/50.0,2));
		 }
private: System::Void label2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->label5->Text = Convert::ToString(Convert::ToDouble(this->label2->Text)/50.0)+"  P.C.";
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ HistoryFile = gcnew OpenFileDialog();
			 HistoryFile->ShowDialog();
			 String^ trcFN = HistoryFile->FileName;
			 double trig = 0.0;
			 int Mode = 0;
			 Form1::CalPC(trcFN,trig,Mode);
		 }
private: System::Void label8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 double Ratio = Convert::ToDouble(this->comboBox1->Text)/Convert::ToDouble(this->label9->Text);
			 this->label10->Text = Convert::ToString(Convert::ToDouble(this->label8->Text)*Ratio);
		 }
private: System::Void label9_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 double Ratio = Convert::ToDouble(this->comboBox1->Text)/Convert::ToDouble(this->label9->Text);
			 this->label10->Text = Convert::ToString(Convert::ToDouble(this->label8->Text)*Ratio);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 this->comboBox1->Text = Convert::ToString(5);
		 }
};
}

