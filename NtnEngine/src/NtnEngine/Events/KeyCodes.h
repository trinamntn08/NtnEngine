#pragma once

namespace NTN
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	enum class KeyState
	{
		None = -1,
		Pressed,
		Held,
		Released
	};

	enum class CursorMode
	{
		Normal = 0,
		Hidden = 1,
		Locked = 2
	};

	typedef enum class MouseButton : uint16_t
	{
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Left = Button0,
		Right = Button1,
		Middle = Button2
	} Button;


	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, MouseButton button)
	{
		os << static_cast<int32_t>(button);
		return os;
	}
}

// From glfw3.h
#define NTN_KEY_SPACE           ::NTN::Key::Space
#define NTN_KEY_APOSTROPHE      ::NTN::Key::Apostrophe    /* ' */
#define NTN_KEY_COMMA           ::NTN::Key::Comma         /* , */
#define NTN_KEY_MINUS           ::NTN::Key::Minus         /* - */
#define NTN_KEY_PERIOD          ::NTN::Key::Period        /* . */
#define NTN_KEY_SLASH           ::NTN::Key::Slash         /* / */
#define NTN_KEY_0               ::NTN::Key::D0
#define NTN_KEY_1               ::NTN::Key::D1
#define NTN_KEY_2               ::NTN::Key::D2
#define NTN_KEY_3               ::NTN::Key::D3
#define NTN_KEY_4               ::NTN::Key::D4
#define NTN_KEY_5               ::NTN::Key::D5
#define NTN_KEY_6               ::NTN::Key::D6
#define NTN_KEY_7               ::NTN::Key::D7
#define NTN_KEY_8               ::NTN::Key::D8
#define NTN_KEY_9               ::NTN::Key::D9
#define NTN_KEY_SEMICOLON       ::NTN::Key::Semicolon     /* ; */
#define NTN_KEY_EQUAL           ::NTN::Key::Equal         /* = */
#define NTN_KEY_A               ::NTN::Key::A
#define NTN_KEY_B               ::NTN::Key::B
#define NTN_KEY_C               ::NTN::Key::C
#define NTN_KEY_D               ::NTN::Key::D
#define NTN_KEY_E               ::NTN::Key::E
#define NTN_KEY_F               ::NTN::Key::F
#define NTN_KEY_G               ::NTN::Key::G
#define NTN_KEY_H               ::NTN::Key::H
#define NTN_KEY_I               ::NTN::Key::I
#define NTN_KEY_J               ::NTN::Key::J
#define NTN_KEY_K               ::NTN::Key::K
#define NTN_KEY_L               ::NTN::Key::L
#define NTN_KEY_M               ::NTN::Key::M
#define NTN_KEY_N               ::NTN::Key::N
#define NTN_KEY_O               ::NTN::Key::O
#define NTN_KEY_P               ::NTN::Key::P
#define NTN_KEY_Q               ::NTN::Key::Q
#define NTN_KEY_R               ::NTN::Key::R
#define NTN_KEY_S               ::NTN::Key::S
#define NTN_KEY_T               ::NTN::Key::T
#define NTN_KEY_U               ::NTN::Key::U
#define NTN_KEY_V               ::NTN::Key::V
#define NTN_KEY_W               ::NTN::Key::W
#define NTN_KEY_X               ::NTN::Key::X
#define NTN_KEY_Y               ::NTN::Key::Y
#define NTN_KEY_Z               ::NTN::Key::Z
#define NTN_KEY_LEFT_BRACKET    ::NTN::Key::LeftBracket   /* [ */
#define NTN_KEY_BACKSLASH       ::NTN::Key::Backslash     /* \ */
#define NTN_KEY_RIGHT_BRACKET   ::NTN::Key::RightBracket  /* ] */
#define NTN_KEY_GRAVE_ACCENT    ::NTN::Key::GraveAccent   /* ` */
#define NTN_KEY_WORLD_1         ::NTN::Key::World1        /* non-US #1 */
#define NTN_KEY_WORLD_2         ::NTN::Key::World2        /* non-US #2 */

/* Function keys */
#define NTN_KEY_ESCAPE          ::NTN::Key::Escape
#define NTN_KEY_ENTER           ::NTN::Key::Enter
#define NTN_KEY_TAB             ::NTN::Key::Tab
#define NTN_KEY_BACKSPACE       ::NTN::Key::Backspace
#define NTN_KEY_INSERT          ::NTN::Key::Insert
#define NTN_KEY_DELETE          ::NTN::Key::Delete
#define NTN_KEY_RIGHT           ::NTN::Key::Right
#define NTN_KEY_LEFT            ::NTN::Key::Left
#define NTN_KEY_DOWN            ::NTN::Key::Down
#define NTN_KEY_UP              ::NTN::Key::Up
#define NTN_KEY_PAGE_UP         ::NTN::Key::PageUp
#define NTN_KEY_PAGE_DOWN       ::NTN::Key::PageDown
#define NTN_KEY_HOME            ::NTN::Key::Home
#define NTN_KEY_END             ::NTN::Key::End
#define NTN_KEY_CAPS_LOCK       ::NTN::Key::CapsLock
#define NTN_KEY_SCROLL_LOCK     ::NTN::Key::ScrollLock
#define NTN_KEY_NUM_LOCK        ::NTN::Key::NumLock
#define NTN_KEY_PRINT_SCREEN    ::NTN::Key::PrintScreen
#define NTN_KEY_PAUSE           ::NTN::Key::Pause
#define NTN_KEY_F1              ::NTN::Key::F1
#define NTN_KEY_F2              ::NTN::Key::F2
#define NTN_KEY_F3              ::NTN::Key::F3
#define NTN_KEY_F4              ::NTN::Key::F4
#define NTN_KEY_F5              ::NTN::Key::F5
#define NTN_KEY_F6              ::NTN::Key::F6
#define NTN_KEY_F7              ::NTN::Key::F7
#define NTN_KEY_F8              ::NTN::Key::F8
#define NTN_KEY_F9              ::NTN::Key::F9
#define NTN_KEY_F10             ::NTN::Key::F10
#define NTN_KEY_F11             ::NTN::Key::F11
#define NTN_KEY_F12             ::NTN::Key::F12
#define NTN_KEY_F13             ::NTN::Key::F13
#define NTN_KEY_F14             ::NTN::Key::F14
#define NTN_KEY_F15             ::NTN::Key::F15
#define NTN_KEY_F16             ::NTN::Key::F16
#define NTN_KEY_F17             ::NTN::Key::F17
#define NTN_KEY_F18             ::NTN::Key::F18
#define NTN_KEY_F19             ::NTN::Key::F19
#define NTN_KEY_F20             ::NTN::Key::F20
#define NTN_KEY_F21             ::NTN::Key::F21
#define NTN_KEY_F22             ::NTN::Key::F22
#define NTN_KEY_F23             ::NTN::Key::F23
#define NTN_KEY_F24             ::NTN::Key::F24
#define NTN_KEY_F25             ::NTN::Key::F25

/* Keypad */
#define NTN_KEY_KP_0            ::NTN::Key::KP0
#define NTN_KEY_KP_1            ::NTN::Key::KP1
#define NTN_KEY_KP_2            ::NTN::Key::KP2
#define NTN_KEY_KP_3            ::NTN::Key::KP3
#define NTN_KEY_KP_4            ::NTN::Key::KP4
#define NTN_KEY_KP_5            ::NTN::Key::KP5
#define NTN_KEY_KP_6            ::NTN::Key::KP6
#define NTN_KEY_KP_7            ::NTN::Key::KP7
#define NTN_KEY_KP_8            ::NTN::Key::KP8
#define NTN_KEY_KP_9            ::NTN::Key::KP9
#define NTN_KEY_KP_DECIMAL      ::NTN::Key::KPDecimal
#define NTN_KEY_KP_DIVIDE       ::NTN::Key::KPDivide
#define NTN_KEY_KP_MULTIPLY     ::NTN::Key::KPMultiply
#define NTN_KEY_KP_SUBTRACT     ::NTN::Key::KPSubtract
#define NTN_KEY_KP_ADD          ::NTN::Key::KPAdd
#define NTN_KEY_KP_ENTER        ::NTN::Key::KPEnter
#define NTN_KEY_KP_EQUAL        ::NTN::Key::KPEqual

#define NTN_KEY_LEFT_SHIFT      ::NTN::Key::LeftShift
#define NTN_KEY_LEFT_CONTROL    ::NTN::Key::LeftControl
#define NTN_KEY_LEFT_ALT        ::NTN::Key::LeftAlt
#define NTN_KEY_LEFT_SUPER      ::NTN::Key::LeftSuper
#define NTN_KEY_RIGHT_SHIFT     ::NTN::Key::RightShift
#define NTN_KEY_RIGHT_CONTROL   ::NTN::Key::RightControl
#define NTN_KEY_RIGHT_ALT       ::NTN::Key::RightAlt
#define NTN_KEY_RIGHT_SUPER     ::NTN::Key::RightSuper
#define NTN_KEY_MENU            ::NTN::Key::Menu

// Mouse
#define NTN_MOUSE_BUTTON_LEFT    ::NTN::Button::Left
#define NTN_MOUSE_BUTTON_RIGHT   ::NTN::Button::Right
#define NTN_MOUSE_BUTTON_MIDDLE  ::NTN::Button::Middle
