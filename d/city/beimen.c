// Room: /city/beimen.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
�������ݵı��š����š�����������վ�ż���ʿ�����̲��Ź���
���˳�������ǰ��һ������Ļ��Ǻӣ����Ҹ���һˮ�ţ����ӻ��ǺӺ�
�ٺӼ�С�ػ��ӡ����Ž��и߸ߵ���¥�����м���ʿ����ǹ�ھ��䡣��
¥�����Ž����Ҷ���š�����Ϊ����ʧ�𣬵����ڳ�ǽ���Ǻں���
�ģ���˰�ֽ���ֵĹٸ���ʾ(gaoshi)���Ե��ر����ۡ�
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"beimendajie",
		"north" : "/d/nanyang/yidao",
		"west"  : "/d/huanghe/caodi1",
		"up"    : __DIR__"chenglou",
		"northeast" : __DIR__"hangou2",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", 10);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}
