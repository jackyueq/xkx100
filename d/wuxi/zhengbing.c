// Room: /d/wuxi/zhengbing.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "������");
	set("long", @LONG
�������±���ļ�����ſ��п�ľ�� (mupai)�����漷�����ˣ�����
��δ�ɵ����꣬���������ǿ��׳�������ˣ�ÿ���������϶��Ƕ�δ��
���㽡�������뱨Ч���ң���սɳ�������ǳ���ͷ�أ�������ʵ
��������ĵط���
LONG );
	set("outdoors", "wuxi");
	set("item_desc", ([
		"mupai" : HIR"
		
         �� �� �� ��

\n"NOR,
	]));
	set("exits", ([
		"north" : __DIR__"eastroad1",
	]));
	set("objects", ([
		__DIR__"npc/guan" : 1,
	]));
	set("coor/x", 380);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

