// Room: /d/nanshaolin/qxdian.c ���ĵ�
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"���ĵ�"NOR);
	set("long",@long
������һ���տ��Ĵ�����湩���ż�����񣬵��аڷ��ż���
���ţ�������ܸ�װǶ��һ�ŵ�ľ�Ƴ���������͸������������
�յĴ��һƬ��⡣�����󳪴���ʹ��������¹���������ȫ����
long);
	set("exits",([
		"west" : __DIR__"dabeidian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


