// Room: /d/suzhou/road2.c
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
		"west"  : __DIR__"road3",
		"east"  : __DIR__"ximen",
	]));
	set("coor/x", 810);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
