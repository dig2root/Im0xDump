#include "ImGuiFrame.h"
#include "ImGuiFileBrowser.h"
#include "ImGuiMemoryEditor.h"

class MainImGuiFrame : public ImGuiFrame {
public:
	virtual void Update() override;
	bool getClose() const { return close; }

private:
	ImVec2 tool_size = ImVec2(720, 360);
	ImVec2 tool_pos = ImVec2(0, 0);
	bool open = false, close = false;
	imgui_addons::ImGuiFileBrowser file_dialog;
	MemoryEditor mem_edit;
	char* bufferMemory;
	int bufferSize=0;
};