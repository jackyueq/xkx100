// Room: /d/jueqinggu/feiyunyan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ƶ��Ƕ����������ܸ�����ʯ�鵹������������ϼ��ب������
�ޣ���Ȼ¥�����ڣ�����ͭ�ı��࣬����ʨ��������������İ���䷿ˮ
��֮�������³�̶��ȣ������޵ף�����ïʢ�������죬��ˮ��䧡�
LONG
	);

	set("exits", ([
		"eastup" : __DIR__"xiangqinxie",
		"west"   : __DIR__"wuxi",
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

