#include "functions.h"

// everything in here was pasted by: zexty#3383

void Testing()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImColor(255, 255, 255, 255);
	colors[ImGuiCol_Button] = ImColor();
	colors[ImGuiCol_ButtonActive] = ImColor();
	colors[ImGuiCol_ButtonHovered] = ImColor();
	colors[ImGuiCol_FrameBg] = ImColor();
	colors[ImGuiCol_FrameBgHovered] = ImColor();
	colors[ImGuiCol_FrameBgActive] = ImColor();

	ImGuiStyle* style = &ImGui::GetStyle();
	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 0.0f;
	style->FramePadding = ImVec2(2, 2);
	style->FrameRounding = 0.0f;
	style->ItemSpacing = ImVec2(8, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 0.0f;
	style->GrabMinSize = 10.0f;
	style->GrabRounding = 0.0f;
	style->ChildRounding = 0.f;

	style->WindowTitleAlign.x = 0.50f;
	style->FrameRounding = 2.0f;

	ImGui::SetNextWindowSize({ 620, 450 });
	ImGui::Begin("#AppleCheats", NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);
	
	p = ImGui::GetWindowPos();

	Render::RectFilled(p.x, p.y, 620, 25, ImColor(0, 0, 0, 255));
	Render::Text(p.x + 3, p.y + 3, ImColor(255, 255, 255, 255), "SUSCHEATS.CC (INSERT) fucking minoritys suck!");

	PS::AC_Tab("Aimbot", 1, 15, 40);
	PS::AC_Tab("Visuals", 2, 165, 40);
	PS::AC_Tab("Mods", 2, 315, 40);
	PS::AC_Tab("Misc", 2, 465, 40);

	if (tabs == 1)
	{
		PS::AC_Checkbox("Aimbot", &Settings::Distance, 20, 100, "sussy:");

	}

	
	ImGui::End();
}

void Config::CWIN()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0);
	colors[ImGuiCol_Button] = ImColor();
	colors[ImGuiCol_ButtonActive] = ImColor();
	colors[ImGuiCol_ButtonHovered] = ImColor();
	colors[ImGuiCol_FrameBg] = ImColor();
	colors[ImGuiCol_FrameBgHovered] = ImColor();
	colors[ImGuiCol_FrameBgActive] = ImColor();

	ImGuiStyle* style = &ImGui::GetStyle();
	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 0.0f;
	style->FramePadding = ImVec2(2, 2);
	style->FrameRounding = 0.0f;
	style->ItemSpacing = ImVec2(8, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 0.0f;
	style->GrabMinSize = 10.0f;
	style->GrabRounding = 0.0f;
	style->ChildRounding = 0.f;

	style->WindowTitleAlign.x = 0.50f;
	style->FrameRounding = 2.0f;

	ImGui::SetNextWindowSize({ 500, 450 });
	ImGui::Begin("#Fortnite", NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);

	int x = 30;
	int y = 20;

	p = ImGui::GetWindowPos();

	Render::Text(p.x + 165, p.y + 30, ImColor(0, 245, 245), "array is a pedophile");

	Render::Rect(p.x + 80, p.y + 70, 100, 45, ImColor(255, 255, 255), 1);
	Render::Rect(p.x + 205, p.y + 70, 100, 45, ImColor(255, 255, 255), 1);
	Render::Rect(p.x + 330, p.y + 70, 100, 45, ImColor(255, 255, 255), 1);

	Render::Text(p.x + 110, p.y + 82, ImColor(255, 255, 255), " Main");
	Render::Text(p.x + 230, p.y + 82, ImColor(255, 255, 255), " Visuals");
	Render::Text(p.x + 351, p.y + 82, ImColor(255, 255, 255), " Exploits");

	ImGui::SetCursorPos({ 80, 70 });
	if (ImGui::Button("##aim", ImVec2(100, 45))) tabs = 1;
	ImGui::SetCursorPos({ 205, 70 });
	if (ImGui::Button("##esp", ImVec2(100, 45))) tabs = 2;
	ImGui::SetCursorPos({ 330, 70 });
	if (ImGui::Button("##idk", ImVec2(100, 45))) tabs = 3;

	const char* ctx = "";

	if (tabs == 1)
	{
		Render::Rect(p.x + 80, p.y + 70, 100, 45, ImColor(0, 245, 245), 1);
		ImGui::SetCursorPosX({ 40 });
		ImGui::Text("");

		Render::Checkbox("Aimbot", &Settings::Aimbot, 38, 150, "Aim Methods:");

		Render::Checkbox("Head", &Settings::Head, 38, 230, "Hitbox:");
		Render::Checkbox("Chest", &Settings::Chest, 38, 260, ctx);

		Render::Slider("##Smoothing", &Settings::Smoothing, 38, 310, 0, 25, "Smoothing");
		Render::Slider("##AimbotFOV", &Settings::AIM_FOV, 38, 350, 0, 25, "Aimbot FOV");

		Render::Checkbox("Visible Check", &Settings::VisCheck, 230, 150, "Extra:");

	}
	if (tabs == 2)
	{
		Render::Rect(p.x + 205, p.y + 70, 100, 45, ImColor(0, 245, 245), 1);
		ImGui::SetCursorPosX({ 40 });
		ImGui::Text("");

		Render::Checkbox("Draw Box", &Settings::BoxESP, 50, 150, "Player:");
		Render::Checkbox("Enable Filled", &Settings::Filled, 50, 180, ctx);
		Render::Checkbox("Player Names", &Settings::Player_Name, 50, 210, ctx);
		Render::Checkbox("Player Distance", &Settings::Distance, 50, 240, ctx);
		Render::Checkbox("Draw Lines", &Settings::Lines, 50, 270, ctx);
		Render::Checkbox("Player Skeleton", &Settings::Skeletons, 50, 300, ctx);

		Render::Checkbox("Draw FOV", &Settings::AimbotFOV, 200, 150, "Extra:");
	}
	if (tabs == 3)
	{
		Render::Rect(p.x + 330, p.y + 70, 100, 45, ImColor(0, 245, 245), 1);
		ImGui::SetCursorPosX({ 40 });
		ImGui::Text("");

		Render::Checkbox("Enable Custom FOV Slider", &Settings::Fov_Slider, 38, 150, "Main:");
		Render::Slider("##FOV Slider", &Settings::Fov_Amt, 38, 200, 90, 150, "Custom FOV");
	}

	ImGui::End();
	ImGui::EndFrame();
}

void Config::CheatLoverz()
{

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImColor(1, 133, 182, 255);
	colors[ImGuiCol_Button] = ImColor();
	colors[ImGuiCol_ButtonActive] = ImColor();
	colors[ImGuiCol_ButtonHovered] = ImColor();
	colors[ImGuiCol_FrameBg] = ImColor();
	colors[ImGuiCol_FrameBgHovered] = ImColor();
	colors[ImGuiCol_FrameBgActive] = ImColor();

	ImGuiStyle* style = &ImGui::GetStyle();
	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 0.0f;
	style->FramePadding = ImVec2(2, 2);
	style->FrameRounding = 0.0f;
	style->ItemSpacing = ImVec2(8, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 0.0f;
	style->GrabMinSize = 10.0f;
	style->GrabRounding = 0.0f;
	style->ChildRounding = 0.f;

	style->WindowTitleAlign.x = 0.50f;
	style->FrameRounding = 2.0f;

	ImGui::SetNextWindowSize({ 520, 580 });
	ImGui::Begin("##CheatLoverz", NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);

	p = ImGui::GetWindowPos();

	Render::ShadowText(p.x + 8, p.y + 5, ImColor(255, 187, 0, 200), "CheatLoverz 2.5 - (Sus Edition)");

	Render::Rect(p.x, p.y, 520, 580, ImColor(0, 67, 91, 255), 2);
	Render::RectFilled(p.x + 10, p.y + 70, 500, 500, ImColor(0, 67, 91));

	PS::CL_Tab("Visuals", 1, 10, 30);
	PS::CL_Tab("Aimbot", 2, 140, 30);
	PS::CL_Tab("Credits", 3, 388, 30);

	if (tabs == 1)
	{
		PS::CL_ToggleButton("Characters ESP", &Settings::BoxESP, 25, 80, 400);
		PS::CL_ToggleButton("Skeleton ESP", &Settings::Skeletons, 25, 110, 400);
		PS::CL_ToggleButton("Skeleton Only Behind Walls", &Settings::VisCheck, 25, 140, 400);
		PS::CL_ToggleButton("Loot ESP", &Settings::Filled, 25, 170, 400);
	}

	if (tabs == 3)
	{
		Render::ShadowText(p.x + 100, p.y + 100, ImColor(255, 255, 255, 255), "all credits go too: lil peep no cap kuh!");
	}

	ImGui::End();
	ImGui::EndFrame();
}

void Config::BypassAC()
{

}
