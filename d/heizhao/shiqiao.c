// Room: /heizhao/shiqiao.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "Сʯ��");
	set("long", @LONG
����һ����ʯ������Сʯ�ţ������Բ�����ͨ����������վ��
���ϸ��ӣ�����ˮ�������ü��ż�м�ֻ���ܴ�������Ҷ������ˮ
�ף�������һ����������������ȥ��������Ⱥɽ�·����������ƣ�
��Զ���塣
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"south"   : __DIR__"hetang",
		"northup" : __DIR__"chanyuan",
	]));
	set("coor/x", -5020);
	set("coor/y", -1210);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}