// Room: /d/xingxiu/jiayuguan.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳ��������Ĺذ������²�ɣ�����ڲ�ס���ķ�ɡ�Ⱥɽ����֮
�£����������ۻ롣�������򰲶�������ս�£��߹��ؾ��Ѵ�Ϊ���١�
һ�����������ͨ����ԭ�����ﳤ���ɴ������������Ѷ�ȥ��������
�������������ġ�˿��֮·����
LONG );
	set("outdoors", "silu");
	set("exits", ([
		"eastup"    : __DIR__"xxroad3",
		"west"      : __DIR__"silk1",
		"southup"   : "/d/qilian/tanglangling",
		"northeast" : "/d/qilian/yumen",
		"northwest" : "/d/qilian/danshan",
		"southwest" : "/d/qilian/shalu1",
		"up"	: "/d/changcheng/jiayuguan",
	]));
	set("objects", ([
		__DIR__"npc/wujiang1" : 1,
		__DIR__"npc/bing1" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -18000);
	set("coor/y", 3000);
	set("coor/z", 0);
	setup();
}
#include "/d/xingxiu/job2.h";
