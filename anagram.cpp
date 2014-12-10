// Write a method to decide if two strings are anagrams or not.

#include <iostream>

bool isAnagram(char buf1[], char buf2[], int size)
{
	int buf1Counter[26];
	int buf2Counter[26];
	for(int i = 0; i < 26; ++i)
	{
		buf1Counter[i] = buf2Counter[i] = 0;
	}
	for(int i = 0; i < size; ++i)
	{
		int char1index = buf1[i]-'a';
		int char2index = buf2[i]-'a';
		buf1Counter[char1index]++;
		buf2Counter[char2index]++;
	}
	for(int i = 0; i < 26; ++i)
	{
		if(buf1Counter[i] != buf2Counter[i])
			return false;
	}
	return true;
}
int main()
{
	char buf1[] = "bouffe";
	char buf2[] = "ffoube";
	std::cout<<isAnagram(buf1, buf2, sizeof(buf1))<<std::endl;
	return 0;
}