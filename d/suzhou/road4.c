// Room: /d/suzhou/road4.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������
�Ҷ��������������һЩС��̯���ƺ���һ�����С�����������ݳ��ˡ�
������ͨ��ɽ�¡�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"hanshansi",
		"south"     : __DIR__"tulu1",
		"east"      : __DIR__"road3",
	]));
	set("coor/x", 790);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
