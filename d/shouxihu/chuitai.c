// Room: /yangzhou/chuitai.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��̨");
	set("long", @LONG
��̨�׳Ƶ���̨�����������������ĳ�侾�ͷ��̨ͤ�����ٺ���
����ͤ�š����������������ഫǬ¡�ʵ����ڴ˴�����ͤΪ�ķ�������
���ǻ�ǽ�����߶����涫װľ���ƿ�����ָ��ţ����ö�������������
����Բ���š��洵̨ƫ��������������Բ�ţ�������ͤ�ţ����ϲප�ţ�
ӳ�������ʡ����Ž辰������"���ǹ���"֮�ơ���������̨���ң�����
��������̨���ҡ����������������(lian)��
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIC"
        ��        ��
        ��        ��
        ��        ��
        ��        ��
        �        ��
\n"NOR
	]));
	set("exits", ([
		"east"  : __DIR__"pingtai2",
		"south" : __DIR__"balongqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}