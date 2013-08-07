// Room: /d/changcheng/juyongguan.c
// Last Modified by Winder on Aug. 25 2000
#include <ansi.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "��ӹ��");
	set("long", WHT@LONG
������ǳ������������۹ة�����ӹ�ء�����羰��������ɽ��Ұ
�ķ�����һ���������еķ�Ҷ������˺�ɫ������������һƬ��ɫ��
���󡣵��꣬�����ʵ۵���������ʱ�����������ľ�ɫ�������ױ�����
�ˡ���ӹ���䡱�ĸ����֡�
    ���ڴ�������ͨ��������������ɹŴ��ԭ����������ǰ����
�����Ӿ����ӳ������ﷸ���Ǵ������ӳ�ȥ�����Գ�ǽ�������˹�
���ĸ�ʾ(gaoshi)���������Ĺٱ�Ҳ�䱸ɭ�ϣ���ʱ�����ſ��ɵ��ˡ�
LONG
NOR  );
	set("outdoors", "changcheng");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west"  : __DIR__"changcheng1",
		"east"  : __DIR__"badaling",
		"north" : "/d/mobei/huanglu1",
		"south" : __DIR__"nroad2",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -190);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n         ��ӹ�ܱ�\n      �����\n";
}
