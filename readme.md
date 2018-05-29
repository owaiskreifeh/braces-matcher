# Braces Matcher
check if every tag has a closing tag in the right order

# Usage
## Direct string
 ```bash
$ chmod +x checker.exe # give it permission to execute
$ ./dist/checker.exe [string to check]
# Example: 
$ ./dist/checker.exe '( { "<" : ">" } )'
```
## File 
```bash
$ chmod +x checker.exe # give it permission to execute
$ ./dist/checker.exe -f [filename]
# Example:
$ ./dist/checker.exe -f testFile
```

# Build and run
## Using build and run tool:
```bash
$ ./build [args] # agrs will be passed to the executabel file
# Examples
$ ./build [string]
$ ./build -f [file path]
```
## Manual build
```bash
$ mkdir -p dist && g++ main.cpp -o /dist/checker.exe
$ cd dist
$ ./checker.exe [args]
```
# Limitation
cant be used for a real thing :P

