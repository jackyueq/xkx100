// Room: /d/fuzhou/luoxingta.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ϡ������Ƕ�����ۣ��ഫ֣���������󣬼��ڴ�
�������ӣ����������ġ�����ˮ���ཫ������Ϊ���ﶫ�����ϼǡ�����
�����Ķ�����������������Ϧ  ������������������
LONG );
	set("exits", ([
		"northup" : __DIR__"gushan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1890);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
