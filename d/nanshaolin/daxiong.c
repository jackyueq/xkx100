// Room: /d/nanshaolin/daxiong.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"���۱���"NOR);
	set("long", @LONG
�����������µĴ��۱��������䣬�����ļ䡣���й���������
���������Ҹ������⡢������λ������һȺɮ�����Է����о���������
���黨΢Ц����̬�����˶ٸ���Ȼ�𾴡�������ÿ�����Ƿ��ɴ�ʦ
�ټ�����Ⱥɮ����֮����
LONG );
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"pingtai",
		"north" : __DIR__"stoneroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



