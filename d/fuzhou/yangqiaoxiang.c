// Room: /d/fuzhou/yangqiaoxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǿ���������ͨ���Ŷ���������������˫����, ��˵��ʱ��һ
��������Ů�మ, ������Ը��˫˫Ͷ��ѳ��, ������˫�ס���
LONG );

	set("exits", ([
		"west"    : __DIR__"nanhoujie1",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
