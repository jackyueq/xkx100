// Room: /d/fuzhou/biaojunz.c
// Date: may.12 1998 Java

inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
�����ھ���լװ���ʮ�ֻ��󡣻���ľ���Ϸ���һ���µ����׳�
˻����������̫ʦ���Ϻô�һ�ű�Ƥ�����������ڵ�����ʵʵ��
LONG );
	set("exits", ([
		"east"  : __DIR__"biaojuzt",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	set("coor/x", 1829);
	set("coor/y", -6297);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
