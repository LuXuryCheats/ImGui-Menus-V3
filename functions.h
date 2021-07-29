ImVec2 p;
#include "imgui/imgui_internal.h"
static int tabs = 1;

struct Config
{             
	void CheatLoverz();
	void BypassAC();
	void Applecheats();
	void MakFN();
	void CWIN();
	void Vegeance();
};
Config g_Config;

namespace Settings
{
	bool Aimbot = true;
	float Smoothing = 1.f;
	float AIM_FOV = 120.f;
	bool AimbotFOV = true;

	bool Fov_Slider = false;
	float Fov_Amt = 90.f;

	bool BoxESP = true;
	bool Filled = true;
	bool Skeletons = true;
	bool Lines = false;
	bool Player_Name = true;
	bool Distance = true;
	float Thickness = 1.f;

	bool NoRecoil = false;
	bool NoSpread = false;

	bool Head = true;
	bool Chest = false;

	int Bone = 1;

	bool VisCheck = true;

	bool Menu = true;
}

namespace Render
{
	struct vec_2
	{
		int x, y;
	};

	struct Colors
	{
		ImColor red = { 255, 0, 0, 255 };
		ImColor green = { 0, 255, 0, 255 };
		ImColor blue = { 0, 136, 255, 255 };
		ImColor aqua_blue = { 0, 255, 255, 255 };
		ImColor cyan = { 0, 210, 210, 255 };
		ImColor royal_purple = { 102, 0, 255, 255 };
		ImColor dark_pink = { 255, 0, 174, 255 };
		ImColor black = { 0, 0, 0, 255 };
		ImColor white = { 255, 255, 255, 255 };
		ImColor purple = { 255, 0, 255, 255 };
		ImColor yellow = { 255, 255, 0, 255 };
		ImColor orange = { 255, 140, 0, 255 };
		ImColor gold = { 234, 255, 0, 255 };
		ImColor royal_blue = { 0, 30, 255, 255 };
		ImColor dark_red = { 150, 5, 5, 255 };
		ImColor dark_green = { 5, 150, 5, 255 };
		ImColor dark_blue = { 100, 100, 255, 255 };
		ImColor navy_blue = { 0, 73, 168, 255 };
		ImColor light_gray = { 200, 200, 200, 255 };
		ImColor dark_gray = { 150, 150, 150, 255 };
	};
	Colors color;

	void Text(int posx, int posy, ImColor clr, const char* text)
	{
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx, posy), ImColor(clr), text);
	}

	void OutlinedText(int posx, int posy, ImColor clr, const char* text)
	{
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 1), ImColor(color.black), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx - 1, posy - 1), ImColor(color.black), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 1), ImColor(color.black), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx - 1, posy - 1), ImColor(color.black), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx, posy), ImColor(clr), text);
	}

	void ShadowText(int posx, int posy, ImColor clr, const char* text)
	{
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 2), ImColor(0, 0, 0, 200), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx + 1, posy + 2), ImColor(0, 0, 0, 200), text);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(posx, posy), ImColor(clr), text);
	}

	void Rect(int x, int y, int w, int h, ImColor color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0, thickness);
	}

	void RectFilledGradient(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void RectFilled(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void Checkbox(const char* v, bool* option, float x, float y, const char* title)
	{
		ImGui::SetCursorPos({ x, y });
		ImGui::Checkbox(v, option);

		p = ImGui::GetWindowPos();

		ImGui::SetCursorPos({ x + 2, y - 20 });
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(0, 245, 245)));
		ImGui::Text(title);
		ImGui::PopStyleColor();

		Render::RectFilled(p.x + x + 3, p.y + y + 3, 16, 16, ImColor(200, 200, 200));

		if (*option)
		{
			Render::RectFilled(p.x + x + 7, p.y + y + 7, 8, 8, ImColor(0, 0, 0, 255));
		}
	}

	void Slider(const char* v, float* option, float x, float y, float min, float max, const char* title)
	{
		ImGui::SetCursorPos({ x, y });
		ImGui::SliderFloat(v, option, min, max);

		ImGui::SetCursorPos({ x + 2, y - 20 });
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(0, 245, 245)));
		ImGui::Text(title);
		ImGui::PopStyleColor();
	}

	void Tab(const char* v, float size_x, float size_y, static int tab_name, int tab_next)
	{
		if (ImGui::Button(v, ImVec2{ size_x, size_y })) tab_name = tab_next;
	}
}

namespace PS
{
	void CL_ToggleButton(const char* v, bool* option, float x, float y, float x2)
	{
		ImGui::SetCursorPos({ x + x2, y });

		ImVec2 pos = ImGui::GetWindowPos();
		float height = 20;
		float width = 40;

		if (ImGui::Button(v, ImVec2{ width, height }))
			*option = !*option;

		Render::Rect(pos.x + x + x2, pos.y + y, 40, 20, ImColor(50, 50, 50), 2);
		Render::RectFilled(pos.x + x + x2, pos.y + y, 40, 20, ImColor(100, 100, 100, 255));
		Render::ShadowText(pos.x + x - 5, pos.y + y, ImColor(255, 187, 0, 200), v);

		if (*option)
		{
			Render::RectFilled(pos.x + x + x2, pos.y + y, 20, 20, ImColor(0, 200, 0, 255));
		}
		else
		{
			Render::RectFilled(pos.x + x + 20 + x2, pos.y + y, 20, 20, ImColor(200, 0, 0, 255));
		}
	}

	void CL_Tab(const char* v, int tab_next, float x, float y)
	{
		ImGui::SetCursorPos({ x, y });
		if (ImGui::Button(v, ImVec2(120, 35))) tabs = tab_next;

		ImVec2 pos = ImGui::GetWindowPos();
		Render::RectFilled(pos.x + x, pos.y + y, 120, 35, ImColor(1, 133, 182, 255));
		Render::Rect(pos.x + x, pos.y + y, 120, 35, ImColor(0, 67, 91, 255), 2);
		Render::ShadowText(pos.x + x + 33, pos.y + y + 6, ImColor(255, 187, 0, 200), v);
	}

	void CL_Slider(const char* v, float option, float x, float y)
	{

	}

	///////////////////////////////////////

	void AC_Checkbox(const char* v, bool* option, float x, float y, const char* title)
	{
		ImGui::SetCursorPos({ x, y });
		ImGui::Checkbox(v, option);

		p = ImGui::GetWindowPos();

		ImGui::SetCursorPos({ x + 2, y - 20 });
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(0, 0, 0, 255)));
		ImGui::Text(title);
		ImGui::PopStyleColor();

		Render::RectFilled(p.x + x + 3, p.y + y + 3, 16, 16, ImColor(200, 200, 200));
		Render::Text(p.x + x + 28, p.y + y + 2, ImColor(0, 0, 0, 255), v);

		if (*option)
		{
			Render::RectFilled(p.x + x + 7, p.y + y + 7, 8, 8, ImColor(0, 0, 0, 255));
		}
	}

	void AC_Tab(const char* v, int tab_next, float x, float y)
	{
		ImGui::SetCursorPos({ x, y });
		if (ImGui::Button(v, ImVec2(140, 30))) tabs = tab_next;

		ImVec2 pos = ImGui::GetWindowPos();
		Render::RectFilled(pos.x + x, pos.y + y, 140, 30, ImColor(234, 234, 234, 255));
		Render::Rect(pos.x + x, pos.y + y, 140, 30, ImColor(175, 175, 175, 255), 1);
		Render::Text(pos.x + x + 48, pos.y + y + 6, ImColor(0, 0, 0, 255), v);
	}
}











