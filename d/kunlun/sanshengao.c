// Room: /d/kunlun/sanshengao.c ����ɽ��ʥ��
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʥ��");
	set("long", @long
��������̲���������������㻨��ԭ������ʥ�����ܶ��ǲ����
ɽ����ס�˺��������������������������˼��������������ɽ�꣬��
ǲ���Ӷ������ϣ��������ã������滨����ǰ����ֲ��������ɽ�����
������һ����������������𣬱�ѭ��Ѱȥ��
long );
	set("exits", ([
		"north" : __DIR__"jingshenfeng",
		"down"  :  __DIR__"fufengshan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40170);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
