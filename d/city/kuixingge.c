// Room: /d/city/kuixingge.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short","���Ǹ�");
	set("long",@LONG
һ������ĸ�¥��ǽ��������¥�����Ϲ���һ�����Ҷ���Ǹ󡹡�
һ¥���ſ��ǣ�ֻ��������������ʣ���Ȼ���ڸ�̨�ϣ���ǰ�Ĺ�����
��һЩ�����ʹ�Ʒ��żȻ�м�������������ݿ��Ǵ��ˡ�
LONG    );

	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"caohebeijie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
