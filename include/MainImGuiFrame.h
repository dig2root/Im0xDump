#include "ImGuiFrame.h"
#include "ImGuiFileBrowser.h"
#include "ImGuiMemoryEditor.h"

class MainImGuiFrame : public ImGuiFrame {
public:
	virtual void Update() override;
	bool getClose() const { return m_close; }

private:
	ImVec2 m_tool_size = ImVec2(720, 360);
	ImVec2 m_tool_pos = ImVec2(0, 0);
	bool m_open = false, m_close = false;
	imgui_addons::ImGuiFileBrowser m_file_dialog;
	MemoryEditor m_mem_edit;
	char* m_bufferMemory;
	int m_bufferSize=0;
};