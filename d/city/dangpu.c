// Room: /city/dangpu.c
// Last Modifyed by Winder on Dec. 12 2001

#include <ansi.h>;
inherit ROOM;

int do_quit();
void create()
{
	set("short", "���굱��");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ��
��̨�ϰ���һ������ (paizi)����̨���������ϰ壬һ˫�������۾�����
���´������㡣
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : HIY"
�������������������� "HIR"��ƽ����"HIY" ��������������������
��  ������������������������������������������  ��
��  ��                                      ��  ��
��  ��  sell    ����                        ��  ��
��  ��  buy     : ��                        ��  ��
��  ��  redeem  : ��                        ��  ��
��  ��  value   : ����                      ��  ��
��  ��  list    : ����                      ��  ��
��  ��        list armor    �����������    ��  ��
��  ��        list weapon   �����������    ��  ��
��  ��        list book     ���鼮�����    ��  ��
��  ��        list medicine ��ҩƷ�����    ��  ��
��  ��        list food     ��ʳƷ�����    ��  ��
��  ��        list liquid   ����Ʒ�����    ��  ��
��  ��        list fruit    ����Ʒ�����    ��  ��
��  ��        list other    �����������    ��  ��
��  ��                                      ��  ��
��  ������������������������������������������  ��
��������������������������������������������������
"NOR,
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"shilijie2",
	]));

	set("coor/x", 0);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
