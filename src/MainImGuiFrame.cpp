#include <iostream>
#include <math.h>
#include "MainImGuiFrame.h"
#include "FileDumper.h"

void MainImGuiFrame::Update() {
    // Creating a window
    ImGui::Begin("Hexadecimal dump file reader - @dig2root", NULL, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowSize(m_tool_size);
    ImGui::SetWindowPos(m_tool_pos);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open..")) {
                m_open = true;
            }
            if (ImGui::MenuItem("Close")) { 
                m_close = true;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    if (m_bufferSize > 0) {
        m_mem_edit.DrawContents(m_bufferMemory, m_bufferSize);
    }

    //Remember the name to ImGui::OpenPopup() and showFileDialog() must be same...
    if (m_open)
        ImGui::OpenPopup("Open File");
        m_open = false;

    /* Optional third parameter. Support opening only compressed rar/zip files.
     * Opening any other file will show error, return false and won't close the dialog.
     */
    if (m_file_dialog.showFileDialog("Open File", imgui_addons::ImGuiFileBrowser::DialogMode::OPEN, ImVec2(700, 310)))
    {
        std::cout << m_file_dialog.selected_fn << std::endl;      // The name of the selected file or directory in case of Select Directory dialog mode
        std::cout << m_file_dialog.selected_path << std::endl;    // The absolute path to the selected file

        // Do reading of file
        FileDumper file_dumper(m_file_dialog.selected_path);
        file_dumper.dump();
        m_bufferMemory = file_dumper.getBuffer();
        m_bufferSize = file_dumper.getFileSize();
    }

    ImGui::End();
}