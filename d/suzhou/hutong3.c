// Room: /d/suzhou/hutong3.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ͬ");
	set("long", @LONG
����һ���ڰ��������С������з·�Ʈ����һ��������Ϣ��
������å���ε������Ͼ��ܻص���֣��㻹�ǸϿ��߰ɡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"hutong2",
		"southeast" : __DIR__"dongdajie2",
	]));
	set("objects", ([
		"/d/city/npc/liumang" : 2,
	]));
	set("coor/x", 880);
	set("coor/y", -990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
