//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "����·");
	set("long", @LONG
����һ������·����ʱ�ɼ��������˱��Ű��������ŵ���������ȥ��
���������������ĺۼ���
LONG );
	set("exits", ([
		"south"     : __DIR__"beimen",
		"northwest" : "/d/wudang/wdroad9",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}