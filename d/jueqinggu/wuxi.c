// Room: /d/jueqinggu/wuxi.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�Ϫ");
	set("long", @LONG
ͻȻһ������ӿ������ǰ�ޱ��޼ʵ�ȫ��ˮ�ɻ���ԭ��������ǳǳ
��һƬˮ�������ߣ�������ˮ�ɡ�ǰ�������һƬ��Ұ�Ļ��ԣ���
�ѱ����·��һ���������ζ�ڿ����������š�
LONG
	);

	set("exits", ([
                "east"  : __DIR__"feiyunyan",
                "enter" : __DIR__"huacong1",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -500);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM); 
}

