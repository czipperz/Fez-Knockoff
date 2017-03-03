((c++-mode . ((eval . (let ((top (file-name-directory
                                  (directory-file-name
                                   (file-name-directory
                                    buffer-file-name)))))
                        (setq-local cmake-ide-build-dir
                                    (concat top "out"))
                        (setq-local flycheck-gcc-include-path
                         (setq-local flycheck-clang-include-path
                          (list top))))))))
