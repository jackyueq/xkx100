// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ��������������һЩС��̯���ƺ���һ�����С���������Ǻų���
�õ����ݳ��ˡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"beimen",
		"southwest" : __DIR__"huqiu",
		"northeast" : __DIR__"sanglin",
		"northwest" : "/d/wuxi/road4",
	]));
	set("coor/x", 850);
	set("coor/y", -900);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
