// Room: /d/kunlun/houyuan.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"��Ժ"NOR);
	set("long", @LONG
������ɽׯ�ĺ�Ժ����ׯ�ųơ���÷��������Ӧ�����Դ��Ժ����
�ͳ������÷����ÿ�괺��÷��ʢ��֮ʱ������һƬ��죬����������
÷��Ʈ����������Ŀ������������ǡ����Ṭ����
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"linggong",
		"west"  : __DIR__"hmszdating",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/guanjia" : 1,
	]));
	set("outdoors", "hongmei");
	set("coor/x", -90020);
	set("coor/y", 10020);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
