#pragma once

#include <iostream>
#include <sys/stat.h>

namespace f_io
{
    FILE* OpenFile(const char* fname, const char* open_type)
    {
        struct stat buffer;
        if (open_type == "r" && stat(fname, &buffer) != 0){
            std::cout << "Couldn't find file: " << fname << std::endl;
            exit(1);
        }

        FILE* fd;
        if((fd = fopen(fname, open_type)) == NULL){
            std::cout << "Couldn't open file to read: " << fname << std::endl;
            exit(1);
        }

        return fd;
    }

    long GetFileSize(const char* fname)
    {
        FILE* fd = OpenFile(fname, "r");
        fseek(fd, 0, SEEK_END);
        long fsize = ftell(fd);
        fclose(fd);
        return fsize;
    }

    char* ReadFileAll(const char* fname)
    {
        long fsize = GetFileSize(fname);
        FILE* fd = OpenFile(fname, "r");
        char *fText = (char*) calloc(fsize,sizeof(char));
        fread(fText, fsize, 1, fd);
        fclose(fd);
        return fText;
    }

    char* ReadFileLine(const char* fname, unsigned int lineIndex)
    {
        FILE* fd = OpenFile(fname, "r");

        int currentLine = 0;
        int lineLength = 0;
        char* lineText;
        char buff;
        
        while(true)
        {
            lineLength = 0;
            while((buff = fgetc(fd)) != EOF)
            {
                lineLength++;
                if(buff == '\n') break;
            }

            if(buff == EOF)
            {
                std::cout << "Reached end of file" << std::endl;
                fclose(fd);
                return nullptr;
            }

            if(currentLine == lineIndex){
                lineText = (char*) calloc(lineLength+1, sizeof(char));
                fseek(fd, -lineLength, SEEK_CUR);
                fread(lineText, lineLength, 1, fd);
                break;
            }
            currentLine++;
        }

        fclose(fd);
        return lineText;
    }

    char* ReadFileLines(const char* fname, unsigned int lineStart, unsigned int lineEnd)
    {
        FILE* fd = OpenFile(fname, "r");

        int currentLine = 0;
        int lineLength = 0;
        size_t reachedStartLine = 0;
        size_t textCharCount = 0;
        char* lineText;
        char buff;
        
        while(true)
        {
            lineLength = 0;
            
            if(currentLine == lineStart){
                reachedStartLine = 1;
            }
            
            while((buff = fgetc(fd)) != EOF)
            {
                if(buff == '\n') {
                    if(reachedStartLine){
                        std::cout << buff;
                        textCharCount++;
                    }
                    break;
                }
                lineLength++;
                if(reachedStartLine){
                    std::cout << buff;
                    textCharCount++;
                }
            }

            if(currentLine == lineEnd){
                lineText = (char*) calloc(textCharCount+1, sizeof(char));
                fseek(fd, -(textCharCount), SEEK_CUR);
                fread(lineText, textCharCount, 1, fd);
                break;
            }

            if(buff == EOF)
            {
                std::cout << "Reached end of file" << std::endl;
                fclose(fd);
                return nullptr;
            }
            currentLine++;
        }

        fclose(fd);
        return lineText;
    }

    char* ReadFileChars(const char* fname, unsigned int startIndex, unsigned int endIndex)
    {
        long fsize = GetFileSize(fname);

        unsigned int charsCount = endIndex - startIndex + 1;
        unsigned int finalEndIndex = startIndex + charsCount;

        if(finalEndIndex > fsize || charsCount > fsize){
            std::cout << "End index out of the file bounds" << std::endl;
            return "";
        }

        FILE* fd = OpenFile(fname, "r");
        fseek(fd, startIndex, SEEK_CUR);
        char *chars = (char*) calloc(charsCount, sizeof(char));
        fread(chars, charsCount, 1, fd);
        fclose(fd);

        return chars;
    }

    char* ReadFileChar(const char* fname, unsigned int index)
    {
        return ReadFileChars(fname, index, index);
    }

    int WriteChars(const char* fname, const char * value, const uint32_t length)
    {
        FILE* fd = OpenFile(fname, "w");
        size_t wn;

        if(fwrite(value, sizeof(char), length, fd) != length)
        {
            fclose(fd);
            return 0;
        }
        
        fclose(fd);
        return 1;
    }

    int WriteChar(const char* fname, const char * value)
    {
        return WriteChars(fname, value, 1);
    }

    int WriteLine(const char* fname, const char * value, unsigned int length, unsigned int line_num)
    {
        // TODO: Write func (WriteLine)
    }
}

namespace str_op
{
    class StringPresets
    {
        const char* numbers = "1234567890";
        const char* lettersLowcase = "abcdefghijklmnopqrstuvwxyz";
        const char* lettersCapital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const char* letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const char* symbols = "!@#$%^&*";
        
        const char* allChars = "1234567890!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    };
}