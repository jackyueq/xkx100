// Room: /d/fuzhou/ximen.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ������š�һ����ֱ�Ĺٵ��������죬ֱ���������������
�����ٵ���ת�뱱��ɽ�괦��ֱ����ԭ��
LONG );
	set("exits", ([
		"east" : __DIR__"xixiaojie",
		"west" : "/d/yanping/guandao1",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
