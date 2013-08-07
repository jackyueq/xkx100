// Room: /city/nanmen.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
һ���ߴ�ĳ��������ڶɽ���ͷ������Ƕ�С������š�����ʯ�
��ǽ�Ͻ���һ����¥������Ѳ�ߵĹٱ��Ǳ������Ļ���Ц������������
�����Ǻ�������ִ�ڡ����Ҹ���һ��ˮ�ţ����ڹٺӺ�С�ػ�����ͨ��
���������ˮ�˵ı�������ǽ�������˹���ƣ������˻������̸��и�
ҵ�Ĺ�棬���ſ����ż��Ű��ĸ�ʾ(gaoshi)��˲�̫��Ŀ����������
�˳������������ţ�������������Ⱥ����ʹ�˸��ܵ����ݵķ�����
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"dujiangqiao",
		"north" : __DIR__"nanmendajie",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", 10);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}