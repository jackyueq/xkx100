// Room: /d/yueyang/xiaolu8.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ʯɽ��");
	set("long", @LONG
�������ھ�ɽ��´ͨ���������ϵ���ʯɽ���ϡ���ɽ������ʮ����
��ɣ��������㣬���̲���������������ɫȫ�޴�ɫ�����ˮ����
ϴ����һ�����쾵���ġ�������Ұ��έҶ���롢������죬��ɽ�Ĳ��㡣
���ɵ�����������������ɶ�����
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"qiuyueting",
		"enter"     : __DIR__"dongtingmiao1",
	]));
	set("coor/x", -1660);
	set("coor/y", 2350);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
