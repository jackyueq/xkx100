// Room: /d/nanshaolin/lshuyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"����Ժ"NOR);
	set("long", @LONG
����һ��ƫƧ��СԺ��Ժ����������ߴ�Ļ������Եü���������
�������������ɮ����ȡ�����ͷ���֮�أ��㼯�����¸��ɹ��õĸ�
����С������似���³�����Ϊ��ֹ�������ˣ�����Ҳһ�����������
�ߡ�Ժ�ſ�վ������ɮ�����ֳֽ䵶�����ܵ��ػ������
LONG );
	set("exits", ([
		"east"  : __DIR__ "huaishu5",
		"north" : __DIR__ "wuqiku",
		"south" : __DIR__ "fangjuku",
	]));
	set("outdoors","nanshaolin");
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1790);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



