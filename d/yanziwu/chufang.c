//Room /d/yanziwu/chufang.c
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
���Ǽ���ĳ�������ʦ����չʾ���Ե���⿾��������������
�����˴������εĲ��㡣
LONG );
	set("exits",([
		"north" : __DIR__"xiaoting",
	]));
	set("objects",([
		__DIR__"npc/nanpu" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1510);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}