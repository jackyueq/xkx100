// Room: /yangzhou/guanyindian.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������׳�С�Ϻ���������麡����ڹ�������������Ϊ������
����̨Ů�񡣵���ͥԺ���������Űز����������ǰ���Ǵ����ţ�ͨ
��������ɡ���ͤ�������Ϸ��š��㺣���ơ�����ʯ�����£��ɴ��
�ϲ��á���
LONG );
	set("exits", ([
		"west"      : __DIR__"banting",
		"southdown" : __DIR__"caotang",
		"eastup"    : __DIR__"pingtai1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}