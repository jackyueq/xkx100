// Room: /d/jueqinggu/xiangqinxie.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����鿷�Ϊ���䣬���ϱ�����Ϊ��ѡ����Ϊ���䣬����ƽֱ���ṹ
���ɡ��������Ȫ��ص����������������ţ���ˮ��ʯ��������ɪ����
ˬ���壬�Ƕ�������֮�ء�
LONG
	);

	set("exits", ([
		"westdown"  : __DIR__"feiyunyan",
		"southdown" : __DIR__"guanlanting",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -480);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

