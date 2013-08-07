// Room: /city/ximen.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "ͨ����");
	set("long", @LONG
ͨ���������ݵ����ţ���ש���ɡ�����ǰ���ų�ǽ���ڻ��Ǻӱ���
��������������ݱ���Ϊ�������ǹ���������ʿ��վ�ڳ��ſڣ������
�������˳������������ﷸ��������ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϣ���
�����ͽ�ס�������ʡ���ǽ�����ż���ͨ����ʾ(gaoshi)�� 
    һ����ֱ����ʯ���������������졣�����ǽ��⣬����ġ���
�εġ���·�ģ����˴Ҵҡ������ǳ��������һƬ���֡�
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"east"  : __DIR__"tongsijie",
		"west"  : "/d/luoyang/road1",
		"north" : "/d/taohuacun/taohua1",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
		__DIR__"npc/runyu" : 1,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", -100);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}