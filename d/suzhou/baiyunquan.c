// Room: /d/suzhou/.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
	set("short", "����Ȫ");
	set("long",@long
һ����Ȫ˳��ɽ´���£�������㼯��һ̶Ȫˮ������������һ��
���ֽС�����Ȫ���������Ȫˮ����������һʯ���У���������һ��
Ȫ���򡰲���Ȫ������Ȫ�󺵲��ߣ��ƴ���ʥ½����Ϊ�����е�һȪ����
ʫ�˰׾�������ʫ��ӽ����ƽɽ�ϰ���Ȫ���Ʊ�����ˮ���У��αر���
ɽ��ȥ�����������˼䡱��Ȫ�����в��ң�Ʒ����Ȫ�����ﲻ����
long);
	set("outdoors", "suzhou");
	set("exits",([
		"westdown" : __DIR__"tianpingshan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1090);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
