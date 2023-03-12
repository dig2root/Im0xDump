#include <iostream>
#include <math.h>
#include "MainImGuiFrame.h"
#include "FileDumper.h"

void MainImGuiFrame::Update() {
    // Creating a window
    ImGui::Begin("Hexadecimal dump file reader - @dig2root", NULL, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowSize(tool_size);
    ImGui::SetWindowPos(tool_pos);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open..")) {
                open = true;
            }
            if (ImGui::MenuItem("Close")) { 
                close = true;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    if (bufferSize > 0) {
        mem_edit.DrawContents(bufferMemory, bufferSize); 
    }

    //Remember the name to ImGui::OpenPopup() and showFileDialog() must be same...
    if (open)
        ImGui::OpenPopup("Open File");

    /* Optional third parameter. Support opening only compressed rar/zip files.
     * Opening any other file will show error, return false and won't close the dialog.
     */
    if (file_dialog.showFileDialog("Open File", imgui_addons::ImGuiFileBrowser::DialogMode::OPEN, ImVec2(700, 310)))
    {
        std::cout << file_dialog.selected_fn << std::endl;      // The name of the selected file or directory in case of Select Directory dialog mode
        std::cout << file_dialog.selected_path << std::endl;    // The absolute path to the selected file
        open = false;

        // Do reading of file
        FileDumper file_dumper(file_dialog.selected_path);
        file_dumper.dump();
        bufferMemory = file_dumper.getBuffer();
        bufferSize = file_dumper.getFileSize();
    }

    ImGui::End();
}