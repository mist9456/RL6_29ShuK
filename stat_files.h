
 struct StatFileInfo {
 int* _letters;
 char* fileName_;
 StatFileInfo();
 StatFileInfo(const char* file_name);
 ~StatFileInfo();
 };
  void GetCountLetters(struct StatFileInfo* fileInfo, const char* fileName);
