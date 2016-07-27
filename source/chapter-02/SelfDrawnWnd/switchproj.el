(defconst slnfile "D:/workspace/uiengine/source/uiengine.sln")
(defconst projfile "D:/workspace/uiengine/source/chapter-02/SelfDrawnWnd/SelfDrawnWnd.vcxproj")

(msvc-activate-projects-after-parse :solution-file slnfile
                                    :project-file projfile
                                    :platform "Win32"
                                    :configuration "Debug"
                                    :version "2015"
                                    :md5-name-p nil
                                    :force-parse-p nil
                                    :allow-cedet-p t
                                    :allow-ac-clang-p t
                                    :allow-flymake-p t
                                    :cedet-spp-table nil
                                    :flymake-manually-p nil)
