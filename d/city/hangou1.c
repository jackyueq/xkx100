// Room: /city/hangou1.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�ع������������У����Կ���ˮ���������ٴ��͸��̵İ�������
�в�ʱ����������Ц֮��������Щ��ͬ�еĻ�������ˮ��ٵĻ�����
�����Ǳ����˵����������۵ģ�Ҳ���ǻ��ϵ������������δ��Ѹ���
�γ������������͵�������϶�·����������ʹ�������ˮ��ӵ��������
LONG );
	set("exits", ([
		"west" : __DIR__"hangou2",
		"east" : __DIR__"hangou0",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

