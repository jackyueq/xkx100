// Room: /d/fuzhou/xihu.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ԭΪ����迣֮�����򣬻�һ��֮ˮ��Ϊ��ũʱ������
��ˮ���̵�������Ϸ���㣬����ʮ�־��¡�
LONG );
	set("exits", ([
		"south" : __DIR__"xixiaojie",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
