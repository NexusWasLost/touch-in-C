# WINT

A lightweight, native Windows utility built in C to quickly create files from the command line, mimicking the core file-creation behavior of Unix touch.

[Download WINT here.](https://github.com/NexusWasLost/wint/releases/download/v1.0/wint.exe)

## Usage
```bash
.\wint file1 file2 ... file-n
```

## Compilation Note:
The downloadable executable is compiled using **GCC** and the makefile follows **GCC** compile command. <br>


## Implementation Notes

* Unlike the standard Unix [touch](https://www.gnu.org/software/coreutils/manual/html_node/touch-invocation.html) utility, WINT is explicitly designed to create new files only.
* Why ? I needed an utility to just create files using the CLI and also it was a good excuse to make a project using C.
* Built on raw Win32 APIs (`CreateFileW`).
* Wint needs to be added to system path to make it work system wide.
