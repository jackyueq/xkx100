// Room: /d/kunlun/kekexili.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ɿ�����ɽ");
	set("long",@long
�ɿ�����ɽ�ֳƿɿ�ϡ��ɽ���ɹ���Ϊ����ɽ������˼������ľ��
����壬���Ӱ��տ���ɽ��ɽ��ƽ���������㲼���ߴ��������Ի�ѩ��
�������������е�ˮ��������⣬�����ϱ������岼�ĺ�����Ϊ��ˮ����
��ľϡ�裬���̼��١�
long);
	set("exits",([
		"east"      : __DIR__"bayankala",
		"northwest" : __DIR__"shankou",
		"north"     : __DIR__"xuedi",
	]));
	set("objects",([
//		"/d/mingjiao/npc/yinli" : 1,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -100000);
	set("coor/y", 20000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);    
}
